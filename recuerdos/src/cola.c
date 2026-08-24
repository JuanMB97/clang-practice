#include <stdio.h>
#include <stdlib.h>

struct NodoCola {
  int dato;
  struct NodoCola* next;
};

struct ColaStack {
  struct NodoCola* first;
  struct NodoCola* last;
};

struct ColaStack* create_cola(){
  struct ColaStack* n_cola = malloc(sizeof(struct ColaStack));
  
  n_cola->first = NULL;
  n_cola->last = NULL;
  
  return n_cola;
}

struct ColaStack* push_cola(int dato, struct ColaStack* cola){
  struct NodoCola* n_temp = malloc(sizeof(struct NodoCola));

  n_temp->dato = dato;
  n_temp->next = NULL;
  
  if(cola->first == NULL){

    cola->first = n_temp;
    cola->last = n_temp;
  }else{
    
    cola->last->next = n_temp;
    cola->last = n_temp;
  }

  return cola;
}


void show_cola(struct ColaStack cola){
  printf("[ ");
  while(cola.first != NULL){
    printf("%d ", cola.first->dato);

    cola.first = cola.first->next;
  }
  printf("]\n");
}

void delete_cola(struct ColaStack* cola){
  struct NodoCola* n_temp;

  while(cola->first != NULL){
    n_temp = cola->first;

    cola->first = cola->first->next;
    free(n_temp);
  }

  cola->first = NULL;
  cola->last = NULL;
}

int main(){

  struct ColaStack* cola = create_cola();

  push_cola(45, cola);

  push_cola(92, cola);

  push_cola(21, cola);

  show_cola(*cola);

  delete_cola(cola);

  free(cola);

  return 0;

}
