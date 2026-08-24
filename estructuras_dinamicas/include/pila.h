#ifndef PILA_H
#define PILA_H

// Estructuras encapsuladas
typedef struct Node Node;
typedef struct Stack Stack;

// Estructuras no encapsuladas (visibles)
typedef struct Register {
    char email [40];
    char password [40];
} Register;


// Funciones 
Node* push_stack(Stack *pila, Register reg);
Stack* create_stack();
void show_stack(Stack* pila);
Register insert_stack(Stack* pila, Register reg, int pos);
void free_stack(Stack* pila);
Register pop_stack(Stack* pila);
Register extract_stack_by_email(Stack* pila, char* email);
void show_register(Register reg);



#endif
