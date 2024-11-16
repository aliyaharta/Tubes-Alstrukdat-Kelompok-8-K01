#include <stdio.h>
#include "mesinkata.h"

void baca_kata(char*kata, int Max){
    int i = 0;
    char input_char;
    input_char = getchar();
    while (input_char != '\n' && i < Max-1)
    {
        kata[i] = input_char;
        i++;
        input_char = getchar(); 
    }
    kata[i] = '\0';
}