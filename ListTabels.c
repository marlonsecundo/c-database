#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char x[100];
    FILE *Tabels = fopen("Tabels.txt", "r");
    while (fscanf(Tabels, "%s", &x)!=-1)
    {
        printf("%s\n", x);
    }
    fclose(Tabels);
    return 0;
}