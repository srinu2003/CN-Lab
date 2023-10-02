#include <stdio.h>
#include <string.h>

void main() {
    char gray[32], bin[32];
    printf("Enter a Gray code: ");
    scanf("%s", gray);
    int len = strlen(gray),i;
    
    bin[0] = gray[0];
    for (i = 0; i < len - 1; i++) {
        bin[i + 1] = (gray[i + 1] == '0') ? bin[i] : (bin[i] == '0') ? '1' : '0';
    }
    bin[i + 1] = '\0';
    
    printf("Binary equivalent: %s\n", bin);
}