#include <stdio.h>

#include "config.h"


void copyString(char *destination, const char *source) {
    int i = 0;
    while (source[i] != '\0') { // Copy each character until null-terminator
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0'; // Add the null-terminator at the end
}

