// Read/Write using get and put
#include <stdio.h>

int main(){
    char str[100];
    printf("Enter a value: ");
    fflush(stdout); // Eclipse bug
    gets(str);

    printf("\nYou entered: ");
    puts(str);

    return 0;
}
