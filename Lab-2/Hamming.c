#include<stdio.h>
#include<stdlib.h>
int parity=0;
void createmsg(int **msg,int *n){
    free(*msg);
    printf("Enter size of msg block: ");
    int sc = scanf("%d",n);
    (*n)++;
    *msg = (int*)malloc(*n * sizeof(int));
}
void Generate(int *msg,int n){
    printf("Enter data bits: ");    
    msg[0]=0;
    for (int i = 0; i < n; i++) {
        if (i & (i - 1)) {
            int sc = scanf("%d",&msg[i]);
            if (msg[i]==1) { parity ^=(i); }
        }
    }
    printf("Message   block: ");
    for (int i = 1; i < n; i++) {
        if (!(i & (i - 1))){
            msg[i]=parity & 1;
            parity >>= 1;
        }
        printf("%d ",msg[i]);
    }
}
void Correction(int *msg,int n){
    printf("Enter senders msg block: ");
    for (int i = 1; i < n; i++) {
        int sc = scanf("%d",&msg[i]);
        if (msg[i]==1) { parity ^=(i); }
    }
    if (parity==0) {
        printf("\nReceiver said \"No Unibit error :)\"");
    }else {
        printf("\nReceiver said \"Error at position: %d!\"",parity);
        msg[parity]^=1; /*corrects error 0-->1 : 1-->0 */
        printf("\nAfter Correction: ");
        for (int i = 1; i < n; i++) {
            printf("%d ",msg[i]);
        }
    }
}
    /**
    * This program reads a non-negative integer to specify size of Messgae block and data bits from user input, ouputs a n-bit hamming code, then reads a sender's message block from user input and checks for unibit errors.
     Example Input:
     input:(7,4)      1   0 1 0
     output:(7,4) 1 0 1 1 0 1 0
     input:(15,11)      1   0 1 0   0 1 0 1 0 0 1
     output:(15,11) 0 0 1 1 0 1 0 1 0 1 0 1 0 0 1
     Reciver said "No Unibit error :)"
    */
void main() {
    printf("1. Generation\n2. Error Detection & Correction\n3. Exit\n");
    int ch, n, *msg;
        createmsg(&msg,&n);
    while(1){
        parity=0;
        printf("\nEnter choice: ");
        int sc = scanf("%d",&ch);
        switch (ch)
        {
        case 1: /*Code Generation */
            Generate(msg,n);
            break;
        case 2: /* Error detection & Correction*/
            Correction(msg,n);
            break;
        case 3: exit(0);
        default:printf("invalid choice!! Try again.");
            break;
        }
        free(msg);
    }
}
