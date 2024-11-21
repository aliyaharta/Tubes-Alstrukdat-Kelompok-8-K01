// quantumWordle.h
#ifndef QUANTUMWORDLE_H
#define QUANTUMWORDLE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORD_LENGTH 5            
#define WORD_COUNT 4            
#define MAX_ATTEMPTS_QUANTUM 9  

extern const char *word_list[] = {"TRULY", "LUCKY", "BUILD", "PLUCK", "STORM"}; 
extern int word_count = 5;      
extern int money;               

void quantumWordle();

#endif 
