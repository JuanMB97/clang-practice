#ifndef PILA_H
#define PILA_H

typedef struct Registro Registro;
typedef struct Nodo Nodo;
typedef struct Pila Pila;

Registro* create_register(int dato);
int getter_register(Registro* registro);
Pila* create_stack();
void push_stack(Registro registro, Pila* pila);
void clear_stack(Pila* pila);


#endif
