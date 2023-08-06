#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

struct PersonaE;
typedef struct PersonaE * Persona;

//Constructor
Persona crearPersonaPorTeclado(); //printf --- scanf
Persona crearPersona(char n[40], int d, float a, float pe);

//Destructor
void destruirPersona(Persona p);

//Mostrar
void mostrarPersona(Persona p);

//Gets
int getDni(Persona p);
float getAltura(Persona p);
float getImc(Persona p);
float getPeso(Persona p);
char* getNombre(Persona p);

//Sets
void setDni(Persona p, int d);
void setAltura(Persona p, float a);
//void setImc(Persona p, float i); No se hace el set de los calculables
void setPeso(Persona p, float pe);
void setNombre(Persona p, char n[40]);

#endif // PERSONA_H_INCLUDED
