#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int elegirTamanio();
int elegirOrdenamiento();
void cargarVectorAleatorio (int v[], int t);
void mostrarVector (int v[], int t);
void ordenamientoBurbuja (int v[], int t);
void ordenamientoSeleccion (int v[], int t);
void ordenamientoInsercion (int v[], int t);
void ordenamientoInsercion2 (int v[], int t);

int main()
{
    srand (time(0));

    int t=elegirTamanio();
    int vec[t];
    int opcion;
    int opcionDeOrdenamiento;
    int verificacion = 0;

    do{
        printf ("\n ------ Menu Principal --------");
        printf ("\n1) Crear vector");
        printf ("\n2) Mostrar vector");
        printf ("\n3) Elegir un metodo de ordenamiento para reorganizar el vector");
        printf ("\n\nIngrese una opcion: ");
        scanf ("%d",&opcion);

        switch (opcion){

            case 1: verificacion = 1;
               cargarVectorAleatorio (vec, t); break;

            case 2: if (verificacion == 1){
               mostrarVector (vec, t);
            }else {
               printf ("\nERROR: Por favor, primero cargue el vector\n");
            }; break;

            case 3: if (verificacion == 1){
                opcionDeOrdenamiento = elegirOrdenamiento();
                printf ("\n---- VECTOR ORDENADO ----");
             if (opcionDeOrdenamiento = 1){
                ordenamientoBurbuja(vec, t); break;
             }
             if (opcionDeOrdenamiento = 2){
                ordenamientoSeleccion (vec,t); break;
             }
             if (opcionDeOrdenamiento = 3){
                ordenamientoInsercion2 (vec, t); break;
               }
            }else {
                printf ("\nERROR: Por favor, primero cargue el vector\n\n");
            }; break;

            case 0: break;
            default: printf ("\nOPCION NO VALIDA: Intente con otro numero que sea de la lista\n"); break;
        }
    }while (opcion!=0);

    printf ("\n\n");

    return 0;
}

int elegirTamanio (){
    int tam;
    printf ("\nIngrese un tamanio para su vector: ");
    scanf ("%d",&tam);

    return tam;
}

int elegirOrdenamiento(){
    int opcion=0;
    do{
        printf ("\n1) Ordenamiento por Burbuja\n");
        printf ("2) Ordenamiento por Seleccion\n");
        printf ("3) Ordenamiento por Insercion\n");
        printf ("\nEliga una opcion:  ");
        scanf ("%d",&opcion);
    }while (opcion=0);

    return opcion;
}

void cargarVectorAleatorio (int v[], int t){
     int i;
     for (i=0; i<t; i++){
        v[i] = rand()%51;
     }
}

void mostrarVector (int v[], int t){
    int i;
    printf("\nVector: ");
    for (i=0; i<t; i++){
        printf ("[%d]  ",v[i]);
    }
    printf ("\n\n");
}

void ordenamientoBurbuja (int v[], int t){
    int i,j;
    int aux;
    for (i=0; i<t; i++){
        for (j=0; j<t-1; j++){
            if (v[j]>=v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
    printf ("\n\n");
}

void ordenamientoSeleccion (int v[], int t){
    int i,j,aux,min;
    for (i=0; i<t; i++){
        min = i;
        for (j=i+1; j<t; j++){
            if (v[min]>v[j]){
                aux = v[min];
                v[min] = v[i];
                v[i] = aux;
            }
        }
    }
    printf ("\n\n");
}

void ordenamientoInsercion (int v[], int t){
    int i,j,aux,r,izq,der;
    for (i=1; i<t; i++){
        aux = v[i];
        izq = 0;
        der = i-1;
        while (izq <= der){
            r = (izq+der)/2;
        if (aux < v[r]){
            der = r-1;
        } else {
            izq = r+1;
        }
        }
        j = i-1;
        while (j>=izq){
            v[j+1] = v[j];
            j = j-1;
        }
        v[izq] = aux;
    }
}

void ordenamientoInsercion2 (int v[],int t){
  int aux,n;
  for (int i=1; i<t; i++){
     aux=v[i];
     n=i;
     while (n>0){
        if (v[n]<v[n-1]){
            v[n]=v[n-1];
            v[n-1]=aux;
            n=n-1;
        }else{
          n=0;
        }
     }
     for (int x=0; x<t; x++){
        printf ("%d ",v[x]);

     }
     printf ("\n\n");
  }
}