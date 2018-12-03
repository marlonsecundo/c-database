#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SearchData(Tabel tabel)
{
    system("cls");

    if (tabel.colLength == 0)
    {
        printf("Digite uma tabela valida\n");
        return;
    }
    int j = 0;
    int var = 1;
    char colname[100];
    int valueInt = 0;
    char *aux;
    char *aux2;
    int x;
    float valueFlo = 0;
    double valueDou = 0;
    char valueStr[100] = "";
    double searchDou = 0;
    float searchFlo = 0;
    char searchStr[100] = "";
    int searchValue = 0;
    int i;
    char search[200] = "";

    char *scanValue = NULL;

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
    strcat(colname, ":");
    if (var >= 1 && var <= 6)
    {
        if (tabel.columns[i].type == 1)
        {
            printf("Digite o valor para iniciar a pesquisa: ");
            setbuf(stdin, NULL);
            scanf("%d", &valueInt);

            strcat(search, colname);
            strcat(search, "%d");
        }
        else if (tabel.columns[i].type == 0)
        {
            printf("Digite a palavra: ");
            setbuf(stdin, NULL);
            scanf("%s", &valueStr);

            strcat(search, colname);
            strcat(search, "%s");
        }
        else if (tabel.columns[i].type == 2)
        {
            printf("Digite o valor para iniciar a pesquisa: ");
            setbuf(stdin, NULL);
            scanf("%f", &valueFlo);

            strcat(search, colname);
            strcat(search, "%f");
        }
        else if (tabel.columns[i].type == 3)
        {
            printf("Digite o valor para iniciar a pesquisa: ");
            setbuf(stdin, NULL);
            scanf("%lf", &valueDou);

            strcat(search, colname);
            strcat(search, "%lf");
        }
    }
    switch (var)
    {
    case 1:
        if (tabel.columns[i].type == 1)
        {
            for (i = 0; i < tabel.dataLength; i++)
            {
                scanValue = strstr(tabel.data[i].value, colname);
                sscanf(scanValue, search, &searchValue);

                if (searchValue > valueInt)
                {
                    printf(tabel.data[i].value);
                }
                else
                {
                    j++;
                    if (j == tabel.dataLength)
                    {
                        printf("Nenhum numero encontrado\n\n");
                    }
                }
            }
        }
        else if (tabel.columns[i].type == 0)
        {
            for (i = 0; i < tabel.dataLength; i++)
            {
                scanValue = strstr(tabel.data[i].value, colname);
                sscanf(scanValue, search, searchStr);

                if (searchStr[0] > valueStr[0])
                {
                    printf(tabel.data[i].value);
                }
                else
                {
                    j++;
                    if (j == tabel.dataLength)
                    {
                        printf("Nenhum nome encontrado\n\n");
                    }
                }
            }
        }
        else if (tabel.columns[i].type == 2)
        {
            for (i = 0; i < tabel.dataLength; i++)
            {
                scanValue = strstr(tabel.data[i].value, colname);
                sscanf(scanValue, search, &searchFlo);

                if (searchFlo > valueFlo)
                {
                    printf(tabel.data[i].value);
                }
                else
                {
                    j++;
                    if (j == tabel.dataLength)
                    {
                        printf("Nenhum numero encontrado\n\n");
                    }
                }
            }
        }
        else if (tabel.columns[i].type == 3)
        {
            for (i = 0; i < tabel.dataLength; i++)
            {
                scanValue = strstr(tabel.data[i].value, colname);
                sscanf(scanValue, search, &searchDou);

                if (searchDou > valueDou)
                {
                    printf(tabel.data[i].value);
                }
                else
                {
                    j++;
                    if (j == tabel.dataLength)
                    {
                        printf("Nenhum numero encontrado\n\n");
                    }
                }
            }
        }
        break;
    case 2:
        if (tabel.columns[i].type == 1)
        {
            for (i = 0; i < tabel.dataLength; i++)
            {
                scanValue = strstr(tabel.data[i].value, colname);
                sscanf(scanValue, search, &searchValue);

                if (searchValue >= valueInt)
                {
                    printf(tabel.data[i].value);
                }
                else
                {
                    j++;
                    if (j == tabel.dataLength)
                    {
                        printf("Nenhum numero encontrado\n\n");
                    }
                }
            }
        }
        else if (tabel.columns[i].type == 0)
        {
            for (i = 0; i < tabel.dataLength; i++)
            {
                scanValue = strstr(tabel.data[i].value, colname);
                sscanf(scanValue, search, searchStr);

                if (searchStr[0] >= valueStr[0])
                {
                    printf(tabel.data[i].value);
                }
                else
                {
                    j++;
                    if (j == tabel.dataLength)
                    {
                        printf("Nenhum nome encontrado\n\n");
                    }
                }
            }
        }
        else if (tabel.columns[i].type == 2)
        {
            for (i = 0; i < tabel.dataLength; i++)
            {
                scanValue = strstr(tabel.data[i].value, colname);
                sscanf(scanValue, search, &searchFlo);
                if (searchFlo >= valueFlo)
                {
                    printf(tabel.data[i].value);
                }
                else
                {
                    j++;
                    if (j == tabel.dataLength)
                    {
                        printf("Nenhum numero encontrado\n\n");
                    }
                }
            }
        }
        else if (tabel.columns[i].type == 3)
        {
            for (i = 0; i < tabel.dataLength; i++)
            {
                scanValue = strstr(tabel.data[i].value, colname);
                sscanf(scanValue, search, &searchDou);

                if (searchDou >= valueDou)
                {
                    printf(tabel.data[i].value);
                }
                else
                {
                    j++;
                    if (j == tabel.dataLength)
                    {
                        printf("Nenhum numero encontrado\n\n");
                    }
                }
            }
        }
        break;
    case 3:
        if (tabel.columns[i].type == 1)
        {
            for (i = 0; i < tabel.dataLength; i++)
            {
                scanValue = strstr(tabel.data[i].value, colname);
                sscanf(scanValue, search, &searchValue);
                if (searchValue == valueInt)
                {
                    printf(tabel.data[i].value);
                }
                else
                {
                    
                    j++;
                    if (j == tabel.dataLength)
                    {
                        printf("Nenhum numero encontrado\n\n");
                    }
                }
            }
        }
        else if (tabel.columns[i].type == 0)
        {
            for (i = 0; i < tabel.dataLength; i++)
            {
                scanValue = strstr(tabel.data[i].value, colname);
                sscanf(scanValue, search, searchStr);
                if (strcmp(searchStr, valueStr) == 0)
                {
                    printf(tabel.data[i].value);
                }
                else
                {
                    j++;
                    if (j == tabel.dataLength)
                    {
                        printf("Nenhum nome encontrado\n\n");
                    }
                }
            }
        }
        else if (tabel.columns[i].type == 2)
        {
            for (i = 0; i < tabel.dataLength; i++)
            {
                scanValue = strstr(tabel.data[i].value, colname);
                sscanf(scanValue, search, &searchFlo);
                if (searchFlo == valueFlo)
                {
                    printf(tabel.data[i].value);
                }
                else
                {
                    j++;
                    if (j == tabel.dataLength)
                    {
                        printf("Nenhum numero encontrado\n\n");
                    }
                }
            }
        }
        else if (tabel.columns[i].type == 3)
        {
            for (i = 0; i < tabel.dataLength; i++)
            {
                scanValue = strstr(tabel.data[i].value, colname);
                sscanf(scanValue, search, &searchDou);

                if (searchDou == valueDou)
                {
                    printf(tabel.data[i].value);
                }
                else
                {
                    j++;
                    if (j == tabel.dataLength)
                    {
                        printf("Nenhum numero encontrado\n\n");
                    }
                }
            }
        }
        break;
    case 4:
        if (tabel.columns[i].type == 1)
        {
            for (i = 0; i < tabel.dataLength; i++)
            {
                scanValue = strstr(tabel.data[i].value, colname);
                sscanf(scanValue, search, &searchValue);
                if (searchValue < valueInt)
                {
                    printf(tabel.data[i].value);
                }
                else
                {
                    j++;
                    if (j == tabel.dataLength)
                    {
                        printf("Nenhum numero encontrado\n\n");
                    }
                }
            }
        }
        else if (tabel.columns[i].type == 0)
        {
            for (i = 0; i < tabel.dataLength; i++)
            {
                scanValue = strstr(tabel.data[i].value, colname);
                sscanf(scanValue, search, searchStr);
                if (searchStr[0] < valueStr[0])
                {
                    printf(tabel.data[i].value);
                }
                else
                {
                    j++;
                    if (j == tabel.dataLength)
                    {
                        printf("Nenhum nome encontrado\n\n");
                    }
                }
            }
        }
        else if (tabel.columns[i].type == 2)
        {
            for (i = 0; i < tabel.dataLength; i++)
            {
                scanValue = strstr(tabel.data[i].value, colname);
                sscanf(scanValue, search, &searchFlo);
                if (searchFlo < valueFlo)
                {
                    printf(tabel.data[i].value);
                }
                else
                {
                    j++;
                    if (j == tabel.dataLength)
                    {
                        printf("Nenhum numero encontrado\n\n");
                    }
                }
            }
        }
        else if (tabel.columns[i].type == 3)
        {
            for (i = 0; i < tabel.dataLength; i++)
            {
                scanValue = strstr(tabel.data[i].value, colname);
                sscanf(scanValue, search, &searchDou);

                if (searchDou < valueDou)
                {
                    printf(tabel.data[i].value);
                }
                else
                {
                    j++;
                    if (j == tabel.dataLength)
                    {
                        printf("Nenhum numero encontrado\n\n");
                    }
                }
            }
        }
        break;
    case 5:
        if (tabel.columns[i].type == 1)
        {
            for (i = 0; i < tabel.dataLength; i++)
            {
                scanValue = strstr(tabel.data[i].value, colname);
                sscanf(scanValue, search, &searchValue);
                if (searchValue <= valueInt)
                {
                    printf(tabel.data[i].value);
                }
                else
                {
                    j++;
                    if (j == tabel.dataLength)
                    {
                        printf("Nenhum numero encontrado\n\n");
                    }
                }
            }
        }
        else if (tabel.columns[i].type == 0)
        {
            for (i = 0; i < tabel.dataLength; i++)
            {
                scanValue = strstr(tabel.data[i].value, colname);
                sscanf(scanValue, search, searchStr);
                if (searchStr[0] <= valueStr[0])
                {
                    printf(tabel.data[i].value);
                }
                else
                {
                    j++;
                    if (j == tabel.dataLength)
                    {
                        printf("Nenhum nome encontrado\n\n");
                    }
                }
            }
        }
        else if (tabel.columns[i].type == 2)
        {
            for (i = 0; i < tabel.dataLength; i++)
            {
                scanValue = strstr(tabel.data[i].value, colname);
                sscanf(scanValue, search, &searchFlo);
                if (searchFlo <= valueFlo)
                {
                    printf(tabel.data[i].value);
                }
                else
                {
                    j++;
                    if (j == tabel.dataLength)
                    {
                        printf("Nenhum numero encontrado\n\n");
                    }
                }
            }
        }
        else if (tabel.columns[i].type == 3)
        {
            for (i = 0; i < tabel.dataLength; i++)
            {
                scanValue = strstr(tabel.data[i].value, colname);
                sscanf(scanValue, search, &searchDou);

                if (searchDou <= valueDou)
                {
                    printf(tabel.data[i].value);
                }
                else
                {
                    j++;
                    if (j == tabel.dataLength)
                    {
                        printf("Nenhum numero encontrado\n\n");
                    }
                }
            }
        }
        break;
    case 6:
        if (tabel.columns[i].type == 1)
        {
            for (i = 0; i < tabel.dataLength; i++)
            {
                scanValue = strstr(tabel.data[i].value, colname);
                sscanf(scanValue, search, &searchValue);
                if (searchValue > valueInt - 5 && searchValue < valueInt + 5)
                {
                    printf(tabel.data[i].value);
                }
                else
                {
                    j++;
                    if (j == tabel.dataLength)
                    {
                        printf("Nenhum numero encontrado\n\n");
                    }
                }
            }
        }
        else if (tabel.columns[i].type == 0)
        {
            for (i = 0; i < tabel.dataLength; i++)
            {
                aux = strstr(tabel.data[i].value, colname);
                if (aux != NULL)
                {
                    sscanf(aux, search, searchStr);
                    aux2 = strstr(searchStr, valueStr);

                    if (aux2 != NULL)
                    {
                        x = strlen(aux2);
                        if (x > 0)
                        {
                            printf(tabel.data[i].value);
                        }
                    }
                    else
                    {
                        j++;
                        if (j == tabel.dataLength)
                        {
                            printf("Nenhum nome encontrado\n\n");
                        }
                    }
                }
            }
        }
        else if (tabel.columns[i].type == 2)
        {
            for (i = 0; i < tabel.dataLength; i++)
            {
                scanValue = strstr(tabel.data[i].value, colname);
                sscanf(scanValue, search, &searchFlo);
                if (searchFlo > valueFlo - 5 && searchFlo < valueFlo + 5)
                {
                    printf(tabel.data[i].value);
                }
                else
                {
                    j++;
                    if (j == tabel.dataLength)
                    {
                        printf("Nenhum numero encontrado\n\n");
                    }
                }
            }
        }
        else if (tabel.columns[i].type == 3)
        {
            for (i = 0; i < tabel.dataLength; i++)
            {
                scanValue = strstr(tabel.data[i].value, colname);
                sscanf(scanValue, search, &searchDou);
                if (searchDou > valueDou - 5 && searchDou < valueDou + 5)
                {
                    printf(tabel.data[i].value);
                }
                else
                {
                    j++;
                    if (j == tabel.dataLength)
                    {
                        printf("Nenhum numero encontrado\n\n");
                    }
                }
            }
        }
        break;
    default:
        printf("\nPesquisa encerrada\n\n");
        break;
    }
}