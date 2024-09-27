// This program displays a pattern in two different ways
#include <stdio.h>
#include <stdlib.h>

int main()
{
   for(int x = 0; x < 10; x++){
    for(int y = 0; y <= x; y++)
        printf("+");
    printf("\n");
   }

   printf("\n");
   for(int x = 10; x >= 0; x--){
    for(int y = 0; y <= x; y++)
        printf("+");
    printf("\n");
   }
    return 0;
}
