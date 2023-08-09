#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
//Declaraciones de las funciones o procedimientos
//PRE: El tamaño que ingresa el usuario debe ser mayor a cero en caso que se use este tamaño
//para un vector o figura
//POST: Se devulve un entero
int elegirTamanio();
//PRE:El tamaño debe ser mayor a cero, y menor a 170, srand(time(0)) y #include <time.h> deben estarn en el main
//POST:Se sobreescribe el vector con numeros aleatorios, entre -70 y 100
void cargarVectorAleatorio(int v[], int tam);
//PRE:El tamaño debe ser mayor a cero
//POST:se muestra por pantalla el vector v
void mostrarVector(int v[], int tam);
//PRE: El tamaño debe ser mayor a cero
//POST: Se devuelve la posicion donde esta el valor minimo
int posMin(int v[], int tam);
//PRE: El tamaño debe ser mayor a cero
//POST: Se devuelve la posicion donde esta el valor maximo
int posMax(int v[], int tam);
//PRE: El tamaño debe ser mayor a cero
//POST: Se devuelve  el valor minimo
int minVector(int v[], int tam);
//PRE: El tamaño debe ser mayor a cero
//POST: Se devuelve el valor maximo
int maxVector(int v[], int tam);
//PRE: El tamaño debe ser mayor a cero
//POST: Se devuelve el promedio del vector
float promVector(int v[], int tam);
//PRE: El tamaño debe ser mayor a cero
//POST: Se sobreescribe el vector resultado con la suma vectorial
void sumaVectores(int v[], int w[], int resultado[], int tam);
//PRE: El tamaño debe ser mayor a cero
//POST: Se sobreescribe el vector resultado con la resta vectorial
void restaVectores(int v[], int w[], int resultado[], int tam);
//PRE: Mini debe ser menor  a maxi... SI o si .. srand(time(0)) y #include <time.h> deben estarn en el main
//POST: Se devuelve un valor aleatroio entre mini y maxi
int aleatorioEntre(int mini, int maxi);
//PRE: mini debe ser menor que maxi y el tamaño mayor a cero.
//POST: se sobreescriben los valores del vector v con valores aleatorios entre mini y maxi
void cargarVectorConAleatorios(int v[], int tam, int mini,int maxi);
//PRE: mini debe ser menor que maxi y el tamaño mayor a cero. Tam debe ser mayor a maxi - mini
//POST: se sobreescriben los valores del vector v con valores aleatorios entre mini y maxi, sin repetidos
void cargarVectorConAleatoriosSinRepetir(int v[], int tam, int mini,int maxi);
//PRE: El tamaño debe ser mayor a cero
//POST: Se sobreescribe el vector v, con los mismos valores pero ordenados de menor a mayor.
void ordenamientoBurbuja(int v[], int tam);
//PRE: El tamaño debe ser mayor a cero
//POST: Se sobreescribe el vector v, con los mismos valores pero ordenados de menor a mayor.
void ordenamientoSeleccion(int v[], int tam);
//PRE: El tamaño debe ser mayor a cero
//POST: Se sobreescribe el vector v, con los mismos valores pero ordenados de menor a mayor.
void ordenamientoInsercion(int v[], int tam);
//PRE: El tamaño debe ser mayor a cero
//POST: Se devuelve la posicion en caso que se encontro el numero, o -1 en caso de no encontrarlo
int busquedaSecuencial(int v[], int tam, int buscar);
//PRE: El tamaño debe ser mayor a cero, el vector v debe estar ordenado.
//POST: Se devuelve la posicion en caso que se encontro el numero, o -1 en caso de no encontrarlo
int busquedaBinaria(int v[], int tam, int buscar);

//-------------------------------SIN HACERLOS----------------------------------------------------------
//Para repasar previo al primer parcial
//PRE: el tamaño debe ser positivo
//POST: Se devuelve uno o menos uno si son iguales o no respectivamente.
int sonIguales(char nombre1[], char nombre2[], int tam);
//Realizar el ordenamiento de mayor a menor
//Realizar todos los mismos algoritmos pero para arrays de float o incluso de char
//Realizar la funcion que devuelve la moda del vector
//Realizar el procedimiento que carga un nuevo vector con la frecuenca de cada componente del vector inicial
//Realizar la fucion que devuelve el desvio standart (float) del vector.

#endif // VECTOR_H_INCLUDED