// #include <stdio.h>
// #include "mesinkata.h"
// #include "mesinkarakter.h"

// int main() {
//     char filename[100];
//     FILE *file = fopen("data.txt", "r");

//     // Membuka file untuk input nama file
//     if (file == NULL) {
//         printf("Gagal membuka file 'data.txt' untuk membaca nama file.\n");
//         return 1;
//     }

//     // Membaca nama file dari `data.txt`
//     fscanf(file, "%s", filename);
//     fclose(file);

//     // Memulai mesin kata pada file yang disebutkan
//     STARTKATA(filename);

//     if (IsEndKata()) {
//         printf("File kosong atau hanya berisi spasi!\n");
//         return 0;
//     }

//     printf("Hasil pembacaan kata-kata dari file '%s':\n", filename);
//     int word_count = 0;

//     while (!IsEndKata()) {
//         Kata current = GetCKata();
//         printf("Kata %d: %s (Panjang: %d)\n", word_count + 1, current.TabKata, getLength(current));
//         word_count++;
//         ADVKATA();
//     }

//     printf("\nTotal kata yang dibaca: %d\n", word_count);

//     return 0;
// }
