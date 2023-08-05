#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    /*Ejercicio 1: Escribir una oración, contar la cantidad de letras vocales y la cantidad de consonantes.  
    cuidado, las oraciones pueden tener símbolos y números.*/
    printf("Ejercicio 1: ");
    char oracion[50] = "";
    int i,j,k;
    int contVocales=0;
    int contConsonantes=0;
    char alfabetoConsonantes[42]="bBcCdDfFgGhHjJkKlLmMnNpPqQrRsStTvVwWxXyYzZ";
    char alfabetoVocales[10]="aAeEiIoOuU";

    printf ("\nEscriba una oracion: ");
    fflush(stdin);
    gets(oracion);

    for (i=0; i<50; i++){ 
      for (j=0; j<10; j++){
         if (oracion[i] == alfabetoVocales[j]){
            contVocales++;
         }
       }
    }

    for (i=0; i<50;i++){
        for (k=0; k<42; k++){
            if (oracion[i] == alfabetoConsonantes[k]){
                contConsonantes++;
            }
        }
    }

    printf ("\nLa cantidad de vocales que hay es ---> %d",contVocales);
    printf ("\nLa cantidad de consonantes que hay es ---> %d\n",contConsonantes);
    printf ("\n");

    //Ejercicio 2: Escribir una oración y mostrarla de atrás hacia adelante. 
    printf("Ejercicio 2: ");
    char oracion1[30]= "";

    printf ("\nEscriba una oracion: ");
    fflush(stdin);
    gets(oracion1);

    printf ("\nEsta oracion de atras hacia adelante seria: ");

    for (i=30-1; i>=0; i--){
       printf ("%c", oracion1[i]);
     }

    printf ("\n");
  
    /*Ejercicio 3: Dada una oración decidir si es o no palíndromo, es decir la lectura de izquierda a derecha es 
    igual que de derecha a izquierda. */
    printf("\nEjercicio 3: ");
    int cont=0;
    int tamanio=0;

    printf ("\nIngrese la cantidad de letras y espacios que va a utilizar\n");
    scanf ("%d",&tamanio);

    char oracion2[tamanio];
    for (i=0; i<tamanio; i++){
     printf ("\nIngrese una oracion de %d palabras,letra por letra\n",tamanio);
     scanf ("%s",&oracion2[i]);
    }
    printf ("\n[-----%s-------]\n",oracion2);
    for (i=0; i<tamanio; i++){
        if (oracion2[i] == oracion2[tamanio-1-i]){
            cont++;
        }
    }
    if (cont == tamanio){
        printf ("\nEs palindromo\n");
    } else {
        printf ("\nNo es palindromo\n");
    }

    printf ("\n");

    /*Ejercicio 4: Escribir el nombre de dos personas y decidir si son o no el mismo nombre. 
    En caso de ser nombres distintos generar un tercer nombre componiendo ambos. */
    printf("\nEjercicio 4: ");
    char nombre1[30]= " ", nombre2[30]= " "; //" " --> siempre poner esto
    char nombre3[60]= " ";

    printf ("\nIngrese un nombre: ");
    fflush(stdin);
    scanf ("%s",nombre1);

    printf ("\nIngrese un segundo nombre: ");
    fflush(stdin);
    scanf ("%s",nombre2);

    for (i=0; i<30; i++)//Hago un bucle que va de 0 a 29
    {//Dentro del bucle coloco un if y un else. Adentro del else pongo 3 for

        if (nombre1[i]==nombre2[i])//Comparo los 2 nombres para saber si son iguales o no
        {
            printf ("\nSon el mismo nombre\n");
        }
        else
        {
            printf ("\nNo son el mismo nombre\n");//Si no son el mismo nombre muestro esto
            for (i=0; i<30; i++)//hago un for de 0 a 29 para nombre1
            {
                nombre3[i]=nombre1[i];//le asigno nueva variable a nombre1
            }//termina en 29

            for (i=30; i<60; i++)//hago un for de 30 a 60  para nombre2
            {
                nombre3[i]=nombre2[i-30];//le asigno la misma variable a nombre2
            }

            printf ("\nNombre compuesto: ");
            for (i=0; i<60; i++)//hago otro for para concatenar los dos nombres distintos
            {
                printf ("%c",nombre3[i]);//muestro por pantalla el nombre compuesto
            }
        }
        i=30;
    }

    //Ejercicio 5: Dadas dos palabras ordenarlas alfabéticamente. 
    printf("\n\nEjercicio 5: ");
    char alfabeto[52] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVxXwWyYzZ";
    char palabra1[20]= " ";
    char palabra2[20]= " ";
    int pos1[20];
    int pos2[20];

    printf ("\nIngrese una palabra: ");
    scanf ("%s",&palabra1);

    printf ("\nIngrese una segunda palabra: ");
    scanf ("%s",&palabra2);

    for (i=0; i<20; i++){
        for (j=0; j<52; j++){
            if (palabra1[i]==alfabeto[j]){
                pos1[i]=j;
            }
        }
    }

    for (i=0; i<20; i++){
        for (j=0; j<52; j++){
            if (palabra2[i]==alfabeto[j]){
                pos2[i]=j;
            }
        }
    }
    printf ("\nEL ORDEN ALFABETICAMENTE QUEDA DE ESTA MANERA: ");

    for (i=0; i<20; i++){
        if (pos1[i] != pos2[i]){
            if (pos1[i]<pos2[i]){
                printf ("\n1) %s ",palabra1);
                printf ("\n2) %s ",palabra2);
            }
            else{
                printf ("\n1) %s ",palabra2);
                printf ("\n2) %s ",palabra1);
            }
            i=20;
        }
    }
    
    /*Ejercicio 6: Escribir un programa que pida tres cadenas al usuario y muestre su longitud (número de letras).
    Ejemplo: el usuario introduce como cadenas perro, pez y cocodrilo. El programa mostrará por pantalla. 
    El número de letras para perro es 5. El número de letras para pez es 3. 
    El número de letras para cocodrilo es 9.*/
    printf("\n\nEjercicio 6: ");
    char cadena1[20]=" ";
    char cadena2[20]=" ";
    char cadena3[20]=" ";

    printf ("\nIngrese una cadena: ");
    fflush(stdin);
    gets(cadena1);

    printf ("\nIngrese una segunda cadena: ");
    fflush(stdin);
    gets(cadena2);

    printf ("\nIngrese una tercera cadena: ");
    fflush(stdin);
    gets(cadena3);

    printf ("\nEl numero de letra para %s es ---> %d",cadena1,strlen(cadena1));
    printf ("\nEl numero de letra para %s es ---> %d",cadena2,strlen(cadena2));
    printf ("\nEl numero de letra para %s es ---> %d",cadena3,strlen(cadena3));


    /*Ejercicio 7: Escribir un programa que pida tres cadenas al usuario y muestre el resultado de concatenar 
    las dos primeras letras de las cadenas introducidas y que indique si las dos primeras cadenas son iguales.
    Ejemplo: el usuario introduce como cadenas perro, vaca y cocodrilo. El programa mostrará por pantalla: 
    “El resultado de concatenar las dos primeras letras de las cadenas es: pevaco. La primera cadena, perro, 
    no es igual a la segunda cadena, vaca.”
    Si el usuario introdujera perro, perro, mulo, el programa debería mostrar: 
    “El resultado de concatenar las dos primeras letras de las cadenas es pepemu. La primera cadena, perro, 
    es igual a la segunda cadena, perro.”*/
    printf("\n\nEjercicio 7: ");
    char nombre4[20],nombre5[20],nombre6[20];

    printf ("\nIngrese una palabra: ");
    scanf ("%s",nombre4);

    printf ("\nIngrese una segunda palabra: ");
    scanf ("%s",nombre5);

    printf ("\nIngrese una tercera palabra: ");
    scanf ("%s",nombre6);

    char letra1 = nombre4[0],letra2 = nombre4[1];
    char letra3 = nombre5[0],letra4 = nombre5[1];
    char letra5 = nombre6[0],letra6 = nombre6[1];

    printf ("\nEl resultado de concatenar las dos primeras letras de las cadenas es: %c%c%c%c%c%c",
             letra1,letra2,letra3,letra4,letra5,letra6);

    for (i=0; i<40; i++){
        if (nombre4[i] != nombre5[i]){
            printf ("\nLa primera cadena %s no es igual a la segunda cadena %s",nombre4,nombre5);
        }else{
        if (nombre4[i] == nombre5[i]){
            printf ("\nLa primera cadena %s es igual a la segunda cadena %s",nombre4,nombre5);
        }
        }
        i=40;
    }

    printf ("\n");

    return 0;
}