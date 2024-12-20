#include <stdio.h>
#include "showCart.h"

// int findItemBarang(SetMap cart, char *name){
//     for (int i = 0; i < barangList.count; i++){
//         if (stringCompare(barangList[i].name,name)){
//             return i;
//         }
//     }
//     return CART_NOT_FOUND;
// }

void showCartItems(SetMap cart){
    if(isEmptyCart(cart)){
        printf("Keranjang belanja kamu kosong\n");
    }
    else{
        printf("Berikut adalah isi keranjangmu.\n");
        printf("Kuantitas Nama Total\n");
        for (int i=0;i<cart.Count;i++){
            int indexbarang = findItemBarang(&barangList,cart.Items[i].Name);
            int cartCost = cart.Items[i].Quantity * barangList.items[indexbarang].price;
            printf("%d %s %d\n",cart.Items[i].Quantity, cart.Items[i].Name, cartCost);
        }
    }
}
