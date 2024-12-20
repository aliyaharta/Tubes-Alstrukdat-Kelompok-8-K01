#include <stdio.h>

#include "config.h"
#include "copystr.h"


void copyString(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') { // Copy characters until null-terminator
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // Add null-terminator at the end

    // int i = 0;
    // while (source[i] != '\0') { // Copy each character until null-terminator
    //     destination[i] = source[i];
    //     i++;
    // }
    // destination[i] = '\0'; // Add the null-terminator at the end
}

