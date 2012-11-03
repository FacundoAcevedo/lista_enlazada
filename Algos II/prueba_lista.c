#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

/* Funcion auxiliar par imprimir resultados de las pruebas: */
void print_test(char* name, bool result)
{
	printf("%s: %s\n", name, result? "OK" : "ERROR");
}


void prueba_unitaria(){	//trabaja con dos entradas y el iterador, prueba acciones básicas.
	printf("\nPRUEBAS UNITARIAS\n\n");
	lista_t* listaP;
	lista_iter_t* iterP;
	char* elemento1="soy el elemento 1";
	char* elemento2="soy el elemento 2";

	listaP=lista_crear();
	print_test("Lista creada esta vacia", lista_esta_vacia(listaP));
	print_test("Lista creada (vacia) tiene primero nulo", lista_ver_primero(listaP)==NULL);
	print_test("Lista creada (vacia) tiene largo 0", lista_largo(listaP)==0);
	print_test("Lista creada (vacia) le inserto primer elemento", lista_insertar_primero(listaP,elemento1));
	print_test("Lista con elemento no esta vacia", !lista_esta_vacia(listaP));
	print_test("Lista con un elemento tiene largo 1", lista_largo(listaP)==1);
	print_test("Primer elemento coincide con elemento insertado", lista_ver_primero(listaP)==elemento1);
	iterP=lista_iter_crear(listaP);
	print_test("Lista se le puede crear un iterador", !(iterP==NULL));
	print_test("Iterador recien creado no esta al final", !lista_iter_al_final(iterP));
	print_test("Primer elemento coincide con elemento insertado", lista_iter_ver_actual(iterP)==elemento1);
	print_test("Puedo insertar en la posicion actual, la primera", lista_insertar(listaP,iterP,elemento2));
	print_test("Lista con dos elementos tiene largo 2", lista_largo(listaP)==2);
	print_test("Primer elemento coincide con elemento insertado", lista_ver_primero(listaP)==elemento2);
	print_test("Primer elemento coincide con elemento insertado", lista_iter_ver_actual(iterP)==elemento2);
	print_test("Borro la primera posicion", lista_borrar(listaP,iterP)==elemento2);
	print_test("Lista con un elemento menos tiene largo 1", lista_largo(listaP)==1);
	print_test("Iterador que no esta al final avanza", lista_iter_avanzar(iterP));
	print_test("Iterador con un elemento y avanzo esta al final", lista_iter_al_final(iterP));
	print_test("Iterador que esta al final no puede avanzar", !lista_iter_avanzar(iterP));
	print_test("Iterador al final no puede leer un dato", lista_iter_ver_actual(iterP)==NULL);
	lista_iter_destruir(iterP);
	print_test("El iterador fue destruido",true);
	print_test("Borro unico elemento, coincide con elemento insertado", lista_borrar_primero(listaP)==elemento1);
	print_test("Lista vaciada esta vacia", lista_esta_vacia(listaP));
	print_test("Lista vaciada tiene primero nulo", lista_ver_primero(listaP)==NULL);
	print_test("Lista vaciada tiene largo 0", lista_largo(listaP)==0);

	print_test("Lista vaciada le inserto ultimo elemento", lista_insertar_ultimo(listaP,elemento1));
	print_test("Lista con elemento no esta vacia", !lista_esta_vacia(listaP));
	print_test("Lista con un elemento tiene largo 1", lista_largo(listaP)==1);
	print_test("Primer elemento coincide con elemento insertado", lista_ver_primero(listaP)==elemento1);
	print_test("Borro unico elemento, coincide con elemento insertado", lista_borrar_primero(listaP)==elemento1);
	print_test("Lista vaciada esta vacia", lista_esta_vacia(listaP));
	print_test("Lista vaciada tiene primero nulo", lista_ver_primero(listaP)==NULL);
	print_test("Lista vaciada tiene largo 0", lista_largo(listaP)==0);

	lista_destruir(listaP,NULL);
}

void prueba_iter(){	//prueba usar el6 allocs, 5 frees, 56 iterador, sin el uso de las funciones que son propias solo de la lista
	printf("\nPRUEBAS CON ITERADOR\n\n");
	lista_t* listaP; lista_iter_t* iterP;
	char* elemento1="soy el elemento 1";
	char* elemento2="soy el elemento 2";
	listaP=lista_crear();
	iterP=lista_iter_crear(listaP);
	print_test("Lista se le puede crear un iterador", !(iterP==NULL));
	print_test("Iterador recien creado en lista vacia esta al final", lista_iter_al_final(iterP));
	print_test("Iterador que esta al final no puede avanzar", !lista_iter_avanzar(iterP));
	print_test("Iterador al final no puede leer un dato", lista_iter_ver_actual(iterP)==NULL);
	print_test("Puedo insertar en la primera posicion", lista_insertar(listaP,iterP,elemento2));
	print_test("Lista con elementos no esta vacia", !lista_esta_vacia(listaP));
	print_test("Lista con un elemento tiene largo 1", lista_largo(listaP)==1);
	print_test("Iterador no esta al final", !lista_iter_al_final(iterP));
	print_test("Puedo insertar en la primera posicion", lista_insertar(listaP,iterP,elemento1));
	print_test("Lista con elementos no esta vacia", !lista_esta_vacia(listaP));
	print_test("Lista con dos elementos tiene largo 2", lista_largo(listaP)==2);
	print_test("Iterador que no esta al final avanza", lista_iter_avanzar(iterP));
	print_test("Puedo borrar donde estoy, recibo el primero que inserte", lista_borrar(listaP,iterP)==elemento2);
	print_test("Iterador esta al final", lista_iter_al_final(iterP));
	print_test("Iterador que esta al final no puede avanzar", !lista_iter_avanzar(iterP));
	print_test("Iterador al final no puede leer un dato", lista_iter_ver_actual(iterP)==NULL);

	lista_iter_destruir(iterP);
	lista_destruir(listaP,NULL);
}

void prueba_lista_con_iter(){	//trabaja con el iterador y prueba el correcto orden de insertar, avanzar y borrar.
	printf("\nPRUEBAS LISTA + ITERADOR\n\n");
	lista_t* listaP;
	lista_iter_t* iterP;
	char* elemento0="soy el elemento 0";
	char* elemento1="soy el elemento 1";
	char* elemento2="soy el elemento 2";
	char* elemento3="soy el elemento 3";
	char* elemento4="soy el elemento 4";
	char* elemento5="soy el elemento 5";
	listaP=lista_crear();
	print_test("Lista le inserto primer elemento", lista_insertar_primero(listaP,elemento4));
	print_test("Lista vaciada le inserto ultimo elemento", lista_insertar_ultimo(listaP,elemento5));

	print_test("Lista le inserto elemento al principio", lista_insertar_primero(listaP,elemento2));

	iterP=lista_iter_crear(listaP);
	print_test("Puedo insertar en la primera posicion", lista_insertar(listaP,iterP,elemento0));
	print_test("Lista con elementos no esta vacia", !lista_esta_vacia(listaP));
	print_test("Lista con cuatro elementos tiene largo 4", lista_largo(listaP)==4);
	print_test("Primer elemento coincide con el elemento que acabo de insertar", lista_ver_primero(listaP)==elemento0);
	print_test("Ver elemento actual coincide con el elemento que inserte", lista_iter_ver_actual(iterP)==elemento0);

	print_test("Iterador que no esta al final avanza", lista_iter_avanzar(iterP));
	print_test("Puedo insertar luego de avanzar", lista_insertar(listaP,iterP,elemento1));
	print_test("Ver elemento actual coincide con el elemento que inserte", lista_iter_ver_actual(iterP)==elemento1);
	print_test("Lista con cinco elementos tiene largo 5", lista_largo(listaP)==5);
	print_test("Puedo borrar donde estoy, recibo el que inserte", lista_borrar(listaP,iterP)==elemento1);
	print_test("Lista con cuatro elementos tiene largo 4", lista_largo(listaP)==4);
	print_test("Puedo volver a insertar sin avanzar", lista_insertar(listaP,iterP,elemento1));

	print_test("Iterador que no esta al final avanza", lista_iter_avanzar(iterP));
	print_test("Iterador que no esta al final avanza", lista_iter_avanzar(iterP));
	print_test("Puedo insertar tras avanzar dos veces", lista_insertar(listaP,iterP,elemento3));
	print_test("Lista con seis elementos tiene largo 6", lista_largo(listaP)==6);
	print_test("Puedo borrar donde estoy, recibo el que inserte", lista_borrar(listaP,iterP)==elemento3);
	print_test("Lista con cinco elementos tiene largo 5", lista_largo(listaP)==5);
	print_test("Puedo volver a insertar", lista_insertar(listaP,iterP,elemento3)); 
	print_test("Iterador que no esta al final avanza", lista_iter_avanzar(iterP));
	print_test("Iterador que no esta al final avanza", lista_iter_avanzar(iterP));
	print_test("Puedo borrar el ultimo elemento, recibo el que uso insertar_ultimo ", lista_borrar(listaP,iterP)==elemento5);
	print_test("Iterador ahora esta al final", lista_iter_al_final(iterP));
	print_test("Iterador que esta al final no puede avanzar", !lista_iter_avanzar(iterP));
	print_test("Iterador al final no puede leer un dato", lista_iter_ver_actual(iterP)==NULL);

	lista_iter_destruir(iterP);
	lista_destruir(listaP,NULL);
}

void prueba_volumen(){	//hace una prueba de volumen si utilizar el iterador
	printf("\nPRUEBAS VOLUMEN\n\n");
	lista_t* listaP;
	lista_iter_t* iterP;
	char* elemento1="soy el elemento 1";
	char* elemento2="soy el elemento 2";     

	listaP=lista_crear();

	bool muchosValores=true;
	int i=0;
	while (muchosValores && i<50){
		i++;
		muchosValores=lista_insertar_ultimo(listaP,elemento2);
	}
	print_test("Puedo insertar muchos valores al final", muchosValores);

	muchosValores=true;
	i=0;
	while (muchosValores && i<100){
		i++;
		muchosValores=lista_insertar_primero(listaP,elemento1);
	}
	print_test("Puedo insertar muchos valores al principio", muchosValores);

	print_test("Lista con largo 150", lista_largo(listaP)==150);

	iterP=lista_iter_crear(listaP);
	print_test("Lista se le puede crear un iterador", !(iterP==NULL));

	muchosValores=true;
	i=0;
	while (muchosValores && i<100){
		i++;
		muchosValores=(lista_iter_avanzar(iterP) && (lista_iter_ver_actual(iterP)==elemento1));
	}

	muchosValores=true;
	i=0;
	while (muchosValores && i<50){
		i++;
		muchosValores=(lista_iter_avanzar(iterP) && (lista_iter_ver_actual(iterP)==elemento2));
	}

	muchosValores=true; i=0;
	while (muchosValores && i<100){
		i++;
		muchosValores=(lista_borrar_primero(listaP)==elemento1);
	}

	muchosValores=true; i=0;
	while (muchosValores && i<50){
		i++;
		muchosValores=(lista_borrar_primero(listaP)==elemento2);
	}

	print_test("Puedo borrar en orden todos los valores", muchosValores);
	print_test("No quedan elementos en la lista", lista_esta_vacia(listaP));
	print_test("Lista vaciada tiene primero nulo", lista_ver_primero(listaP)==NULL);
	print_test("Lista vaciada tiene largo 0", lista_largo(listaP)==0);
	print_test("Creo un ultimo elemento en la lista", lista_insertar_primero(listaP,elemento2));
	print_test("El primer elemento es el elemento que agregue", lista_borrar_primero(listaP)==elemento2);

	lista_iter_destruir(iterP);
	lista_destruir(listaP,NULL);     
}

void prueba_volumen_union(){	//hace una prueba de volumen utilizando el iterador
	printf("\nPRUEBAS VOLUMEN + ITERADOR\n\n");
	int i;
	bool muchosValores;
	lista_t* listaP; lista_iter_t* iterP;
	char* elemento1="soy el elemento 1";
	char* elemento2="soy el elemento 2";

	listaP=lista_crear();
	print_test("Lista creada (vacia) le inserto primer elemento", lista_insertar_primero(listaP,elemento2));
	iterP=lista_iter_crear(listaP);
	print_test("Lista se le puede crear un iterador", !(iterP==NULL));

	muchosValores=true; i=0;
	while (muchosValores && i<200){
		i++;
		muchosValores=(lista_insertar(listaP,iterP,elemento1));
	}

	muchosValores=true; i=0;
	while (muchosValores && i<200){
		i++;
		muchosValores=(lista_borrar(listaP,iterP)==elemento1);
	}

	print_test("Puedo borrar en orden todos los valores", muchosValores);
	
	print_test("Borro primer elemento", lista_borrar_primero(listaP)==elemento2);
	print_test("No quedan elementos en la lista", lista_esta_vacia(listaP));
	print_test("Lista vaciada tiene primero nulo", lista_ver_primero(listaP)==NULL);
	print_test("Lista vaciada tiene largo 0", lista_largo(listaP)==0);

	lista_iter_destruir(iterP);
	lista_destruir(listaP,NULL);
}

void prueba_destruir_dato(){
	lista_t* listaP;
	int* mipuntero1 = malloc(sizeof(int));
	int* mipuntero2 = malloc(sizeof(int));
	int* mipuntero3 = malloc(sizeof(int));
	int* puntero;

	listaP=lista_crear();
	if (mipuntero1 != NULL && mipuntero2 != NULL && mipuntero3 != NULL){
		*mipuntero1 = 1;	
		*mipuntero2 = 2;
		*mipuntero3 = 3;
		print_test("Lista le inserto primer elemento", lista_insertar_primero(listaP,mipuntero3));
		print_test("Lista le inserto primer elemento", lista_insertar_primero(listaP,mipuntero2));
		print_test("Lista le inserto primer elemento", lista_insertar_primero(listaP,mipuntero1));
		print_test("Lista con tres elementos tiene largo 3", lista_largo(listaP)==3);
		puntero=lista_borrar_primero(listaP);
		print_test("Quito el primer elemento de la lista", puntero==mipuntero1);
		free(puntero);
		print_test("Borro un elemento de la lista y hago free manual", true);
		lista_destruir(listaP,free);
		printf("Se destruye la lista, valgrind analiza que no hayan perdidas de memoria");
	}else{
		lista_destruir(listaP,NULL);
	}
}


void pruebas_lista(){
	prueba_unitaria();
	prueba_iter();
	prueba_lista_con_iter();
	prueba_volumen();
	prueba_volumen_union();
	prueba_destruir_dato();
}

int main(void){
	pruebas_lista();
	return 0;
}
