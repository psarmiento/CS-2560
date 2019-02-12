#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Initial given values
    double meal = 88.67;
    double taxRate = 0.0675;
    double tip = 0.20;

    // Bill is the total before tip is added
    // Total bill includes tip
    double bill;
    double totalBill;
    double taxAmount;
    double tipAmount;

    // Calculate tax to be added to bill by multiplying taxRate * meal
    // Then add this amount with meal charge for bill
    taxAmount = meal * taxRate;
    bill = taxAmount + meal;

    // Tip is now calculated by multiplying tax rate with bill amount
    tipAmount = bill * tip;
    totalBill = bill + tipAmount;

    // Print all info of meal
    printf("Meal: %.2f\n", meal);
    printf("Tax:  %.2f\n", taxAmount);
    printf("Tip:  %.2f\n", tipAmount);
    printf("Total bill:  %.2f\n", totalBill);
    return 0;
}

