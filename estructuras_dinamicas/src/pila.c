#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/pila.h"

struct Node {
    Register reg;
    Node* back;
    Node* next;
};

struct Stack {
  Node* top;
  int size;
};

// Funciones para gestionar la pila
Node* push_stack(Stack *pila, Register reg){
    Node* n_node = malloc(sizeof(Node));

    n_node->next = NULL;
    n_node->reg = reg;
    n_node->back = pila->top;

    if(pila->top != NULL){
       pila->top->next = n_node; 
    }
    pila->top = n_node;
    pila->size++;

    return n_node;
}

Stack* create_stack(){
    Stack* stack = malloc(sizeof(Stack));
    
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void show_stack(Stack* pila){
    Node* temp_node = pila->top;

    printf("Stack size: %d\n", pila->size);
    printf("[\n");
    while(temp_node != NULL){
        printf("\tEmail: %s - Password: %s, \n",
                temp_node->reg.email,
                temp_node->reg.password);

        temp_node = temp_node->back;
    }
    printf("]\n");
}

Register insert_stack(Stack* pila, Register reg, int pos){
    Node* temp_node = pila->top;
    Node* n_node = malloc(sizeof(Node));
    
    n_node->reg = reg;
    n_node->back = NULL;
    n_node->next = NULL;

    if (pos == 0){
        temp_node = push_stack(pila, reg);

    } else if (pila->size-1 < pos){
        while(temp_node->back != NULL){
           temp_node = temp_node->back; 
        }
        n_node->back = NULL;
        n_node->next = temp_node;
        temp_node->back = n_node;
    } else if (pila->size > 1){

        for(int i=1; i < pos; i++){
            temp_node = temp_node->back;     
        }

        n_node->next = temp_node->next;
        n_node->back = temp_node;

        n_node->next->back = n_node;

        temp_node->next = n_node;

        temp_node = n_node;

    }

    pila->size++;
    n_node = NULL; 
    return temp_node->reg;
}

Register pop_stack(Stack* pila){
    Node* temp_node = pila->top;
    Register reg = {};

    if (temp_node != NULL) {
        reg = pila->top->reg;
    
        pila->top = pila->top->back;
        
        if(pila->top !=NULL){
            pila->top->next = NULL;
        }

        pila->size--;
        free(temp_node);
    }
    return reg;
}

Register extract_stack_by_email(Stack* pila, char* email){
    Node* temp_node = pila->top;
    Register reg = {};


    while(temp_node != NULL && strcmp(temp_node->reg.email, email) != 0 ){
        temp_node = temp_node->back;
    }

    if(temp_node != NULL){
        if(temp_node->next != NULL){
            temp_node->next->back = temp_node->back;
        }

        if(temp_node->back != NULL){
            temp_node->back->next = temp_node->next;
        }

        reg = temp_node->reg;
        pila->size--;
        free(temp_node);
    }
      
    return reg;
}

void show_register(Register reg){
    printf("Registro: %s - %s\n", reg.email, reg.password);
}

void free_stack(Stack* pila){
    Node* temp_node;
    while(pila->top != NULL){
        temp_node = pila->top;
        pila->top = pila->top->back;
        free(temp_node);
    }
}
