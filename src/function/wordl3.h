#ifndef WORDL3_H
#define WORDL3_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORD_LENGTH 5        
#define MAX_ATTEMPTS 5       

extern const char *word_list[] = {"TRULY", "LUCKY", "BUILD", "PLUCK", "STORM"}; 
extern int word_count = 5;           
extern int money;               

/* 
I.S: Permainan W0RDL3 belum dimulai. Pemain memiliki sejumlah uang dan kesempatan bermain.
F.S: Pemain berhasil menebak kata dalam jumlah kesempatan yang diberikan atau kehabisan kesempatan. Hasil permainan akan dicetak, dan jumlah uang pemain akan diperbarui jika menang.
*/
void wordl3();

#endif 
