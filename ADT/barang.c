#include "barang.h"
#include <stdlib.h>

ListBarang barangList;

Barang CreateBarang(const char *name, int price) {
    Barang newItem;
    
    copyString(newItem.name, name);

    newItem.name[WordMax - 1] = '\0';
    newItem.price = price;

    return newItem;
}

void CreateListBarang(ListBarang *barangList, int capacity){
    barangList -> items = (Barang *)malloc(capacity * sizeof(Barang));
    barangList -> capacity = capacity;
    barangList -> count = 0;
}

boolean isEmptyBarang(ListBarang *listBarang){
    return(listBarang->count == 0);
}

int findItemBarang(ListBarang *ListBarang, char *name){
    for (int i = 0; i < barangList.count; i++){
        if (stringCompare(barangList.items[i].name,name)){
            return i;
        }
    }
    return -1;
}