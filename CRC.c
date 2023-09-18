#include <stdio.h>
#include <stdbool.h>

// Function to perform CRC error detection
bool performCRCDetection(int data[], int dataLength, int divisor[], int divisorLength) {
    // Append zeros to the data
    int appendedData[dataLength + divisorLength - 1];
    for (int i = 0; i < dataLength; i++) {
        appendedData[i] = data[i];
    }
    for (int i = dataLength; i < dataLength + divisorLength - 1; i++) {
        appendedData[i] = 0;
    }

    // Perform division
    for (int i = 0; i < dataLength; i++) {
        if (appendedData[i] == 1) {
            for (int j = 0; j < divisorLength; j++) {
                appendedData[i + j] ^= divisor[j];
            }
        }
    }

    // Check if remainder is zero
    for (int i = dataLength; i < dataLength + divisorLength - 1; i++) {
        if (appendedData[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    // Example data and divisor
    int data[] = {1, 0, 1, 0, 0, 1, 0, 1};
    int dataLength = sizeof(data) / sizeof(data[0]);
    int divisor[] = {1, 0, 1, 1};
    int divisorLength = sizeof(divisor) / sizeof(divisor[0]);

    // Perform CRC error detection
    bool errorDetected = performCRCDetection(data, dataLength, divisor, divisorLength);

    // Print result
    if (errorDetected) {
        printf("Error detected!\n");
    } else {
        printf("No error detected.\n");
    }

    return 0;
}