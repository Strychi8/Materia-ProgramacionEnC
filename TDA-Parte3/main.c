#include <stdio.h>
#include <stdlib.h>
#include "vectorYMatriz.c"

int main(){
    
    Ejemplo e1 = cargarEjemplo();
    mostrarEjemplo(e1);

    //Recorro el vector con el get
    printf("\n3) Recorro el vector con el get: ");
    for(int i = 0 ; i<5; i++){
        printf("[%d]  ", getVector(e1)[i]);
    }

    //La matriz se accede con posiciones consecutivas
    //Esto lo pueden mejorar con int* getMatrizColuma1(Ejemple e){ return e->matriz[1]}

    //En el peor de los casos si no les gusta y no se quieren quedar con eso
    //pueden definir en el .h a la matriz y listo, evitan el get.

    printf("\n\n4) Recorro la  matriz con el get: \n");

    for(int i = 0 ; i<(4*3); i++){
        printf("[%d]  ", getMatriz(e1)[i]);
    }
    
    printf("\n\n");
    return 0;
}