#include "queue.h"
#include <stdio.h>

#define MAX_ITEM_LENGTH 100

int main() {
    Queue antrian;
    char item[MAX_ITEM_LENGTH];

    // Inisialisasi queue
    createQueue(&antrian);

    while (1) {
        printf("\nMenu:\n");
        printf("[E]nqueue (Tambah item ke antrian)\n");
        printf("[D]equeue (Hapus item dari antrian)\n");
        printf("[C]ek apakah antrian kosong\n");
        printf("[F]Cek apakah antrian penuh\n");
        printf("[I]tem cek keberadaan dalam antrian\n");
        printf("[Q]uit (Keluar)\n");
        printf("Pilihan Anda: ");

        char command;
        scanf(" %c", &command);
        getchar(); 

        if (command == 'E' || command == 'e') {
            printf("Masukkan item untuk enqueue: ");
            int i = 0;
            char c;
            while ((c = getchar()) != '\n' && i < MAX_ITEM_LENGTH - 1) {
                item[i++] = c;
            }
            item[i] = '\0';

            if (!isFull(antrian)) {
                enqueue(&antrian, item);
                printf("Item '%s' berhasil ditambahkan ke antrian.\n", item);
            } else {
                printf("Antrian penuh. Tidak bisa menambahkan item baru.\n");
            }
        } else if (command == 'D' || command == 'd') {
            if (!isEmpty(antrian)) {
                dequeue(&antrian, item);
                printf("Item '%s' berhasil dihapus dari antrian.\n", item);
            } else {
                printf("Antrian kosong. Tidak ada item untuk dihapus.\n");
            }
        } else if (command == 'C' || command == 'c') {
            if (isEmpty(antrian)) {
                printf("Antrian kosong.\n");
            } else {
                printf("Antrian tidak kosong.\n");
            }
        } else if (command == 'F' || command == 'f') {
            if (isFull(antrian)) {
                printf("Antrian penuh.\n");
            } else {
                printf("Antrian tidak penuh.\n");
            }
        } else if (command == 'I' || command == 'i') {
            printf("Masukkan item yang ingin dicek: ");
            int i = 0;
            char c;
            while ((c = getchar()) != '\n' && i < MAX_ITEM_LENGTH - 1) {
                item[i++] = c;
            }
            item[i] = '\0';

            if (inQueue(antrian, item)) {
                printf("Item '%s' ada dalam antrian.\n", item);
            } else {
                printf("Item '%s' tidak ada dalam antrian.\n", item);
            }
        } else if (command == 'Q' || command == 'q') {
            printf("Keluar dari program.\n");
            break;
        } else {
            printf("Perintah tidak dikenal.\n");
        }
    }

    return 0;
}
