#ifndef TENISTA_H_INCLUDED
#define TENISTA_H_INCLUDED

struct tenistaE;
typedef struct tenistaE * Tenista;

void iniciarTenistas(Tenista v[], int t);

void cargarTenistas(Tenista v[], int t);
Tenista pasarDeCharAStruct(char delimitador[], int fin);

void mostrarTenistas(Tenista v[], int t);
void ordenarTenistas(Tenista v[], int t);

int getEdad(Tenista t);
int getRanking(Tenista t);
char*getNombre(Tenista t);
char*getManoHabil(Tenista t);
float getAltura(Tenista t);

void setEdad(Tenista t, int nuevaEdad);
void setRanking(Tenista t, int nuevoRanking);
void setAltura(Tenista t, float nuevaAltura);
void setNombre(Tenista t, char nuevoNombre[40]);
void setManoHabil(Tenista t, char nuevaManoHabil[40]);

#endif // TENISTA_H_INCLUDED