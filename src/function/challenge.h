#ifndef CHALLENGE_H
#define CHALLENGE_H

#include <stdio.h>
#include "tebakangka.h"
#include "wordl3.h"
#include "quantumWordle.h"

// Deklarasi variabel global
extern const char *word_list[];
extern const int word_count;
extern int money;

// Deklarasi fungsi
/**
 * I.S. Program menampilkan daftar challenge dan meminta input angka dari pengguna.
 * F.S. Challenge yang dipilih akan dijalankan jika uang mencukupi, 
 *      atau menampilkan pesan bahwa uang tidak cukup jika tidak mencukupi.
 */
void challenge();


#endif // CHALLENGE_H
