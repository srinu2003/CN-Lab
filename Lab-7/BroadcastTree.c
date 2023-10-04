#include<stdio.h>
struct path{
    int s,d,t; /*s:source, d:destination, t:traffic/travel-time*/
};
int main(){
    int n;
    printf("Enter no.of nodes:");
    scanf("%d",&n);

    int graph[10][10],node[10] = {0,0,0,0,0,0,0,0,0,0};
    struct path pathq[100],temp;

    printf("Enter distance between nodes:\n ");
    for(int i = 0; i < n;i++){
        printf(" %c",65+i);
    }printf("\n");
    for (int i = 0; i<n;i++){
        printf("%c ",65+i);
        for(int j = 0; j < n;j++){
            scanf("%d",&graph[i][j]);
            if(i==j){ graph[i][j] = -1;}
            pathq[n*i+j].s = i;
            pathq[n*i+j].d = j;
            pathq[n*i+j].t = graph[i][j];
            /* Inserssion Sort: for all the paths */
            for(int k = n*i+j; k > 0; k--){
                if(pathq[k].t < pathq[k-1].t){
                    temp     = pathq[k];
                    pathq[k]   = pathq[k-1];
                    pathq[k-1] = temp;
                }
            }
        }
    }
    int dist = 0;
    printf("Broadcast tree:\n");
    for(int i = n,count = 1; count <= n , i < n*n ; i++) { /*First n paths are '-1'*/
        if (!(node[pathq[i].d]) && pathq[i].t > 0 ) {
            printf("(%c)-->(%c) = %2d\n",65 + pathq[i].s,65 + pathq[i].d,pathq[i].t);
            dist += pathq[i].t;
            node[pathq[i].s] = 1;
            node[pathq[i].d] = 1;
            count++;
        }
    }
    printf("Total distsnce: %d",dist);
    return 0;
}
// 0 1 -1 4 3 -1 1 0 -1 4 2 -1 -1 -1 0 -1 4 5 4 4 -1 0 4 -1 3 2 4 4 0 7 -1 -1 5 -1 -1 0