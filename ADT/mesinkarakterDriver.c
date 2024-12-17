// #include <stdio.h>
// #include "mesinkarakter.h"
// #include "config.h"

// int main(void) {
//     char filename[100];
//     FILE *file = fopen("data.txt", "r");

//     // Validasi pembukaan file data.txt
//     if (file == NULL) {
//         printf("Gagal membuka file 'data.txt'. Pastikan file tersebut ada.\n");
//         return 1;
//     }

//     // Membaca nama file dari data.txt
//     if (fscanf(file, "%s", filename) != 1) {
//         printf("Gagal membaca nama file dari 'data.txt'.\n");
//         fclose(file);
//         return 1;
//     }
//     fclose(file);

//     // Memulai mesin karakter
//     START(filename);
//     if (GetCC() == MARK) {
//         printf("File '%s' kosong atau hanya berisi tanda akhir.\n", filename);
//         return 0;
//     }

//     // Membaca karakter demi karakter hingga akhir file
//     printf("Membaca file '%s':\n", filename);
//     while (!IsEOP()) {
//         printf("Karakter yang dibaca: %c\n", GetCC());
//         ADV();
//     }

//     printf("Selesai membaca file '%s'.\n", filename);

//     return 0;
// }
