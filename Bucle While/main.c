#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    //ITERACION-WHILE
    //Ejercicio 7: Mostrar los primeros 20 numeros pares usando While
    printf("\n1) Ejercicio 7: ");
    int numero = 1;
       
    while(numero <= 40){
        if(numero%2 == 0){
            printf("\nEl numero es %d y es par", numero);
        }
        numero++;
    }
       
    //Ejercicio 8: Pedir un numero y transformarlo a numero binario
    printf("\n\n2) Ejercicio 8: ");
    int numero1,resto,cont = 0;
    double cifra,sumaBinario = 0;

    printf ("\nIngrese un numero para convertirlo en binario: ");
    scanf ("%d",&numero1);
    printf ("\n");

    while (numero1>0){
        cont = cont + 1;
        resto = numero1 % 2;
        numero1 = numero1 / 2;
        cifra = resto * pow(10,cont-1);
        sumaBinario = sumaBinario + cifra;
    }
    printf ("\nBinario: %.0f\n",sumaBinario);
    printf ("\n");
       
    /*Ejercicio 9: Crear un programa que pida numeros positivos al usuario, y vaya calculando la suma de todos ellos
    (terminara cuando se teclea un numero negativo o cero o cuando la suma supere los 1500)*/
    printf("\n\n3) Ejercicio 9: ");
    int numero2 = 1;
    int suma = 0;

    while (numero2>0 && numero2<1500){
      printf ("\nIngrese un numero positivo: ");
      scanf ("%d",&numero2);
        if(numero2 >= 0){
            suma = suma + numero2;
        }
    }
    printf ("\nSuma: %d\n", suma);
       
  return 0;
}