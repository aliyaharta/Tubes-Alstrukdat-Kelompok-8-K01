#ifndef WORDCHECK_H
#define WORDCHECK_H

#include <stdio.h>

#define WORD_LENGTH 5 

/* 
I.S: `word` adalah kata yang akan diperiksa. `usedWords` adalah array 2D yang berisi daftar kata yang telah digunakan, 
dan `count` adalah jumlah kata yang ada di `usedWords`.
F.S: Mengembalikan 1 jika `word` ditemukan di dalam `usedWords`, dan 0 jika tidak.
*/
int wordCheck(const char *word, char usedWords[][WORD_LENGTH + 1], int count);

#endif 