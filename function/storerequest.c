#include "storerequest.h"

int inStore(ListBarang *barangList, char *name){
    for(int i = 0; i<barangList->count; i++){
        if(stringCompare(barangList->items[i].name,name)){
            return 1;
        }
    }
    return 0;
}

void storerequest(ListBarang barangList, Queue *queue){
    
    ArrayOfKata inputkata;

    printf("Nama barang yang diminta : ");
    inputkata = inputUser();

    char barang;

    combineword(&barang,inputkata);

    if (inputkata.WordCount > 0) {
        if (inStore(&barangList, &barang)) {
            printf("Barang sudah ada di Toko\n");
        } 
        else {
            if(inQueue(*queue, &barang)) {
                printf("Barang sudah ada di antrian\n");
            } 
            else {
                if (!isFull(*queue)) {
                    enqueue(queue, &barang);
                    CreateBarang(&barang, 0);
                    printf("Barang berhasil dimasukkan ke antrian: %s", queue->items[queue->tail]);
                    printf("%s",queue->items[queue->head]);
                    }
                else{
                    char temp;
                    dequeue(queue,&temp);
                    enqueue(queue,&barang);
                    CreateBarang(&barang, 0);
                    printf("%s",queue->items[queue->tail]);
                    printf("Barang berhasil dimasukkan ke antrian: %s", queue->items[queue->tail]);
                    printf("%s",queue->items[queue->head]);
                    }
            }
            // if (!isEmpty(*queue)) {
            // if (inQueue(*queue, &barang)) {
            //     printf("Barang sudah ada di antrian\n");
            // } 
            // else {
            //     if (!isFull(*queue)) {
            //         enqueue(queue, &barang);
            //         CreateBarang(&barang, 0);
            //         printf("Barang berhasil dimasukkan ke antrian: %s", queue->items[queue->tail]);
            //         printf("%s",queue->items[queue->head]);
            //     }
            //     else{
            //         char temp;
            //         dequeue(queue,&temp);
            //         enqueue(queue,&barang);
            //         CreateBarang(&barang, 0);
            //         printf("%s",queue->items[queue->tail]);
            //         printf("Barang berhasil dimasukkan ke antrian: %s", queue->items[queue->tail]);
            //         printf("%s",queue->items[queue->head]);
            //     }
            // }
            // }
            // else{
            //     enqueue(queue, &barang);
            //     CreateBarang(&barang, 0);
            //     printf("%s",queue->items[queue->tail]);
            //     printf("Barang berhasil dimasukkan ke antrian: %s\n", queue->items[queue->tail]);
            //     printf("%s",queue->items[queue->head]);
            // }
        }
    }
}
