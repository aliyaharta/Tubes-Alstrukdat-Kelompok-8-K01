#include <stdio.h>
#include "copystr.h"

int main() {
    char source[100];      // Buffer untuk string sumber
    char destination[100]; // Buffer untuk string tujuan

    // Membaca string sumber dari input menggunakan fscanf
    printf("Masukkan string sumber (tanpa spasi): ");
    fscanf(stdin, "%s", source); // Membaca hingga spasi atau newline

    // Menyalin string sumber ke tujuan
    copyString(destination, source);

    // Menampilkan hasil
    printf("String sumber: %s\n", source);
    printf("String tujuan (hasil salinan): %s\n", destination);

    return 0;
}
