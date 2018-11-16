#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DefineTabel.c"
#include "GetTabel.c"
#include "InsertData.c"
#include "TabelCreator.c"

void main()
{

    char name[50];
    printf("-- Informe a Tabela a Ser Criada --\n");

    printf("Digite o nome da tabela: ");
    scanf("%s", name);

    Tabel tabel = readTabel(name);

    insertData(tabel);
}



