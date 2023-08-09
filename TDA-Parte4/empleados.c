#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"
#define CANT 10

struct EmpleadosE{
  char nombre[40];
  char apellido[40];
  int edad;
  int sueldo;
  int sueldoEdad;
};

struct EmpresaE{
  char nombreEmpresa[40];
  char direccion[40];
  int telefono;
  char rubro[40];
  Empleado empleados[CANT];
};

Empleado crearEmpleado(){
   Empleado e = malloc(sizeof(struct EmpleadosE));

   strcpy(e->nombre," ");
   strcpy(e->apellido," ");
   e->edad = -1;
   e->sueldo = -10;
   e->sueldoEdad = ((e->sueldo) + (e->edad*30));

   return e;
}

void mostrarEmpleado(Empleado e){
    printf ("\nNombre: %s",e->nombre);
    printf ("\nApellido: %s",e->apellido);
    printf ("\nEdad: %d",e->edad);
    printf ("\nSueldo: %d",e->sueldo);
    printf("\nSueldo final: %d\n",e->sueldoEdad);
}

Empresa crearEmpresa(){
  Empresa e = malloc(sizeof(struct EmpresaE));
  char auxNombre[40] = " ";
  char auxDireccion[40] = " ";
  char auxRubro[40] = " ";

  printf("\nIngrese el nombre de la Empresa: ");
  fflush(stdin);
  gets(auxNombre);
  strcpy(e->nombreEmpresa,auxNombre);
  printf("Ingrese la direccion: ");
  fflush(stdin);
  gets(auxDireccion);
  strcpy(e->direccion,auxDireccion);
  printf ("Ingrese el telefono: ");
  scanf("%d",&e->telefono);
  printf("Ingrese el rubro: ");
  fflush(stdin);
  gets(auxRubro);
  strcpy(e->rubro,auxRubro);

  for(int i=0; i<CANT; i++){
    //setNombre(e->empleados[i]->nombre," ");
    //setApellido(e->empleados[i]->apellido," ");
    //setEdad(e->empleados[i]->edad,-1);
    //setSueldo(e->empleados[i]->sueldo,-10);
    e->empleados[i] = crearEmpleado();
  }

  return e;
}

void mostrarEmpresa (Empresa e){
  printf ("\n\n------- Empresa ---------\n");
  printf("\nNombre: %s",e->nombreEmpresa);
  printf ("\nDireccion: %s",e->direccion);
  printf ("\nTelefono: %d",e->telefono);
  printf ("\nRubro: %s",e->rubro);

  printf ("\n\n------- Empleados --------\n");
  for(int i=0; i<CANT; i++){
    if(getEdad(e->empleados[i]) != -1){
      mostrarEmpleado(e->empleados[i]);
    }
  }
}

char * getNombre (Empleado e){
  return e->nombre;
}
char * getApellido (Empleado e){
  return e->apellido;
}
int getEdad (Empleado e){
  return e->edad;
}
int getSueldo (Empleado e){
  return e->sueldo;
}
int getEdadSueldo (Empleado e){
  return e->sueldoEdad;
}

void setNombre (Empleado e, char nuevoNombre[40]){
  strcpy(e->nombre,nuevoNombre);
}
void setApellido (Empleado e, char nuevoApellido[40]){
  strcpy(e->apellido,nuevoApellido);
}
void setEdad (Empleado e, int nuevaEdad){
  e->edad = nuevaEdad;
  e->sueldoEdad =((e->sueldo)+(nuevaEdad*30));
}
void setSueldo (Empleado e, int nuevoSueldo){
  e->sueldo = nuevoSueldo;
  e->sueldoEdad =(nuevoSueldo + (e->edad*30));
}

void agregarEmpleado (Empresa e, char nom[40], char ape[40], int eda, int sueld){
   for(int i=0; i<CANT; i++){
     if(getEdad(e->empleados[i]) == -1){
        setNombre(e->empleados[i],nom);
         setApellido(e->empleados[i],ape);
         setEdad(e->empleados[i],eda);
         setSueldo(e->empleados[i],sueld);
         break;
     }
   }
}

void eliminarEmpleado (Empresa e, char ape[40]){
  int i;
  for(i=0; i<CANT; i++){
    if(strcmp(getApellido(e->empleados[i]),ape)==0){
         setNombre(e->empleados[i]," ");
         setApellido(e->empleados[i]," ");
         setEdad(e->empleados[i],-1);
         setSueldo(e->empleados[i],-10);
    }
  }
}

void modificarEmpleado (Empresa e, char ape[40]){
  printf("\n----- MODIFICANDO ------");
  for(int i=0; i<CANT; i++){
     if(getEdad(e->empleados[i]) != -1){
         setApellido(e->empleados[i],"Fernandez");
         setEdad(e->empleados[i],29);
         setNombre(e->empleados[i],"Sebastian");
         break;
     }
  }
}

void ordenarEmpleadosPorSeleccion(Empresa e){
  Empleado aux;
  int i,j,min;
    for(i=0; i<CANT; i++){
        min=i;
        for(j=i+1; j<CANT; j++){
            if(getEdadSueldo(e->empleados[min]) <= getEdadSueldo(e->empleados[j])){
               min = j;
            }
        }
        aux = e->empleados[min];
        e->empleados[min] = e->empleados[i];
        e->empleados[i] = aux;
    }
}

void ordenarEmpleadosPorInsercion (Empresa e){
  Empleado aux;
  int n;
    for (int i=0; i<CANT; i++){
       aux = e->empleados[i];
       n = i;
        while (n>0){
            if (strcmp(getApellido(e->empleados[n]),getApellido(e->empleados[n-1])) == -1){
                e->empleados[n]=e->empleados[n-1];
                e->empleados[n-1]=aux;
                n=n-1;
            }else {
                n=0;
            }
        }
    }
}

void guardarEmpleados (Empresa e){
   FILE * lectura = fopen("archivoEmpleados.txt","w");

   for(int i=0; i<CANT; i++){
        if(getEdad(e->empleados[i]) != -1){
            fprintf(lectura,"%s+%s+%d+%d+%d\n",getNombre(e->empleados[i]),getApellido(e->empleados[i]),
            getEdad(e->empleados[i]),getSueldo(e->empleados[i]),getEdadSueldo(e->empleados[i]));
        }   
    }

   fclose(lectura);
}