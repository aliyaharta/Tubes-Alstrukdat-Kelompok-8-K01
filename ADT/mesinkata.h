#ifndef MESINKATA_H
#define MESINKATA_H

#include "config.h"
#include "boolean.h"
#include "config.h"

#define BLANK ' '  // Karakter pemisah kata

typedef struct {
    char TabKata[100];
    int Index;
    int Length;
} Kata;

extern Kata currentKata;
extern boolean EndKata;

int getLength(Kata namaKata);
// Fungsi ini digunakan untuk mendapatkan panjang Kata 
void STARTKATA(char *filename); 
// Fungsi ini digunakan untuk Inisialisasi Mesin Kata
void ADVKATA();                 
// Fungsi ini digunakan untuk pindah ke kata berikutnya
Kata GetCKata();                
// Fungsi ini digunakan untuk mengambil kata saat ini
boolean IsEndKata();            
// Fungsi ini digunakan untuk mengecek apakah sudah pada akhir kata
void IgnoreBlank();
// Fungsi ini digunakan untuk mengabaikan Blank 
void SalinKata();
// Fungsi ini digunakan untuk menyalin Kata

#endif
