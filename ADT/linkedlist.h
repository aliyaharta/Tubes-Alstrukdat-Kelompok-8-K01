#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define MAX_LEN 100

typedef struct Node {
    char data[MAX_LEN];
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} LinkedList;

// Fungsi untuk membuat LinkedList kosong
void list_create(LinkedList *list);

// Fungsi untuk menghancurkan LinkedList dan membebaskan memori
void list_destroy(LinkedList *list);

// Fungsi untuk menambahkan elemen di akhir LinkedList
int list_insert_last(LinkedList *list, const char *data);

// Fungsi untuk mendapatkan panjang LinkedList
int list_length(const LinkedList list);

// Fungsi untuk mendapatkan node pada posisi tertentu
Node *list_get_node(const LinkedList list, int position);

// Fungsi untuk mencetak isi LinkedList
void list_print(const LinkedList list);

// Fungsi untuk membandingkan dua string tanpa string.h
int list_compare_strings(const char *str1, const char *str2);

#endif
