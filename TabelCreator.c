#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DefineTabel.c"

int createTabel()
{
    Tabel newTabel;
    int colCount = 0;
    int i = 0;

    // -- Criação da Tabela --

    printf("-- Informe a Tabela a Ser Criada --\n");

    printf("Digite o nome da tabela: ");
    scanf("%s", &newTabel.name);
    printf("Digite o numero de colunas: ");
    scanf("%d", &colCount);
    printf("\n");

    printf("-- Informe os Dados das Colunas --\n");

    newTabel.columns = (Column *)malloc(colCount * sizeof(Column));

    for (i = 0; i < colCount; i++)
    {
        char colName[60];
        int colType = 0;

        printf("Digite o nome da coluna: ");
        scanf("%s", &colName);

        printf("Digite o tipo de dado da coluna (0:Char 1:Int 2:Float 3:Double): ");
        scanf("%d", &colType);
        printf("\n");

        strcpy(newTabel.columns[i].name, colName);

        newTabel.columns[i].type = colType;
    }

    printf("Qual o numero de coluna de chave primaria?\n");
    scanf("%d", &newTabel.primary);

    // -- Salvamento em Arquivo --

    FILE *fileTabel = fopen(newTabel.name, "w");

    fprintf(fileTabel, "Colunas [\n");

    for (i = 0; i < colCount; i++)
    {
        fprintf(fileTabel, "{ Name:%s Type:%d }\n", newTabel.columns[i].name, newTabel.columns[i].type);
    }
    fprintf(fileTabel, "]\n\n");

    fprintf(fileTabel, "Chave Primaria:%d\n\n", newTabel.primary);

    fprintf(fileTabel, "Data\n");

    // -- Salvamento no Arquivo Tabels
    FILE *Tabels = fopen("Tabels", "a+");
    fprintf(Tabels, "%s\n", newTabel.name);

    fclose(Tabels);
    fclose(fileTabel);
    return 0;
}


