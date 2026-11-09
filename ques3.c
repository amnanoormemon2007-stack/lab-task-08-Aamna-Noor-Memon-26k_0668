#include <stdio.h>

void displayRoutes()
{
    printf("\n===== BUS TICKET SYSTEM =====\n");
    printf("1. Karachi to Hyderabad - Rs. 800\n");
    printf("2. Karachi to Sukkur - Rs. 2200\n");
    printf("3. Karachi to Multan - Rs. 3500\n");
}

int getRoute()
{
    int route;

    do
    {
        printf("Enter route number (1-3): ");
        scanf("%d", &route);
    } while (route < 1 || route > 3);

    return route;
}

int getSeats()
{
    int seats;

    do
    {
        printf("Enter number of seats (1-6): ");
        scanf("%d", &seats);
    } while (seats < 1 || seats > 6);

    return seats;
}

double getFare(int route)
{
    switch (route)
    {
        case 1: return 800;
        case 2: return 2200;
        case 3: return 3500;
        default: return 0;
    }
}

double calculateTotal(double fare, int seats)
{
    return fare * seats;
}

double calculateSeatType(double total, char type)
{
    if (type == 'B' || type == 'b')
        return total + (total * 0.30);
    else
        return total;
}

void printTicket(int route, int seats, char type, double fare)
{
    char *routeName;

    switch (route)
    {
        case 1: routeName = "Karachi to Hyderabad"; break;
        case 2: routeName = "Karachi to Sukkur"; break;
        case 3: routeName = "Karachi to Multan"; break;
        default: routeName = "Unknown";
    }

    printf("\n===== BUS TICKET =====\n");
    printf("Route: %s\n", routeName);
    printf("Seats: %d\n", seats);
    printf("Seat Type: %c\n", type);
    printf("Final Fare: Rs. %.2f\n", fare);
}

int main()
{
    int i, route, seats;
    char type;
    double fare, total, finalFare;
    double earnings = 0;

    for (i = 1; i <= 2; i++)
    {
        printf("\nPassenger %d\n", i);

        displayRoutes();

        route = getRoute();
        seats = getSeats();

        fare = getFare(route);
        total = calculateTotal(fare, seats);

        do
        {
            printf("Choose Economy (E) or Business (B): ");
            scanf(" %c", &type);
        } while (type != 'E' && type != 'e' &&
                 type != 'B' && type != 'b');

        finalFare = calculateSeatType(total, type);

        printTicket(route, seats, type, finalFare);

        earnings += finalFare;
    }

    printf("\nTotal Company Earnings: Rs. %.2f\n", earnings);

    return 0;
}