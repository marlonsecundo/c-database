#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct column
{
    char name[60];
    int type;
} Column;

typedef struct data
{
    char value[200];
} Data;

typedef struct tabel
{
    int primary;
    Column *columns;
    Data *data;
    int length;
    char name[60];
} Tabel;