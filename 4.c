#include <stdio.h>
#include <string.h>
int findRoom(char rooms[][5], char room[])
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if (strcmp(rooms[i], room) == 0)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int choice = 0, i = 0;
    char rooms[5][5] = {"R101", "R102", "R103", "R104", "R105"};
    char guests[5][30];
    for (i = 0; i < 5; i++)
    {
        guests[i][0] = '\0';
    }
    char room[50], name[50];
    do
    {
        int x = 0, i = 0;
        printf("\n1.Book Room 2.Check Out 3.Show Rooms 4.Exit\n");
        printf("Choice:");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            printf("Enter Room Number:");
            fgets(room, sizeof(room), stdin);
            room[strcspn(room, "\n")] = '\0';
            x = findRoom(rooms, room);
            if (x == -1)
            {
                printf("Room Unknown");
            }
            else if (guests[x][0] != '\0')
            {
                printf("%s already occupied", room);
            }
            else
            {
                printf("Enter Name:");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                name[29] = '\0';
                strcpy(guests[x], name);
                printf("Room is booked for %s", name);
            }
            break;
        case 2:
            printf("Enter Room Number:");
            fgets(room, sizeof(room), stdin);
            room[strcspn(room, "\n")] = '\0';
            x = findRoom(rooms, room);
            if (x == -1)
            {
                printf("Room Unknown");
            }
            else if (guests[x][0] == '\0')
            {
                printf("ALready Empty");
            }
            else
            {
                printf("%s Checked Out", guests[x]);
                strcpy(guests[x], "\0");
            }
            break;
        case 3:
            for (i = 0; i < 5; i++)
            {
                printf("%d %s %s\n", i + 1, rooms[i],guests[i][0]?guests[i]:"empty");
            }
            break;
        }

    } while (choice != 4);
}