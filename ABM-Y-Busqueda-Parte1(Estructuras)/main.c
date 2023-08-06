#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANTJUGADORES 3

struct Jugador{
   char nombreYApellido[30];
   int dni;
   float altura;
};

struct Equipo{
   char nombreEquipo[30];
   struct Jugador plantel[CANTJUGADORES];
   int jugadoresAgregados;
};

struct Equipo cargarEquipo();
void mostrarEquipo (struct Equipo equipo);
struct Jugador cargarJugador();
void cargarJugadores (struct Jugador v[], int t);
void mostrarJugador (struct Jugador j);
void mostrarJugadores (struct Jugador v[], int t);
int busquedaDeJugador (struct Jugador v[], int t, int dniBuscado);
struct Equipo agregarJugador (struct Equipo e, struct Jugador j);
struct Equipo eliminarJugador (struct Equipo e, int dni);
struct Equipo modificarJugador (struct Equipo e, int dni);

int main()
{
    //struct Jugador arrayJugadores[CANTJUGADORES];
    struct Equipo e1;
    e1 = cargarEquipo();

    struct Jugador j1,j2,j3,j4;
    j1 = cargarJugador();
    j2 = cargarJugador();
    j3 = cargarJugador();
    j4 = cargarJugador();
    e1 = agregarJugador(e1,j1);
    e1 = agregarJugador(e1,j2);
    e1 = agregarJugador(e1,j3);
    e1 = agregarJugador(e1,j4);
    printf("\n1) Muestro el equipo: ");
    mostrarEquipo(e1);
    
    printf("\n2) Muestro el equipo y elimino a un jugador: ");
    e1 = eliminarJugador (e1, 2);
    //e1 = modificarJugador (e1, 3);
    mostrarEquipo (e1);

    //printf ("\n\nEstoy buscando al dni 2 ----> %d",busquedaDeJugador(arrayJugadores, CANTJUGADORES, 2));

    return 0;
}
void cargarJugadores (struct Jugador v[], int t){
    int i;
    char nombreAux[30]= " ";
    for (i=0; i<t; i++){
        printf("\nJugador %d",i+1);
        printf ("\nIngrese su nombre y apellido: ");
        fflush (stdin);
        gets (nombreAux);
        strcpy (v[i].nombreYApellido, nombreAux);
        printf ("Ingrese su DNI: ");
        scanf ("%d",&v[i].dni);
        printf ("Ingrese su altura: ");
        scanf ("%f",&v[i].altura);
    }
}
struct Jugador cargarJugador(){
    struct Jugador j;
    char nombreAux[30]= " ";
    printf ("\nIngrese su nombre y apellido: ");
    fflush (stdin);
    gets (nombreAux);
    strcpy (j.nombreYApellido,nombreAux);
    printf ("Ingrese su DNI: ");
    scanf ("%d",&j.dni);
    printf ("Ingrese su altura: ");
    scanf ("%f",&j.altura);

    return j;
};
void mostrarJugador (struct Jugador j){
   printf ("\nNombre y apellido: %s\nDNI: %d\nAltura: %.2f\n",j.nombreYApellido,
           j.dni,j.altura);
}
void mostrarJugadores (struct Jugador v[], int t){
    int i;
    for (i=0; i<t; i++){
        if (v[i].dni != -1){
           mostrarJugador(v[i]);
        }
    }
}
struct Equipo cargarEquipo(){
    struct Equipo e;
    e.jugadoresAgregados = 0;
    char nombreAux[30]= " ";
    printf ("\nIngrese el nombre del Equipo: ");
    fflush (stdin);
    gets(nombreAux);
    strcpy(e.nombreEquipo,nombreAux);

    //cargarJugadores (e.plantel, CANTJUGADORES);

    for (int i=0; i<CANTJUGADORES; i++){
        e.plantel[i].dni = -1;
        e.plantel[i].altura = -10;
        strcpy (e.plantel[i].nombreYApellido, "XXI");
    }

    return e;
};
void mostrarEquipo (struct Equipo equipo){
    printf ("\nPlantel del Equipo:\n");
    printf ("\nNombre: %s\n",equipo.nombreEquipo);
    mostrarJugadores (equipo.plantel,CANTJUGADORES);
    //mostrarJugadores (equipo.plantel,equipo.jugadoresAgregados);
}
int busquedaDeJugador (struct Jugador v[], int t, int dniBuscado){
   int i;
   int resultado = -1;
   for (i=0; i<t; i++){
    if (v[i].dni == dniBuscado){
        resultado = i;
    }
   }
   return resultado;
}
struct Equipo agregarJugador (struct Equipo e, struct Jugador j){
    int i = e.jugadoresAgregados;
    e.plantel[i] = j;
    e.jugadoresAgregados = e.jugadoresAgregados + 1;

    return e;
};
struct Equipo eliminarJugador (struct Equipo e, int dni){
    int i = busquedaDeJugador(e.plantel, CANTJUGADORES, dni);

    if (i!=-1){
    e.plantel[i].dni = -1;
    e.plantel[i].altura = -10;
    strcpy (e.plantel[i].nombreYApellido,"XXI");
    }
    //ordenarPorDni (e.plantel, CANTJUGADORES)
    //e.jugadoresAgregados = e.jugadoresAgregados-1;
    return e;
};
struct Equipo modificarJugador (struct Equipo e, int dni){
    int i = busquedaDeJugador (e.plantel, CANTJUGADORES, dni);

    if (i!=-1){
        e.plantel[i] = cargarJugador();
        //case 1: modificar nombre
        //case 2: modificar dni
        //e.plantel[i].dni = dniAux;
        //printf ---- scanf ---- dniAux

    }
    return e;
};
