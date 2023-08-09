#include <stdio.h>
#include <stdlib.h>
#include "tenista.c"
#define TAM 20

int main(){

    Tenista tenistas[TAM];//array de tenistas
    iniciarTenistas(tenistas,TAM);//inicio todas las posiciones vacias con -1 o " "
    
    printf("\n1) Cargo y muestro los tenistas: \n");
    cargarTenistas(tenistas,TAM);//se carga en el array los tenistas del txt
    mostrarTenistas(tenistas,TAM);//muestro a los tenistas cargados
    
    printf("\n2) Ordeno y muestro los tenistas: \n");
    ordenarTenistas(tenistas,TAM);//ordeno a los tenistas por edad, de menor a mayor
    mostrarTenistas(tenistas,TAM);//muestro a los tenistas ordenados por edad

    return 0;
}