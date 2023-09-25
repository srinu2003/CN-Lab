#include<stdio.h>
#include<stdlib.h>

int main() {
	int w, i, f, *frames;

	printf("Enter window size:");
	scanf("%d", &w);
	printf("Enter number of frames to transmmit:");
	scanf("%d", &f);

	if (w <= 0 || f <= 0 ) {
        printf("Invalid inputs.\n");
        return 1;
	}

	frames = (int*)malloc(f * sizeof(int));
	printf("Enter %d frames:", f);
	for (i = 0; i < f; i++) {
	    scanf("%d", &frames[i]);
	}

	printf("----\nWith sliding window protocol the frames will be sent in the following manner(assuming no corruption of frames)\n");
	printf("After sending %d frames at each stage sender waits for acknowledgement sent by the receiver\n----", w);

	for (i = 0; i < f; i++) {
        if (i % w == 0) {
			printf("\nSender: ");
            for(int j = i; j < i + w && j < f; j++) {
            	printf("%d ", frames[j]);
            }
            printf("\n");
            printf("Acknowledgement received.\n");
        } else {
            // Send the next frame.
            printf("%d ", frames[i]);
        }
	}

	// If the number of frames to send is not a multiple of the window size, send the remaining frames without waiting for an acknowledgment.
	if (f % w != 0) {
	    printf("\nAcknowledgement received.\n");
	}
	return 0;
}
