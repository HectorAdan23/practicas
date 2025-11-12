#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Punteros dobles globales para el inventario
char **nombresProductos;

// punteros globales normales
int *cantidades;
double *precios;

//enteros globales
int numP;

//funciones principales
int inventarioPrincipal();

int main() {
    
    int opcion;
    double totalInventario = 0.0;       //valores necesarios
    numP = 0;
    int finC;

    printf("=== SISTEMA DE INVENTARIO ===\n");

    // Llenar inventario con datos de ejemplo.
    finC = inventarioPrincipal();
    
    if(finC == 0){
        return 0;   //si esto es verdad, se acaba el c por no guardar memoria
    }

    // Menú interactivo
    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Agregar producto\n");
        printf("2. Mostrar inventario\n");
        printf("3. Calcular valor total del inventario\n");
        printf("4. Salir\n");
        printf("Seleccione opcion: ");
        scanf("%d", &opcion);

        getchar();      //limpiar el buffer

        switch(opcion) {
            case 1:
    
               

                break;

            case 2:

               

                break;

            case 3:

                  

                break;

            case 4:
                
                //mensaje de despedida del programa
                printf("Saliendo del sistema...\n");
                break;

            default:

                //El usuario dio un valor invalido
                printf("Opcion invalida.\n");
        }
    } while(opcion != 4);

    // Liberar memoria antes de salir
    

    return 0;
}

int inventarioPrincipal(){

    nombresProductos = (char**) calloc(8,sizeof(char*));
    //asignar memoria al global puntero doble nombreproductos

    cantidades = (int*) calloc (8,sizeof(int));
    //asignar memoria al global puntero simple cantidades

    precios = (double*) calloc (8,sizeof(double));
    //asignar memoria al global puntero simple cantidades

    // Verificar que se realizaron los espacios de memoria correcpondientes, en caso positivo, retornar 0
    if (!nombresProductos || !cantidades || !precios) {

        printf("Error: No se pudo asignar memoria\n");  
        return 0;

    }

    //asignar memoria a los punteros espacios reservados para las cadenas de char(nombres de los productos)
    for(int i = 0 ; i < 8 ; i++){

        nombresProductos[i] =  (char*) calloc(30,sizeof(char));
        
        if (!nombresProductos[i]) {

            printf("Error: No se pudo asignar memoria\n");  
            return 0;
        
        }
    
    }

    //se coopean los nombres de los productos en los espacios reservados de nombreProductos
    strcpy(nombresProductos[0],"Laptop HP");
    strcpy(nombresProductos[1],"Mouse Inalambrico");
    strcpy(nombresProductos[2],"Teclado Mecanico");
    strcpy(nombresProductos[3],"Memoria USB");
    strcpy(nombresProductos[4],"Luces de Noche");
    strcpy(nombresProductos[5],"Mesa de noche");
    strcpy(nombresProductos[6],"Adaptador OTG");
    strcpy(nombresProductos[7],"Cable ETERNET");

    for(int j = 0 ; j < 8 ; j++ ){

        //reasignar memoria para los arreglos de char de los productos (evitar malgaste de memoria)
        nombresProductos[j] = (char*) realloc (nombresProductos[j],(strlen(nombresProductos[j]) + 1) * sizeof(char));

    }
    
    //se agregan las cantidades
    cantidades [0] = 5;
    cantidades [1] = 8;
    cantidades [2] = 9;
    cantidades [3] = 10;
    cantidades [4] = 4;
    cantidades [5] = 4;
    cantidades [6] = 7;
    cantidades [7] = 8;
    
    //se agregan los precios
    precios [0] = 10000.0;
    precios [1] = 80.0;
    precios [2] = 500.0;
    precios [3] = 150.0;
    precios [4] = 400.0;
    precios [5] = 1100.0;
    precios [6] = 50.0;
    precios [7] = 20.0;
    
    numP = 8; //cambiamos el valor de numP para usarlos despues como indice

    return 1;
}