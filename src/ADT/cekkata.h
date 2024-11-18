#ifndef CEKKATA_H
#define CEKKATA_H

#include "ADT/boolean.h"

#define MAX_LEN 50

typedef struct 
{
    char TabWord[MAX_LEN];
    int Length;
}Word;

extern boolean endWord;
extern Word CurrentWord;

void CreateWord(int length, char *string, Word *w);

void CekWor(Word a, Word b);

#endif