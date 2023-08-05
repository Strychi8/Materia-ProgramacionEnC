#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int elegirTamanio();
//void cargarVectorAleatorio(float vector[], int tam); no se usa en este caso
void cargarVectorPorTeclado (float vector[], int tam);
void cargarVectorPorTeclado2 (float vector[], int tam);
void mostrarVector (float vector[], int tam);
void mostrarVector2 (float vector[], int tam);
float calcularMaximo(float vector[], int tam);
float calcularMinimo (float vector[], int tam);
void cargarResta (float vector[], int tam, float vector2[], int t);
void cargarSuma (float vector[], int tam, float vector2[], int t);
float calcularPromedio(float vector[], int tam);

int main()
{
    printf("TEMA 2\n");
    //srand(time(0));
    int t = elegirTamanio();

    float vec[t];
    float vec1[t];
    cargarVectorPorTeclado(vec, t);
    cargarVectorPorTeclado2 (vec1, t);
    printf ("\nEl usuario eligio un tamanio de: %d",t);
    mostrarVector (vec, t);
    mostrarVector2 (vec1, t);
    printf ("\nEl minimo del vector 1 es: %.2f",calcularMinimo (vec, t));
    printf ("\nEl maximo del vector 2 es: %.2f",calcularMaximo (vec1, t));
    cargarResta (vec, t, vec1, t);
    cargarSuma(vec, t, vec1, t);
    printf ("\nEl promedio del vector 1 es: %.2f",calcularPromedio (vec, t));
    printf ("\nEl promedio del vector 2 es: %.2f",calcularPromedio (vec1, t));

    printf ("\n");
    return 0;
}

int elegirTamanio(){
   int tam;
   printf ("\nIngrese el tamanio de los 2 vectores: ");
   scanf ("%d",&tam);

   return tam;
}

/*void cargarVectorAleatorio(float vector[], int tam){
    int i;
    for (i=0; i<tam; i++){
        vector[i] = -50 + rand() % 101;
    }
}*/

void cargarVectorPorTeclado(float vector[], int tam){
    int i;
    float V2[tam];

    for (i=0; i<tam; i++){
        printf ("\nIngrese un numero en la posicion %d: ",i);
        scanf ("%f",&vector[i]);
    }
}

void cargarVectorPorTeclado2 (float vector[], int tam){
   int i;

   for (i=0; i<tam; i++){
        printf ("\nIngrese un numero en la posicion %d: ",i);
        scanf ("%f",&vector[i]);
    }
}

void mostrarVector (float vector[], int tam){
    int i;
    float V2[tam];

    printf ("\nEl primer vector es: ");
    for (i=0; i<tam; i++){
        printf ("[%.2f] ",vector[i]);
    }
}

void mostrarVector2 (float vector[], int tam){
    printf ("\nEl segundo vector es: ");
    for (int i=0; i<tam; i++){
        printf ("[%.2f] ",vector[i]);
    }
}

float calcularMaximo(float vector[], int tam){
     float max=vector[0];

     for (int i=0; i<tam; i++){
        if (vector[i]>max){
            max = vector[i];
        }
     }
     return max;
}

float calcularMinimo (float vector[], int tam){
     float min=vector[0];

     for (int i=0; i<tam; i++){
        if (vector[i]<min){
            min=vector[i];
        }
     }
     return min;
}

void cargarResta (float vector[], int tam, float vector2[], int t){
    int i;
    float resta[tam];

    printf ("\nLa resta de los 2 vectores es: ");
    for (i=0; i<tam; i++){
        resta[i] = vector[i]-vector2[i];
        printf ("[%.2f] ",resta[i]);
    }
}

void cargarSuma (float vector[],int tam,float vector2[], int t){
    int i;
    float vector3[tam];

    printf ("\nLa suma de los 2 vectores es: ");
    for (i=0; i<tam; i++){
        vector3[i] = vector[i]+vector2[i];
        printf ("[%.2f] ",vector3[i]);
    }

}

float calcularPromedio(float vector[], int tam){
     float prom;
     float suma=0;

     for (int i=0; i<tam; i++){
        suma = suma + vector[i];
     }
     prom = suma/tam;

     return prom;
}