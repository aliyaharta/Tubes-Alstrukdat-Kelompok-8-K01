#include <stdio.h>
#include "mesinkarakter.h"
#include "config.h"

int main(void) {
    char filename[100];
    printf("Masukkan nama file: ");
    scanf("%s", filename);

    START(filename);
    while (!IsEOP()) {
        printf("Karakter yang dibaca: %c\n", GetCC());
        ADV();
    }
    printf("Selesai membaca file.\n");

    return 0;


}