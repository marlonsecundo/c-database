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
    char value[500];
} Data;

typedef struct tabel
{
    char name[60];
    int primary;

    Column *columns;
    Data *data;

    int colLength;
    int dataLength;
} Tabel;