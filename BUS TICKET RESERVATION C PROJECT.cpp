#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int bus_num;
    int num_of_seats;
} pd;

// Function prototypes
void reservation(void);        // Function for ticket reservation
void viewdetails(void);        // Function to display available buses
void printticket(char name[], int, int, float); // Function to print a ticket
void specificbus(int);         // Function to display details of a specific bus
float charge(int, int);        // Function to calculate the ticket charge
void login();                  // Function for user login

int main() {
    system("cls");
    system("COLOR 0A");
    printf("\t\t=================================================\n");
    printf("\t\t|                                               |\n");
    printf("\t\t|       ----------------------------------      |\n");
    printf("\t\t|             BUS TICKET RESERVATION            |\n");
    printf("\t\t|                    SYSTEM                     |\n");
    printf("\t\t|       ----------------------------------      |\n");
    printf("\t\t|                                               |\n");
    printf("\t\t|                                               |\n");
    printf("\t\t|                                               |\n");
    printf("\t\t|                                               |\n");
    printf("\t\t|                                               |\n");
    printf("\t\t=================================================\n\n\n");

    printf(" \n Press any key to continue:");
    getch();
    system("cls");
    login();
    int menu_choice, choice_return;
    start:
    system("cls");
    printf("\n=================================\n");
    printf("     BUS RESERVATION SYSTEM");
    printf("\n=================================");
    printf("\n1>> Reserve A Ticket");
    printf("\n------------------------");
    printf("\n2>> View All Available Buses");
    printf("\n------------------------");
    printf("\n3>> Exit");
    printf("\n-->");
    scanf("%d", &menu_choice);
    switch (menu_choice) {
        case 1:
            reservation();
            break;
        case 2:
            viewdetails();
            printf("\n\nPress any key to go to the Main Menu..");
            getch();
            break;
        case 3:
            return (0);
        default:
            printf("\nInvalid choice");
    }
    goto start;
    return (0);
}

// Function to display details of available buses
void viewdetails(void) {
    system("cls");
    printf("---------------------------------------------------------------------------------------");
    printf("\nBus.No\tName\t\t\tDestinations  \t\tCharges  \t\tTime\n");
    printf("---------------------------------------------------------------------------------------");
    printf("\n1001\tGodavari Travels     \tDharan to Kavre       \tRs.500    \t\t9:00  AM");
    printf("\n1002\tDevit Travels        \tKavre To Dharan       \tRs.500  \t\t12:00 PM");
    printf("\n1003\tHero Travels         \tBenighat To Pokhara   \tRs.450   \t\t1:50  PM");
    printf("\n1004\tSuper Deluxe         \tPokhara To Benigha    \tRs.450   \t\t11:00 AM");
    printf("\n1005\tSai Baba Travels     \tMaitidevi To Janakpur \tRs.400  \t\t7:05  AM");
    printf("\n1006\tShine On Travels     \tJanakpur To Maitidevi \tRs.400   \t\t9:30  AM");
    printf("\n1007\tMayur Travels        \tJumla To Humla        \tRs.350   \t\t1:00  PM");
    printf("\n1008\tShree Travels        \tHumla To Jumla        \tRs.350   \t\t4:00  PM");
    printf("\n1009\tKathmandu Express    \tKathmandu To Pokhara  \tRs.600  \t\t5:35  PM");
    printf("\n1010\tSajha Yatayat        \tPokhara To Kathmandu  \tRs.600   \t\t4:15  PM");
}

// Function for ticket reservation
void reservation(void) {
    char confirm;
    int i = 0;
    float charges;
    pd passdetails;
    FILE *fp;
    fp = fopen("seats_reserved.txt", "a");
    system("cls");

    printf("\nEnter Your Name:> ");
    fflush(stdin);
    gets(passdetails.name);
    printf("\nEnter Number of seats:> ");
    scanf("%d", &passdetails.num_of_seats);
    printf("\n\n>>Press Enter To View Available Buses<< ");
    getch();
    system("cls");
    viewdetails();
    printf("\n\nEnter bus number:> ");
    start1:
    scanf("%d", &passdetails.bus_num);
    if (passdetails.bus_num >= 1001 && passdetails.bus_num <= 1010) {
        charges = charge(passdetails.bus_num, passdetails.num_of_seats);
        printticket(passdetails.name, passdetails.num_of_seats, passdetails.bus_num, charges);
    } else {
        printf("\nInvalid bus Number! Enter again--> ");
        goto start1;
    }

    printf("\n\nConfirm Ticket (y/n):>");
    start:
    scanf(" %c", &confirm);
    if (confirm == 'y') {
        fprintf(fp, "%s\t\t%d\t\t%d\t\t%.2f\n", &passdetails.name, passdetails.num_of_seats,
                passdetails.bus_num, charges);
        printf("==================");
        printf("\n Reservation Done\n");
        printf("==================");
        printf("\nPress any key to go back to the Main menu");
    } else {
        if (confirm == 'n') {
            printf("\nReservation Not Done!\nPress any key to go back to the Main menu!");
        } else {
            printf("\nInvalid choice entered! Enter again-----> ");
            goto start;
        }
    }
    fclose(fp);
    getch();
}

// Function to calculate the ticket charge
float charge(int bus_num, int num_of_seats) {
    if (bus_num == 1001) {
        return (500 * num_of_seats);
    }
    if (bus_num == 1002) {
        return (500 * num_of_seats);
    }
    if (bus_num == 1003) {
        return (450 * num_of_seats);
    }
    if (bus_num == 1004) {
        return (450 * num_of_seats);
    }
    if (bus_num == 1005) {
        return (400 * num_of_seats);
    }
    if (bus_num == 1006) {
        return (400 * num_of_seats);
    }
    if (bus_num == 1007) {
        return (350 * num_of_seats);
    }
    if (bus_num == 1008) {
        return (350 * num_of_seats);
    }
    if (bus_num == 1009) {
        return (600 * num_of_seats);
    }
    if (bus_num == 1010) {
        return (600 * num_of_seats);
    }
}

// Function to print a ticket
void printticket(char name[], int num_of_seats, int bus_num, float charges) {
    system("cls");
    printf("-------------------\n");
    printf("\tTICKET\n");
    printf("-------------------\n\n");
    printf("Name:\t\t\t%s", name);
    printf("\nNumber Of Seats:\t%d", num_of_seats);
    printf("\nbus Number:\t\t%d", bus_num);
    specificbus(bus_num);
    printf("\nCharges:\t\t%.2f", charges);
}

// Function to display details of a specific bus
void specificbus(int bus_num) {
    if (bus_num == 1001) {
        printf("\nbus:\t\t\tGodavari Travels ");
        printf("\nDestination:\t\tDharan to Kavre");
        printf("\nDeparture:\t\t9am ");
    }
    if (bus_num == 1002) {
        printf("\nbus:\t\t\tDevit Travels ");
        printf("\nDestination:\t\tKavre to Dharan");
        printf("\nDeparture:\t\t12pm");
    }
    if (bus_num == 1003) {
        printf("\nbus:\t\t\tHero Travels ");
        printf("\nDestination:\t\tBenighat To Pokhara");
        printf("\nDeparture:\t\t8am");
    }
    if (bus_num == 1004) {
        printf("\nbus:\t\t\tSuper Deluxe ");
        printf("\nDestination:\t\tPokhara to Benighat");
        printf("\nDeparture:\t\t11am ");
    }
    if (bus_num == 1005) {
        printf("\nbus:\t\t\tSai Baba Travels ");
        printf("\nDestination:\t\tMaitidevi to Janakpur");
        printf("\nDeparture:\t\t7am");
    }
    if (bus_num == 1006) {
        printf("\nbus:\t\t\tShine On Travels ");
        printf("\nDestination:\t\tJanakpur to Maitidevi ");
        printf("\nDeparture:\t\t9.30am ");
    }
    if (bus_num == 1007) {
        printf("\nbus:\t\t\tMayur Travels");
        printf("\nDestination:\t\tHumla to Jumla ");
        printf("\nDeparture:\t\t1pm ");
    }
    if (bus_num == 1008) {
        printf("\nbus:\t\t\tShree Travels ");
        printf("\n Destination:\t\tJumla to Humla");
        printf("\nDeparture:\t\t4pm ");
    }
    if (bus_num == 1009) {
        printf("\nbus:\t\t\tKathmandu Express");
        printf("\nDestination:\t\tKathmandu to Pokhara");
        printf("\nDeparture:\t\t3.35pm ");
    }
    if (bus_num == 1010) {
        printf("\nbus:\t\t\tSajha Yatayat");
        printf("\nDestination:\t\tPokhara to Kathmandu");
        printf("\nDeparture:\t\t1.15 ");
    }
}

// Function for user login
void login() {
    int a = 0, i = 0;
    char uname[10], c = ' ';
    char pword[10], code[10];
    char user[10];
    char pass[10];
    do {
        printf("\n  =======================  LOGIN FORM  =======================\n  ");
        printf(" \n                       ENTER USERNAME:-");
        scanf("%s", &uname);
        printf(" \n                       ENTER PASSWORD:-");
        while (i < 10) {
            pword[i] = getch();
            c = pword[i];
            if (c == 13) break;
            else printf("*");
            i++;
        }
        pword[i] = '\0';
        i = 0;
        if (strcmp(uname, "admin") == 0 && strcmp(pword, "pass") == 0) {
            printf("  \n\n\n       WELCOME TO OUR  BUS RESERVATION SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
            printf("\n\n\n\t\t\t\tPress any key to continue...");
            getch();
            break;
        } else {
            printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
            a++;
            getch();
            system("cls");
        }
    } while (a <= 2);
    if (a > 2) {
        printf("\nSorry, you have entered the wrong username and password for four times!!!");
        getch();
    }
    system("cls");
}