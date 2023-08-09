#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vector.h"

//Implementacion o cuerpo de las funciones o procedimientos
int elegirTamanio(){
    int tam = 0;
    printf("Ingrese el tamanio: ");
    scanf("%d", &tam);

    return tam;
}

void cargarVectorAleatorio(int v[], int tam){
   for (int i=0; i<tam; i++){
        //-70 a 100      171 =  MAX - (-70) +1
        v[i] = -70 + rand()%171;
    }
}

void mostrarVector(int v[], int tam){
    for (int i=0; i<tam; i++){
      printf("[%d] ", v[i]);
    }
}

int posMin(int v[], int tam){
    int pos = 0;
    int min = v[0];

    for (int i=0; i<tam; i++){
        if(v[i]<min){
           min = v[i];
           pos = i;
        }
    }

    return pos;
}

int minVector(int v[], int tam){
    int min = v[posMin(v,tam)];

    return min;
}

void sumaVectores(int v[], int w[], int resultado[], int tam){
    for (int i = 0; i <tam; i++){
        resultado[i] = v[i] + w[i];
    }
}

void ordenamientoBurbuja(int v[], int tam){
    int aux;

    for (int i=0; i<tam; i++){
       for(int j=0; j<tam-1; j++){
            if(v[j]>v[j+1]){
                aux = v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
        }
    }
}

void ordenamientoSeleccion(int v[], int tam){
    int min, auxiliar;
    for (int i=0; i<tam; i++){
        min = i;
        for(int j=i+1; j<tam; j++){
           if(v[min]>v[j]){
                min = j;
            } //Cierra el id
        } //Cierra el for

        auxiliar = v[min];
        v[min]= v[i];
        v[i]= auxiliar;
    }//Cierra el for
}

void ordenamientoInsercion(int v[], int tam){
    int i, j, temp;
    for(i=0; i<tam; i++){
        temp=v[i];
        j=i-1;
        while(j>=0 && v[j]>temp){
            v[j+1] = v[j];
            j--;
        }
       v[j+1] = temp;
    }
}

int busquedaSecuencial(int v[], int tam, int buscar){
    int pos = -1;

    for (int i=0; i<tam; i++){
        if (v[i] == buscar){ //Lo encontre
           pos = i;
        }
    }
    // if ( pos == -1){ printf("No lo encontre");}
    return pos;
}

int busquedaBinaria(int v[], int tam, int buscar){
    int sup = 0 ;
    int inf =0;
    int centro = 0;
    sup = tam -1;

    while(inf <= sup){
       centro = (sup + inf ) /2;
        if(v[centro] == buscar){
            return centro;
        } else{ 
            if(buscar < v[centro]){
               inf = centro +1;
            } else { 
               sup = centro -1;
            }
        }
    }

    return -1;
}

int aleatorioEntre(int mini, int maxi){
    //mini = 8, maxi = 20
    int resultado = 0;

    resultado = mini + rand()%(maxi - mini +1);

    return resultado;
}

void cargarVectorConAleatorios(int v[], int tam, int mini, int maxi){
    for (int i = 0; i<tam; i++){
       v[i] = aleatorioEntre(mini, maxi);
    }
}

void cargarVectorConAleatoriosSinRepetir(int v[], int tam, int mini, int maxi){
     int numeroNuevo = 0;
     int resultadoBusqueda = 0 ;

    for (int i=0; i<tam; i++){
       do{
          numeroNuevo = aleatorioEntre(mini, maxi);
          resultadoBusqueda = busquedaSecuencial(v, tam, numeroNuevo); //nos da la posicion ---> -1
        }while (resultadoBusqueda!=-1);

        v[i] = numeroNuevo;
    }
}