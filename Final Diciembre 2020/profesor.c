#include <stdio.h>
#include <stdlib.h>
#include "profesor.h"
#include <string.h>
#define CANT 10

struct profesorE{
   char nombre[50];
   int sueldo;
   int antiguedad;
   float sueldoFinal;
};

struct materiaE{
   char nombre[50];
   int cantInscriptos;
   Profesor profesores[CANT];
};

Profesor crearProfesor (){
   Profesor p = malloc(sizeof(struct profesorE));

   strcpy(p->nombre," ");
   p->antiguedad = -1;
   p->sueldo = -10;
   p->sueldoFinal = (p->sueldo) + (p->antiguedad+0.1);

  return p;
}

Materia crearMateria(){
   Materia m = malloc(sizeof(struct materiaE));
   char auxNombre[50] = " ";
   printf("\nIngrese el nombre de la Materia: ");
   fflush(stdin);
   gets(auxNombre);
   strcpy(m->nombre,auxNombre);
   printf("Ingrese la cantidad de inscriptos: ");
   scanf("%d",&m->cantInscriptos);

    for(int i=0; i<CANT; i++){
      m->profesores[i] = crearProfesor();
    }

   return m;
}

void mostrarProfesores (Profesor p){
   printf("\n\n------- PROFESOR -----------\n");
   printf("\nNombre: %s",getNombre(p));
   printf("\nAntiguedad: %d",getAntiguedad(p));
   printf("\nSueldo: %.2f",getSueldoFinal(p));
}

void mostrarMateria (Materia m){
   printf("\n---------- MATERIA -------------\n");
   printf ("\nNombre de la materia: %s",m->nombre);
   printf ("\nInscriptos: %d",m->cantInscriptos);

    for (int i=0; i<CANT; i++){
        if(getAntiguedad(m->profesores[i]) != -1){
          mostrarProfesores(m->profesores[i]);
        }
    }
}

void agregarProfesor (Materia m, char nom[50], int suel, int anio){
    for (int i=0; i<CANT; i++){
       if(getAntiguedad(m->profesores[i]) == -1){
          setNombre(m->profesores[i],nom);
          setAntiguedad(m->profesores[i],anio);
          setSueldo(m->profesores[i],suel);
          break;
        }
    }
}

void eliminarProfesor (Materia m, char nom[50]){
    for(int i=0; i<CANT; i++){
        if(strcmp(getNombre(m->profesores[i]),nom) == 0){
          setNombre(m->profesores[i]," ");
          setSueldo(m->profesores[i],-1);
          setAntiguedad(m->profesores[i],-1);
          break;
        }
    }
}

void ordenarProfesoresPorSueldo(Materia m){
   Profesor aux;
   int min;
    for(int i=0; i<CANT; i++){
       min=i;
        for(int j=i+1; j<CANT; j++){
            if(getSueldoFinal(m->profesores[min]) >= getSueldoFinal (m->profesores[j])){
               min = j;
            }
        }
       aux = m->profesores[min];
       m->profesores[min] = m->profesores[i];
       m->profesores[i] = aux;
    }
}

void cargarProfesores (Materia m){
   iniciarMateria(m);
   FILE * lectura = fopen ("archivoProfesores.txt","r");

   int cont = 0;
    while(!feof(lectura)){
      char aux[40] = " ";
      fgets(aux,40,lectura);
      m->profesores[cont] = charAProfesor(aux,40);
      cont++;
    }

   fclose(lectura);

    for(int i=0; i<CANT; i++){
        if(getAntiguedad(m->profesores[i]) != -1){
           printf("%s\n%.2f\n%d\n",getNombre(m->profesores[i]),getSueldoFinal(m->profesores[i]),
           getAntiguedad(m->profesores[i]));
        }
    }
}

void iniciarMateria (Materia m){
  for(int i=0; i<CANT; i++){
     m->profesores[i] = -1;
  }
}

Profesor charAProfesor (char c[], int n){
    Profesor p;
    int posPuntoYComa = 0;
    int posPuntoYComa1 = 0;
    char auxNombre[40] = " ";
    char auxSueldo[40] = " ";
    char auxAntiguedad[40] = " ";

    //busquedaSecuencial(c, n, ';')
    for ( int i = 0; i<n; i++ ){
        if( c[i]== '+'){
            posPuntoYComa = i;
            i=n;
        }
    }

    for (int i=posPuntoYComa+1 ; i<n; i++){
        if(c[i] == '+'){
           posPuntoYComa1 = i;
        }
    }

    for ( int i = 0; i<posPuntoYComa; i++){
       auxNombre[i]= c[i];
       //p.nombre[i] = c[i]; PERFECTO...
    }

    for(int i=posPuntoYComa+1; i<posPuntoYComa1; i++){
        auxSueldo[i-posPuntoYComa-1] = c[i];
    }

    for (int i = posPuntoYComa1+1; i<n ; i++){
        auxAntiguedad[i-posPuntoYComa1 -1]= c[i];
    }

    strcpy(p->nombre, auxNombre);
    p->sueldoFinal = atof(auxSueldo);//int <----char
    p->antiguedad = atoi(auxAntiguedad);
    //char <--- int itoa
    //float <----char   atof

    return p;
};

void guardarProfesores (Materia m){
  FILE * lectura = fopen("archivoProfesores.txt","w");

    for(int i=0; i<CANT; i++){
        if(getAntiguedad(m->profesores[i]) != -1){
          fprintf(lectura,"%s+%.2f+%d\n",getNombre(m->profesores[i]),getSueldoFinal(m->profesores[i]),
          getAntiguedad(m->profesores[i]));
        }
    }

  fclose(lectura);
}

char * getNombre (Profesor p){
   return p->nombre;
}
int getSueldo (Profesor p){
  return p->sueldo;
}
int getAntiguedad (Profesor p){
  return p->antiguedad;
}
float getSueldoFinal (Profesor p){
  return p->sueldoFinal;
}
void setNombre (Profesor p,char nuevoNombre[50]){
    strcpy(p->nombre,nuevoNombre);
}
void setSueldo (Profesor p,int nuevoSueldo){
   p->sueldo = nuevoSueldo;
   p->sueldoFinal = nuevoSueldo + (p->antiguedad+0.1);
}
void setAntiguedad (Profesor p,int nuevoAnio){
   p->antiguedad = nuevoAnio;
   p->sueldoFinal = p->sueldo + (nuevoAnio + 0.1);
}

void fibonacci(int penultimo,int ultimo,int n){
  int actual = 0;

  printf("%d ",ultimo);
  if(n>1){
    actual=penultimo+ultimo;
    fibonacci(ultimo,actual,n-1);
  }

}

int fibo(int n){

  if(n>2){
    return fibo(n-1)+fibo(n-2);
  } else if(n==2){
    return 1;
  } else if(n==1){
    return 1;
  } else if(n==0){
    return 0;
  }

}