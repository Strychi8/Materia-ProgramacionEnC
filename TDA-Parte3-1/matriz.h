#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED
//Segunda dimension de la matriz, la primer dimension esta libre
//la enviamos por parametro
#define RENGLONES 6
//Dejaremos fija esta dimencion cuando trabajamos con arreglos de char
#define LARGO_ORACION 30

//PRE: c debe ser un numero positivo.
//POST: Se carga la matriz m
void cargarMatriz(int m[][RENGLONES], int c );
//PRE: c debe ser un numero positivo.
//POST: Se muestra la matriz m
void mostrarMatriz(int m[][RENGLONES], int c );
//PRE: c debe ser un numero positivo
//POST: Se realiza la suma pr renglones de los numeros de la matriz
//Cada suma se guarda en el vector v
void sumarPorRenglones(int m[][RENGLONES], int c, int v[]);

//-----------------------------------SIN HACER----------------------------------------
//Para practicar

//PRE: c debe ser un numero positivo, mini debe ser menor que maxi.. m
//POST: Se carga la matriz m, con aleatatorios entre mini y maxi
void cargarMatrizDeAleatorios(int m[][RENGLONES],int c, int mini, int maxi);
//PRE: c debe ser un numero positivo, mini debe ser menor que maxi.. maxi-mini debe ser mayor que c*renglones
//POST: Se carga la matriz m, con aleatatorios entre mini y maxi SIN REPETIR
void cargarMatrizDeAleatoriosSinRepetir(int m[][RENGLONES], int c, int mini, int maxi);
//PRE: c debe ser un numero positivo
//POST: Se realiza la suma pr columnas de los numeros de la matriz
//Cada suma se guarda en el vector v
void sumarPorColumnas(int m[][RENGLONES], int c, int v[]);
//PRE: c debe ser un numero positivo
//POST: Se realiza el promedio de cada uno de los  renglones de los numeros de la matriz
//Cada suma se guarda en el vector v
void promedioPorRenglones(int m[][RENGLONES], int c, float v[]);
//PRE: c debe ser un numero positivo
//POST: Se realiza el promedio de cada uno de los  renglones de los numeros de la matriz
//Cada suma se guarda en el vector v
void promedioPorColumnas(int m[][RENGLONES], int c, float v[]);
//PRE: c debe ser un numero positivo
//POST:Se suma la matriz m1 con la matriz m2, se guarda el resultado en la matriz resultado
void sumaDeMatrices(int m1[][RENGLONES], int c, int m2[][RENGLONES], int resultado[][RENGLONES]  );
//PRE: c debe ser un numero positivo
//POST:Se suma la matriz m1 con la matriz m2, se guarda el resultado en la matriz resultado
void restaDeMatrices(int m1[][RENGLONES], int c, int resultado[][RENGLONES]);
//PRE:RENGLONES es global debe ser mayor que cero
//POST: Se multiplica m1 con m2, y se obtiebe resultado, la matriz debe ser cuadrada
void multiplicacionDeMatrices(int m1[RENGLONES][RENGLONES], int m2[RENGLONES][RENGLONES], int resultado[RENGLONES][RENGLONES]);
//PRE: c debe ser mayor a cero, es la cantidad de oraciones que tenemos, las horaciones tiene LARGO_ORCACION caracteres
//busco es la oracion que estoy buscando, tiene tamaño LARGO_ORACION
//POST: se devuelve la posiccion de la oracion, o menos 1 en caso de no encontrarse.
int buscarOracion(char oraciones[][LARGO_ORACION], int c, char busco[]);

#endif // MATRIZ_H_INCLUDED