#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


/* ******************************************************************
 *                        PRUEBAS UNITARIAS
 * *****************************************************************/

/* Funci√≥n auxiliar para imprimir si estuvo OK o no. */
void print_test(char* name, bool result)
{
    printf("%s: %s\n", name, result? "OK" : "ERROR");
}

/* Prueba que las primitivas de la pila funcionen correctamente. */
void prueba_pila()
{
	/* Declaro las variables a utilizar */
	pila_t *p1;
	char *a1="holaa";
	char *a2="comoo";
	char *a3="estaas";

	/* Pruebo la creaci√≥n de una pila */
	p1 = pila_crear();
	print_test("Prueba pila crear p1", p1 != NULL);

	/* Pruebo la pila_esta_vacia con una pila vacia */
	print_test("Prueba pila vacia con pila vacia", pila_esta_vacia(p1));
	print_test("Desapilar una pila vacia da error", pila_desapilar(p1)==NULL);
	print_test("Tope de una pila vacia da nulo", pila_ver_tope(p1)==NULL);

	/* Pruebo apilar una pila */
	print_test("Prueba pila apilar unitario", pila_apilar(p1,a1));

	/* Pruebo que la pila no esta vacia con una pila recien apilada */
	print_test("Prueba pila vacia con pila no vacia", !pila_esta_vacia(p1));

	/* Pruebo ver el tope de una pila no vacia */
	print_test("Prueba pila ver tope unitario", pila_ver_tope(p1)==a1);

	/* Pruebo desapilar una pila no vacia */
	print_test("Prueba pila desapilar unitario", pila_desapilar(p1)==a1);

	/* Pruebo apilar y desapilar 3 valores en una pila */
	pila_apilar(p1,a1);
	pila_apilar(p1,a2);
	pila_apilar(p1,a3);
	print_test("Prueba pila apilar y desapilar por tres", pila_desapilar(p1)==a3 && pila_desapilar(p1)==a2 && pila_desapilar(p1)==a1);

	/* Pruebo apilar y desapilar muchos valores en una pila */
	int i;
	for (i=0;i<1024;i++){
		pila_apilar(p1,a1);
	}
	pila_apilar(p1,a2);
	print_test("Prueba apilar mas valores que el tamaÒo inicial de la pila", pila_desapilar(p1)==a2);
	print_test("Prueba apilar mas valores que el tamaÒo inicial de la pila", pila_desapilar(p1)==a1);

	i=0;
	bool esigual=true;
	while (i<1023 && esigual){
		esigual= (a1 == pila_desapilar(p1));
		i++;
	}

	print_test("Prueba desapilar mas valores que el tama√±o inicial de la pila", esigual);

	/* Pruebo que despues de las operaciones la pila este vacia */
	print_test("Prueba pila vacia con pila vacia", pila_esta_vacia(p1));
	print_test("Desapilar una pila vacia da error", pila_desapilar(p1)==NULL);
	print_test("Tope de una pila vacia da nulo", pila_ver_tope(p1)==NULL);

	pila_destruir(p1,NULL);
}

/* ******************************************************************
 *                        PROGRAMA PRINCIPAL
 * *****************************************************************/

/* Programa principal. */
int main(void)
{
	/* Ejecuta todas las pruebas unitarias. */
	prueba_pila();
	return 0;
}
