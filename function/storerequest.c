#include "storerequest.h"

void storerequest(ListBarang barangList, Queue *queue){
    
    ArrayOfKata inputkata;

    printf("Nama barang yang diminta : ");
    inputkata = inputUser();

    char barang[WordMax];

    combineword(barang,inputkata);

    if (inputkata.WordCount > 0) {
        if (isinbarang(barangList, barang)) {
            printf("Barang sudah ada di Toko\n");
        } 
        else {
            if(inQueue(*queue, barang)) {
                printf("Barang sudah ada di antrian\n");
            } 
            else {
                if (!isFull(*queue)) {
                    enqueue(queue, barang);
                    CreateBarang(barang, 0);
                    printf("Barang berhasil dimasukkan ke antrian: %s\n", queue->items[queue->tail]);
                }
                else{
                    char temp;
                    dequeue(queue,&temp);
                    enqueue(queue,barang);
                    CreateBarang(barang, 0);
                    printf("Barang berhasil dimasukkan ke antrian: %s\n", queue->items[queue->tail]);
                }
            }
        }
    }
}
