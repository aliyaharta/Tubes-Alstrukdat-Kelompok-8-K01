#include <stdio.h>
#include "mesinkata.h"
#include "inputUser.h"
#include "config.h"


ArrayOfKata katas;

void CopyString(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') { 
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

ArrayOfKata inputUser() {
    katas.WordCount = 0;

    STARTKATA(NULL); 
    while (!IsEndKata() && katas.WordCount < WordMax) {
        Kata word = GetCKata();
        CopyString(katas.kata[katas.WordCount], word.TabKata); 
        katas.WordCount++; 
        ADVKATA(); 
    }

    return katas; 
}


