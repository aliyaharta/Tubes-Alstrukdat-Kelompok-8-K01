#ifndef STOREREQUEST_H
#define STOREREQUEST_H

#include <stdio.h>
#include "src/ADT/barang.h"
#include "src/ADT/list_barang.h"
#include "src/ADT/mesinkarakter.h"
#include "src/ADT/mesinkata.h"
#include "src/ADT/queue.h"

void storeRequest(ListBarang lb, Queue *q, const Word *barangReq);

#endif