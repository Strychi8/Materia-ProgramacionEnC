#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.c"
#include "materia.c"

int main(){

    printf("\nClase 2-10-2020\n");
    
    printf("\n1) Creo 2 personas y las muestro por pantalla: ");
    Persona p1 = crearPersonaPorTeclado();
    //Persona p1 = crearPersona("Nico", 111, 1.87, 92.7);
    mostrarPersona(p1);

    Persona p2 = crearPersona("Edu", 2222, 1.77, 77.7);
    mostrarPersona(p2);

    //p2->altura  :( No se puede entrar a esos datos
    //printf("\n----> DNI P1: %d", getDni(p1));
    //p1->dni = 21312; :( no se puede editar...
    
    printf("\n2) Seteo por nombre y peso a la persona 1: \n");
    setNombre(p1, "Luz");
    setPeso(p1, 63.9);
    mostrarPersona(p1);

    /*Array de Persona
    int cantidad = 3;
    Persona personas[cantidad];

    for ( int i = 0; i<cantidad; i++){
        //personas[i] = crearPersonaPorTeclado();
    }

    for ( int i = 0; i<cantidad; i++){
        mostrarPersona(personas[i]);
    }*/
    
    printf("\n3) Cargo a 3 personas para la materia = Programacion: \n");
    Materia m1 = crearMateria("Programacion");
    printf("\n4) Muestro la materia y a las personas que asisten a esa materia: \n");
    mostrarMateria(m1);
    destruirMateria (m1);

    return 0;
}