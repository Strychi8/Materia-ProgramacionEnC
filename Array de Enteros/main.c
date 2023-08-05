#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int main(){

   /*Ejercicio 1: Crear un programa semejante al ejemplo 1, donde nos muestre el máximo, el
   mínimo y nos muestre todo el vector pero de atrás para adelante, es decir 
   de la posición 19 a la 0. */
   printf("Ejercicio 1");
   int n,i;

   printf ("\nIngrese un numero para su vector: ");
   scanf ("%d",&n);

   int vector[n];

   for (i=0; i<n; i++){
    printf ("\nIngrese valores: ",i+1);
    scanf ("%d",&vector[i]);
   }

   int maximo=vector[0];
   int minimo=vector[0];
   //Calculando el minimo
   for (i=0;i<n;i++){
    if (vector[i]<minimo){
        minimo = vector[i];
    }
   }
   //Calculando el maximo
   for (i=0;i<n;i++){
    if (vector[i]>maximo){
        maximo = vector[i];
    }
   }
   //Mostrando el minimo y el maximo por pantalla
   printf ("\nEl minimo es -----> %d",minimo);
   printf ("\nEl maximo es -----> %d\n",maximo);

   printf ("\nNumeros de atras para adelante: ");
   for (i=n-1; i>=0; i--){
     printf ("[%d] ",vector[i]);
   }

   /*Ejercicio 2: Crear un arreglo que ingresa 10 alturas. Una vez ingresadas las alturas, 
   mostrar la mínima, la máxima, el promedio y las alturas en las posiciones pares, 
   es decir vector[0], vector[2], etc etc.*/
   printf("\n\nEjercicio 2");
   int j;
   float altura[10];

   for (j=0; j<10; j++){
    printf ("\nIngrese numeros decimales: ");
    scanf ("%f",&altura[j]);
   }

   float maxima=altura[0];
   float minima=altura[0];
   float prom=0;
   float suma=0;

   for (j=0; j<10; j++){
    if (altura[j]<minima){
        minima = altura[j];
    }
   }

   for (j=0; j<10; j++){
    if (altura[j]>maxima){
        maxima = altura[j];
    }
   }

   for (j=0; j<10; j++){
     suma = suma + altura[j];
   }
    prom = suma/10;

    printf ("\nEl numero minimo es ----> %.2f",minima);
    printf ("\nEl numero maximo es ----> %.2f",maxima);
    printf ("\nEl promedio es ----> %.2f\n",prom);

   for (j=0; j<10; j=j+2){
    printf ("\nAlturas en las posiciones pares %d: %.2f\n",j,altura[j]);
   }

    /*Ejercicio 3: El usuario elige cuantas posiciones tiene el vector. Una vez definido 
    el tamaño del vector (por el usuario), el usuario tipea tantos números enteros 
    como sean necesarios para completar el array. Una vez completo el array,
    mostrar la suma de los números pares, el promedio de los impares, el máximo valor 
    y la posición donde estaba el máximo, el mínimo y su posición. Mostrar el arreglo 
    de derecha a izquierda y de izquierda a derecha. */
    printf("\nEjercicio 3");
    int n1,k;

    printf ("\nIngrese un numero para su vector: ");
    scanf ("%d",&n1);

    int vector1[n1];

    for (k=0; k<n1; k++){
        printf ("\nIngrese numeros enteros: ");
        scanf ("%d",&vector1[k]);
    }

    int maximo1=vector1[0];
    int minimo1=vector1[0];
    float promImpar=0;
    float sumaImpar=0;
    int sumaPar=0;
    int contImpar=0;
    int posc=0,posc1=0;

    for (k=0; k<n1; k++){
        if (vector1[k]<minimo1){
            minimo1 = vector1[k];
            posc = k;
          }
    }

    for (k=0; k<n1; k++){
        if (vector1[k]>maximo1){
            maximo1 = vector1[k];
            posc1 = k;
        }
    }

    for (k=0; k<n1; k++){
        if (vector1[k]%2 == 0){
            sumaPar = sumaPar + vector1[k];
        }else{
            sumaImpar = sumaImpar + vector1[k];
            contImpar = contImpar + 1;
        }
    }
    promImpar = sumaImpar/contImpar;

    printf ("\nEl minimo es ----> %d y esta en la posicion %d",minimo1,posc);
    printf ("\nEl maximo es ----> %d y esta en la posicion %d",maximo1,posc1);
    printf ("\nLa suma total de pares es -------> %d",sumaPar);
    printf ("\nEl promedio de los impares es ----> %f",promImpar);
    
    printf("\nArray de izquierda a derecha: ");
    for (k=n1-1; k>=0; k--){
        printf ("[%d] ",vector1[k]);
    }
    printf("\nArray de derecha a izquierda: ");
    for (k=0; k<n1; k++){
        printf ("[%d] ",vector1[k]);
    }

   // Ejercicio 4: Crear un vector de 30 números enteros aleatorios
   printf("\n\nEjercicio 4");
   srand(time(0));
   int tamanio=30;
   int vector2[tamanio];
   int indice;

    printf ("\nVector de Numeros Aleatorios: ");
    for (indice=0; indice<tamanio; indice++){
        vector2[indice] = rand() % 300;
        printf ("[%d] ",vector2[indice]);
    }

    return 0;
}