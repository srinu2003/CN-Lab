#include<stdio.h> 
void main(){
    int n=5,m,msg[16] =  {1,0,1,1,
                        0,1,1,0,
                        0,0,0,1,
                        0,0,1,0 };
    // int *ptr = msg;
    int parity = 0;
    for (int i = 0; i < 16; i++)
    {
        // parity = (msg[i]==1) ? (parity^i) : parity;
        if (msg[i]==1)
        {
            parity ^=(i);
        }
    }
    printf("Parity : %d\n",parity);
    printf("Enter message to send:");
    scanf("%d",&m);
    printf("%d: ",m);
    for (int i = 0; i < 11; i++)
    {
        printf("%d ",(m%10));
        m/=10;
    }
    
    printf("Sender sent:");
    // printf("Recever receved:");
    printf("\n%d",4^7);
}