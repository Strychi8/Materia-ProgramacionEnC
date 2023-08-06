#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metrogas.h"
#define CANT 10

struct usuarioE{
   char nombreApellido[40];
   int numCuenta;
};

struct fechaE{
   int mes;
   int anio;
};

struct facturaE{
   int total;
   Usuario usuario;
   Fecha fecha;
};

Usuario crearUsuario(int num, char nomApe[40]){
  Usuario a = malloc(sizeof(struct usuarioE));

  setCuenta(a,num);
  setNombreApe(a,nomApe);

  return a;
}
Fecha crearFecha (int m, int a){
  Fecha f = malloc(sizeof(struct fechaE));

  setMes(f,m);
  setAnio(f,a);

  return f;
}
Factura crearFactura (int tot, Usuario u, Fecha fech){
  Factura fac = malloc(sizeof(struct facturaE));
  setConsumo(fac,tot);

  fac->usuario = u;
  fac->fecha = fech;

  return fac;
}
void mostrarFacturas(Factura f[],int t){

    for(int i=0; i<t; i++){
        if(getCuenta(f[i]) != -1){
           printf("\n\nFactura %d",i+1);
           mostrarUsuario(f[i]->usuario);
           mostrarFecha(f[i]->fecha);
           printf("\nConsumo: %d\nTOTAL: ",getConsumo(f[i]));
        }
    }
}
void mostrarUsuario(Usuario a){
    printf("\nCuenta: %d",getCuenta(a));
    printf("\nUsuario: %s",getNomApe(a));
}

void mostrarFecha(Fecha f){
   printf("\nFecha: %d/%d ",getMes(f),getAnio(f));
}
void ordenarFacturas(Factura f[], int t){
   Usuario aux;
   printf("\n\n------- Ordeno las facturas -------");
   for(int i=0; i<t; i++){
    for(int j=0; j<t-1; j++){
        if(strcmp(getNomApe(f[j]),getNomApe(f[j+1]))==1){
            aux=f[j];
            f[j] = f[j+1];
            f[j+1] = aux;
        }
     }
   }
}
int getCuenta (Usuario a){
  return a->numCuenta;
}
char * getNomApe (Usuario a){
  return a->nombreApellido;
}
int getMes(Fecha f){
  return f->mes;
}
int getAnio(Fecha f){
  return f->anio;
}
int getConsumo(Factura fac){
  return fac->total;
}

void setCuenta(Usuario a,int nuevaCuenta){
  a->numCuenta = nuevaCuenta;
}
void setNombreApe(Usuario a,char nuevoNombre[40]){
  strcpy(a->nombreApellido,nuevoNombre);
}
void setMes(Fecha f,int nuevoMes){
  f->mes = nuevoMes;
}
void setAnio(Fecha f,int nuevoAnio){
  f->anio = nuevoAnio;
}
void setConsumo(Factura fac,int nuevoConsumo){
  fac->total = nuevoConsumo;
}