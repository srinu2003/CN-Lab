#include <stdio.h>
#include <string.h>

int main() {
    char message[32]; 
    char divisor[] = "1001"; 

    printf("Enter a 32-bit message: ");
    scanf("%s", message);

    int m = strlen(message);
    int n = strlen(divisor);


    for (int i = 0; i < n - 1; i++) {
        message[m + i] = '0';
    }

    for (int i = 0; i < m; i++) {
        if (message[i] == '1') {
            for (int j = 0; j < n; j++) {
                message[i + j] = (message[i + j] == divisor[j]) ? '0' : '1';
            }
        }
    }

    for (int i = m; i < m + n - 1; i++) {
        if (message[i] == '1') {
            printf("Error detected!\n");
            return 0;
        }
    }

    printf("No error detected.\n");

    return 0;
}
