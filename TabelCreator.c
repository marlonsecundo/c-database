#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct column{
    char name [60];
    int type;
}Column;
typedef struct tabel{
    char primary [60];
    Column columns[20];
    char name [60];
}Tabel;
int main(){
    
}