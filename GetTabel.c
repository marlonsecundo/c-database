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

    char string[100] = "";

    FILE *tabels = fopen("Tabels", "r");

    int i = 0;

    Tabel tabel = {};

    char value[100] = "";
    while (fgets(string, sizeof string, tabels) != NULL)
    {
        i++;
        strcpy(value, tabelName);
        strcat(value, "\n");
        if (strcmp(string, value) == 0)
        {
            i = -1;
            break;
        }
    }

    if (i == 0 || i != -1)
    {
        return tabel;
    }

    FILE *fileTabel = fopen(tabelName, "r");

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

    tabel.columns = NULL;
    Column *colAux = NULL;

    while (fgets(string, sizeof string, fileTabel) != NULL)
    {
        if (strcmp(string, "Colunas [\n") == 0)
            continue;
        if (strcmp(string, "]\n") == 0)
            break;

        sscanf(string, "{ Name:%s Type:%d }", name, &type);

        colAux = (Column *)malloc((i + 1) * sizeof(Column));

        for (int j = 0; j < i; j++)
            colAux[j] = tabel.columns[j];

        strcpy(colAux[i].name, name);
        colAux[i].type = type;

        tabel.columns = colAux;

        i++;

        colAux = NULL;
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
            fgets(string, sizeof string, fileTabel);

            fgets(string, sizeof string, fileTabel);

            sscanf(string, "Chave Primaria:%d", &tabel.primary);

            break;
        }
    }

    return tabel;
}

Tabel setData(FILE *fileTabel, Tabel tabel)
{
    char string[100] = "";

    fseek(fileTabel, 0, SEEK_SET);

    int i = 0;
    int exec = 0;

    tabel.data = NULL;
    Data *dataAux = NULL;

    while (fgets(string, sizeof string, fileTabel) != NULL)
    {
        if (strcmp(string, "Data\n") == 0)
        {
            exec = 1;
            continue;
        }

        if (exec == 1)
        {
            dataAux = (Data *)malloc((i + 1) * sizeof(Data));

            for (int j = 0; j < i; j++)
                dataAux[j] = tabel.data[j];

            strcpy(dataAux[i].value, string);

            tabel.data = dataAux;

            i++;

            dataAux = NULL;
        }
    }

    if (i > 0)
        tabel.dataLength = i;

    return tabel;
}
