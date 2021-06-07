#include <stdio.h>
int main()
{
    int i, j, sum = 0, n;
    int d[20];
    int disk;
    int temp=0, max=0;
    int temp1;
    printf("enter number of location\t");
    scanf("%d", &n);
    printf("enter position of head\t");
    scanf("%d", &disk);
    printf("enter elements of disk queue\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &d[i]);
    }
    d[n] = disk;
    n = n + 1;
    for (i = 0; i < n; i++) 
    {
        for (j = i; j < n; j++)
        {
            if (d[i] > d[j])
            {
                temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
    }
    max = d[n];
    for (i = 0; i < n; i++) 
    {
        if (disk == d[i])
        {
            temp1 = i;
            break;
        }
    }
    for (i = temp1; i >= 0; i--)
    {
        printf("%d->", d[i]);
    }
    printf("Start->");
    for (i = temp1 + 1; i < n; i++)
    {
        printf("%d->", d[i]);
    }
    sum = disk + max;
    printf("completed");
    printf("\nTotal seeks %d\n", sum);
    return 0;
}