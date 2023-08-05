#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    /*Ejercicio 1: Crear una matriz de 12 columnas y 4 renglones, de números decimales, 
    cada valor explica las ganancias de 4 empresas distintas mes a mes.  

    A- Encontrar el total ganado por cada empresa al año.
    B- Encontrar cuanto se gano por mes contando a todas las empresas
    C- Calcular el total ganado por todas las empresas juntas.
    D- Encontrar que empresa gano mas y en qué mes.
    E- Que empresa gano menos y cuándo.
    F- Calcular el promedio de ganancias de cada empresa por bimestres. ¿Cuál gano mas en cada bimestre?*/
    printf("\nEjercicio 1:\n");
    srand(time(0));

    float matriz[12][4];
    int ren,col;
    float totalAnio[4]={0,0,0,0}; //INICIALIZAR SIEMPRE
    float totalMes[12]={0,0,0,0,0,0,0,0,0,0,0,0}; //INICIALIZAR SIEMPRE
    float sumaTotal=0;


    for (ren=0; ren<4; ren++){
        for (col=0; col<12; col++){
            matriz[col][ren] = rand()%50; //CARGO LA MATRIZ ALEATORIAMENTE
        }
    }
    printf("\nMatriz: \n");
    for (ren=0; ren<4; ren++){
        for (col=0; col<12; col++){
            printf ("[%.2f]  ",matriz[col][ren]); //MUESTRO LA MATRIZ
        }
        printf ("\n\n");
    }
    //PUNTO A
    for (ren=0; ren<4; ren++){
        for (col=0; col<12; col++){
            totalAnio[ren] = totalAnio[ren] + matriz[col][ren];//Total de cada empresa por año
        }
    }
    printf ("\nA) Total ganado por cada Empresa al anio: ");
    for (ren=0; ren<4; ren++){
        printf ("[%.2f]   ",totalAnio[ren]);
    }

    //PUNTO B
    printf ("\n\n");
    for (ren=0; ren<4; ren++){
        for (col=0; col<12; col++){
            totalMes[col] = totalMes[col] + matriz[col][ren];
        }
    }

    printf ("\nB) Total ganado por cada Empresa por Mes: ");
    for (col=0; col<12; col++){
        printf ("[%.2f]  ",totalMes[col]);
    }

    //PUNTO C
    printf ("\n\n");

    for (ren=0; ren<4; ren++){
        for (col=0; col<12; col++){
            sumaTotal = sumaTotal + matriz[col][ren];
        }
    }
    printf ("\nC) La suma total ganado por todas las empresas juntas es: %.2f",sumaTotal);

    //PUNTO D
    printf ("\n\n");
    int posR=0,posC=0;
    float max=matriz[0][0];
    float min=matriz[0][0];

    for (ren=0; ren<4; ren++){
        for (col=0; col<12; col++){
            if (matriz[col][ren]>max){
                max = matriz[col][ren];
                posR=  ren;
                posC = col;
            }
        }
    }

    printf ("\nD) La empresa que gano mas fue la empresa %d con %.2f y fue en el mes %d ",posR+1,max,posC+1);

    //PUNTO E

    printf ("\n\n");

    for (ren=0; ren<4; ren++){
        for (col=0; col<12; col++){
            if (matriz[col][ren]<min){
                min=matriz[col][ren];
                posR=ren;
                posC=col;
            }
        }
    }

    printf ("\nE) La empresa que gano menos fue la empresa %d con %.2f y fue en el mes %d ",posR+1,min,posC+1);

    //PUNTO F
    printf ("\n\n");
    printf ("\nF) ----------------- BIMESTRES --------------------");

    //Bucle que muestra el promedio de ganancias de cada empresa por bimestre
    for (ren=0; ren<4; ren++){
        for (col=0; col<12; col=col+2){
            printf ("\nEl promedio de la empresa %d en el bimestre %d genero: %.2f",ren+1,col/2,((matriz[col][ren]+matriz[col+1][ren])/2));
        }
    }
    
    /*Ejercicio 2: Crear aleatoriamente 2 matrices de 4x4 y generar matrices nuevas donde se:

    A- Haga Matriz1 + Matriz2
    B- Haga Matriz1 – Matriz2
    C- Matriz1.Matriz2*/
    printf("\n\nEjercicio 2:\n");
    srand(time(0));

    ren = 4;
    col = 4;
    int mat[ren][col];
    int mat1[ren][col];
    int suma[ren][col];
    int resta[ren][col];
    int mult[ren][col];
    int c,r,k;

    printf("Primera Matriz:\n");
    for (r=0; r<ren; r++){
        for (c=0; c<col; c++){
            mat[r][c] = rand()%9;
        }
    }
    for (r=0; r<ren; r++){
        for (c=0; c<col; c++){
            printf (" [%d] ",mat[r][c]);
        }
        printf ("\n");
    }
    printf ("\nSegunda Matriz:\n");
    for (r=0; r<ren; r++){
        for (c=0; c<col; c++){
            mat1[r][c] = rand()%9;
        }
    }
    for (r=0; r<ren; r++){
        for (c=0; c<col; c++){
            printf (" [%d] ",mat1[r][c]);
        }
        printf ("\n");
    }
    printf ("\nSuma de Matrices:\n");
    for (r=0; r<ren; r++){
        for (c=0; c<col; c++){
            suma[r][c] = mat[r][c] + mat1[r][c];
        }
    }
    for (r=0; r<ren; r++){
        for (c=0; c<col; c++){
            printf (" [%d] ",suma[r][c]);
        }
        printf ("\n");
    }
    printf ("\nResta de Matrices:\n");
    for (r=0; r<ren; r++){
        for (c=0; c<col; c++){
            resta[r][c] = mat[r][c]-mat1[r][c];
        }
    }
    for (r=0; r<ren; r++){
        for (c=0; c<col; c++){
            printf (" [%d] ",resta[r][c]);
        }
        printf ("\n");
    }
    printf ("\nProducto de Matrices:\n");
    for (r=0; r<ren; r++){
        for (c=0; c<col; c++){
            mult[r][c] = 0;
            for (k=0; k<col; k++){
                mult[r][c] = (mult[r][c] + (mat[k][c] * mat1[r][k]));
            }
        }
    }
    for (r=0; r<ren; r++){
        for (c=0; c<col; c++){
            printf (" [%d] ",mult[r][c]);
        }
        printf ("\n");
    }

    /*Ejercicio 3: Hacer un menú que permita, cargar un vector, mostrar el vector, cargar una matriz, 
    mostrar una matriz, en todos los casos el usuario debe indicar de que dimensiones quiere al vector o la matriz. 
    Con el cero se sale del menú. */
    printf("\nEjercicio 3:\n");
    srand(time(0));

    int tamanio,renglon,columna,opcion;
    int i,ren1,col1;

    printf ("Ingrese el tamanio del vector: ");
    scanf ("%d",&tamanio);//Le pido al usuario que ingrese el tamanio del vector

    printf ("\nIngrese las filas que quiere para su matriz: ");
    scanf ("%d",&renglon);

    printf ("\nIngrese las columnas que desea para su matriz: ");
    scanf ("%d",&columna);

    int v1[tamanio];
    int matriz1[columna][renglon];
    int verificacion = 0;
    int verificacion1 = 0;

    do{
        printf ("\n\n0) Salir\n");
        printf ("\n1) Cargar Vector\n");
        printf ("\n2) Mostrar Vector\n");
        printf ("\n3) Cargar Matriz\n");
        printf ("\n4) Mostrar Matriz\n");
        printf ("\nPor favor ingrese una opcion: ");
        scanf ("%d",&opcion);

        switch (opcion){

        case 1:
            verificacion = 1;
            for (i=0; i<tamanio; i++){
                printf ("\nIngrese un numero en la posicion %d: ",i+1);
                scanf ("%d",&v1[i]);//Cargo el vector
            }
            printf ("\n1) -------------- Se cargo el vector -------------\n");
            break;

        case 2:
            if (verificacion == 1){
                printf ("\n2) VECTOR: ");
                for (i=0; i<tamanio; i++){
                    printf ("[%d]  ",v1[i]);
                }
            }
            else{
                printf ("\nPrimero cargue el vector!!!\n");
            }; break;

        case 3:
            verificacion1 = 2;
            for (ren1=0; ren1<renglon; ren1++){
                for (col1=0; col1<columna; col1++){
                    matriz1[col1][ren1] = rand()%50;

                }
            }
            printf ("\n3) ------------ Se cargo la matriz -------------\n");
            break;

        case 4:
            if (verificacion1 == 2){
                printf ("\n4) MATRIZ: \n");
                for (ren1=0; ren1<renglon; ren1++){
                    for (col1=0; col1<columna; col1++){
                        printf (" [%d] ", matriz1[col1][ren1]);
                    }
                    printf ("\n");
                }
            }else{
                printf ("\nPrimero cargue la matriz!!!\n");
            }; break;

        case 0: break;

        default: printf ("\nERROR: Opcion no valida\n");
      }
    } while (opcion!=0);

    return 0;
}