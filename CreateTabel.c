#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CreateTabel()
{
    setbuf(stdin, NULL);

    Tabel newTabel;
    char primary[100] = "";
    int i = 0;

    printf("\n-- Informe a Tabela a Ser Criada --\n");

    printf("Digite o nome da tabela: ");
    scanf("%s", &newTabel.name);

    printf("Digite o numero de colunas: ");
    scanf("%d", &newTabel.colLength);
    printf("\n");

    printf("-- Informe os Dados das Colunas --\n");

    newTabel.columns = (Column *)malloc(newTabel.colLength * sizeof(Column));
    newTabel.data = (Data *)malloc(0 * sizeof(Data));

    for (i = 0; i < newTabel.colLength; i++)
    {
        char colName[60];
        int colType = 0;

        printf("Digite o nome da coluna: ");
        scanf("%s", &colName);

        if (strlen(colName) <= 0)
        {
            printf("\nErro: Digite algum nome para a tabela \n");
            return;
        }

        printf("Digite o tipo de dado da coluna (0:Char 1:Int 2:Float 3:Double): ");
        scanf("%d", &colType);

        strcpy(newTabel.columns[i].name, colName);

        newTabel.columns[i].type = colType;
    }

    int p = 0;
    do
    {
        printf("Qual o nome da coluna de chave primaria?\n");
        scanf("%s", primary);

        int value = 0;

        for (value = 0; value < newTabel.colLength; value++)
        {
            if (strcmp(primary, newTabel.columns[value].name) == 0)
                break;
        }

        if (value >= newTabel.colLength)
        {
            printf("\n -- Digite uma coluna existente -- \n");
            continue;
        }

        if (newTabel.columns[value].type != 1)
        {
            printf("\n-- Erro --\n");
            printf("A coluna deve ser do tipo inteira\n");
        }
        else
        {
            newTabel.primary = value;
            p = 1;
        }

    } while (p == 0);

    // -- Salvamento em Arquivo --

    FILE *fileTabel = fopen(newTabel.name, "w");

    fprintf(fileTabel, "Colunas [\n");

    for (i = 0; i < newTabel.colLength; i++)
    {
        fprintf(fileTabel, "{ Name:%s Type:%d }\n", newTabel.columns[i].name, newTabel.columns[i].type);
    }

    fprintf(fileTabel, "]\n\n");

    fprintf(fileTabel, "Chave Primaria:%d\n\n", newTabel.primary);

    fprintf(fileTabel, "Data\n");

    // -- Salvamento no Arquivo Tabels
    FILE *Tabels = fopen("Tabels", "a+");
    fprintf(Tabels, "%s\n", newTabel.name);

    fflush(Tabels);
    fflush(fileTabel);

    fclose(Tabels);
    fclose(fileTabel);
    printf("\n");
}
