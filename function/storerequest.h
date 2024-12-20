#ifndef STOREREQUEST_H
#define STOREREQUEST_H

#include <stdio.h>
#include "./../ADT/barang.h"
#include "./../ADT/mesinkarakter.h"
#include "./../ADT/mesinkata.h"
#include "./../ADT/queue.h"
#include "./../ADT/inputUser.h"
#include "./../ADT/copystr.h"
#include "./../ADT/combineword.h"
#include "compare.h"

void inToko(ListBarang barangList, char name);
void storerequest(ListBarang barangList, Queue *q);

#endif