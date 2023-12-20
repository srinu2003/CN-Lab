#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Shifts the characters in the given string based on the provided shift value.
 * The shift value determines the number of positions each character should be shifted.
 * The mode parameter determines whether to shift the characters to the right (mode = 1) or to the left (mode = 0).
 * Only alphabetic characters are shifted, while non-alphabetic characters remain unchanged.
 *
 * @param data The string to be shifted.
 * @param mode The mode of shifting (1 for right shift, 0 for left shift).
 */
void DES_Shift(char* data, int mode) {
    int len = strlen(data), shift;
    printf("Enter the key: ");
    scanf("%d", &shift);
    shift  = (mode == 1) ? shift : 26 - shift;
    for (int i = 0; i < len; i++) {
        if (data[i] >= 'a' && data[i] <= 'z') {
            data[i] = 'a' + (data[i] - 'a' + shift) % 26;
        } else if (data[i] >= 'A' && data[i] <= 'Z') {
            data[i] = 'A' + (data[i] - 'A' + shift) % 26;
        }
    }
}

int main() {
    printf("1. Encrypt\n2. Decrypt\n3. Exit\n");
    char* data = NULL;
    int ch,size,shift;
    size_t buffer = 0;
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        getchar();
        switch (ch) {
        case 1:
            printf("Enter the message to encrypt: ");
            getline(&data, &buffer, stdin);
            DES_Shift(data, 1);
            printf("Encrypted message: %s\n", data);
            break;
        case 2:
            printf("Enter the message to decrypt: ");
            getline(&data, &buffer, stdin);
            DES_Shift(data, 0);
            printf("Decrypted message: %s\n", data);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        } free(data);
        data = NULL;
    }
    return 0;
}