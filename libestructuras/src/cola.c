#include <stdlib.h>
#include <stdio.h>
#include "../include/cola.h"
#include "../include/nodo.h"
#include "../include/estado.h"

struct Cola {
    Nodo *primero;
    Nodo *ultimo;
};

Cola* cola_crear(){
    Cola* cola = malloc(sizeof(Cola));
    cola->primero = NULL;
    cola->ultimo = NULL;
    return cola;
}

void cola_push(Cola* cola, int dato){
    Nodo* n_nodo = malloc(sizeof(Nodo));
    n_nodo->dato = dato;
    n_nodo->siguiente = NULL;

    if(cola->primero == NULL){
        cola->primero = n_nodo;
        cola->ultimo = n_nodo;
    } else{
        cola->ultimo->siguiente = n_nodo;
        cola->ultimo = n_nodo; 
    } 
}

Estado cola_pop(Cola* cola){
    Estado result = ERROR;
    Nodo* t_nodo = NULL;

    if(cola->primero != NULL){
        t_nodo = cola->primero;

        cola->primero = cola->primero->siguiente;
        free(t_nodo);
    }
    if(t_nodo != NULL){
        result = OK;
    }else{
        result = VACIA;
    }
    return result; 
}

void cola_destruir(Cola* cola){
    Nodo* t_nodo;
    while(cola->primero != NULL){
        t_nodo = cola->primero;
        cola->primero = cola->primero->siguiente;

        free(t_nodo);
    }
    cola->ultimo = NULL;
    free(cola);
}

void cola_mostrar(Cola* cola){
    Nodo* t_nodo = cola->primero;
    printf("[ ");
    while(t_nodo != NULL){
        printf("%d ", t_nodo->dato);
        t_nodo = t_nodo->siguiente;
    }
    printf(" ]\n");
}
