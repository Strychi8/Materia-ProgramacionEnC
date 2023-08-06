#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "teatros.h"

struct TeatroE {
   int codigo;
   char nombreT[40];
   char direccion[40];
   int capacidad;
};

void iniciarLosTeatros (Teatro v[], int t){
  int i;
  for (i=0; i<t; i++){
     v[i] = malloc(sizeof(struct TeatroE));
     setCodigo(v[i], -1);
     setNombre (v[i]," ");
     setDireccion (v[i]," ");
     setCapacidad (v[i], -1);
  }
}


void mostrarTeatros (Teatro v[], int t){
   int i;
   for (i=0; i<t; i++){
       if (getCodigo (v[i]) != -1){
            printf ("COD: %d    ",getCodigo (v[i]));
            printf ("NOMBRE: %s    ",getNombreT (v[i]));
            printf ("DIRECCION: %s    ",getDireccion (v[i]));
            printf ("CAP: %d\n",getCapacidad (v[i]));
            printf ("\n");
        }
   }
}

void eliminarTeatro (Teatro v[],int t,int codigo){
   int i;
   for (i=0; i<t; i++){
     if (getCodigo (v[i]) == codigo){
        setCodigo (v[i], -1);
        setNombre (v[i]," ");
        setDireccion (v[i]," ");
        setCapacidad (v[i], -1);
        break;
      }
    }
}

void agregarTeatro (Teatro v[], int t, int cod, char nom[40], char dir[40], int cap){
   int i;
   for (i=0; i<t; i++){
      if (getCodigo (v[i]) == -1){
        setCodigo (v[i],cod);
        setNombre (v[i],nom);
        setDireccion (v[i],dir);
        setCapacidad (v[i],cap);
        break;
       }
    }
}

int getCodigo (Teatro t){
  return t->codigo;
}
char * getNombreT (Teatro t){
  return t->nombreT;
}
char * getDireccion (Teatro t){
  return t->direccion;
}
int getCapacidad (Teatro t){
  return t->capacidad;
}
void setCodigo (Teatro t,int nuevoCodigo){
  t->codigo = nuevoCodigo;
}
void setNombre (Teatro t,char nuevoNombre[40]){
  strcpy (t->nombreT,nuevoNombre);
}
void setDireccion (Teatro t,char nuevaDireccion[40]){
  strcpy (t->direccion,nuevaDireccion);
}
void setCapacidad (Teatro t,int nuevaCapacidad){
  t->capacidad = nuevaCapacidad;
}

void guardarTeatros (Teatro v[], int t){
    FILE * lectura = fopen ("teatro.txt","w");

    for (int i=0; i<t; i++){
         if (getCodigo (v[i]) != -1){
            fprintf (lectura,"%d+%s+%s+%d\n",getCodigo(v[i]),getNombreT (v[i]),getDireccion (v[i]),getCapacidad (v[i]));
         }
    }
    fclose(lectura);
}
