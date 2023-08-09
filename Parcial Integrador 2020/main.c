#include <stdio.h>
#include <stdlib.h>
#include "arbol.c"
#define CANTARBOLES 100

int main(){

    Arbol arbol[CANTARBOLES];
    iniciarArboles(arbol,CANTARBOLES);
    printf("\n1) Cargando los arboles.......");
    cargarArboles(arbol,CANTARBOLES);
    
    printf("\n\n2) Agrego y muestro los arboles agregados:\n");
    agregarArbol(arbol,CANTARBOLES,"Laurel",210,2.55);
    agregarArbol(arbol,CANTARBOLES,"Secuoya Caucho",150,1.99);
    agregarArbol(arbol,CANTARBOLES,"Gikgo biloba",90,1.88);
    mostrarArboles(arbol,CANTARBOLES);
    
    printf("\n\n3) Modifico un arbol y muestro los arboles:\n");
    modificarArbol(arbol,CANTARBOLES,"Laurel");
    mostrarArboles(arbol,CANTARBOLES);
    
    printf("\n\n4) Elimino 2 arboles y muestro todos los arboles:\n");
    eliminarArbol (arbol,CANTARBOLES,"Cocotero");
    eliminarArbol (arbol,CANTARBOLES,"Falsa Acacia");
    mostrarArboles(arbol,CANTARBOLES);

    printf("\n\n5) Guardando en arboles.txt.......");
    guardarArboles(arbol,CANTARBOLES);
    
    printf("\n\n");
    return 0;
}