#include<stdio.h>
void main()
{
    int N,n,sb=0,sm,fs,ws,count=0,flg=0,ack = 0;
    printf("Enter no.of ws: ");
    scanf("%d",&ws);
    printf("Enter no.of frams: ");
    scanf("%d",&fs);
    printf("Enter crpt fram: ");
    scanf("%d",&n);
    while (sb<=fs)
    {
        sm = fs;
        flg = 0;
        for ( sb = ack + 1; sb <= sm && sb <= fs; sb++)
        {
            count++;
            printf("%d. Frame %d sent",count,sb);
            if(count%n==0&&flg == 0)
            {
                ack = sb - 1;
                flg = 1;
                sm = sb + ws;
            }
            if(count%n==0)
                printf("(crpt)");
        
            printf("\n");
        }
    }
    
}