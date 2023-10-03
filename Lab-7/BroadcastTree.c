#include<stdio.h>
struct p{
        int s,d,c;
};
int main(){
        int n;
        printf("Enter no.of nodes:");
        scanf("%d",&n);
        int graph[10][10],node[10] = {0,0,0,0,0,0,0,0,0,0};
        struct p path[100],temp;
        printf("Enter distance between nodes:\n ");
        for(int i = 0; i < n;i++){
            printf(" %c",65+i);
        }printf("\n");
        for (int i = 0; i<n;i++){
            printf("%c ",65+i);
                for(int j = 0; j < n;j++){
                        scanf("%d",&graph[i][j]);
                        if(i==j){ graph[i][j] = -1;}
                        path[n*i+j].s = i;
                        path[n*i+j].d = j;
                        path[n*i+j].c = graph[i][j];
                        /* Inserssion Sort */
                        for(int k = n*i+j; k > 0; k--){
                                if(path[k].c < path[k-1].c){
                                    temp     = path[k];
                                    path[k]   = path[k-1];
                                    path[k-1] = temp;
                                }
                        }
                }
        }
        int dist = 0;
        printf("Broadcast tree:\n");
        for(int i = n,count = 1; count <= n , i < n*n ; i++) {
            if (!(node[path[i].d])) {
                printf("(%c)-->(%c) = %2d\n",65 + path[i].s,65 + path[i].d,path[i].c);
                dist += path[i].c;
                node[path[i].s] = 1;
                node[path[i].d] = 1;
                count++;
            }
        }
        printf("Total distsnce: %d",dist);
        return 0;
}