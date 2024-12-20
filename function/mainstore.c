#include <stdio.h>
#include <stdlib.h>
#include "storeRemove.h"
#include "storeSupply.h"

// #define MAX_BARANG 100
// #define MAX_USER 100

// // // Assuming these structures exist
// // typedef struct {
// //     char name[100];  // Nama barang
// //     int price;       // Harga barang
// // } Barang;

// // typedef struct {
// //     Barang items[MAX_BARANG];  // List barang
// //     int count;                 // Jumlah barang di toko
// //     int capacity;              // Kapasitas toko
// // } ListBarang;

// // typedef struct {
// //     char name[100];
// //     int money;
// //     char password[100];
// // } User;

// // Barang barangList[MAX_BARANG];
// // int barangCount = 0;

// // User userList[MAX_USER];
// // int userCount = 0;


int main() {
    // Inisialisasi data
    Queue antrian;
    ListBarang barangList;
    int kapasitasToko = 10; // Kapasitas maksimum toko

    // Membuat queue dan list barang
    createQueue(&antrian);
    CreateListBarang(&barangList, kapasitasToko);

    // Menambahkan beberapa item ke antrian
    enqueue(&antrian, "AK47");
    enqueue(&antrian, "Bazooka");
    enqueue(&antrian, "Sticky Web Gun");

    int pilihan;
    do {
        printf("\nMENU:\n");
        printf("1. Store Supply\n");
        printf("2. Store Remove\n");
        printf("3. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                storeSupply(&antrian, &barangList);
                break;
            case 2:
                storeRemove(&barangList);
                break;
            case 3:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
                break;
        }
    } while (pilihan != 3);

    // Membersihkan memori jika diperlukan
    free(barangList.items);

    return 0;
}
