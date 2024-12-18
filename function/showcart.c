#include <stdio.h>
#include "showCart.h"

int findItemBarang(const char *name){
    for (int i = 0; i < barangCount; i++){
        if (stringCompare(barangList[i].name,name)){
            return i;
        }
    }
    return CART_NOT_FOUND;
}

void showCartItems(SetMap cart){
    if(isEmptyCart(cart)){
        printf("Keranjang belanja kamu kosong\n");
    }
    else{
        printf("Berikut adalah isi keranjangmu.\n");
        printf("Kuantitas Nama Total\n");

        for (int i=0;i<cart.Count;i++){
            int indexBarang = findItemBarang(cart.Items[i].Name);

            if (indexBarang != CART_NOT_FOUND){
                int cartCost = cart.Items[i].Quantity * barangList[indexBarang].price;
                printf("%d %s %d\n",cart.Items[i].Quantity, cart.Items[i].Name, cartCost);
            }
        }
    }
}
