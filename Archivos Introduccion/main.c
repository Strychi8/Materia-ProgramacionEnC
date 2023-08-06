#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Persona{
   char nombre[30];
   int dni;
};

struct Persona charAPersona(char c[], int n);

int main(){

    printf("\nPersistencia de datos!\n");

    //Guardar los datos ----> Bases de datos (2do anio en adelante)
    //-----------------------> Archivos ( lo vamos a ver)
    //-----------------------> Archivos binarios (101010010101)
    //--------- :) ----------> Archivos de Texto  (Nico es el profe)
    //WORD, EXCEL Y BLOC DE NOTAS

    //Que cosas haces con un archivo (ESCRIBIRLO ---- LEERLO)

    //Escribir ----- Leer ---------->>> printf -------- scanf/gets

    //Escribir un archivo!!!!!!!!!!!!
    printf("\n1) Escribir en un archivo(vaya a archivo1.txt)\n");
    //1) Abrir el archivo
    FILE * puntero;
    /*char nombreApellido = " ";
    int dni = 42999222;
    float puntaje = 20*0.5;*/

    puntero = fopen("archivo1.txt", "a");

    //2)Escribir
    fprintf(puntero, "\nPuntaje del Jugador: %.2f\nNombre y Apellido: %s\nDNI: %d\n",20*0.5,"Santiago Veliz",42999222);

    //3) Cerrar
    fclose(puntero);

    //Lectura
    //1) Abrir el archivo
    printf("\n2) Para leer un archivo: \n");
    FILE * puntero1 = fopen("archivo2.txt", "r");

    //2)Leer
    while (!feof(puntero1)){
       char aux[40] = " ";
       //No hace falta el fflush
       fgets(aux, 40 ,puntero1); //Busca un \n
       printf("------>>>> %s", aux);
    }

    //3) Cerrar
    fclose(puntero1);

    //Para guardar TODOS los datos del archivo
    //tengo que usar un array
    printf("\n\n3) Para leer un archivo(configurado): \n");
    struct Persona personas[4];
    int contadorPersonas = 0;

    //Lectura
    //1) Abrir el archivo
    FILE * puntero2 = fopen("archivo2.txt", "r");

    //2)Leer

    while (!feof(puntero2)){
       char aux[40] = " ";
       //No hace falta el fflush
       fgets(aux, 40 ,puntero2); //Busca un \n

       //Persona <------ aux CHAR
       personas[contadorPersonas]  = charAPersona(aux, 40);

       contadorPersonas++;
    }

    //3) Cerrar
    fclose(puntero2);

    for (int i = 0; i<4; i++){
         printf("Nombre y Apellido: %s --- DNI: %d\n", personas[i].nombre, personas[i].dni );
    }

    return 0;
}

struct Persona charAPersona(char c[], int n){
    struct Persona p;
    int posPuntoYComa = 0;

    //busquedaSecuencial(c, n, ';')
    for ( int i = 0; i<n; i++ ){
        if( c[i]== ';'){
            posPuntoYComa = i;
        }
    }

    char auxNombre[40] = " ";
    char auxDni[40] = " ";

    for ( int i = 0; i<posPuntoYComa; i++){
        auxNombre[i]= c[i];
        //p.nombre[i] = c[i]; PERFECTO...
    }

    for ( int i = posPuntoYComa+1; i<n ; i++){
        auxDni[i-posPuntoYComa -1]= c[i];
    }

    strcpy(p.nombre, auxNombre);
    p.dni = atoi(auxDni);//int <----char
    //char <--- int itoa
    //float <----char   atof

    return p;
};