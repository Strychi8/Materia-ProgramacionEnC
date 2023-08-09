#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "negocio.h"

struct NegocioE{
  char nombreNegocio[100];
  int altura;
  int piso;
  char vereda;//p o i,par o impar
};

struct BilleteE{
  float precio;
  char nombreDolar[30];
};

Negocio crearNegocioPorTeclado (){
  Negocio n = malloc(sizeof(struct NegocioE));
  char auxNombre[100] = " ";
  char auxVereda[20] = " ";

  printf ("\nIngrese el nombre del Negocio: ");
  fflush (stdin);
  gets (auxNombre);
  strcpy (n->nombreNegocio,auxNombre);
  printf ("Ingrese la altura: ");
  scanf ("%d",&n->altura);
  printf ("Ingrese el piso: ");
  scanf ("%d",&n->piso);

  do{
    printf ("Ingrese la vereda (p o i, par o impar): ");
    fflush (stdin);
    scanf ("%c",&n->vereda);
    getchar();
    if((n->vereda != 'p' && n->vereda != 'i') ){
      printf("\nERROR: ");
      getchar();
    }
  }while (n->vereda != 'p' && n->vereda != 'i');
  
  return n;
}

Negocio crearNegocio (char negocio[100], int a, int p, char v){
  Negocio n = malloc(sizeof(struct NegocioE));

  strcpy (n->nombreNegocio,negocio);
  n->altura = a;
  n->piso = p;
  n->vereda = v;

  return n;
}

void mostrarNegocio (Negocio n){
  printf ("\n------ Negocio  ------");
  printf ("\nNombre del Negocio: %s",n->nombreNegocio);
  printf ("\nAltura: %d",n->altura);
  printf ("\nPiso: %d",n->piso);
  printf ("\nVereda: %c",n->vereda); 
}

char * getVereda (Negocio n){
  return n->vereda;
}
int getAltura (Negocio n){
  return n->altura;
}
int getPiso (Negocio n){
  return n->piso;
}
char * getNombreN (Negocio n){
  return n->nombreNegocio;
}
float getPrecio (Billete b){
  return b->precio;
}
char * getNombreDolar (Billete b){
  return b->nombreDolar;
}

void setAltura (Negocio n, int nuevaAltura){
  n->altura = nuevaAltura;
}
void setPiso (Negocio n, int nuevoPiso){
  n->piso = nuevoPiso;
}
void setNombreN (Negocio n, char nuevoNombreN){
  strcpy (n->nombreNegocio,nuevoNombreN);
}
void setVereda (Negocio n, char nuevaVereda){
  n->vereda = nuevaVereda;
}

void destruirNegocio (Negocio n){
  free(n);
}

void menuOpciones(){
  int opcion=0;
  do{
    printf ("\n1) Mostrar los primeros n numeros naturales de mayor a menor");
    printf ("\n2) Mostrar los primeros n numeros naturales");
    printf ("\n0) Salir");
    printf ("\n\nIngrese una opcion: ");
    scanf ("%d",&opcion);
   switch (opcion){
      case mostrarDeMayorAMenor: numNaturalesDeMayorAMenor(10); break;
      case mostrarPrimeroNumNaturales: primerosNumNaturales(10); break;
      case salir: break;
      default: printf ("\nERROR: Opcion no valida\n");
    }
  }while (opcion != salir);
}

void numNaturalesDeMayorAMenor (int n){
    if (n==0){
        return 0;
    }
    printf ("%d  ",n);
    numNaturalesDeMayorAMenor(n-1);
}

void primerosNumNaturales (int n){
    if (n==0){
        return 0;
    }
    primerosNumNaturales(n-1);
    printf ("%d  ",n);
}

float pedirNumero (){
   float num;
   printf ("\nIngrese un numero del vector: ");
   scanf ("%f",&num);
  return num;
}

int busquedaBinaria (int v[], int t, int buscarNum){
    buscarNum = pedirNumero();
    int posInicial=0;
    int posFinal=0;
    int posCentro=0;
    posFinal = t-1;
    while (posInicial <= posFinal){
        posCentro = (posInicial+posFinal)/2;
        if (v[posCentro] == buscarNum){
            return posCentro;
        } else {
           if (buscarNum>v[posCentro]){
            posInicial = posCentro+1;
           }else {
            posFinal = posCentro-1;
           }
        }
    }
    return -1;
}

void cargarDolares (Billete v[], int n){
    int contadorBilletes = 0;
    //Lectura
    //1) Abrir el archivo
    FILE * puntero = fopen("archivoDolar.txt", "r");

    //2)Leer
    while (!feof(puntero)){
     char aux[40] = " ";
     //No hace falta el fflush
     fgets(aux, 40 ,puntero); //Busca un \n
     //Persona <------ aux CHAR
     v[contadorBilletes]  = charABillete(aux, 40);
     contadorBilletes++;
    }
    //3) Cerrar
    fclose(puntero);
}

Billete charABillete (char c[], int n){
  Billete b = malloc(sizeof(struct BilleteE));

  int pos1=0;
  char auxPrecio[40] = " ";
  char auxNombreD[40] = " ";
  int i;

  for (i=0; i<n; i++){
    if (c[i]=='+'){
        pos1 = i;
    }
  }
  for (i=0; i<pos1; i++){
    auxNombreD[i] = c[i];
  }
  for (i=pos1+1; i<n; i++){
    auxPrecio[i-pos1-1] = c[i];
  }
  strcpy (b->nombreDolar,auxNombreD);
  b->precio = atof(auxPrecio);

  return b;
}

void ordenarValorDolar (Billete v[], int n){
   Billete auxValor;
   int i,j;

   for (i=0; i<n; i++){
    for (j=0; j<n-1; j++){
        if (v[j]->precio > v[j+1]->precio){
            auxValor = v[j];
            v[j] = v[j+1];
            v[j+1] = auxValor;
        }
      }
    }
}

void mostrarDolares (Billete v[], int n){
   for ( int i = 0; i<n; i++){
       if (getPrecio (v[i]) != -1){
         printf("%s+%.2f\n", getNombreDolar (v[i]), getPrecio(v[i]));
        }
    }
}