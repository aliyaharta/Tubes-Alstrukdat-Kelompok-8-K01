#include "charCheck.h"

void charCheck(const char *jawaban, const char *tebakan, char *hasil) { 
    int check[WORD_LENGTH] = {0}; 
    int i, j;

    for (i = 0; i < WORD_LENGTH; i++) {
        if (tebakan[i] == jawaban[i]) {
            hasil[i * 4] = tebakan[i];    
            hasil[i * 4 + 1] = ' ';
            hasil[i * 4 + 2] = ' ';
            hasil[i * 4 + 3] = ' ';     
            check[i] = 1;                 
        } else {
            hasil[i * 4] = '_';
            hasil[i * 4 + 1] = ' ';
            hasil[i * 4 + 2] = ' ';
            hasil[i * 4 + 3] = ' ';
        }
    }

    for (i = 0; i < WORD_LENGTH; i++) {
        if (hasil[i * 4] == '_') { 
            for (j = 0; j < WORD_LENGTH; j++) {
                if (!check[j] && tebakan[i] == jawaban[j]) {
                    hasil[i * 4] = tebakan[i];
                    hasil[i * 4 + 1] = '*';
                    hasil[i * 4 + 2] = ' ';
                    hasil[i * 4 + 3] = ' ';
                    check[j] = 1;            
                    break;
                }
            }
        }
    }

    for (i = 0; i < WORD_LENGTH; i++) {
        if (hasil[i * 4] == '_') {     
            hasil[i * 4] = tebakan[i];
            hasil[i * 4 + 1] = '%';
            hasil[i * 4 + 2] = ' ';
            hasil[i * 4 + 3] = ' ';   
        }
    }
    hasil[WORD_LENGTH * 4] = '\0'; 
}
