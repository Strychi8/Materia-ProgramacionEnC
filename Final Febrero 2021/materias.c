#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "materias.h"
#define CANT 10

struct EstudianteE{
  char nombre[40];
  int edad;
  Materia materias[CANT];
  //int cont;
};

struct MateriaE{
  int horarioSemanal;
  char profesor[40];
  int inscriptos;
};

Materia crearMateria(int horSem, char profeT[40], int ins){
   Materia m = malloc(sizeof(struct MateriaE));

  //m->horarioSemanal = horSem;
  setHorario(m,horSem);
  setInscriptos(m,ins);
  setProfe(m,profeT);
  //m->inscriptos = ins;
  //strcpy(m->profesor,profeT);

   return m;
}

Estudiante crearEstudiante (char nom[40], int eda){
  Estudiante e = malloc(sizeof(struct EstudianteE));
  //e->cont=0;

  //strcpy(e->nombre,nom);
  //e->edad = eda;
  setNombre(e,nom);
  setEdad(e,eda);

  for(int i=0; i<CANT; i++){
     e->materias[i] = crearMateria(-1," ",-1);
  }
  return e;
}

void agregarMateria(Estudiante e, Materia m){
   for(int i=0; i<CANT; i++){
      if(getInscriptos(e->materias[i]) == -1){
          e->materias[i] = m;
          break;
      }
   }
}

void eliminarMateria(Estudiante e, Materia m){
   for(int i=0; i<CANT; i++){
       if(strcmp(getProfe(e->materias[i]),getProfe(m))==0){
          e->materias[i] = crearMateria(-1," ",-1);
          //destruirMateria(e->materias[i]);
          break;
        } 
    }
}

int getHorario(Materia m){
  return m->horarioSemanal;
}
char * getProfe(Materia m){
  return m->profesor;
}
int getInscriptos(Materia m){
  return m->inscriptos;
}
int getEdad(Estudiante e){
  return e->edad;
}
char * getNombre(Estudiante e){
  return e->nombre;
}
void setHorario(Materia m,int nuevoHorario){
  m->horarioSemanal=nuevoHorario;
}
void setInscriptos(Materia m ,int nuevosInscriptos){
  m->inscriptos=nuevosInscriptos;
}
void setProfe(Materia m,char nuevoProfe[40]){
  strcpy(m->profesor,nuevoProfe);
}
void setEdad (Estudiante e,int nuevaEdad){
  e->edad = nuevaEdad;
}
void setNombre(Estudiante e,char nuevoNombre[40]){
  strcpy(e->nombre,nuevoNombre);
}

void mostrarEstudiante(Estudiante e){
   printf("\n--------- Estudiante --------\n");
   printf("\nNombre: %s",getNombre(e));
   printf("\nEdad: %d",getEdad(e));

   for(int i=0; i<CANT; i++){
      if(getHorario(e->materias[i]) != -1){
        mostrarMateria(e->materias[i]);
      }
   }
}

void mostrarMateria (Materia m){
   printf("\n---------- Materia -----------\n");
   printf("\nTitular: %s",getProfe(m));
   printf("\nAlumnos: %d",getInscriptos(m));
   printf("\nHoras/sem: %d",getHorario(m));
}

void ordenarMateriasPorTitular(Estudiante e){
  Materia aux;
  int i,j;
  for(i=0; i<CANT; i++){
    for(j=0; j<CANT-1; j++){
        if(strcmp(getProfe(e->materias[j]),getProfe(e->materias[j+1]))== 1){
            aux=e->materias[j];
            e->materias[j] = e->materias[j+1];
            e->materias[j+1] = aux;
        }
    }
  }
}

int cantidadDeAlumnos(Estudiante e){
  int i;
  int acum=0;

    for(i=0; i<CANT; i++){
      acum = acum + getInscriptos(e->materias[i]);
    }

  return acum;
}

void guardarEstudiante (Estudiante e){
   FILE * lectura = fopen("archivoEstudiante.txt","w");

   for(int i=0; i<CANT; i++){
       if(getHorario(e->materias[i]) != -1){
          fprintf(lectura,"%d+%s+%d\n",getHorario(e->materias[i]),getProfe(e->materias[i]),
          getInscriptos(e->materias[i]));
        }
    }

   fclose(lectura);
}