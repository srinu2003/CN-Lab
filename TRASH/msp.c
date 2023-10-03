#include<stdio.h>
int main(){
        int n;
        printf("Enter no.of nodes:");
        scanf("%d",&n);
        int graph[10][10],node[10] = {0,0,0,0,0,0,0,0,0,0};
        int queue[100][3];
        printf("Enter distance between nodes:\n ");
        for(int i = 0; i < n;i++){
            printf(" %c",65+i);
        }printf("\n");
        for (int i = 0; i<n;i++){
            printf("%c ",65+i);
                for(int j = 0; j < n;j++){
                        scanf("%d",&graph[i][j]);
                        if(i==j){ graph[i][j] = -1;}
                        queue[n*i+j][0] = i;
                        queue[n*i+j][1] = j;
                        queue[n*i+j][2] = graph[i][j];
                        /* Inserssion Sort */
                        for(int k = n*i+j; k > 0; k--){
                                if(queue[k][2] < queue[k-1][2]){
                                        queue[k][2] += queue[k-1][2];
                                        queue[k-1][2] =  queue[k][2] - queue[k-1][2];
                                        queue[k][2] -= queue[k-1][2];
                                        queue[k][0] += queue[k-1][0];
                                        queue[k-1][0] =  queue[k][0] - queue[k-1][0];
                                        queue[k][0] -= queue[k-1][0];
                                        queue[k][1] += queue[k-1][1];
                                        queue[k-1][1] =  queue[k][1] - queue[k-1][1];
                                        queue[k][1] -= queue[k-1][1];
                                }
                        }
                }
        }
        /* printf("Your Graph:\n");
        for(int i = 0; i < n;i++){
                for(int j = 0; j < n;j++){
                        printf("%d ",graph[i][j]);
                }
                printf("\n");
        }
        for(int i = n; i < n*n;i++){
                printf("(%c)-->(%c) = %2d\n",65 + queue[i][0],65 + queue[i][1],queue[i][2]);
        } */
        int dist = 0;
        printf("Broadcast tree:\n");
        for(int i = n,count = 1; count <= n , i < n*n ; i++) {
            if (!(node[queue[i][1]])) {
                printf("(%c)-->(%c) = %2d\n",65 + queue[i][0],65 + queue[i][1],queue[i][2]);
                dist += queue[i][2];
                node[queue[i][0]] = 1;
                node[queue[i][1]] = 1;
                count++;
            }
        }
        printf("Total distsnce: %d",dist);
        return 0;
}