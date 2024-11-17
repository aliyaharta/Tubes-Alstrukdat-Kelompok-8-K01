#include "storeList.h"

void storeList(ListBarang lb){
    if (lb.count == 0){
        printf("TOKO KOSONG\n");
        return;
    }

    printf("List barang yang ada di toko: \n");

    int i, j, jumUnique=0;
    Barang barangUnique[lb.capacity];

    for (i=0; i<lb.count; i++){
        int isUnique = 1;

        printf("- ");
        for (j=0; j<jumUnique; j++){
            if (IsBarangNameEqual(&lb.items[i], (Word *)&barangUnique[j].name)){
                isUnique = 0;
                break;
            }
        }

        if (isUnique) {
            barangUnique[jumUnique++] = lb.items[i];
            printf("- %s\n", lb.items[i].name);
        }
    }
}