/*
    This program asks the user for information on a population
    Information includes birth rate, death rate and the current population size
    Information will then be displayed based off of user input
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int bRate, dRate;
    int initialPop, newPop;
    int years;

    years = bRate = dRate = initialPop = newPop = -1;

    // Ask for user input before any calculations can be done
    while(initialPop < 2){
        printf("Enter an initial population size (of at least 2 or greater value): ");
        fflush(stdout);
        scanf("%d", &initialPop);

        if(initialPop < 2)      // Input validation
            printf("Invalid input, please enter a value greater than or equal to 2\n");

    }

    while(bRate < 0){
        printf("Enter the birth rate of the population (positive numbers only): ");
        fflush(stdout);
        scanf("%d", &bRate);
        if(bRate < 0)       // Input validation
            printf("Negative value entered, please enter a positive number\n");
    }

    while(dRate < 0){
        printf("Enter the death rate of the population (positive numbers only): ");
        fflush(stdout);
        scanf("%d", &dRate);
        if(dRate < 0)   // Input validation
            printf("Negative value entered, please enter a positive number\n");
    }

    while(years <= 0){
        printf("Enter the number of years to display (at least 1 or greater): ");
        fflush(stdout);
        scanf("%d", &years);

        if(years <= 0)  // Input validation
            printf("Number of years entered is not 1 or less than 1, please enter a correct value\n");
    }

    int prevPop;
    prevPop = initialPop;       // for initial calculation
    // loop to process the amount of years entered in by user
    for(int x = 0; x < years; x++){
        int count = x;
        count++;      // Keep track on number of years
        newPop = prevPop + (bRate * prevPop) - (dRate * prevPop);

        printf("Year %d\n",count );
        printf("Population in year %d %d\n", count, newPop);

        // Update previous population for next iteration
        prevPop = newPop;
    }
    return 0;
}
