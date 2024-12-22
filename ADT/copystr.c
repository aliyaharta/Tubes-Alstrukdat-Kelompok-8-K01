#include <stdio.h>

#include "config.h"
#include "copystr.h"


void copyString(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';

   
}

