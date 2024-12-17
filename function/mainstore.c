#include <stdio.h>
#include <stdlib.h>
#include "readfile.h"
#include "storeList.h"
#include "storeRequest.h"

#define MAX_BARANG 100
#define MAX_USER 100

// // Assuming these structures exist
// typedef struct {
//     char name[100];  // Nama barang
//     int price;       // Harga barang
// } Barang;

// typedef struct {
//     Barang items[MAX_BARANG];  // List barang
//     int count;                 // Jumlah barang di toko
//     int capacity;              // Kapasitas toko
// } ListBarang;

// typedef struct {
//     char name[100];
//     int money;
//     char password[100];
// } User;

// Barang barangList[MAX_BARANG];
// int barangCount = 0;

// User userList[MAX_USER];
// int userCount = 0;

// // Function prototypes
// void storeList(ListBarang lb);
// void storeRequest(ListBarang lb, Queue *q);

int main() {
    // Membaca data dari file
    const char *filename = "barang.txt";  // Gantilah dengan nama file yang sesuai
    if (readFile(filename) != 0) {
        printf("Error membaca file\n");
        return 1;
    }

    // Menampilkan list barang menggunakan storeList
    ListBarang lb;
    lb.count = barangCount;
    lb.capacity = MAX_BARANG;
    for (int i = 0; i < barangCount; i++) {
        lb.items[i] = barangList[i];
    }

    printf(">> STORE LIST\n");
    storeList(lb);  // Menampilkan daftar barang di toko

    // Membuat queue untuk menyimpan request barang
    Queue q;
    CreateQueue(&q);

    // Menangani request barang menggunakan storeRequest
    printf("\n>> STORE REQUEST\n");
    storeRequest(lb, &q);

    return 0;
}
