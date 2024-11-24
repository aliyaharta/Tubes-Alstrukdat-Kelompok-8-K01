#include <stdio.h>
#include "mesinkarakter.h"
#include "config.h"

char currentChar;
boolean EOP;

static FILE *pita;

boolean IsNewline() {
    return currentChar == '\n'; // True jika karakter saat ini adalah '\n'
}

void START(char *filename) {
    if (filename == NULL) {
        // Jika filename NULL, gunakan keyboard (stdin) sebagai pita
        pita = stdin;
        printf("Masukkan input: ");
    } else {
        // Jika filename diberikan, buka file sebagai pita
        pita = fopen(filename, "r");
        if (pita == NULL) {
            printf("File tidak ditemukan.\n");
            currentChar = MARK;
            EOP = true;
            return;
        }
    }
    ADV(); // Baca karakter pertama
}

void ADV() {
     int result = fgetc(pita); // Baca satu karakter dari file
    if (result == EOF) {
        currentChar = MARK; // Tandai akhir file
        EOP = true;
    } else {
        currentChar = (char)result;
        EOP = (currentChar == MARK); // Tandai akhir pita berdasarkan MARK
    }
    if (EOP && pita != stdin && pita != NULL) {
        fclose(pita); // Tutup pita jika menggunakan file
        pita = NULL;
    }
}


char GetCC() {
    return currentChar;
}

boolean IsEOP() {
    return EOP;
}
