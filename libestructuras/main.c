#include "cola.h"
#include "pila.h"
#include <stdio.h>

int main(){
    Cola* cola = cola_crear();
    Pila* pila = pila_crear();

    // Agregamos
    pila_push(pila, 5);
    pila_push(pila, 10);
    pila_push(pila, 20);
    
    cola_push(cola, 10);
    cola_push(cola, 82);
    cola_push(cola, 0);
    
    pila_mostrar(pila);
    cola_mostrar(cola);

    printf("Estado pila: %d.\n",pila_pop(pila));
    printf("Estado cola: %d.\n", cola_pop(cola));

    pila_mostrar(pila);
    cola_mostrar(cola);

    // Liberamos
    pila_destruir(pila);
    cola_destruir(cola);

    return 0;
}
