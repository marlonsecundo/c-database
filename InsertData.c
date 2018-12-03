#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Tabel InsertData(Tabel tabel)
{
    char err = 0;
    int k = 0;

    float f = 0;
    double d = 0;
    int l = 0;
    char verify[100] = "";

    Tabel errTabel = {};

    if (tabel.colLength == 0)
    {
        return tabel;
    }

    printf("Colunas a serem preenchidas:\n");

    char type[50] = "";
    char data[300] = "";

    char value[50] = "";
    char pkValue[100] = "";

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
        case 3:
            sscanf("Double", "%s", type);
        }

        printf("Coluna: %s Tipo: %s \n", tabel.columns[i].name, type);
        printf("Digite o valor:");
        scanf("%s", value);

        strcpy(verify, value);
        strcat(verify, "\n");
        // verificação de  tipos
        switch (tabel.columns[i].type)
        {
        case 1:
            if (sscanf(verify, "%d%c", &l, &err) != 2 || err != '\n')
                k = 1;
            break;
        case 2:
            if (sscanf(verify, "%f%c", &f, &err) != 2 || err != '\n')
                k = 1;
            break;
        case 3:
            if (sscanf(verify, "%lf%c", &d, &err) != 2 || err != '\n')
                k = 1;
        }

        err = 0;

        if (k == 1)
        {
            system("cls");
            setbuf(stdin, NULL);
            return errTabel;
        }

        if (i == tabel.primary)
            strcpy(pkValue, value);

        strcat(data, tabel.columns[i].name);
        strcat(data, ":");
        strcat(data, value);
    }

    strcat(data, " }\n");

    // Verificação de PK
    char *search = NULL;
    char scanValue[100] = "";
    char searchValue[100] = "";
    char colName[100] = "";

    strcat(colName, tabel.columns[tabel.primary].name);
    strcat(colName, ":");

    strcat(scanValue, colName);
    strcat(scanValue, "%s");

    for (int i = 0; i < tabel.dataLength; i++)
    {
        search = strstr(tabel.data[i].value, colName);
        sscanf(search, scanValue, searchValue);

        if (strcmp(searchValue, pkValue) == 0)
        {
            printf("\nErro:A chave primaria ja existe\n\n");
            return tabel;
        }
    }

    tabel.dataLength += 1;

    Data *dataAux = (Data *)malloc(tabel.dataLength * sizeof(Data));

    for (int i = 0; i < tabel.dataLength - 1; i++)
    {
        dataAux[i] = tabel.data[i];
    }

    strcpy(dataAux[tabel.dataLength - 1].value, data);

    tabel.data = dataAux;

    system("cls");
    printf("Dados inseridos\n\n");

    return tabel;
}