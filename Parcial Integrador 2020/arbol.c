#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"

struct ArbolE {
    char nombreE[40];
    int edad;
    float altura;
};

void iniciarArboles (Arbol a[], int t){
   for(int i=0; i<t; i++){
      a[i] = malloc(sizeof(struct ArbolE));
      setNombre(a[i]," ");
      setEdad(a[i],-1);
      setAltura(a[i],-1);
   }
}

void mostrarArboles(Arbol a[], int t){
   for(int i=0; i<t; i++){
       if(getAltura(a[i]) != -1){
          printf("\n----- Arbol %d -----",i+1);
          printf("\nEspecie: %s",getNombre(a[i]));
          printf("\nEdad: %d",getEdad(a[i]));
          printf("\nAltura: %.2f",getAltura(a[i]));
       }
   }
}

void agregarArbol(Arbol a[], int t, char nom[40], int eda, float alt){
   for(int i=0; i<t; i++){
      if(getAltura(a[i]) == -1){
        setNombre(a[i],nom);
        setEdad(a[i],eda);
        setAltura(a[i],alt);
        break;
      }
   }
}

int buscarPorEspecie(Arbol a[], int t, char nom[40]){
  for(int i=0; i<t; i++){
    if(strcmp(getNombre(a[i]),nom)==0){
        return i;
    }
  }
}

void modificarArbol(Arbol a[], int t, char nom[40]){
    int i=buscarPorEspecie(a,t,nom);
    printf("\nModificando arbol %s\n",nom);
    printf("\nIngrese la nueva edad: ");
    scanf("%d",&a[i]->edad);
    printf("Ingrese la nueva altura: ");
    scanf("%f",&a[i]->altura);
}

void eliminarArbol(Arbol a[], int t, char nom[40]){
    for(int i=0; i<t; i++){
        if(strcmp(getNombre(a[i]),nom)==0){
            setNombre(a[i]," ");
            setEdad(a[i],-1);
            setAltura(a[i],-1);
            break;
        }
    }
}

void cargarArboles(Arbol a[], int t){
   FILE * lectura = fopen("arboles.txt","r");

   int cont = 0;

   while(!feof(lectura)){
      char aux[40] = " ";
      fgets(aux,40,lectura);
      a[cont] = charAStruct(aux,40);
      cont++;
    } 

   fclose(lectura);
}

void guardarArboles (Arbol a[], int t){
   FILE * lectura = fopen("arboles.txt","w");

   for(int i=0; i<t; i++){
       if(getAltura(a[i]) != -1){
          fprintf(lectura,"%s+%d+%.2f\n",getNombre(a[i]),getEdad(a[i]),getAltura(a[i]));
        }
    }

   fclose(lectura);
}

Arbol charAStruct(char delimitador[], int fin){
   //formato: especie + edad + altura
   char auxNombre[40] = " ";
   char auxEdad[40] = " ";
   char auxAltura[40] = " ";

   int pos1 = 0;
   int pos2 = 0;

   for(int i=0; i<fin; i++){
     if(delimitador[i] == '+'){
        pos1=i;
        i=fin;
     }
   }
   for(int i=pos1+1; i<fin; i++){
     if(delimitador[i] == '+'){
        pos2=i;
     }
   }
   for(int i=0; i<pos1; i++){
      auxNombre[i] = delimitador[i];
   }
   for(int i=pos1+1; i<pos2; i++){
      auxEdad[i-pos1-1] = delimitador[i];
   }
   for(int i=pos2+1; i<fin; i++){
      auxAltura[i-pos2-1] = delimitador[i];
   }
   Arbol arbol = malloc(sizeof(struct ArbolE));
   strcpy(arbol->nombreE,auxNombre);
   arbol->edad = atoi(auxEdad);
   arbol->altura = atof(auxAltura);

   return arbol;
}

char * getNombre(Arbol a){
  return a->nombreE;
}
int getEdad (Arbol a){
  return a->edad;
}
float getAltura (Arbol a){
  return a->altura;
}

void setNombre(Arbol a,char nuevoNombre[40]){
  strcpy(a->nombreE,nuevoNombre);
}
void setEdad(Arbol a,int nuevaEdad){
  a->edad = nuevaEdad;
}
void setAltura(Arbol a,float nuevaAltura){
  a->altura = nuevaAltura;
}