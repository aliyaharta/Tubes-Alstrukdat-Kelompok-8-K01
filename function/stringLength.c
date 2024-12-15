#include "stringLength.h"

// Fungsi untuk menghitung panjang string 
int stringLength(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}