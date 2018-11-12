#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct column
{
    char name[60];
    int type;
} Column;

typedef struct tabel
{
    int primary;
    Column *columns;
    char name[60];
} Tabel;

typedef struct data
{
    char value[100];
} Data;

int createTabel();

int main()
{
    createTabel();
}

int createTabel()
{
    Tabel newTabel;
    int colCount = 0;
    int i = 0;

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

    printf("Nome da tabela: %s\n", newTabel.name);

    printf("Qual o numero de coluna de chave primaria?\n");
    scanf("%d", &newTabel.primary);

    strcat(newTabel.name, ".txt");
    FILE *NewTabel = fopen(newTabel.name, "w");

    if (NewTabel == NULL)
    {
        printf("Erro no arquivo!\n");
    }

    fprintf(NewTabel, "Colunas [ \n");
    for (i = 0; i < colCount; i++)
    {
        fprintf(NewTabel, "{ Name:%s Type:%d }\n", newTabel.columns[i].name, newTabel.columns[i].type);
    }
    fprintf(NewTabel, "]\n");
    fprintf(NewTabel, "Chave Primaria:%d\n", newTabel.primary);
    FILE *Tabels = fopen("Tabels.txt", "a+");
    fprintf(Tabels, "%s\n", newTabel.name);

    fclose(Tabels);
    fclose(NewTabel);
    return 0;
}
