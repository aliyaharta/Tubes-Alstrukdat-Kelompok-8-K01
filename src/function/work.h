#ifndef WORK_H
#define WORK_H

#include <stdio.h>

extern int money;

#define MAX_LEN 50
typedef struct {
    char name[MAX_LEN];
    char password[MAX_LEN];
    int money;
} User;

/* 
I.S: Pemain belum memilih pekerjaan dan belum melakukan aktivitas kerja.
F.S: Pemain memilih pekerjaan, menunggu selama durasi yang sesuai, dan mendapatkan gaji yang ditambahkan ke uang pemain.
*/
void work();

#endif // WORK_H
