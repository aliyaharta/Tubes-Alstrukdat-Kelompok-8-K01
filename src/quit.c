#include <stdio.h>
#include "list_barang.h"
#include "list_user.h"

void QuitProgram(ListBarang *lb, ListUser *lu) {
    Word saveOption;
    printf("Apakah Anda ingin menyimpan data sebelum keluar? (Y/N): ");

    //baca input user 
    STARTWORD(stdin);
    saveOption = CurrentWord;

    if ((saveOption.Length == 1 && (saveOption.TabWord[0] == 'Y' || saveOption.TabWord[0] == 'y'))) {
        printf("Masukkan nama file untuk menyimpan data; ");
        ADVWORD(); 

        char filename[50];
        for (int i = 0; i < CurrentWord.Length; i++) {
            filename[i] = CurrentWord.TabWord[i];
        }
        filename[CurrentWord.Length] = '\0';

        // panggil SaveProgram
        SaveProgram(*lb, *lu, filename);
    }

    printf("Terima kasih telah menggunakan program ini.\n");

    // mengosongkan memori ListBarang
    FreeListBarang(lb);
    

}