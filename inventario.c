#include <stdio.h>
#include <stdlib.h>
#include "inventario.h"
#include <string.h>

Inventario *crearArreglo(){
    Inventario*nuevoArreglo;
    nuevoArreglo=(Inventario*)malloc(sizeof(Inventario));
    nuevoArreglo->num_departamentos=0;
    return nuevoArreglo;
}

void crearDepartamento(Inventario*unInventario){
    Departamento nuevoDepartamento;
   Departamento* temp = realloc(unInventario->departamentos, (unInventario->num_departamentos + 1) * sizeof(Departamento));
if (temp == NULL) {
    printf("Error al asignar memoria para el departamento.\n");
    return;  // o manejar el error de alguna otra forma
}
unInventario->departamentos = temp;

    nuevoDepartamento.nombre_departamento=(char*)malloc(30*sizeof(char));
    printf("\n Ingrese el nombre del departamento");
    getchar();
    fgets(nuevoDepartamento.nombre_departamento, 30, stdin);
    nuevoDepartamento.nombre_departamento[strcspn(nuevoDepartamento.nombre_departamento, "\n")] = '\0';  // Eliminar el salto de línea
    printf("\n Ingrese el maximo de articulos del departamento");
    scanf("%d",&nuevoDepartamento.max_articulos);
    nuevoDepartamento.articulos = (Articulo*)malloc(nuevoDepartamento.max_articulos*sizeof(Articulo));
    nuevoDepartamento.num_articulos=0;
        for(int i=0;i<nuevoDepartamento.max_articulos;i++){
        nuevoDepartamento.articulos[i].inventario=(int*)calloc(1,sizeof(int));
        nuevoDepartamento.articulos[i].nombre=(char*)calloc(30,sizeof(char));
    }
    unInventario->departamentos[unInventario->num_departamentos]=nuevoDepartamento;
    unInventario->num_departamentos++;
}

void insertarArticulo(int indice,int indice_dep,Inventario*unInventario){
    if(unInventario->departamentos[indice].num_articulos>=unInventario->departamentos[indice].max_articulos){
        printf("\n ERROR: se ha alcanzado el limite de articulos");
    }else{
        printf("\n Ingrese el codigo del articulo");
        scanf("%d",&unInventario->departamentos[indice].articulos[indice_dep].codigo);
        printf("\n Ingrese el precio del articulo");
        scanf("%f",&unInventario->departamentos[indice].articulos[indice_dep].precio);
        printf("\n Ingrese el inventario del articulo");
        scanf("%d",unInventario->departamentos[indice].articulos[indice_dep].inventario);
        printf("\n Ingrese el nombre del articulo: ");
        getchar();
        fgets(unInventario->departamentos[indice].articulos[indice_dep].nombre, 30, stdin);
        unInventario->departamentos[indice].articulos[indice_dep].nombre[strcspn(unInventario->departamentos[indice].articulos[indice_dep].nombre, "\n")] = '\0';
        unInventario->departamentos[indice].num_articulos++;
    }
}

void listarArticulos(int indice,int indice_dep,Inventario*unInventario){
    printf("\n ====ARTICULOS====");
    for(int i=0;i<indice_dep;i++){
        printf("\n Codigo del articulo: %d",unInventario->departamentos[indice].articulos[i].codigo);
        printf("\n Nombre del articulo: %s",unInventario->departamentos[indice].articulos[i].nombre);
        printf("\n Precio del articulo: %f",unInventario->departamentos[indice].articulos[i].precio);
        printf("\n Inventario del articulo: %i",*unInventario->departamentos[indice].articulos[i].inventario);
        printf("\n\n");
    }
}

//función para leer archivos
void LeerArticulos(Arreglo_articulos *arreglo, int *num_articulos) {
    FILE *dulce = fopen("Dulces.txt", "r");
    if (dulce == NULL) {
        printf("No se pudo acceder al archivo\n");
        return;
    }

    while (*num_articulos < 30 &&
           fscanf(dulce, "%29s %d %d %f",
                  arreglo->articulos[*num_articulos].nombre,
                  &arreglo->articulos[*num_articulos].inventario,
                  &arreglo->articulos[*num_articulos].codigo,
                  &arreglo->articulos[*num_articulos].precio) == 4) {
        (*num_articulos)++;
    }

    fclose(dulce);
}


/*
codigo;
    float precio;
    int *inventario;
    char *nombre[30];*/
