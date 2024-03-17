#include <stdio.h>
#include "database.h"
#include "computer.h"
#include <stdlib.h>


int db_write(char *database, Computer *computer) {
    FILE *fp = fopen(database, "wb");;
    char *c = (char *)computer;

    for (int i = 0; i < sizeof(Computer); i++) {
        putc(*c++, fp);
    }
    fclose(fp);
    return 0;
}

Computer *db_read(char *database) {
    FILE *db;
    int i;
    Computer * comp = malloc(sizeof(Computer));
    db = fopen(database, "rb");
    char *c = (char *)comp;

    while ((i = getc(db)) != EOF) {
        *c = i;
        c++;
    }

    fclose(db);
    return comp;
}