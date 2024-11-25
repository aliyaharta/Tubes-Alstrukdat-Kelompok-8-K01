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
        if (currentKata.Index < NMax) {
            currentKata.TabKata[currentKata.Index] = GetCC();
            currentKata.Index++;
        }
        ADV();
    }
    currentKata.TabKata[currentKata.Index] = '\0'; // Null-terminated string
}

void STARTKATA(char *filename) {
    START(filename); // Mulai Mesin Karakter
    IgnoreBlank();   // Lewati spasi awal
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


void test() {
    printf("NMax is: %d\n", NMax);
}