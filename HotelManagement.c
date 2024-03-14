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
    struct guest guest;
    int booked;
};

void displayavailablerooms(struct room rooms[])
{
    int i;
    printf("Available Rooms\n");
    for (i = 0; i < 10; i++)
    {
        if (rooms[i].booked == 0)
        {
            printf("Room No: %d  ", rooms[i].room_no);
            if (rooms[i].ac == 1)
            {
                printf("AC: Yes  ");
            }
            else
            {
                printf("AC: No  ");
            }
            printf("Rent: %d  \n", rooms[i].rent);
        }
    }
}


void bookRoom(struct room rooms[])
{
    int room_no;
    printf("Enter room no: ");
    scanf("%d", &room_no);
    if (rooms[room_no - 1].booked == 0)
    {
        rooms[room_no - 1].booked = 1;

        printf("Enter guest name: ");
        scanf(" %s", rooms[room_no - 1].guest.name);
        printf("Enter guest address: ");
        scanf(" %s ", rooms[room_no - 1].guest.address);
        printf("Enter guest phone: ");
        scanf(" %s ", rooms[room_no - 1].guest.phone);
        printf("Enter no of days: ");
        scanf(" %d ", &rooms[room_no - 1].guest.days);
        printf("Enter checkin date: ");
        scanf("%d %d %d", &rooms[room_no - 1].guest.checkin.day, &rooms[room_no - 1].guest.checkin.month, &rooms[room_no - 1].guest.checkin.year);
        rooms[room_no - 1].guest.total = rooms[room_no - 1].guest.days * rooms[room_no - 1].rent;
        printf("Enter no of members: ");
        scanf("%d", &rooms[room_no - 1].guest.totalmembers);


        printf("Room booked successfully\n");
    }
    else
    {
        printf("Room is already booked\n");
    }
}

void displayBookedRooms(struct room rooms[])
{
    int i;
    printf("Booked Rooms\n");
    for (i = 0; i < 10; i++)
    {
        if (rooms[i].booked == 1)
        {
            printf("Room No: %d  ", rooms[i].room_no);
            if (rooms[i].ac == 1)
            {
                printf("AC: Yes  ");
            }
            else
            {
                printf("AC: No  ");
            }
            printf("Rent: %d  ", rooms[i].rent);
            printf("Guest Name: %s  ", rooms[i].guest.name);
            printf("Guest Address: %s  ", rooms[i].guest.address);
            printf("Guest Phone: %s  ", rooms[i].guest.phone);
            printf("No of days: %d  ", rooms[i].guest.days);
            printf("Checkin date: %d/%d/%d  ", rooms[i].guest.checkin.day, rooms[i].guest.checkin.month, rooms[i].guest.checkin.year);
            printf("Total: %d  ", rooms[i].guest.total);
            printf("No of members: %d  \n", rooms[i].guest.totalmembers);
        }
    }
}

void displayAllRooms(struct room rooms[])
{
    int i;
    printf("All Rooms\n");
    for (i = 0; i < 10; i++)
    {
        printf("Room No: %d  ", rooms[i].room_no);
        if (rooms[i].ac == 1)
        {
            printf("AC: Yes  ");
        }
        else
        {
            printf("AC: No  ");
        }
        printf("Rent: %d  ", rooms[i].rent);
        if (rooms[i].booked == 1)
        {
            printf("Guest Name: %s  ", rooms[i].guest.name);
            printf("Guest Address: %s  ", rooms[i].guest.address);
            printf("Guest Phone: %s  ", rooms[i].guest.phone);
            printf("No of days: %d  ", rooms[i].guest.days);
            printf("Checkin date: %d/%d/%d  ", rooms[i].guest.checkin.day, rooms[i].guest.checkin.month, rooms[i].guest.checkin.year);
            printf("Total: %d  ", rooms[i].guest.total);
            printf("No of members: %d  \n", rooms[i].guest.totalmembers);
        }
        else
        {
            printf("Room is not booked\n");
        }
    }
}

void checkOut(struct room rooms[])
{
    int room_no;
    printf("Enter room no: ");
    scanf("%d", &room_no);
    if (rooms[room_no - 1].booked == 1)
    {
        rooms[room_no - 1].booked = 0;
        printf("Room checked out successfully\n");
    }
    else
    {
        printf("Room is not booked\n");
    }
}

void main()
{
 
    struct room rooms[10];
    struct room roomBookingHistory[0];

    int i;
    for (i = 0; i < 10; i++)
    {
        rooms[i].room_no = i + 1;
        if (i % 2 == 0)
        {
            rooms[i].ac = 1;
            rooms[i].rent = 700;
        }
        else
        {
            rooms[i].ac = 0;
            rooms[i].rent = 1000;
        }

        rooms[i].booked = 0;
    }
    printf("Welcome to Hotel Management System\n");
restartapp:

    int choice, room_no;
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
        displayavailablerooms(rooms);
        break;
    case 2:
        displayBookedRooms(rooms);
        break;
    case 3:
        displayAllRooms(rooms);
        break;
    case 4:
        bookRoom(rooms);
        break;
    case 5:
        checkOut(rooms);
        break;
    case 6:
        exit(0);
        break;
    }
    goto restartapp;
}