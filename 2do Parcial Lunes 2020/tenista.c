#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tenista.h"

struct tenistaE{
   int edad;
   int ranking;
   char nombre[40];
   float altura;
   char manoHabil[40];
};

void iniciarTenistas(Tenista v[], int t){
   for(int i=0; i<t; i++){
      v[i] = malloc(sizeof(struct tenistaE));
      setEdad(v[i],-1);
      setRanking(v[i],-1);
      setAltura(v[i],-1);
      setNombre(v[i]," ");
      setManoHabil(v[i]," ");
   }
}

void mostrarTenistas(Tenista v[], int t){
   for(int i=0; i<t; i++){
       if(getRanking(v[i]) != -1){
          printf("\n------ Tenista ------\n");
          printf("Rank: %d\n",getRanking(v[i]));
          printf("Nombre: %s\n",getNombre(v[i]));
          printf("Edad: %d\n",getEdad(v[i]));
          printf("Altura: %.2f\n",getAltura(v[i]));
          printf("Golpe: %s\n",getManoHabil(v[i]));
        }
   }
}

void cargarTenistas(Tenista v[], int t){
   FILE * lectura=fopen("rank.txt","r");//genero un puntero a un archivo
   //abro el archivo con r
   int cont = 0;

   while(!feof(lectura)){//mientras no encuentre un \0 no termina el archivo
      char aux[40] = " ";
      fgets(aux,40,lectura);
      //printf("----> %s",aux);
      v[cont]= pasarDeCharAStruct(aux,40);
      cont++;
    }

   fclose(lectura);
}

Tenista pasarDeCharAStruct(char delimitador[], int fin){
   //formato: ranking+nombre-edad*altura/mano habil
   //Declaro las posiciones donde se guardan los delimitadores
   int pos1 = 0;
   int pos2 = 0;
   int pos3 = 0;
   int pos4 = 0;

   char auxRanking[40] = " ";
   char auxNombre[40] = " ";
   char auxEdad[40] = " ";
   char auxAltura[40] = " ";
   char auxManoHabil[40] = " ";

    //Empiezo la busqueda de los separadores
    for(int i=0; i<fin; i++){
        if(delimitador[i] == '+'){
            pos1=i;
            //i=fin;
        }
    }
    for(int i=pos1+1; i<fin; i++){
        if(delimitador[i] == '-'){
            pos2=i;
            //i=fin;
        }
    }
    for(int i=pos2+1; i<fin; i++){
        if(delimitador[i] == '*'){
            pos3=i;
            //i=fin;
        }
    }
    for(int i=pos3+1; i<fin; i++){
        if(delimitador[i] == '/'){
            pos4=i;
        }
    }
   //Empiezo a leer el ranking
   for(int i=0; i<pos1; i++){
      auxRanking[i] = delimitador[i];
   }
   //Empiezo a leer el nombre
   for(int i=pos1+1; i<pos2; i++){
      auxNombre[i-pos1-1] = delimitador[i];
   }
   //Lectura de la edad
   for(int i=pos2+1; i<pos3; i++){
      auxEdad[i-pos2-1] = delimitador[i];
   }
   //Lectura de la altura
   for(int i=pos3+1; i<pos4; i++){
      auxAltura[i-pos3-1] = delimitador[i];
   }
   //Por ultimo,lectura de la mano habil
   for(int i=pos4+1; i<fin; i++){
      auxManoHabil[i-pos4-1] = delimitador[i];
   }

   Tenista t = malloc(sizeof(struct tenistaE));

   t->ranking = atoi(auxRanking);//ranking
   strcpy(t->nombre,auxNombre);//nombre
   t->edad = atoi(auxEdad);//edad
   t->altura = atof(auxAltura);//altura
   //Separo el DERECHO del ZURDO
   //Compruebo que si es D, el resultado es 0, por lo tanto hago que el string
   //diga DERECHO por el contrario si es diferente de 0 es ZURDO
   int result = strncmp(auxManoHabil,"D", 1);
   if(result == 0){
     setManoHabil(t,"DERECHO");
   }else{
     setManoHabil(t,"ZURDO");
   }

   return t;
}

int getEdad(Tenista t){
 return t->edad;
}
int getRanking(Tenista t){
 return t->ranking;
}
char*getNombre(Tenista t){
 return t->nombre;
}
char*getManoHabil(Tenista t){
 return t->manoHabil;
}
float getAltura(Tenista t){
 return t->altura;
}

void setEdad(Tenista t, int nuevaEdad){
  t->edad=nuevaEdad;
}
void setRanking(Tenista t, int nuevoRanking){
  t->ranking=nuevoRanking;
}
void setAltura(Tenista t, float nuevaAltura){
  t->altura=nuevaAltura;
}
void setNombre(Tenista t, char nuevoNombre[40]){
  strcpy(t->nombre,nuevoNombre);
}
void setManoHabil(Tenista t, char nuevaManoHabil[40]){
  strcpy(t->manoHabil,nuevaManoHabil);
}

void ordenarTenistas(Tenista v[], int t){
  Tenista aux;

  //METODO BURBUJA
   for(int i=0; i<t; i++){
       for(int j=0; j<t-1; j++){
           if(getEdad(v[j]) >= getEdad(v[j+1])){
              aux = v[j];
              v[j] = v[j+1];
              v[j+1] = aux;
            }
        }
    }
}
