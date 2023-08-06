#include <stdio.h>
#include <stdlib.h>
#include "metrogas.c"

int main(){

    printf("\n------------ FINAL MAYO 2021 ---------------\n");

    Usuario u1= crearUsuario(1111,"Brenda Perez");
    Fecha fecha1 = crearFecha(3,2021);
    Factura f1 = crearFactura(120,u1,fecha1);

    Usuario u2= crearUsuario(2222,"Jorge Golfieri");
    Fecha fecha2 = crearFecha(1,2021);
    Factura f2= crearFactura(411,u2,fecha2);

    Usuario u3= crearUsuario(3333,"Alejandra Vranic");
    Fecha fecha3 = crearFecha(5,2021);
    Factura f3= crearFactura(33,u3,fecha3);

    Factura facturas[3] = {f1,f2,f3};
    mostrarFacturas(facturas,3);

    ordenarFacturas(facturas,3);
    mostrarFacturas(facturas,3);

    return 0;
}
