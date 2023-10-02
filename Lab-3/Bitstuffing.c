#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int *num,*cp,i,j,k,count,n;
    printf("Enter the number of bits: ");
    scanf("%d", &n);
    num = (int*)malloc(n * sizeof(int));
    cp = (int*)malloc(n * sizeof(int));
    printf("Enter sending bits: ");
    for(i = 0; i < n; ++i) {
        scanf("%d",&num[i]);
    }
    for ( i = 0, j = 0, count = 1; i < n; i++, j++) {
        cp[j]=num[i];
        if(num[i]==1) {
            for(k = i + 1; num[k] == 1 && k < n && count < 5; k++,i++) {
                cp[++j] = num[k];
                if(++count == 5) {
                    cp[++j] = 0;
                }
            }
        }
    }
    printf("After Bit Stuffing: ");
    for(i=0; i<j; i++)
    printf("%d ",cp[i]);
    free(num);
    return 0;
}