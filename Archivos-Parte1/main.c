#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Producto {
   float precio;
   char nombreProducto[50];
};

//----- Carga por teclado ----
struct Producto cargarProductosPorTeclado ();
void mostrarProducto (struct Producto p);

//----- archivo.txt ----
void cargarProductos(struct Producto v[], int n);
struct Producto charAProducto(char c[], int n);
void guardarProductos (struct Producto v[],int n);

//---- Array ------
int buscarPosicionDisponible(struct Producto v[], int n);
void agregarProducto(struct Producto v[], int n, struct Producto p);
void iniciarProductos (struct Producto v[], int n);
void mostrarProductos (struct Producto v[],int n);

int main()
{
    //menuOpciones();
    int cantidad = 100;
    struct Producto vectorProductos [cantidad];
    
    printf("\n1) Carga y muestra de productos: ");
    cargarProductos (vectorProductos,cantidad);
    mostrarProductos (vectorProductos,cantidad);

    struct Producto p1;
    //struct Producto p2 = cargarProductosPorTeclado ();

    //agregarProducto (vectorProductos, cantidad, p1);
    //agregarProducto (vectorProductos, cantidad, p2);

    int opcion = 0;
   
    do{
       printf("\n---------- Menu Principal ----------\n ");
       printf ("\n1) Para agregar mas productos");
       printf ("\n0) Salir\n");
       printf ("\nEliga una opcion: ");
       scanf ("%d",&opcion);

     switch (opcion){
       case 1: p1 = cargarProductosPorTeclado ();
               agregarProducto (vectorProductos,cantidad,p1); break;

       case 0: break;

       default: printf ("\nERROR: Opcion no valida\n");
      }
    }while (opcion != 0);
    
    printf("\n2) Muestro y guardo los productos en el archivoProductos.txt: ");
    mostrarProductos (vectorProductos, cantidad);
    guardarProductos (vectorProductos,cantidad);

    return 0;
}

struct Producto cargarProductosPorTeclado (){
  struct Producto p;
  char auxNombre[50] = " ";
  printf ("\nIngrese el nombre del producto: ");
  fflush (stdin);
  gets(auxNombre);
  strcpy (p.nombreProducto,auxNombre);
  printf ("Ingrese el precio: ");
  scanf ("%f",&p.precio);

  printf ("\nCREADA..... :D\n");
  system("cls");

  return p;
}

void iniciarProductos (struct Producto v[], int n){
    //Inicio el array para que no tenga basura
    for (int i = 0; i<n; i++){
       v[i].precio = -1;
    }
}
void cargarProductos(struct Producto v[], int n){
    iniciarProductos(v, n);

    FILE * puntero = fopen("archivoProductos.txt", "r");

    while(!feof(puntero)){
       char aux[40] = " ";
       fgets(aux, 40, puntero);
       struct Producto p = charAProducto(aux, 40);
       agregarProducto(v,n,p);
       //guardarProductos (v,n);
    }

    fclose(puntero);
}

int buscarPosicionDisponible(struct Producto v[], int n){
    int posicion = -9;
    int i = 0;

    while(posicion==-9&&i<n){
        if(v[i].precio==-1){
            posicion = i;
        }
       i++;
    }

    return posicion;
}

void agregarProducto(struct Producto v[], int n, struct Producto p){
    int i = buscarPosicionDisponible(v,  n);

    if(i!=-9){
        v[i] = p;
    }else {
        printf("\nYa no hay espacio para agregar!!!\n");
    }
}
struct Producto charAProducto(char c[], int n){
    //El formato es precio;nombre
    int pos1 = 0;
    int i;
    char auxNombre[40]=" ";
    char auxPrecio[40]=" ";
    struct Producto p;

    for (i = 0; i<n; i++){
        if(c[i]==';'){
            pos1 = i;
            i = n; //Así termino el for
        }
    }

    for (i = 0; i<pos1; i++){
        auxPrecio[i]= c[i];
        //p.nombre[i] = c[i]; PERFECTO...
    }

    for (i = pos1+1; i<n ; i++){
      auxNombre[i-pos1 -1]= c[i];
    }

    p.precio = atof(auxPrecio);
    strcpy(p.nombreProducto, auxNombre);

    return p;
};

void guardarProductos(struct Producto v[], int n){
    FILE * puntero = fopen("archivoProductos.txt", "w");

    for ( int i = 0; i<n; i++){
        if(v[i].precio != -1){
         fprintf(puntero, "%.2f;%s\n", v[i].precio, v[i].nombreProducto);
        }
    }

    fclose(puntero);
}

void mostrarProductos(struct Producto v[], int n){
    printf("\n");
    for ( int i = 0; i<n; i++){
        if (v[i].precio != -1){
            mostrarProducto(v[i]);
        }
    }
    printf("\n");
}

void mostrarProducto (struct Producto p){
   printf("\n");
   printf ("Precio: $ %.2f --- Nombre: %s",p.precio,p.nombreProducto);
}