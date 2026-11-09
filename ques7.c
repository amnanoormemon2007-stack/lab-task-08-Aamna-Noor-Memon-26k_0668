#include <stdio.h>

int findMax(int *p, int n)
{
    int max = *p;
    int i;

    for (i = 1; i < n; i++)
    {
        if (*(p + i) > max)
            max = *(p + i);
    }

    return max;
}

int findMin(int *p, int n)
{
    int min = *p;
    int i;

    for (i = 1; i < n; i++)
    {
        if (*(p + i) < min)
            min = *(p + i);
    }

    return min;
}

double findAverage(int *p, int n)
{
    int sum = 0;
    int i;

    for (i = 0; i < n; i++)
        sum += *(p + i);

    return (double)sum / n;
}

int countAbove(int *p, int n, double avg)
{
    int count = 0;
    int i;

    for (i = 0; i < n; i++)
    {
        if (*(p + i) > avg)
            count++;
    }

    return count;
}

void reverseArray(int *p, int n)
{
    int *start = p;
    int *end = p + n - 1;
    int temp;

    while (start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int searchMark(int *p, int n, int key)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (*(p + i) == key)
            return i + 1;
    }

    return -1;
}

int main()
{
    int marks[10];
    int i, key, position;
    int passCount = 0;

    double avg;

    printf("Enter marks of 10 students (0-100):\n");

    for (i = 0; i < 10; i++)
    {
        do
        {
            printf("Student %d: ", i + 1);
            scanf("%d", &marks[i]);
        } while (marks[i] < 0 || marks[i] > 100);
    }

    printf("\nOriginal Array:\n");

    for (i = 0; i < 10; i++)
        printf("%d ", marks[i]);

    printf("\n\nHighest Marks: %d\n", findMax(marks, 10));
    printf("Lowest Marks: %d\n", findMin(marks, 10));

    avg = findAverage(marks, 10);

    printf("Average Marks: %.2f\n", avg);

    printf("Students Above Average: %d\n",
           countAbove(marks, 10, avg));

    for (i = 0; i < 10; i++)
    {
        if (marks[i] >= 40)
            passCount++;
    }

    printf("Pass Count: %d\n", passCount);

    printf("\nEnter mark to search: ");
    scanf("%d", &key);

    position = searchMark(marks, 10, key);

    if (position != -1)
        printf("Mark found at position %d\n", position);
    else
        printf("Mark not found!\n");

    reverseArray(marks, 10);

    printf("\nReversed Array:\n");

    for (i = 0; i < 10; i++)
        printf("%d ", marks[i]);

    printf("\n");

    return 0;
}