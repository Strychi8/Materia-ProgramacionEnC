#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

struct EmpleadosE;
typedef struct EmpleadosE * Empleado;

struct EmpresaE;
typedef struct EmpresaE * Empresa;

Empleado crearEmpleado();
Empresa crearEmpresa();

char * getNombre (Empleado e);
char * getApellido (Empleado e);
int getEdad (Empleado e);
int getSueldo (Empleado e);
int getEdadSueldo (Empleado e);

void setNombre (Empleado e, char nuevoNombre[40]);
void setApellido (Empleado e, char nuevoApellido[40]);
void setEdad (Empleado e, int nuevaEdad);
void setSueldo (Empleado e, int nuevoSueldo);

void ordenarEmpleadosPorInsercion (Empresa e);
void ordenarEmpleadosPorSeleccion (Empresa e);

void agregarEmpleado (Empresa e, char nom[40], char ape[40], int eda, int sueld);
void eliminarEmpleado (Empresa e, char ape[40]);
void guardarEmpleados(Empresa e);

#endif // EMPLEADOS_H_INCLUDED
