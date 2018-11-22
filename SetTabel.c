#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SetTabel(Tabel tabel)
{ 
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);

    FILE *fileTabel = fopen(tabel.name, "w");

    fprintf(fileTabel, "Colunas [\n");

    printf("Colunas: %d\n", tabel.colLength);

    for (int i = 0; i < tabel.colLength; i++)
    {
        fprintf(fileTabel, "{ Name:%s Type:%d }\n", tabel.columns[i].name, tabel.columns[i].type);
    }

    fprintf(fileTabel, "]\n\n");

    fprintf(fileTabel, "Chave Primaria:%d\n\n", tabel.primary);

    fprintf(fileTabel, "Data\n");
    printf("Data: %d\n", tabel.dataLength);
    for (int i = 0; i < tabel.dataLength; i++)
    {
        fprintf(fileTabel, "%s", tabel.data[i].value);
    }

    fclose(fileTabel);

    setbuf(stdin, NULL);
}