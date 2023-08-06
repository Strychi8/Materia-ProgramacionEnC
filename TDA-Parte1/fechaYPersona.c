#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fechaYPersona.h"

struct FechaE{
  int dia;
  int mes;
  int anio;
  char formatoFecha[40];
};
//Axiomas: se crea la estructura PersonaE
//edad no puede ser menor o igual a 0
//dni no puede ser menor o igual a 0
struct PersonaE{
  int edad;
  int dni;
  float dniEdad;
};

Persona cargarPersona (){
  Persona p = malloc(sizeof(struct PersonaE));
  
  printf ("\nPersona: ");
  printf ("\nIngrese su edad: ");
  scanf ("%d",&p->edad);
  printf ("Ingrese su DNI: ");
  scanf ("%d",&p->dni);

  p->dniEdad = (p->dni) - ((p->edad)*2);

  return p;
}

void mostrarPersona (Persona p){
  printf ("\nPersona: ");
  printf ("\nEdad: %d\nDNI: %d\nDniEdad: %f\n",p->edad,p->dni,p->dniEdad);
}

Fecha cargarFecha(){
   struct FechaE * f = malloc(sizeof(struct FechaE));

   f->dia=20;
   f->mes=5;
   f->anio=2020;

   return f;
}

void mostrarFecha (Fecha f){
  printf("\nFecha: ");
  printf ("\nDia: %d\nMes: %d\nAnio: %d\n",f->dia,f->mes,f->anio);
}

Fecha cargarFechaPorParametros (int d, int m, int a){
  Fecha f = malloc(sizeof(struct FechaE));

  f->dia = d;
  f->mes = m;
  f->anio = a;

  return f;
}

Fecha cargarFechaPorTeclado (){
  Fecha f = malloc(sizeof(struct FechaE));
  printf ("\nIngrese el dia: ");
  scanf ("%d",&f->dia);
  printf ("Ingrese el mes: ");
  scanf ("%d",&f->mes);
  printf ("Ingrese el anio: ");
  scanf ("%d",&f->anio);

  return f;
}

int getDia (Fecha f){
  return f->dia;
}
int getMes (Fecha f){
  return f->mes;
}
int getAnio (Fecha f){
  return f->anio;
}
void setDia (Fecha f,int nuevoDia){
  f->dia = nuevoDia;
}
void setMes (Fecha f,int nuevoMes){
  f->mes = nuevoMes;
}
void setAnio (Fecha f,int nuevoAnio){
  f->anio = nuevoAnio;
}
int getEdad (Persona p){
  return p->edad;
}
int getDni (Persona p){
  return p->dni;
}
float getDniEdad (Persona p){
  return p->dniEdad;
}
void setEdad (Persona p,int nuevaEdad){
  p->edad = nuevaEdad;
  p->dniEdad = (p->dni) - (nuevaEdad*2);
}
void setDni (Persona p,int nuevoDni){
  p->dni = nuevoDni;
  p->dniEdad = nuevoDni - ((p->edad)*2);
}
void destruirPersona(Persona p){
  free(p);
}