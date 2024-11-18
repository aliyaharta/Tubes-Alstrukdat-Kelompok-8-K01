#include <stdio.h>
#include "mesinkata.h"

void baca_kata(Word *kata, int Max){
    int i = 0;
    char input_char;
    input_char = getchar();
    while (input_char != '\n' && i < Max)
    {
        kata->TabWord[i] = input_char;
        i++; 
    }
    kata->TabWord[i] = '\0';
    kata->Length = i;
}
