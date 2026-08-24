#include <stdio.h>

int main(void) {
    char nombre[] = "Juan";
    
    nombre [2] = 'x';
    printf("%s\n", nombre);
    printf("%c\n", nombre[0]);
    printf("%c\n", nombre[1]);
    printf("%c\n", nombre[2]);
    printf("%d\n", nombre[4]);
    printf("%d\n", nombre[5]);
    printf("%d\n", nombre[6]);

    printf("sizeof: %zu\n", sizeof(nombre));

    return 0;
}
