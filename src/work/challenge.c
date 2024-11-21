#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define WORD_LENGTH 5

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
    int uang; 

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
            uang = 550 - (50*(kesempatan+1));
            printf("Tebakanmu benar! %d rupiah telah ditambahkan ke akun anda.\n", uang);
            break;
        }
        kesempatan++;
    }

    if (kesempatan > 9){
        printf("Maaf kesempatanmu sudah habis.\n");
    }
}


void charCheck(const char *jawaban, const char *tebakan, char *hasil) { 
    int check[WORD_LENGTH] = {0}; 
    int i, j;

    for (i = 0; i < WORD_LENGTH; i++) {
        if (tebakan[i] == jawaban[i]) {
            hasil[i * 4] = tebakan[i];    
            hasil[i * 4 + 1] = ' ';
            hasil[i * 4 + 2] = ' ';
            hasil[i * 4 + 3] = ' ';     
            check[i] = 1;                 
        } else {
            hasil[i * 4] = '_';
            hasil[i * 4 + 1] = ' ';
            hasil[i * 4 + 2] = ' ';
            hasil[i * 4 + 3] = ' ';
        }
    }

    for (i = 0; i < WORD_LENGTH; i++) {
        if (hasil[i * 4] == '_') { 
            for (j = 0; j < WORD_LENGTH; j++) {
                if (!check[j] && tebakan[i] == jawaban[j]) {
                    hasil[i * 4] = tebakan[i];
                    hasil[i * 4 + 1] = '*';
                    hasil[i * 4 + 2] = ' ';
                    hasil[i * 4 + 3] = ' ';
                    check[j] = 1;            
                    break;
                }
            }
        }
    }

    for (i = 0; i < WORD_LENGTH; i++) {
        if (hasil[i * 4] == '_') {     
            hasil[i * 4] = tebakan[i];
            hasil[i * 4 + 1] = '%';
            hasil[i * 4 + 2] = ' ';
            hasil[i * 4 + 3] = ' ';   
        }
    }
    hasil[WORD_LENGTH * 4] = '\0'; 
}

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


void wordl3(){
    #define MAX_ATTEMPTS 5

    char jawaban[WORD_LENGTH + 1];
    char tebakan[WORD_LENGTH + 1];
    char hasil[WORD_LENGTH * 4 + 1];
    char semua_hasil[MAX_ATTEMPTS][WORD_LENGTH * 4 + 1]; 
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
    
    strcpy(jawaban[i], random);  
    i++; 
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
            if (strlen(tebakan[i]) != WORD_LENGTH) {
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
            if (strcmp(tebakan[i], jawaban[i]) != 0) {
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

void challenge (){
        int angka;
        scanf("%d", &angka);

        if (angka == 1){
            if (money < 200){
                printf("Uang yang dimiliki kurang! Silakan kerja terlebih dahulu.");
            }
            else{
                money -= 200;
                printf("Masukkan tebakanmu!\n");
                tebakangka();
            }
        }
        else if (angka == 2){
            if (money < 500){
                printf("Uang yang dimiliki kurang! Silakan cari challenge lain atau kerja terlebih dahulu.");
            }
            else{
                money-=500;
                wordl3();
            }
        }
        else if (angka == 3){
            if (money < 600){
                printf("Uang yang dimiliki kurang! Silakan cari challenge lain atau kerja terlebih dahulu.");
            }
            else {
                money-=600;
                quantumWordle();
            }
        }
    }

int main (){
    printf("Daftar challenge yang tersedia :\n");
    printf("1. Tebak Angka (biaya main=200)\n"); 
    printf("2. W0RDL399 (biaya main=500)\n");
    printf("3. Quantum W0RDL3 (biaya main = 600)\n");
    printf("Masukan challenge yang hendak dimainkan:\n");

    challenge();

    char tanya;
    getchar();
    printf("Apakah kamu masih mau melanjutkan challenge? (y / n): \n");
    scanf("%c", &tanya);

    while (tanya != 'n'){
        if (tanya == 'y'){
            printf("Daftar challenge yang tersedia :\n");
            printf("1. Tebak Angka (biaya main=200)\n"); 
            printf("2. W0RDL399 (biaya main=500)\n");
            printf("3. Quantum W0RDL3 (biaya main = 600)\n");
            printf("Masukan challenge yang hendak dimainkan:\n");

            challenge();
            getchar();
        }
        else if (tanya != 'y'){
            printf("Inputan salah! Input antara 'y' atau 'n'\n");
            getchar();
            scanf("%c", &tanya);
        }
        printf("Apakah kamu masih mau melanjutkan challenge? (y / n): \n");
        scanf("%c", &tanya);
    }
}