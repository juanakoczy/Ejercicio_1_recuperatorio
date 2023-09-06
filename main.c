
#include "LISTAS.h"
#include "stdio.h"

int main() {
    Lista * lista1 = newLista();
    Lista * lista2 = newLista();


    insertarOrdenado(lista1, newNodo(1));
    insertarOrdenado(lista1, newNodo(3));
    insertarOrdenado(lista1, newNodo(2));
    insertarOrdenado(lista1, newNodo(6));
    insertarOrdenado(lista1, newNodo(4));

    imprimir(lista1);

    printf ("\n");

    insertarOrdenado(lista2, newNodo(5));
    insertarOrdenado(lista2, newNodo(3));
    insertarOrdenado(lista2, newNodo(7));
    insertarOrdenado(lista2, newNodo(4));
    insertarOrdenado(lista2, newNodo(6));
    insertarOrdenado(lista2, newNodo(8));

    imprimir(lista2);

    printf ("\n");


    Lista * listanueva =  diferencia(lista1, lista2);

    imprimir(listanueva);


    return 0;
}
