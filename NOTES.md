#### Goback-N
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10 // Window size

// Global variables
int Rn = 0;       // Request number
int Sn = 0;       // Sequence number
int Sb = 0;       // Sequence base
int Sm = N + 1;   // Sequence max

// Simulate packet reception
bool receivePacket(int packetRn, bool isErrorFree) {
    if (packetRn == Rn && isErrorFree) {
        // Accept the packet and send it to a higher layer
        printf("Received packet with Rn=%d (Accepted)\n", Rn);
        Rn++;
        return true;
    } else {
        // Refuse the packet
        printf("Received packet with Rn=%d (Refused)\n", packetRn);
        return false;
    }
}

// Send a request for a specific Rn
void sendRequest(int requestedRn) {
    printf("Sending request for Rn=%d\n", requestedRn);
}

// Simulate packet transmission
void transmitPacket() {
    if (Sn >= Sb && Sn < Sm) {
        printf("Transmitting packet with Sn=%d\n", Sn);
        Sn++;
    }
}

// Receiver function
void receiver() {
    Rn = 0;
    while (true) {
        // Simulate receiving a packet with request number Rn
        int receivedRn = rand() % (N * 2); // Generate a random Rn for simulation
        bool isErrorFree = rand() % 2;     // Simulate packet errors randomly

        if (receivePacket(receivedRn, isErrorFree)) {
            // Packet was accepted, increment Rn
            Rn++;
        }
        // Always send a request for the current Rn
        sendRequest(Rn);
    }
}

// Sender function
void sender() {
    Sb = 0;
    Sm = N + 1;
    while (true) {
        // Simulate receiving a request number
        int requestedRn = rand() % (N * 2); // Generate a random Rn for simulation

        // Update Sm and Sb based on the received request number
        if (requestedRn > Sb) {
            Sm = (Sm - Sb) + requestedRn;
            Sb = requestedRn;
        }

        // Simulate packet transmission
        transmitPacket();
    }
}

int main() {
    // Start sender and receiver as separate threads or processes.
    // These will run forever until manually terminated.
    // You can use threading or process management libraries as needed.
    
    return 0;
}
```

#### CRC
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