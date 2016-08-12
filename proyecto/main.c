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
int tam;
char letra[28] = "abcdefghijklmnopqrstuvwxyz";
char monta [50][50][50];


char **split ( char *string, const char sep) {

char **list;
char *p = string;
int i = 0;

int pos;
const int len = strlen (string);

list = (char **) malloc (sizeof (char *));
if (list == NULL) {
return NULL;
}
	list[pos=0] = NULL;

while (i < len) { while ((p[i] == sep) && (i < len)) i++; if (i < len) { char **tmp = (char **) realloc (list , (pos + 2) * sizeof (char *)); if (tmp == NULL) { /* Cannot allocate memory */ free (list); return NULL; } list = tmp; tmp = NULL; list[pos + 1] = NULL; list[pos] = (char *) malloc (sizeof (char)); if (list[pos] == NULL) { /* Cannot allocate memory */ for (i = 0; i < pos; i++) free (list[i]); free (list); return NULL; } int j = 0; for (i; ((p[i] != sep) && (i < len)); i++) { list[pos][j] = p[i]; j++; char *tmp2 = (char *) realloc (list[pos],(j + 1) * sizeof (char)); if (list[pos] == NULL) { /* Cannot allocate memory */ for (i = 0; i < pos; i++) free (list[i]); free (list); return NULL; } list[pos] = tmp2; tmp2 = NULL; } list[pos][j] = '\0'; pos++; } } return list; }





void particion(char size[], char unit[], char name[], char path[], char type[], char fit[], char delet[], char add[]){
struct MBR mbr;
FILE *disco;
if((strcasecmp(size,"")!=0)&&(strcasecmp(path,"")!=0)&&(strcasecmp(name,"")!=0)){
    if((fopen (path, "rb+")) != NULL){
        disco = fopen (path, "rb+");
    }else{
        printf("Error");
    }

fread (&mbr, sizeof(mbr), 1,disco);

if((strcmp(delet,"") == 0) && (strcmp(add,"") == 0) && strcasecmp(type, "p")==0){
if(mbr.mbr_partition_1.part_status=='0'){
if(mbr.mbr_tamano - sizeof(mbr) >= atoi(size)*1024){
if(strcasecmp(mbr.mbr_partition_2.part_name, name)!=0 && strcasecmp(mbr.mbr_partition_3.part_name, name)!=0 && strcasecmp(mbr.mbr_partition_4.part_name, name) !=0){
strcpy(mbr.mbr_partition_1.part_name, name);
mbr.mbr_partition_1.part_start = sizeof(mbr);
mbr.mbr_partition_1.part_status = '1';
mbr.mbr_partition_1.part_size = atoi(size)*1024;
mbr.mbr_partition_1.part_type = 'p';
mbr.mbr_partition_1.part_fit = fit;
printf("Se creo la particion 1", name);}
else{printf("Ya existe una particion con este nombre");}
}else
{
printf("Tamaño insuficiente");
}
}
else if(mbr.mbr_partition_2.part_status=='0'){
if(mbr.mbr_tamano - sizeof(mbr) >= atoi(size)*1024){
if(strcasecmp(mbr.mbr_partition_1.part_name, name)!=0 && strcasecmp(mbr.mbr_partition_3.part_name, name)!=0 && strcasecmp(mbr.mbr_partition_4.part_name, name) !=0){
strcpy(mbr.mbr_partition_2.part_name, name);
mbr.mbr_partition_2.part_start = sizeof(mbr);
mbr.mbr_partition_2.part_status = '1';
mbr.mbr_partition_2.part_size = atoi(size)*1024;
mbr.mbr_partition_2.part_type = 'p';
mbr.mbr_partition_2.part_fit = fit;
printf("Se creo la particion 2", name);}
else{printf("Ya existe una particion con este nombre");}
}else
{
printf("Tamaño insuficiente");
}
}
else if(mbr.mbr_partition_3.part_status=='0'){
if(mbr.mbr_tamano - sizeof(mbr) >= atoi(size)*1024){
if(strcasecmp(mbr.mbr_partition_1.part_name, name)!=0 && strcasecmp(mbr.mbr_partition_2.part_name, name)!=0 && strcasecmp(mbr.mbr_partition_4.part_name, name) !=0){
strcpy(mbr.mbr_partition_3.part_name, name);
mbr.mbr_partition_3.part_start = sizeof(mbr);
mbr.mbr_partition_3.part_status = '1';
mbr.mbr_partition_3.part_size = atoi(size)*1024;
mbr.mbr_partition_3.part_type = 'p';
mbr.mbr_partition_3.part_fit = fit;
printf("Se creo la particion 3", name);}
else{printf("Ya existe una particion con este nombre");}
}else
{
printf("Tamaño insuficiente");
}
}
else if(mbr.mbr_partition_4.part_status=='0'){
if(mbr.mbr_tamano - sizeof(mbr) >= atoi(size)*1024){
if(strcasecmp(mbr.mbr_partition_1.part_name, name)!=0 && strcasecmp(mbr.mbr_partition_2.part_name, name)!=0 && strcasecmp(mbr.mbr_partition_3.part_name, name) !=0){
strcpy(mbr.mbr_partition_4.part_name, name);
mbr.mbr_partition_4.part_start = sizeof(mbr);
mbr.mbr_partition_4.part_status = '1';
mbr.mbr_partition_4.part_size = atoi(size)*1024;
mbr.mbr_partition_4.part_type = 'p';
mbr.mbr_partition_4.part_fit = fit;
printf("Se creo la particion 4", name);}
else{printf("Ya existe una particion con este nombre");}
}else
{
printf("Tamaño insuficiente");
}
}
else { printf("particiones llenas");}
}

}

fseek(disco,0,SEEK_SET);
fwrite(&mbr,sizeof(mbr),1,disco);
fclose(disco);
}

void analizar(char comando[])
{

    char *token;
    char *tokens;
    char *size="";    char *unit="";    char *name="";    char *path=""; char *type=""; char *fit=""; char *delet=""; char *add="";
    char tamano[100]="";    char unidad[2]="";     char nombre[100]="";   char dir[100]=""; char tipo[10]=""; char ajuste[10]="";  char borrar[10]="";char agregar[10]="";
    int contador = 0; char **comodin;
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
    strcpy(dir, strtok(tokens, "\""));
    }
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, strtok(tokens, "\""));}
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
    strcpy(dir, strtok(tokens, "\""));}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, strtok(tokens, "\""));}
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
    strcpy(dir, strtok(tokens, "\""));}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, strtok(tokens, "\""));}
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
    strcpy(dir, strtok(tokens, "\""));}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, strtok(tokens, "\""));}
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
    if(strcasecmp(unidad,"k")==0){
                contador = 1;
    }else if(strcasecmp(unidad,"m")==0){
                contador = 1024;
    }
    else if(strcasecmp(unidad,"")==0){
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
        struct MBR  master;
        time_t t = time(0);
        struct tm *timel = localtime(&t);
        strftime(master.mbr_fecha_creacion,128,"%d/%m/%y %H:%M:%S",timel);
        master.mbr_tamano = tamano;
        master.mbr_disk_signature = 1;
        master.mbr_partition_1.part_status = '0';
        master.mbr_partition_2.part_status = '0';
        master.mbr_partition_3.part_status = '0';
        master.mbr_partition_4.part_status = '0';
        while (i<tam/4){
         fwrite("0", 1, sizeof(i),Fichero);
         i++;
        }
        rewind(Fichero);
        fwrite(&master, sizeof(master), 1, Fichero);
        fclose(Fichero);
    }



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
    strcpy(dir, strtok(tokens, "\""));}
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



    else if(strcasecmp(token, "fdisk") == 0){
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
    } tokens = strtok(NULL, " ");
    if(tokens != NULL){
        type = tokens; contador++;
    } tokens = strtok(NULL, " ");
    if(tokens != NULL){
        fit = tokens; contador++;
    } tokens = strtok(NULL, " ");
    if(tokens != NULL){
        delet = tokens; contador++;
    } tokens = strtok(NULL, " ");
    if(tokens != NULL){
        add = tokens; contador++;
    }int cont = 0;
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
    strcpy(dir, strtok(tokens, "\""));}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, strtok(tokens, "\""));}
    else if(strcasecmp(tokens, "+type") == 0){
    tokens = strtok(NULL, "::");
    strcpy(tipo, tokens);}
    else if(strcasecmp(tokens, "+fit") == 0){
    tokens = strtok(NULL, "::");
    strcpy(ajuste, tokens);}
    else if(strcasecmp(tokens, "+delete") == 0){
    tokens = strtok(NULL, "::");
    strcpy(borrar, tokens);}
    else if(strcasecmp(tokens, "+add") == 0){
    tokens = strtok(NULL, "::");
    strcpy(agregar, tokens);}
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
    strcpy(dir, strtok(tokens, "\""));}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, strtok(tokens, "\""));}
    else if(strcasecmp(tokens, "+type") == 0){
    tokens = strtok(NULL, "::");
    strcpy(tipo, tokens);}
    else if(strcasecmp(tokens, "+fit") == 0){
    tokens = strtok(NULL, "::");
    strcpy(ajuste, tokens);}
    else if(strcasecmp(tokens, "+delete") == 0){
    tokens = strtok(NULL, "::");
    strcpy(borrar, tokens);}
    else if(strcasecmp(tokens, "+add") == 0){
    tokens = strtok(NULL, "::");
    strcpy(agregar, tokens);}
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
    strcpy(dir, strtok(tokens, "\""));}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, strtok(tokens, "\""));}
    else if(strcasecmp(tokens, "+type") == 0){
    tokens = strtok(NULL, "::");
    strcpy(tipo, tokens);}
    else if(strcasecmp(tokens, "+fit") == 0){
    tokens = strtok(NULL, "::");
    strcpy(ajuste, tokens);}
    else if(strcasecmp(tokens, "+delete") == 0){
    tokens = strtok(NULL, "::");
    strcpy(borrar, tokens);}
    else if(strcasecmp(tokens, "+add") == 0){
    tokens = strtok(NULL, "::");
    strcpy(agregar, tokens);}
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
    strcpy(dir, strtok(tokens, "\""));}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, strtok(tokens, "\""));}
    else if(strcasecmp(tokens, "+type") == 0){
    tokens = strtok(NULL, "::");
    strcpy(tipo, tokens);}
    else if(strcasecmp(tokens, "+fit") == 0){
    tokens = strtok(NULL, "::");
    strcpy(ajuste, tokens);}
    else if(strcasecmp(tokens, "+delete") == 0){
    tokens = strtok(NULL, "::");
    strcpy(borrar, tokens);}
    else if(strcasecmp(tokens, "+add") == 0){
    tokens = strtok(NULL, "::");
    strcpy(agregar, tokens);}
    else{
    tokens = strtok(NULL, "::");
    printf("Error en el comando: %s", tokens);
    }
    }
    else if(cont == 4 && strcasecmp(type, "") != 0){
    tokens = strtok(type, "::");
    if(strcasecmp(tokens, "-size") == 0){
    tokens = strtok(NULL, "::");
    strcpy(tamano, tokens);}
    else if(strcasecmp(tokens, "+unit") == 0){
    tokens = strtok(NULL, "::");
    strcpy(unidad, tokens);}
    else if(strcasecmp(tokens, "-path") == 0){
    tokens = strtok(NULL, "::");
    strcpy(dir, strtok(tokens, "\""));}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, strtok(tokens, "\""));}
    else if(strcasecmp(tokens, "+type") == 0){
    tokens = strtok(NULL, "::");
    strcpy(tipo, tokens);}
    else if(strcasecmp(tokens, "+fit") == 0){
    tokens = strtok(NULL, "::");
    strcpy(ajuste, tokens);}
    else if(strcasecmp(tokens, "+delete") == 0){
    tokens = strtok(NULL, "::");
    strcpy(borrar, tokens);}
    else if(strcasecmp(tokens, "+add") == 0){
    tokens = strtok(NULL, "::");
    strcpy(agregar, tokens);}
    else{
    tokens = strtok(NULL, "::");
    printf("Error en el comando: %s", tokens);
    }
    }else if(cont == 5 && strcasecmp(fit, "") != 0){
    tokens = strtok(fit, "::");
    if(strcasecmp(tokens, "-size") == 0){
    tokens = strtok(NULL, "::");
    strcpy(tamano, tokens);}
    else if(strcasecmp(tokens, "+unit") == 0){
    tokens = strtok(NULL, "::");
    strcpy(unidad, tokens);}
    else if(strcasecmp(tokens, "-path") == 0){
    tokens = strtok(NULL, "::");
    strcpy(dir, strtok(tokens, "\""));}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, strtok(tokens, "\""));}
    else if(strcasecmp(tokens, "+type") == 0){
    tokens = strtok(NULL, "::");
    strcpy(tipo, tokens);}
    else if(strcasecmp(tokens, "+fit") == 0){
    tokens = strtok(NULL, "::");
    strcpy(ajuste, tokens);}
    else if(strcasecmp(tokens, "+delete") == 0){
    tokens = strtok(NULL, "::");
    strcpy(borrar, tokens);}
    else if(strcasecmp(tokens, "+add") == 0){
    tokens = strtok(NULL, "::");
    strcpy(agregar, tokens);}
    else{
    tokens = strtok(NULL, "::");
    printf("Error en el comando: %s", tokens);
    }
    }else if(cont == 6 && strcasecmp(delet, "") != 0){
    tokens = strtok(delet, "::");
    if(strcasecmp(tokens, "-size") == 0){
    tokens = strtok(NULL, "::");
    strcpy(tamano, tokens);}
    else if(strcasecmp(tokens, "+unit") == 0){
    tokens = strtok(NULL, "::");
    strcpy(unidad, tokens);}
    else if(strcasecmp(tokens, "-path") == 0){
    tokens = strtok(NULL, "::");
    strcpy(dir, strtok(tokens, "\""));}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, strtok(tokens, "\""));}
    else if(strcasecmp(tokens, "+type") == 0){
    tokens = strtok(NULL, "::");
    strcpy(tipo, tokens);}
    else if(strcasecmp(tokens, "+fit") == 0){
    tokens = strtok(NULL, "::");
    strcpy(ajuste, tokens);}
    else if(strcasecmp(tokens, "+delete") == 0){
    tokens = strtok(NULL, "::");
    strcpy(borrar, tokens);}
    else if(strcasecmp(tokens, "+add") == 0){
    tokens = strtok(NULL, "::");
    strcpy(agregar, tokens);}
    else{
    tokens = strtok(NULL, "::");
    printf("Error en el comando: %s", tokens);
    }
    }else if(cont == 7 && strcasecmp(add, "") != 0){
    tokens = strtok(add, "::");
    if(strcasecmp(tokens, "-size") == 0){
    tokens = strtok(NULL, "::");
    strcpy(tamano, tokens);}
    else if(strcasecmp(tokens, "+unit") == 0){
    tokens = strtok(NULL, "::");
    strcpy(unidad, tokens);}
    else if(strcasecmp(tokens, "-path") == 0){
    tokens = strtok(NULL, "::");
    strcpy(dir, strtok(tokens, "\""));}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, strtok(tokens, "\""));}
    else if(strcasecmp(tokens, "+type") == 0){
    tokens = strtok(NULL, "::");
    strcpy(tipo, tokens);}
    else if(strcasecmp(tokens, "+fit") == 0){
    tokens = strtok(NULL, "::");
    strcpy(ajuste, tokens);}
    else if(strcasecmp(tokens, "+delete") == 0){
    tokens = strtok(NULL, "::");
    strcpy(borrar, tokens);}
    else if(strcasecmp(tokens, "+add") == 0){
    tokens = strtok(NULL, "::");
    strcpy(agregar, tokens);}
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
    printf("El tipo es: %s\n", tipo);
    printf("El ajuste es: %s\n", ajuste);
    printf("Delete es: %s\n", borrar);
    printf("Add es: %s\n", agregar);
    if((strcasecmp(tamano,"")!=0)&&(strcasecmp(dir,"")!=0)&&(strcasecmp(nombre,"")!=0)){
    if(strcasecmp(unidad,"k")==0){
                contador = 1024;
    }else if(strcasecmp(unidad,"m")==0){
                contador = 1024*1024;
    }
    else if(strcasecmp(unidad,"b")==0){
                contador = 1;
    }
    else if(strcasecmp(unidad,"")==0){
                contador = 1024;
    }
    else{
    printf("Error de unidad"); contador = 1024;
    }
    if(strcasecmp(tipo,"p")==0 || strcasecmp(tipo,"e")==0 || strcasecmp(tipo,"l")==0){
    }else if(strcasecmp(tipo,"")==0){
                strcpy(tipo, "p");
    }else{
    printf("Tipo de particion incorrecto");
    }
    if(strcasecmp(ajuste,"bf")==0 || strcasecmp(ajuste,"ff")==0 || strcasecmp(ajuste,"wf")==0){
    }else if(strcasecmp(ajuste,"")==0){
                strcpy(ajuste, "wf");
    }else{
    printf("Ajuste incorrecto");
    }
    particion(tamano, unidad, nombre, dir, tipo, ajuste, borrar, agregar);
    }
    }


    else if(strcasecmp(token, "mount") == 0){
    struct MBR m;
    tokens = comando;
    tokens = strtok(NULL, " ");
    if(tokens != NULL){
        path = tokens; contador++;
    } tokens = strtok(NULL, " ");
    if(tokens != NULL){
        name = tokens; contador++;
    }
    int cont = 0;
    while(cont < contador){
    if(cont == 0 && strcasecmp(path, "") != 0){
    tokens = strtok(path, "::");
    if(strcasecmp(tokens, "-path") == 0){
    tokens = strtok(NULL, "::");
    strcpy(dir, strtok(tokens, "\""));}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, strtok(tokens, "\""));}
    else{
    tokens = strtok(NULL, "::");
    printf("Error en el comando: %s", tokens);
    }
    }
    else if(cont == 1 && strcasecmp(name, "") != 0){
    tokens = strtok(name, "::");
    if(strcasecmp(tokens, "-path") == 0){
    tokens = strtok(NULL, "::");
    strcpy(dir, strtok(tokens, "\""));}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, strtok(tokens, "\""));}
    else{
    tokens = strtok(NULL, "::");
    printf("Error en el comando: %s", tokens);
    }
    }cont ++;
    }
    printf("El nombre es: %s\n", nombre);
    printf("La Direccion es: %s\n", dir);
    FILE *part;
    if(fopen(dir, "r+b")==NULL){
    printf("La particion no existe");
    } else{
    part = fopen(dir, "r+b");
    fseek(part,0,SEEK_SET);
    fread (&m, sizeof(m), 1,part);
    if(strcasecmp(m.mbr_partition_1.part_name, nombre)==0){
    int i=0; int enumerador =1; char *id = malloc(sizeof(char) * 128);
    while(i<50){
    if((strcasecmp(monta[i][0],"")==0) || (strcasecmp(monta[i][0], dir)==0)){
    strcpy(monta[i][0], dir);
    while ((strcasecmp(monta[i][enumerador], "") != 0)&&(strcasecmp(monta[i][enumerador], nombre) != 0)){
    enumerador++;
    }
    strcpy(monta[i][enumerador], nombre);
    sprintf(id, "vd%c%d", letra[0], enumerador);
    strcpy(monta[i][enumerador+1], id);
    strcpy(monta[i][enumerador+2], "1");
    printf("id asignado %s", id);
    m.mbr_partition_1.part_status = 'm';
    break;
    }else{
    i++;
    }
    }
    }else if(strcasecmp(m.mbr_partition_2.part_name, nombre)==0){
    int i=0; int enumerador =1; char *id = malloc(sizeof(char) * 128);
    while(i<50){
    if((strcasecmp(monta[i][0],"")==0) || (strcasecmp(monta[i][0], dir)==0)){
    strcpy(monta[i][0], dir);
    while ((strcasecmp(monta[i][enumerador], "") != 0)&&(strcasecmp(monta[i][enumerador], nombre) != 0)){
    enumerador++;
    }
    strcpy(monta[i][enumerador], nombre);
    sprintf(id, "vd%c%d", letra[0], enumerador);
    strcpy(monta[i][enumerador+1], id);
    strcpy(monta[i][enumerador+2], "2");
    printf("id asignado %s", id);
    m.mbr_partition_2.part_status = 'm';
    break;
    }else{
    i++;
    }
    }
    }else if(strcasecmp(m.mbr_partition_3.part_name, nombre)==0){
    int i=0; int enumerador =1; char *id = malloc(sizeof(char) * 128);
    while(i<50){
    if((strcasecmp(monta[i][0],"")==0) || (strcasecmp(monta[i][0], dir)==0)){
    strcpy(monta[i][0], dir);
    while ((strcasecmp(monta[i][enumerador], "") != 0)&&(strcasecmp(monta[i][enumerador], nombre) != 0)){
    enumerador++;
    }
    strcpy(monta[i][enumerador], nombre);
    sprintf(id, "vd%c%d", letra[0], enumerador);
    strcpy(monta[i][enumerador+1], id);
    strcpy(monta[i][enumerador+2], "3");
    printf("id asignado %s", id);
    m.mbr_partition_3.part_status = 'm';
    break;
    }else{
    i++;
    }
    }
    }else if(strcasecmp(m.mbr_partition_4.part_name, nombre)==0){
    int i=0; int enumerador =1; char *id = malloc(sizeof(char) * 128);
    while(i<50){
    if((strcasecmp(monta[i][0],"")==0) || (strcasecmp(monta[i][0], dir)==0)){
    strcpy(monta[i][0], dir);
    while ((strcasecmp(monta[i][enumerador], "") != 0)&&(strcasecmp(monta[i][enumerador], nombre) != 0)){
    enumerador++;
    }
    strcpy(monta[i][enumerador], nombre);
    sprintf(id, "vd%c%d", letra[0], enumerador);
    strcpy(monta[i][enumerador+1], id);
    strcpy(monta[i][enumerador+2], "4");
    printf("id asignado %s", id);
    m.mbr_partition_4.part_status = 'm';
    break;
    }else{
    i++;
    }
    }
    }fclose(part);
    }

    }


    else if(strcasecmp(token, "umount") == 0){
    tokens = comando;
    tokens = strtok(NULL, " ");
    if(tokens != NULL){
        path = tokens;
    }
    tokens = strtok(path, "::");
    if(strcasecmp(tokens, "-id1") == 0){
    tokens = strtok(NULL, "::");
    strcpy(dir, tokens);}
    printf("El id es: %s\n", dir);
    int s = 0; int a = 0; char *prueba = "";
    while(strcasecmp(monta[s][2],dir) != 0){
    s++;
    if(s > 50){
    prueba = "error";
    break;
    }
    }
    if(strcasecmp(prueba, "error")!=0){
    char *ruta = monta[s][0]; char id[2];
    strcpy(id, monta[s][3]);
    struct MBR m;
    FILE *part;
    part = fopen(monta[s][0], "r+b");
    fseek(part,0,SEEK_SET);
    fread (&m, sizeof(m), 1,part); int t = 0;
    while(t < 4){
    strcpy(monta[s][t], "");
    t++;
    }
    if(strcasecmp(id, "1")==0){
    m.mbr_partition_1.part_status = 'u';
    printf("Particion %s fue desmontada", dir);
    }else if(strcasecmp(id, "2")==0){
    m.mbr_partition_2.part_status = 'u';
    printf("Particion %s fue desmontada", dir);
    }else if(strcasecmp(id, "3")==0){
    m.mbr_partition_3.part_status = 'u';
    printf("Particion %s fue desmontada", dir);
    }else if(strcasecmp(id, "4")==0){
    m.mbr_partition_4.part_status = 'u';
    printf("Particion %s fue desmontada", dir);
    }
    }else{printf("error, id no existe");}

    }


else if(strcasecmp(token, "exec") == 0){
    tokens = comando;
    tokens = strtok(NULL, " ");
    if(tokens != NULL){
        path = tokens;
    }
    tokens = strtok(path, "::");
    if(strcasecmp(tokens, "-path") == 0){
    tokens = strtok(NULL, "::");
    strcpy(dir, strtok(tokens, "\""));}
    printf("El id es: %s\n", dir);
    FILE *Fich = fopen (dir, "r");
    char Archivo[250]="";    char Archivot[250]="";
    if(Fich != NULL){
    while(feof(Fich)==0){
    fgets(Archivo,100,Fich);
    strcpy(Archivot, Archivo);
    if(Archivot[0] != '#'){
    if((strcasecmp(Archivo,"") != 0)){
    printf("\n%s", Archivo);
    analizar(Archivo);
    }
    }else{
    printf("\n%s", Archivot);
    }
    }
    fclose(Fich);
    }
    }



    else if(strcasecmp(token, "rep") == 0){
    tokens = comando;
    tokens = strtok(NULL, " ");
    if(tokens != NULL){
        path = tokens; contador++;
    } tokens = strtok(NULL, " ");
    if(tokens != NULL){
        name = tokens; contador++;
    } tokens = strtok(NULL, " ");
    if(tokens != NULL){
        type = tokens; contador++;
    } tokens = strtok(NULL, " ");
    if(tokens != NULL){
        size = tokens; contador++;
    }
    int cont = 0;
    while(cont < contador){
    if(cont == 0 && strcasecmp(path, "") != 0){
    tokens = strtok(path, "::");
    if(strcasecmp(tokens, "-path") == 0){
    tokens = strtok(NULL, "::");
    strcpy(dir, strtok(tokens, "\""));}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, tokens);}
    else if(strcasecmp(tokens, "-id") == 0){
    tokens = strtok(NULL, "::");
    strcpy(tipo, tokens);}
    else if(strcasecmp(tokens, "+ruta") == 0){
    tokens = strtok(NULL, "::");
    strcpy(tamano, strtok(tokens, "\""));}
    else{
    tokens = strtok(NULL, "::");
    printf("Error en el comando: %s", tokens);
    }
    }else if(cont == 1 && strcasecmp(name, "") != 0){
    tokens = strtok(name, "::");
    if(strcasecmp(tokens, "-path") == 0){
    tokens = strtok(NULL, "::");
    strcpy(dir, strtok(tokens, "\""));}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, tokens);}
    else if(strcasecmp(tokens, "-id") == 0){
    tokens = strtok(NULL, "::");
    strcpy(tipo, tokens);}
    else if(strcasecmp(tokens, "+ruta") == 0){
    tokens = strtok(NULL, "::");
    strcpy(tamano, strtok(tokens, "\""));}
    else{
    tokens = strtok(NULL, "::");
    printf("Error en el comando: %s", tokens);
    }
    }else if(cont == 2 && strcasecmp(type, "") != 0){
    tokens = strtok(type, "::");
    if(strcasecmp(tokens, "-path") == 0){
    tokens = strtok(NULL, "::");
    strcpy(dir, strtok(tokens, "\""));}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, tokens);}
    else if(strcasecmp(tokens, "-id") == 0){
    tokens = strtok(NULL, "::");
    strcpy(tipo, tokens);}
    else if(strcasecmp(tokens, "+ruta") == 0){
    tokens = strtok(NULL, "::");
    strcpy(tamano, strtok(tokens, "\""));}
    else{
    tokens = strtok(NULL, "::");
    printf("Error en el comando: %s", tokens);
    }
    }
    else if(cont == 3 && strcasecmp(size, "") != 0){
    tokens = strtok(size, "::");
    if(strcasecmp(tokens, "-path") == 0){
    tokens = strtok(NULL, "::");
    strcpy(dir, strtok(tokens, "\""));}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, tokens);}
    else if(strcasecmp(tokens, "-id") == 0){
    tokens = strtok(NULL, "::");
    strcpy(tipo, tokens);}
    else if(strcasecmp(tokens, "+ruta") == 0){
    tokens = strtok(NULL, "::");
    strcpy(tamano, strtok(tokens, "\""));}
    else{
    tokens = strtok(NULL, "::");
    printf("Error en el comando: %s", tokens);
    }
    }cont ++;
    }
    printf("El nombre es: %s\n", nombre);
    printf("La Direccion es: %s\n", dir);
    printf("La ruta es: %s\n", tamano);
    printf("El id es: %s\n", tipo);
    if(strcasecmp(nombre, "mbr")==0){
    int s = 0; int a = 0; char *prueba = "";
    while(strcasecmp(monta[s][2],tipo) != 0){
    printf("%i", s);
    printf("%s", monta[s][2]);
    s++;
    if(s > 50){
    prueba = "error";
    break;
    }
    }
    if(strcasecmp(prueba, "error")!=0){
    struct MBR mabore;
    FILE *part;
    part = fopen(monta[s][0], "r+b");
    fseek(part,0,SEEK_SET);
    fread (&mabore, sizeof(mabore), 1,part);
    FILE *fp;
 	fp = fopen ("re.dot", "w+");
    fprintf(fp," digraph mbr {\n");
    fprintf(fp,"label=<<B>Master Boot Record: %s</B>>;\n",dir);
    fprintf(fp,"fontsize=17;");
    fprintf(fp,"node [shape=plaintext fontname = \"Ubuntu\"];\n");

    fprintf(fp,"MBR [label=<<table border=\"1\" cellborder=\"1\" cellspacing=\"0\">\n");
    fprintf(fp,"<tr><td bgcolor=\"#033670\"><b>Nombre</b></td><td bgcolor=\"#033670\"><b>Valor</b></td></tr> \n");

    fprintf(fp,"<tr><td bgcolor=\"#9BC4F3\"><b>mbr_tamaño</b></td><td>%i</td></tr>\n",mabore.mbr_tamano);
    fprintf(fp,"<tr><td bgcolor=\"#9BC4F3\"><b>mbr_fecha_creacion</b></td><td>%s</td></tr>\n",mabore.mbr_fecha_creacion);
    fprintf(fp,"<tr><td bgcolor=\"#9BC4F3\"><b>mbr_disk_signature</b></td><td>%i</td></tr>\n",mabore.mbr_disk_signature);

    if(mabore.mbr_partition_1.part_status != '0'){
    fprintf(fp,"<tr><td bgcolor=\"#275EA6\"><b>part_status_1</b></td><td>%c</td></tr>\n",mabore.mbr_partition_1.part_status);
    fprintf(fp,"<tr><td bgcolor=\"#275EA6\"><b>part_type_1</b></td><td>%c</td></tr>\n",mabore.mbr_partition_1.part_type);
    fprintf(fp,"<tr><td bgcolor=\"#275EA6\"><b>part_fit_1</b></td><td>%c</td></tr>\n",mabore.mbr_partition_1.part_fit);
    fprintf(fp,"<tr><td bgcolor=\"#275EA6\"><b>part_start_1</b></td><td>%d</td></tr>\n",mabore.mbr_partition_1.part_start);
    fprintf(fp,"<tr><td bgcolor=\"#275EA6\"><b>part_size_1</b></td><td>%d</td></tr>\n",mabore.mbr_partition_1.part_size);
    fprintf(fp,"<tr><td bgcolor=\"#275EA6\"><b>part_name_1</b></td><td>%s</td></tr>\n",mabore.mbr_partition_1.part_name);}

    if(mabore.mbr_partition_2.part_status != '0'){
	fprintf(fp,"<tr><td bgcolor=\"#9BC4F3\"><b>part_status_2</b></td><td>%c</td></tr>\n",mabore.mbr_partition_2.part_status);
    fprintf(fp,"<tr><td bgcolor=\"#9BC4F3\"><b>part_type_2</b></td><td>%c</td></tr>\n",mabore.mbr_partition_2.part_type);
    fprintf(fp,"<tr><td bgcolor=\"#9BC4F3\"><b>part_fit_2</b></td><td>%c</td></tr>\n",mabore.mbr_partition_2.part_fit);
    fprintf(fp,"<tr><td bgcolor=\"#9BC4F3\"><b>part_start_2</b></td><td>%d</td></tr>\n",mabore.mbr_partition_2.part_start);
    fprintf(fp,"<tr><td bgcolor=\"#9BC4F3\"><b>part_size_2</b></td><td>%d</td></tr>\n",mabore.mbr_partition_2.part_size);
    fprintf(fp,"<tr><td bgcolor=\"#9BC4F3\"><b>part_name_2</b></td><td>%s</td></tr>\n",mabore.mbr_partition_2.part_name);}

    if(mabore.mbr_partition_3.part_status != '0'){
	fprintf(fp,"<tr><td bgcolor=\"#275EA6\"><b>part_status_3</b></td><td>%c</td></tr>\n",mabore.mbr_partition_3.part_status);
    fprintf(fp,"<tr><td bgcolor=\"#275EA6\"><b>part_type_3</b></td><td>%c</td></tr>\n",mabore.mbr_partition_3.part_type);
    fprintf(fp,"<tr><td bgcolor=\"#275EA6\"><b>part_fit_3</b></td><td>%c</td></tr>\n",mabore.mbr_partition_3.part_fit);
    fprintf(fp,"<tr><td bgcolor=\"#275EA6\"><b>part_start_3</b></td><td>%d</td></tr>\n",mabore.mbr_partition_3.part_start);
    fprintf(fp,"<tr><td bgcolor=\"#275EA6\"><b>part_size_3</b></td><td>%d</td></tr>\n",mabore.mbr_partition_3.part_size);
    fprintf(fp,"<tr><td bgcolor=\"#275EA6\"><b>part_name_3</b></td><td>%s</td></tr>\n",mabore.mbr_partition_3.part_name);}

    if(mabore.mbr_partition_4.part_status != '0'){
    fprintf(fp,"<tr><td bgcolor=\"#9BC4F3\"><b>part_status_4</b></td><td>%c</td></tr>\n",mabore.mbr_partition_4.part_status);
    fprintf(fp,"<tr><td bgcolor=\"#9BC4F3\"><b>part_type_4</b></td><td>%c</td></tr>\n",mabore.mbr_partition_4.part_type);
    fprintf(fp,"<tr><td bgcolor=\"#9BC4F3\"><b>part_fit_4</b></td><td>%c</td></tr>\n",mabore.mbr_partition_4.part_fit);
    fprintf(fp,"<tr><td bgcolor=\"#9BC4F3\"><b>part_start_4</b></td><td>%d</td></tr>\n",mabore.mbr_partition_4.part_start);
    fprintf(fp,"<tr><td bgcolor=\"#9BC4F3\"><b>part_size_4</b></td><td>%d</td></tr>\n",mabore.mbr_partition_4.part_size);
    fprintf(fp,"<tr><td bgcolor=\"#9BC4F3\"><b>part_name_4</b></td><td>%s</td></tr>\n",mabore.mbr_partition_4.part_name);}

    fprintf(fp,"</table>>];}\n");
    fclose ( fp );

    char com[100];
    strcpy(com,"dot -Tpng re.dot -o ");
    strcat(com, dir);
    system(com);
    char con[100];
    strcpy(con, "gnome-open ");
    system("gnome-open re.dot");
    strcat(con, dir);
    system(con);
    }
    }else if(strcasecmp(nombre, "disk")==0){
    int s = 0; int a = 0; char *prueba = "";
    while(strcasecmp(monta[s][2],tipo) != 0){
    printf("%i", s);
    printf("%s", monta[s][2]);
    s++;
    if(s > 50){
    prueba = "error";
    break;
    }
    }
    if(strcasecmp(prueba, "error")!=0){
    struct MBR mabore;
    FILE *part;
    part = fopen(monta[s][0], "r+b");
    fseek(part,0,SEEK_SET);
    fread (&mabore, sizeof(mabore), 1,part);
    FILE *fp;
 	fp = fopen ("disk.dot", "w+" );
    fprintf(fp," digraph {\n");

    fprintf(fp,"label=<<B>%s</B>>;\n",dir);
    fprintf(fp,"fontsize=17;");
    fprintf(fp,"node [shape=plaintext fontname = \"Ubuntu\"];\n");
    fprintf(fp,"node [shape=plaintext fontname = \"Ubuntu\"];\n");
    fprintf(fp,"graph [fontname = \"Ubuntu\"];\n");

    fprintf(fp,"b [label=<");
    fprintf(fp,"<TABLE>");
    fprintf(fp,"<TR>");
    fprintf(fp,"<TD ALIGN=\"center\" BORDER=\"1\" WIDTH=\"%i\"><b>MBR</b></TD>", ((sizeof(mabore) * 60000) /mabore.mbr_tamano ));

    if(mabore.mbr_partition_1.part_status =='0' && mabore.mbr_partition_2.part_status == '0' && mabore.mbr_partition_3.part_status =='0' && mabore.mbr_partition_4.part_status =='0'){
    fprintf(fp,"<TD ALIGN=\"center\" BORDER=\"1\" COLSPAN=\"3\" ALIGN=\"center\" PORT=\"there\"><b>Libre</b></TD>");
    }else{

    if(mabore.mbr_partition_1.part_status =='0'){
    fprintf(fp,"<TD ALIGN=\"center\" BORDER=\"1\"><b>Libre</b></TD>");
    }else{


    if(mabore.mbr_partition_1.part_type == 'p'){
    fprintf(fp,"<TD ALIGN=\"center\" BORDER=\"1\" WIDTH=\"%i\"><b>Primaria</b></TD>",((mabore.mbr_partition_1.part_size * 60000) /mabore.mbr_tamano ));

    }else{
    fprintf(fp,"<TD><TABLE BORDER=\"2\"><TR>");
    fprintf(fp,"<TD ALIGN=\"center\" BORDER=\"1\"><b>Libre</b></TD>");
    fprintf(fp,"</TR>");
    }
    }

    if(mabore.mbr_partition_2.part_status == '0'){
    fprintf(fp,"<TD ALIGN=\"center\" BORDER=\"1\"><b>Libre</b></TD>");
    }else{


    if(mabore.mbr_partition_2.part_type == 'p'){
    fprintf(fp,"<TD ALIGN=\"center\" BORDER=\"1\" WIDTH=\"%i\"><b>Primaria</b></TD>",((mabore.mbr_partition_2.part_size * 60000) /mabore.mbr_tamano ));

    }else{
    fprintf(fp,"<TD><TABLE BORDER=\"2\"><TR>");
    fprintf(fp,"<TD ALIGN=\"center\" BORDER=\"1\"><b>Libre</b></TD>");
    fprintf(fp,"</TR>");
    }
    }


    if(mabore.mbr_partition_3.part_status =='0'){
    fprintf(fp,"<TD ALIGN=\"center\" BORDER=\"1\"><b>Libre</b></TD>");
    }else{


    if(mabore.mbr_partition_3.part_type == 'p'){
    fprintf(fp,"<TD ALIGN=\"center\"  BORDER=\"1\" WIDTH=\"%i\"><b>Primaria</b></TD>",((mabore.mbr_partition_3.part_size * 60000) /mabore.mbr_tamano ));

    }else{
    fprintf(fp,"<TD><TABLE BORDER=\"2\"><TR>");
    fprintf(fp,"<TD ALIGN=\"center\" BORDER=\"1\"><b>Libre</b></TD>");
    fprintf(fp,"</TR>");
    }
    }


    if(mabore.mbr_partition_4.part_status == '0'){
    fprintf(fp,"<TD ALIGN=\"center\" BORDER=\"1\"><b>Libre</b></TD>");
    }else{


    if(mabore.mbr_partition_4.part_type == 'p'){
    fprintf(fp,"<TD ALIGN=\"center\" BORDER=\"1\" WIDTH=\"%i\"><b>Primaria</b></TD>",((mabore.mbr_partition_4.part_size * 60000) /mabore.mbr_tamano ));

    }else{
    fprintf(fp,"<TD><TABLE BORDER=\"2\"><TR>");
    fprintf(fp,"<TD ALIGN=\"center\" BORDER=\"1\"><b>Libre</b></TD>");
    fprintf(fp,"</TR>");
    }
    }
    }
    fprintf(fp,"</TR>");
    fprintf(fp,"</TABLE>>];");
    fprintf(fp,"}\n");
    fclose(fp);
    char com[100];
    strcpy(com,"dot -Tpng disk.dot -o ");
    strcat(com, dir);
    system(com);
    char con[100];
    strcpy(con, "gnome-open ");
    system("gnome-open disk.dot");
    strcat(con, dir);
    system(con);
    }
    }
    }

}


void main(){
int ctokens=1; char t[200]; char h[400];
    time_t to;
    srand((unsigned) time(&to));
    while(ctokens==1){
    scanf(" %[^\n]s", comando);
    if(comando[0]=="#"){
    }
    else{
    if (comando[strlen(comando)-1] == '\\')
    {
    	scanf(" %[^\n]s", t);
        strncpy(h, comando, strlen(comando)-1);
        strcat(h, t);
        strcpy(comando, h);
        analizar(comando);
    }
    else
    {
        analizar(comando);
    }
    }}
}
