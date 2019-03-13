#include <stdio.h>
#include <stdlib.h>

/*
    This program prints multiplication table
    from getting user input
    Table should be n x n
    n being user input
*/
int main()
{
    int input;
    printf("Enter an integer for a multiplication table: ");
    scanf("%d", &input);

    int arr[input][input];

    createTable(input, arr);

    // print table
    for(int x = 0; x < input; x++)
        printf("%d", x + 1);

    for(int y = 0; y < input; y++){
        printf("%d ", y + 1);
        for(int z = 0; z < input; z++){
            printf("%d ", arr[y][z]);
        }
        printf("\n");
    }
    return 0;
}

// Function that takes users input and initializes the array with the proper values
void createTable(int size, int arr[][]){
    int *ptr;
    ptr = arr;
    int val;
    // Values should be offset by 1 when doing calculations
    for(int x = 0; x < size; x++){
        for(int y = 0; y < size; y++){
            arr = (x + 1)(y + 1);
        }
    }
}

