#include <stdio.h>
#include <stdlib.h>
#include "ListaEnc.h"

struct NodoE{
  int item;
  //void item;
  //Persona item;
  Nodo prox;
};

struct ListaEncE{
  Nodo* inicio;
  int tam;
};

ListaEnc crearLista() {
    ListaEnc lista = malloc(sizeof(struct ListaEncE));

    if (lista == NULL){
        return NULL;
    } 

    lista->inicio = NULL;
    lista->tam = 0;
    return lista;
}

int liberarLista(ListaEnc lista) {
    if (lista == NULL){
        return ESTRUCTURA_NO_INICIALIZADA;
    }
    // remove todos os elementos da lista
    while(!estaVacia(lista)){
        removerInicio(lista, NULL);
    }

    free(lista);
    lista->inicio = 0;
    lista->tam = 0;

    return OK;
}

int estaVacia(ListaEnc lista) {
    if (lista == NULL){
        return TRUE;
    }

    if (lista->inicio == 0){
        return TRUE;
    }

    return FALSE;
}

Nodo crearNo(int item, Nodo prox) {
	Nodo no = malloc(sizeof(struct NodoE));

	if (no == NULL){
        return NULL;
    }

	no->item = item;
	no->prox = prox;

	return no;
}

int insertarInicio(ListaEnc lista, int item) {
    if (lista == NULL){
        return ESTRUCTURA_NO_INICIALIZADA;
    }

    Nodo nuevoNo = crearNo(item, lista->inicio);
    if (nuevoNo == NULL){
        return ESTRUCTURA_NO_INICIALIZADA;
    }

    lista->inicio = nuevoNo;
    lista->tam++;

    return OK;
}

int insertar(ListaEnc lista, int item, int pos) {
    if (lista == NULL){
        return ESTRUCTURA_NO_INICIALIZADA;
    }

    if (pos < 0 || pos > lista->tam){
        return INDICE_INVALIDO;
    }

    Nodo nuevoNo;
    if (pos == 0) {
        return insertarInicio(lista, item);
    }else {
        // prepara para inserir
        Nodo aux;
        aux = lista->inicio;
        for(int i = 0; i < pos - 1; i++) {
            aux = aux->prox;
        }
        // adiciona o nó
        nuevoNo = nuevoNo = crearNo(item, aux->prox);
        if (nuevoNo == NULL){
            return ESTRUCTURA_NO_INICIALIZADA;
        }
        aux->prox = nuevoNo;
    }
    lista->tam++;

    return OK;
}

int insertarFin(ListaEnc lista, int item) {
    return insertar(lista, item, lista->tam);
}

int removerInicio(ListaEnc lista, int* item) {
    if (lista == NULL){
        return ESTRUCTURA_NO_INICIALIZADA;
    }

    if (estaVacia(lista)){
        return ESTRUCTURA_VACIA;
    }

    Nodo aux = lista->inicio;
    if (item != NULL){
        *item = aux->item;
    }

    lista->inicio = aux->prox;
    free(aux);
    aux = NULL;
    lista->tam--;

    return OK;
}

int remover(ListaEnc lista, int* item, int pos) {
    if (lista == NULL){
        return ESTRUCTURA_NO_INICIALIZADA;
    }

    if (estaVacia(lista)){
        return ESTRUCTURA_VACIA;
    }

    if (pos < 0 || pos >= lista->tam){
        return INDICE_INVALIDO;
    }

    Nodo ant, atual;
    if (pos == 0) {
        return removerInicio(lista, item);
    }else {
        // prepara para remover
        ant = NULL;
        atual = lista->inicio;
        for(int i = 0; i < pos; i++) {
            ant = atual;
            atual = atual->prox;
        }
        // remove o nó atual
        ant->prox = atual->prox;
        if (item != NULL)
            *item = atual->item;
        free(atual);
        atual = NULL;
    }
    lista->tam--;

    return OK;
}

int removerFin(ListaEnc lista, int* item) {
    return remover(lista, item, lista->tam - 1);
}

int obtenerElemento(ListaEnc lista, int* item, int pos) {
    if (lista == NULL){
        return ESTRUCTURA_NO_INICIALIZADA;
    }

    if (estaVacia(lista)){
        return ESTRUCTURA_VACIA;
    }

    if (pos < 0 || pos >= lista->tam){
        return INDICE_INVALIDO;
    }

    if (item == NULL){
        return PARAMETRO_INVALIDO;
    }

    Nodo aux;
    aux = lista->inicio;

    for(int i = 0; i < pos; i++) {
        aux = aux->prox;
    }
    *item = aux->item;

    return OK;
}

int obtenerTamanio(ListaEnc lista, int* tam) {
    if (lista == NULL){
        return ESTRUCTURA_NO_INICIALIZADA;
    }

    if (tam == NULL){
        return PARAMETRO_INVALIDO;
    }
    *tam = lista->tam;

    return OK;
}

void imprimir(ListaEnc lista) {
    int cantDeElementos;
    obtenerTamanio(lista, &cantDeElementos);

    printf("[");
    for(int i = 0;i < cantDeElementos; i++) {
        int el;
        obtenerElemento(lista, &el, i);
        printf(" %d ", el);
    }
    printf("]\n");
}