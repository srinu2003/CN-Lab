#include<stdio.h>
#include<stdlib.h>

    /**
    * This program reads a non-negative integer to specify size of Messgae block and data bits from user input, ouputs a n-bit hamming code, then reads a sender's message block from user input and checks for unibit errors.
    * Example Input:
    * input:(7,4)      1   0 1 0
    * output:(7,4) 1 0 1 1 0 1 0
    * input:(15,11)      1   0 1 0   0 1 0 1 0 0 1
    * output:(15,11) 0 0 1 1 0 1 0 1 0 1 0 1 0 0 1
    * Reciver said "No Unibit error :)"
    */
void main() {
    printf("1. Generation\n2. Error detection\n3. Error Correction\n4. Exit");
    int ch, n, *msg, parity = 0;
    while(1){
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: /*Code Generation */
            printf("Enter size of msg block: ");
            scanf("%d",&n);
            n++;
            msg = (int*) malloc(n * sizeof(int));
            parity = 0;
            printf("Enter data bits: ");    
            msg[0]=0;
            for (int i = 0; i < n; i++) {
                if (i & (i - 1)) {
                    scanf("%d",&msg[i]);
                    if (msg[i]==1) { parity ^=(i); }
                }
            }
            printf("Message block: ");
            for (int i = 1; i < n; i++) {
                if (!(i & (i - 1))){
                    msg[i]=parity & 1;
                    parity >>= 1;
                }
                
                printf("%d ",msg[i]);
            } free(msg);
            break;
        case 2: /* Error detection */
            printf("Enter size of msg block: ");
            scanf("%d",&n);
            n++;
            msg = (int*) malloc(n * sizeof(int));
            parity = 0;
            printf("Enter senders msg block: ");
            for (int i = 1; i < n; i++) {
                scanf("%d",&msg[i]);
                if (msg[i]==1) { parity ^=(i); }
            }
            if (parity==0) {
                printf("\nReceiver said \"No Unibit error :)\"");
            }else {
                printf("\nReceiver said \"Error at position: %d!\"",parity);
            }
            break;
        case 3: /* Error Correction */
            printf("Enter size of msg block: ");
            scanf("%d",&n);
            n++;
            msg = (int*) malloc(n * sizeof(int));
            parity = 0;
            printf("\nEnter senders msg block: ");
            for (int i = 1; i < n; i++) {
                scanf("%d",&msg[i]);
                if (msg[i]==1) { parity ^=(i); }
            }
            msg[parity]^=1; /*corrects error 0-->1 : 1-->0 */
            if (parity==0) {
                printf("\nReceiver said \"No Unibit error :)\"");
            }else {
                printf("After Correction: ");
                for (int i = 1; i < n; i++) {
                    printf("%d ",msg[i]);
                }
            } free(msg);
            break;
        case 4: exit(0);
        default:printf("invalid choice!! Try again.");
            break;
        }
    }
}