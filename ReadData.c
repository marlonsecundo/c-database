#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char tabel[60];
    printf("Digite o nome da tabela: ");
    scanf("%s", &tabel);
    FILE *Tabel = fopen(tabel, "r");
    if (Tabel == NULL)
    {
        printf("Erro no arquivo!");
        return -1;
    }
    char read[100];
    int i;
    while(fgets(read, sizeof read, Tabel)!=NULL)
    {
        if(strcmp(read, "Data\n") == 0)
        {
            while(fgets(read, sizeof read, Tabel)!=NULL)
            {
                printf(read);
            }
        }
    }
    fclose(Tabel);
    return 0;    
}