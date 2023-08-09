#ifndef TEATROS_H_INCLUDED
#define TEATROS_H_INCLUDED

struct TeatroE;
typedef struct TeatroE * Teatro;

//PRE: t tiene que ser menor que 0 y el vector tiene que estar declarado
//POST: Se inicializa el codigo y la capacidad en -1, y el nombre y la direccion en " "
//En esas posiciones se podran guardar nuevos datos
void iniciarLosTeatros (Teatro v[], int t);

int getCodigo (Teatro t);
char * getNombreT (Teatro t);
char * getDireccion (Teatro t);
int getCapacidad (Teatro t);

void setCodigo (Teatro t, int nuevoCodigo);
void setNombre (Teatro t, char nuevoNombre[40]);
void setDireccion (Teatro t, char nuevaDireccion[40]);
void setCapacidad (Teatro t, int nuevaCapacidad);

//PRE: t tiene que ser menor que 0, el array tiene que estar declarado
//Se declara el codigo por parametro
//POST: Se elimina un teatro con el codigo identificador
void eliminarTeatro (Teatro v[], int t, int codigo);
//PRE: t tiene que ser menor que 0, el array tiene que estar declarado
//Se declaran por parametros cod,nom,dir y cap
//POST: Se agrega un teatro
void agregarTeatro (Teatro v[], int t, int cod, char nom[40], char dir[40], int cap);
//PRE: t tiene que ser menor que 0, el array tiene que estar inicializado
//POST: Se guardan los datos en el archivo teatro.txt
void guardarTeatros (Teatro v[], int t);
//PRE: t tiene que ser menor que 0 y el array tiene que estar declarado
//POST: Se muestran los datos de los teatros
void mostrarTeatros (Teatro v[], int t);

#endif // TEATROS_H_INCLUDED
