#include <stdio.h>
#include <stdlib.h>
#include "materias.c"

int main(){

    printf("\n1) Crear y agregar materias a estudiante: \n");

    Materia m1 = crearMateria (4,"Jorge G",90);
    Materia m2 = crearMateria (8,"Federico R",56);
    Materia m3 = crearMateria (6,"Roberto G",105);
    Materia m4 = crearMateria (4,"Edgardo D",75);

    Estudiante e1 = crearEstudiante("Estudiante 1",23);
    agregarMateria(e1,m1);
    agregarMateria(e1,m2);
    agregarMateria(e1,m3);
    agregarMateria(e1,m4);
    mostrarEstudiante(e1);

    printf("\n\n2) Mostrar estudiante con materias ordenadas por titular:\n");
    ordenarMateriasPorTitular(e1);
    mostrarEstudiante(e1);

    printf("\n\n3) Mostrar cantidad de alumnos:\n");
    printf("\nLa cantidad de alumnos que cursan junto al estudiante: %d",cantidadDeAlumnos(e1));

    printf("\n\n4) Elimino una materia e imprimo: \n");
    eliminarMateria(e1,m3);
    mostrarEstudiante(e1);
    
    printf("\n\n5) Guardando datos en archivoEstudiante.txt.....");
    guardarEstudiante(e1);
    
    printf("\n\n");
    return 0;
}