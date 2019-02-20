/*
    This program takes an array and reverses the order of it
    through a function that accepts int[] and the length of the array
    as it's arguments
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    for(int x = 0; x < 5; x++)
        printf("arr[%d]:%d  ",x,arr[x]);

    printf("\nAfter reversing array\n");
    reverseArr(arr, 5);


     for(int x = 0; x < 5; x++)
        printf("arr[%d]:%d  ",x,arr[x]);
    return 0;
}

// Function that takes in an array and reverses it
int reverseArr(int arr[], int length){
    int *ptr;
    ptr = &arr;     // pointer to point to address of arr[]
    int temp;
    int tempLength = length;    // temporarily keep track of length
    for(int x = 0; x < length/2; x++){
        temp = arr[x];
        // swapping the values
        arr[x] = arr[tempLength - 1];
        arr[tempLength - 1] = temp;
        tempLength--;   // increment tempLength after every iteration
    }

    return ptr;
}
