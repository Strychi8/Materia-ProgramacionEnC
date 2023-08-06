#include <stdio.h>
#include <stdlib.h>
#include "materia.h"
#include "persona.h"
#include <string.h>
#define CANT 3

struct MateriaE{
    char nombreM[40];
    //Anidada con personas
    //Persona personas[CANT];
    Persona personas[CANT];
    //int contador
};

Materia crearMateria(char n[40]){
    Materia m = malloc(sizeof (struct MateriaE));

    strcpy(m->nombreM, n);

    for ( int i = 0; i<CANT; i++){
        m->personas[i] = crearPersonaPorTeclado();
    }

    return m;
};

void mostrarMateria(Materia m){
    printf("\n-------- MATERIA -------\n");
    printf("NOMBRE DE MATERIA: %s\n", m->nombreM);

    for ( int i = 0; i<CANT; i++){
       mostrarPersona(m->personas[i]);
    }
}

char *getNombreM (Materia m){
   return m->nombreM;
}

void setNombreM (Materia m, char nuevoNombreMateria){
   strcpy (m->nombreM,nuevoNombreMateria);
}

void destruirMateria(Materia m){
   free(m);
}