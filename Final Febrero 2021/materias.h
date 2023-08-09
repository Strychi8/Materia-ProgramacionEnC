#ifndef MATERIAS_H_INCLUDED
#define MATERIAS_H_INCLUDED

struct MateriaE;
typedef struct MateriaE * Materia;
struct EstudianteE;
typedef struct EstudianteE * Estudiante;

//Cargar
Materia crearMateria(int horSem, char profeT[40], int ins);
Estudiante crearEstudiante (char nom[40], int eda);
//Mostrar
void mostrarEstudiante(Estudiante e);
void mostrarMateria(Materia m);
//Agregar y eliminar
void agregarMateria(Estudiante e,Materia m);
void eliminarMateria(Estudiante e,Materia m);
//Ordenamiento
void ordenarMateriasPorTitular(Estudiante e);
//Getters
int getHorario(Materia m);
char * getProfe(Materia m);
int getInscriptos(Materia m);
int getEdad(Estudiante e);
char * getNombre(Estudiante e);
//Setters
void setHorario(Materia m, int nuevoHorario);
void setInscriptos(Materia m , int nuevosInscriptos);
void setProfe(Materia m, char nuevoProfe[40]);
void setEdad (Estudiante e, int nuevaEdad);
void setNombre(Estudiante e, char nuevoNombre[40]);

//guardar
void guardarEstudiante (Estudiante e);

#endif // MATERIAS_H_INCLUDED