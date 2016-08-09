#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>


struct PARTITION
{
	char 	part_status;
	char 	part_type;
	char 	part_fit;
    int     part_start;
    int     part_size;
    char    part_name[16];
};

struct MBR{
	int 	mbr_tamano;
	time_t*	mbr_fecha_creacion;
	int 	mbr_disk_signature;
	struct 	PARTITION mbr_partition_1;
	struct 	PARTITION mbr_partition_2;
	struct  PARTITION mbr_partition_3;
	struct 	PARTITION mbr_partition_4;
	char 	part_nombre[50];
	int 	part_inicio;
	int 	part_tam;
};

struct EBR
{
	char 	part_status;
	char 	part_fit;
    int     part_start;
	int 	part_size;
	int 	part_next;
    int     part_previous;
	char	part_name[16];
};

struct SuperBloque{
	int	    s_filesystem_type;
	int 	s_inodes_count;
	int 	s_blocks_count;
	int 	s_free_blocks_count;
	int 	s_free_inodes_count;
	time_t*	s_mtime;
	time_t*	s_umtime;
	int 	s_mnt_count;
	int 	s_magic;
	int 	s_inode_size;
	int 	s_block_size;
	int 	s_first_ino;
	int 	s_first_blo;
	int 	s_bm_inode_start;
	int 	s_bm_block_start;
	int 	s_inode_start;
	int 	s_block_start;
};


struct Journal{
	int 	Journal_tipo_operacion;
	int 	Journal_tipo;
	char	Journal_nombre[10];
	int 	Journal_contenido;
	time_t*	Journal_fecha;
	char	Journal_propietario[10];
	int 	Journal_Permisos;
};

char comando[];
char buffer[1];
int tam;

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
        strcat(com, dir);
        strcat(com, "");
        system(com);
    }
    }
    if(strcasecmp(unidad,"k")==0){
                contador = 1;
    }else if(strcasecmp(unidad,"m")==0){
                contador = 1024;
    }
    else{
    printf("Error de unidad"); contador = 1024;
    }
        int tam = 0;
        tam = atoi(tamano)*1024*contador;
        char ruta[100] = "mkdir -p ";
        strcat(ruta,dir);
        system(ruta);
        strcat(dir,nombre);
        FILE *Fichero = fopen (dir, "w+b"); int i=0;
        while (i<tam/4){
         fwrite("0", 1, sizeof(i),Fichero);
         i++;
        }
        fclose(Fichero);
    }
    else if(strcasecmp(token, "rmdisk") == 0){
    tokens = comando;
    tokens = strtok(NULL, " ");
    if(tokens != NULL){
        path = tokens;
    }
    tokens = strtok(path, "::");
    if(strcasecmp(tokens, "-path") == 0){
    tokens = strtok(NULL, "::");
    strcpy(dir, tokens);}
    if(fopen(dir, "r")==NULL){
    printf("El disco no existe");
    } else{
    if(remove(dir) == 0){
    printf("Disco Eliminado");
    }else{
    printf("Error");
    }
    }
    }
    else if(strcasecmp(token, "rmdisk") == 0){
    }

}
