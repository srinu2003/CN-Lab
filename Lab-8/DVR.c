#include<stdio.h>
struct node {
        unsigned cost[20];
        unsigned from[20];
} rt[10];
int main() {
        int costMat[20][20];
        int n,i,j,k,count=0;
        printf("\nEnter the number of nodes: ");
        scanf("%d",&n);
        printf("Enter the cost matrix:\n");

        for(i=0;i<n;i++){
            for(j=0;j<n;j++) {
                scanf("%d",&costMat[i][j]);

                costMat[i][i] = 0;
                rt[i].cost[j] = costMat[i][j];
                rt[i].from[j] = j;
            }
        }
        do{
            count=0;
            for(i = 0; i < n; i++){
                for(j = 0; j < n; j++){
                    for(k = 0; k < n; k++){
                        if( rt[i].cost[j] > costMat[i][k] + rt[k].cost[j]) {
                            rt[i].cost[j] = rt[i].cost[k] + rt[k].cost[j];
                            rt[i].from[j] = k;
                            count++;
                        }
                    }
                }
            }
        } while(count!=0);

        for(i=0;i<n;i++) {
            printf("\nState value for router %d is:\n",i+1);
            for(j=0;j<n;j++) {
                printf("Node %d via %d Distance: %d\n",j+1,rt[i].from[j]+1,rt[i].cost[j]);
            }
        }
        printf("\n");
}