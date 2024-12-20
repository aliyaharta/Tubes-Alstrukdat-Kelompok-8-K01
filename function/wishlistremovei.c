#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

void wishlist_removei(LinkedList *wishlist, int position) {
    if (wishlist->size == 0) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, WISHLIST kosong!\n");
        return;
    }

    if (position <= 0 || position > wishlist->size) {
        printf("Penghapusan barang WISHLIST gagal dilakukan, Barang ke-%d tidak ada di WISHLIST!\n", position);
        return;
    }

    Node *current = wishlist->head;
    Node *prev = NULL;

    // Iterasi untuk mencapai posisi ke-i
    for (int i = 1; i < position; i++) {
        prev = current;
        current = current->next;
    }

    // Hapus node pada posisi ke-i
    if (prev == NULL) { // Jika node yang dihapus adalah head
        wishlist->head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    wishlist->size--;

    printf("Berhasil menghapus barang posisi ke-%d dari wishlist!\n", position);
}


// int main() {
//     LinkedList wishlist;
//     list_create(&wishlist);

//     list_insert_last(&wishlist, "Barang1");
//     list_insert_last(&wishlist, "Barang2");
//     list_insert_last(&wishlist, "Barang3");

//     printf("Wishlist sebelum penghapusan:\n");
//     list_print(wishlist);

//     wishlist_remove(&wishlist, 2);

//     printf("Wishlist setelah penghapusan:\n");
//     list_print(wishlist);

//     wishlist_remove(&wishlist, 10);
//     wishlist_remove(&wishlist, 1);
//     wishlist_remove(&wishlist, 1);
//     wishlist_remove(&wishlist, 1);
//     list_destroy(&wishlist);

//     return 0;
// }
