#ifndef PLAYCHALLENGE_H
#define PLAYCHALLENGE_H

#include <stdio.h>
#include "challenge.h"

// Deklarasi fungsi playChallenge
/**
 * I.S.
 * - Daftar challenge sudah tersedia.
 * - Pengguna memiliki sejumlah uang (variabel global `money`) untuk bermain challenge.
 * - Fungsi `challenge()` sudah terdefinisi dan dapat dipanggil.
 *
 * F.S.
 * - Pengguna dapat memilih dan memainkan challenge yang tersedia selama mereka memiliki cukup uang.
 * - Jika input tidak valid, akan meminta pengguna untuk memasukkan input yang benar.
 * - Program akan terus menawarkan challenge hingga pengguna memilih keluar dengan input `n`.
 */
void playChallenge(int userIndex);

#endif // PLAYCHALLENGE_H