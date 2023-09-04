#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i,count=0,prev=-1;
    printf("Enter the number of bits: ");
    scanf("%d", &n);
    int *num = (int*)malloc(n * sizeof(int));
    printf("Enter the bits: ");
    for(i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
    }
    printf("Bit Straped: ");
    // prev = num[0];
    for(i = 0; i < n; ++i) {
        if (count==5)
        {
            printf("%d ",*(num+i));
        }
        if (prev==num[i])
        {
            count++;
        } else {
            count=0;
        }
        if (count==5)
        {
        printf("%d ", *(num + i)^1);
        }
        prev=num[i];
    }
    free(num);
    return 0;
}
