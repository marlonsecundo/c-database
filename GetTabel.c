#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Tabel setColumns(FILE *fileTabel, Tabel tabel);
Tabel setPrimaryKey(FILE *fileTabel, Tabel tabel);
Tabel setData(FILE *fileTabel, Tabel tabel);

Tabel GetTabel()
{
    char tabelName[50];
    printf("Digite o nome da tabela: ");
    scanf("%s", tabelName);
    printf("\n");

    FILE *fileTabel = fopen(tabelName, "r");
    Tabel tabel = {};

    strcpy(tabel.name, tabelName);

    // Set Columns
    tabel = setColumns(fileTabel, tabel);

    // Set Primary Key
    tabel = setPrimaryKey(fileTabel, tabel);

    // Set Data
    tabel = setData(fileTabel, tabel);

    fclose(fileTabel);

    setbuf(stdin, NULL);

    return tabel;
}

Tabel setColumns(FILE *fileTabel, Tabel tabel)
{
    fseek(fileTabel, 0, SEEK_SET);

    char string[100];
    char name[100];
    int type = 0;

    int i = 0;

    tabel.columns = (Column*) malloc(1 * sizeof(Column));

    while (fgets(string, sizeof string, fileTabel) != NULL)
    {
        if (strcmp(string, "Colunas [\n") == 0)
            continue;
        if (strcmp(string, "]\n") == 0)
            break;

        sscanf(string, "{ Name:%s Type:%d }", name, &type);

        tabel.columns = (Column *)realloc(tabel.columns, i + 1 * sizeof(Column));

        strcpy(tabel.columns[i].name, name);
        tabel.columns[i].type = type;

        i++;
    }

    tabel.colLength = i;

    return tabel;
}

Tabel setPrimaryKey(FILE *fileTabel, Tabel tabel)
{
    char string[100];

    fseek(fileTabel, 0, SEEK_SET);
    while (fgets(string, sizeof string, fileTabel) != NULL)
    {
        if (strcmp(string, "]\n") == 0)
        {
            fgets(string, sizeof string, fileTabel); // Pula o espaço

            fgets(string, sizeof string, fileTabel);

            sscanf(string, "Chave Primaria:%d", &tabel.primary);

            break;
        }
    }

    return tabel;
}

Tabel setData(FILE *fileTabel, Tabel tabel)
{
    char string[100];

    fseek(fileTabel, 0, SEEK_SET);

    int i = 0;
    int exec = 0;
    
    tabel.data = (Data*) malloc(sizeof(Data*));

    while (fgets(string, sizeof string, fileTabel) != NULL)
    {
        if (strcmp(string, "Data\n") == 0)
        {
            exec = 1;
            continue;
        }

        if (exec == 1)
        {
            tabel.data = (Data *)realloc(tabel.data, i + 1 * sizeof(Data));

            strcpy(tabel.data[i].value, string);

            i++;
        }
    }

    if (i > 0)
        tabel.dataLength = i;

    return tabel;
}
