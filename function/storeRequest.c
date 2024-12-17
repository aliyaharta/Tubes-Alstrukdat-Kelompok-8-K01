#include "storeRequest.h"

void storeRequest(ListBarang lb, Queue *q) {
    ArrayOfKata input;
    Kata barangReq;

    printf(">> STORE REQUEST\n");
    printf("Nama barang yang diminta: ");
    input = inputUser();

    if (input.WordCount > 0) {
        // Copy the requested barang name
        int length = 0;
        while (input.kata[0][length] != '\0') {
            length++;
        }

        barangReq.Length = length; 
        copyString(barangReq.TabKata, input.kata[0]);
    } else {
        printf("Input tidak valid.\n");
        return;
    }

    // Check if barang already exists in the store
    int i;
    for (i = 0; i < lb.count; i++) {
        if (IsBarangNameEqual(&lb.items[i], &barangReq)) {
            printf("Barang dengan nama yang sama sudah ada di toko!\n");
            return;
        }
    }

    // Check if barang already exists in the queue (waiting list)
    int panjangQueue = length(*q);
    for (i = 0; i < panjangQueue; i++) {
        int idx;
        dequeue(q, &idx);

        if (IsBarangNameEqual(&lb.items[idx], &barangReq)) {
            printf("Barang dengan nama sama sudah ada di antrean!\n");
            enqueue(q, idx);  // Re-add to queue
            return;
        }
        enqueue(q, idx);  // Re-add to queue
    }

    // Add new barang to queue
    Barang barangBaru;
    CreateBarang(&barangBaru, &barangReq, 0);  // Default price 0
    enqueue(q, lb.count);  // Add item index to queue
    printf("Nama barang yang diminta: %s\n", barangReq.TabKata);
}
