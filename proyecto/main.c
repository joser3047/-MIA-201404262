#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char comando[1000];

void main()
{
    int ctokens=1;
    int tamano=0;
    system("clear");
    scanf(" %[^\n]s", comando);
    char *token = strtok(comando, " ");
    char *tokens = strtok(NULL, " ");
    if (strcasecmp(token, "mkdisk") == 0) {
    while(tokens != NULL){
    char *comand = strtok(tokens, "::");
    if(strcasecmp(comand, "-size") == 0){
    comand = strtok(NULL, "::");
    printf("%s", comand);
    }
    if(strcasecmp(comand, "+unit") == 0){
    comand = strtok(NULL, "::");
    printf("%s", comand);
    }
    if(strcasecmp(comand, "-path") == 0){
    comand = strtok(NULL, "::");
    printf("%s", comand);
    }
    }
    }
}
