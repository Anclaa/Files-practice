#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main(void) {
  FILE *archivo;
  int op;
  int fue=1;
  char p[10];
  char bus[50];
  char pe[50];	
  int m;
  char nom_produ[10][50]= {"Leche", "Pan", "Huevos", "Jamon", "Queso", "Cere","Pollo", "Arroz", "Frijoles", "Aceite"};
  int cantidad_produ[10] = {5, 6, 2, 6, 10, 5, 5, 11, 10, 0};
  do{
  printf("Escoja una opcion:\n");
  printf("1. Crear archivo\n");
  printf("2. Agregar Producto\n");
  printf("3. Buscar producto\n");
  printf("4. Eliminar producto\n");
  printf("5. Editar lista\n");
  printf("6. Salir\n");
  scanf("%d", &op);
    
  switch(op){
    case 1:
      crear_archivo(nom_produ, cantidad_produ);
     break;
    case 2:
      printf("Ingrese el nombre del producto: ");
      scanf("%s", &p);
      printf("cantidad del nuevo producto");
      scanf("%d", &m);
      agregar_texto(p, m);
     break;
    case 3:
      printf("Cual es el producto a buscar: ");
      scanf("%s", bus);
      buscar_producto(bus);
      break;
    case 4:
      printf("Ingrese el nombre del producto a eliminar: ");
      scanf("%s", &pe);
      eliminarElemento("archivo1.txt", pe);
    break;
    case 5:
      printf("Ingrese el nombre del producto a editar: ");
      scanf("%s", &pe);
      printf("Ingrese el nuevo nombre del producto: ");
      scanf("%s", &p);
      editarElemento("archivo1.txt", pe, p);
    break;
    case 6:
      fue=0;
    break;
    default:
      printf("Opcion no valida\n");
    }
    
  }while(fue==1);
 
  return 0;
}