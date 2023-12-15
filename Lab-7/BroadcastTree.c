#include<stdio.h>
struct edge{
    int s,d,t; /*s:source, d:destination, t:traffic/travel-time*/
};
int main(){
    int n, graph[10][10], node[10] = {0,0,0,0,0,0,0,0,0,0};
    struct edge edgeq[100],temp; /*An Edges Queue 'edgeq' for storing sorted-paths*/
    printf("Enter no.of nodes:");
    scanf("%d",&n);
    
    for (int i = 0; i<n;i++){
        for(int j = 0; j < n;j++){
            if (i<j) {
                printf("Enter traffic between (%c)--(%c): ",65+i,65+j);
                scanf("%d",&graph[i][j]);
            } else if (i==j) {
                graph[i][j] = -2;
            } else {
                graph[i][j] = graph[j][i];
            }
            edgeq[n*i+j].s = i;
            edgeq[n*i+j].d = j;
            edgeq[n*i+j].t = graph[i][j];
            /* Inserssion Sort: for all the edges */
            for(int k = n*i+j; k > 0; k--){
                if(edgeq[k].t < edgeq[k-1].t){
                    temp       = edgeq[k];
                    edgeq[k]   = edgeq[k-1];
                    edgeq[k-1] = temp;
                }
            }
        }
    }
    int cost = 0;
    printf("\nBroadcast tree:\n");
    for(int i = n,count = 1; count < n , i < n*n ; i++) { /*First n edges are '-2'*/
        if (!(node[edgeq[i].d]) && edgeq[i].t > 0 ) {
            printf("(%c)-->(%c) = %2d\n",65 + edgeq[i].s,65 + edgeq[i].d,edgeq[i].t);
            cost += edgeq[i].t;
            node[edgeq[i].s] = 1;
            node[edgeq[i].d] = 1;
            count++;
        }
    }
    printf("Total distsnce: %d",cost);
    return 0;
}
