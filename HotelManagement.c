#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct date
{
    int day;
    int month;
    int year;
};
struct guest
{
    char name[20];
    int room_no;
    char address[50];
    char phone[10];
    int days;
    struct date checkin;
    struct date checkout;
    int total;
    int totalmembers;
};
struct room
{
    int room_no;
    int ac;
    int rent;
    struct guest g;
    int booked;
};

void displayAvailableRooms(struct room availableRooms[])
{
    int i;
    printf("Available Rooms\n");
    for (i = 0; i < 10; i++)
    {
        if (availableRooms[i].booked == 0)
        {
            printf("Room No: %d  ", availableRooms[i].room_no);
            if (availableRooms[i].ac == 1)
            {
                printf("AC: Yes  ");
            }
            else
            {
                printf("AC: No  ");
            }
            printf("Rent: %d  \n", availableRooms[i].rent);
        }
    }
}


void main()
{
    struct room hotel[2];
    struct room availableRooms[10];
    struct room bookedRooms[10];
    int i;
    for (i = 0; i < 10; i++)
    {
        availableRooms[i].room_no = i + 1;
        if (i % 2 == 0)
        {
            availableRooms[i].ac = 1;
            availableRooms[i].rent = 700;
        }
        else
        {
            availableRooms[i].ac = 0;
            availableRooms[i].rent = 1000;
        }

        availableRooms[i].booked = 0;
    }
restartapp:

    int choice, room_no;
    printf("Welcome to Hotel Management System\n");
    printf("Choose an option\n");
    printf("1. Display Available rooms\n");
    printf("2. Display Booked rooms\n");
    printf("3. Display All rooms\n");
    printf("4. Book a room\n");
    printf("5. Check out\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        displayAvailableRooms(availableRooms);
        break;
    case 2:
        // displayBookedRooms(bookedRooms);
        break;
    case 3:
        // displayAllRooms(availableRooms, bookedRooms);
        break;
    case 4:
        // bookRoom(availableRooms, bookedRooms);
        break;
    case 5:
        // checkOut(availableRooms, bookedRooms);
        break;
    case 6:
        exit(0);
        break;
    }
    goto restartapp;
}