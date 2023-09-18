#include<stdlib.h>
#include<stdio.h>

void getValues(int *x, int *msg) {
    *x = 5;
    msg = (int*)malloc(*x * sizeof(int));
    for(int i = 0; i < *x; i++) {
        msg[i] = i;
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