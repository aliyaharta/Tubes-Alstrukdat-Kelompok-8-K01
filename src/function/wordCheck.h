#ifndef WORDCHECK_H
#define WORDCHECK_H

#include <stdio.h>

#define WORD_LENGTH 5 

int wordCheck(const char *word, char usedWords[][WORD_LENGTH + 1], int count);

#endif 
