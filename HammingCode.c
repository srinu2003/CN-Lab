#include<stdio.h>
#include<stdlib.h>
void main() {
    //input:(15,11)  1 0 1 0 0 1 0 1 0 0 1
    //output:(15,11) 0 0 1 1 1 0 1 0 0 0 1 0 1 0 0 1
    //input:(7,4)  1 0 1 0
    //output:(7,4) 1 0 1 1 0 0 1 0
    int n;
    printf("Enter size of msg block: ");
    scanf("%d",&n);
    n++;
    // printf("%d",n);
    printf("Enter data bits: ");    
    int *msg = (int*) malloc(n * sizeof(int));

    int parity = 0,p;
    for (int i = 0; i < n; i++) {
        if ((i & (i - 1))) {
            scanf("%d",&msg[i]);
            if (msg[i]==1) { parity ^=(i); }
        }
    }
    printf("Message block: ");
    for (int i = 0; i < n; i++) {
        if (!(i & (i - 1))){
            msg[i]=parity & 1;
            parity >>= 1;
        }
        // printf("%d:%d, ",i,msg[i]);
        printf("%d, ",msg[i]);
    }
    printf("\nEnter senders msg block:");
    // printf("%d",parity);
    for (int i = 0; i < n; i++) {
        scanf("%d",&msg[i]);
        if (msg[i]==1) { parity ^=(i); }
    }
    for (int i = 1; i < n; i++) {
        printf("%d ",msg[i]);
    }
    if (parity==0) {
        printf("\nReciver said \"No Unibit error :)\"");
    }else {
        printf("\nReciver said \"Error at position: %d!\"",parity);
    }
}
