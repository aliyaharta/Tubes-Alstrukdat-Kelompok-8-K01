#ifndef MESINKARAKTER_H
#define MESINKARAKTER_H

#include "boolean.h"

#define MARK '\n' // Penanda akhir dari input

// State Mesin Karakter
extern char currentChar;  // Karakter yang sedang diproses
extern boolean EOP;       // End of Process, apakah sudah mencapai akhir input

void START(char *filename);  
// Fungsi ini digunakan untuk Inisialisasi Mesin Karakter (input bisa dari file atau stdin)
void ADV();                  
// Fungsi ini digunakan untuk pindah ke karakter berikutnya
char GetCC();                
// Fungsi ini digunakan untuk mengambil karakter saat ini
boolean IsEOP();             
// Fungsi ini digunakan untuk mengecek apakah sudah sampai di akhir input
boolean IsNewline(); 
// Fungsi ini digunakan untuk mengecek apakah karakter saat ini adalah newline


#endif
