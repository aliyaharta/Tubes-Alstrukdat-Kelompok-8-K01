#include <stdio.h>
#include "mesinkarakter.h"
#include "mesinkata.h"

void ReadWordsFromFile(const char *filename) {
    // Initialize the word processing for the file
    STARTKATA((char *)filename);

    // Check if the file is empty or cannot be opened
    if (IsEOP()) {
        printf("File is empty or cannot be opened.\n");
        return;
    }

    printf("Words in the file:\n");
    while (!IsEOP()) {
        // Process the current word
        Kata currentWord = GetCKata();
        printf("%s\n", currentWord.TabKata); // Print the current word

        // Advance to the next word
        ADVKATA();

        // Skip newlines (handled by ADVKATA internally if implemented correctly)
    }
}
