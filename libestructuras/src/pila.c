#include <stdio.h>
#include <stdlib.h>
#include "../include/pila.h"
#include "../include/nodo.h"
#include "../include/estado.h"

struct Pila {
    Nodo* tope;
};

Pila* pila_crear(){
    Pila* p = malloc(sizeof(Pila));
    p->tope = NULL;
    return p;
}

void pila_push(Pila* p, int dato){
    Nodo* temp_nodo = malloc(sizeof(Nodo));

    temp_nodo->dato = dato;
    temp_nodo->siguiente = p->tope;
    p->tope = temp_nodo;
}

Estado pila_pop(Pila* p){
    Estado result = ERROR;
    Nodo* temp_nodo = NULL;
    if(p->tope != NULL) {
        temp_nodo = p->tope;
        p->tope = p->tope->siguiente;
        free(temp_nodo);
    }

    if(temp_nodo !=NULL){
        result = OK;
    }else{
        result = VACIA;
    }

    return result;
}

void pila_destruir(Pila* p){
    Nodo* temp_nodo;

    while(p->tope != NULL){
        temp_nodo = p->tope;
        p->tope = p->tope->siguiente;
        free(temp_nodo);
    }
    free(p);
}

void pila_mostrar(Pila* pila){
    Nodo* t_nodo = pila->tope;
    printf("[ ");
    while(t_nodo != NULL){
        printf("%d ", t_nodo->dato);
        t_nodo = t_nodo->siguiente;
    }
    printf(" ]\n");
}
