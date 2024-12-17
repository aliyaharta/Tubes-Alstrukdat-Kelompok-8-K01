#include "wordl3.h"
#include "stringLength.h" 
#include "toUpperCase.h" 
#include "inputUser.h"
#include "charCheck.h"

void wordl3(){
    #define MAX_ATTEMPTS 5

    char jawaban[WORD_LENGTH + 1];
    char tebakan[WORD_LENGTH + 1];
    char hasil[WORD_LENGTH * 4 + 1];
    char semua_hasil[MAX_ATTEMPTS][WORD_LENGTH * 4 + 1]; 
    int kesempatan = 0;

    srand(time(NULL)); 

    const char *random = word_list[rand() % word_count];
    
    int j = 0;
    while (random[j] != '\0') {
        jawaban[j] = random[j];
        j++;
    }
    jawaban[j] = '\0'; 

    printf("WELCOME TO W0RDL3, YOU HAVE %d CHANCES TO ANSWER BEFORE YOU LOSE!\n", MAX_ATTEMPTS);
    for (int i = 0; i < MAX_ATTEMPTS; i++) {
        printf("_ _ _ _ _\n");
    }
    printf("\n");

    while (kesempatan < MAX_ATTEMPTS) {
        printf("Masukkan kata tebakan Anda: ");
        
        ArrayOfKata userInput = inputUser();

        if (userInput.WordCount < 1) {
            printf("Input tidak boleh kosong!\n");
            continue;
        }

        CopyString(tebakan, userInput.kata[0]); 

        int length = stringLength(tebakan);

        if (length != WORD_LENGTH) {
            printf("Kata harus berisi %d karakter!\n", WORD_LENGTH);
            continue;
        }

        for (int i = 0; i < WORD_LENGTH; i++) {
            tebakan[i] = toUpperCase(tebakan[i]);
        }

        charCheck(jawaban, tebakan, hasil);

        int i = 0;
        while (hasil[i] != '\0') {
            semua_hasil[kesempatan][i] = hasil[i];
            i++;
        }
        semua_hasil[kesempatan][i] = '\0';

        printf("Hasil:\n");
        for (int i = 0; i <= kesempatan; i++) {
            printf("%s\n", semua_hasil[i]);
        }
        for (int i = kesempatan + 1; i < MAX_ATTEMPTS; i++) {
            printf("_ _ _ _ _\n");
        }
        printf("\n");

        int sama = 1; 
        for (int i = 0; tebakan[i] != '\0' || jawaban[i] != '\0'; i++) {
            if (tebakan[i] != jawaban[i]) {
                sama = 0; 
                break;
            }
        }

        if (sama) {
            printf("Selamat, Anda menang!\n");
            money += 1500; 
            printf("+1500 rupiah telah ditambahkan ke akun Anda.\n");
            break;
        }

        kesempatan++;
    }

    int beda = 0; 
    for (int i = 0; jawaban[i] != '\0' || tebakan[i] != '\0'; i++) {
        if (jawaban[i] != tebakan[i]) {
            beda = 1; 
            break;
        }
    }

    if (beda) {
        printf("Boo! Anda kalah. Jawaban yang benar adalah: %s\n", jawaban);
    }
}
