#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

struct FechaE;
typedef struct FechaE *Fecha;

struct PersonaE;
typedef struct PersonaE *Persona;

//PRE: Se necesita haber creado el tipo de dato, puntero a la Persona
//POST: Se retorna una PERSONA, automatica
Persona cargarPersona();
//PRE: Debe estar creada la persona que se envia por parametro
//POST: Se muestra por pantalla la persona
void mostrarPersona (Persona p);

//PRE: Se necesita haber creardo el tipo de dato, puntero a la Fecha
//POST: Se retorna una FECHA, automatica
Fecha cargarFecha();
//PRE: Debe estar creada la Fecha que se envia por parametro
//POST: Se muestra por la consola la fecha
void mostrarFecha (Fecha f);
//PRE: Se necesita conocer los parametros a enviar
//POST: Se retorna una FECHA con esos parametros
Fecha cargarFechaPorParametros (int d,int m,int a);
//PRE: Los parametros de la fecha se piden por teclado
//POST: Se retorna una FECHA con esos parametros
Fecha cargarFechaPorTeclado ();
//PRE: Debe estar creada la fecha que se envia pr parametro
//POST: Se retorna la variable dia acorde a la fecha enviada por parametro
int getDia (Fecha f);
//PRE: Debe estar creada la Fecha que se envia por parametro
//POST: Se retorna la variable mes acorde a la Fecha enviado por parametro
int getMes (Fecha f);
//PRE: Debe estar creada la fecha que se envia pr parametro
//POST: Se retorna la variable anio acorde a la fecha enviada por parametro
int getAnio (Fecha f);
//PRE: Debe estar creada la fecha que se envia pr parametro, se necesita conocer la nueva fecha
//POST: Se modifica el dia de la fecha enviada por parametro
void setDia (Fecha f,int nuevoDia);
//PRE: Debe estar creada la fecha que se envia pr parametro, se necesita conocer la nueva fecha
//POST: Se modifica el mes de la fecha enviada por parametro
void setMes (Fecha f,int nuevoMes);
//PRE: Debe estar creada la fecha que se envia pr parametro, se necesita conocer la nueva fecha
//POST: Se modifica el anio de la fecha enviada por parametro
void setAnio (Fecha f,int nuevoMes);
//PERSONA
int getEdad (Persona p);
int getDni (Persona p);
float getDniEdad (Persona p);
void setEdad (Persona p,int nuevaEdad);
void setDni (Persona p,int nuevoDni);
//PRE: Se necesita crear creada la persona
//POST: Se libera esa memoria y destruye el puntero
void destruirPersona(Persona p);

#endif // FECHA_H_INCLUDED
