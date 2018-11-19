#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertData(Tabel tabel)
{
    printf("Colunas a serem preenchidas:\n");

    char type[20];

    for (int i = 0; i < tabel.length; i++)
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

    printf("\nDigite os dados separados por espaco:\n");


    char string[500];

    setbuf(stdin, NULL);
    scanf("%[^\n]", string);

    char data[500];

    strcat(data, "{ ");
    strcat(data, string);
    strcat(data, " }");

}