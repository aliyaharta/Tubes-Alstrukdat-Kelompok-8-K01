// delay.h
#ifndef DELAY_H
#define DELAY_H

#include <time.h>

/**
 * I.S.
 * - `seconds` adalah bilangan integer positif yang merepresentasikan durasi waktu tunda dalam detik.
 *
 * F.S.
 * - Program berhenti (tertunda) selama `seconds` detik sebelum melanjutkan eksekusi ke baris kode berikutnya.
 * - Tidak ada perubahan pada variabel lain selama fungsi ini berjalan.
 */
void delay(int seconds);

#endif // DELAY_H
