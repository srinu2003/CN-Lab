#include <stdio.h>

// Function to calculate parity bits
void calculateParityBits(int data[11], int parityBits[4]) {
    parityBits[0] = data[0] ^ data[1] ^ data[3] ^ data[4] ^ data[6] ^ data[8] ^ data[10];
    parityBits[1] = data[0] ^ data[2] ^ data[3] ^ data[5] ^ data[6] ^ data[9] ^ data[10];
    parityBits[2] = data[1] ^ data[2] ^ data[3] ^ data[7] ^ data[8] ^ data[9] ^ data[10];
    parityBits[3] = data[4] ^ data[5] ^ data[6] ^ data[7] ^ data[8] ^ data[9] ^ data[10];
}

int main() {
    int data[11], encodedData[15], parityBits[4];

    printf("Enter 11 bits of data: ");
    for (int i = 0; i < 11; i++) {
        scanf("%d", &data[i]);
    }

    calculateParityBits(data, parityBits);

    encodedData[0] = parityBits[0];
    encodedData[1] = parityBits[1];
    encodedData[2] = data[0];
    encodedData[3] = parityBits[2];
    encodedData[4] = data[1];
    encodedData[5] = data[2];
    encodedData[6] = data[3];
    encodedData[7] = parityBits[3];
    encodedData[8] = data[4];
    encodedData[9] = data[5];
    encodedData[10] = data[6];
    encodedData[11] = data[7];
    encodedData[12] = data[8];
    encodedData[13] = data[9];
    encodedData[14] = data[10];

    printf("Encoded data: ");
    for (int i = 0; i < 15; i++) {
        printf("%d", encodedData[i]);
    }

    return 0;
}