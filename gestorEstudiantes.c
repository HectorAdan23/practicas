#include <stdio.h>
#include <string.h>

typedef struct {

    char nombre[50];			//Definimos struct para almacenar la informacion de cada estudiante
    int matricula;
    double calificaciones[4];
    double promedio;

} Estudiante;

//funciones principales
void capturarEstudiante(Estudiante *est);

int main(){
    Estudiante grupo[3];	//para 3 estudiantes, no mas
		
	printf("=== SISTEMA DE GESTIÓN ACADÉMICA ===\n");
	
	// Capturar datos de 3 estudiantes
	for(int i = 0; i < 3; i++) {

		printf("\nEstudiante %d:\n", i+1);		//Almanea todos los datos de los estudiantes llamando a las funciones del bucle
		capturarEstudiante(&grupo[i]);
		
	
	}
	
	
	printf("\n=== LISTA COMPLETA DE ESTUDIANTES ===\n");
	
	// Mostrar todos los estudiantes
	
	
	// Encontrar el mejor promedio
	int mejorIndex = 0;
	
	//Todo lo siguiente solo sirve para encontrar el promedio mas alto de entre los estudiantes ingresados
	if(grupo[0].promedio < grupo[1].promedio){
		
		if(grupo[2].promedio < grupo[1].promedio){

			mejorIndex = 1;		//El estudiante 2 e quien tiene mejor promedio

		}else{
			mejorIndex = 2;		//EL estudiante 3 es quien tiene mejor oromedio

		}
	}else{
		
		if(grupo[2].promedio < grupo[0].promedio){

			mejorIndex = 0;		//El estudiante 1 es quien tiene mejor promedio

		}else{

			mejorIndex = 2;		//El estudiante 3 es quien tiene mejor promedio;

		}
	}

	printf("\n=== ESTUDIANTE CON MEJOR PROMEDIO ===\n");	//Se imprime el nombre y promedio del mejor puntaje
	printf("Nombre: %s\n", grupo[mejorIndex].nombre);
	printf("Promedio: %.2f\n", grupo[mejorIndex].promedio);
	
	return 0;
}