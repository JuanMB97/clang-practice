#include <stdio.h>
#include <stdlib.h>

struct DoubleStack {
  struct Nodoble* tope;
};

struct Nodoble {
  int dato;
  struct Nodoble* previus;
  struct Nodoble* next;
};

struct DoubleStack* create_double_stack(){
  struct DoubleStack* n_double = malloc(sizeof(struct DoubleStack));

  n_double->tope = NULL;
  
  return n_double;
}

// Agrega un elemento a la pila al final.
struct DoubleStack* push_double(int dato, struct DoubleStack* doble){
  struct Nodoble* n_nodoble = malloc(sizeof(struct Nodoble));

  n_nodoble->dato = dato;

  if(doble->tope == NULL){
    n_nodoble->previus = NULL;
    n_nodoble->next = NULL;

    doble->tope = n_nodoble;
  }else{
    n_nodoble->next = doble->tope;
    n_nodoble->previus = NULL;
       
    doble->tope->previus = n_nodoble;
    doble->tope = n_nodoble;
  }
  return doble;
}

void show_double_stack(struct DoubleStack* doble){
  struct Nodoble* n_temp = doble->tope;
  if (doble->tope == NULL) return;

  printf("[ ");
  while(n_temp != NULL){
    printf("%d ", n_temp->dato);
    n_temp = n_temp->next;
  }
  printf("]\n");
}

void clear_double_stack(struct DoubleStack* doble){
  struct Nodoble* n_temp;

  while(doble->tope != NULL){
    n_temp = doble->tope;
    doble->tope = doble->tope->next;

    free(n_temp);
  }

  doble->tope = NULL;
}

// Extraer todos los nodo de la pila si coincide el valor pasado por parametro
struct DoubleStack* delete_data(int value, struct DoubleStack* doble){
  struct Nodoble* n_temp = doble->tope;
  struct Nodoble* n_clean = NULL;
  while(n_temp != NULL){
    if(n_temp->dato == value){
      
      if(n_temp->previus != NULL){
        if(n_temp->next != NULL){
          n_temp->previus->next = n_temp->next;
        }else{
          n_temp->previus->next = NULL;
        }
      }

      if(n_temp->next !=NULL){
        if(n_temp->previus != NULL){
          n_temp->next->previus = n_temp->previus;
        }else{
          n_temp->next->previus = NULL;
        }
      }

      if(doble->tope->dato == value){
        doble->tope = doble->tope->next;
        if(doble->tope != NULL){
          doble->tope->previus = NULL;
        }
      }

      n_clean = n_temp;
    }

    n_temp = n_temp->next;
    
    if(n_clean != NULL) free(n_clean);
    n_clean = NULL;
  }
  return doble;
}

int pop_double(struct DoubleStack* doble){
  struct Nodoble* n_temp;
  int dato;
  if(doble != NULL){
    dato = doble->tope->dato;
    n_temp = doble->tope;  
    doble->tope = doble->tope->next;
    free(n_temp);
  }

  return dato;
}


int main(){
  
  struct DoubleStack* mi_doble = create_double_stack();

  push_double(10, mi_doble);
  push_double(7, mi_doble);
  push_double(5, mi_doble);
  push_double(24, mi_doble);
  push_double(5, mi_doble);
  push_double(82, mi_doble);

  show_double_stack(mi_doble);

  delete_data(5, mi_doble);

  int dato = pop_double(mi_doble);

  printf("Extraccion: %d \n", dato);

  show_double_stack(mi_doble);

  clear_double_stack(mi_doble);

  
  free(mi_doble);

  return 0;
}



