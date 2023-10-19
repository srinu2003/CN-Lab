#include<stdio.h>
void main()
{
    int frameSize, windowSize, n, seqMax, seqNext, count = 0, flg = 0, ack = 0;
    
    printf("Enter size of frame: ");
    scanf("%d",&frameSize); 
    
    printf("Enter sliding window size: ");
    scanf("%d",&windowSize);
    
    printf("Enter which nth frame is courrupted: ");
    scanf("%d",&n);
    
    printf("GoBack-%d ARQ:\n",windowSize);
    if(windowSize <= 0 || frameSize < windowSize || n < 1) {
        printf("Invalied inputs.");
        return;
    }
    while(ack<frameSize)
    {
        seqMax = frameSize;
        flg = 0;
        for( seqNext = ack + 1 ; (seqNext <= seqMax) && (seqNext <= frameSize) ; seqNext++)
        {
            count++;
            if((count%n==0) && (flg == 0))
            {
                flg = 1;
                seqMax = seqNext + windowSize - 1;
            }
            if(flg == 0)
                ack++;
            
            printf("\n%2d. Frame %2d is send. Ack:%2d",count,seqNext,ack);
            if(count%n==0)
                printf(" (courrupted!)");
        }
    }
}