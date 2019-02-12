/*
Program that calculates number of millimeters the ocean level will rise in certain number of years
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    double risingRate = 1.5;
    // Multiply rising rate by # of years in the future the ocean will rise
    double fiveYrs =  risingRate * 5;
    double sevenYrs = risingRate * 7;
    double tenYrs = risingRate * 10;

    // display all the info
    printf("Amount ocean levels will eventually rise to in the future\n");
    printf("The values displayed are represented in millimeters\n");
    printf("5 years: %.2f\n", fiveYrs);
    printf("7 years: %.2f\n", sevenYrs);
    printf("10 years: %.2f\n", tenYrs);


    return 0;
}

