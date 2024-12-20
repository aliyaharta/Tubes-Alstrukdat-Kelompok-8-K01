#include <stdio.h>
#include "combineword.h"

void combineword(char dest[], ArrayOfKata inputkata) {
    int pos = 0;

    for (int i = 0; i < inputkata.WordCount; i++) {
        int j = 0;

        while (inputkata.kata[i][j] != '\0') {
            dest[pos++] = inputkata.kata[i][j];
            j++;
        }

        if (i < inputkata.WordCount - 1) {
            dest[pos++] = ' ';
        }
    }
    dest[pos] = '\0';
}

