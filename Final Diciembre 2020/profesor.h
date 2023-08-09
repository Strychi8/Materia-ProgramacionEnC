#ifndef PROFESOR_H_INCLUDED
#define PROFESOR_H_INCLUDED

struct profesorE;
typedef struct profesorE * Profesor;
struct materiaE;
typedef struct materiaE * Materia;

Materia crearMateria ();
Profesor crearProfesor ();
void mostrarProfesores (Profesor p);
void mostrarMateria (Materia m);

char * getNombre (Profesor p);
int getSueldo (Profesor p);
int getAntiguedad (Profesor p);
float getSueldoFinal (Profesor p);
void setNombre (Profesor p, char nuevoNombre[50]);
void setSueldo (Profesor p, int nuevoSueldo);
void setAntiguedad (Profesor p, int nuevoAnio);

void agregarProfesor (Materia m, char nom[50], int suel, int anio);
void eliminarProfesor (Materia m, char nom[50]);

void ordenarProfesoresPorSueldo(Materia m);
void iniciarMateria(Materia m);

void fibonacci(int penultimo, int ultimo, int n);
int fibo (int n);

void guardarProfesores (Materia m);
void cargarProfesores (Materia m);

Profesor charAProfesor (char c[], int n);

#endif // PROFESOR_H_INCLUDED
