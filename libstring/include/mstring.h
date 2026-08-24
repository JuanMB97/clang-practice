#include <string.h>
#ifndef MSTRING_H
#define MSTRING_H

size_t mstring_len(const char* str);
size_t mcount_char(const char* str, const char letter);
const char* mfind_char(const char* str, const char letter);
int mstrcmp(const char* f_word, const char* s_word);
int mstr_charcmp(const char f, const char s);
char* mstrcpy(const char* word, char* destino);
char* mstrcpy_safe(const char* word, char* destino, size_t tam);
char* mstr_concat(const char* word, char* destino);
char* mstr_concat_safe(const char* word, char* destino, size_t tam);
typedef enum {
  READ_OK,
  READ_EOF,
  READ_ERROR,
} MReadStatus;
MReadStatus read_line(char* buffer, size_t size);
#endif

