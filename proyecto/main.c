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

void analizar(char comando[])
{

    char *token;
    char *tokens;
    char *size="";    char *unit="";    char *name="";    char *path=""; char *type=""; char *fit=""; char *delet=""; char *add="";
    char tamano[100]="";    char unidad[2]="";     char nombre[100]="";   char dir[100]=""; char tipo[10]=""; char ajuste[10]="";  char borrar[10]="";char agregar[10]="";
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
        master.mbr_disk_signature = rand();
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
    }if(tokens != NULL){
        type = tokens; contador++;
    }if(tokens != NULL){
        fit = tokens; contador++;
    }if(tokens != NULL){
        delet = tokens; contador++;
    }if(tokens != NULL){
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
    strcpy(dir, tokens);}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, tokens);}
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
    strcpy(dir, tokens);}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, tokens);}
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
    strcpy(dir, tokens);}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, tokens);}
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
    strcpy(dir, tokens);}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, tokens);}
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
    strcpy(dir, tokens);}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, tokens);}
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
    strcpy(dir, tokens);}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, tokens);}
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
    strcpy(dir, tokens);}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, tokens);}
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
    strcpy(dir, tokens);}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, tokens);}
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
    }else if(strcasecmp(tipo,"")==0){
                strcpy(tipo, "wf");
    }else{
    printf("Ajuste incorrecto");
    }
    if(strcasecmp(borrar,"full")==0 || strcasecmp(ajuste,"fast")==0){
    }else if(strcasecmp(tipo,"")==0){
                strcpy(tipo, "fast");
    }else{
    printf("delete incorrecto");
    }

    }
    }


    else if(strcasecmp(token, "mount") == 0){
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
    strcpy(dir, tokens);}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, tokens);}
    else{
    tokens = strtok(NULL, "::");
    printf("Error en el comando: %s", tokens);
    }
    }
    else if(cont == 1 && strcasecmp(name, "") != 0){
    tokens = strtok(name, "::");
    if(strcasecmp(tokens, "-path") == 0){
    tokens = strtok(NULL, "::");
    strcpy(dir, tokens);}
    else if(strcasecmp(tokens, "-name") == 0){
    tokens = strtok(NULL, "::");
    strcpy(nombre, tokens);}
    else{
    tokens = strtok(NULL, "::");
    printf("Error en el comando: %s", tokens);
    }
    }cont ++;
    }
    printf("El nombre es: %s\n", nombre);
    printf("La Direccion es: %s\n", dir);
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
    strcpy(dir, tokens);}
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

}


void main(){
int ctokens=1;
    while(ctokens==1){
    scanf(" %[^\n]s", comando);
    analizar(comando);}
}
