#include <stdio.h>

union Dato {
    int entero;
    float decimal;
    char letra;
};

int main(void) {
    union Dato dato;

    dato.entero = 65;

    printf("entero: %d\n", dato.entero);
    printf("decimal: %f\n", dato.decimal);
    printf("letra: %c\n", dato.letra);

    printf("sizeof(union Dato): %zu\n", sizeof(dato));

    return 0;
}
