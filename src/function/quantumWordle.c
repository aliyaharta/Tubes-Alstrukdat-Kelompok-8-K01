#include "quantumWordle.h" 

void quantumWordle() {
    #define WORD_COUNT 4
    #define MAX_ATTEMPTS_QUANTUM 9

    char jawaban[WORD_COUNT][WORD_LENGTH + 1];
    char tebakan[WORD_COUNT][WORD_LENGTH + 1];
    char hasil[MAX_ATTEMPTS_QUANTUM][WORD_COUNT][WORD_LENGTH * 4 + 1];
    int kesempatan = 0;

    srand(time(NULL));

    int i = 0;
    while (i < WORD_COUNT) {
        const char *random = word_list[rand() % word_count];  
        while (wordCheck(random, jawaban, i)) { 
            random = word_list[rand() % word_count]; 
        }
        
        while (i < WORD_COUNT) {
        const char *random = word_list[rand() % word_count];  
        while (wordCheck(random, jawaban, i)) { 
            random = word_list[rand() % word_count]; 
        }
        
        int j = 0;
        while (random[j] != '\0') {
            jawaban[i][j] = random[j];
            j++;
        }
        jawaban[i][j] = '\0'; 
        
        i++;
        }

    }

    printf("WELCOME TO QUANTUM! YOU HAVE %d CHANCES TO GUESS %d WORDS!\n", MAX_ATTEMPTS_QUANTUM, WORD_COUNT);
    for (int i = 0; i < MAX_ATTEMPTS_QUANTUM; i++) {
        for (int j = 0; j < WORD_COUNT; j++) {
            printf("_ _ _ _ _   ");
        }
        printf("\n");
    }
    printf("\n");

    while (kesempatan < MAX_ATTEMPTS_QUANTUM) {
        printf("Masukkan %d kata tebakan Anda (dipisah dengan spasi):\n", WORD_COUNT);
        for (int i = 0; i < WORD_COUNT; i++) {
            scanf("%s", tebakan[i]);
            int len = 0;
            for (int j = 0; tebakan[i][j] != '\0'; j++) {
                len++;
            }

            if (len != WORD_LENGTH) {
                printf("Kata harus berisi %d karakter!\n", WORD_LENGTH);
                i--;
                continue;
            }
            for (int j = 0; j < WORD_LENGTH; j++) {
                tebakan[i][j] = toupper(tebakan[i][j]);
            }
        }

        int semua_benar = 1;

        for (int i = 0; i < WORD_COUNT; i++) {
            charCheck(jawaban[i], tebakan[i], hasil[kesempatan][i]);
            if (stringCompare(tebakan[i], jawaban[i]) != 0) {
                semua_benar = 0;
            }
        }

        printf("Hasil tebakan Anda:\n");
        for (int i = 0; i <= kesempatan; i++) {
            for (int j = 0; j < WORD_COUNT; j++) {
                printf("%s   ", hasil[i][j]);
            }
            printf("\n");
        }
        for (int i = kesempatan + 1; i < MAX_ATTEMPTS_QUANTUM; i++) {
            for (int j = 0; j < WORD_COUNT; j++) {
                printf("_ _ _ _ _   ");
            }
            printf("\n");
        }
        printf("\n");

        if (semua_benar) {
            printf("Selamat, Anda menang! Semua kata berhasil ditebak.\n");
            money += 2000;  
            printf("+2000 rupiah telah ditambahkan ke akun Anda.\n");
            return;
        }

        kesempatan++;
    }

    printf("Boo! Anda kalah. Jawaban yang benar adalah:\n");
    for (int i = 0; i < WORD_COUNT; i++) {
        printf("%s ", jawaban[i]);
    }
    printf("\n");
}