#include <string.h>
#include <stdio.h>
#include "../include/mstring.h"

// Contar cantidad de caracteres
size_t mstring_len(const char* str){
  size_t acum = 0;
  
  while(str[acum] != 0){
    acum += 1; 
  }

  return acum;
}

// Contar un caracter en un string
size_t mcount_char(const char* str, const char letter){
  size_t acum, count = 0;

  while(str[acum] != 0){
    if(str[acum] == letter){
     count += 1; 
    }
    acum += 1;
  }

  return count;
}

// Encontrar un caracter y devolver el puntero
const char* mfind_char(const char* str, const char letter){
  size_t acum = 0;
  const char* ref = NULL;
  while(str[acum] != 0){
    if(str[acum] == letter){
       ref = &str[acum];
       break;
    }
    acum += 1;
  }
  return ref;
}

/* 
  Comparar dos cadenas
    Retorna -> Cero si son iguales. 
    Retorna -> Negativo si en la diferencia de caracteres el primer string
               es mayor en ascii. EJ: "ABC" > "ABD"
    Retorna -> Positivo si en la diferencia de caracteres el segundo string
               es mayor en ascii. EJ: "ABD" < "ABC"
*/
int mstr_charcmp(const char f, const char s){
  int value;
  if(f == s){
    value = 0;
  }else if (f > s) {
    value = f * (-1);
  }else {
    value = s;
  }
  return value;
}

int mstrcmp(const char* f_word, const char* s_word){
  int value;

  int len_f_word = mstring_len(f_word);
  int len_s_word = mstring_len(s_word);

  int minor = len_f_word >= len_s_word? len_f_word: len_s_word;

  for (int i=0; i<minor; i++) {
    value = mstr_charcmp(f_word[i], s_word[i]);
    if(value != 0){
      break;
    }
  }

  return value;
}

// -- Copiar una cadena en otra cadena vacia o no. --
// La funcion asume que el destino tiene espacio
// suficiente para grabar la palabra
char* mstrcpy(const char* word, char* destino){
  int i = 0;

  while(word[i] != 0){
    destino[i] = word[i];

    i += 1;
  }
  destino[i] = 0;
  return destino;
}

char* mstrcpy_safe(const char* word, char* destino, size_t tam){
  int i = 0;
  int word_tam = mstring_len(word) + 1;

  if(word_tam < tam){
    while(word[i] != 0){
      destino[i] = word[i];

      i += 1;
    }
    destino[i] = 0;
  }else{
   destino = ""; 
  }

  return destino;
}

char* mstr_concat(const char* word, char *destino){
  int i = 0;
  int j = 0;

  while(destino[i] != 0){
    i += 1;
  }

  while(word[j] != 0){
    destino[i] = word[j];
    j += 1;
    i += 1;
  }
  destino[i] = 0;
  return destino;
}

char* mstr_concat_safe(const char* word, char* destino, size_t tam){
  int i = 0;
  int j = 0;
  int word_tam = mstring_len(word);

  while(destino[i] != 0){
    i += 1;
  }
  if((word_tam + i + 1) < tam){
    while(word[j] != 0){
      destino[i] = word[j];
      i += 1;
      j += 1;
    }
  }
  destino[i] = 0;
  return destino;
}

// Leer del teclado
MReadStatus read_line(char* buffer, size_t size){
  MReadStatus response;
  fgets(buffer, size, stdin);

  
  return response;
}
