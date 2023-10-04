# COMPUTER NETWORKS LAB EXPERIEMENTS
![C-Programming](https://img.shields.io/badge/C-programming.svg) ![GCC](https://img.shields.io/badge/GCC-6.3.0-1.svg) 

This repository contains C programs for the [`CN-Lab`](https://github.com/srinu2003/CN-Lab) course.

## Contents 
### MID-1
- [`Lab-1`](<Lab-1>)
    1. Binary to Graycode
    2. Graycode to Binry
+ [`Lab-2`](<Lab-2>)
    1. Hamming Code
+ [`Lab-3`](<Lab-3>)
    1. Bitstuffing
+ [`Lab-4`](<Lab-4>)
    1. Charecter Count
    2. Charecter Stuffing
+ [`Lab-5`](<Lab-5>)
    1. Cyclic Redundency Code
+ [`Lab-6`](<Lab-6>)
    1. Sliding Window Protocol
    2. Go Back-N Protocol
    3. Dijkstra's algorithm for Network Traffic
+ [`Lab-7`](<Lab-7>)
    1. Minimum cost Spanning tree for Broadcast tree

<!-- - [`Lab-7`](<Lab-7>)
    1. KnapSack (Greedy)
- [`INTERNAL 1`](<INTERNAL 1>)
    1. Knapsack (Greedy)
- [`Lab-8`](<Lab-8>)
    1. Prims
    2. Kruskals
- [`Lab-9`](<Lab-9>)
    1. JobSequence (Greedy)
    2. Single Source Shortest Path
- [`Lab-10`](<Lab-10>)
    1. N Queen's
    2. Optimal BST
    3. Knapsack (Dynamic)
- [`Lab-11`](<Lab-11>)
    1. Sum of Subset (Backtracking)
    2. Graph Colouring (Backtracking)
    3. All Pair Shortest Path
    4. Travelling Scales Person
- [`INTERNAL 2`](<INTERNAL 2>)
    1. All Pair Shortest Path (Dynamic)
    2. Applets (Checkbox, Textfield) -->


<!-- ## License
This repository is licensed under the MLRITM License.
I hope this is helpful! Let me know if you have any other questions. -->
```c
#include<stdio.h>
// struct path{
//     int s,d,t; /*s:source, d:destination, t:traffic/travel-time*/
// };
int main(){
    int n;
    printf("Enter no.of nodes:");
    scanf("%d",&n);

    int graph[10][10],node[10] = {0,0,0,0,0,0,0,0,0,0};
    // struct path pathq[100],temp;

    printf("Enter distance between nodes:\n ");
    for(int i = 0; i < n;i++){
        printf(" %c",65+i);
    }printf("\n");
    for (int i = 0; i<n;i++){
        printf("%c ",65+i);
        
        for(int j = i; j < n;j++){
            
            // scanf("%d",&graph[i][j]);
            if(i==j){ graph[i][j] = -1;}
            // pathq[n*i+j].s = i;
            // pathq[n*i+j].d = j;
            // pathq[n*i+j].t = graph[i][j];
            /* Inserssion Sort: for all the paths */
            // for(int k = n*i+j; k > 0; k--){
            //     if(pathq[k].t < pathq[k-1].t){
            //         temp     = pathq[k];
            //         pathq[k]   = pathq[k-1];
            //         pathq[k-1] = temp;
            //     }
            }
        }
    }
    // int dist = 0;
    // printf("Broadcast tree:\n");
    // for(int i = n,count = 1; count <= n , i < n*n ; i++) { /*First n paths are '-1'*/
    //     if (!(node[pathq[i].d]) && pathq[i].t > 0 ) {
    //         printf("(%c)-->(%c) = %2d\n",65 + pathq[i].s,65 + pathq[i].d,pathq[i].t);
    //         dist += pathq[i].t;
    //         node[pathq[i].s] = 1;
    //         node[pathq[i].d] = 1;
    //         count++;
    //     }
    // }
    // printf("Total distsnce: %d",dist);
    return 0;
}
// 0 1 -1 4 3 -1 1 0 -1 4 2 -1 -1 -1 0 -1 4 5 4 4 -1 0 4 -1 3 2 4 4 0 7 -1 -1 5 -1 -1 0```