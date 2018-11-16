#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char erase[60];
    char str[100];
    printf("Qual tabela deseja que seja apagada? ");
    scanf("%s", &erase);
    strcat(str, "\n");
    FILE *Erase = fopen("Tabels.txt", "r+");
    fseek(Erase, 0, SEEK_SET);
    while(fgets(str, sizeof str, Erase) != NULL)
    {
        if(strcmp(str, erase) == 0){
            
        }
        else{
            fprintf(Erase, str);
        }
    }
    fclose(Erase);
    return 0;
}