#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Tabel InsertData(Tabel tabel)
{
    printf("Colunas a serem preenchidas:\n");

    char type[50] = "";
    char data[300] = "";

    char value[50] = "";

    strcat(data, "{");

    for (int i = 0; i < tabel.colLength; i++)
    {
        strcat(data, " ");

        switch (tabel.columns[i].type)
        {
        case 0:
            sscanf("String", "%s", type);
            break;
        case 1:
            sscanf("Int", "%s", type);
            break;
        case 2:
            sscanf("Float", "%s", type);
            break;
        case 4:
            sscanf("Double", "%s", type);
        }

        printf("Coluna: %s Tipo: %s \n", tabel.columns[i].name, type);
        printf("Digite o valor:");
        scanf("%s", value);

        strcat(data, tabel.columns[i].name);
        strcat(data, ":");
        strcat(data, value);
    }

    strcat(data, " }\n");

    tabel.dataLength += 1;

    Data *dataAux = (Data *)malloc(tabel.dataLength * sizeof(Data));

    for (int i = 0; i < tabel.dataLength - 1; i++)
    {
        dataAux[i] = tabel.data[i];
    }

    strcpy(dataAux[tabel.dataLength - 1].value, data);

    tabel.data = dataAux;

    printf("\n\n");

    return tabel;
}