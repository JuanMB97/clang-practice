#include "mstring.h"
#include <stdio.h>

int main(){
  char word[] = "banana";
  size_t tam = mstring_len(word);
  
  printf("La palabra tiene %zu caracteres. \n", tam);
  

  size_t cant = mcount_char(word, 'a');

  printf("Cantidad de 'a' en %s es %zu. \n", word, cant);

  const char* p_letter = mfind_char(word, 'a');

  if(p_letter != NULL){
    printf("PUNTERO -> %p \n", p_letter);
  }

  // Test comparar strings
  int res = mstrcmp("banana", "banananA");

  printf("VALOR: %d \n", res);
  //int res = mstrcmp("Juan", "Juan");

  // reemplaza string por otro.
  char dst[5]; 
  char *data = mstrcpy("Juan", dst);


  printf("Destino: %s \n", data);

  // Reemplaza string
  //int tam_safe = 10;
  char dst_safe[5];
  
  char *data_safe = mstrcpy_safe("Mogolicores", dst_safe, 15);
  
  if(data_safe != NULL){
    printf("SAFE: %s \n", data_safe);
  }else{
    printf("Es NULL \n");
  }
  
  char spc[20] = "Juan el ";
  char* concat = mstr_concat("Loco ", spc);

  printf("CONCAT: %s \n", concat);

  char* concat_safe = mstr_concat_safe("go", spc, 20);

  return 0;
}
