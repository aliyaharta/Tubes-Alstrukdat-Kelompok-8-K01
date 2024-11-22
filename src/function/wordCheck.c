#include "wordCheck.h"

int wordCheck(const char *word, char usedWords[][WORD_LENGTH + 1], int count) {
    for (int i = 0; i < count; i++) {
        int check = 1; 
        for (int j = 0; word[j] != '\0' || usedWords[i][j] != '\0'; j++) {
            if (word[j] != usedWords[i][j]) {
                check = 0; 
                break;
            }
        }
        if (check) {
            return 1; 
        }
    }
    return 0; 
}
