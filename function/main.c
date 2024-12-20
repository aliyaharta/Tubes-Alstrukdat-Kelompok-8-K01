#include <stdio.h>
#include "display.h"
#include "inputUser.h"
#include "boolean.h"
#include "compare.h"
#include "readfile.h"
#include "user.h"
#include "copystr.h"
#include "writefile.h"
#include "work.h"
#include "copystr.h"
#include "barang.h"
#include "combineword.h"
#include "storelist.h"
#include "storerequest.h"
#include "playChallenge.h"


int main (){

    boolean isExit = false;
    boolean isDone = false;
    boolean isLogin = false;
    boolean dataLoaded = false;
    int UserIndex;
    Queue antrian;

    printf("\033[3J\033[H\033[J");
    printf("\n\n\n");

    welcome_menu();
    ArrayOfKata inputkata;
    createQueue(&antrian);

    while(!isExit){
        isDone = false;
        do{ printf("\n>> ");
            inputkata = inputUser();
            printf("\n");

            // printf("\033[3J\033[H\033[J");
            printf("\n\n\n");
            loadingScreen(120);
            // printf("\033[3J\033[H\033[J");
            // printf("\n\n\n");
            if (stringCompare(inputkata.kata[0], "QUIT") && inputkata.WordCount == 1) {
                printf("\033[3J\033[H\033[J");            
                delay(1,'s');
                keluar_game();
                isExit = true;
                isDone = true;
            }

            else if (stringCompare(inputkata.kata[0], "START") && inputkata.WordCount == 1) {

                delay(300,'m');
                if(readFile("SAVE/BASE/data.txt")==0){
                    printf("File konfigurasi aplikasi berhasil dibaca. PURRMART berhasil dijalankan.\n");
                }
                else {
                    printf("File konfigurasi telah rusak. Lakukan install ulang! \n");
                }
                dataLoaded = true;
                isDone = true;
            }

            else if (stringCompare(inputkata.kata[0], "LOAD") && inputkata.WordCount == 2) {
                
                printf("Memuat file %s",inputkata.kata[1]);
                delay(380,'m');
                printf(".");
                delay(380,'m');
                printf(".");
                delay(380,'m');
                printf(".\n\n");
                delay(1,'s');
                char filepath[150];
                sprintf(filepath, "SAVE/%s", inputkata.kata[1]);
                if(readFile(filepath)==0){
                    printf("Save file berhasil dibaca. PURRMART berhasil dijalankan.\n");
                }
                else {
                    printf("Save file tidak ditemukan. PURRMART gagal dijalankan. \n");
                }
                dataLoaded = true;
                isDone = true;
            }

            else if (stringCompare(inputkata.kata[0], "LOGIN") && inputkata.WordCount == 1) {
                if (dataLoaded){
                    if (!isLogin){
                    printf("Username: ");
                    ArrayOfKata username = inputUser();
                    printf("Password: ");
                    ArrayOfKata password = inputUser();
                    
                    if (username.WordCount == 1 && password.WordCount == 1) {
                            int idx = getIndex(username.kata[0]); // Directly call getIndex
                            if (idx != -1 && stringCompare(userList[idx].password, password.kata[0])) {
                                printf("\nLogin berhasil! \nSelamat datang, %s\n", userList[idx].name);
                                UserIndex = idx;
                                isLogin = true; // Update login status
                                isDone = true;
                            } else {
                                printf("Username atau password salah. Silakan coba lagi.\n");
                            }
                        }
                    else if(password.WordCount>1){
                        printf("Username atau password salah. Silakan coba lagi.\n");

                    }     
                    else {
                        printf("Anda telah login.\n");
                    }
                    }
                }
                else{
                    printf("Lakukan START atau LOAD terlebih dahulu\n");
                }
            }

            else if (stringCompare(inputkata.kata[0], "LOGOUT") && inputkata.WordCount == 1) {
                
                if (isLogin){
                    printf("Anda telah logout dari sistem PURRMART.\nSilakan REGISTER/LOGIN kembali untuk melanjutkan.\n");
                    isLogin = false;
                }
                else {
                    printf("Anda belum login.\n");
                }
                isDone = true;
                dataLoaded = false;
            }

            else if (stringCompare(inputkata.kata[0], "REGISTER") && inputkata.WordCount == 1 && !isLogin) {
                if (dataLoaded){
                    if (userCount<maxUser){
                        printf("Username: ");
                        ArrayOfKata username = inputUser();

                        if (getIndex(username.kata[0])==-1){
                            copyString(userList[userCount].name,username.kata[0]);
                            printf("Password: ");
                            ArrayOfKata password = inputUser();
                            copyString(userList[userCount].password,password.kata[0]);
                            userList[userCount].money=0;
                            userCount++;
                            printf("User berhasil ditambahkan\n");
                        }
                        else {
                            printf("Username tidak tersedia!\n");
                        }

                    }
                    else{
                        printf("Jumlah user telah maksimal.\n");
                    }
                    isDone = true;
                }
                else{
                    printf("Lakukan START atau LOAD terlebih dahulu");
                }
            }


            else if (stringCompare(inputkata.kata[0], "WORK") && inputkata.WordCount == 1 && isLogin) {
                work(UserIndex);
                isDone = true;
            } 

            else if (stringCompare(inputkata.kata[0], "HELP") && inputkata.WordCount == 1) {
                
                login_help(isLogin);
                isDone = true;
            }

            else if (stringCompare(inputkata.kata[0], "SAVE") && inputkata.WordCount == 2) {
                
                printf("Menyimpan file %s",inputkata.kata[1]);
                delay(380,'m');
                printf(".");
                delay(380,'m');
                printf(".");
                delay(380,'m');
                printf(".\n\n");
                char filepath[150];
                sprintf(filepath, "SAVE/%s", inputkata.kata[1]);
                writeFile(filepath);
                isDone = true;
            }
            else if (stringCompare(inputkata.kata[0], "WORK") && stringCompare(inputkata.kata[1],"CHALLENGE") && inputkata.WordCount == 2) {
                playChallenge(UserIndex);
                isDone = true;
            } 
            else if (stringCompare(inputkata.kata[0], "STORE") && stringCompare(inputkata.kata[1],"LIST") && inputkata.WordCount == 2) {
                storelist(&barangList);
                isDone = true;
            } 
            else if (stringCompare(inputkata.kata[0], "STORE") && stringCompare(inputkata.kata[1],"REQUEST") && inputkata.WordCount == 2) {
                Queue antrian;
                createQueue(&antrian);
                storerequest(barangList,&antrian);
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
            else if (stringCompare(inputkata.kata[0], "PROFILE") && inputkata.WordCount == 1){
                printf("Nama : %s\n",userList[UserIndex].name);
                printf("Money : %d\n",userList[UserIndex].money);
                isDone = true;
            }
            else if (stringCompare(inputkata.kata[0], "CART") && stringCompare(inputkata.kata[1],"SHOW") && inputkata.WordCount == 2){
                // showCartItems(userList[UserIndex].cart);
                isDone = true;
            }
            else if (stringCompare(inputkata.kata[0], "CART") && stringCompare(inputkata.kata[1],"ADD") && inputkata.WordCount == 2){
                isDone = true;
            }
            else if (stringCompare(inputkata.kata[0], "CART") && stringCompare(inputkata.kata[1],"REMOVE") && inputkata.WordCount == 2){
                isDone = true;
            }
            else if (stringCompare(inputkata.kata[0], "CART") && stringCompare(inputkata.kata[1],"SHOW") && inputkata.WordCount == 2){
                isDone = true;
            }
            else if (stringCompare(inputkata.kata[0], "CART") && stringCompare(inputkata.kata[1],"PAY") && inputkata.WordCount == 2){
                isDone = true;
            }
            else{
                printf("Masukkan command yang sesuai!\nPastikan menggunakan huruf kapital!\ncommand 'HELP' untuk bantuan\n");
            }
        }while(!isDone);
        
    }

    return 0;
}