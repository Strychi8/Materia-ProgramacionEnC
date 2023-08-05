#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//2) Devolver 0 si es falso, 1 si es cierto, probarlo en el main, con casos positivos y negativos:
int esBisiesto(int anio);
int sonIguales(char nombre1[], int t, char nombre2[]);
int esMayorDeEdad(int anioNacimiento, int anioHoy);
int esPalindromo(char oracion[], int tam);

int main()
{
    
    int anio;
    printf("\n1) Es Bisiesto? ");
    printf ("Devuelve --> %d \n",esBisiesto(anio));

    int tam = 20;
    char cadena1[tam];
    char cadena2[tam];
    printf("\n2) Son Iguales? ");
    printf ("Devuelve --> %d \n",sonIguales(cadena1, tam, cadena2));

    int anioNacimiento;
    int anioHoy;
    printf("\n3) Es Mayor de Edad? ");
    printf ("Devuelve --> %d \n",esMayorDeEdad (anioNacimiento, anioHoy));

    int tamanio=100;
    char oracion[tamanio];
    printf("\n4) Es Palindromo? ");
    printf ("Devuelve --> %d ",esPalindromo(oracion, tamanio));

    return 0;
}
int esBisiesto(int anio){
    int devolucion;
    printf ("\nIngrese un anio: ");
    scanf ("%d",&anio);

    if (anio%4==0 || anio%100!=0 && anio%400==0){
        devolucion = 1;
    }else {
        devolucion = 0;
    }

    return devolucion;
}
int sonIguales(char nombre1[], int t, char nombre2[]){
     printf ("\nIngrese un nombre: ");
     fflush(stdin);
     gets(nombre1);
     printf ("\nIngrese un segundo nombre: ");
     fflush(stdin);
     gets(nombre2);
     int devolucion;
     int i;

     for (i=0; i<t; i++){
     for(int j=0; j<t; j++){
         if(strcmp(nombre1, nombre2)==0){
          devolucion = 1;
        }else{
          devolucion = 0;
        }
     }
     }

    return devolucion;
}
int esMayorDeEdad(int anioNacimiento, int anioHoy){
    printf ("\nIngrese su anio de nacimiento: ");
    scanf ("%d",&anioNacimiento);
    printf ("\nIngrese el anio actual: ");
    scanf ("%d",&anioHoy);
    int devolucion,resultado;
    resultado = anioHoy - anioNacimiento;

    if (resultado >= 18){
        devolucion = 1;
    }else {
       devolucion = 0;
    }

    return devolucion;
}
int esPalindromo(char oracion[], int tam){
    int devolucion=0;
    int fin=0;
    int inicio=0;
    printf ("\nEscribe una palabra: ");
    fflush(stdin);
    gets(oracion);
    int longitud = strlen(oracion);

    for (fin=longitud-1; oracion[fin]==oracion[inicio] && fin>=0; inicio++,fin--);
    if (inicio==longitud){
        devolucion=1;
    } else {
        devolucion=0;
    }

    return devolucion;
}
