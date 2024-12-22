#include <stdio.h>
#include "storelist.h"

void storelist(ListBarang barangList){
    if(isEmptyBarang(barangList)){
        printf("Toko kamu kosong\n");
    }
    else{
        printf("List Barang di toko :\n");
        for(int i=0;i<barangList.count;i++){
            printf("%s - Harga : %d\n",barangList.items[i].name, barangList.items[i].price);
        }
    }
}