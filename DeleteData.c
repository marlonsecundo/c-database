#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Tabel DeleteData(Tabel tabel)
{
    printf("\n -- Apagar Dados Na Tabela -- \n");
    char primary[100] = "";

    printf("Coluna de Chave Primaria: %s\n", tabel.columns[tabel.primary].name);
    printf("Digite o valor: ");
    scanf("%s", primary);

    int colIndex = -1;

    char name[100] = "";
    char data[300] = "";

    strcpy(name, tabel.columns[tabel.primary].name);

    strcat(data, name);
    strcat(data, ":");
    strcat(data, primary);

    int j = 0;


    Data *tabelData = (Data *)malloc(sizeof(Data));

    tabelData = (Data *)realloc(tabelData, (tabel.dataLength - 1) * sizeof(Data));

    for (int i = 0; i < tabel.dataLength; i++)
    {
        if (strstr(tabel.data[i].value, data) == NULL)
        {
            printf("Palavra: %s\n", tabel.data[i].value);
            strcpy(tabelData[j].value, tabel.data[i].value);
            j++;
        }
    }

    tabel.data = tabelData;
    tabel.dataLength -= 1;
    
    return tabel;
}