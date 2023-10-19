#include <stdio.h>
#include <stdlib.h>

int main() {
    int frame_size;
    int N  = 10;      /* Window size */
    int Rn = 0;       /* Request number `Rn = Ack + 1`               */
    int Sn = 0;       /* `[Sb:Sm)` Sequence number  [0 1 2 3 4 5] 6  */
    int Sb = 0;       /* `Sb = 0`Sequence base      (0)1 2 3 4 5     */
    int Sm = 11;      /* `Sm = N + 1` Sequence max   0 1 2 3 4 5 (6) */
    int count = 0,n;
    printf("Enter size of frame: ");
    scanf("%d",&frame_size);
    printf("Enter sliding window size:");
    scanf("%d",&N);
    Sm = N;
    printf("Enter which nth frame is courrupted: ");
    scanf("%d",&n);

    if(N <= 0 || frame_size < N || n < 1) {
            printf("Invalied inputs.");
            return 1;
    } printf("GoBack-%d ARQ:\n",N);

    for (int ack = -1; ack < frame_size - 1; printf(" //timeout")) 
    {
        for ( Sn = Sb; Sn < Sm ; Sn++) {
            count++; /*frame sent*/
            ack = (count%n == 0)? ack : (Sn == Sb)? Sn : ack;

            printf("\n%2d. Frame %2d is send. Ack:%2d",count,Sn,ack);
            
            Sm = (ack + (Sm - Sb + 1) >= frame_size)? frame_size : ack + (Sm - Sb + 1);
            Sb = ack + 1;
            if (count%n == 0)
            { printf(" (courrupted!)"); }
        }
    }
    return 0;
}
/*
frame_size = 6
N = 5 (window size)
n = 3
count    frame                  ack = Rn - 1
1.  frame 1 sent               |  1
2.  frame 2 sent               |  2
3.  frame 3 sent (courrupted)  |  2
4.  frame 4 sent               |  2
5.  frame 5 sent               |  2
6.  frame 6 sent (courrupted)  |  2
7.  frame 3 sent //timeout     |  3
8.  frame 4 sent               |  4
9.  frame 5 sent (courrupted)  |  4
10. frame 6 sent               |  4
11. frame 5 sent               |  5
12. frame 6 sent (courrupted)  |  5
13. frame 6 sent               |  6
*/