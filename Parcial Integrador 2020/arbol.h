#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

struct ArbolE;
typedef struct ArbolE * Arbol;

void iniciarArboles(Arbol a[], int t);//inicializo las posiciones a vacias o -1
void cargarArboles(Arbol a[], int t);//cargo los arboles que estan en el txt
void guardarArboles (Arbol a[], int t);//guardo los arboles en el txt
Arbol charAStruct(char delimitador[], int fin);//paso los chars a structs
//Mostrar
void mostrarArboles(Arbol a[], int t);
//ABM
void agregarArbol(Arbol a[], int t, char nom[40], int eda, float alt);
void modificarArbol(Arbol a[], int t, char nom[40]);
void eliminarArbol(Arbol a[], int t, char nom[40]);
//Getters
char*getNombre(Arbol a);
int getEdad (Arbol a);
float getAltura (Arbol a);
//Setters
void setNombre(Arbol a, char nuevoNombre[40]);
void setEdad(Arbol a, int nuevaEdad);
void setAltura(Arbol a, float nuevaAltura);

#endif // ARBOL_H_INCLUDED