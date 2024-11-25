#ifndef compare_h
#define compare_h

/**
 * I.S.
 * - `str1` dan `str2` adalah dua string yang tidak kosong dan berakhir dengan karakter null (`\0`).
 *
 * F.S.
 * - Mengembalikan `1` jika kedua string identik (panjang dan karakter pada posisi yang sama).
 * - Mengembalikan `0` jika ada perbedaan antara kedua string (panjang berbeda atau ada karakter berbeda).
 */
int stringCompare(const char *str1, const char *str2);

#endif
