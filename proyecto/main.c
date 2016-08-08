#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char comando[];

void main()
{
    int ctokens=1;
    system("clear");
    scanf(" %[^\n]s", comando);
    char *token;
    char *tokens;
    char *size="";    char *unit="";    char *name="";    char *path="";
    char tamano[100]="";    char unidad[2]="";     char nombre[100]="";   char dir[100]="";
    int contador = 0;
    token = strtok(comando, " ");
    if (strcasecmp(token, "mkdisk") == 0) {
    tokens = comando;
    tokens = strtok(NULL, " ");
    if(tokens != NULL){
        size = tokens; contador++;
    } tokens = strtok(NULL, " ");
    if(tokens != NULL){
        unit = tokens; contador++;
    } tokens = strtok(NULL, " ");
    if(tokens != NULL){
        name = tokens; contador++;
    } tokens = strtok(NULL, " ");
    if(tokens != NULL){
        path = tokens; contador++;
    } int cont = 0;
    while(cont < contador){
    if(cont == 0 && strcasecmp(size, "") != 0){
    tokens = strtok(size, "::");
    if(strcasecmp(tokens, "-size") == 0){
    tokens = strtok(NULL, "::");
    strcpy(tamano, tokens);}
    else if(strcasecmp(tokens, "+unit") == 0){
    tokens = strtok(NULL, "::");
    strcpy(unidad, tokens);}
    else if(strcasecmp(tokens, "-path") == 0){
    tokens = strtok(NULL, "::");
    strcpy(dir, tokens);}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, tokens);}
    else{
    tokens = strtok(NULL, "::");
    printf("Error en el comando: %s", tokens);
    }
    }
    else if(cont == 1 && strcasecmp(unit, "") != 0){
    tokens = strtok(unit, "::");
    if(strcasecmp(tokens, "-size") == 0){
    tokens = strtok(NULL, "::");
    strcpy(tamano, tokens);}
    else if(strcasecmp(tokens, "+unit") == 0){
    tokens = strtok(NULL, "::");
    strcpy(unidad, tokens);}
    else if(strcasecmp(tokens, "-path") == 0){
    tokens = strtok(NULL, "::");
    strcpy(dir, tokens);}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, tokens);}
    else{
    tokens = strtok(NULL, "::");
    printf("Error en el comando: %s", tokens);
    }
    }
    else if(cont == 2 && strcasecmp(name, "") != 0){
    tokens = strtok(name, "::");
    if(strcasecmp(tokens, "-size") == 0){
    tokens = strtok(NULL, "::");
    strcpy(tamano, tokens);}
    else if(strcasecmp(tokens, "+unit") == 0){
    tokens = strtok(NULL, "::");
    strcpy(unidad, tokens);}
    else if(strcasecmp(tokens, "-path") == 0){
    tokens = strtok(NULL, "::");
    strcpy(dir, tokens);}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, tokens);}
    else{
    tokens = strtok(NULL, "::");
    printf("Error en el comando: %s", tokens);
    }
    }
    else if(cont == 3 && strcasecmp(path, "") != 0){
    tokens = strtok(path, "::");
    if(strcasecmp(tokens, "-size") == 0){
    tokens = strtok(NULL, "::");
    strcpy(tamano, tokens);}
    else if(strcasecmp(tokens, "+unit") == 0){
    tokens = strtok(NULL, "::");
    strcpy(unidad, tokens);}
    else if(strcasecmp(tokens, "-path") == 0){
    tokens = strtok(NULL, "::");
    strcpy(dir, tokens);}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, tokens);}
    else{
    tokens = strtok(NULL, "::");
    printf("Error en el comando: %s", tokens);
    }
    } cont++;
    }
    printf("El tamaño es: %s\n", tamano);
    printf("El nombre es: %s\n", nombre);
    printf("La Direccion es: %s\n", dir);
    printf("La unidad es: %s\n", unidad);
    if((strcasecmp(tamano,"")!=0)&&(strcasecmp(dir,"")!=0)&&(strcasecmp(nombre,"")!=0)){
    if(dir[0] == '/'){
        char com[100];
        strcpy (com,  "mkdir -p '");
        strncat(com, dir, strlen(path)-1);
        strcat(com, "'");
        system(com);
    }
    }
    if(strcasecmp(unidad,"k")==0){
                contador = 1;
    }else{
                contador = 1024;
    }

    }
}
