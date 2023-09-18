#include <stdlib.h>
#include <stdio.h>

void getValues(int *n, int **msg) {
    *n = 5;
    *msg = (int*)malloc(*n * sizeof(int));
    for(int i = 0; i < *n; i++) {
        (*msg)[i] = i;
    }
}

int main() {
    int a;
    int *b;
    getValues(&a, &b);
    printf("a: %d\n", a);  // a: 5
    for(int i = 0; i < a; i++) {
        printf("b[%d]: %d\n", i, b[i]);  // b[i]: i
    }
    free(b);
    return 0;
}