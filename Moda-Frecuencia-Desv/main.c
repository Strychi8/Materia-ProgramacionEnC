#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int pedirTamanio ();
void cargarVector (float v[], int tam);
void mostrarVector (float v[], int tam);
void cargarFrecuencia (float v[], int tam);
void mostrarModa (float v[], int tam);
float calcularPromedio (float v[], int tam);
float calcularDesvioEstandar (float v[], int tam);
float calcularMediaDelVector (float v[], int tam);

int main(){
    //Ejercicio 5: Crear un programa que muestre por pantalla el vector con numeros
    //aleatorios, la frencuencia, la moda, el promedio y el desvio estandar
    int t = pedirTamanio();
    float vector1[t];
    float vector2[t];

    cargarVector (vector1, t);
    cargarVector (vector2, t);

    printf ("\n1) El usuario eligio un tamanio de: %d", t);
    printf ("\n\n2) El primer vector es: ");
    mostrarVector (vector1, t);
    printf ("\n2-1) El segundo vector es: ");
    mostrarVector (vector2, t);
    printf ("\n\n3) Frecuencias del primer vector: ");
    cargarFrecuencia (vector1, t);
    printf ("\n3-1) Frecuencias del segundo vector: ");
    cargarFrecuencia (vector2, t);
    printf ("\n\n4) La moda del primer vector es: ");
    mostrarModa (vector1, t);
    printf ("\n4-1) La moda del segundo vector es: ");
    mostrarModa (vector2, t);
    printf ("\n\n5) El promedio del primer vector es: %.2f ",calcularPromedio (vector1, t));
    printf ("\n5-1) El promedio del segundo vector es: %.2f ",calcularPromedio (vector2, t));
    printf ("\n\n6) El desvio estandar del primer vector es: %.2f ",calcularDesvioEstandar (vector1, t));
    printf ("\n6-1) El desvio estandar del segundo vector es: %.2f ",calcularDesvioEstandar (vector2, t));
    printf ("\n\n7) La media del primer vector es: %.2f ",calcularMediaDelVector(vector1, t));
    printf ("\n7-1) La media del segundo vector es: %.2f ",calcularMediaDelVector(vector2, t));

    printf ("\n\n");
    return 0;
}
int pedirTamanio (){
    int tam;
    printf ("\nIngrese el tamanio de los 2 vectores: ");
    scanf ("%d",&tam);

    return tam;
}
void cargarVector (float v[], int tam){
    int i;
    for (i=0; i<tam; i++){
        printf ("Ingrese el numero en la posicion %d: ",i+1);
        scanf ("%f", &v[i]);
    }
}
void mostrarVector (float v[], int tam){
    int i;
    for (i=0; i<tam; i++){
        printf ("[%.2f] ",v[i]);
    }
}
void cargarFrecuencia (float v[],int tam){
    int i,j;
    int frecuencia[tam];
    int cont=0;
    for (i=0; i<tam; i++){
        cont=0;
        for (j=0; j<tam; j++){
            if (v[i]==v[j]){
                cont = cont+1;
            }
        }
        if (cont != 0){
            frecuencia[i] = cont;
        }
    }
    for (i=0; i<tam; i++){
        printf ("\nLa frecuencia de %.2f es: %d/%d   ",v[i],frecuencia[i],tam);
    }
}
void mostrarModa (float v[], int tam){
    int i,j;
    int frecuencia[tam];
    int cont=0;

    for (i=0; i<tam; i++){
        cont=0;
        for (j=0; j<tam; j++){
            if (v[i]==v[j]){
                cont = cont+1;
            }
        }
        if (cont != 0){
            frecuencia[i] = cont;
        }
    }
    int frecuenciaMaxima;
    int numeroDeModa;
    frecuenciaMaxima = frecuencia[0];

    for (i=0; i<tam; i++){
        if (frecuencia[i]>frecuenciaMaxima){
            frecuenciaMaxima = frecuencia[i];
            numeroDeModa = i;
        }
    }
    printf ("[%d] ",numeroDeModa);
}
float calcularPromedio (float v[], int tam){
    float promedio=0;
    for (int i=0; i<tam; i++){
        promedio = promedio + v[i];
    }
    promedio = promedio/tam;

    return promedio;
}
float calcularDesvioEstandar (float v[], int tam){
    float promedio=0;
    int i;
    for (i=0; i<tam; i++){
        promedio=promedio+v[i];
    }
    promedio=promedio/tam;
    float desvioEstandar=0;
    float desv=0;

    for (i=0; i<tam; i++){
        desvioEstandar = desvioEstandar + pow((v[i]-promedio),2);
    }
    desv = pow(desvioEstandar,0.5)*0.2;

    return desv;
}
float calcularMediaDelVector (float v[], int tam){
    int i;
    float media=0;

    for (i=0; i<tam; i++){
        media = media + v[i];
    }
    media = media/tam;

    return media;
}
