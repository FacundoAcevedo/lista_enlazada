#!/bin/bash
OPCIONES="-std=c99 -Wall -pedantic -g"


gcc $OPCIONES -c lista.c cola.c pila.c

gcc $OPCIONES lista.o cola.o pila.o  lista_pruebas.c -o lista_pruebas.bin
