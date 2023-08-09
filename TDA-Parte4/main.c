#include <stdio.h>
#include <stdlib.h>
#include "empleados.c"

int main()
{   
    printf("\n0) Cargo la Empresa:\n");
    Empresa e1 = crearEmpresa();
    
    printf("\n1) Agrego e imprimo por pantalla la empresa y sus empleados: ");
    agregarEmpleado(e1,"Nicolas","Nietzche",20,50000);
    agregarEmpleado(e1,"Leandro","Carioca",34,50000);
    agregarEmpleado(e1,"Pedro","Velazco",25,50000);
    agregarEmpleado(e1,"Tomas","Sanchez",35,50000);
    mostrarEmpresa(e1);
    
    printf ("\n\n2) Elimino al empleado con apellido = 'Sanchez' e imprimo: ");
    eliminarEmpleado(e1,"Sanchez");
    mostrarEmpresa(e1);

    printf ("\n\n3) Ordeno por apellido y muestro la Empresa: ");
    //ordenarEmpleadosPorSeleccion(e1);
    ordenarEmpleadosPorInsercion(e1);
    //modificarEmpleado(e1,"Nietzche");
    mostrarEmpresa(e1);
    
    printf ("\n\n4) Guardando los datos en archivoEmpleados.txt..... ");
    guardarEmpleados(e1);

    printf("\n\n");
    return 0;
}