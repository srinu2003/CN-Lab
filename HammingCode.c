#include<stdio.h> 
void main(){
    int n;
    printf("Enter no.of bits: ");
    scanf("%d",&n);
    printf("Enter %d bits:",n);
    int msg[n];
    // int m,msg[16] =  {  0,0,0,1,
    //                     1,0,1,0,
    //                     1,0,1,0,
    //                     1,0,0,1 };
    // int m,msg[16] =  {  0,0,0,1,
    //                     1,0,1,0,
    //                     1,0,1,0,
    //                     1,0,0,1 };
    // int *ptr = msg;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&msg[i]);
    }
    
    int parity = 0;
    for (int i = 1; i < n; i++)
    {
        if (msg[i]==1) { parity ^=(i); }
    }
    if (parity==0) {
        printf("Reciver said \"No Unibit error :)\"");
    }else {
        printf("Reciver said \"Error at position: %d!\"",parity);
    }

}