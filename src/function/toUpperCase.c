#include "toUpperCase.h"

// Fungsi untuk mengubah karakter menjadi huruf besar
char toUpperCase(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A'; 
    }
    return c;
}