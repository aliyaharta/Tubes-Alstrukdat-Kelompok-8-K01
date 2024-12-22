#include "barang.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50

// bantu nyalin string
void copyString(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0' && i < MAX_NAME_LENGTH - 1) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// bantu bandingin string
boolean stringCompare(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}

int main() {
    ListBarang list;
    int capacity;

    printf("Masukkan kapasitas daftar barang: ");
    scanf("%d", &capacity);
    getchar(); 

    CreateListBarang(&list, capacity);

    if (isEmptyBarang(list)) {
        printf("Daftar barang kosong.\n");
    }

    // Menambahkan barang ke dalam daftar
    char name[MAX_NAME_LENGTH];
    int price;

    printf("Masukkan nama barang: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    int i = 0;
    while (name[i] != '\n' && name[i] != '\0') {
        i++;
    }
    name[i] = '\0'; 

    printf("Masukkan harga barang: ");
    scanf("%d", &price);

    Barang barangBaru = CreateBarang(name, price);

    if (list.count < list.capacity) {
        list.items[list.count++] = barangBaru;
        printf("Barang '%s' dengan harga %d berhasil ditambahkan.\n", name, price);
    } else {
        printf("Daftar barang penuh, tidak bisa menambahkan barang baru.\n");
    }

    // Mencari barang berdasarkan nama
    printf("Masukkan nama barang yang ingin dicari: ");
    getchar(); 
    fgets(name, MAX_NAME_LENGTH, stdin);
    i = 0;
    while (name[i] != '\n' && name[i] != '\0') {
        i++;
    }
    name[i] = '\0'; 

    int index = findItemBarang(list, name);
    if (index != -1) {
        printf("Barang '%s' ditemukan pada indeks %d dengan harga %d.\n", name, index, list.items[index].price);
    } else {
        printf("Barang '%s' tidak ditemukan dalam daftar.\n", name);
    }

    // Mengecek apakah barang ada di daftar
    printf("Masukkan nama barang untuk dicek: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    i = 0;
    while (name[i] != '\n' && name[i] != '\0') {
        i++;
    }
    name[i] = '\0'; 

    if (isinbarang(list, name)) {
        printf("Barang '%s' ada dalam daftar.\n", name);
    } else {
        printf("Barang '%s' tidak ada dalam daftar.\n", name);
    }

    // Membersihkan memori
    free(list.items);

    return 0;
}
