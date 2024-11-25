#include "stringToInt.h"

int stringToInt(char str[]) {
    int result = 0;      // To store the final integer value
    int i = 0;           // Index for iterating through the string
    int isNegative = 0;  // Flag to check if the number is negative

    // Check if the first character is a minus sign
    if (str[i] == '-') {
        isNegative = 1;  // Mark as negative
        i++;             // Move to the next character
    }

    // Process each character of the string
    while (str[i] != '\0') {
        result = result * 10 + (str[i] - '0');  // Convert character to digit and accumulate
        i++;
    }

    // Apply the negative sign if necessary
    if (isNegative) {
        result = -result;
    }

    return result;  // Return the final integer
}