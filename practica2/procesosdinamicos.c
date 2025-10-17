#include <stdio.h>
#include <stdlib.h>


void main(){

    printf("=== Calculadora de Promedio Dinámica ===\n\n");
    int opcion = 0;         //Entero: Denomina el caso que se realizara en la funcion switch
    double *calif;          //Puntero: Servira con ayuda de las funciones calloc y realloc
    int score;              //Entero: Calificaciones que quiera ingresar el usuario
    
    int num_prac = 0;       
    //Entero: Apoyara con *calif para hacer operaciones con el valor guardado en el mismo puntero *calif

    int P_num = 1;          
    //Entero: Apoya en las impresiones, contabilizando el numero de calificaciones de
    //practicas ingresadas y cuando sacamos promedio del total con prom".

    double suma = 0.0;              //Acumulador para todas las calificaciones ingresadas
    double prom = 0.0;              //promedio de las calificaciones ingresadas
    char opcion_case1;              //opcion para ingresar o no mas calificaciones
    int longitudcalif = 0;          //Lleva el numero total de calificaiones ingresadas

    while(opcion != 2){
        printf("1) Ingresar calificaciones\n");
        printf("2) Salir\n");                               //Menu principal al inicio de la ejecucion del C
        printf("Seleccione una opcion: ");                  //Seleccionar una opcion
        scanf("%i",&opcion);
        printf("===============================\n\n");

        switch(opcion){
        case 1:
            
            //El usuario ingreso 1inicia a ingresar calificaciones

            printf("Cuantas calificaciones desea agregar: ");
            scanf("%d",&score);

            calif = (double*) calloc(score,sizeof(double));  
            //Almacena memoria dinamica en *calif con espacios de double
            
            if(calif == NULL){                                  

                printf("\nEl puntero *calif no apunta a nada");     //Se verifica que calif no apunte al vacio
                return;
            }

            for(int i = 0;i < score;i++){

                printf("\nIngresa la calificacion de la practica que sea <= 0, pero >= 10");        //mientras i no sea igual a score
                printf("\nIngresa la calificacion de la practica %d: ",P_num);                      //ingreda otra calificaion
                scanf("%lf",calif + num_prac);

                if((*(calif + num_prac) < 0.0) || (*(calif + num_prac) > 10.0)){

                    while((*(calif + num_prac) < 0.0) || (*(calif + num_prac) > 10.0)){
                            
                        printf("\nCalificacion no valida, vuelva a intentar");
                        printf("\nIngresa la calificacion de la practica que sea <= 0, pero >= 10");    //Si calificaion no cumple la
                        printf("\nIngresa la calificacion de la practica %d: ",P_num);                  //condicion del parametro
                        scanf("%lf",calif + num_prac);                                                  //insistir agregar calificacion 
                                                                                                        //con las condiciones correctas 
                    }
                        

                }

                num_prac++;         //se suman 1 a su total hasta ahora las veces que se repita el ciclo for
                P_num++;
            }
                
                
                
            printf("\n=== Desea agregar mas calificaciones de practicas ===\n\n");
            printf("s)Agregar mas\n");                                          //Segundo menu    
            printf("n)No agregar mas \n");                                      //Desea agregar mas calificaciones
            printf("Seleccione una opcion: ");                                  
            scanf(" %c",&opcion_case1);

            if(((opcion_case1 != 's') && (opcion_case1 != 'S')) && ((opcion_case1 != 'n') && (opcion_case1 != 'N'))){
                    
                while(((opcion_case1 != 's') && (opcion_case1 != 'S')) && ((opcion_case1 != 'n') && (opcion_case1 != 'N'))){
                
                    printf("\nCaracter no valido");
                    printf("\n=== Desea agragar mas calificaciones de practicas ===");
                    printf("\ns)Agregar mas");                      //Si opcion_case1 no cumple el parametro
                    printf("\nn)No agregar mas");                   //insistir una opcion correcta
                    printf("Seleccione una opcion: ");              
                    scanf("%c",&opcion_case1);
                
                }
            } 
                

            if((opcion_case1 == 's') || (opcion_case1 == 'S')){

                int temp = 0;                           //Checar si opcion_case1 es 'S' p 's'
                int j;                                  //si es verdad, continua agregando calificaciones

                while((opcion_case1 == 's') || (opcion_case1 == 'S')){
                    
                    printf("\nCuantas calificaciones mas desea agregar: ");     
                    scanf("%d",&temp);                                          
                                                            //Se agrega cuantas calificaiones se desea agregar
                    j = score;                              //y se prepara para 'score' y 'j' para ingresar mas
                    score += temp;

                    calif = (double*) realloc(calif,score * sizeof(double));    //Se cambia el espacio de la memoria dinamica a la necesidad del usuario

                    if(calif == NULL){

                        printf("\nEl puntero *calif no apunta a nada");     //Por seguridad, se vuelve a checar que no apunte a nada calif
                        return;
                    }

                    for(j; j < score ;j++){

                        printf("\nIngresa la calificacion de la practica que sea <= 0, pero >= 10");    //Se empieza a agregar mas calificaciones
                        printf("\nIngresa la calificacion de la practica %d: ",P_num);
                        scanf("%lf",calif + num_prac);

                        if((*(calif + num_prac) < 0.0) || (*(calif + num_prac) > 10.0)){

                            while(*(calif + num_prac) < 0.0 || *(calif + num_prac) > 10.0){
                                    
                                printf("\nCalificacion no valida, vuelva a intentar");
                                printf("\nIngresa la calificacion de la practica que sea <= 0, pero >= 10");    //Si la calificacion no cumple el parametro
                                printf("\nIngresa la calificacion de la practica %d: ",P_num);                  //insistir en ingresar calificaciones correctas
                                scanf("%lf",calif + num_prac);                                                  //que cumplan las carecteristicas dadas

                            }
                
                        }  
                        
                        num_prac++;     //Se suma 1 a su total hasta ahora las veces que se repita el ciclo for
                        P_num++;
                    }

                    printf("\n=== Desea agragar mas calificaciones de practicas ===");
                    printf("\ns)Agregar mas");
                    printf("\nn)No agregar mas\n");            //Se pregunta por ultima vez si el usuario quiera agregar mas calificaciones
                    printf("Seleccione una opcion: ");         //En el caso de no, termina el while para empezar a calcular el promedio de todas
                    scanf(" %c",&opcion_case1);                //las calificaciones ingresadas hasta este punto

                    if(((opcion_case1 != 's') && (opcion_case1 != 'S')) && ((opcion_case1 != 'n') && (opcion_case1 != 'N'))){

                        while(((opcion_case1 != 's') && (opcion_case1 != 'S')) && ((opcion_case1 != 'n') && (opcion_case1 != 'N'))){
                
                            printf("\nCaracter no valido");
                            printf("\n=== Desea agragar mas calificaciones de practicas ===");      //Se checa por ultima vez que opcion_case1 cumple
                            printf("\ns)Agregar mas");                                              //el parametro, de lo contrario se insistira que
                            printf("\nn)No agregar mas\n");                                         //se de una opcion correcta
                            printf("Seleccione una opcion: ");
                            scanf("%c",&opcion_case1);
                            
                        }
                    }
                }
            }

            for(int k = 0;k < score; k++){
                                                //Aqui se termina el while y se empieza a calcular
                suma += *(calif + k);           //suma que incrementara su valor segun k sea menor a la cantidad 
                longitudcalif++;                //de calificaciones ingresadas, tambien se obtiene el valor 
            }                                   //de longitud para obtener las calificaciones ingresadas en otra variable.

            prom = suma / longitudcalif;        //Se obtiene el promedio
            P_num--;                            //Se resta 1 para evitar que la impresion denote una practica mas que el usuario ingreso

            printf("\nEl promedio de las %d ingresadas es de : %.2f ",P_num,prom);

            if(prom > 7.0){

                printf("\nSituacion del estudiante: APROVADO");
                
            }                                                           //Si el promedio es mayor a 7, el dueño de las calificaiones
            else{                                                       //aprovara o no la asignatura
                    
                printf("\nSituacion del estudiante: NO APROVADO");
                
            }
            printf("\n\n===================================\n\n");
            
            free(calif);

            opcion = 0;                     //Se devuelve todos los valores a sus respectivos estados
            score = 0;                      //de inicio para volver a utilizar el menu y el programa
            num_prac = 0;                   
            P_num = 1;
            suma = 0.0;
            prom = 0.0;
            opcion_case1 = 'n';
            longitudcalif = 0;


            break;
            
        case 2:

            //mensaje de despedida
            printf("\nMemoria liberada!!! Hasta luego.\n");
            
            break;

        default:
            //opcion del usuario invalida
            printf("\n=== Opcion invalida === \nPor favor seleccione una opcion del menu:\n");
        }
    
    }


}


