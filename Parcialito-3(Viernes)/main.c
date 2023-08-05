#include <stdio.h>
#include <stdlib.h>

void cargarVector (float vector[], int tamanio);
void mostrarVector (float vector[], int tamanio);
int posicionMaximo (float vector[], int tamanio);
int mostrarPosMin (float vector[],int tamanio);
float promedioVector (float vector[], int tamanio);

int main(){
    
    printf("\nTEMA 2: ");
    int opcion;
    int tam = 8;
    int auxiliar = 0;
    float vec1[tam];

    do{
        printf ("\n1) Cargar un vector de 8 flotantes por teclado");
        printf ("\n2) Mostrar el vector");
        printf ("\n3) Ver la posicion del maximo vector");
        printf ("\n4) Mostrar el promedio");
        printf ("\n5) Salir");
        printf ("\n\nIngrese una opcion: ");
        scanf ("%d",&opcion);

        switch (opcion){
         case 1: auxiliar=1;
            cargarVector(vec1, tam); break;

         case 2: 
            if (auxiliar == 1){
               printf ("\nEl vector es: ");
               mostrarVector(vec1, tam);}
            else{
                printf ("\nERROR: Primero cargue el vector\n");
            }; break;

         case 3: 
            if (auxiliar == 1){
                printf ("\nLa posicion del maximo del vector es: %d \n",posicionMaximo(vec1, tam));}
             else {
                printf ("\nERROR: Primero cargue el vector\n");
             }; break;

         case 4: 
            if (auxiliar==1){
                printf ("\nEl promedio del vector es: %.2f \n",promedioVector(vec1, tam));}
            else{
                printf ("\nERROR. Primero cargue el vector\n");
            }; break;

         case 5: break;
         default: printf ("\nERROR: Opcion no valida\n");
        }
    } while (opcion!=5);

    return 0;
}
void cargarVector (float vector[], int tamanio){
    int i;
    for (i=0; i<tamanio; i++){
        printf ("\nIngrese un numero en la posicion %d: ",i);
        scanf ("%f",&vector[i]);
    }
}
void mostrarVector (float vector[], int tamanio){
    int i;
    for (i=0; i<tamanio; i++){
        printf ("[%.2f] ",vector[i]);
    }
}
int posicionMaximo (float vector[], int tamanio){
    int i;
    int posMaximo;
    float maximo=vector[0];

    for (i=0; i<tamanio; i++){
        if (vector[i]>maximo){
            maximo = vector[i];
            posMaximo = i;
        }
    }
    return posMaximo;
}
float promedioVector (float vector[], int tamanio){
    int i;
    float promedio;
    float suma=0;

    for (i=0; i<tamanio; i++){
        suma = suma + vector[i];
    }
    promedio = suma/tamanio;

    return promedio;
}

int mostrarPosMin (float vector[],int tamanio){
  int posMin = 0;
  float minimo = vector[0];

  for (int i=0; i<tamanio; i++){
      if(vector[i]<minimo){
         minimo = vector[i];
         posMin = i;
      }
  }
   return posMin;
}
