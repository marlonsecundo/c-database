#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertNewData()
{
    printf("-- Inserção de Dados --\n");
    char name[50];

    printf("Digite o nome da tabela: ");
    scanf("%s", name);

    FILE *fileTabel = fopen(name, "a+");
    char string[100];

    printf("Insira os dados correspondentes em uma linha separado por espaço:\n");
}

