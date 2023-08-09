#include <stdio.h>
#include <stdlib.h>
#include "teatros.c"

int main()
{
    int tam = 100;
    Teatro teatros[tam];
    iniciarLosTeatros(teatros,tam);
    
    printf("\n1) Agrego 4 teatros\n");
    agregarTeatro (teatros,tam,123,"Luna Park","Avenida Corrientes",20000);
    agregarTeatro (teatros,tam,232,"Gran Rex","Avenida Corrientes",20000);
    agregarTeatro (teatros,tam,432,"Teatro Colon","Avenida Corrientes",20000);
    agregarTeatro (teatros,tam,12,"Guimeres","Avenida Corrientes",20000);
    
    printf("\n2) Muestro teatros: \n");
    mostrarTeatros(teatros,tam);
    
    printf("\n3) Elimino un teatro con codigo = 432\n");
    eliminarTeatro(teatros,tam,432);
    
    printf("\n4) Muestro teatros: \n");
    mostrarTeatros(teatros,tam);

    printf("\n5) Guardando teatros en archivo txt...\n");
    guardarTeatros(teatros,tam);

    return 0;
}
