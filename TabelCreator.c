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
    char primary[1];
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

    for (i = 0; i < colCount; i++)
    {
        printf("Coluna %s \n", newTabel.columns[i].name);
        printf("Tipo de Dado: %d", newTabel.columns[i].type);
        printf("\n");
    }

    return 0;
}
