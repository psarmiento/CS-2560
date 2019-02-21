#include <stdio.h>
#include <stdlib.h>

/*
    This program is a geometry calculator that will ask for user input and based off their input will
    calculate area of certain basic geometric figures
    Input validation for negative values will be accounted for
*/
int main()
{
    int choice;

    printf("Geometry Calculator");
    while(choice != 4){
        menu();
        fflush(stdout);
        scanf("%d", &choice);       // store input directly into choice address

        if (choice < 0 || choice > 4)   // input validation
            printf("Invalid input. Only choose between 1 - 4\n");

        else if(choice == 1)
            areaCircle();

        else if(choice == 2)
            areaRectangle();

        else if(choice == 3)
            areaOfTriangle();
    }


    return 0;
}

// Prints general menu for program
void menu(){
    printf("\n\n1. Calculate the Area of a Circle\n");
    printf("2. Calculate the Area of a Rectangle\n");
    printf("3. Calculate the Area of a Triangle\n");
    printf("4. Quit\n");
}

// Calculates area of circle and displays area based on user input
void areaCircle(){
    int radius;
    double PI = 3.14159;
    double area = -1;   // area will be calculated when positive input is received
    while(area < 0){
        printf("\nEnter the value of the radius: ");
        fflush(stdout);
        scanf("%d", &radius);

        if(radius < 0)  // Input validation
            printf("The value you entered is negative, only positive values are accepted\n");
        else{
            area = radius * radius * PI;
            printf("The area of the circle is: %.3f", area);
        }
    }
}

// Calculates area of triangle and displays area based on user input
void areaRectangle(){
    int length, width, area;
    length = width = area = -1;

    while(length < 0){
        printf("Enter a value of length: ");
        fflush(stdout);
        scanf("%d", &length);
        if(length < 0)
            printf("The value you entered is negative, only positive values are accepted\n");
    }

    while(width < 0){
        printf("Enter a value for width: ");
        fflush(stdout);
        scanf("%d", &width);
        if(width < 0)
            printf("The value you entered is negative, only positive values are accepted\n");
    }

    area = length * width;
    printf("The area of the rectangle is: %d\n", area);
}

// Calculates area of a triangle and displays the area based on user input
void areaOfTriangle(){
    int base, height;
    base = height = -1;
    double area;

    while(base < 0){
        printf("Enter a value for the base: ");
        fflush(stdout);
        scanf("%d", &base);
        if(base < 0)
            printf("The value you entered is negative, only positive values are accepted\n");
    }

    while(height < 0){
        printf("Enter a value for the height: ");
        fflush(stdout);
        scanf("%d", &height);
        if(height < 0)
            printf("The value you entered is negative, only positive values are accepted\n");
    }

    area = base * height * 0.5;
    printf("The area of the triangle is: %.3f\n", area);
}
