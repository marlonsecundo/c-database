#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ReadData()
{
    system("cls");

    char tabel[60];
    printf("Digite o nome da tabela: ");
    scanf("%s", &tabel);

    FILE *Tabel = fopen(tabel, "r");

    char read[100];

    int i = -1;

    while (fgets(read, sizeof read, Tabel) != NULL)
    {
        if (strcmp(read, "Data\n") == 0)
        {
            i = 1;
            while (fgets(read, sizeof read, Tabel) != NULL)
            {
                printf(read);
            }
        }
    }

    if (i == -1)
    {
        printf("Digite uma tabela valida\n");
    }

    fclose(Tabel);

    printf("\n\n");

    setbuf(stdin, NULL);
}