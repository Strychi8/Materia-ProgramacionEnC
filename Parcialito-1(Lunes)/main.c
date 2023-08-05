#include <stdio.h>
#include <stdlib.h>

int main(){

    //TEMA 2: Crear un programa que muestre en orden descendente los numeros que esten entre
    //10000 y -600, que sean divisibles por 2 y 7, pero que no sean divisibles por 5 ni por 3
    //Luego se pide mostrar por pantalla, ademas, la suma de estos numeros.
    printf("\nTema 2\n");
    int i;
    int suma;
    printf ("Numeros entre 1000 y -600, divisibles por 2 y 7, y no divisibles por 5 y 3:\n\n");
    for (i=10000; i>=-600; i--){
        if (i%7==0 && i%2==0 && i%5!=0 && i%3!=0){
            printf ("%d ",i);
            suma = suma + i;
        }
    }
    printf ("\n\nLa suma total es ----> %d ",suma);

    //TEMA 3: Se pide crear el algoritmo que permite la distribucion de los temas.
    //Se requiere que se ingrese por teclado los datos de 5 alumnos,nombre,dni
    //email, se muestre por pantalla los datos de estos alumnos y un mensaje que
    //diga que tema le toco.
    printf("\n\nTema 3\n");
    int j;
    int dni;
    int tam = 50;
    int numFinal;
    char alumno[tam];
    char email[tam];

    for (j=0; j<5; j++){
        printf("Alumno %d", j+1);
        printf ("\nIngrese su nombre y apellido:\n");
        fflush(stdin);
        gets(alumno);
        printf ("\nIngrese su DNI:\n");
        scanf ("%d",&dni);
        printf ("\nIngrese el ultimo digito de su DNI:\n");
        scanf ("%d",&numFinal);
        printf ("\nIngrese su email:\n");
        fflush(stdin);
        gets(email);
        printf ("\nNombre: %s\n",alumno);
        printf ("Dni: %d\n",dni);
        printf ("E-mail: %s\n",email);

        if (numFinal==0 || numFinal==1){
            printf ("Tema: 1\n\n");
        }
        if (numFinal==2 || numFinal==3){
            printf ("Tema: 2\n\n");
        }

        if (numFinal==4 || numFinal==5){
            printf ("Tema: 3\n\n");
        }

        if (numFinal==6 || numFinal==7){
            printf ("Tema: 4\n\n");
        }

        if (numFinal==8 || numFinal==9){
            printf ("Tema: 5\n\n");
        }
    }

    //TEMA 5: Crear un programa que cuente del -100 al 2000 en donde
    //se realice la suma total y el producto total de los numeros que
    //sean impares y divisibles por 17
    printf("\n\nTema 5\n");
    int k;
    int producto=1;
    int suma1=0;
    printf ("Numeros Impares y divisibles por 17:\n\n");
    for (k=-100; k<=2000; k++){
        if (k%2!=0 && k%17==0){
            printf ("%d ",k);
            suma1 = suma1 + k;
            producto = producto * k;
        }
    }
    printf ("\n\nLa suma total es ----> %d ",suma1);
    printf ("\nEl producto total es ----> %d ",producto);

    return 0;
}