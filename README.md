# Prácticas en C y Estructuras de Datos

Este repositorio contiene una serie de ejercicios y proyectos diseñados para practicar y dominar el lenguaje C, enfocándose fuertemente en el modelo mental, el manejo de memoria a bajo nivel y las estructuras de datos dinámicas.

El desarrollo sigue un plan de estudio intensivo estructurado en dos semanas:

## 📚 Plan de Estudio

### Semana 1: Sintaxis y Modelo Mental
- **Día 1:** Setup y conceptos básicos (compilación, flags, argc/argv, I/O con `fgets`).
- **Día 2:** Tipos de datos, `sizeof`, direcciones de memoria y el **Stack**.
- **Día 3:** Punteros (operadores `&` y `*`, doble punteros).
- **Día 4:** Arrays como memoria contigua y Strings en C (`\0`, `strlen` manual).
- **Día 5:** Estructuras (`struct`), pasaje por valor vs referencia.
- **Día 6:** El **Heap** real (`malloc`, `calloc`, `free`, prevención de leaks, address sanitizer).
- **Día 7:** Implementación de un Vector Dinámico básico (`push`, `realloc`).

### Semana 2: Nivel Ingeniero
- **Día 8:** Funciones, modularización y separación de módulos (`.h`, `static`, `extern`).
- **Día 9:** Punteros avanzados (punteros a función, tabla de funciones).
- **Día 10:** Layout de memoria (padding, alineación, `offsetof`, packing).
- **Día 11:** Strings a fondo (`strtok`, `memcpy`, `memmove`).
- **Día 12:** Estructuras dinámicas (Listas enlazadas, nodos dinámicos).
- **Día 13:** Mini-proyecto: Lector de archivos, parsing y almacenamiento dinámico.
- **Día 14:** Debugging profundo con **GDB** (breakpoints, inspección de memoria).

## 🛠️ Tecnologías y Herramientas
- **Lenguaje:** C (Estándar C11)
- **Compilador:** GCC (con flags recomendados como `-Wall -Wextra -std=c11`)
- **Debugging:** GDB y Address Sanitizer (`-fsanitize=address`)

## 📂 Estructura del Repositorio
- `Ejercicios/`: Prácticas diarias.
- `estructuras_dinamicas/` / `libestructuras/`: Implementación propia de estructuras de datos como listas y vectores.
- `libstring/`: Funciones y herramientas para trabajar con cadenas de caracteres.
- `PLAN.md`: Archivo con el plan y rutinas de aprendizaje originales.
