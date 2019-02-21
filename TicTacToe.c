/*
    This program simulates a tic tac toe game
    Users are able to input row and column input
    for their moves
    The board should be displayed initially and after
    every players move

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool checkWinner(); // prototype for checkWinner function
char arr[3][3];     // array for board
int player = 1;     // player 1 = 1
                    // player 2 = 2
                    // helps keep track of which player's turn it is
                    // player 1 will start by default

int main()
{
    bool endGame = false;// should end game when a user or tie is announced

    int row, column;    // user will input row and column

    // initialize empty board
    // with '*' for empty spaces
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++)
            arr[x][y] = '*';
    }

    printf("Tic-Tac-Toe\n");
    while(endGame == false){
        display();
        printf("Player %d enter row choice: ", player);
        fflush(stdout);
        scanf("%d", &row);

        printf("Player %d enter column choice: ", player);
        fflush(stdout);
        scanf("%d", &column);

        playerTurn(row, column);

        // Change to certain player after their turn
        if(player == 1)
            player++;
        else if(player == 2)
            player--;

        endGame = checkWinner();
    }

    return 0;
}

// Displays board
void display(){
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++)
            printf("%c ", arr[x][y]);
        printf("\n");
    }
}

// Takes in user input and inserts their choice of row and column
// onto the proper place on the board
// Must check if user input is valid and if spaces are taken or not
void playerTurn(int row, int column){
    // First check if row and column are between 0-2
    if(row < 0 || row > 2){
        while(row < 0 || row > 2){
            printf("Row choice was out of bounds enter a valid row #(0-2): ");
            fflush(stdout);
            scanf("%d", &row);
        }
    }
    if(column < 0 || column > 2){
        while(column < 0 || column > 2){
            printf("Column choice was out of bounds enter a valid column #(0-2): ");
            fflush(stdout); 
            scanf("%d", &column);
        }
    }
    // Inserting player choice of row and column into properly selected spots
    if(arr[row][column] == '*'){
        if(player == 1)
            arr[row][column] = 'x';
        else
            arr[row][column] = 'o';
    }
    // When current selected spot is already taken
    else if(arr[row][column] == 'x' || arr[row][column] == 'o'){
        while(arr[row][column] == 'x' || arr[row][column] == 'o'){
            printf("Current choice of row and column are taken, enter new row and column choices(0-2)\n");
            printf("Row: ");
            fflush(stdout); 
            scanf("%d", &row);

            printf("Column: ");
            fflush(stdout); 
            scanf("%d", &column);
        }
        if(player == 1)
            arr[row][column] = 'x';
        else
            arr[row][column] = 'o';
    }
}

bool checkWinner(){
    int countP1;  // keeps track of certain characters in a row
                  // for player 1
    int countP2;  // for player 2
    int countEtc; // keeps track of '*' characters
                  // if this number is 0 with countP1 & countP2 < 3, then
                  // there is a tie

    // Check rows
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            if(arr[x][y] == 'x')
                countP1++;
            else if(arr[x][y] == 'o')
                countP2++;
             else if(arr[x][y] == '*')
                countEtc++;
        }
        // Reset count if there is no 3 in a row
        if(countP1 < 3)
            countP1 = 0;
        if(countP2 < 3)
            countP2 = 0;

        if(countP1 == 3){
            printf("Player 1 wins!\n");
            return true;
            break;
        }
        else if(countP2 == 3){
            printf("Player 2 wins!\n");
            return true;
            break;
        }

    }
}
