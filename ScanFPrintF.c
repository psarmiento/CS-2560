// You define type of I/O
// scanf and printf

// reading two items a string and int
#include <stdio.h>

int main(){
    char str[100];
    int i;

    printf("Enter a value: ");
    fflush(stdout);     // Eclipse bug
    scanf("%s %d", str, &i);

    printf("\nYou entered: %s %d ", str, i);

    return 0;
}
