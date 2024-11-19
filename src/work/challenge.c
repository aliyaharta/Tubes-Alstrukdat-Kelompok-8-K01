#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define WORD_LENGTH 5
#define MAX_ATTEMPTS 5

const char *word_list[] = {"TRULY", "LUCKY", "BUILD", "PLUCK", "STORM"};
const int word_count = 5;

int money = 1000;

int generateRandomNumber(int min, int max) {
    time_t t;
    t = time(NULL);

    unsigned int seed = (unsigned int)t;
    seed ^= seed << 13;
    seed ^= seed >> 17;
    seed ^= seed << 5;

    int randomNum = (seed % (max - min + 1)) + min;
    return randomNum;
}

void tebakangka(){

    int kesempatan = 0; 

    int randomNum = generateRandomNumber(0,100);
    while (kesempatan < 10){
        int tebakan; 
        scanf("%d", &tebakan);

        if (tebakan > randomNum){
            printf("Tebakanmu lebih besar!\n");
        }
        else if (tebakan < randomNum){
            printf("Tebakanmu lebih kecil!\n");
        }
        else {
            printf("Tebakanmu benar! +350 rupiah telah ditambahkan ke akun anda.\n");
        }
    }
    printf("Maaf kesempatanmu sudah habis.\n");
}

void charCheck(const char *jawaban, const char *tebakan, char *hasil) { 
    int check[WORD_LENGTH] = {0}; 
    int i, j;

    for (i = 0; i < WORD_LENGTH; i++) {
        if (tebakan[i] == jawaban[i]) {
            hasil[i * 2] = tebakan[i];    
            hasil[i * 2 + 1] = ' ';     
            check[i] = 1;                 
        } else {
            hasil[i * 2] = '_';        
            hasil[i * 2 + 1] = ' ';
        }
    }

    for (i = 0; i < WORD_LENGTH; i++) {
        if (hasil[i * 2] == '_') { 
            for (j = 0; j < WORD_LENGTH; j++) {
                if (!check[j] && tebakan[i] == jawaban[j]) {
                    hasil[i * 2] = tebakan[i]; 
                    hasil[i * 2 + 1] = '*'; 
                    check[j] = 1;            
                    break;
                }
            }
        }
    }

    for (i = 0; i < WORD_LENGTH; i++) {
        if (hasil[i * 2] == '_') {     
            hasil[i * 2] = tebakan[i];   
            hasil[i * 2 + 1] = '%';    
        }
    }
    hasil[WORD_LENGTH * 2] = '\0'; 
}

void wordl3(){
    char jawaban[WORD_LENGTH + 1];
    char tebakan[WORD_LENGTH + 1];
    char hasil[WORD_LENGTH * 2 + 1];
    char semua_hasil[MAX_ATTEMPTS][WORD_LENGTH * 2 + 1]; 
    int kesempatan = 0;

    srand(time(NULL)); 
    strcpy(jawaban, word_list[rand() % word_count]);

    printf("WELCOME TO W0RDL3, YOU HAVE %d CHANCES TO ANSWER BEFORE YOU LOSE!\n", MAX_ATTEMPTS);
    for (int i = 0; i < MAX_ATTEMPTS; i++) {
        printf("_ _ _ _ _\n");
    }
    printf("\n");

    while (kesempatan < MAX_ATTEMPTS) {
        printf("Masukkan kata tebakan Anda: ");
        scanf("%s", tebakan);

        if (strlen(tebakan) != WORD_LENGTH) {
            printf("Kata harus berisi %d karakter!\n", WORD_LENGTH);
            continue;
        }

        for (int i = 0; i < WORD_LENGTH; i++) {
            tebakan[i] = toupper(tebakan[i]);
        }

        charCheck(jawaban, tebakan, hasil);

        strcpy(semua_hasil[kesempatan], hasil);

        printf("Hasil:\n");
        for (int i = 0; i <= kesempatan; i++) {
            printf("%s\n", semua_hasil[i]);
        }
        for (int i = kesempatan + 1; i < MAX_ATTEMPTS; i++) {
            printf("_ _ _ _ _\n");
        }
        printf("\n");

        if (strcmp(tebakan, jawaban) == 0) {
            printf("Selamat, Anda menang!\n");
            money += 1500; 
            printf("+1500 rupiah telah ditambahkan ke akun Anda.\n");
            break;
        }

        kesempatan++;
    }

    if (strcmp(jawaban, tebakan) != 0) {
        printf("Boo! Anda kalah. Jawaban yang benar adalah: %s\n", jawaban);
    }
}

int main (){
    int angka;

    printf("Daftar challenge yang tersedia :\n");
    printf("1. Tebak Angka (biaya main=200)\n"); 
    printf("2. W0RDL399 (biaya main=500)\n");
    printf("Masukan challenge yang hendak dimainkan:\n");

    scanf("%d", &angka);

    if (angka == 1){
        money -= 200;
        printf("Masukkan tebakanmu!\n");
        tebakangka();
    }
    else if (angka == 2){
        money-=500;
        wordl3();
    }
}
