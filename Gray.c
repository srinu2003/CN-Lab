#include<stdio.h>

void main() {
    unsigned long long bin;
    //Input
    printf("Enter a gray number: ");

    scanf("%llu", &bin);
    // printf("Binary equivalent: %u\n", bin);
    
    int dec = 0, base = 1;
    
    //Converting Binary to Decimal
    while (bin) {
        dec += (bin % 10) * base;
        bin /= 10;
        base *= 2;
    }

    // printf("Dec equivalent: %u\n", dec);
    int graydec = dec ^ (dec >> 1);//Getting gray code
    // printf("Gray code DEcimal equivalent: %u\n", graydec);
    
    int gray[32], index = 0;
    while (graydec > 0) gray[index++] = graydec % 2, graydec /= 2;
    printf("Gray code equivalent: ");
    while (index--) printf("%d", gray[index]);
    printf("\n");
    
}