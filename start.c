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
    char term;
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
        printf("7 - Deletar uma tabela\n");
        printf("-- Outro valor - Encerrar o programa --\n");
        printf("----------------------------------\n");

        if (scanf("%d%c", &x, &term) != 2 || term != '\n')
        {
            system("cls");
            printf("\nInsira um numero\n");
            x = 1;
            setbuf(stdin, NULL);
            continue;
        }

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
            printf("\nPrograma encerrado\n");
            break;
        }
    }

    return 0;
}
