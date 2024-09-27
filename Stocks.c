/*
This program calculates profit Joe makes on the stocks he bought
and also the amount he pays to his broker
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    double commissionRate = 0.002;  // 2% to be paid to broker

    // Initial amount Joe pays for when he first buys the stocks @ 45.50 each
    int stocksBought = 1000;
    double buyRate = 45.50;
    double initialPaid = 1000 * buyRate;
    double commissionBuy = initialPaid * commissionRate;

    // Now calculate values for when Joe sold the socks @ 56.90 each
    double sellRate = 56.90;
    double soldStockAmount = stocksBought * sellRate;
    double commissionSold = soldStockAmount * commissionRate;

    // Calculate profit made
    double totalPaidBroker = commissionBuy + commissionSold;
    double moneyMade = (soldStockAmount - initialPaid) - totalPaidBroker;

    // Display info
    printf("Amount Joe paid initially for the stocks: %.2f\n", initialPaid);
    printf("Amount Joe paid to broker after buying stocks: %.2f\n", commissionBuy);
    printf("Amount Joe sold the stocks for: %.2f\n", soldStockAmount);
    printf("Amount Joe paid broker after selling stocks: %.2f\n", commissionSold);
    printf("Total amount of money Joe made after selling stocks and paying his broker: %.2f\n", moneyMade);
    return 0;
}

