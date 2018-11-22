#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DefineTabel.c"
#include "GetTabel.c"
#include "InsertData.c"
#include "CreateTabel.c"
#include "ListTabels.c"
#include "ReadData.c"
#include "SetTabel.c"

int main()
{
    int x = 1;
    Tabel tabel;
    while (x > 0 && x <= 4)
    {
        printf("-- Informe o que deseja fazer --\n");
        printf("1 - Criar uma tabela\n");
        printf("2 - Listar todas as tabelas\n");
        printf("3 - Inserir uma nova linha em uma tabela\n");
        printf("4 - Mostrar os dados de uma tabela\n");
        printf("Outro valor - Encerrar o programa\n");
        scanf("%d", &x);

        
        switch (x)
        {
        case 1:
            createTabel();
            break;
        case 2:
            listTabels();
            break;
        case 3:
            tabel = GetTabel();
            tabel = insertData(tabel);
            SetTabel(tabel);
            break;
        case 4:
            readData();
            break;
        default:
            break;
        }
    }

    return 0;
}
