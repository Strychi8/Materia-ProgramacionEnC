#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COL 5

void fibonacci(int penultimo,int ultimo,int n);
int numFactorial(int n);
void mostrarHasta (int n);
int sumaHasta(int n);
int mostrarArrayRecursivo(int v[],int n);
void funcionEnteros(int n1,int n);
void pasarDecimalBinario(int n);
void pasarABinario();

int main(){
    
    printf("\nRecursividad: \n");
    printf ("\n1) La suma de los primeros N enteros es: %d ",sumaHasta(10));
    int vector[5] = {1,2,3,4,5};
    printf ("\n\n2) La suma de los primero datos del vector es: %d ",mostrarArrayRecursivo(vector,4));
    printf("\n\n3) Los numeros comprendidos entre un entero y otro entero: ");
    funcionEnteros(3,10);
    int num=0;
    printf ("\nIngrese un numero factorial: ");
    scanf("%d",&num);
    printf ("\n4) El factorial del numero %d es: %d",num,numFactorial(num));
    printf("\n\n5) Lista de numeros: ");
    mostrarHasta(19);
    printf("\n\n6) Sucesion de Fibonacci: ");
    fibonacci(0,1,5);
    printf ("\n\n7) Numero binario: ");
    pasarDecimalBinario(34);
    
    printf("\n\n8) Pasar a Binario: ");
    pasarABinario();

    printf("\n\n");
    return 0;
}

void pasarDecimalBinario (int n){
  if(n<=1){
    printf("%d ",n);
  }else{
    pasarDecimalBinario(n/2);
    printf("%d ",n%2);
  }
}

void fibonacci(int penultimo, int ultimo, int n){
  int actual = 0;
  printf("%d  ",ultimo);
  if(n>1){
    actual=penultimo+ultimo;
    fibonacci(ultimo,actual,n-1);
  }
}

void mostrarHasta (int n){
  if(n==0){
    return 0;
  }else{
    mostrarHasta(n-1);
    printf("%d  ", n);
  }
}

int numFactorial (int n){
  if(n<=1){
    return 1;
  }else{
     return n*numFactorial(n-1);
  }
}

int sumaHasta (int n){
   int suma = 0;
   if(n==1){
     return 1;
   } else {
       suma = n+sumaHasta(n-1);
   }
   return suma;
}

int mostrarArrayRecursivo(int v[], int n){
  if (n==0){
    return v[0];
  }else{
    return v[n]+mostrarArrayRecursivo(v,n-1);
  }
}

void funcionEnteros(int n1, int n){
  if(n==n1){
    return 0;
  }
  if(n<n1){
    printf("%d ",n1-1);
    return funcionEnteros(n,n1-1);
  }else{
    printf("%d ",n-1);
    return funcionEnteros(n-1,n1);
  }
}

void pasarABinario (){
  int numero = 0;
  printf ("\nIngrese un numero para convertirlo en binario: ");
  scanf ("%d",&numero);
  printf("\nNumero Binario: ");
  while (numero != 0){
     numero = numero/2;
     printf(" %d ",numero%2);
  }
}