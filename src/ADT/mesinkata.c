#include "mesinkarakter.h"
#include "mesinkata.h"
#include <stdio.h>

// #define NMax 50
// #define BLANK ' '

// typedef struct
// {
//    char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
//    int Length;
// } Word;

// /* State Mesin Kata */
boolean EndWord;
Word CurrentWord;

void IgnoreBlanks() {
   while (currentChar == ' ') {
      ADV();
   }
}

void STARTWORD() {
   START();
   IgnoreBlanks(); 
   if (currentChar == '.') {
      EndWord = true;
   } else {
      EndWord = false;
      CopyWord();
   }
}

void ADVWORD() {
   IgnoreBlanks();
   if (currentChar == '.') {
      EndWord = true;
   } else {
      CopyWord();
      IgnoreBlanks();
   }
}

void CopyWord() {
   int i = 0;
   while ((currentChar != MARK) && (currentChar != BLANK) && (i < NMax)) {
      CurrentWord.TabWord[i] = currentChar;
      ADV();
      i++;      
   }
   CurrentWord.Length = i;
}