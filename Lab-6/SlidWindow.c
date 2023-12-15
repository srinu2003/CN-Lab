#include<stdio.h>
#include<stdlib.h>

int main(){
        int w,f,*frames;

        printf("Enter size of sliding window:");
        scanf("%d",&w);
        printf("Enter no.of frames:");
        scanf("%d",&f);

        if(w <= 0 || f <= 0){ 
                printf("Invalied inputs.");
                return 1;
        }

        frames = (int*)malloc(f * sizeof(int));
        printf("Enter %d frames:",f);
        for(int i = 0;i < f;i++){
                scanf("%d",&frames[i]);
        }

        printf("----\nThefollowing is by using Sliding windoew protocol\n----\nSender: ");


        for(int i = 0;i < f;i++){
                if((i+1)%w==0){
                        printf("%d ",frames[i]);
                        printf("\nAcknowledgement recieved");
                        printf("\nSender: ");
                }else{
                        printf("%d ",frames[i]);
                }
        }
        if(f%w != 0){
                printf("\nAcknowledgement recieved\n");
        }free(frames);
        return 0;
}
