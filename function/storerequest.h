#ifndef STOREREQUEST_H
#define STOREREQUEST_H

#include <stdio.h>
#include "barang.h"
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "queue.h"
#include "inputUser.h"
#include "copystr.h"
#include "combineword.h"
#include "compare.h"

void inToko(ListBarang barangList, char name);
void storerequest(ListBarang barangList, Queue *q);

#endif