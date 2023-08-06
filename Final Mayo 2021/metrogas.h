#ifndef METROGAS_H_INCLUDED
#define METROGAS_H_INCLUDED

struct usuarioE;
typedef struct usuarioE * Usuario;

struct fechaE;
typedef struct fechaE * Fecha;

struct facturaE;
typedef struct facturaE * Factura;

Usuario crearUsuario(int num, char nomApe[40]);
Fecha crearFecha (int m, int a);
Factura crearFactura (int tot, Usuario u, Fecha fech);

void mostrarFacturas(Factura f[], int t);
void mostrarUsuario(Usuario a);
void mostrarFecha(Fecha f);
void ordenarFacturas(Factura f[], int t);

int getCuenta (Usuario a);
char * getNomApe (Usuario a);
int getMes(Fecha f);
int getAnio(Fecha f);
int getConsumo(Factura fac);

void setCuenta(Usuario a, int nuevaCuenta);
void setNombreApe(Usuario a, char nuevoNombre[40]);
void setMes(Fecha f, int nuevoMes);
void setAnio(Fecha f, int nuevoAnio);
void setConsumo(Factura fac, int nuevoConsumo);

#endif // METROGAS_H_INCLUDED