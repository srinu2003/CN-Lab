#include<stdio.h> 
void main(){
    int n;
    printf("Enter no.of bits: ");
    scanf("%d",&n);
    printf("Enter %d bits:",n);
    int msg[n];

    int parity = 0,p[4];
    for (int i = 0; i < n; i++)
    {
        if (i && (!(i & (i - 1))))
        {
            msg[i] = 0;
            continue;
        }
        
        scanf("%d",&msg[i]);
        if (msg[i]==1) { parity ^=(i); }
        // printf("%d\n",parity);
        // p[parity%4] = 0;
    }
    int i =1;
    while (parity>0)
    {
        msg[i] = parity%2;
        parity /=2;
        i *=2;
        printf("%d ",i);
    }
    printf("Message block:");
    for (int j = 0; j < i; j++) 
    {
        if (msg[j]==1) { parity ^=(j); } else{msg[i] = 0;}
        printf(" %d ",msg[j]);
        // printf("%d\n",parity);
        // p[parity%4] = 0;
    }
    if (parity==0) {
        printf("\nReciver said \"No Unibit error :)\"");
    }else {
        printf("\nReciver said \"Error at position: %d!\"",parity);
    }

}