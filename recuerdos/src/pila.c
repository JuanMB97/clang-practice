#include <stdlib.h>
#include <stdio.h>
#include "../include/pila.h"

struct Registro {
  int dato;
};

struct Nodo {
  struct Registro registro;
  struct Nodo* next;
};

struct Pila {
  struct Nodo* tope;
};


Pila* create_stack(){
  struct Pila* pila = malloc(sizeof(struct Pila));

  pila -> tope = NULL;
  return pila;
};

Registro* create_register(int dato){
  Registro* n_registro = malloc(sizeof(Registro));
  n_registro -> dato = dato;
  return n_registro; 
}

int getter_register(Registro* registro){
  return registro -> dato;
}

void push_stack(Registro registro, Pila* pila){
  
  struct Nodo* n_nodo = malloc(sizeof(struct Nodo));

  n_nodo -> registro =  registro;
  n_nodo -> next = pila -> tope;
  pila -> tope = n_nodo;
}

void clear_stack(Pila* pila){
  struct Nodo* r_node;  

  while(pila -> tope != NULL){
    r_node = pila -> tope;

    pila->tope = pila-> tope ->next;
    free(r_node);
  }

  free(r_node);
}
