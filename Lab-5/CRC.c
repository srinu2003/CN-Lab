#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void get_crc(char *msg, char *div,int *m,int *n) {
    *m = strlen(msg);
    *n = strlen(div);
    printf("CRC code is: %s",msg);
    for (int i = 0; i < *n - 1; i++) { msg[*m + i] = '0';}
    for (int i = 0; i < *m; i++) {
        if (msg[i] == '1') {
            for (int j = 0; j < *n; j++) {
            msg[i + j] = (msg[i + j] == div[j]) ? '0' : '1';
            }
        }
    }
    return ;
}
void main(){
    char msg[100],div[10];
    int n=0,m=0,ch,i,j;
    printf("1.Generate\n2.Detect\n3.Exit");
    while(1){
        printf("\nEnter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:/*Generation*/;
            printf("Enter Message: ");
            scanf("%s",msg);
            printf("Enter equation Coefficient:");
            scanf("%s",div);
            get_crc(msg,div,&m,&n);
            printf(" ");
            for (i = m; i < m + n - 1; i++) {
                printf("%c",msg[i]);
            }
            break;
            case 2:
            printf("Enter Sender's CRC code: ");
            scanf("%s",msg);
            get_crc(msg,div,&m,&n);
            for (i = m; i < m + n - 1; i++) {
                if (msg[i] == '1') {
                    printf("\nError detected!");
                    break;
                }
            }
            printf("\nNo error detected.");
            break;
            case 3:exit(0);
            default: printf("Invalid Choice! Try again.");
        }
    }
}