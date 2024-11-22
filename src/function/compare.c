#include "compare.h"

int stringCompare(const char *str1, const char *str2) {
    int i = 0;

    // Compare characters until a mismatch or null terminator is found
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;  // Strings are not equal
        }
        i++;
    }

    // Check if both strings ended
    return str1[i] == '\0' && str2[i] == '\0';
}
