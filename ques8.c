#include <stdio.h>
#include <stdlib.h>

void display(int *p, int n)
{
    int i;

    printf("\nStock: ");

    for (i = 0; i < n; i++)
        printf("%d ", *(p + i));

    printf("\n");
}

void showTotalAndLowest(int *p, int n)
{
    int i, total = 0;
    int lowest = *p;

    for (i = 0; i < n; i++)
    {
        total += *(p + i);

        if (*(p + i) < lowest)
            lowest = *(p + i);
    }

    printf("Total Stock: %d\n", total);
    printf("Lowest Stock: %d\n", lowest);
}

void sortStock(int *p, int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (*(p + j) > *(p + j + 1))
            {
                temp = *(p + j);
                *(p + j) = *(p + j + 1);
                *(p + j + 1) = temp;
            }
        }
    }
}

int main()
{
    int n, i, choice, position, value;
    int *stock, *newStock;

    do
    {
        printf("Enter starting size (3-8): ");
        scanf("%d", &n);
    } while (n < 3 || n > 8);

    stock = (int *)malloc(n * sizeof(int));

    if (stock == NULL)
    {
        printf("Memory allocation failed!");
        return 1;
    }

    printf("Enter stock quantities:\n");

    for (i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d", &stock[i]);
    }

    do
    {
        printf("\n===== GROCERY STOCK MENU =====\n");
        printf("1. Display Stock\n");
        printf("2. Update Stock\n");
        printf("3. Insert New Item\n");
        printf("4. Delete Item\n");
        printf("5. Sort Stock\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                display(stock, n);
                break;

            case 2:
                printf("Enter position to update (1-%d): ", n);
                scanf("%d", &position);

                if (position >= 1 && position <= n)
                {
                    printf("Enter new stock value: ");
                    scanf("%d", &value);

                    stock[position - 1] = value;

                    showTotalAndLowest(stock, n);
                }
                else
                    printf("Invalid position!\n");

                break;

            case 3:
                printf("Enter insertion position (1-%d): ", n + 1);
                scanf("%d", &position);

                if (position >= 1 && position <= n + 1)
                {
                    printf("Enter new stock value: ");
                    scanf("%d", &value);

                    newStock = (int *)malloc((n + 1) * sizeof(int));

                    if (newStock == NULL)
                    {
                        printf("Memory allocation failed!\n");
                        break;
                    }

                    for (i = 0; i < position - 1; i++)
                        newStock[i] = stock[i];

                    newStock[position - 1] = value;

                    for (i = position; i <= n; i++)
                        newStock[i] = stock[i - 1];

                    free(stock);

                    stock = newStock;
                    n++;

                    showTotalAndLowest(stock, n);
                }
                else
                    printf("Invalid position!\n");

                break;

            case 4:
                if (n <= 1)
                {
                    printf("Cannot delete the last item!\n");
                    break;
                }

                printf("Enter position to delete (1-%d): ", n);
                scanf("%d", &position);

                if (position >= 1 && position <= n)
                {
                    newStock = (int *)malloc((n - 1) * sizeof(int));

                    if (newStock == NULL)
                    {
                        printf("Memory allocation failed!\n");
                        break;
                    }

                    for (i = 0; i < position - 1; i++)
                        newStock[i] = stock[i];

                    for (i = position - 1; i < n - 1; i++)
                        newStock[i] = stock[i + 1];

                    free(stock);

                    stock = newStock;
                    n--;

                    showTotalAndLowest(stock, n);
                }
                else
                    printf("Invalid position!\n");

                break;

            case 5:
                sortStock(stock, n);

                printf("Stock Sorted Successfully!\n");

                display(stock, n);
                showTotalAndLowest(stock, n);

                break;

            case 6:
                printf("Exiting Program...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 6);

    free(stock);
    stock = NULL;

    printf("Memory Released Successfully!\n");

    return 0;
}