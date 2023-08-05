#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MESES 12

//PRE: el tamanio tiene que ser mayor a 0
//POST: se retorna una variable entera
int elegirCantidadDeEmpresa ();
//PRE: cantEmpresa tiene que ser positivo
//POST: se realiza la carga de la matriz aleatoria
void cargarMatrizAleatoria (float m[][MESES], int cantEmpresa);
//PRE: cantEmpresa tiene que ser positivo, la matriz ya debe estar cargada
//POST: se muestra la matriz aleatoria
void mostrarMatriz (float m[][MESES], int cantEmpresa);
//PRE:
//POST:
void gananciaAnualPorEmpresas (float m[][MESES], int cantEmpresa, float v[]);
//PRE:
//POST:
void gananciaTotalPorMeses (float m[][MESES], int cantEmpresa, float v[]);
//PRE:
//POST:
void mostrarVector (float v[], int t);
//PRE:
//POST:
void encontrarMinimoMatriz (float m[][MESES], int cantEmpresa, int posMin[]);
//PRE:
//POST:
void mostrarMinimo (int v[], int t);
//PRE: t tiene que ser positivo
//POST: se carga el nombre y el apellido en una sola variable
void cargarNombreYApellido (char nomyape[], int t);
//PRE: el nomyape tiene que estar cargado
//POST: se crea la contrasenia a partir de la variable nomyape
void crearContrasenia (char nomyape[], int t, char contrasenia[]);
//PRE: la contrasenia ya tiene que estar creada
//POST: se muestra la cadena
void mostrar (char cadena[], int t);

int main(){

    printf ("\nTEMA 3\n");
    srand (time(0));
    int tam=50;
    char nombreYApellido[tam];
    char contra[tam];

    cargarNombreYApellido (nombreYApellido, tam);
    crearContrasenia (nombreYApellido, tam, contra);
    mostrar (nombreYApellido, tam);
    mostrar (contra, tam);

    int tam1 = elegirCantidadDeEmpresa();
    printf ("La cantidad que eligio fue ----> %d \n",tam1);

    int cantEmpresas=tam1;
    float matriz[cantEmpresas][MESES];
    cargarMatrizAleatoria(matriz, cantEmpresas);
    printf ("\nLa matriz es:\n");
    mostrarMatriz (matriz, cantEmpresas);

    float vectorAnual[cantEmpresas];
    printf ("\nLa ganancia que gano cada Empresa por Anio fue:\n");
    gananciaAnualPorEmpresas (matriz,cantEmpresas,vectorAnual);
    mostrarVector (vectorAnual, cantEmpresas);

    float vectorTotalMeses [cantEmpresas];
    printf ("\n\nLa ganancia total por meses que ganaron las empresas es:\n");
    gananciaTotalPorMeses (matriz, cantEmpresas, vectorTotalMeses);
    mostrarVector (vectorTotalMeses, MESES);

    int posMinimo[2];
    encontrarMinimoMatriz (matriz, cantEmpresas,posMinimo);
    mostrarMinimo (posMinimo, 2);

    printf ("\n\n");
    return 0;
}

int elegirCantidadDeEmpresa (){
   int cant;
   printf ("\nIngrese la cantidad de empresas: ");
   scanf ("%d",&cant);
   while (cant<3){
      printf ("\nERROR: Ingrese otro numero que no sea MENOR que 3: ");
      scanf ("%d",&cant);
   }

   return cant;
}

void cargarMatrizAleatoria (float m[][MESES], int cantEmpresa){
    int r,c;
    for (r=0; r<cantEmpresa; r++){
        for (c=0; c<MESES; c++){
            m[r][c] =((float) (-100 + rand()%601)/1.001);
        }
    }
}

void mostrarMatriz (float m[][MESES] ,int cantEmpresa){
    int r,c;
    for (r=0; r<cantEmpresa; r++){
        for (c=0; c<MESES; c++){
            printf (" %.2f ",m[r][c]);
        }
        printf ("\n");
    }
}

void gananciaAnualPorEmpresas (float m[][MESES], int cantEmpresa, float v[]){
    int r,c;
    for (r=0; r<cantEmpresa; r++){
        v[r]=0;
        for (c=0; c<MESES; c++){
            v[r] = v[r] + m[r][c];
        }
    }
}

void gananciaTotalPorMeses (float m[][MESES], int cantEmpresa, float v[]){
    int r,c;
    for (r=0; r<cantEmpresa; r++){
        v[r]=0;
        for (c=0; c<MESES; c++){
            v[c] = v[c] + m[r][c];
        }
    }
}

void mostrarVector (float v[], int t){
    int i;
    for (i=0; i<t; i++){
        printf (" %.2f ",v[i]);
    }
}

void encontrarMinimoMatriz (float m[][MESES], int cantEmpresa, int posMin[]){
    int r,c;
    float min = m[0][0];
    posMin[0]=0;
    posMin[1]=0;
    for (r=0; r<cantEmpresa; r++){
        for (c=0; c<MESES; c++){
            if (m[r][c]<min){
                min = m[r][c];
                posMin[0] = r;
                posMin[1] = c;
            }
        }
    }

}

void mostrarMinimo (int v[], int t){
    int i;
    printf ("\n\nEl minimo esta en la posicion: ");
    for (i=0; i<2; i++){
        printf ("[%d]  ",v[i]);
    }
}

void cargarNombreYApellido (char nomyape[], int t){
    printf ("\nIngrese su nombre y apellido: ");
    fflush (stdin);
    gets (nomyape);
}

void crearContrasenia (char nomyape[], int t, char contrasenia[]){
    strcpy(contrasenia, nomyape);
    int i,j;
    int vocales[10] = {'a','e','i','o','u','A','E','I','O','U'};

    for (i=0; i<t; i++){
        for (j=0; j<10; j++){
            if (contrasenia[i] == vocales[j]){
                contrasenia[i] = 'X';
            }
        }
    }
}
void mostrar (char cadena[],int t){
    printf ("\nPassword: %s \n",cadena);
}

