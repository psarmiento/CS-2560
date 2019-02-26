/*
    This program simulates a theater, the user will have to input ticket prices per row
    and will also allow user to buy tickets and view available seats
    Author: Paul Sarmiento
    CS 2560
    Project 1
*/
#include <stdio.h>
#include <stdlib.h>

char theater[15][30];    // Will be used to keep track of available seats and taken seats in theater
                         // '#' = empty     '*' = purchased seat
double prices[15];      // Holds the prices per row for the theater, user will input prices into here
int totalSales = 0;   // Keeps track of total tickets sold
double moneyMade = 0;   // Total amount of money made from ticket sales
int main()
{
	printf("Theater Program.\n\n");
    int userInput = 0;  // For menu choices
    // First initialize theater array to be empty
    for(int x = 0 ; x < 15; x++){
        for(int y = 0; y < 30; y++)
            theater[x][y] = '#';
    }

    rowPrice();

    // Display seats
    displaySeats();

    // Main loop for users to purchase tickets and view other info
    while(userInput != 5){
        menu();
        fflush(stdout);
        scanf("%d", &userInput);

        if(userInput == 1)
            displaySeats();
        else if(userInput == 2)
            purchase();
        else if(userInput == 3)
            seatsSoldInfo();
        else if(userInput == 4)
            totalMoneyInfo();

    }

    printf("End of program!\n");
    return 0;
}

// Displays options for the user to choose from for the program
void menu(){
    printf("\n1. Display seating chart\n");
    printf("2. Purchase tickets\n");
    printf("3. View seats sold information\n");
    printf("4. View total amount of money made from sales\n");
    printf("5. Exit\n");

}

// Displays the theater, with '#' as empty and '*' as taken
void displaySeats(){
    printf("\n");
    for(int x = 0 ; x < 15; x++){
        for(int y = 0; y < 30; y++)
           printf("%c", theater[x][y]);

       printf("\n");
    }
}

// Will prompt user to enter in ticket prices for every row
void rowPrice(){
    for(int x = 0; x < 15; x++){
        printf("Enter the ticket price for row %d: ", x + 1);
        fflush(stdin);
        fflush(stdout);
        scanf("%lf", &prices[x]);
    }
}

// Handles the purchasing of tickets for theater
// Displays ticket total and also updates the theater display for which seats are taken
// Will take into account invalid input
void purchase(){
    int row, column;
    // Prompt user for row and column choice for seats
    printf("Please select a row to sit in (1-15): ");
    fflush(stdout);
    scanf("%d", &row);
    // Input validation
    if(row < 1 || row > 15){
        while( row < 1 || row > 15){
            printf("Invalid row input, please enter another row (1-15): ");
            fflush(stdout);
            fflush(stdin);
            scanf("%d", &row);
        }

    }

    printf("Please enter a seat #(1-30) for row %d: ", row);
    fflush(stdout);
    fflush(stdin);
    scanf("%d", &column);
    if(column < 1 || column > 30){
        while( column < 1 || column > 30){
            printf("Invalid seat input, please enter another seat (1-30): ");
            fflush(stdout);
            fflush(stdin);
            scanf("%d", &column);
        }

    }

    // Check if seats chosen are available
    if(theater[row - 1][column - 1] == '*'){
        while(theater[row - 1][column - 1] == '*'){
            printf("Your current choice of seats are taken please choose another seat\n");
            printf("Row(1-15): ");
            fflush(stdout);
            scanf("%d", &row);
            printf("Seat #(1-30): ");
            fflush(stdout);
            scanf("%d", &column);
        }
    }

    // Update theater display when tickets are bought
    // Offset user input choice by 1 for array
    if(theater[row - 1][column - 1] == '#'){
        theater[row - 1][column - 1] = '*';
        totalSales++;   // Keep track of ticket sales
        moneyMade += prices[row - 1];       // Keeping track of money made
    }
}

void seatsSoldInfo(){
    printf("\nTotal number of seats sold: %d", totalSales);

    // Display information for seats available in every row
    for(int x = 0; x < 15; x++){
    int rowCount = 0;
        for(int y = 0; y < 30; y++){
            if(theater[x][y] == '#')
                rowCount++;
        }
       printf("\nNumber of seats available in row %d: %d", x + 1, rowCount);
    }
    printf("\nTotal available seats in entire theater: %d", 450 - totalSales);
}

void totalMoneyInfo(){
    printf("\nTotal amount of money made $%.2f", moneyMade);
}
