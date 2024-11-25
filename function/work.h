#ifndef WORK_H
#define WORK_H

#include "inputUser.h"
#include "delay.h"
#include "compare.h"
#include "mesinkata.h"

extern int money;

#define MAX_LEN 50

/* 
I.S: Pemain belum memilih pekerjaan dan belum melakukan aktivitas kerja.
F.S: Pemain memilih pekerjaan, menunggu selama durasi yang sesuai, dan mendapatkan gaji yang ditambahkan ke uang pemain.
*/
void work(int idx);

#endif // WORK_H
