#include <stdio.h>

void readMarks(int *m1, int *m2, int *m3)
{
    do
    {
        printf("Enter Subject 1 marks (0-100): ");
        scanf("%d", m1);
    } while (*m1 < 0 || *m1 > 100);

    do
    {
        printf("Enter Subject 2 marks (0-100): ");
        scanf("%d", m2);
    } while (*m2 < 0 || *m2 > 100);

    do
    {
        printf("Enter Subject 3 marks (0-100): ");
        scanf("%d", m3);
    } while (*m3 < 0 || *m3 > 100);
}

void calculateStats(int m1, int m2, int m3,
                    int *total, double *average,
                    int *highest, int *lowest)
{
    *total = m1 + m2 + m3;

    *average = (double)*total / 3;

    *highest = m1;
    *lowest = m1;

    if (m2 > *highest)
        *highest = m2;

    if (m3 > *highest)
        *highest = m3;

    if (m2 < *lowest)
        *lowest = m2;

    if (m3 < *lowest)
        *lowest = m3;
}

void swapMarks(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void addGraceMarks(int *mark, int grace)
{
    if (*mark >= 35 && *mark <= 39)
    {
        if (grace > 5)
            grace = 5;

        if (grace < 0)
            grace = 0;

        if (*mark + grace > 40)
            grace = 40 - *mark;

        *mark += grace;
    }
}

void findGrade(double avg, char *grade, char *remarks)
{
    if (avg >= 80)
    {
        *grade = 'A';
        remarks[0] = 'E';
        remarks[1] = 'x';
        remarks[2] = 'c';
        remarks[3] = 'e';
        remarks[4] = 'l';
        remarks[5] = 'l';
        remarks[6] = 'e';
        remarks[7] = 'n';
        remarks[8] = 't';
        remarks[9] = '\0';
    }
    else if (avg >= 70)
    {
        *grade = 'B';
        sprintf(remarks, "Good");
    }
    else if (avg >= 60)
    {
        *grade = 'C';
        sprintf(remarks, "Good");
    }
    else if (avg >= 50)
    {
        *grade = 'D';
        sprintf(remarks, "Needs Improvement");
    }
    else
    {
        *grade = 'F';
        sprintf(remarks, "Needs Improvement");
    }
}

void incrementByValue(int x)
{
    x++;
}

void incrementByReference(int *x)
{
    (*x)++;
}

int main()
{
    int student, m1, m2, m3;
    int total, highest, lowest;
    int grace;

    double average;
    char grade;
    char remarks[30];

    printf("Enter grace marks (0-5): ");
    scanf("%d", &grace);

    if (grace < 0 || grace > 5)
    {
        printf("Invalid grace marks!\n");
        return 0;
    }

    printf("\n===== STUDENT RESULT SYSTEM =====\n");

    printf("Student   Total   Average   Grade   Remarks\n");

    for (student = 1; student <= 5; student++)
    {
        printf("\nStudent %d\n", student);

        readMarks(&m1, &m2, &m3);

        addGraceMarks(&m1, grace);
        addGraceMarks(&m2, grace);
        addGraceMarks(&m3, grace);

        calculateStats(m1, m2, m3,
                       &total, &average, &highest, &lowest);

        if (m1 < m2)
            swapMarks(&m1, &m2);

        if (m2 < m3)
            swapMarks(&m2, &m3);

        if (m1 < m2)
            swapMarks(&m1, &m2);

        findGrade(average, &grade, remarks);

        printf("\nSorted Marks: %d %d %d\n", m1, m2, m3);
        printf("Highest: %d\n", highest);
        printf("Lowest: %d\n", lowest);

        printf("%d       %d      %.2f      %c       %s\n",
               student, total, average, grade, remarks);
    }

    printf("\n===== INCREMENT COMPARISON =====\n");

    int x = 10;

    printf("Original Value: %d\n", x);

    incrementByValue(x);

    printf("After Increment By Value: %d\n", x);

    incrementByReference(&x);

    printf("After Increment By Reference: %d\n", x);

    /*
       Increment by value changes only the local copy.
       Increment by reference changes the original variable using its address.
    */

    return 0;
}