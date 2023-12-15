#include <stdio.h>
#include <stdlib.h>

// Function prototype
void processArray(int rows, int cols, int **arr);

int main() {
    // Define the dimensions of the 2D array
    int rows = 3;
    int cols = 4;

    // Dynamically allocate memory for an array of pointers
    int **myArray = (int **)malloc(rows * sizeof(int *));

    // Dynamically allocate memory for each row
    for (int i = 0; i < rows; i++) {
        myArray[i] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the 2D array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            myArray[i][j] = i * cols + j + 1;
        }
    }

    // Pass the 2D array to the function
    processArray(rows, cols, myArray);

    // Free the dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        free(myArray[i]);
    }
    free(myArray);

    return 0;
}

// Function definition
void processArray(int rows, int cols, int **arr) {
    // Access elements of the 2D array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
