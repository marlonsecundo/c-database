#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SearchData(Tabel tabel)
{
    int var = 1;
    char colname[100];
    int value;
    int searchValue = 0;
    char start[100] = "";
    char end[100] = "";
    int i;
    char search[200] = "";
    printf("As colunas existentes: \n");
    for (i = 0; i < tabel.colLength; i++)
    {
        printf("%s ", tabel.columns[i].name);
    }
    printf("\nQual coluna deseja iniciar a pesquisa?\n");
    scanf("%s", &colname);

    for (i = 0; i < tabel.colLength; i++)
    {
        if (strcmp(colname, tabel.columns[i].name) == 0)
            break;
    }
    FILE *fileSearch = fopen(tabel.name, "r");

    printf("---- Selecione o estilo de pesquisa ----\n");
    printf("1 - Pesquisar valores maiores que o informado\n");
    printf("2 - Pesquisar valores maiores ou iguais ao informado\n");
    printf("3 - Pesquisar valores iguais ao informado\n");
    printf("4 - Pesquisar valores menores que o informado\n");
    printf("5 - Pesquisar valores menores ou iguais ao informado\n");
    printf("6 - Pesquisar valores proximos ao informado\n");
    printf("Outro valor - Encerrar pesquisa\n");
    scanf("%d", &var);

    printf("Digite o valor para a pesquisa: ");
    scanf("%d", &value);

    strcat(search, "%s ");
    strcat(search, colname);
    strcat(search, ":");
    strcat(search, "%d");
    strcat(search, " %s");

    switch (var)
    {
    case 1:
        for (i = 0; i < tabel.dataLength; i++)
        {
            sscanf(tabel.data[i].value, search, start, &searchValue, end);
            if (searchValue > value)
            {
                printf(tabel.data[i].value);
            }
        }
        break;
    case 2:
        for (i = 0; i < tabel.dataLength; i++)
        {
            sscanf(tabel.data[i].value, search, start, &searchValue, end);
            if (searchValue >= value)
            {
                printf(tabel.data[i].value);
            }
        }
        break;
    case 3:
        for (i = 0; i < tabel.dataLength; i++)
        {
            sscanf(tabel.data[i].value, search, start, &searchValue, end);
            if (searchValue == value)
            {
                printf(tabel.data[i].value);
            }
        }
        break;
    case 4:
        for (i = 0; i < tabel.dataLength; i++)
        {
            sscanf(tabel.data[i].value, search, start, &searchValue, end);
            if (searchValue < value)
            {
                printf(tabel.data[i].value);
            }
        }
        break;
    case 5:
        for (i = 0; i < tabel.dataLength; i++)
        {
            sscanf(tabel.data[i].value, search, start, &searchValue, end);
            if (searchValue <= value)
            {
                printf(tabel.data[i].value);
            }
        }
        break;
    case 6:
        for (i = 0; i < tabel.dataLength; i++)
        {
            sscanf(tabel.data[i].value, search, start, &searchValue, end);
            if (searchValue > value - 5 && searchValue < value + 5)
            {
                printf(tabel.data[i].value);
            }
        }
        break;
    default:
        break;
    }
}