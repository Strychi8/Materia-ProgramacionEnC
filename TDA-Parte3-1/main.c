#include <stdio.h>
#include <stdlib.h>
#include "vector.c"
#include "matriz.c"

int main(){
  
    printf("\n1) Cargar Vector: \n");
    int tamanio = elegirTamanio();
    int vector[tamanio];
    cargarVectorAleatorio(vector,tamanio);
    
    printf("\n2) Vector: ");
    mostrarVector(vector,tamanio);
    
    printf("\n\n3) Cargando Matriz..... \n");
    int COLUMNAS = 5;
    int matriz[COLUMNAS][RENGLONES];
    cargarMatriz(matriz,COLUMNAS);
    
    printf("\n4) Matriz: \n");
    mostrarMatriz(matriz,COLUMNAS);

    printf("\n\n");
    return 0;
}