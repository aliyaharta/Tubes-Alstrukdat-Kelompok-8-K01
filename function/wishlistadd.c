#include <stdio.h>
#include <stdlib.h>
#include "wishlistadd.h"

void wishlist_add(LinkedList *wishlist, char *item_name) {
    //Memeriksa barang apakah sudah ada di wishlist
    Node *current = wishlist->head;
    while (current != NULL) {
        if (list_compare_strings(current->data, item_name) == 0) {
            printf("%s sudah ada di wishlist!\n", item_name);
            return;
        }
        current = current->next;
    }
    
    //Menambahkan barang ke wishlist
    if(isinbarang(barangList,item_name)){
        if (list_insert_last(wishlist, item_name)) {
            printf("Berhasil menambahkan %s ke wishlist!\n", item_name);
        } 
        else {
            printf("Gagal menambahkan %s ke wishlist!\n", item_name);
        }
    }
    else{
        printf("Tidak ada barang dengan nama %s!\n",item_name);
    }
}


// int main() {
//     LinkedList wishlist;
//     list_create(&wishlist);

//     wishlist_add(&wishlist, "Ayam Goreng");
//     wishlist_add(&wishlist, "Burger");
//     wishlist_add(&wishlist, "Ayam Goreng"); 

//     printf("Isi wishlist:\n");
//     list_print(wishlist);
// }
