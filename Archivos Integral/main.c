#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mercaderia{
   char nombre[20];
   int codigo;
   float precio;
};

//------------------Mercaderia----------------------------
//Pre: Ninguna
//Post: Pide los datos por teclado y retorna una Mecaderia
struct Mercaderia crearMercaderiaPorTeclado();
//Pre: La mercaderia tiene que estar creada
//post: Muestra los datos de la mercaderia
void mostrarMercaderia(struct Mercaderia m);

//------------------Archivo.txt----------------------------
//Pre: El archivo tiene que estar creado con el siguiente formato
//nombre;codigo;precio
//Post: Carga el array v, con las mercaderias que estan en el archivo
void cargarMercaderias(struct Mercaderia v[], int n);
//Pre: El array c[] tiene que tener el formato nombre;codigo;precio
//Post: Transforma ese array en un elemento mercaderia y lo retorna
struct Mercaderia charAMercaderia(char c[], int n);
//Pre: El array v tiene que estar iniciado
//Post: Guarda los datos en el archivo
void guardarMercaderias(struct Mercaderia v[], int n);

//------------------ARRAY de Mercaderia----------------------------
//pre: n debe ser mayor a cero, el array tiene que estar declarado
//post: En cada elemento, marca con precio = -1 los elementos "vacios"
//En esas posiciones se podran guardar nuevos datos
void iniciarMercaderias(struct Mercaderia v[], int n);
//Pre: Se tiene que iniciar la mercaderia inicialmente con precio= -1
//Post: nos devuelve en que posicion podemos escribir una nueva mercaderia
int buscarPosicionDisponible(struct Mercaderia v[], int n);
//Pre: la mercaderia tiene que existir, y el array tiene que estar iniciado correctamente
//post: agrega esa mercaderia a alguna posicion del array
void agregarMercaderia(struct Mercaderia v[], int n, struct Mercaderia m);
//Pre: El array tiene que estar iniciado/cargado
//Post: Muestra por consola el estado de las mercaderias
void mostrarMercaderias(struct Mercaderia v[], int n);

//--------------Para que agreguen y mejoren---------------------
//Modifica solo el precio de la mercaderia con el codigo indicado
void modificarMercaderia(struct Mercaderia v[], int n, int codigo);
void eliminarMercaderia(struct Mercaderia v[], int n, int codigo);
int busquedaPorCodigo (struct Mercaderia v[],int n,int codigoBuscado);
void ordenarPorCodigo (struct Mercaderia v[],int n);
//Crear un menu que nos de las opciones de ver, cargar, modificar, eliminar
//guardar, etc
//en vez de borrar todo el archivo y escribirlo con w, podrian ir
//agregando cada vez que se crea una nueva mercaderia y usar a, generen
//esa modificación

int main()
{
    printf("\nEjemplo Integrador ABMs - Archivos\n");

    int cantidad = 13;
    int opcion = 0;
    int auxCodigo = 0;
    struct Mercaderia mercaderias[cantidad];

    do{
      printf ("\n1) Cargar Mercaderia\n");
      printf ("2) Mostrar Mercaderia\n");
      printf ("3) Modificar Mercaderia\n");
      printf ("4) Eliminar Mercaderia\n");
      printf ("5) Guardar Mercaderia en el archivo\n");
      printf ("0) Salir\n");
      printf ("\nElija una de las opciones: ");
      scanf ("%d",&opcion);

     switch(opcion){
       case 1: cargarMercaderias (mercaderias,cantidad); break;
       case 2: mostrarMercaderias (mercaderias,cantidad); break;
       case 3:  printf ("\nIngrese el codigo para modificar productos: ");
               scanf ("%d",&auxCodigo);
               modificarMercaderia (mercaderias,cantidad,auxCodigo); break;
       case 4: printf ("\nIngrese el codigo para eliminar productos: ");
              scanf ("%d",&auxCodigo);
              eliminarMercaderia (mercaderias,cantidad,auxCodigo); break;
       case 5: guardarMercaderias(mercaderias, cantidad); break;
       case 0: break;
       default: printf ("\nERROR: Ingrese otra opcion\n");
      }
    }while (opcion != 0);

    // cargarMercaderias(mercaderias, cantidad);
     //mostrarMercaderias(mercaderias, cantidad);

    //struct Mercaderia m1 = crearMercaderiaPorTeclado();
    //struct Mercaderia m2 = crearMercaderiaPorTeclado();

    //agregarMercaderia(mercaderias, cantidad, m1);
    //agregarMercaderia(mercaderias, cantidad, m2);

   // mostrarMercaderias(mercaderias, cantidad);

    //ordenarPorCodigo (mercaderias,cantidad);

    //mostrarMercaderias (mercaderias,cantidad);

    return 0;
}

struct Mercaderia crearMercaderiaPorTeclado(){
    struct Mercaderia m;
    char aux[20]= " ";

    printf("\n\nCreando mercaderia Nueva...\n") ;
    printf("\nIngrese el nombre: ") ;
    fflush(stdin);
    gets(aux);
    strcpy(m.nombre, aux);

    printf("Ingrese el precio: ");
    scanf("%f", &m.precio);

    printf("Ingrese el codigo: ");
    scanf("%d", &m.codigo);

    printf("\nCreada!!!  :)\n") ;
    system("cls");//borro la consola

    return m;
};

void mostrarMercaderia(struct Mercaderia m){
    printf("\n-----------------------------------------\n");
    printf("Mercaderia: %s --- Codigo: %d --- Precio: $ %.2f",
           m.nombre, m.codigo, m.precio);
}

void iniciarMercaderias(struct Mercaderia v[], int n){
    //inicio el array para que no tenga basura
    for ( int i = 0; i<n; i++){
        v[i].precio = -1;
    }
}

void agregarMercaderia(struct Mercaderia v[], int n, struct Mercaderia m){
    int i = buscarPosicionDisponible(v,  n);

    if(i != -9){
       v[i] = m;
    }else{
       printf("\nYa no hay espacio para agregar!!!\n");
    }
}

void mostrarMercaderias(struct Mercaderia v[], int n){

    for (int i = 0; i<n; i++){
        if (v[i].precio != -1 && v[i].codigo != 0){
           mostrarMercaderia(v[i]);
        }
    }
}

int buscarPosicionDisponible(struct Mercaderia v[], int n){
    int posicion = -9;
    int i = 0;

    while(posicion == -9 && i<n){
        if(v[i].precio == -1){
            posicion = i;
        }
       i++;
    }

    return posicion;
}

void cargarMercaderias(struct Mercaderia v[], int n){
    iniciarMercaderias(v, n);

    FILE * puntero = fopen("archivoMercaderias.txt", "r");

    while(!feof(puntero)){
        char aux[40] = " ";
        fgets(aux, 40, puntero);
        struct Mercaderia m = charAMercaderia(aux, 40);
        //agregarMercaderia(v,n,m);
    }

    fclose(puntero);
}

struct Mercaderia charAMercaderia(char c[], int n){
    //El formato es nombre; codigo; precio
    int pos1 = 0;
    int pos2 = 0;
    int i;
    char auxNombre[40]=" ";
    char auxCodigo[40]=" ";
    char auxPrecio[40]=" ";

    struct Mercaderia m;

    for (i = 0; i<n; i++){
        if(c[i]==';'){
            pos1 = i;
            i = n; //Así termino el for
        }
    }
    for (i = pos1+1; i<n; i++){
        if(c[i]==';'){
            pos2 = i;
        }
    }
    for (i = 0; i<pos1; i++){
        auxNombre[i]= c[i];
    }
    for (i = pos1+1; i<pos2; i++){
        auxCodigo[i-pos1-1]= c[i];
    }
     for (i = pos2+1; i<n; i++){
        auxPrecio[i-pos2-1]= c[i];
    }

    strcpy(m.nombre, auxNombre);
    m.codigo = atoi(auxCodigo);
    m.precio = atof(auxPrecio);

    return m;
};

void guardarMercaderias(struct Mercaderia v[], int n){
    FILE * puntero = fopen("archivoMercaderias.txt", "w");

    for ( int i = 0; i<n; i++){
        if(v[i].precio != -1 && v[i].codigo != 0){
            fprintf(puntero, "%s;%d;%f\n", v[i].nombre, v[i].codigo, v[i].precio);
        }
    }

    fclose(puntero);
}
// la busqueda por codigo es obligatoria para la modificacion y la eliminacion
int busquedaPorCodigo (struct Mercaderia v[], int n, int codigoBuscado){
  int i;
  int result = -1;

  for (i=0; i<n; i++){
      if (v[i].codigo == codigoBuscado){
          result = i;
      }
  }

  return result;
}

void modificarMercaderia(struct Mercaderia v[], int n, int codigo){
    int i = busquedaPorCodigo (v,n,codigo);
    int opcion = 0;
    char auxNombre[20] = " ";

    if (i != -1){
       do{
         printf ("\n\n1) Modificar precio\n");
         printf ("2) Modificar nombre\n");
         printf ("0) No modificar nada\n");
         printf ("\nElija una opcion: ");
         scanf ("%d",&opcion);

         switch (opcion){
            case 1: printf ("\nIngrese el precio nuevo: ");
                   scanf ("%f",&v[i].precio); break;
            case 2: printf ("\nIngrese el nombre nuevo: ");
                    fflush (stdin);
                    gets (auxNombre);
                    strcpy (v[i].nombre,auxNombre); break;
            case 0: break;
            default: printf ("\nERROR; Ingrese otra opcion\n");
         }
       }while (opcion != 0);
    }

}
void eliminarMercaderia(struct Mercaderia v[], int n, int codigo){
    int i = busquedaPorCodigo (v,n,codigo);

    if (i != -1){
        v[i].codigo = 0;
        v[i].precio = -1;
        strcpy (v[i].nombre,"XXI");
    }
}
// este procedimiento sera fundamental para la eliminacion de productos
// deja la basura en la ultima posicion
void ordenarPorCodigo (struct Mercaderia v[], int n){
   struct Mercaderia auxCodigo;
   int i,j;

   for (i=0; i<n; i++){
      for (j=0; j<n-1; j++){
         if(v[j].codigo < v[j+1].codigo){
             auxCodigo = v[j];
             v[j] = v[j+1];
             v[j+1] = auxCodigo;
         }
      }
   }
}