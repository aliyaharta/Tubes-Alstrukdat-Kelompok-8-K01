#include <stdio.h>
#include "src/ADT/mesinkata.h"
#include "src/ADT/mesinkarakter.h"
#include "src/ADT/list_barang.h"
#include "src/ADT/barang.h"

void storeList(ListBarang lb){
    if (lb.count == 0){
        printf("TOKO KOSONG\n");
        return;
    }

    printf("List barang yang ada di toko: \n");

    int i, j;
    for (i=0; i<lb.count; i++){
        Barang barangIni = lb.items[i];

        printf("- ");
        for (j=0; j<barangIni.name->Length; j++){
            putchar(barangIni.name->TabWord[i]);
        }
        printf("\n");
    }
}