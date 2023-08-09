#ifndef NEGOCIO_H_INCLUDED
#define NEGOCIO_H_INCLUDED

struct NegocioE;
typedef struct NegocioE * Negocio;

struct BilleteE;
typedef struct BilleteE * Billete;

Negocio crearNegocioPorTeclado();
Negocio crearNegocio (char negocio[100], int a, int p, char v);
void mostrarNegocio (Negocio n);
char * getNombreN (Negocio n);
int getAltura (Negocio n);
int getPiso (Negocio n);
char * getVereda (Negocio n);
char * getNombreDolar (Billete b);
float getPrecio (Billete b);
void setPiso (Negocio n, int nuevoPiso);
void setAltura (Negocio n, int nuevaAltura);
void setNombreN (Negocio n, char nuevoNombreN);
void setVereda (Negocio n, char nuevaVereda);
void destruirNegocio (Negocio n);

enum opciones {salir,mostrarDeMayorAMenor,mostrarPrimeroNumNaturales};
void numNaturalesDeMayorAMenor (int n);
void primerosNumNaturales (int n);

float pedirNumero ();
int busquedaBinaria (int v[], int t, int buscarNum);

void cargarDolares (Billete v[], int n);
Billete charABillete (char c[], int n);
void ordenarValorDolar (Billete v[], int n);
void mostrarDolares (Billete v[], int n);

#endif // NEGOCIO_H_INCLUDED