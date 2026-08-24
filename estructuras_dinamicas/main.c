#include "pila.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    Stack* pila = create_stack();

    char resp;

    Register reg;
    
    printf("Ingresa una cuenta:\n");
    do {
        
        scanf("%s", reg.email);
        scanf("%s", reg.password);
        push_stack(pila, reg);
        
        printf("Desea agregar una cuenta nueva?");
        scanf(" %c", &resp);

    } while (resp == 'y');

    Register n_reg1 = {"bar@gmail.com", "12345"};
    Register n_reg2 = {"grok@gmail.com", "1010"};

    push_stack(pila, n_reg1);
    push_stack(pila, n_reg2);

    show_stack(pila);
    
    Register n_reg3 = {"yiyam@yahoo.com", "tecito"};
    Register insertado = insert_stack(pila, n_reg3, 2);
    
    show_register(insertado);
    show_stack(pila);
    
    Register pop1 = pop_stack(pila);

    show_stack(pila);
    
    char* emailP = "koko";
    
    Register extract1 = extract_stack_by_email(pila, emailP);

    show_stack(pila);

    free_stack(pila);

    free(pila);
    
    return 0;
}
