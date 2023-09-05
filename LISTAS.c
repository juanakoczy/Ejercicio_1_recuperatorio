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

Lista * diferencia (Lista * lista1, Lista * lista2){

    Nodo * aux1 = lista1->cabecera;
    Nodo * aux2 = lista2->cabecera;
    Nodo * nodoDiferente = NULL;


    Lista * listanueva = malloc(sizeof (Lista));
    listanueva->cabecera = NULL;

    while (aux1!= NULL && aux2 != NULL){
        if (aux1->dato < aux2->dato){

            nodoDiferente->dato = aux1->dato;
            nodoDiferente->sig = NULL;

            insertarOrdenado(listanueva,nodoDiferente);

            aux1 = aux1->sig;
        }
        else if (aux1->dato > aux2->dato)
               aux2 = aux2->sig;
        else {
            aux1 = aux1->sig;
            aux2 = aux2->sig;
        }
    }
    return (Lista *) listanueva;
}