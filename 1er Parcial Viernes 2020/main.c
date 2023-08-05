#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define PAISES 6
#define BIMESTRE 6

//PRE: t tiene que ser positivo
//POST: se carga la variable nombre
void cargarNombreDeUsuario(char nombre[], int t);
//PRE: t tiene que ser positivo
//POST: se carga la variable contrasenia
void cargarContrasenia(char contrasenia[], int t);
int contarVocales(char contrasenia[], int t);
int contarNumeros(char contrasenia[], int t);
//PRE: t tiene que ser positivo
//POST: se muestran los datos del usuario NOMBRE Y CONTRASENIA
void mostrarDatos(char nombre[], int t, char contrasenia[]);
void cargarMatrizAleatoriaParesSinRepetir (int m[PAISES][BIMESTRE], int mini, int maxi);
int buscarEnMatriz(int m[PAISES][BIMESTRE], int numRepetido);
//PRE: la matriz debe estar ya cargada
//POST: se muestra la matriz personalizada
void mostrarMatrizPersonalizada(int m[PAISES][BIMESTRE]);
void cargarDiagonalPrincipal(int m[PAISES][BIMESTRE], int diagonal[]);
void mostrarDiagonal (int diagonal[]);
float frecuenciaEnLaMatriz(int m[PAISES][BIMESTRE], int datoBuscado);
void mostrarModa (int m[PAISES][BIMESTRE], int datoBuscado);

int main()
{
    printf("\n--------- TEMA 3 ------------\n");
    srand (time(0));
    char nombreUsuario[30]= " ";
    char contra[30]= " ";
    int mini=1000;
    int maxi=9000;

    cargarNombreDeUsuario (nombreUsuario,30);
    cargarContrasenia (contra,30);
    mostrarDatos (nombreUsuario, 30, contra);

    int matriz[PAISES][BIMESTRE];
    cargarMatrizAleatoriaParesSinRepetir (matriz,mini,maxi);
    mostrarMatrizPersonalizada (matriz);

    int vectorDiagonal[PAISES];
    cargarDiagonalPrincipal (matriz,vectorDiagonal);
    mostrarDiagonal (vectorDiagonal);

    int dato;
    printf ("\nLa frecuencia del 4068 es: %f",frecuenciaEnLaMatriz(matriz,dato));

    mostrarModa(matriz,dato);

    printf ("\n");
    return 0;
}

void cargarNombreDeUsuario(char nombre[], int t){
     printf ("\nIngrese su nombre de usuario: ");
     fflush (stdin);
     gets (nombre);
}

void cargarContrasenia(char contrasenia[], int t){
     do{
       printf ("\nPor favor ingrese su contrasenia, debe tener por lo menos 2 numeros y 4 vocales: ");
       fflush (stdin);
       gets (contrasenia);

     }while (contarVocales (contrasenia, t)<4 || contarNumeros (contrasenia,t)<2);

}

int contarVocales(char contrasenia[], int t){
   int cont = 0;
   //diccionario
   for (int i=0; i<t; i++){
      if (contrasenia[i]=='a' || contrasenia[i]=='e' ||contrasenia[i]=='i' || contrasenia[i]=='o' || contrasenia[i]=='u' ){
        cont++;
      }
   }
   return cont;
}

int contarNumeros(char contrasenia[], int t){
    int cont = 0;
    char diccionario[9] = {1,2,3,4,5,6,7,8,9};

    for (int i=0; i<t; i++){
        if (contrasenia[i] == diccionario[i]){
            cont++;
        }
    }
    return cont;
}

void mostrarDatos(char nombre[], int t, char contrasenia[]){
    printf ("\n----- Sus Datos: ------\n");
    printf ("\nSu Nombre de Usuario es: %s ",nombre);
    printf ("\nSu Contrasenia es: %s ",contrasenia);
}

int aleatorioEntre (int mini, int maxi){
   int result;
   result = mini + rand() % (maxi-mini+1);

   if (result%2 != 0){
      result=result+1;
   }
    return result;
}

void cargarMatrizAleatoriaParesSinRepetir(int m[PAISES][BIMESTRE], int mini, int maxi){
    int c,r;
    int numeroNuevo = 0;
    int resultadoBusqueda = 0;

    for (r=0; r<PAISES; r++){
       for (c=0; c<BIMESTRE; c++){
          do{
               numeroNuevo = aleatorioEntre (mini, maxi);
               resultadoBusqueda = buscarEnMatriz (m, numeroNuevo);
          }while (resultadoBusqueda != -1);

           m[r][c] = numeroNuevo;
        }
    }
}

int buscarEnMatriz (int m[PAISES][BIMESTRE], int numRepetido){
    int pos = -1;
    int c,r;

    for (r=0; r<PAISES; r++){
       for (c=0; c<BIMESTRE; c++){
        if (m[r][c] == numRepetido){
            pos = m[r][c];
        }
       }
    }
    return pos;
}

void mostrarMatrizPersonalizada (int m[PAISES][BIMESTRE]){
     int r,c;
     printf ("\n\nPAISES: BIM1  BIM2  BIM3  BIM4  BIM5  BIM6\n");

     for (r=0; r<PAISES; r++){
        printf ("\nPAIS-%d",r);
        for (c=0; c<BIMESTRE; c++){
            printf (" %d ",m[r][c]);
        }
        printf ("\n");
     }
}

void cargarDiagonalPrincipal (int m[PAISES][BIMESTRE], int diagonal[]){
    int r,c;
    for (r=0; r<PAISES; r++){
        for (c=0; c<BIMESTRE; c++){
            if (r==c){
                diagonal[r] = m[r][c];
             }
        }
    }
}

void mostrarDiagonal (int diagonal[]){
    printf ("\n---------- DIAGONAL ------------\n");
    for (int r=0; r<PAISES; r++){
        printf ("%d       ||",diagonal[r]);
     }
    printf ("\n\n");
}

float frecuenciaEnLaMatriz (int m[PAISES][BIMESTRE], int datoBuscado){
   float frecuencia = 0;
   int cont = 0;

   for (int r=0; r<PAISES; r++){
      for (int c=0; c<BIMESTRE; c++){
          if (buscarEnMatriz(m,datoBuscado) == 1){
             cont++;
          }
      }
   }
   frecuencia = cont/(PAISES*BIMESTRE);

   return frecuencia;
}

void mostrarModa (int m[PAISES][BIMESTRE], int datoBuscado){

   float frecuencia = 0;
   int cont = 0;

   for (int r=0; r<PAISES; r++){
      for (int c=0; c<BIMESTRE; c++){
          if (buscarEnMatriz(m,datoBuscado)==1){
             cont++;
          }
      }
   }
   frecuencia = cont/(PAISES*BIMESTRE);

   int numeroModa = 0;
   int numeroModa1=0;
   int maxFrecuencia = frecuencia;

    for (int r=0; r<PAISES; r++){
        for (int c=0; c<BIMESTRE; c++){
            if(maxFrecuencia<frecuencia){
                maxFrecuencia = frecuencia;
                numeroModa = r;
                numeroModa1 = c;

            }
        }
    }

  printf ("\nEl numero de Moda del renglon es ---> %d",numeroModa);
  printf ("\nEl numero de Moda de la columna es ---> %d\n",numeroModa1);
}
