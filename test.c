#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char nome[100] = "{ nome:marlon matricula:111 }\n";
    char search[100] = "matricula";
    char search1[100] = "matricula:%s";
    char chars[100] = "";

    char start[100] = "";
    char end[100] = "";
    char *value = NULL;

    value = strstr(nome, search);

    sscanf(value, search1, end);

    return 0;
}