#include <stdio.h>
#include <stdlib.h>
#include "profesor.c"

int main()
{
    printf("\n0) Cargo la materia...\n");
    Materia m1 = crearMateria();

    //cargarProfesores(m1);
    printf("\n1) Agrego los siguientes profesores e imprimo la materia...\n");
    agregarProfesor (m1,"Carlos Olmedo",20000,10);
    agregarProfesor (m1,"Alberto Velez",20000,3);
    agregarProfesor (m1,"Lautaro Vazquez",20000,20);
    agregarProfesor (m1,"Leonardo Espinazola",20000,30);
    mostrarMateria (m1);

    eliminarProfesor (m1,"Leonardo Espinazola");

    printf("\n\n2) Ordeno a los profesores por sueldo e imprimo: \n");
    ordenarProfesoresPorSueldo(m1);
    mostrarMateria(m1);
    
    printf("\n\n3) Guardando los datos en archivoProfesores.txt....");
    guardarProfesores(m1);

    printf("\n\n");
    //fibonacci(0,1,10);

    printf("\n");
    printf("4) Sucesion de Fibonacci: \n");
    for(int num=0; num<10; num++){
        printf("%d = %d\n",fibo(num),num);
    }

    printf("\n\n");
    return 0;
}