#include <stdio.h>
#include <string.h>
#include "funciones.h"

void crear_archivo(char u[][50], int f[]) {
  FILE *archivo;
  archivo = fopen("archivo1.txt", "w+");
  if(archivo==NULL){
    printf("Error al abrir el archivo\n");
    return;
  }
  for(int i=0; i<10; i++){
    fprintf(archivo, "%s %d\n", u[i], f[i]);	
  }
  fclose(archivo);
  }

void agregar_texto(char p[], int a){
  int mont;
  char nuevo[10];
  FILE *archivo;
  archivo = fopen("archivo1.txt", "a+");
  if(archivo==NULL){
    printf("Error al abrir el archivo\n");
    return;
  }
  fprintf(archivo, "%s %d\n", p, a);
  fclose(archivo);
}

void buscar_producto(char p[]){
  FILE *archivo;
  archivo = fopen("archivo1.txt", "r+");
  if(archivo==NULL){
    printf("Error al abrir el archivo\n");
    return;
  }
  int cant;
  char producto[50];
  while(feof(archivo)!=1){
    fscanf(archivo, "%s %d", &producto, &cant);
    if(strcmp(producto, p)==0){
      printf("La cantidad del producto es: %d\n", cant);
    }
     }
  fclose(archivo);
  }

void eliminarElemento(char nombreArchivo[], char elementoEliminar[]) {
    FILE *archivo;
    FILE *archivoTemporal;
    char buffer[100];
    int eliminado = 0;

    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }

    archivoTemporal = fopen("temp.txt", "w");
    if (archivoTemporal == NULL) {
        fclose(archivo);
        printf("Error al abrir el archivo.\n");
        return;
    }

    while (fgets(buffer, sizeof(buffer), archivo)) {
        if (strstr(buffer, elementoEliminar) != NULL) {
            eliminado = 1;
        } else {
            fputs(buffer, archivoTemporal);
        }
    }

    fclose(archivo);
    fclose(archivoTemporal);

    if (eliminado) {
        remove(nombreArchivo);
        rename("temp.txt", nombreArchivo);
        printf("Elemento eliminado con éxito.\n");
    } else {
        remove("temp.txt");
        printf("Elemento no encontrado en el archivo.\n");
    }
}
void editarElemento(char nombreArchivo[], char elementoEliminar[], char nuevoElemento[], int cant) {
    FILE *archivo;
    FILE *archivoTemporal;
    char buffer[100]; 
    int eliminado = 0;
  
    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para eliminar el elemento.\n");
        return;
    }

    archivoTemporal = fopen("temp.txt", "w");
    if (archivoTemporal == NULL) {
        fclose(archivo);
        printf("No se pudo crear el archivo temporal.\n");
        return;
    }

    while (fgets(buffer, sizeof(buffer), archivo)) {
        if (strstr(buffer, elementoEliminar) != NULL) {
            eliminado = 1;
            fprintf(archivoTemporal, "%s %d\n", nuevoElemento, cant);
        } else {
            fputs(buffer, archivoTemporal);
        }
    }

    fclose(archivo);
    fclose(archivoTemporal);

  if (eliminado) {
      remove(nombreArchivo);
      rename("temp.txt", nombreArchivo);
      printf("Elemento editado con éxito.\n");
  } else {
      remove("temp.txt");
      printf("Elemento no encontrado en el archivo.\n");
  }
}
/*
void editarElemento(char nombreArchivo[], char elementoEliminar[], char nuevoElemento[]) {
    FILE *archivo;
    FILE *archivoTemporal;
    char buffer[100];
    int eliminado = 0;

    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para eliminar el elemento.\n");
        return;
    }

    archivoTemporal = fopen("temp.txt", "w");
    if (archivoTemporal == NULL) {
        fclose(archivo);
        printf("No se pudo crear el archivo temporal.\n");
        return;
    }

    while (fgets(buffer, sizeof(buffer), archivo)) {
        if (strstr(buffer, elementoEliminar) != NULL) {
            eliminado = 1;
            strncpy(buffer, nuevoElemento, strlen(nuevoElemento));
        }
        fputs(buffer, archivoTemporal);
    }

    fclose(archivo);
    fclose(archivoTemporal);

    if (eliminado) {
        remove(nombreArchivo);
        rename("temp.txt", nombreArchivo);
        printf("Elemento editado con éxito.\n");
    } else {
        remove("temp.txt");
        printf("Elemento no encontrado en el archivo.\n");
    }
}
*/
