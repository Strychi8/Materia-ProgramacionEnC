#include <stdio.h>
#include <stdlib.h>
#include "negocio.c"

int main(){
     
    printf("\n1) Creo un negocio por teclado y lo imprimo:\n");
    Negocio n1 = crearNegocioPorTeclado();
    mostrarNegocio(n1);

    printf("\n\n2) Creo un negocio por parametros y lo imprimo:\n");
    Negocio n2 = crearNegocio("Pollos Hermanos",23,42,'i');
    mostrarNegocio(n2);

    printf("\n\n3) Muestro el menu principal: \n");
    menuOpciones();
    
    printf("\n2) Busqueda Binaria: \n");
    int vectorNumeros[17]={1,2,3,4,7,8,11,13,14,21,22,31,34,45,47,48,49};
    int buscoNumero;
    int posicion = busquedaBinaria (vectorNumeros, 17, buscoNumero);
    printf ("\nLa posicion del numero es: [%d]\n",posicion);

    printf("\n4) Cargo y muestro los dolares: \n");
    Billete dolares[4];
    cargarDolares (dolares, 4);
    mostrarDolares (dolares, 4);
    
    printf("\n5) Ordeno por precio y muestro los dolares: \n");
    ordenarValorDolar (dolares, 4);
    mostrarDolares (dolares, 4);
    
    printf("\n\n");
    return 0;
}