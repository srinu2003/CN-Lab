#include<stdio.h>
void main(){
    int *ptr,msg;
    printf("Enter numbers:");
    for( ptr = &msg; *ptr != 9 ; ptr++)
    {
        scanf("%d",ptr);
    }
    ptr = &msg;
    printf("Numbers entered : ");
    for( ptr = &msg; *ptr <8 ; ptr++)
    {
        printf(",%d",*ptr);
    }
    
}