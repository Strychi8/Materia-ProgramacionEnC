#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"

void cargarMatriz(int m[][RENGLONES], int c){
    for (int i=0; i<RENGLONES; i++){
        for (int j=0; j<c; j++){
            m[j][i] = rand()%10;
        }
    }
}

void  mostrarMatriz(int m[][RENGLONES], int c){
    for (int i=0; i<RENGLONES; i++){
        for (int j=0; j<c; j++){
            printf("[%d] ", m[j][i]) ;
        }
        printf("\n");
    }
}

void sumarPorRenglones(int m[][RENGLONES], int c, int v[]){
    for (int i=0; i<RENGLONES; i++){
        //iniciar vector en cero
        v[i] = 0 ;
        for (int j=0; j<c; j++){
            //SUMA = SUMA +NUMERO
            v[i] = v[i] + m[j][i];
        }
    }
}