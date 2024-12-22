#include <stdio.h>
#include "stringToInt.h" 

int main() {
    char str[100]; 

    printf("Enter a string representing an integer: ");
    scanf("%s", str); 

    int result = stringToInt(str);

    printf("The integer value is: %d\n", (10*result));

    return 0;
}
