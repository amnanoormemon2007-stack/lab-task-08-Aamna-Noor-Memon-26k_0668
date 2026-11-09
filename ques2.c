#include <stdio.h>

void displayHospital()
{
    printf("\n===== CITY HOSPITAL =====\n");
    printf("1. General Ward - Rs. 1500/day\n");
    printf("2. Semi-Private - Rs. 3500/day\n");
    printf("3. Private - Rs. 6000/day\n");
}

int getRoomType()
{
    int type;

    do
    {
        printf("Enter room type (1-3): ");
        scanf("%d", &type);
    } while (type < 1 || type > 3);

    return type;
}

int getDays()
{
    int days;

    do
    {
        printf("Enter days stayed (1-30): ");
        scanf("%d", &days);
    } while (days < 1 || days > 30);

    return days;
}

double calculateRoomCharges(int type, int days)
{
    switch (type)
    {
        case 1: return 1500 * days;
        case 2: return 3500 * days;
        case 3: return 6000 * days;
        default: return 0;
    }
}

double medicineCharge()
{
    double medicine;

    printf("Enter medicine bill: ");
    scanf("%lf", &medicine);

    return medicine + (medicine * 0.05);
}

double calculateDiscount(double total, int days)
{
    if (days >= 7)
        return total * 0.08;
    else
        return 0;
}

void printBill(int type, int days, double room,
               double medicine, double finalAmount)
{
    char *roomName;

    switch (type)
    {
        case 1: roomName = "General Ward"; break;
        case 2: roomName = "Semi-Private"; break;
        case 3: roomName = "Private"; break;
        default: roomName = "Unknown";
    }

    printf("\n===== FINAL HOSPITAL BILL =====\n");
    printf("Room: %s\n", roomName);
    printf("Days: %d\n", days);
    printf("Room Charges: Rs. %.2f\n", room);
    printf("Medicine Charges: Rs. %.2f\n", medicine);
    printf("Final Amount: Rs. %.2f\n", finalAmount);
}

int main()
{
    int type, days;
    char senior;
    double room, medicine, total, discount, finalAmount;

    displayHospital();

    type = getRoomType();
    days = getDays();

    room = calculateRoomCharges(type, days);
    medicine = medicineCharge();

    total = room + medicine;
    discount = calculateDiscount(total, days);
    finalAmount = total - discount;

    printf("Is patient senior citizen? (y/n): ");
    scanf(" %c", &senior);

    if (senior == 'y' || senior == 'Y')
        finalAmount -= 1000;

    if (finalAmount < 0)
        finalAmount = 0;

    printBill(type, days, room, medicine, finalAmount);

    return 0;
}