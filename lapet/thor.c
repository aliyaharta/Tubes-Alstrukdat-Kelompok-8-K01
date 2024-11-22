#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_LEN 100
#define MAX_USERS 100
#define MAX_BARANGS 100

// Struktur data untuk User
typedef struct {
    char name[MAX_LEN];
    char password[MAX_LEN];
    int money;
} User;

// Struktur data untuk Barang
typedef struct {
    char name[MAX_LEN];
    int price;
} Barang;

// Mesin Karakter
char currentChar;
FILE *file;

// Fungsi untuk memulai mesin karakter
void startChar(const char *filePath) {
    file = fopen(filePath, "r");
    if (file != NULL) {
        currentChar = fgetc(file);
    } else {
        currentChar = EOF;
    }
}

// Fungsi untuk maju ke karakter berikutnya
void advChar() {
    if (file != NULL) {
        currentChar = fgetc(file);
    }
}

// Fungsi untuk mengecek akhir file
int eotChar() {
    return currentChar == EOF;
}

// Mesin Kata
char currentWord[MAX_LEN];
int wordLength;

// Fungsi untuk memulai mesin kata
void startWord() {
    wordLength = 0;
    while (currentChar != EOF && (currentChar == ' ' || currentChar == '\n')) {
        advChar();
    }
    while (currentChar != EOF && currentChar != ' ' && currentChar != '\n') {
        currentWord[wordLength++] = currentChar;
        advChar();
    }
    currentWord[wordLength] = '\0'; // Null-terminate string
}

// Fungsi untuk maju ke kata berikutnya
void advWord() {
    startWord();
}

// Fungsi untuk konversi kata ke integer
int wordToInt() {
    int result = 0;
    for (int i = 0; currentWord[i] != '\0'; i++) {
        result = result * 10 + (currentWord[i] - '0');
    }
    return result;
}

// Fungsi membaca file dan mengisi array
void readFile(const char *filePath, User users[], int *userCount, Barang barangs[], int *barangCount) {
    startChar(filePath);

    // Membaca jumlah User
    startWord();
    *userCount = wordToInt();
    for (int i = 0; i < *userCount; i++) {
        // Membaca nama
        advWord();
        strcpy(users[i].name, currentWord);

        // Membaca password
        advWord();
        strcpy(users[i].password, currentWord);

        // Membaca uang
        advWord();
        users[i].money = wordToInt();
    }

    // Membaca jumlah Barang
    startWord();
    *barangCount = wordToInt();
    for (int i = 0; i < *barangCount; i++) {
        // Membaca nama barang
        advWord();
        strcpy(barangs[i].name, currentWord);

        // Membaca harga barang
        advWord();
        barangs[i].price = wordToInt();
    }

    fclose(file);
}

// Fungsi mencetak data User
void printUsers(User users[], int userCount) {
    printf("Users:\n");
    for (int i = 0; i < userCount; i++) {
        printf("Name: %s, Password: %s, Money: %d\n", users[i].name, users[i].password, users[i].money);
    }
}

// Fungsi mencetak data Barang
void printBarangs(Barang barangs[], int barangCount) {
    printf("Barangs:\n");
    for (int i = 0; i < barangCount; i++) {
        printf("Name: %s, Price: %d\n", barangs[i].name, barangs[i].price);
    }
}

// Fungsi menulis semua data ke file
void writeFile(const char *filePath, User users[], int userCount, Barang barangs[], int barangCount) {
    FILE *file = fopen(filePath, "w");
    if (!file) {
        printf("Error: Unable to open file '%s' for writing.\n", filePath);
        exit(1);
    }

    // Menulis jumlah User
    fprintf(file, "%d\n", userCount);
    for (int i = 0; i < userCount; i++) {
        fprintf(file, "%s %s %d\n", users[i].name, users[i].password, users[i].money);
    }

    // Menulis jumlah Barang
    fprintf(file, "%d\n", barangCount);
    for (int i = 0; i < barangCount; i++) {
        fprintf(file, "%s %d\n", barangs[i].name, barangs[i].price);
    }

    fclose(file);
}

int main() {
    User users[MAX_USERS];
    Barang barangs[MAX_BARANGS];
    int userCount = 0, barangCount = 0;

    // Nama file
    const char *filePath = "lapet/data.txt";

    // Membaca file
    readFile(filePath, users, &userCount, barangs, &barangCount);

    // Menampilkan data
    printUsers(users, userCount);
    printBarangs(barangs, barangCount);

    // Menambahkan User baru sebagai contoh
    strcpy(users[userCount].name, "newuser");
    strcpy(users[userCount].password, "newpass");
    users[userCount].money = 200;
    userCount++;

    // Menambahkan Barang baru sebagai contoh
    strcpy(barangs[barangCount].name, "newitem");
    barangs[barangCount].price = 500;
    barangCount++;

    // Menulis kembali data ke file
    writeFile(filePath, users, userCount, barangs, barangCount);

    return 0;
}
