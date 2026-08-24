#include "pila.h"
#include <stdio.h>

int main(){
    
  Pila* mi_pila = create_stack();

  Registro* mi_registro = create_register(5);

  printf("El dato del registro es: %d \n", getter_register(mi_registro));

  return 0;
}
