#include "boolean.h"
#include <stdio.h>
#include "mesinkarakter.h"

// #define MARK '.'
// /* State Mesin */
// extern char currentChar;
// extern boolean EOP;

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START() {
    pita = stdin;
    ADV();
}

void ADV() {
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar==MARK);
    if (EOP) {
        fclose(pita);
    }
}

char GetCC() {
return currentChar;
}

boolean IsEOP() {
return currentChar == MARK;
}
