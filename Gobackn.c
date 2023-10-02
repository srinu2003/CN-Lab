#include<stdio.h>
int main() {
	int ws,sent,ack=-1,i;
	printf("Enter window size: ");
	scanf("%d",&ws);
	while(1) {
		for( sent = ack+1; sent < ws; sent++) {
				printf("Frame %d has been transmitted.\n",sent);
			}
			printf("\nPlease enter last Acknowledgement received: ");
			scanf("%d",&ack);

			if(ack == ws-1) break;
	}
    return 0;
}