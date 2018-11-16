#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deleteTabel()
{
    char erase[100];
    printf("Qual tabela deletar?\n");
    scanf("%s", &erase);
    char str[100];
    
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
    fclose(Erase);
    fclose(Aux);
    
    FILE *Done = fopen("Tabels", "w+");
    FILE *A = fopen("Help", "r");

    fseek(A, 0, SEEK_SET);
    while (fgets(str, sizeof str, A) != NULL)
    {
        fprintf(Done, str);
    }
    fclose(A);

    remove("Help");
    remove(erase);

    fclose(Done);
}