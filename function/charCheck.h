#ifndef CHARCHECK_H
#define CHARCHECK_H
#define WORD_LENGTH 5  

/**
 * I.S. 
 * - `jawaban` adalah string yang berisi kata kunci dengan panjang WORD_LENGTH.
 * - `tebakan` adalah string yang berisi tebakan pengguna dengan panjang WORD_LENGTH.
 * - `hasil` adalah array kosong dengan ukuran minimal WORD_LENGTH * 4 + 1.
 *
 * F.S.
 *   - `hasil` berisi representasi visual dari hasil pengecekan:
 *   - Huruf yang benar di posisi yang tepat ditampilkan dengan huruf itu sendiri, diikuti tiga spasi.
 *   - Huruf yang benar tetapi di posisi salah ditampilkan dengan huruf itu, diikuti tanda bintang (*) dan dua spasi.
 *   - Huruf yang salah ditampilkan dengan huruf itu, diikuti tanda persen (%) dan dua spasi.
 * - Contoh hasil: "T*  R*  U%  L%  Y%""
 */
void charCheck(const char *jawaban, const char *tebakan, char *hasil);

#endif 