#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    char node;
    int cost;
}node;

int dijkstra(unsigned int **graph,int SIZE,int source,int target){
    printf("Number:%u\n",graph[1][4]);
    return 0;
}

int main(){
    unsigned int graph[7][7];
    //  = {
    //     {0, 3, 0, 0, 1, 1, 8},
    //     {3, 0, 4, 1, 0, 1, 6},
    //     {0, 4, 0, 1, 2, 0, 0},
    //     {0, 1, 1, 0, 5, 0, 0},
    //     {0, 0, 2, 5, 0, 0, 0},
    //     {1, 1, 0, 0, 0, 0, 0},
    //     {8, 6, 0, 0, 0, 0, 0}
    // };


    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            // if (graph[i][j] == 0) {
            //     graph[i][j] = -1;
            // }
            // if (i == j) {
            //     graph[i][j] = 0;
            // }
            // graph[i][j] = (i == j) ? 0 : (graph[i][j] == 0) ? -1 : graph[i][j];
            graph[i][j] = (i == j) ? 0 : (graph[i][j] == 0) ? -1 : 5;
        }
    
    }
    dijkstra((int **)graph, 7, 0, 6);
    // unsigned int i = 0 - 1;
    // printf("Number:%u\n",graph[1][4]);
    return 0;
}