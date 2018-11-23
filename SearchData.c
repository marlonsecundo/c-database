#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void searchData(Tabel tabel)
{
    int var = 1;
    char colname[100];
    int i;
    printf("As colunas existentes: \n");
    for(i = 0; i < tabel.colLength; i++)
    {
        printf("%s ", tabel.columns[i].name);
    }
    printf("\nQual coluna deseja iniciar a pesquisa?\n");
    scanf("%s", &colname);

    for (i = 0; i < tabel.colLength; i++)
    {
        if (strcmp(colname,tabel.columns[i].name) == 0)
            break;
    }
    FILE *search = fopen(tabel.name, "r");
    while(var>0 && var<6)
    {
        printf("---- Selecione o estilo de pesquisa ----\n");
        printf("1 - Pesquisar valores maiores que o informado\n");
        printf("2 - Pesquisar valores maiores ou iguais ao informado\n");
        printf("3 - Pesquisar valores iguais ao informado\n");
        printf("4 - Pesquisar valores menores que o informado\n");
        printf("5 - Pesquisar valores menores ou iguais ao informado\n");
        printf("6 - Pesquisar valores proximos ao informado\n");
        printf("Outro valor - Encerrar pesquisa\n");
        scanf("%d", &var);

        switch(var)
        {
            case 1:
                
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                
                break;
            case 6:
                
                break;
            default:
                break;
        }
    }
}