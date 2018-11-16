#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "GetTabel.c"

void main()
{
    char tabel[100];
    scanf("%s", tabel);

    readTabel(tabel);
}