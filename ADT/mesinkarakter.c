#include <stdio.h>
#include "mesinkarakter.h"

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
        printf("Masukkan input (akhiri dengan '.'): ");
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
    if (fscanf(pita, "%c", &currentChar) == EOF) {
        EOP = true; // Tandai akhir pita jika mencapai EOF
    } else {
        EOP = (currentChar == MARK); // Tandai akhir pita berdasarkan MARK
    }
    if (EOP && pita != stdin) {
        fclose(pita); // Tutup pita jika menggunakan file
    }
}


char GetCC() {
    return currentChar;
}

boolean IsEOP() {
    return EOP;
}
