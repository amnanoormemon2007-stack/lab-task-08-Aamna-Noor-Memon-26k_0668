#include <stdio.h>

int main()
{
    double costPrice, sellPrice, quantity;
    double totalCost, totalSales, profitLoss;
    double profitPercentage;

    double *ptrCost = &costPrice;
    double *ptrSell = &sellPrice;
    double *ptrQuantity = &quantity;

    double *ptrTotalCost = &totalCost;
    double *ptrTotalSales = &totalSales;
    double *ptrProfitLoss = &profitLoss;
    double *ptrPercentage = &profitPercentage;

    printf("Enter Cost Price: ");
    scanf("%lf", ptrCost);

    printf("Enter Selling Price: ");
    scanf("%lf", ptrSell);

    printf("Enter Quantity Sold: ");
    scanf("%lf", ptrQuantity);

    *ptrTotalCost = (*ptrCost) * (*ptrQuantity);
    *ptrTotalSales = (*ptrSell) * (*ptrQuantity);

    *ptrProfitLoss = *ptrTotalSales - *ptrTotalCost;

    if (*ptrProfitLoss > 0)
    {
        printf("\nProfit\n");
        *ptrPercentage = (*ptrProfitLoss / *ptrTotalCost) * 100;
        printf("Profit Percentage: %.2f%%\n", *ptrPercentage);
    }
    else if (*ptrProfitLoss < 0)
    {
        printf("\nLoss\n");
        *ptrPercentage = (-*ptrProfitLoss / *ptrTotalCost) * 100;
        printf("Loss Percentage: %.2f%%\n", *ptrPercentage);
    }
    else
    {
        printf("\nNo Profit No Loss\n");
        *ptrPercentage = 0;
    }

    printf("Total Cost: %.2f\n", *ptrTotalCost);
    printf("Total Sales: %.2f\n", *ptrTotalSales);
    printf("Profit/Loss: %.2f\n", *ptrProfitLoss);

    double *larger;

    if (*ptrCost >= *ptrSell)
        larger = ptrCost;
    else
        larger = ptrSell;

    printf("\nLarger Value: %.2f\n", *larger);

    printf("\n===== VARIABLE AND POINTER ADDRESSES =====\n");

    printf("Variable       Address\n");
    printf("Cost Price     %p\n", (void *)&costPrice);
    printf("Selling Price  %p\n", (void *)&sellPrice);
    printf("Quantity       %p\n", (void *)&quantity);
    printf("Total Cost     %p\n", (void *)&totalCost);
    printf("Total Sales    %p\n", (void *)&totalSales);
    printf("Profit/Loss    %p\n", (void *)&profitLoss);
    printf("Percentage     %p\n", (void *)&profitPercentage);

    printf("\nPointer        Address\n");
    printf("ptrCost        %p\n", (void *)&ptrCost);
    printf("ptrSell        %p\n", (void *)&ptrSell);
    printf("ptrQuantity    %p\n", (void *)&ptrQuantity);
    printf("ptrTotalCost   %p\n", (void *)&ptrTotalCost);
    printf("ptrTotalSales  %p\n", (void *)&ptrTotalSales);
    printf("ptrProfitLoss  %p\n", (void *)&ptrProfitLoss);
    printf("ptrPercentage  %p\n", (void *)&ptrPercentage);
    printf("larger         %p\n", (void *)&larger);

    return 0;
}