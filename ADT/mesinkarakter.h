#ifndef MESINKARAKTER_H
#define MESINKARAKTER_H

#include "boolean.h"

#define MARK '\n' // Penanda akhir dari input

// State Mesin Karakter
extern char currentChar;  // Karakter yang sedang diproses
extern boolean EOP;       // End of Process, apakah sudah mencapai akhir input

void START(char *filename);  // Inisialisasi mesin karakter (input bisa dari file atau stdin)
void ADV();                  // Pindah ke karakter berikutnya
char GetCC();                // Mengambil karakter saat ini
boolean IsEOP();             // Mengecek apakah sudah sampai di akhir input
boolean IsNewline(); // Mengecek apakah karakter saat ini adalah newline


#endif
