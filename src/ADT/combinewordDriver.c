#include "combineword.h"
#include <stdio.h>

#define MAX_WORD_LENGTH 50
#define MAX_ARRAY_SIZE 100

typedef struct {
    char kata[MAX_ARRAY_SIZE][MAX_WORD_LENGTH];
    int WordCount;
} ArrayOfKata;

int main() {
    ArrayOfKata inputkata;
    char result[500];
    int start, end;

    // Inisialisasi array kata
    printf("Masukkan jumlah kata: ");
    scanf("%d", &inputkata.WordCount);
    getchar(); 

    for (int i = 0; i < inputkata.WordCount; i++) {
        printf("Masukkan kata ke-%d: ", i + 1);
        int j = 0;
        char c;
        while ((c = getchar()) != '\n' && j < MAX_WORD_LENGTH - 1) {
            inputkata.kata[i][j++] = c;
        }
        inputkata.kata[i][j] = '\0';
    }

    // Memasukkan range start dan end
    printf("Masukkan indeks awal (start): ");
    scanf("%d", &start);
    printf("Masukkan indeks akhir (end): ");
    scanf("%d", &end);

    combineword(result, inputkata, start, end);

    printf("Hasil kombinasi kata: %s\n", result);

    return 0;
}
