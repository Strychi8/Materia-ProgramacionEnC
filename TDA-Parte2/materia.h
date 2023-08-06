#ifndef MATERIA_H_INCLUDED
#define MATERIA_H_INCLUDED

struct MateriaE;
typedef struct MateriaE * Materia;

Materia crearMateria(char n[40]);
void mostrarMateria(Materia m);

//Getters y Setters
char * getNombreM (Materia m);
void setNombreM (Materia m, char nuevoNombreMateria);

void destruirMateria(Materia m);

#endif // MATERIA_H_INCLUDED