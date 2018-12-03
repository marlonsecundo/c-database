#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CreateTabel()
{
    setbuf(stdin, NULL);

    Tabel newTabel;
    char primary[100] = "";
    int i = 0;
    char err = 0;

    printf("\n-- Informe a Tabela a Ser Criada --\n");

    printf("Digite o nome da tabela: ");
    scanf("%s", &newTabel.name);

    printf("Digite o numero de colunas: ");

    if (scanf("%d%c", &newTabel.colLength, &err) != 2 || err != '\n')
    {
        system("cls");
        printf("\nInsira um número inteiro\n\n");
        setbuf(stdin, NULL);
        return;
    }
    err = 0;

    if (newTabel.colLength <= 0)
    {
        system("cls");
        printf("\nDigite pelo o menos 1 coluna\n");
        return;
    }

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

        if (scanf("%d%c", &colType, &err) != 2 || err != '\n')
        {
            system("cls");
            printf("\nHaha nao bugou\n\n");
            printf("\nInsira um número inteiro\n");
            setbuf(stdin, NULL);
            return;
        }
        err = 0;

        strcpy(newTabel.columns[i].name, colName);

        newTabel.columns[i].type = colType;
    }

    for (int i = 0; i < newTabel.colLength; i++)
    {
        if (newTabel.columns[i].type == 1)
        {
            break;
        }

        if (i + 1 == newTabel.colLength)
        {
            system("cls");
            printf("Crie um tabela com pelo menos uma coluna candidata a chave primaria\n");
            return;
        }
    }

    int p = 0;
    do
    {
        printf("Qual o nome da coluna de chave primaria?\n");
        scanf("%s", primary);

        int value = 0;
        int k = -1;

        for (value = 0; value < newTabel.colLength; value++)
        {
            if (strcmp(primary, newTabel.columns[value].name) == 0)
            {
                k = 0;
                break;
            }
        }

        if (k == -1)
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
