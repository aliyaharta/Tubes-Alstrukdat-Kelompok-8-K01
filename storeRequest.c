#include "storeRequest.h"

void storeRequest(ListBarang lb, Queue *q){
    ArrayOfKata input;
    Word barangReq;

    printf("Masukkan nama barang yang diminta: ");
    input = inputUser();

    if (input.WordCount > 0) {
        int length = 0;
        while (input.kata[0][length] != '\0') {
            length++;
        }

        barangReq.Length = length; 
        CopyString(barangReq.TabWord, input.kata[0]);
    } else {
        printf("Input tidak valid.\n");
    }

    int i, panjangQueue = length(*q), idx;

    for (i=0; i<lb.count; i++){
        if (IsBarangNameEqual(&lb.items[i], &barangReq)){
            printf("Barang dengan nama yang sama sudah ada di toko!\n");
            return;
        }
    }

    for (i=0; i<panjangQueue; i++){
        dequeue(q, &idx);

        if (IsBarangNameEqual(&lb.items[idx], &barangReq)){
            printf("Barang dengan nama sama sudah ada di antrean!\n");
            enqueue(q, idx);
            return;
        }

        enqueue(q, idx);
    }

    Barang barangBaru;
    CreateBarang(&barangBaru, &barangReq, 0); 
    enqueue(q, lb.count); 
    printf("Nama barang yang diminta: %s\n", barangReq.TabWord);

}