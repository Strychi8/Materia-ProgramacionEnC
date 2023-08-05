#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    printf("Tema 2\n");
   /*2) El usuario puede elegir el tamaño de un vector de enteros. Una vez seleccionado se pide
   guardar los valores en otro vector, con la siguiente lógica, a los pares hay que
   multiplicarlos por -5. A los impares hay que cambiarles el signo y multiplicarlos por la
   posición del vector, solo si son mayores a 5, de no ser así no hacerles nada. Una vez
   conseguidos los dos vectores se pide encontrar el promedio general de los dos vectores
   y la suma de todos los números. La carga del vector se debe hacer de forma aleatoria
   con números entre -20 y 20.
   Ejemplo:
   Se debe mostrar por pantalla algo así, obviamente dependiente de la carga del vector:
   V = ( -8, 12, 1, 11) ----------------- W = (40, -60, 1, -33)
   El promedio es: -36/8 Y la suma es: -36*/
   srand (time(0));

    int i,tam;
    float promGeneral=0;
    float suma1=0;
    int posc=0;

    printf ("\nIngrese el tamanio del vector\n");
    scanf ("%d",&tam); //Tamanio del vector

    int v1[tam];
    int v2[tam];

    for (i=0; i<tam; i++){
       v1[i] = -20 + rand() % 41; //Cargo el vector aleatoriamente
    }

    //Carga del segundo vector
    for (i=0; i<tam; i++){
       posc = i; //asigno variable a i
       if (v1[i]%2 == 0){
          v2[i] = v1[i] * -5;
        }
    }

     for (i=0; i<tam; i++){
        posc = i;
        if (v1[i]%2!=0 && v1[i]>5){
            v2[i] = v1[i] * -posc;
        }else{ 
            v2[i] = v1[i];
        }
    }

    for (i=0; i<tam; i++){
     suma1 = suma1 + v1[i] + v2[i]; //Calculo la suma general de los dos vectores

    }

    int div = tam*2;
    promGeneral = suma1/div ; //Calculo promedio

    printf ("V1= ");
    for (i=0; i<tam; i++){
       printf ("%d ",v1[i]); //Muestro el primer vector
    }

    printf (" --------  V2= ");

    for (i=0; i<tam; i++){
       printf ("%d ",v2[i]);//Muestro el segundo vector
    }

    //Muestro el promedio y la suma por pantalla
    printf ("\n\nEl promedio es: %.2f  Y la suma es: %.0f",promGeneral,suma1);
    printf ("\n");

    return 0;
}