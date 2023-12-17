#include <stdio.h>
#include <string.h>
char data[20][20];
int n;
void main()
{
    int i, ch, j;
    char tmp[20][20];
    printf("Enter the number of frames:");
    scanf("%d", &n);
    for (i = 0; i <= n; i++)
    {
        if (i != 0)
        {
            printf("Frame%d: ", i);
            scanf("%s", data[i]);
        }
    }
    for (i = 0; i <= n; i++)
    {
        tmp[i][0] = 49 + strlen(data[i]);
        tmp[i][1] = '\0';
        strcat(tmp[i], data[i]);
    }
    printf("\n\t\t AT THE SENDER:\n");
    printf("Data as frames:\n");
    for (i = 1; i <= n; i++)
    {
        printf("frame%d: ", i);
        puts(tmp[i]);
    }
    printf("Data transmitted: ");
    for (i = 1; i <= n; i++)
        printf("%s", tmp[i]);
    printf("\n\t\t AT THE RECEIVER\n");
    printf("Data received after removing count char: ");
    for (i = 1; i <= n; i++)
    {
        ch = (int)(tmp[i][0] - 49);
        for (j = 1; j <= ch; j++)
            data[i][j - 1] = tmp[i][j];
        data[i][j - 1] = '\0';
    }
    for (i = 1; i <= n; i++)
        printf("%s", data[i]);
    printf("\nData as frames:\n");
    for (i = 1; i <= n; i++)
    {
        printf("Frame%d: ", i);
        puts(data[i]);
    }
}
