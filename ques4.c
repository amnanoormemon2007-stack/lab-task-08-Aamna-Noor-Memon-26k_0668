#include <stdio.h>

void displayRules()
{
    printf("\n===== TAXI FARE SYSTEM =====\n");
    printf("Base Fare: Rs. 150\n");
    printf("First 10 km: Rs. 60/km\n");
    printf("After 10 km: Rs. 45/km\n");
}

double getDistance()
{
    double distance;

    do
    {
        printf("Enter distance (0-200 km): ");
        scanf("%lf", &distance);
    } while (distance <= 0 || distance > 200);

    return distance;
}

int getWaitingTime()
{
    int time;

    do
    {
        printf("Enter waiting time (0-120 minutes): ");
        scanf("%d", &time);
    } while (time < 0 || time > 120);

    return time;
}

double calculateDistanceCharge(double distance)
{
    double charge;

    if (distance <= 10)
        charge = distance * 60;
    else
        charge = (10 * 60) + ((distance - 10) * 45);

    return charge + 150;
}

double calculateWaitingCharge(int time)
{
    if (time <= 5)
        return 0;
    else
        return (time - 5) * 10;
}

double calculateNightFare(double fare, int hour)
{
    if (hour >= 22 || hour < 6)
        return fare + (fare * 0.25);
    else
        return fare;
}

void printReceipt(double distance, int waiting, double fare)
{
    printf("\n===== TAXI RECEIPT =====\n");
    printf("Distance: %.2f km\n", distance);
    printf("Waiting Time: %d minutes\n", waiting);
    printf("Final Fare: Rs. %.2f\n", fare);
}

int main()
{
    int i, waiting, hour;
    double distance, distanceCharge;
    double waitingCharge, fare;
    double totalEarnings = 0;
    double highestFare = 0;

    for (i = 1; i <= 3; i++)
    {
        printf("\nTrip %d\n", i);

        displayRules();

        distance = getDistance();
        waiting = getWaitingTime();

        do
        {
            printf("Enter trip hour (0-23): ");
            scanf("%d", &hour);
        } while (hour < 0 || hour > 23);

        distanceCharge = calculateDistanceCharge(distance);
        waitingCharge = calculateWaitingCharge(waiting);

        fare = distanceCharge + waitingCharge;
        fare = calculateNightFare(fare, hour);

        printReceipt(distance, waiting, fare);

        totalEarnings += fare;

        if (fare > highestFare)
            highestFare = fare;
    }

    printf("\nTotal Earnings: Rs. %.2f\n", totalEarnings);
    printf("Highest Fare: Rs. %.2f\n", highestFare);

    return 0;
}