#include <stdio.h>
#include <string.h>

int main() {
    char bin[32], gray[32];
    printf("Enter a Binary code: ");
    scanf("%s", bin);
    
    gray[0] = bin[0];
    for (int i = 1; bin[i]; i++)
        gray[i] = (bin[i] == bin[i - 1]) ? '0' : '1';
    
    gray[strlen(bin)] = '\0';
    
    printf("Gray code equivalent: %s\n", gray);
    return 0;
    
}