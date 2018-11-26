#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ReadData()
{
    char tabel[60];
    printf("Digite o nome da tabela: ");
    scanf("%s", &tabel);

    FILE *Tabel = fopen(tabel, "r");

    char read[100];

    while (fgets(read, sizeof read, Tabel) != NULL)
    {
        if (strcmp(read, "Data\n") == 0)
        {
            while (fgets(read, sizeof read, Tabel) != NULL)
            {
                printf(read);
            }
        }
    }

    fclose(Tabel);

    printf("\n\n");

    setbuf(stdin, NULL);
}