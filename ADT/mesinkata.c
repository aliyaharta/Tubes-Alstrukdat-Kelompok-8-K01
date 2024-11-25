#include <stdio.h>
#include "mesinkata.h"
#include "mesinkarakter.h"
#include "boolean.h"
#include "config.h"

Kata currentKata;
boolean EndKata;

void IgnoreBlank() {
    while (GetCC() == BLANK && !IsEOP()) {
        ADV();
    }
}

int getLength(Kata namaKata){
    return namaKata.Index+1;
}

void SalinKata() {
    currentKata.Index = 0;
    while (GetCC() != BLANK && !IsEOP()) {
        if (currentKata.Index < WordMax) {
            currentKata.TabKata[currentKata.Index] = GetCC();
            currentKata.Index++;
        }
        ADV();
    }
    currentKata.TabKata[currentKata.Index] = '\0'; // Null-terminated string
}

void STARTKATA(const char *filename) {
    // Pastikan filename diberikan
    if (filename != NULL) {
        START((char *)filename); // Panggil START untuk membuka file
    } else {
        START(NULL); // Jika NULL, gunakan stdin
    }

    IgnoreBlank(); 
    if (IsEOP()) {
        EndKata = true;
    } else {
        EndKata = false;
        SalinKata();
    }
}


void ADVKATA() {
    IgnoreBlank();
    if (IsEOP()) {
        EndKata = true;
    } else {
        SalinKata();
    }
}

Kata GetCKata() {
    return currentKata;
}

boolean IsEndKata() {
    return EndKata;
}

