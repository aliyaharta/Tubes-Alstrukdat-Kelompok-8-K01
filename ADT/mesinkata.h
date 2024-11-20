#ifndef MESINKATA_H
#define MESINKATA_H

#include "config.h"
#include "boolean.h"

#define BLANK ' '  // Karakter pemisah kata

typedef struct {
    char TabKata[100];
    int Index;
} Kata;

extern Kata currentKata;
extern boolean EndKata;

int getLength(Kata namaKata);
void STARTKATA(char *filename); // Inisialisasi Mesin Kata
void ADVKATA();                 // Pindah ke kata berikutnya
Kata GetCKata();                // Mengambil kata saat ini
boolean IsEndKata();            // Mengecek apakah sudah akhir kata
void IgnoreBlank();            
void SalinKata();

#endif
