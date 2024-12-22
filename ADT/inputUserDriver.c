#include <stdio.h>
#include "inputUser.h"
#include "config.h"

int main(void) {
    ArrayOfKata result = inputUser();

    printf("Stored words:\n");
    for (int i = 0; i < result.WordCount; i++) {
        printf("%s\n", result.kata[i]);
    }

    printf("Total words: %d\n", result.WordCount);

    return 0; 