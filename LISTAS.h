//
// Created by Usuario on 5/9/2023.
//

#ifndef EJERCICIO_1_RECUPERATORIO_LISTAS_H
#define EJERCICIO_1_RECUPERATORIO_LISTAS_H

typedef struct nodo{

    int dato;
    struct nodo * sig;

}Nodo;

typedef struct lista {

    Nodo * cabecera;

}Lista;

Nodo * newNodo(int dato);
Lista * newLista ();

void insertarOrdenado (Lista * lista, Nodo * nodo);
void imprimir (Lista * lista);
Lista * diferencia (Lista * lista1, Lista * lista2);


#endif //EJERCICIO_1_RECUPERATORIO_LISTAS_H
