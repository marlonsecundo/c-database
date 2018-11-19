#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DefineTabel.c"
#include "GetTabel.c"
#include "InsertData.c"
#include "TabelCreator.c"
#include "ListTabels.c"

void main()
{
    int x=1;
    while(x>0 && x<=4)
    {
        printf("-- Informe o que deseja fazer --\n");
        printf("1 - Criar uma tabela\n");
        printf("2 - Listar todas as tabelas\n");
        printf("3 - Inserir uma nova linha em uma tabela\n");
        printf("4 - Mostrar os dados de uma tabela\n");
        printf("Outro valor - Encerrar o programa\n");
        scanf("%d", &x);
        switch(x)
        {
            case 1:
            
                createTabel();
                break;
            
            case 2:
            
                listTabels();
                break;
            
        }
    }
}



