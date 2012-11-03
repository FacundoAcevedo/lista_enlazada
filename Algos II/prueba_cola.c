#include "cola.h"
#include <stdio.h>
#include <stdlib.h>

/* Funcion auxiliar par imprimir resultados de las pruebas: */
void print_test(char* name, bool result)
{
    printf("%s: %s\n", name, result? "OK" : "ERROR");
}

void destruir_un_dato(void *midato);

void pruebas_cola(){

	cola_t* colaP=cola_crear();
	char* elemento1="soy el elemento 1";
	char* elemento2="soy el elemento 2";
	char* elemento3="soy el elemento 3";

	print_test("Cola creada esta vacia", cola_esta_vacia(colaP));
	print_test("Cola creada (vacia) tiene primero nulo", cola_ver_primero(colaP)==NULL);
	print_test("No puedo desencolar de cola vacia", cola_desencolar(colaP)==NULL);
	print_test("Puedo encolar primer valor (elemento1)", cola_encolar(colaP, elemento1));
	print_test("La cola no esta vacia", !cola_esta_vacia(colaP));
	print_test("El primero de la cola es el elemento1", cola_ver_primero(colaP)==elemento1);
	print_test("Si desencolo el primer valor es el mismo (elemento1)", cola_desencolar(colaP)==elemento1);

	print_test("Puedo encolar elementos 1,2 y 3", cola_encolar(colaP, elemento1) && cola_encolar(colaP,elemento2) && cola_encolar(colaP,elemento3));
	print_test("Si desencolo tres veces, salen en el orden en el que los puse", cola_desencolar(colaP)==elemento1 && cola_desencolar(colaP)==elemento2 && cola_desencolar(colaP)==elemento3);
	print_test("La cola esta nuevamente vacia", cola_esta_vacia(colaP));
	print_test("El primero de la cola es nulo", cola_ver_primero(colaP)==NULL);

	bool muchosValores=true;
	int i=0;
	while (muchosValores && i<200){
		i++;
		muchosValores=cola_encolar(colaP,elemento1);
	}
	print_test("Puedo encolar muchos valores", muchosValores);

	muchosValores=true; i=0;
	while (muchosValores && i<200){
		i++;
		muchosValores=(cola_desencolar(colaP)==elemento1);
	}
	print_test("Puedo desencolar todos los valores", muchosValores);
	print_test("No quedan elementos en la cola", cola_esta_vacia(colaP));
	print_test("Creo un ultimo elemento en la cola", cola_encolar(colaP,elemento2));
	print_test("El primer elemento es el elemento que agregue", cola_ver_primero(colaP)==elemento2);

	cola_destruir(colaP,NULL);

	colaP=cola_crear();

	int* mipuntero = malloc(sizeof(int));

	if (mipuntero != NULL){
		*mipuntero = 3;
		cola_encolar(colaP, mipuntero);
		print_test("Nuevo puntero encolado: ", cola_ver_primero (colaP) == mipuntero);
		cola_destruir(colaP, free);
	}else{
		cola_destruir(colaP, NULL);
	}
}
     
int main(void){
	pruebas_cola();
	return 0;
}
