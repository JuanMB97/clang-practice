#ifndef PILA_H
#define PILA_H
#include "../include/estado.h"

typedef struct Pila Pila;

// creación
Pila* pila_crear();

// operaciones
void pila_push(Pila* p, int dato);
Estado pila_pop(Pila* p);

// liberar memoria
void pila_destruir(Pila* p);
void pila_mostrar(Pila* p);

#endif
