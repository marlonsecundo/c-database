#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void setTabel(Tabel tabel)
{
    int i;
    int count = sizeof(tabel.columns)/sizeof(Column*);
    FILE *set = fopen(tabel.name, "w");
    fprintf(set, "Colunas [\n");
    for (i = 0; i < count; i++)
    {
        fprintf(set, "{ Name:%s Type:%d }\n", tabel.columns[i].name, tabel.columns[i].type);
    }
    fprintf(set, "]\n\n");

    fprintf(set, "Chave Primaria:%d\n\n", tabel.primary);

    fprintf(set, "Data\n");
    
    fprintf(set, "{ ");
    
    
    fprintf(set, "}");
}