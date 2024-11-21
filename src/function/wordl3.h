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

void wordl3();

#endif 
