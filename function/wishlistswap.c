#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h" 

void wishlist_swap(LinkedList *wishlist, int i, int j) {
    // Periksa indeks udah bener apa belum
    if (i <= 0 || j <= 0 || i > list_length(*wishlist) || j > list_length(*wishlist)) {
        printf("Indeks tidak valid untuk melakukan swap!\n");
        return;
    }

    // Ambil pointer elemen pada posisi i dan j
    Node *node_i = list_get_node(*wishlist, i);
    Node *node_j = list_get_node(*wishlist, j);

    if (node_i == NULL || node_j == NULL) {
        printf("Gagal melakukan swap karena elemen tidak ditemukan!\n");
        return;
    }

    // Menukar isi elemen
    char temp[MAX_LEN];
    for (int k = 0; k < MAX_LEN; k++) {
        temp[k] = node_i->data[k];
        node_i->data[k] = node_j->data[k];
        node_j->data[k] = temp[k];
    }

    printf("Berhasil menukar posisi %s dengan %s pada wishlist!\n", node_i->data, node_j->data);
}


// int main() {
//     LinkedList wishlist;
//     list_create(&wishlist);

//     wishlist_swap(&wishlist, 1, 2); 
//     wishlist_swap(&wishlist, 1, 3); 

//     printf("Isi wishlist setelah swap:\n");
//     list_print(wishlist);

//     list_destroy(&wishlist);
//     return 0;
// }
