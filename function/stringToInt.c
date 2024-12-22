#include "stringToInt.h"

int stringToInt(char str[]) {
    int result = 0;     
    int i = 0;         
    int isNegative = 0; 
    if (str[i] == '-') {
        isNegative = 1;  
        i++;             

    while (str[i] != '\0') {
        result = result * 10 + (str[i] - '0');  
        i++;
    }

    if (isNegative) {
        result = -result;
    }

    return result;  
}