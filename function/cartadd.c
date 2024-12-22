#include <stdio.h>
#include "cartadd.h"

void addcart(SetMap *cart, ListBarang barangList, char *name, int quantity){
    if(isinbarang(barangList,name)){
        if(isFullCart(*cart)){
            printf("Keranjang Full!\n");
        }
        else{
            int index = findCartItem(*cart, name);
    
            if(index != CART_NOT_FOUND){
                cart->Items[index].Quantity = cart->Items[index].Quantity + quantity;
                printf("Berhasil menambahkan %d %s ke keranjang belanja!!!\n", quantity, name);
            }
            else {
                copyString(cart->Items[cart->Count].Name, name);
                cart->Items[cart->Count].Quantity = quantity;
                cart->Count = cart->Count + 1;
                printf("Berhasil menambahkan %d %s ke keranjang belanja!!!\n", quantity, name);
            }
        }
    }
    else{
        printf("Barang tidak ada di toko!\n");
    }
}
