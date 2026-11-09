#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    int hotterCount = 0;

    double *temp;
    double *ptr;

    do
    {
        printf("Enter number of days (1-10): ");
        scanf("%d", &n);
    } while (n < 1 || n > 10);

    temp = (double *)malloc(n * sizeof(double));

    if (temp == NULL)
    {
        printf("Memory allocation failed!");
        return 1;
    }

    ptr = temp;

    for (i = 0; i < n; i++)
    {
        do
        {
            printf("Enter temperature for day %d: ", i + 1);
            scanf("%lf", &temp[i]);
        } while (temp[i] < -10 || temp[i] > 55);
    }

    printf("\n===== TEMPERATURE RECORD =====\n");

    for (i = 0; i < n; i++)
    {
        printf("Day %d: %.2f at address %p\n",
               i + 1, *(ptr + i), (void *)(ptr + i));
    }

    double hottest = *ptr;
    double coldest = *ptr;

    ptr = temp;

    for (i = 0; i < n; i++)
    {
        if (*ptr > hottest)
            hottest = *ptr;

        if (*ptr < coldest)
            coldest = *ptr;

        if (*ptr > 40)
            hotterCount++;

        ptr++;
    }

    printf("\nHottest Temperature: %.2f\n", hottest);
    printf("Coldest Temperature: %.2f\n", coldest);
    printf("Days Above 40: %d\n", hotterCount);

    free(temp);
    temp = NULL;

    printf("\nMemory Released Successfully!\n");

    return 0;
}