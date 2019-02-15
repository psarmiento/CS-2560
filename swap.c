#include <stdio.h>
#include <stdlib.h>


void swap(int *x, int *y) // defining function called swap
{
    int z = *x;
    *x = *y;
    *y = z;
}
int main()
{
    int a = 45, b = 35;
    printf("Before swap\n");
    printf("a = %d  b = %d\n", a,b);

    swap(&a, &b);

    printf("After swap\n");
    printf("a = %d  b = %d\n", a,b);
    return 0;
}
