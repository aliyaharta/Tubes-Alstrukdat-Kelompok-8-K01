#include <stdio.h>
#include "display.h"
#include "inputUser.h"
#include "boolean.h"
#include "compare.h"
#include "readfile.h"

int main (){
    boolean isExit = false;
    boolean isDone = false;

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    welcome_menu();
    ArrayOfKata inputkata;
    while(!isExit){
        isDone = false;
        do{ printf(">> ");
            inputkata = inputUser();
            printf("\n");

        if (stringCompare(inputkata.kata[0], "QUIT") && inputkata.WordCount == 1) {
            printf("\n\nKamu keluar dari PURRMART.\nDadah ^_^/\n\n");
            delay(250);
            keluar_game();
            isExit = true;
            isDone = true;
        }
        else if (stringCompare(inputkata.kata[0], "HELP") && inputkata.WordCount == 1) {
            login_help();
            printf("\n\n");
            isDone = true;
        }
        else if (stringCompare(inputkata.kata[0], "START") && inputkata.WordCount == 1) {

            if(readFile("SAVE/BASE/data.txt")==0){
                printf("File konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.\n\n");
            }
            else {
                printf("File konfigurasi telah rusak. Lakukan install ulang! \n\n");
            }
            
            isDone = true;
        }
        else if (stringCompare(inputkata.kata[0], "LOAD") && inputkata.WordCount == 2) {
            printf("Meload /save/");
            isDone = true;
        }
        else if (stringCompare(inputkata.kata[0], "SAVE") && inputkata.WordCount == 2) {
            printf("Save file\n\n");
            isDone = true;
        }
        else if (stringCompare(inputkata.kata[0], "LOGIN") && inputkata.WordCount == 1) {
            printf("Username:\nPassword:\n\n");
            isDone = true;
        }
        else if (stringCompare(inputkata.kata[0], "LOGOUT") && inputkata.WordCount == 1) {
            printf("Anda telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n\n");
            isDone = true;
        }
        else if (stringCompare(inputkata.kata[0], "REGISTER") && inputkata.WordCount == 1) {
            printf("Username:\nPassword:\n\n");
            isDone = true;
        }
        else if (stringCompare(inputkata.kata[0], "WORK") && inputkata.WordCount == 1) {
            printf("Daftar pekerjaan:\n\n");
            isDone = true;
        } 
        else if (stringCompare(inputkata.kata[0], "WORK") && stringCompare(inputkata.kata[1],"CHALLENGE") && inputkata.WordCount == 2) {
            printf("Daftar challenge yang tersedia:\n1. Tebak Angka (biaya main=200)\n2. W0RDL399 (biaya main=500)\n\n");
            isDone = true;
        } 
        else if (stringCompare(inputkata.kata[0], "STORE") && stringCompare(inputkata.kata[1],"LIST") && inputkata.WordCount == 2) {
            printf("List barang yang ada di toko :\n\n");
            isDone = true;
        } 
        else if (stringCompare(inputkata.kata[0], "STORE") && stringCompare(inputkata.kata[1],"REQUEST") && inputkata.WordCount == 2) {
            printf("Nama barang yang diminta: \n\n");
            isDone = true;
        } 
        else if (stringCompare(inputkata.kata[0], "STORE") && stringCompare(inputkata.kata[1],"SUPPLY") && inputkata.WordCount == 2) {
            printf("Apakah kamu ingin menambahkan barang ");
            isDone = true;
        } 
        else if (stringCompare(inputkata.kata[0], "STORE") && stringCompare(inputkata.kata[1],"REMOVE") && inputkata.WordCount == 2) {
            printf("Nama barang yang akan dihapus: ");
            isDone = true;
        } 
        }while(!isDone);
        
    }

    return 0;
}