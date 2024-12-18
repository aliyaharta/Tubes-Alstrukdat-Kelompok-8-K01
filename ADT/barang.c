#include "barang.h"
#include <stdlib.h>

ListBarang barangList;

void CreateListBarang(ListBarang *barangList, int capacity){
    barangList -> items = (Barang *)malloc(capacity * sizeof(Barang));
    barangList -> capacity = capacity;
    barangList -> count = 0;
}

boolean isEmptyBarang(ListBarang *listBarang){
    return(listBarang->count == 0);
}

