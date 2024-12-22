#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 100

int main() {
    LinkedList list;
    char input[MAX_INPUT_LENGTH];
    int choice;

    // Inisialisasi LinkedList
    list_create(&list);

    do {
        printf("\nMenu:\n");
        printf("1. Tambahkan elemen ke LinkedList\n");
        printf("2. Cetak LinkedList\n");
        printf("3. Tampilkan panjang LinkedList\n");
        printf("4. Hapus LinkedList\n");
        printf("5. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);
        getchar(); // Bersihkan newline dari input buffer

        switch (choice) {
            case 1:
                printf("Masukkan data: ");
                int i = 0;
                char c;
                while ((c = getchar()) != '\n' && i < MAX_INPUT_LENGTH - 1) {
                    input[i++] = c;
                }
                input[i] = '\0';

                if (list_insert_last(&list, input)) {
                    printf("Data berhasil ditambahkan.\n");
                } else {
                    printf("Gagal menambahkan data.\n");
                }
                break;

            case 2:
                printf("Isi LinkedList:\n");
                list_print(list);
                break;

            case 3:
                printf("Panjang LinkedList: %d\n", list_length(list));
                break;

            case 4:
                list_destroy(&list);
                printf("LinkedList telah dihapus.\n");
                break;

            case 5:
                printf("Keluar dari program.\n");
                break;

            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (choice != 5);

    // Pastikan memori bersih saat keluar
    list_destroy(&list);

    return 0;
}
