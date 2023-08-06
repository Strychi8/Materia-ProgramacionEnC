#include <stdio.h>
#include <stdlib.h>
#include "persona.c"

int main(){

    printf("\nClase 28-9-2020\n");

    //TDA <----- TIPO DE DATO ABSTRACTO
    Persona persona1 = crearPersonaPorTeclado();
    mostrarPersona(persona1);

    //Persona persona2 = crearPersonaPorTeclado();
    //mostrarPersona(persona2);
    printf("\nNombre: %s", getNombre(persona1));
    setNombre (persona1);
    printf("\nDNI: %d", getDni(persona1));

    //Quiero CAMBIAR/MODIFICAR el dni de la persona 5555
    //MAL
    //getDni(persona1) = 55555;
    //persona1->dni = 5555;

    setDni(persona1, 555555);
    mostrarPersona(persona1);

    setNombre(persona1);
    mostrarPersona(persona1);

    destruirPersona(persona1);

    return 0;
}
