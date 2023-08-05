#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){

    /*Tema 1: Se pide crear un programa en el cual el usuario puede elegir el tamaño del vector
    de numeros flotantes con el que vamos a trabajar. Una vez elegido el tamaño del vector se
    pide crear una carga por teclado de este, impidiendo que el usuario ingrese numeros
    negativos. Luego el programa debe entrar a un menu que permite 1-Mostar el maximo,
    2-Mostrar el promedio,0-Salir y mostrar todo el array*/
    printf("\nTema 1\n");
    int i,n,opcion;

    printf ("\nIngrese el tamanio del vector: \n");
    scanf ("%d",&n);

    float vector[n];

    //CARGO EL VECTOR
    for (i=0; i<n; i++){
        printf ("\nIngrese los numeros para cargar el vector: \n",i);
        scanf ("%f",&vector[i]);
        while (vector[i]<0){
            printf ("\nPor favor ingrese otro numero que no sea negativo\n");
            scanf ("%f",&vector[i]);
        }
    }
    float maximo = vector[0];

    for (i=0; i<n; i++){
        if (vector[i]>maximo){
            maximo=vector[i];
        }
    }
    float suma=0;
    float prom=0;

    for (i=0; i<n; i++){
        suma = suma + vector[i];
    }
    prom = suma/n;

    do{
        printf ("\n1-Mostrar Maximo");
        printf ("\n2-Mostrar Promedio");
        printf ("\n0-Salir y Mostrar todo el array");
        printf ("\n\nIngrese una opcion: ");
        scanf ("%d",&opcion);

        switch (opcion){
        case 1: printf ("\nEl numero maximo es --------> %f\n",maximo); break;
        case 2: printf ("\nEl promedio es ---------> %f\n",prom); break;
        case 0: break;
        default: printf ("\nERROR: Opcion no valida\n");
        }

    } while (opcion!=0);
    printf("\nArray: ");
    for (i=0; i<n; i++){
        printf ("[%.2f] ",vector[i]);
    }
    printf ("\n");

   /* Tema 2: Generar un programa en el cual el usuario puede elegir el tamaño del vector de 
   numeros enteros. Una vez elegido el tamaño del vector se pide crear una carga aleatoria
   de este. Luego el programa debe entrar a un menu que permite 1-Mostrar la cantidad
   de pares,2-Mostrar el promedio,0-Salir y mostrar todo el array invertido.*/
    printf("\nTema 2\n");
    srand(time(0));

    int n1;
    int contPar=0;
    float suma1=0;
    float prom1=0;
    int opcion1;

    printf ("\nPor favor ingrese el tamanio del vector: \n");
    scanf ("%d",&n1);

    int vector1[n1];

    for (i=0; i<n1; i++){
        vector1[i] = rand()%100;//Cargo aleatoriamente el vector

    }

    for (i=0; i<n1; i++){
        if (vector1[i]%2 == 0){
            contPar = contPar + 1;//Contador para saber la cantidad de numeros pares
        }
    }
    for (i=0; i<n1; i++){
        suma1 = suma1 + vector1[i];
    }
    prom = suma1/n1;//Calculo el promedio de la suma de los numeros

    do{
      printf ("\n1-Mostrar la cantidad de pares");
      printf ("\n2-Mostrar el promedio");
      printf ("\n0-Salir y mostrar el array invertido");
      printf ("\nIngrese una opcion: ");
      scanf ("%d",&opcion1);

    switch (opcion1){
      case 1: printf ("\nLa cantidad de numeros pares que hay son -----> %d\n",contPar); break;
      case 2: printf ("\nEl promedio total es ----> %.2f\n",prom); break;
      case 0: break;
      default: printf ("\nERROR. Esa opcion no es valida\n"); break;
    }
    } while (opcion1!=0);
    printf("\nEl array invertido es: ");
    for (i=n1-1; i>=0; i--){
        printf ("[%d] ",vector1[i]);
    }
    printf ("\n");

    /*Tema 3: Se pide crear un menu con las siguiente opciones 1-Cargar un array de 5 numeros
    enteros aleatorios,2-Mostrar el array,3-Mostrar el maximo y el minimo del array,
    4-Mostrar de forma invertida los numeros pares del array,0-Salir y mostrar todo el array.*/
    printf("\n\nTema 3\n");
    srand(time(0));

    int opcion2;
    int vector2[5];
    int maximo1 = vector2[0];
    int minimo = vector2[0];

    printf ("\n---------------------MENU---------------------------\n");

    do{
        printf ("\n1-Cargar un array de 5 numeros enteros aleatorios");
        printf ("\n2-Mostrar el array");
        printf ("\n3-Mostrar el maximo y el minimo del array");
        printf ("\n4-Mostrar de forma invertida los numeros pares del array");
        printf ("\n0-Salir y mostrar todo el array");
        printf ("\n\nIngrese una opcion: ");
        scanf ("%d",&opcion2);

        switch (opcion2){
        case 1:
            printf("\nMuestro los numeros aleatorios: ");
            for (i=0; i<5; i++){
                vector2[i] = rand()%30;
                printf ("[%d] ",vector2[i]);//GENERO Y MUESTRO LOS NUMEROS ALEATORIOS
            }
            break;
        case 2:
            printf("\nSe muestra el array: ");
            for (i=0; i<5; i++){
                printf ("[%d] ",vector2[i]);//MUESTRO EL ARRAY
            }
            break;
        case 3:
            maximo1 = vector2[0];
            minimo = vector2[0];

            for (i=0; i<5; i++){
                if (vector2[i]<minimo){//CALCULO EL MINIMO
                    minimo = vector2[i];
                }
            }

            for (i=0; i<5; i++){
                if (vector2[i]>maximo1){ //CALCULO EL MAXIMO
                    maximo1 = vector2[i];
                }
            }
            //MUESTRO EL MAXIMO Y EL MINIMO POR PANTALLA
            printf ("\nEl maximo es --------> %d\n",maximo1);
            printf ("\nEl minimo es ---------> %d\n",minimo);
            break;
        case 4:
            printf("\nForma invertida de los numeros pares: ");
            for (i=5-1; i>=0; i--){
                if (vector2[i]%2 == 0){ //CALCULO LOS NUMEROS PARES
                    printf ("[%d] ",vector2[i]);
                }
            }
            break;
        case 0:
            break;
        default: printf ("\nERROR: Esa opcion no es valida\n");//SI INGRESA OTRA OPCION SE MUESTRA ESTE MSJ
        }
    } while (opcion2!=0);

    printf("\nArray: ");
    for (i=0; i<5; i++){
        printf ("[%d] ",vector2[i]); //DESPUES DE SALIR DEL MENU SE MOSTRARA
    }                               //EL ARRAY POR PANTALLA

    return 0;
}