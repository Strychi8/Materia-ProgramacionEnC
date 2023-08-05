#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Pre: El tamaño tiene que ser mayor a 0
//Post: Sera el tamaño del vector
int elegirTamanio();
float pedirNumero();
//VECTORES
void cargarVector (float v[], int t);
void cargarVectorAleatorio (float v[], int t);
//ALGORITMO DE ORDENAMIENTO
void ordenamientoBurbuja (float v[], int t);
//ALGORITMO DE BUSQUEDA
//PRE: El vector tiene que estar cargado y ORDENADO
//POST: Devuelve un entero que es la POSICION del dato buscado SI LO ENCONTRO
//Cuando no lo encuentra nos da "-1"
float busquedaBinaria (float v[], int t, int dato);
int buscarEnVector (float v[], int t, int busco);
void mostrarVector (float v[], int t);

int main()
{
    srand(time(0));
    int tam=0;
    float vec[tam];
    float buscoNumero;
    int posicion;
    int opcion;

    printf (" --------------- Menu Principal ---------------\n");
    do{
        printf ("\n1) Elegir tamanio del Vector");
        printf ("\n2) Cargar Vector a mano");
        printf ("\n3) Cargar Vector aleatorio");
        printf ("\n4) Mostrar Vector");
        printf ("\n5) Ordenar Vector por burbujeo");
        printf ("\n6) Ingrese un numero para ver si esta o no en el vector");
        printf ("\n7) Salir del menu\n");
        printf ("\nEliga una opcion: ");
        scanf ("%d",&opcion);

      switch (opcion){

        case 1: tam = elegirTamanio(); break;

        case 2: cargarVector (vec, tam); break;

        case 3: cargarVectorAleatorio (vec, tam); break;

        case 4: mostrarVector (vec, tam); break;

        case 5: ordenamientoBurbuja (vec, tam); break;
      
        case 6: posicion = buscarEnVector (vec, tam ,buscoNumero);
        printf ("\nSu numero esta en la posicion %d ",posicion); break;

        case 7: break;

        default: printf ("\nERROR: Opcion no valida\n");
      }
    } while (opcion!=7);
    
    //NO SE IMPLEMENTA LA BUSQUEDA BINARIA, LA IMPLEMENTACION SE ENCUENTRA ABAJO
    
    printf ("\n");
    return 0;
}

int elegirTamanio(){
    int tamanio;
    printf ("\nEliga el tamanio para su vector: ");
    scanf ("%d",&tamanio);

    return tamanio;
}

float pedirNumero(){
   float num;
   printf ("\nEscriba un numero: ");
   scanf ("%f",&num);

   return num;
}

void cargarVector (float v[], int t){
    int i;
    for (i=0; i<t; i++){
        printf ("\nEliga un numero en la posicion %d: ",i+1);
        scanf ("%f",&v[i]);
    }
}

void cargarVectorAleatorio (float v[], int t){
     int i;
     for (i=0; i<t; i++){
        v[i] = rand()%11;
     }
}

void ordenamientoBurbuja (float v[], int t){
     int i,j;
     int aux;

     for (i=0; i<t; i++){
        for (j=0; j<t-1; j++){
            if (v[j] >= v[j+1]){
            aux = v[j];
            v[j] = v[j+1];
            v[j+1] = aux;
         }
        }
      }
}

int buscarEnVector (float v[], int t, int busco){
    int pos = -1;
    busco = pedirNumero();
    int i;

    for (i=0; i<t; i++){
        if (v[i] == busco){
            pos = i;
            printf ("\nSu numero fue encontrado\n");
        }
    }
    if (pos == -1){
         printf ("\nSu numero NO fue encontrado\n");
    }
    return pos;
}

void mostrarVector (float v[], int t){
     int i;
     printf("\nVector: ");
     for (i=0; i<t; i++){
        printf ("[%.2f] ",v[i]);
     }
     printf ("\n");
}

float busquedaBinaria (float v[], int t, int dato){
    int posInicial=0;
    int posFinal=0;
    int posCentro=0;
    posFinal = t-1;

    while (posInicial <= posFinal){
        posCentro = (posInicial + posFinal)/2;
        if (v[posCentro] == dato){
            return posCentro;
        } else {
           if (dato > v[posCentro]){
            posInicial = posCentro+1;
           } else {
             posFinal = posCentro-1;
           }
        }
    }
    return -1;
}
