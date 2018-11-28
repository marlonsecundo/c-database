#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DeleteTabel()
{
    char erase[100];
    char erase1[100];
    printf("Qual tabela deseja deletar?\n");
    scanf("%s", &erase);
    char str[100];
    strcpy(erase1, erase);
    strcat(erase, "\n");
    FILE *Erase = fopen("Tabels", "r");
    FILE *Aux = fopen("Help", "w");
    fseek(Erase, 0, SEEK_SET);
    while (fgets(str, sizeof str, Erase) != NULL)
    {
        if (strcmp(str, erase) == 0)
        {
        }
        else
        {
            fprintf(Aux, str);
        }
    }
    fflush(Erase);
    fflush(Aux);

    fclose(Erase);
    fclose(Aux);

    FILE *Done = fopen("Tabels", "w+");
    FILE *A = fopen("Help", "r");

    fseek(A, 0, SEEK_SET);
    while (fgets(str, sizeof str, A) != NULL)
    {
        fprintf(Done, str);
    }

    fflush(A);
    fclose(A);

    remove("Help");
    remove(erase1);

    fflush(Done);
    fclose(Done);

    printf("-----Tabela apagada com sucesso-----\n\n");
}