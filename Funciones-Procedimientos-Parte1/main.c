#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define RENGLON "\n\n"
//Las funciones se definen arriba del main
//Las variables son globales
//resultado(tipo de dato)-nombre-(Parametros de entrada)

//1) Crear las siguientes funciones y procedimientos, probandolos desde el main:
void cargarValor (int n);
int cargarValor2 (int n);
int sumarNumerosEntre (int inicial, int fin);
int calcularEdad (int anioHoy, int nacimiento);
float calcularIndiceDeMasaCorporal(float peso, float altura);
void dibujarPiramide(int base, int altura);
void dibujarTriangulo (int base, int altura);
void calcularHipotenusa(float cateto1, float cateto2);
int cantidadDeVecesQueApareceLaLetra(char oracion[], int tam, char letra);
int pedirEnteroPorTeclado();
float pedirFloatPorTeclado();
void cargarVector(int v[], int t); //definir un vector global solo por ahora
void mostrarVector(int v[], int t);
int maximoVector();
int minimoVector();
int cantidadNumerosRepetidosEnElVector();

int main()
{
    //OBSERVACION
    int a = 4;
    cargarValor(a);
    printf("1) Cargar Valor: ");
    printf ("%d\n", a);
    a = cargarValor2(a);
    printf("2) Cargar Valor 2: ");
    printf ("%d\n", a);
    //Opcion 1: Guardar el valor
    int laSumaes = sumarNumerosEntre (10, 101);
    //Opcion 2: Mostrar el valor
    printf("3) Suma de Numeros: ");
    printf ("%d ",sumarNumerosEntre(1, 100));
    printf (RENGLON);
    
    printf("4) Calcular Edad: \n");
    printf ("Tendra ----> %d anios en el 2020",calcularEdad(2020, 2000));
    printf (RENGLON);
    
    printf("5) Indice de Masa Corporal: ");
    printf ("%.2f ",calcularIndiceDeMasaCorporal(62, 1.62*1.62));
    printf (RENGLON);
    
    printf("6) Dibujo de un triangulo:\n");
    dibujarTriangulo (12,7);
    printf (RENGLON);
    
    printf("7) Dibujo de una piramide:\n");
    dibujarPiramide(15,5);
    printf (RENGLON);

    printf ("8) Calculo de la hipotenusa: ");
    calcularHipotenusa (4,3);
    printf (RENGLON);

    char cadena[100] = "Habia una vez";
    char letraRepetida = 'a';
    printf("9) Cantidad de veces que aparece la letra: ");
    printf ("%d ", cantidadDeVecesQueApareceLaLetra(cadena, 100, letraRepetida));
    printf (RENGLON);
    
    printf("10) Pedir entero por teclado: \n");
    pedirEnteroPorTeclado();
    printf (RENGLON);
    printf("11) Pedir flotante por teclado: \n");
    pedirFloatPorTeclado();
    printf (RENGLON);

    int tam = 5;
    int vector[tam];
    //carga vector
    printf("12) Cargo vector: \n");
    cargarVector(vector, tam);
    printf (RENGLON);
    //mostrar vector
    printf("13) Muestro vector: ");
    mostrarVector(vector, tam);
    printf (RENGLON);
    
    printf("14) El maximo valor del vector es: ");
    printf ("%d ",maximoVector(vector, tam));
    printf (RENGLON);
    
    printf("15) El minimo valor del vector es: ");
    printf ("%d ",minimoVector(vector, tam));
    printf (RENGLON);

    printf("16) La cantidad de numeros repetidos en el vector son: ");
    printf ("%d ",cantidadNumerosRepetidosEnElVector(vector, tam));
    printf (RENGLON);

    return 0;
}
//Abajo del main va el cuerpo-implementacion
void cargarValor (int n){
    n = 11;
}
int cargarValor2 (int n){
    n = 11;

    return n;
}
int sumarNumerosEntre (int inicial, int fin){
    int i;
    int suma=0;

    for (i=inicial; i<fin; i++){
        suma = suma + i;
    }
    return suma;
}

int calcularEdad (int anioHoy, int nacimiento){
    return anioHoy-nacimiento;
}
float calcularIndiceDeMasaCorporal(float peso, float altura){
   return peso/altura;
}
void dibujarTriangulo (int base, int altura){
    for (int i=1; i<=altura; i++){
        for (int j=1; j<=i; j++){
           printf ("*");
        }
        printf ("\n");
    }
}
void dibujarPiramide(int base, int altura){

    for (int i=1; i<=altura; i++){
        for (int j=1; j<=base-i; j++){
            printf (" ");
        }
        for (int aux=1; aux<=2*i-1; aux++){
            printf ("X");
        }
        printf ("\n");
    }

}
void calcularHipotenusa(float cateto1, float cateto2){
     //float resultado = (cateto1*cateto1)+(cateto2*cateto2);
     //float hipotenusa = sqrt(resultado);
     float hipotenusa = sqrt(pow(cateto1,2) + pow(cateto2,2));
     printf ("%f",hipotenusa);
}
int cantidadDeVecesQueApareceLaLetra(char oracion[], int tam, char letra){
    int cont = 0;
    //tam = 100;
    for (int i=0; i<tam; i++){
      if (oracion[i] == letra){
        cont++;
      }
    }
    return cont;
}
int pedirEnteroPorTeclado(){
    int numeroEntero;
    printf ("Ingrese un numero entero: ");
    scanf ("%d",&numeroEntero);
    printf ("Su numero entero sera ---> %d\n",numeroEntero);

    return numeroEntero;
}
float pedirFloatPorTeclado(){
    float numeroFlotante;
    printf ("\nIngrese un numero con coma: ");
    scanf ("%f",&numeroFlotante);
    printf ("El numero que ingreso fue -----> %.2f\n",numeroFlotante);

    return numeroFlotante;
}
void cargarVector(int v[], int t){

    for (int i=0; i<t; i++){
        printf ("Ingrese un numero: ");
        scanf ("%d",&v[i]);
    }
}
void mostrarVector(int v[], int t){

    for (int i=0; i<t; i++){
        printf ("[%d]  ",v[i]);
    }
}
int maximoVector(int v[], int t){
    int max = v[0];

    for (int i=0; i<t; i++){
        if (v[i]>max){
            max = v[i];
        }
    }
    return max;
}
int minimoVector(int v[], int t){
    int min = v[0];

    for (int i=0; i<t; i++){
        if (v[i]<min){
            min = v[i];
        }
    }
    return min;
}
int cantidadNumerosRepetidosEnElVector(int v[], int t){
    int cont = 0;

    for (int i=0; i<t; i++){
        for (int j=i+1; j<t; j++){
            if (v[i] == v[j]){
               cont++;
            }
        }
    }
    return cont;
}