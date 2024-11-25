#include <stdio.h>
#include "mesinkata.h"
#include "inputUser.h"
#include "config.h"


ArrayOfKata katas;

// Function to copy a string from `src` to `dest`
void CopyString(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') { // Copy characters until null-terminator
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // Add null-terminator at the end
}

// Function to read input from the user and populate the `ArrayOfKata` structure
ArrayOfKata inputUser() {
    // Initialize the `katas` structure
    katas.Length = 0;

    // Start reading words using input from stdin
    STARTKATA(NULL); // NULL means using stdin

    while (!IsEndKata() && katas.Length < 5) { // Ensure no overflow
        Kata word = GetCKata();
        CopyString(katas.kata[katas.Length], word.TabKata); // Copy the word to `katas.kata`
        katas.Length++; // Increment Length after adding a word
        ADVKATA(); // Move to the next word
    }

    return katas; // Return the populated structure
}

