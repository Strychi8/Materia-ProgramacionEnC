#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Fecha {
    int dia;
    int mes;
    int anio;
};
struct Alumno {
    char nombre[40];
    char genero;
    int anio;
    float altura;
    struct Fecha fechaNac;
};// se declara solo las variables, no se puede inicializar ni poner printf-scanf
struct Vehiculo{
    char patente[7];
    int anio;
    char color[15];
    int precio;
};

void mostrarAlumno (struct Alumno a);
struct Alumno cargarAlumnoPorTeclado ();
struct Alumno cargarAlumno (char n[40], char g, float h, int anio);
//EJERCICIO 1 (VEHICULOS)
void cargarVehiculos (struct Vehiculo v[], int t);
void mostrarVehiculos (struct Vehiculo v[], int t);
void ordenarVehiculoPorPatente (struct Vehiculo v[], int t);
int validarPatente (char p[]);

//ESTRUCTURAS: muchos datos *DE DISTINTOS TIPOS*

int main(){

    struct Alumno alumno1;
    struct Alumno alumno2; //En este momento hay basura
    //alumno1.nombre = "Tomas"; //Me mostrara basura, se tendra que usar strcpy
    //alumno1.altura = 1.67;
    //alumno1.genero = 'M';
    //alumno1.anio = 2020;
    //strcpy (alumno1.nombre,"Tomas");

    alumno1 = cargarAlumnoPorTeclado ();
    alumno2 = cargarAlumno ("Nestor", 'm', 5.43f, 2020);
    mostrarAlumno (alumno1);
    mostrarAlumno (alumno2);

    int tam = 2;
    struct Vehiculo vehiculos[tam];

    cargarVehiculos (vehiculos,tam);
    mostrarVehiculos (vehiculos,tam);

    ordenarVehiculoPorPatente (vehiculos,tam);
    mostrarVehiculos (vehiculos,tam);

    printf ("\n\n");
    return 0;
}
struct Alumno cargarAlumnoPorTeclado (){
     struct Alumno a;
     char aux [40]= "";
     printf ("\nIngrese su nombre: ");
     fflush (stdin);
     gets (aux);
     strcpy (a.nombre,aux);
     //gets (a.nombre); basura
     printf ("Ingrese su genero: ");
     scanf ("%c",&a.genero);
     printf ("Ingrese su altura: ");
     scanf ("%f",&a.altura);
     printf ("Ingrese el anio de Ingreso: ");
     scanf ("%d",&a.anio);

     return a;
};
struct Alumno cargarAlumno (char n[40],char g, float h,int anio){
    struct Alumno a;

    strcpy (a.nombre,n);
    a.genero = g;
    a.altura = h;
    a.anio = anio;

    return a;

};
void mostrarAlumno (struct Alumno a){
    printf ("\nNombre: %s",a.nombre);
    printf ("\nGenero: %c",a.genero);
    printf ("\nAltura: %f",a.altura);
    printf ("\nAnio de Ingreso: %d\n",a.anio);
}
void cargarVehiculos (struct Vehiculo v[], int t){
    char patenteAux[7]= " ";
    char colorAux[15]= " ";
    int i;
    for (i=0; i<t; i++){
    printf ("\nIngrese la patente: ");
    fflush (stdin);
    gets (patenteAux);
    strcpy (v[i].patente,patenteAux);
    printf ("\nEsta patente devolvera ----> %d\n",validarPatente(v[i].patente));

    printf ("\nIngrese el color del vehiculo: ");
    fflush (stdin);
    gets (colorAux);
    strcpy (v[i].color,colorAux);
    printf ("Ingrese el precio: ");
    scanf ("%d",&v[i].precio);
    printf ("Ingrese el anio que lo compro: ");
    scanf ("%d",&v[i].anio);
    }
}
void mostrarVehiculos (struct Vehiculo v[],int t){
     int i;
     for (i=0;i<t;i++){
         printf ("\n\nDatos del Vehiculo %d",i+1);
         printf ("\nLa patente es ----> %s ",v[i].patente);
         printf ("\nEl anio de creacion es ----> %d ",v[i].anio);
         printf ("\nEl color del vehiculo es ----> %s ",v[i].color);
         printf ("\nEl precio que tiene es ----> %d ",v[i].precio);
     }

}
void ordenarVehiculoPorPatente (struct Vehiculo v[],int t){
     struct Vehiculo vehiculoAux;
     int i,j;
     printf ("\n\n------- Ordenamiento por Patente -------");
     for (i=0; i<t; i++){
        for (j=0; j<t-1; j++){
            if (strcmp(v[j].patente, v[j+1].patente)==1){
                vehiculoAux = v[j];
                v[j] = v[j+1];
                v[j+1] = vehiculoAux;
            }
        }
     }
}
int validarPatente (char p[]){
   int devolucion = -1;
   int longitud = strlen(p);

   if (longitud == 7){
         if ((isdigit(p[0])) || (isdigit(p[1])) ||  (!isdigit(p[2])) ||
           (!isdigit(p[3])) || (!isdigit(p[4])) || (isdigit(p[5])) || (isdigit(p[6]))){

            printf ("\nERROR: La patente que ingreso es invalida\n");
            devolucion = 0;
         }
    } else if (longitud == 6){
         if ((!isdigit(p[0])) || (!isdigit(p[1])) ||  (!isdigit(p[2])) ||
            (isdigit(p[3])) || (isdigit(p[4])) || (isdigit(p[5]))){

            printf ("\nERROR: La patente que ingreso es invalida\n");
            devolucion = 0;
         }
     } else {
        printf ("\nERROR: La patente que ingreso es incorrecta\n");
     }
     return devolucion;
}

