#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SetTabel(Tabel tabel)
{
    if (tabel.colLength == 0)
    {
        system("cls");
        printf("Digite uma tabela valida\n\n");
        return;
    }

    setbuf(stdin, NULL);

    FILE *fileTabel = fopen(tabel.name, "w");

    fprintf(fileTabel, "Colunas [\n");

    for (int i = 0; i < tabel.colLength; i++)
    {
        fprintf(fileTabel, "{ Name:%s Type:%d }\n", tabel.columns[i].name, tabel.columns[i].type);
    }

    fprintf(fileTabel, "]\n\n");

    fprintf(fileTabel, "Chave Primaria:%d\n\n", tabel.primary);

    fprintf(fileTabel, "Data\n");
    for (int i = 0; i < tabel.dataLength; i++)
    {
        fprintf(fileTabel, "%s", tabel.data[i].value);
    }

    fclose(fileTabel);
}