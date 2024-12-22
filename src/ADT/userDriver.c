#include "user.h"
#include "compare.h"
#include <stdio.h>

#define MAX_NAME_LENGTH 100
#define MAX_USERS 100

User userList[MAX_USERS];
int userCount = 0;

// Fungsi utama
int main() {
    char name[MAX_NAME_LENGTH];
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Tambah pengguna\n");
        printf("2. Cari pengguna\n");
        printf("3. Tampilkan semua pengguna\n");
        printf("4. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);
        getchar(); 

        if (choice == 1) {
            if (userCount < MAX_USERS) {
                printf("Masukkan nama pengguna: ");
                int i = 0;
                char c;
                while ((c = getchar()) != '\n' && i < MAX_NAME_LENGTH - 1) {
                    name[i++] = c;
                }
                name[i] = '\0';

                if (getIndex(name) == -1) {
                    copyString(userList[userCount].name, name);
                    userCount++;
                    printf("Pengguna '%s' berhasil ditambahkan.\n", name);
                } else {
                    printf("Pengguna '%s' sudah ada.\n", name);
                }
            } else {
                printf("Daftar pengguna penuh. Tidak bisa menambahkan pengguna baru.\n");
            }

        } else if (choice == 2) {
            printf("Masukkan nama pengguna yang ingin dicari: ");
            int i = 0;
            char c;
            while ((c = getchar()) != '\n' && i < MAX_NAME_LENGTH - 1) {
                name[i++] = c;
            }
            name[i] = '\0';

            int index = getIndex(name);
            if (index != -1) {
                printf("Pengguna '%s' ditemukan pada indeks %d.\n", name, index);
            } else {
                printf("Pengguna '%s' tidak ditemukan.\n", name);
            }

        } else if (choice == 3) {
            printf("Daftar pengguna:\n");
            for (int i = 0; i < userCount; i++) {
                printf("%d. %s\n", i + 1, userList[i].name);
            }

        } else if (choice == 4) {
            printf("Keluar dari program.\n");
            break;

        } else {
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }

    return 0;
}
