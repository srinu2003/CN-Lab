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
    int n;
    printf("Enter size of msg block: ");
    scanf("%d",&n);
    n++;
    int *msg = (int*) malloc(n * sizeof(int));
    int parity = 0;
    printf("Enter data bits: ");    
    msg[0]=0;
    for (int i = 0; i < n; i++) {
        if (i & (i - 1)) {
            scanf("%d",&msg[i]);
            if (msg[i]==1) { parity ^=(i); }
        }
    }
    printf("Message block: \n");
    for (int i = 1; i < n; i++) {
        if (!(i & (i - 1))){
            msg[i]=parity & 1;
            parity >>= 1;
        }
        
        printf("%d, ",msg[i]);
    }
    printf("\nEnter senders msg block:");
    //parity = 0;
    for (int i = 1; i < n; i++) {
        scanf("%d",&msg[i]);
        if (msg[i]==1) { parity ^=(i); }
    }
    if (parity==0) {
        printf("\nReceiver said \"No Unibit error :)\"");
    }else {
        printf("\nReceiver said \"Error at position: %d!\"",parity);
        msg[parity]^=1; //corrects error 0-->1 : 1-->0
    }
}