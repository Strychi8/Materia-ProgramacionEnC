#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Un enumerador es un tipo de datos definido por el usuario que consiste en un 
conjunto de valores con nombre llamados enumeradores.*/
enum color {verde,amarillo,azul};
enum booleano {verdadero,falso};
enum opciones {salir,cargar,eliminar,modificar,mostrar};

struct Alumno {
   char nombre[20];
   int edad;
};

/*Punteros
Un puntero es una variable que almacena la direccion de memoria de un elemento determinado del programa
En todos los lenguajes de programacion hay punteros, que yo no los vea no significa que no haya punteros
Un puntero apunta en princio a nuestro dato, mi puntero guardara la direccion de memoria de algo*/
int cargarNumero (int n);
void cargarNumero2 (int * n);
void suma_dos(int * x14, int * y, int * z);
void datos (int * x15,float * y15,char *c);
void mostrarInfo(void);

int main()
{
    /*for (int i=salir; i<=mostrar; i++){
        printf ("\n----> %d",i);
    }*/
    int * puntero1;//Define un puntero que apunta a un entero
    char * puntero2;
    int numero = 140;
    char letra = 'd';
    puntero1= &numero;//Referencia a la memoria donde esta numero
    puntero2= &letra;
    printf ("----> %d",numero);
    printf ("\n----> %d",&puntero1);//Direccion de Memoria de un puntero
    printf ("\n----> %d",puntero1);//Direccion de Memoria donde esta numero
    printf ("\n----> %d",*puntero1);//tomo el dato que tengo guardado en numero
    //printf ("\n----> %c",letra);

    * puntero1 = 100;//Altero el valor de forma implicita de la variable numero,
                     //no cambia la dir. de memoria pero si podemos cambiar lo que
                     //tiene almacenado
    printf ("\n\n----> %d",numero);
    printf ("\n----> %d",puntero1);//Direccion de Memoria donde esta numero
    printf ("\n----> %d\n",*puntero1);//tomo el dato que tengo guardado en numero

    printf ("\n1) PUNTERO GENERICO (VOID) CON CASTEOS \n");
    int variable;
    int * punter1;
    void * punter2;

    variable = 5;
    punter1 = &variable;
    punter2 = punter1;

    printf("Valor: %d",*(int*)punter2);//lo casteo a tipo de dato entero y me muestra el contenido de esa direccion de memoria
    printf("\nValor: %d",*punter1);

    printf ("\n\n2) VECTORES\n");
    int * punteroV;
    int vector[5] = {1,23,4,54,3};
    punteroV = &vector[4];
    printf ("---> %d",punteroV);
    printf ("\n---> %d",*punteroV);
    printf ("\n---> %d\n",vector[4]);

    punteroV = vector; //C trabaja los array como punteros
    printf ("---> %d",punteroV);
    printf ("\n---> %d",*punteroV);

    printf ("\n---> %d",*(punteroV+1));
    printf ("\n---> %d\n",*(punteroV+2));

    printf ("\n3) ESTRUCTURAS\n");
    //la distancia de la direccion de memoria en estructuras ya no
    //es de 4 bits sino 24 bytes, ocupan mas espacio que un array
    //de 5 elementos enteros
    struct Alumno alumno1;
    alumno1.edad = 17;
    strcpy (alumno1.nombre,"Carlos");
    struct Alumno * punteroE;
    punteroE= &alumno1;
    printf ("---> %d", punteroE);
    printf ("\n---> %s", punteroE->nombre);
    printf ("\n---> %d\n", punteroE->edad);
    printf ("\n---> %d\n", (*punteroE).nombre);

    printf ("\n4) FUNCIONES Y PROCEDIMIENTOS\n");
    int num = -10;
    printf ("----> %d\n",num);
    num = cargarNumero (num);//Cargo el nuevo numero y pierdo el -10
    printf ("----> %d\n",num);
    cargarNumero2 (&num); //n es igual a &num y por lo tanto *n es igual a num
    printf ("\n---> %d\n",num);
    printf("\n------ SUMA -------\n");

    int sum0 = 13;
    int sum1 = 65;
    int sum2= 71;
    suma_dos(&sum0,&sum1,&sum2);
    printf("\nEl cambio de estas 3 variables es: %d, %d, %d\n",sum0,sum1,sum2);

    int num0;
    float dec0;
    char let0;
    datos (&num0,&dec0,&let0);
    printf("\n--- Numero --- Decimal ---- Letra ---\n\n");
    printf("Numero: %d\nDecimal: %.2f\nLetra: %c\n",num0,dec0,let0); //me va a mostrar el procedimiento

    printf("\n----------- DATOS ------------\n");
    int num1 = 10;
    float dec1 = 8.2;
    char let1 = 'r';
    //datos2(&num1,&dec1,&let1);
    printf("\nDATOS: %d, %.2f, %c",num1,dec1,let1);

    printf ("\n\nEjercicio 1: \n"); //Ejercicio 1
    int * punt;
    int x=7;
    int y=5;
    punt = &x;//Apunta la direccion de memoria en donde esta guardado el 7
    *punt=4;//Le cambiamos el numero en 4
    printf ("%d, %d",x,y);
    
    printf ("\n\nEjercicio 2: \n"); //Ejercicio 2
    int * punt1;
    int x1=7;
    int y1=5;
    punt1=&x1;
    x1=4;
    printf ("%d, %d",*punt1,y1);
    
    printf ("\n\nEjercicio 3: \n"); //Ejercicio 3
    int * punt2;
    int x2=7;
    int y2=5;
    punt2=&x2;//direccion de memoria de la variable x2=7
    x2=23;
    punt2=&y2;//direccion de memoria de la variable y2=5
    printf ("%d, %d",*punt2,x2);
    
    printf ("\n\nEjercicio 4: \n"); //Ejercicio 4
    int * punt3;
    int x3=7;
    int y3=5;
    punt3=&x3;//direccion de memoria de la variable x3=7
    *punt3=3;//de 7 a 3
    punt3=&y3;//direccion de memoria de la variable y3=5
    *punt3=&x3;//direccion de memoria de la variable x3=3
    x3=9;
    printf ("%d, %d",*punt3,x3);
    
    printf ("\n\nEjercicio 5: \n"); //Ejercicio 5
    int * puntA,*puntB;
    int x4=7;
    int y4=5;
    puntA=&x4;//direccion de memoria de la variable x4=7
    *puntA=3;//de 7 a 3
    puntB=&y4;//direccion de memoria de la variable y4=5
    *puntB=x4;//contenido en el puntero B habra un 3
    x4=9;
    printf ("%d, %d",*puntB,x4);
    
    printf ("\n\nEjercicio 6: \n"); //Ejercicio 6
    int * punt4,*punt5;
    int x5=7;//
    int y5=5;//
    punt4=&x5;//9
    *punt4=3;//9
    punt5=&y5;//3
    *punt5=x5;//3
    x5=9;
    printf ("%d, %d",*punt5,*punt4);
    
    printf ("\n\nEjercicio 7: \n"); //Ejercicio 7
    int *punteroA,*punteroB;
    int a=7;//
    int b=5;//3
    punteroA=&a;//9
    *punteroA=3;//9
    punteroB=&b;//3
    *punteroB=a;//3
    a=9;
    punteroB=punteroA;
    printf ("%d, %d",*punteroB, b);
    
    printf ("\n\nEjercicio 8: \n"); //Ejercicio 8
    int * puntV,i;
    int v1[5]={1,2,3,4,5};
    puntV=v1;
    *puntV=9;
    for (i=0;i<5;i++){
    printf ("[%d] ",v1[i]);
    }
    
    printf ("\n\nEjercicio 9: \n"); //Ejercicio 9
    int * puntV1;
    int v2[5]={1,2,3,4,5};
    puntV1=&v2[0];
    *puntV1=9;
    puntV1[3]=7;
    for (i=0; i<5; i++){
    printf ("[%d] ",v2[i]);
    }
    
    printf ("\n\nEjercicio 10: \n"); //Ejercicio 10
    int * puntV2;
    int v3[5]={1,2,3,4,5};
    puntV2=v3;
    *v3=11;
    *(puntV2 + 3) = 9;
    for (i=0; i<5; i++){
    printf ("[%d]",v3[i]);
    }

    printf ("\n\nEjercicio 11: \n"); //Ejercicio 11
    int * puntV3;
    int v4[5]={1,2,3,4,5};// 1 11 9 7 5
    puntV3=v4;
    *(puntV3 + 2) = 9;
    *(v4 + 3) = 7;
    puntV3[1] = 11;
    for (i=0; i<5; i++){
    printf ("[%d] ",*(puntV3+i));
    }
    
    printf ("\n\nEjercicio 12: \n"); //Ejercicio 12
    int * puntV4;
    int v5[5]={1,2,3,4,5}; //1 2 9 7 11
    puntV4 = v5 + 4;
    *(puntV4-2) = 9;
    puntV4--;//contador=cont-1
    *(puntV4) = 7;
    puntV4[1]=11;
    for (i=0; i<5; i++){
    printf ("[%d] ",*(v5+i));
    }
    
    printf ("\n\nEjercicio 13: \n"); //Ejercicio 13
    int * puntV5;
    int v6[5]={1,2,3,4,5};//1 9 7 11 5
    puntV5 = &v6[0]+3;
    *(puntV5-2)=9;
    puntV5--;
    *(puntV5)=7;
    puntV5[1]=11;
    puntV5 = v6;
    for (i=0; i<5; i++){
    printf ("[%d]  ",puntV5[i]);
    }


    printf ("\n");
    return 0;
}
int cargarNumero (int n){
    return n = 1000;
}
void cargarNumero2 (int * n){
   *n =20000; //n es igual a &num y *n es igual a num
}
//Ejercicio 14
void suma_dos(int * x14, int * y, int * z ){
  *x14=*x14+2;
  *y=*y+2;
  *z=*z+2;
}
/*void main (void){
    int x14,y,z;
    x14 = 3;
    y = 10;
    z = 15;
    suma_dos (&x14, &y, &z);
    printf ("%d  %d  %d  %d\n",x14,y,z);
}
//Ejercicio 15
void main (void){
    int x15 = 9;
    float y15 = 44.6;
    char c = 'a';
    datos (&x15,&y15,&c);
    printf ("%d  %f  %c\n",x15,y15,c);

}*/
void datos (int * x15, float * y15, char *c){
   *x15 = 8;
   *y15 = 4.2;
   *c = 'g';
}
//Ejercicio 16
void datos2 (int *x16, float * y16, char *c16){
   printf ("%d  %f  %c",x16,y16,c16);//muestra basura
   *x16= 8;
   *y16 = 4.2;
   *c16 = 'g';
}
void mostrarInfo (void){
    int x16 = 9;
    float y16 = 44.6;
    char c16 = 'a';
    datos2 (&x16,&y16,&c16);
    printf ("%d  %d  %f  %c\n",x16,y16,c16);
}