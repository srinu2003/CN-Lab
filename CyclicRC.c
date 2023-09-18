#include <stdio.h>
#include <string.h>

int main() {
    char message[32]; // Message (32 bits)
    char divisor[] = "1001"; // CRC divisor

    printf("Enter a 32-bit message: ");
    scanf("%s", message);

    int m = strlen(message);
    int n = strlen(divisor);

    // Append zeros for CRC
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

    // Check if the remainder is all zeros
    for (int i = m; i < m + n - 1; i++) {
        if (message[i] == '1') {
            printf("Error detected!\n");
            return 0;
        }
    }

    printf("No error detected.\n");

    return 0;
}
