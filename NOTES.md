## Goback-N




### Pseudocode: [gobabk-n.c](TRASH/goback-n.c)

```
Question:
Station A needs to send a message consisting of 6 packets to station B  using a sliding window (window size 5) and Go Back N error control strategy. All packets are ready and immediately available for transmission.

If every 3rd packet that A transmits gets lost (but no ACKs from B ever get lost), then what is the number of packets that A will transmit for sending the message to B?

Sol:
    frame_size = 6
    N = 5 (window size)
    n = 3
```


|S.No|Frame                      |ack = Rn - 1|
|---:|:--------------------------|------------|
|1.  | frame 1 sent              |  1
|2.  | frame 2 sent              |  2
|3.  | frame 3 sent (courrupted) |  2
|4.  | frame 4 sent              |  2
|5.  | frame 5 sent              |  2
|6.  | frame 6 sent (courrupted) |  2
|7.  | frame 3 sent `(timeout)`  |  3
|8.  | frame 4 sent              |  4
|9.  | frame 5 sent (courrupted) |  4
|10. | frame 6 sent              |  4
|11. | frame 5 sent `(timeout)`  |  5
|12. | frame 6 sent (courrupted) |  5
|13. | frame 6 sent `(timeout)`  |  6

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*PSEUDOCODE from (https://en.wikipedia.org/wiki/Go-Back-N_ARQ)

function receiver is
    Rn := 0
    Do the following forever:
        if the packet received = Rn and the packet is error free then
            Accept the packet and send it to a higher layer
            Rn := Rn + 1
        else
            Refuse packet
        Send a Request for Rn : ack = Rn - 1 i.e. ack+1


function sender is
    Sb := 0
    Sm := N + 1
    Repeat the following steps forever:
        if you receive a request number where Rn > Sb i.e. (ack >= Sb) then
            Sm := (Sm − Sb) + Rn
            Sb := Rn
        if no packet is in transmission then
            Transmit a packet where Sb ≤ Sn ≤ Sm.  
            Packets are transmitted in order.
*/

// Global variables
int frame_size;
int N  = 10;      // Window size
int Rn = 0;       // Request number `Rn = Ack + 1`
int Sn = 0;       // `[Sb:Sm)` Sequence number  [0 1 2 3 4 5]
int Sb = 0;       // `Sb = 0`Sequence base      (0)1 2 3 4 5
int Sm = 11;      // `Sm = N + 1` Sequence max   0 1 2 3 4 5 (6)

int main() {
    int count = 0,n;
    printf("Enter size of frame: ");
    scanf("%d",&frame_size); //6
    printf("Enter sliding window size:");
    scanf("%d",&N); //5
    Sm = N; //0 --> (N-1) + 1
    printf("Enter which nth frame is courrupted: ");
    scanf("%d",&n); //3

    if(N <= 0 || frame_size < N || n < 1) {
            printf("Invalied inputs.");
            return 1;
    } printf("GoBack-%d ARQ:\n",N);

    for (int ack = -1; ack < frame_size - 1; printf(" //timeout")) 
    {
        for ( Sn = Sb = 0; Sn < Sm ; Sn++) {
            count++; //frame sent
            ack = (count%n == 0)? ack : (Sn == Sb)? Sn : ack;

            printf("\n%2d. Frame %2d is send. Ack:%2d",count,Sn,ack);
            // ack = (count%n == 0)? ack,printf("Ack:%2d (courrupted)",ack) : (Sn == Sb)? Sn,printf("Ack:%2d //timeout",ack) : ack,printf("Ack:%2d",ack);
            // printf(" [%2d(%2d)%2d:%2d]",Sb,Sn,Sm,ack);
            Sm = (ack + (Sm - Sb + 1) >= frame_size)? frame_size : ack + (Sm - Sb + 1);
            Sb = ack + 1;
            // printf(" --> [%2d(%2d)%2d:%2d]",Sb,Sn+1,Sm,ack);
            if (count%n == 0){
                printf(" (courrupted!)");
            }
        }
    }
    return 0;
}
```

## CRC
```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){
    char msg[100],div[10];
    int n=0,m=0,ch,i,j;
    printf("1.Generate\n2.Detect\n3.Exit");
    while(1){
        printf("\nEnter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:/*Generation*/;
            printf("Enter CRC code: ");
            scanf("%s",msg);

            printf("Enter equation Coefficient:");
            scanf("%s",div);
            m = strlen(msg);
            n = strlen(div);
            printf("Message is: %s",msg);
            for (i = 0; i < n - 1; i++) { msg[m + i] = '0';}

            for (i = 0; i < m; i++) {
                if (msg[i] == '1') {
                    for (j = 0; j < n; j++) {
                        msg[i + j] = (msg[i + j] == div[j]) ? '0' : '1';
                    }
                }
            }
            printf(" ");
            for (i = m; i < m + n - 1; i++) {
                printf("%c",msg[i]);
            }
            break;
            case 2:
        printf("Enter Sender's CRC code: ");
            scanf("%s",msg);
            m = strlen(msg);
            n = strlen(div);
            printf("Message is: %s",msg);
            for (i = 0; i < n - 1; i++) { msg[m + i] = '0';}

            for (i = 0; i < m; i++) {
                if (msg[i] == '1') {
                    for (j = 0; j < n; j++) {
                        msg[i + j] = (msg[i + j] == div[j]) ? '0' : '1';
                    }
                }
            }
            for (i = m; i < m + n - 1; i++) {
                if (msg[i] == '1') {
                    printf("\nError detected!");
                    break;
                }
            }
            printf("\nNo error detected.");
            break;
            case 3:exit(0);
            default: printf("Invalid Choice! Try again.");
        }
    }
}
```