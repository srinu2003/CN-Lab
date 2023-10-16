#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool receivePacket(int packetRn, bool isErrorFree);
void sendRequest(int requestedRn);
void transmitPacket();
void receiver();
void sender();

// Global variables
int frame_size;
int N  = 10;      // Window size
int Rn = 0;       // Request number
int Sn = 0;       // Sequence number
int Sb = 0;       // Sequence base
int Sm = 11;      // Sequence max

int main() {
    int count = 0,n;
    printf("Enter size of frame: ");
    scanf("%d",&frame_size);
    printf("Enter sliding window size:");
    scanf("%d",&N);
    Sm = N;
    printf("Enter which nth frame is courrupted: ");
    scanf("%d",&n);
    
    if(N <= 0 || frame_size < N) {
            printf("Invalied inputs.");
            return 1;
    } printf("GoBack-%d ARQ:\n",N);
    for (int frame = 0; frame < frame_size;) {

        for ( Sn = Sb; Sn < Sm; Sn++) 
        {
            printf("\n%2d. Frame %2d is send.",count,Sn);
        }
    }

    return 0;
}

// // Simulate packet reception
// bool receivePacket(int packetRn, bool isErrorFree) {
//     if (packetRn == Rn && isErrorFree) {
//         // Accept the packet and send it to a higher layer
//         printf("Received packet with Rn=%d (Accepted)\n", Rn);
//         Rn++;
//         return true;
//     } else {
//         // Refuse the packet
//         printf("Received packet with Rn=%d (Refused)\n", packetRn);
//         return false;
//     }
// }

// // Send a request for a specific Rn
// void sendRequest(int requestedRn) {
//     printf("Sending request for Rn=%d\n", requestedRn);
// }

// // Simulate packet transmission
// void transmitPacket() {
//     if (Sn >= Sb && Sn < Sm) {
//         printf("Transmitting packet with Sn=%d\n", Sn);
//         Sn++;
//     }
// }

// // Receiver function
// void receiver() {
//     Rn = 0;
//     while (true) {
//         // Simulate receiving a packet with request number Rn
//         int receivedRn = rand() % (N * 2); // Generate a random Rn for simulation
//         bool isErrorFree = rand() % 2;     // Simulate packet errors randomly

//         if (receivePacket(receivedRn, isErrorFree)) {
//             // Packet was accepted, increment Rn
//             Rn++;
//         }
//         // Always send a request for the current Rn
//         sendRequest(Rn);
//     }
// }

// // Sender function
// void sender() {
//     Sb = 0;
//     Sm = N + 1;
//     while (true) {
//         // Simulate receiving a request number
//         int requestedRn = rand() % (N * 2); // Generate a random Rn for simulation

//         // Update Sm and Sb based on the received request number
//         if (requestedRn > Sb) {
//             Sm = (Sm - Sb) + requestedRn;
//             Sb = requestedRn;
//         }

//         // Simulate packet transmission
//         transmitPacket();
//     }
// }