#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fechaYPersona.c"

int main()
{
    printf("\n1) Cargo fechas.....\n");
    Fecha fecha1 = cargarFecha();
    mostrarFecha (fecha1);

    Fecha fecha2 = cargarFechaPorParametros (20,6,2012);
    mostrarFecha (fecha2);

    Fecha fecha3 = cargarFechaPorTeclado ();
    printf("\n2) Muestro las fechas: ");
    printf ("\nDia: %d\nMes: %d\nAnio: %d\n",getDia(fecha3),getMes(fecha3),getAnio(fecha3));
    
    printf("\n3) Cargo persona por teclado: \n");
    Persona persona1 = cargarPersona();
    Persona persona2 = cargarPersona ();

    printf("\n\n4) Muestro las 2 personas por pantalla: ");
    printf ("\nEdad: %d\nDNI: %d\n",getEdad(persona1),getDni(persona1));
    printf ("\nEdad: %d\nDNI: %d",getEdad(persona2),getDni(persona2));
    
    printf("\n\n5) Modificando persona1 y persona2....\n");
    setEdad (persona1,17);
    setDni (persona2,32456783);

    //printf ("\n---- Nueva Edad ----\n");
    //printf ("\nEdad: %d\n",getEdad(persona1));
    
    printf("\n6) Muestro las 2 personas por pantalla: ");
    mostrarPersona (persona1);
    mostrarPersona (persona2);
    
    printf("\n7) Liberando los datos de las 2 personas.....\n");
    destruirPersona (persona1);
    destruirPersona (persona2);

    return 0;
}
