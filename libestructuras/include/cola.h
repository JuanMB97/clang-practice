#ifndef COLA_H
#define COLA_H
#include "estado.h"

typedef struct Cola Cola;

Cola* cola_crear();
void cola_push(Cola* c, int dato);
Estado cola_pop(Cola* c);
void cola_destruir(Cola* c);
void cola_mostrar(Cola* c);

#endif

