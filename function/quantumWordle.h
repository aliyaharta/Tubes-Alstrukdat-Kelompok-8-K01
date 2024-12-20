
// quantumWordle.h
#ifndef QUANTUMWORDLE_H
#define QUANTUMWORDLE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORD_LENGTH 5            
#define WORD_COUNT 4            
#define MAX_ATTEMPTS_QUANTUM 9               

/**
 * I.S.
 * - Daftar kata tersedia di variabel global `word_list` dan jumlahnya di `word_count`.
 * - Pemain memiliki uang di variabel global `money`.
 * - Fungsi pendukung seperti `wordCheck`, `stringLength`, `toUpperCase`, `charCheck`, dan `stringCompare` telah terdefinisi.
 * - Konstanta `WORD_LENGTH` mendefinisikan panjang setiap kata.
 *
 * F.S.
 * - Pemain dapat menebak hingga `MAX_ATTEMPTS_QUANTUM` kali untuk menebak `WORD_COUNT` kata secara benar.
 * - Jika pemain berhasil menebak semua kata dengan benar dalam jumlah kesempatan yang diberikan, mereka memenangkan permainan dan mendapatkan tambahan uang.
 * - Jika pemain gagal menebak semua kata dengan benar, jawaban yang benar akan ditampilkan.
 */
void quantumWordle(int userIndex);

#endif
