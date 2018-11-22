#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Tabel insertData(Tabel tabel)
{
    printf("Colunas a serem preenchidas:\n");
 
    char type[20];

    for (int i = 0; i < tabel.colLength; i++)
    {
        switch (tabel.columns[i].type)
        {
        case 0:
            sscanf("String", "%s", type);
            break;
        case 1:
            sscanf("Int", "%s", type);
            break;
        case 2:
            sscanf("Float", "%s", type);
            break;
        case 4:
            sscanf("Double", "%s", type);
        }

        printf("Coluna: %s Tipo: %s \n", tabel.columns[i].name, type);
    }

    char string[500];
    char data[600];
    strcpy(data, "");

    printf("\nDigite os dados separados por espaco:\n");
    setbuf(stdin, NULL);
    scanf("%[^\n]", string);

    strcat(data, "{ ");
    strcat(data, string);
    strcat(data, " }\n");

    tabel.dataLength += 1;
    tabel.data = (Data *)realloc(tabel.data, tabel.dataLength * sizeof(Data *));

    strcpy(tabel.data[tabel.dataLength - 1].value, data);

    printf("\n\n");
    
    return tabel;
}