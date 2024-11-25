#include <stdio.h>
#include "user.h"
#include "barang.h"
#include "readfile.h"

int main() {
    // Membaca file data
    readFile("data.txt");

    // Menampilkan daftar barang
    printf("Barang List:\n");
    for (int i = 0; i < barangCount; i++) {
        printf("Price: %d, Name: %s\n", barangList[i].price, barangList[i].name);
    }

    // Menampilkan daftar user
    printf("\nUser List:\n");
    for (int i = 0; i < userCount; i++) {
        printf("Money: %d, Password: %s, Name: %s\n", userList[i].money, userList[i].password, userList[i].name);
    }

    return 0;
}
