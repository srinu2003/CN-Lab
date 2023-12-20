#include <stdio.h>
int main()
{
    int in, out, buck_size, n, store = 0;
    printf("Enter bucket size, outgoing rate and no of inputs: ");
    scanf("%d %d %d", &buck_size, &out, &n);
    while (n != 0)
    {
        printf("Enter the in packet size : ");
        scanf("%d", &in);
        printf("in packet size: %d\n", in);
        if (in <= (buck_size - store)) {
            store += in;
            printf("Bucket buffer size %d out of %d\n", store, buck_size);
        } else {
            printf("Dropped %d no of packets \n", in - (buck_size - store));
            printf("Bucket buffer size %d out of: %d\n", buck_size, buck_size);
            store = buck_size;
        }
        store = store - out;
        printf("After outgoing %d packets left out of %d in buffer:\n", store, buck_size);
        n--;
    }
}