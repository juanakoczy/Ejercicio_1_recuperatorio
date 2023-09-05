//
// Created by Usuario on 5/9/2023.
//

#include "LISTAS.h"
#include <stdio.h>
#include "malloc.h"

Nodo * newNodo(int dato) {

    Nodo *aux = NULL;
    aux = malloc(sizeof(Nodo));

    if (aux == NULL) {
    printf("No hay espacio de memoria suficiene.");
    exit(-1);
    }

    else{
        aux->dato = dato;
        aux->sig = NULL;
    }

    return aux;
}
Lista * newLista (){

    Lista * aux = NULL;
    aux = malloc (sizeof(newLista));

    if (aux == NULL){
        printf ("No hay espacio de memoria suficiente.");
        exit(-1);
    }
    else{
        aux->cabecera = NULL;
    }
    return aux;
}

void insertarOrdenado (Lista * lista, Nodo * nodo){

    Nodo * actual =  lista->cabecera;
    Nodo * anterior = NULL;

    while (actual != NULL && actual->dato < nodo->dato){

        anterior = actual;
        actual = actual->sig;
    }

    if (anterior == NULL){

        nodo->sig = lista->cabecera;
        lista->cabecera = nodo;

    }

    else {

        anterior->sig = nodo;
        nodo->sig = actual;
    }
}

void imprimir (Lista * lista){

    Nodo * aux = lista->cabecera;

    while (aux != NULL){
        printf ("\t %d \t", aux->dato);
        aux = aux->sig;
    }
}

Lista* diferencia(Lista* lista1, Lista* lista2) {
    Nodo* aux1 = lista1->cabecera;
    Nodo* aux2 = lista2->cabecera;

    Lista* listanueva = newLista();

    while (aux1 != NULL) {
        int encontrado = 0;//Bandera para indicar que los nodos son iguales
        aux2 = lista2->cabecera;

        while (aux2 != NULL) {
            if (aux1->dato == aux2->dato) {
                encontrado = 1;//encuentra nodos iguales y sale
                break;
            }
            aux2 = aux2->sig;//avanza la lista 2
        }

        if (!encontrado) {//no lo encuentra en la lista 2, lo agrega a una lista nueva
            Nodo* nodoDiferente = newNodo(aux1->dato);
            insertarOrdenado(listanueva, nodoDiferente);
        }

        aux1 = aux1->sig;//avanza la lista 1
    }

    // Agregar elementos de la lista 2 que no están en la lista 1, idem al anterior
    aux2 = lista2->cabecera;
    while (aux2 != NULL) {
        int encontrado = 0;
        aux1 = lista1->cabecera;

        while (aux1 != NULL) {
            if (aux2->dato == aux1->dato) {
                encontrado = 1;
                break;
            }
            aux1 = aux1->sig;
        }

        if (!encontrado) {
            Nodo* nodoDiferente = newNodo(aux2->dato);
            insertarOrdenado(listanueva, nodoDiferente);
        }

        aux2 = aux2->sig;
    }

    return listanueva;
}
