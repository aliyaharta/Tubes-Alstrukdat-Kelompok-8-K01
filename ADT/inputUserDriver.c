#include <stdio.h>
#include "inputUser.h"
#include "config.h"

int main(void) {
    // Call `inputUser` to read words and store them in the `katas` structure
    ArrayOfKata result = inputUser();

    // Print the stored words
    printf("Stored words:\n");
    for (int i = 0; i < result.length; i++) {
        printf("%s\n", result.kata[i]);
    }

    // Print the total number of words
    printf("Total words: %d\n", result.length);

    return 0; // Indicate successful execution
}