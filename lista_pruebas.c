#include "lista.h"
#include "pila.h"
#include "cola.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


/* ******************************************************************
 *                        PRUEBAS UNITARIAS 
 * *****************************************************************/

/* Funcion auxiliar para imprimir si estuvo OK o no. */
void print_test(char* name, bool result) {
	printf("%s: %s\n", name, result? "OK" : "ERROR");
}
	
void (destruir)(void* dato) {
	pila_destruir((pila_t*)dato);
	puts("OK");
}

void prueba_lista(void){
// DATOS ESTATICOS    
int cero = 0;
int uno = 1;
int *val0 ;
val0 = &cero;
int *val1;
val1 = &uno; 
char *val2 = "Sexy Chambelan";

//DATOS DINAMICOS
// Pilas
pila_t* pila1 = pila_crear();
pila_apilar(pila1, val0);
pila_apilar(pila1, val1);
pila_apilar(pila1, val2);
pila_t* pila2 = pila_crear();
// cola
cola_t* cola = cola_crear();
cola_encolar(cola, val1);
cola_encolar(cola, val2);
cola_encolar(cola, val1);
cola_encolar(cola, val0);
cola_encolar(cola, val2);


printf("\n\n ########### COMIENZO DE PRUEBAS ########### \n\n");

//Creo las listas
lista_t *lista_est = lista_crear();
lista_t *lista_pilas = lista_crear();
lista_t *lista_listas = lista_crear();



printf("######## lista con datos estaticos ########\n");
// La lista_est debe estar vacia
print_test("1) Prueba lista_esta_vacia",lista_esta_vacia(lista_est)); //OK
print_test("2) Prueba lista_ver_primero", lista_ver_primero(lista_est)==NULL); //OK

// Inserto val0 en el 1er lugar. La lista_est tiene un elemento.
print_test("3) Inserto en el 1er lugar val0 a lista_est", lista_insertar_primero(lista_est, val0)); //OK
// La lista_est no esta vacia
print_test("4) Prueba lista_esta_vacia",!lista_esta_vacia(lista_est)); //OK

//Inserto val1 en el 1er lugar. La lista_est tiene dos elementos.
print_test("5) Inserto val1  en el 1er lugar a la lista_est", lista_insertar_primero(lista_est, val1)); //OK

//Inserto val2 en el 1er lugar. La lista_est tiene dos elementos.
print_test("5) Inserto val2  en el 1er lugar a la lista_est", lista_enlistar(lista_est, val2)); //OK
//Chequeo que el primero de la lista_est sea val2.
print_test("7) Prueba lista_ver_primero", lista_ver_primero(lista_est)==val2); //OK

//Inserto val2 en el ultimo lugar. La lista_est tiene dos elementos.
print_test("5) Inserto val2  en ultimo lugar a la lista_est", lista_insertar_ultimo(lista_est, val2)); //OK
//Chequeo que el primero de la lista_est sea val2.
print_test("7) Prueba lista_ver_primero", lista_ver_primero(lista_est)==val2); //OK


//~ //DesInserto el primer elemento de la lista_est: val0. La lista_est tiene 2 elementos.
//~ print_test("8) Prueba lista_desenlistar",val0 == lista_desenlistar(lista_est)); //OK
//~ 
//~ //Chequeo que el priemro de la lista_est sea val1.
//~ print_test("9) Prueba lista_ver_primero", lista_ver_primero(lista_est)==val1);
//~ 
//~ //DesInserto el segundo elemento de la lista_est: val1. La lista_est tiene 1 elemento.
//~ print_test("10) Prueba lista_desenlistar",val1 == lista_desenlistar(lista_est)); //OK
//~ print_test("11) Prueba lista_esta_vacia",!lista_esta_vacia(lista_est)); //OK
//~ //Chequeo que el primero de la lista_est sea val2.
//~ print_test("12) Prueba lista_desenlistar",lista_ver_primero(lista_est) == val2); //OK
//~ 
//~ //DesInserto el tercer elemento: val2. La lista_est quedo vacia.
//~ print_test("13) Prueba lista_desenlistar",val2 == lista_desenlistar(lista_est)); //OK
//~ print_test("14) Prueba lista_esta_vacia", lista_esta_vacia(lista_est));
//~ 
//~ //Intento desenlistar. Como esta vacia, retorna NULL.
//~ print_test("15) Prueba lista_desenlistar", lista_desenlistar(lista_est) == NULL); //OK
//~ 
//~ printf("\n\n");
//~ 
//~ 
//~ 
//~ printf("######## lista con pilas como datos ########\n");
//~ // Inserto pila1 a lista_pilas. La lista_pilas tiene un elemento.
//~ print_test("16) Inserto pila1 a la lista_pilas", lista_enlistar(lista_pilas, pila1)); //OK
//~ // La lista_pilas no esta vacia
//~ print_test("17) Prueba lista_esta_vacia",!lista_esta_vacia(lista_pilas)); //OK
//~ 
//~ // Inserto pila1 de nuevo. La lista_pilas tiene 2 elementos.
//~ print_test("18) Inserto pila1 a la lista_pilas", lista_enlistar(lista_pilas, pila1)); //OK
//~ 
//~ // Inserto pila2. La lista_pilas tiene 3 elementos.
//~ print_test("19) Inserto pila2 a la lista_pilas", lista_enlistar(lista_pilas, pila2)); //OK
//~ 
//~ //Desencolo el primer elemento de la lista_pilas: pila1. La lista_pilas tiene 2 elementos.
//~ print_test("20) Prueba lista_desenlistar",pila1 == lista_desenlistar(lista_pilas)); //OK
//~ 
//~ //Desencolo el segundo elemento de la lista_pilas: pila1. La lista_pilas tiene 1 elementos.
//~ print_test("21) Prueba lista_desenlistar", pila1 == lista_desenlistar(lista_pilas));
//~ 
//~ //Desencolo el tercer elemento de la lista_pilas: pila2. La lista_pilas queda vacia.
//~ print_test("22) Prueba lista_desenlistar", pila2 == lista_desenlistar(lista_pilas));
//~ print_test("23) Prueba lista_esta_vacia", lista_esta_vacia(lista_pilas));
//~ // Inserto pila1 de nuevo. La lista_pilas tiene 2 elementos.
//~ print_test("BISSS) Inserto pila1 a la lista_pilas", lista_enlistar(lista_pilas, pila1)); //OK
//~ print_test("BISSS) Inserto pila2 a la lista_pilas", lista_enlistar(lista_pilas, pila2)); //OK
//~ 
//~ printf("\n\n");
//~ 
//~ 
//~ 
//~ printf("######## lista con listas como datos ########\n");
//~ // Inserto lista_aux a lista_listas. La lista_listas tiene un elemento.
//~ print_test("24) Inserto lista_aux a la lista_listas", lista_enlistar(lista_listas, lista_aux)); //OK
//~ // La lista_aux no esta vacia
//~ print_test("25) Prueba lista_esta_vacia",!lista_esta_vacia(lista_listas)); //OK
//~ 
//~ //Desencolo el primer elemento de la lista_listas: lista_aux. La lista_listas tiene 0 elementos.
//~ print_test("26) Prueba lista_desenlistar",lista_aux == lista_desenlistar(lista_listas)); //OK
//~ print_test("27) Prueba lista_esta_vacia", lista_esta_vacia(lista_listas));
//~ 
//~ printf("\n\n");
//~ 
//~ // Destruyo lista_est
//~ lista_destruir(lista_est, NULL);
//~ 
//~ // Destruyo lista_aux
//~ lista_destruir(lista_aux, NULL);
//~ 
//~ // Destruyo lista_listas
//~ lista_destruir(lista_listas, NULL);
//~ 
//~ // Destruyo lista_pilas
//~ lista_destruir(lista_pilas, (*destruir));
//~ 

printf("\n\n ########### FIN DE PRUEBAS ########### \n\n");





}
//~ /* ******************************************************************
 //~ *                        PROGRAMA PRINCIPAL
 //~ * *****************************************************************/

/* Programa principal. */
int main(void) {
	//~ /* Ejecuta todas las pruebas unitarias. */
	prueba_lista();
	return 0;
}
