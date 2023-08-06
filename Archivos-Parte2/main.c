#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct EmpleadoE{
   int legajo;
   char nombre[40];
   float sueldo;
};

struct EmpleadoE cargarEmpleado ();
void mostrarEmpleado (struct EmpleadoE e);
//char y cargar empleados en un archivo
struct EmpleadoE charAEmpleado (char c[], int n);
void cargarEmpleados (struct EmpleadoE v[], int n);
//mostrar empleados(plural)
void mostrarEmpleados (struct EmpleadoE v[], int n);
//guardar
void guardarEmpleados (struct EmpleadoE v[], int n);
//agregar y eliminar
struct EmpleadoE agregarEmpleados (struct EmpleadoE v[], int n, struct EmpleadoE e);
void eliminarEmpleados (struct EmpleadoE v[], int n, int legajo);
//buscarPos y buscarLegajo
int buscarPosDisponible (struct EmpleadoE v[], int n);
int buscarLegajo (struct EmpleadoE v[],int t, int legajoBuscado);

int main()
{
   int opcion = 0;
   int cantEmpleados = 100;
   int auxLegajo = 0;
   struct EmpleadoE vectorEmpleados[cantEmpleados];
   struct EmpleadoE e1;

   cargarEmpleados (vectorEmpleados,cantEmpleados);
   mostrarEmpleados (vectorEmpleados,cantEmpleados);

   /*do{
    printf ("\n1-Incorporar Empleados");
    printf ("\n2-Mostrar Empleados");
    printf ("\n3-Despedir Empleados");
    printf ("\n0-Salir\n");
    printf ("\nElija una opcion:\n");
    scanf ("%d",&opcion);

    switch (opcion){

    case 1: e1 = cargarEmpleado ();
            agregarEmpleados (vectorEmpleados,cantEmpleados,e1); break;
    case 2: mostrarEmpleados (vectorEmpleados,cantEmpleados); break;
    case 3: printf ("\nIngrese el legajo de un empleado para despedirlo:\n");
            scanf ("%d",&auxLegajo);
            eliminarEmpleados (vectorEmpleados,cantEmpleados,auxLegajo);break;
    case 0: break;
    default: printf ("\nERROR. Ingreso una opcion no valida\n");
    }

   } while (opcion != 0);

    //mostrarEmpleados (vectorEmpleados,cantEmpleados);
    guardarEmpleados (vectorEmpleados,cantEmpleados);*/

    return 0;
}

struct EmpleadoE cargarEmpleado (){
   struct EmpleadoE e;
   char auxNombre[40] = " ";
   printf ("\nIngrese el legajo: ");
   scanf ("%d",&e.legajo);
   printf ("\nIngrese su nombre: ");
   fflush (stdin);
   gets (auxNombre);
   strcpy (e.nombre,auxNombre);
   printf ("\nIngrese su sueldo: ");
   scanf ("%f",&e.sueldo);

   return e;
};

void mostrarEmpleado (struct EmpleadoE e){
   printf ("\nLegajo: %d",e.legajo);
   printf ("\nNombre del Empleado: %s",e.nombre);
   printf ("\nSueldo: %.2f",e.sueldo);

   printf ("\n");
}

struct EmpleadoE charAEmpleado (char c[], int n){
   int pos = -1;
   int pos1 = -1;
   int i;
   char auxLegajo[40] = " ";
   char auxNombre[40] = " ";
   char auxSueldo[40] = " ";
   struct EmpleadoE e;

   for (i=0; i<n; i++){
      if (c[i] == ';'){
         pos = i;
         i = n;
      }
    }
   for (i=0; i<pos+1; i++){
       if (c[i] == ';'){
        pos1 = i;
       }
    }
   for (i=0; i<pos+1; i++){
       auxLegajo[i] = c[i];
    }
   for (i=pos+1; i<pos1; i++){
      auxNombre[i-pos-1] = c[i];
    }
   for (i=pos1+1; i<n; i++){
      auxSueldo[i-pos1-1] = c[i];
    }

    e.legajo = atoi(auxLegajo);
    strcpy (e.nombre,auxNombre);
    e.sueldo = atof (auxSueldo);

   return e;
};

void mostrarEmpleados (struct EmpleadoE v[], int n){
  int i;
  for (i=0; i<n; i++){
    if (v[i].legajo != -1 && v[i].legajo != 0){
       mostrarEmpleado (v[i]);
    }
  }
  printf ("\n");
}

int buscarPosDisponible (struct EmpleadoE v[], int n){
   int pos = -10;
   for (int i=0; i<n; i++){
        if (v[i].legajo == -1){
           pos = i;
        }
    }

   return pos;
}

void iniciarEmpleados (struct EmpleadoE v[], int n){
   int i;
   for (i=0; i<n; i++){
      v[i].legajo = -1;
      v[i].sueldo = -2;
      strcpy(v[i].nombre," ");
   }
}

void cargarEmpleados (struct EmpleadoE v[], int n){
    iniciarEmpleados (v,n);

    FILE * puntero = fopen ("archivoEmpleados.txt","r");

    while (!feof(puntero)){
       char aux[40] = " ";
       fgets (aux,40,puntero);
       struct EmpleadoE e = charAEmpleado (aux,40);
       agregarEmpleados (v,n,e);
       //guardarEmpleados (v,n);
    }

    fclose(puntero);
}

struct EmpleadoE agregarEmpleados (struct EmpleadoE v[], int n, struct EmpleadoE e){
   int i = buscarPosDisponible (v,n);

    if (i != -10){
       v[i] = e;
    }else {
       printf ("\nYa no hay mas espacio\n");
    }

   return e;
};

void guardarEmpleados (struct EmpleadoE v[], int n){
   FILE * puntero = fopen ("archivoEmpleados.txt","w");

   for (int i=0; i<n; i++){
        if (v[i].legajo != -1 && v[i].legajo != 0){
         fprintf (puntero,"%d;%s;%.2f\n",v[i].legajo,v[i].nombre,v[i].sueldo);
        }
    }

   fclose (puntero);
}

void eliminarEmpleados (struct EmpleadoE v[], int n, int legajo){
   int i = buscarLegajo (v,n,legajo);

   if (i != -1){
      v[i].legajo = -1;
      strcpy (v[i].nombre,"XXX");
      v[i].sueldo = -11;
   }
}

int buscarLegajo (struct EmpleadoE v[], int t, int legajoBuscado){
   int resultado = -1;
   int i;

   for (i=0; i<t; i++){
        if (v[i].legajo == legajoBuscado){
           resultado = i;
        }
    }

   return resultado;
}