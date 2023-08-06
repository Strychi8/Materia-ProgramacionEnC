#include <stdio.h>
#include <stdlib.h>
#include "ListaEnC.c"

int main()
{
    printf("\nListas-Pilas-Colas\n");

    //Las pilas se usan mucho en Sistemas Operativos, trata de resolver
    //los problemas lo mas rapido posible. Se saca el ultimo elemento
    //El primer dato que entra es el ultimo que se resuelve
    //Al igual que las Colas se Agrega al Final pero al Eliminar u Obtener
    //un elemento se saca el ultimo
    //Las colas (el primer dato que entra es el primero que se resuelve)
    //Son un caso particular de las listas. El eliminar se llama Desencolar
    //y el agregar se denomina Encolar.
    //Se saca el primer elemento (Eliminar y Obtener) y nada mas se Agrega al final
    //Un ejemplo en Programacion es el Siu Guarani
    //Las listas (conjunto de nodos) donde en cada nodo se almacena un valor
    //y se almacena un puntero al siguiente nodo
    //son mas lentas, con lo que seran menos eficaces
    //Tendre un struct Lista que lo unico que me interesara es el primer nodo
    //int, char , long float...
    //array ---------> MUCHOS datos de un MISMO TIPO
    //int vector[4] _  _  _  _

    //Estructuras // MUCHOS datos de distinto tipo {}

    //Listas ----> MUCHOS(sean cualquier numero) datos de un MISMO TIPO
    //->Inicial: array[0]
    //->Agrego dos elementos: array[2]
    //->Elimino 1: array[1]

    ListaEnc listaNumeros = crearLista();//el tam es 0 y apunto a ningun nodo
    int resultado = 0; //Voy a guardar los resultados de la funciones

    //Agregar Elementos
    insertarInicio(listaNumeros, 5);
    insertarFin(listaNumeros, 4);
    insertarFin(listaNumeros,-1);
    insertarInicio(listaNumeros, 4);
    insertarInicio(listaNumeros, 3);
    insertarFin (listaNumeros, 2);
    insertarFin (listaNumeros,23);
    insertar (listaNumeros,34,3);

    removerInicio(listaNumeros,&resultado);
    removerFin(listaNumeros, &resultado);
    remover(listaNumeros, &resultado, 3);
    //4 5 34 -1 2
    imprimir(listaNumeros);

    //obtenerTamanio(listaNumeros,&resultado);
    //printf("Dato que borre: %d", resultado );

    //Diferencias que hay entre una lista,pila y cola
    //La lista es un conjunto de nodos donde en cada nodo se almacena un valor
    //y se almacena un puntero al siguiente nodo.
    //Tambien tiene una Struct Lista en donde se guarda el primer nodo y el tamaño
    //En cambio la pila (stack) trata de resolver los problemas lo mas rapido posible
    //El primer dato que entra es el ultimo que se resuelve.
    //Y a diferencia de las colas, estas tratan de resolver el primer dato
    //que entra. Eliminar y Obtener Elemento seran al inicio y su Agregar
    //al final
    //Sus agregar se llaman encolar y sus eliminar se denominan desencolar.
    //Los procedimientos/funciones de la lista seran Insertar,InsertarInicio,InsertarFin
    //Tambien tiene eliminar,eliminarInicio,eliminarFin, imprimir, obtener
    //elemento y liberarLista
    //Los procedimientos/funciones de la pila son InsertarFin,EliminarFin,ObtenerDatoFin
    //Los procedimientos/funciones de la cola son DesencolarInicio,EncolarFin,ObtenerDatoInicio
    //Una de las virtudes que tienen frente aun array es el tamaño ya que
    //el problema que surge del array es no conocer el tamaño, en cambio,
    //en las listas se puede modificar su tamaño al instante. Es mas versatil
    //que los array y tienen esa virtud que no desperdician nada en cuanto a la
    //estrucutura de datos

    return 0;
}
