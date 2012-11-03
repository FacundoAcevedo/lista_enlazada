#!/bin/bash
OPCIONES="-std=c99 -Wall -pedantic -g"


#gcc $OPCIONES -c lista.c cola.c pila.c
gcc $OPCIONES -c tdas.c 

#gcc $OPCIONES tdas.o  lista_pruebas.c -o lista_pruebas.bin
gcc $OPCIONES tdas.o  prueba_lista.c -o prueba_lista.bin
