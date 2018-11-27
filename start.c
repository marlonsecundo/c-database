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
#include "DeleteData.c"
#include "SearchData.c"
#include "DeleteTabel.c"

int main()
{
    int x = 1;
    Tabel tabel;
    while (x > 0 && x <= 7)
    {
        printf("-- Informe o que deseja fazer --\n");
        printf("1 - Criar uma tabela\n");
        printf("2 - Listar todas as tabelas\n");
        printf("3 - Inserir uma nova linha em uma tabela\n");
        printf("4 - Mostrar os dados de uma tabela\n");
        printf("5 - Apagar uma linha\n");
        printf("6 - Pesquisar na tabela\n");
        printf("7 - Deletar uma tabela");
        printf("-- Outro valor - Encerrar o programa --\n");
        scanf("%d", &x);
        printf("----------------------------------\n");

        switch (x)
        {
        case 1:
            CreateTabel();
            break;
        case 2:
            ListTabels();
            break;
        case 3:
            tabel = GetTabel();
            tabel = InsertData(tabel);
            SetTabel(tabel);
            break;
        case 4:
            ReadData();
            break;
        case 5:
            tabel = GetTabel();
            tabel = DeleteData(tabel);
            SetTabel(tabel);
            break;
        case 6:
            tabel = GetTabel();
            SearchData(tabel);
            break;
        case 7:
            DeleteTabel();
            break;
        default:
            break;
        }
    }

    return 0;
}
