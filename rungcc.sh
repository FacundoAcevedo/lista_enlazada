#!/bin/bash
OPCIONES="-std=c99 -Wall -predantic -g"


gcc $OPCIONES -c lista.c

gcc $OPCIONES lista.o lista_pruebas.c -o lista_pruebas.bin
