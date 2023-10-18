#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
function receiver is
    Rn := 0
    Do the following forever:
        if the packet received = Rn and the packet is error free then
            Accept the packet and send it to a higher layer
            Rn := Rn + 1
        else
            Refuse packet
        Send a Request for Rn : ack = Rn - 1 i.e. -1


function sender is
    Sb := 0
    Sm := N + 1
    Repeat the following steps forever:
        if you receive a request number where Rn > Sb i.e. (ack >= Sb) then
            Sm := (Sm − Sb) + Rn
            Sb := Rn
        if no packet is in transmission then
            Transmit a packet where Sb ≤ Sn ≤ Sm.  
            Packets are transmitted in order.
*/
bool receivePacket(int packetRn, bool isErrorFree);
void sendRequest(int requestedRn);
void transmitPacket();
void receiver();
void sender();

// Global variables
int frame_size;
int N  = 10;      // Window size
int Rn = 0;       // Request number Rn = Ack + 1
int Sn = 0;       // `Sb = 0` Sequence number  1 2 3 4 5 6
int Sb = 0;       // Sequence base   (1)2 3 4 5 6
int Sm = 11;      // Sequence max     1 2 3 4 5(6) 

int main() {
    int count = 0,n;
    printf("Enter size of frame: ");
    scanf("%d",&frame_size); //6
    printf("Enter sliding window size:");
    scanf("%d",&N); //5
    Sm = N;
    printf("Enter which nth frame is courrupted: ");
    scanf("%d",&n); //3

    if(N <= 0 || frame_size < N) {
            printf("Invalied inputs.");
            return 1;
    } printf("GoBack-%d ARQ:\n",N);

    for (int ack = -1; ack < frame_size;) {
        Sn = Sb;
        count++;
        printf("\n%2d. Frame %2d is send. ",count,Sn+1);
        if (count%n == 0){
            printf("(courrupted)");
            Sb = Sn;
            // ack = Sn-1;
            continue;
        }
        // else {
        //     Sm = (Sm - Sb) + ack+1;
        //     Sb = Sn;
        // }
        Sm = ack + (Sm - Sb + 1);
        Sb = ack + 1;
        Sn++;
    }

    //  for ( Sn = Sb; Sn < Sm; Sn++) {
    //         count++;
    //         printf("\n%2d. Frame %2d is send.",count,Sn);
    //        if (count%n == 0)
    //         {
    //             printf("(courrupted)");
    //             ack = (ack > Sb)? ack : Sb - 1;
    //             // set Sb = Sn;
    //         }
    //     }

    return 0;
}
// frame_size = 6
// N = 5 (window size)
// n = 3
//count    frame                  ack = Rn - 1
// 1.  fra 1 sent               |  1
// 2.  fra 2 sent               |  2
// 3.  fra 3 sent (courrupted)  |  2
// 4.  fra 4 sent               |  2
// 5.  fra 5 sent               |  2
// 6.  fra 6 sent (courrupted)  |  2
// 7.  fra 3 sent //timeout     |  3
// 8.  fra 4 sent               |  4
// 9.  fra 5 sent (courrupted)  |  4
// 10. fra 6 sent               |  4
// 11. fra 5 sent               |  5
// 12. fra 6 sent (courrupted)  |  5
// 13. fra 6 sent               |  6


// printf("\n%2d. Frame %2d is send.",count,Sn);
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