#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ListTabels()
{
    system("cls");
    printf("\n-- Tabelas Existentes --\n");
    char x[100];
    FILE *Tabels = fopen("Tabels", "r");

    while (fscanf(Tabels, "%s", &x) != -1)
        printf("%s\n", x);

    fclose(Tabels);

    printf("\n\n");
}
