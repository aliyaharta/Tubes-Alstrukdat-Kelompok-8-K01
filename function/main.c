#include <stdio.h>
#include "mesinkata.h"
#include "main.h"

int main() {
    // Menggunakan input dari keyboard (stdin)
    STARTKATA(NULL); // NULL berarti menggunakan stdin

    while (!IsEndKata()) {
        Kata word = GetCKata();
        printf("%s\n", word.TabKata); // Menampilkan kata
        ADVKATA(); // Lanjutkan ke kata berikutnya
    }

    return 0;
}
