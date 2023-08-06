#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define COL 5
#define LARGO_ORACION 30

void mostrarVector (int v[], int ren);
//PRE: la variable ren tiene que ser positivo
//POST: Se inicializa el vector v en 0
void cargarVectorConCeros (int m[][COL], int ren, int v[]);
//PRE: mini debe ser menor que maxi
//POST: retorna una variable result aleatoria
int aleatorioEntre (int mini, int maxi);
//PRE: la variable ren tiene que ser positivo, mini debe ser menor que maxi
//POST: se carga la matriz m, con aleatorios entre mini y maxi
void cargarMatrizAleatorio (int m[][COL], int ren, int mini, int maxi);
//PRE:
//POST: Muestra la carga de una matriz aleatoria
int buscarEnLaMatriz (int m[][COL], int ren, int numeroRepetido);
//PRE: la variable ren tiene que ser positivo, mini debe ser menor que maxi
//POST: se carga la matriz m, con aleatorios entre mini y maxi SIN REPETIR
void cargarMatrizAleatorioSinRepetir (int m[][COL], int ren, int mini, int maxi);
//PRE: la variable ren tiene que ser positivo
//POST: se realiza la suma por renglones de los numeros de la matriz
void sumarPorRenglones (int m[][COL], int ren, int v[]);
//PRE: la variable ren tiene que ser positivo
//POST: se realiza la suma por columnas de los numeros de la matriz
void sumarPorColumnas (int m[][COL], int ren, int v[]);
//PRE: ren tiene que ser positivo
//POST: se muestra el maximo por renglones de los numeros de la matriz
void maximoDelRenglon (int m[][COL], int ren, int v[]);
//PRE: la variable ren tiene que ser positivo, debe estar cargada la matriz
//POST: Se realiza el promedio de cada uno de los renglones de los numeros de la matriz
//Cada suma se guarda en el vector v
void promedioPorRenglones (int m[][COL], int ren, float v[]);
//PRE: la variable ren tiene que ser positivo, debe estar cargada la matriz
//POST: Se realiza el promedio de cada uno de las columnas de los numeros de la matriz
//Cada suma se guarda en el vecto v
void promedioPorColumnas (int m[][COL], int ren, float v[]);
//PRE: la variable ren tiene que ser positivo, debe estar cargada la matriz
//POST: Se suma la matriz m con la matriz m1, se guarda el resultado en la matriz  m3
void sumaDeMatrices (int m[][COL], int m1[][COL], int ren, int m3[][COL]);
//PRE: la variable ren tiene que ser positivo, debe estar cargada la matriz
//POST: Se resta la matriz m1 con la matriz m2, se guarda el resultado en la matriz m3
void restaDeMatrices (int m[][COL], int m1[][COL], int ren, int m3[][COL]);
//PRE: COL es global debe ser mayor que 0
//POST: Se realiza la multiplicacion entra las matrices m y m1 y se obtiene el resultado
//La matriz debe ser cuadrado
void multiplicacionDeMatrices (int m[COL][COL], int m1[COL][COL], int m3[COL][COL]);
//PRE: la variable ren tiene que ser positivo, la matriz ya debe estar cargada
//POST: se muestra el resultado de la matriz
void mostrarMatriz (int m[][COL], int ren);
//PRE: col debe ser mayor que 0, es la cantidad de oraciones que tenemos, las oraciones
//tienen LARGO_ORACION. busco es la oracion que estoy buscando, tiene tamaño LARGO_ORACION
//POST: Se devuelve la posicion de la oracion, o -1 si no la encuentra
int buscarOracion (char oraciones[][LARGO_ORACION], int col, char busco[]);

int main(){

    srand(time(0));
    int mini = 1;
    int maxi = 10;
    int renglon = 5;
    int matriz [renglon][COL];

    cargarMatrizAleatorio (matriz,renglon,mini,maxi);
    printf ("\n1) La matriz aleatoria es:\n");
    mostrarMatriz (matriz, renglon);

    int vectorSumaPorRenglones [renglon];
    printf ("\n2) La suma de la matriz por RENGLONES es: ");
    cargarVectorConCeros (matriz, renglon, vectorSumaPorRenglones);
    sumarPorRenglones (matriz, renglon, vectorSumaPorRenglones);
    mostrarVector (vectorSumaPorRenglones, COL);

    int vectorSumaPorColumnas [COL];
    printf ("\n\n3) La suma de la matriz por COLUMNAS es: ");
    cargarVectorConCeros (matriz, renglon, vectorSumaPorColumnas);
    sumarPorColumnas (matriz, renglon, vectorSumaPorColumnas);
    mostrarVector (vectorSumaPorColumnas, COL);

    int vectorMax[renglon];
    printf ("\n\n4) El maximo de la matriz por RENGLON es: ");
    maximoDelRenglon(matriz,renglon,vectorMax);
    mostrarVector (vectorMax, COL);

    //float renglon1 = (float) renglon;
    float vectorPromDeRenglones[renglon];
    printf ("\n\n5) El promedio de la suma de los RENGLONES es: ");
    promedioPorRenglones (matriz, renglon, vectorPromDeRenglones);

    float vectorPromDeColumnas[renglon];
    printf ("\n\n6) El promedio de la suma de las COLUMNAS es: ");
    promedioPorColumnas (matriz, renglon, vectorPromDeColumnas);


    int matriz1[renglon][COL];
    int matriz3[renglon][COL];
    printf ("\n\n7) La matriz 2 es:\n");
    cargarMatrizAleatorio (matriz1,renglon,mini,maxi);
    mostrarMatriz (matriz1, renglon);

    printf ("\n8) La suma de las 2 matrices es:\n");
    sumaDeMatrices (matriz,matriz1,renglon,matriz3);

    printf ("\n9) La resta de las 2 matrices es:\n");
    restaDeMatrices (matriz,matriz1,renglon,matriz3);

    printf ("\n10) La multiplicacion de las 2 matrices es:\n");
    multiplicacionDeMatrices (matriz,matriz1,matriz3);

    char buscar[LARGO_ORACION] = " ";
    int col = 5;
    char oraciones[col][LARGO_ORACION];
    printf ("\n11) Devuelve ----> %d", buscarOracion (oraciones, col, buscar));

    printf ("\n");
    return 0;
}
int aleatorioEntre (int mini, int maxi){
    int result = 0;
    result = mini + rand()%(maxi-mini+1);

    return result;
}
void cargarVectorConCeros (int m[][COL], int ren, int v[]){
    int i;
    for (i=0; i<COL; i++){
        v[i] = 0;
     }
}
void cargarMatrizAleatorio (int m[][COL], int ren, int mini, int maxi){
    int r,c;
    for (r=0; r<ren; r++){
        for (c=0; c<COL; c++){
            m[r][c] = mini + rand()%(maxi-mini+1);
        }
    }
}
int buscarEnLaMatriz (int m[][COL], int ren, int numeroRepetido){
    int r,c;
    int pos = -1;
    for (r=0; r<ren; r++){
        for (c=0; c<COL; c++){
            if (m[r][c] == numeroRepetido){
               pos=m[r][c];
            }
        }
    }
    return pos;
}
void cargarMatrizAleatorioSinRepetir (int m[][COL], int ren, int mini, int maxi){
    int c,r;
    int numeroNuevo = 0;
    int resultadoBusqueda = 0;

    for (r=0; r<ren; r++){
        for (c=0; c<COL; c++){
            do{
            numeroNuevo = aleatorioEntre(mini, maxi);
            resultadoBusqueda = buscarEnLaMatriz (m, ren, numeroNuevo);
            }while (resultadoBusqueda != -1);

            m[r][c] = numeroNuevo;
        }
        printf ("\n");
    }
}
void sumarPorRenglones (int m[][COL], int ren, int v[]){
    int r,c;
    for (r=0; r<ren; r++){
        for (c=0; c<COL; c++){
            v[r] = v[r]+m[r][c];
        }
    }
}
void sumarPorColumnas (int m[][COL], int ren, int v[]){
    int r,c;
    for (r=0; r<ren; r++){
        for (c=0; c<COL; c++){
            v[c] = v[c]+m[r][c];
        }
    }
}
void promedioPorRenglones (int m[][COL], int ren, float v[]){
    int r,c;
    float suma=0;
    for (r=0; r<ren; r++){
        for (c=0; c<COL; c++){
            suma = suma+m[r][c];
        }
        v[r]=suma/ren;
        suma=0;
    }
    for(r=0; r<ren; r++){
        printf ("[%.2f] ",v[r]);
    }

}
void promedioPorColumnas (int m[][COL], int ren, float v[]){
    int r,c;
    float suma=0;
    for (c=0; c<COL; c++){
        for (r=0; r<ren; r++){
            suma = suma+m[r][c];

        }
        v[c]=suma/COL;
        suma=0;
    }

    for(c=0; c<COL; c++){
        printf ("[%.2f] ",v[c]);
    }
}
void maximoDelRenglon (int m[][COL], int ren, int v[]){
    int r,c;
    int mayor=v[0];
    for (r=0; r<ren; r++){
        mayor = m[r][0];
        for (c=0; c<COL; c++){
            if (m[r][c]>mayor){
                mayor=m[r][c];
            }
            v[r] = mayor;
        }
    }
}
void sumaDeMatrices (int m[][COL],int m1[][COL], int ren, int m3[][COL]){
    int r,c;
    for (r=0; r<ren; r++){
        for (c=0; c<COL; c++){
            m3[r][c] = m[r][c]+m1[r][c];
        }
    }
    for (r=0; r<ren; r++){
        for (c=0; c<COL; c++){
            printf ("[%d] ",m3[r][c]);
        }
        printf ("\n");
    }
}
void restaDeMatrices (int m[][COL], int m1[][COL], int ren, int m3[][COL]){
     int r,c;
    for (r=0; r<ren; r++){
        for (c=0; c<COL; c++){
            m3[r][c] = m[r][c] - m1[r][c];
        }
    }
    for (r=0; r<ren; r++){
        for (c=0; c<COL; c++){
            printf ("[%d] ",m3[r][c]);
        }
        printf ("\n");
    }
}
void multiplicacionDeMatrices (int m[COL][COL], int m1[COL][COL], int m3[COL][COL]){
    int r,c,k;
    for (r=0; r<COL; r++){
        for (c=0; c<COL; c++){
                m3[r][c]=0;
                for (k=0; k<COL; k++){
                    m3[r][c] = (m3[r][c] + (m[r][k]*m1[k][c]));
                }
        }
    }
    for (r=0; r<COL; r++){
        for (c=0; c<COL; c++){
            printf ("[%d] ",m3[r][c]);
        }
        printf ("\n");
    }
}
void mostrarMatriz (int m[][COL], int ren){
    int r,c;
    for (r=0; r<ren; r++){
        for (c=0; c<COL; c++){
            printf ("[%d] ",m[r][c]);
        }
        printf ("\n");
    }
}
void mostrarVector (int v[], int ren){
    int i;
    for (i=0; i<ren; i++){
        printf ("[%d] ",v[i]);
    }
}
int buscarOracion (char oraciones[][LARGO_ORACION], int col, char busco[]){
    int l,c;
    int pos = -1;
    for (c=0; c<col; c++){
        for (l=0; l<LARGO_ORACION; l++){
            if (strcmp(oraciones,busco)==0){
               printf ("\nSu oracion fue encontrada. ");
               pos = l;
            }
        }
    }
    return pos;
}