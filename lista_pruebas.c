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

// FUNICONES DESTRUIR
void (destruir_pila)(void* dato) {
	pila_destruir((pila_t*)dato);
}

void (destruir_lista_)(void* dato) {
	lista_destruir((lista_t*)dato,NULL);
}

void (destruir_cola)(void*dato){
	cola_destruir((cola_t*)dato, NULL);
	}

void prueba_lista(void){
// DATOS ESTATICOS    
int cero = 0;
int uno = 1;
int *val0 ;
val0 = &cero;
int *val1;
val1 = &uno; 
char *val2 = "Porno duro";

//DATOS DINAMICOS
// Pilas
pila_t* pila1 = pila_crear();
pila_apilar(pila1, val0);
pila_apilar(pila1, val1);
pila_apilar(pila1, val2);
pila_t* pila2 = pila_crear();
// cola
cola_t* cola1 = cola_crear();
cola_t* cola2 = cola_crear();
cola_t* cola3 = cola_crear();
cola_encolar(cola1, val1);
cola_encolar(cola1, val2);
cola_encolar(cola2, val1);
cola_encolar(cola3, val0);



printf("\n\n ########### COMIENZO DE PRUEBAS ########### \n\n");

//Creo las listas
lista_t *lista_vacia = lista_crear();
lista_t *lista_est = lista_crear();
lista_t *lista_pilas = lista_crear();
lista_t *lista_colas = lista_crear();
lista_t *lista_listas = lista_crear();



printf("######## lista con datos estaticos ########\n");
// La lista_est debe estar vacia. lista_est = []
print_test("1) Prueba lista_esta_vacia",lista_esta_vacia(lista_est)); 
print_test("2) Prueba lista_ver_primero", lista_ver_primero(lista_est)==NULL); 
print_test("3) Prueba lista_largo", lista_largo(lista_est)== 0); 

// Inserto val0 en el 1er lugar. lista_est = [val0]
print_test("4) Inserto en el 1er lugar val0 a lista_est", lista_insertar_primero(lista_est, val0)); 
// La lista_est no esta vacia
print_test("5) Prueba lista_esta_vacia",lista_esta_vacia(lista_est)==false); 
print_test("6) Prueba lista_ver_primero", lista_ver_primero(lista_est)!=NULL); 

//Inserto val1 en el 1er lugar. lista_est = [val1, val0]
print_test("7) Inserto val1  en el 1er lugar a la lista_est", lista_insertar_primero(lista_est, val1)); 

//Inserto val2 en el 1er lugar. lista_est = [val2, val1, val0]
print_test("8) Inserto val2  en el 1er lugar a la lista_est", lista_insertar_primero(lista_est, val2)); 

//Chequeo que el primero de la lista_est sea val2.
print_test("9) Prueba lista_ver_primero", lista_ver_primero(lista_est)==val2); 

//Inserto val1 en el ultimo lugar. lista_est = [val2, val1, val0, val1]
print_test("10) Inserto val1  en ultimo lugar a la lista_est", lista_insertar_ultimo(lista_est, val1)); 
//Chequeo que el primero de la lista_est siga siendo val2.
print_test("11) Prueba lista_ver_primero", lista_ver_primero(lista_est)==val2); 
//Chequeo que el largo de la lista sea de 4.
print_test("12) Prueba lista_largo", lista_largo(lista_est) == 4);

 
//Borro el primer elemento de la lista_est: val2. lista_est = [val1, val0, val1]
print_test("13) Prueba lista_borrar_primero",val2 == lista_borrar_primero(lista_est));   

//Chequeo que el priemro de la lista_est sea val1.
print_test("14) Prueba lista_ver_primero", lista_ver_primero(lista_est)==val1);

//Borro con lista_borrar_primero los elementos que quedan para verificar
//que se comporta correctamente al recibir una lista vacia.

print_test("15) Prueba lista_borrar_primero",val1 == lista_borrar_primero(lista_est));   
print_test("16) Prueba lista_borrar_primero",val0 == lista_borrar_primero(lista_est));   
print_test("17) Prueba lista_borrar_primero",val1 == lista_borrar_primero(lista_est));   
// La lista esta vacia.
print_test("18) Prueba lista_borrar_primero",NULL == lista_borrar_primero(lista_est));   

// Inserto val0 con lista_insertar_ultimo. lista_est = [val0]
print_test("19) Prueba lista_insertar_ultimo", lista_insertar_ultimo(lista_est, val0));
print_test("20) Prueba lista_insertar_ultimo", lista_ver_primero(lista_est) == val0);
// Inserto val1 con lista_insertar_ultimo. lista_est = [val0, val1]
print_test("21) Prueba lista_insertar_ultimo", lista_insertar_ultimo(lista_est, val1));
// Inserto val2 con lista_insertar_ultimo. lista_est = [val0, val1, val2]
print_test("22) Prueba lista_insertar_ultimo", lista_insertar_ultimo(lista_est, val2));


printf("######## Pruebas del iterador ########\n");

// Intento crear un iterador de lista_vacia. Devuelve NULL.
lista_iter_t* iteradorNull = lista_iter_crear(lista_vacia);
print_test("23) Prueba lista_iter_crear", iteradorNull == NULL);

// Creo un iterador de lista_est (no vacia). lista_est= [val0, val1, val2]
lista_iter_t* iterador0 = lista_iter_crear(lista_est);

// Uso este iterador para recorrer toda la lista y chequear que se trata de [val0, val1, val2]
print_test("24) Prueba lista_iter_ver_actual", lista_iter_ver_actual(iterador0) == val0);
lista_iter_avanzar(iterador0);
print_test("25) Prueba lista_iter_ver_actual", lista_iter_ver_actual(iterador0) == val1);
lista_iter_avanzar(iterador0);
print_test("26) Prueba lista_iter_ver_actual", lista_iter_ver_actual(iterador0) == val2);
print_test("27) Prueba lista_iter_avanzar", !lista_iter_avanzar(iterador0));
//Chequeo que me encuentro al final de la lista.
print_test("28) Prueba lista_iter_al_final", lista_iter_al_final(iterador0));



// Elimino este iterador.
lista_iter_destruir(iterador0);

// Creo otro iterador de lista_est.
lista_iter_t* iterador = lista_iter_crear(lista_est);
// Avanzo un lugar para ubicarme en val1.
lista_iter_avanzar(iterador);
// lista_est = [val0, val1, val2] iterador = val1.
//Chequeo que NO me encuentro al final de la lista.
print_test("29) Prueba lista_iter_al_final", !lista_iter_al_final(iterador));

// Inserto val2 en la posicion del iterador (val1).
lista_insertar(lista_est, iterador, val2);
// lista_est = [val0, val2, val1, val2]. iterador = val2
// Chequeo posicion del iterador (debe haber cambiado a val2).
print_test("30) Prueba lista_iter_ver_actual", lista_iter_ver_actual(iterador) == val2);
// Avanzo y chequeo que el siguiente valor sea val1.
lista_iter_avanzar(iterador);
print_test("31) Prueba lista_iter_ver_actual", lista_iter_ver_actual(iterador) == val1);

// Borro val1 con lista_borrar.
print_test("32) Prueba lista_borrar", lista_borrar(lista_est, iterador) == val1);

//Avanzo de nuevo. iterador = val2. lista_est = [val0, val2, val2]
lista_iter_avanzar(iterador);
//Chequeo que SI me encuentro al final de la lista.
print_test("33) Prueba lista_iter_al_final", lista_iter_al_final(iterador));
// Chequeo que el ultimo es val2.
print_test("34) Prueba lista_iter_ver_actual", lista_iter_ver_actual(iterador) == val2);

// Avanzo de nuevo. Devuelve false.
print_test("35) Prueba lista_iter_avanzar", lista_iter_avanzar(iterador) == false);
// Chequeo que el intento de avanzar no descoloco al iterador.
print_test("36) Prueba lista_iter_ver_actual", lista_iter_ver_actual(iterador) == val2);


printf("\n\n######## lista con pilas como datos ########\n");
// Inserto en el 1er lugar pila1 a lista_pilas. lista_pilas=[pila1]
print_test("37) Inserto en el 1er lugar pila1 a la lista_pilas", lista_insertar_primero(lista_pilas, pila1));
// La lista_pilas no esta vacia
print_test("38) Prueba lista_esta_vacia",!lista_esta_vacia(lista_pilas));

// Inserto pila2 en el 1er lugar. lista_pilas=[pila2, pila1]
print_test("39) Inserto pila2 en el 1er lugar a la lista_pilas", lista_insertar_primero(lista_pilas, pila2));   

// Creo un iterador de lista_pilas.
lista_iter_t* iterador2 = lista_iter_crear(lista_pilas);
lista_iter_avanzar(iterador2);
// Avanzo una posicion. iterador2 = pila1.
// Borro pila1 con lista_borrar. lista_pilas=[pila2]
print_test("40) Prueba lista_borrar",pila1 == lista_borrar(lista_pilas, iterador2));   

// Compruebo que me haya quedado 1 elementos en la lista.
print_test("41) Prueba lista_largo", lista_largo(lista_pilas)==1);  
print_test("42) Prueba lista_esta_vacia",!lista_esta_vacia(lista_pilas)); 


printf("\n\n");

printf("######## lista con colas como datos ########\n");
// Inserto en el 1er lugar cola1 a lista_colas. lista_colas=[cola1]
print_test("43) Inserto en el 1er lugar cola1 a la lista_colas", lista_insertar_primero(lista_colas, cola1));
// La lista_colas no esta vacia
print_test("44) Prueba lista_esta_vacia",!lista_esta_vacia(lista_colas));

// Inserto cola2 en el ultimo lugar. lista_colas=[ cola1, cola2]
print_test("45) Inserto cola2 en el ultimo lugar a la lista_colas", lista_insertar_ultimo(lista_colas, cola2));   

// Inserto cola3 en el ultimo lugar. lista_colas=[cola1, cola2, cola3]
print_test("46) Inserto cola3 en el ultimo lugar a la lista_colas", lista_insertar_ultimo(lista_colas, cola3));   

// Creo un iterador de lista_colas.
lista_iter_t* iterador3 = lista_iter_crear(lista_colas);
lista_iter_avanzar(iterador3);
lista_iter_avanzar(iterador3);
// Avanzo 2 posiciones. iterador3 = cola3.
// Borro cola3 con lista_borrar. lista_colas=[cola1, cola2]
print_test("47) Prueba lista_borrar",cola3 == lista_borrar(lista_colas, iterador3));   

print_test("48) Prueba lista_largo", lista_largo(lista_colas)==2);  
print_test("49) Prueba lista_esta_vacia",!lista_esta_vacia(lista_colas)); 


printf("\n\n");

printf("######## lista con listas como datos ########\n");
// Inserto en el 1er lugar lista_est a lista_listas. lista_listas=[lista_est]
print_test("50) Inserto en el 1er lugar lista_est a la lista_listas", lista_insertar_primero(lista_listas, lista_est));
// La lista_listas no esta vacia
print_test("51) Prueba lista_esta_vacia",!lista_esta_vacia(lista_listas));

// Inserto lista_pilas en el 1er lugar. lista_listas=[lista_pilas, lista_est]
print_test("52) Inserto lista_pilas en el 1er lugar a la lista_listas", lista_insertar_primero(lista_listas, lista_pilas));   

// Inserto lista_colas en el 1er lugar. lista_listas=[lista_colas, lista_pilas, lista_est]
print_test("53) Inserto lista_colas en el primer lugar a la lista_listas", lista_insertar_primero(lista_listas, lista_colas));   

// Creo un iterador de lista_listas.
lista_iter_t* iterador4 = lista_iter_crear(lista_listas);
lista_iter_avanzar(iterador4);
lista_iter_avanzar(iterador4);
// Avanzo 2 posiciones. iterador4 = lista_est.
// Borro lista_est con lista_borrar. lista_listas=[lista_colas, lista_pilas]
print_test("54) Prueba lista_borrar",lista_est == lista_borrar(lista_listas, iterador4));   
// Compruebo que me haya quedado un solo elemento en la lista.
print_test("55) Prueba lista_largo", lista_largo(lista_listas)==2);  
print_test("56) Prueba lista_esta_vacia",!lista_esta_vacia(lista_listas)); 

// Elimino el iterador.
//~ lista_iter_destruir(iterador4);

printf("\n\n");

// Destruyo iteradores
lista_iter_destruir(iteradorNull);
lista_iter_destruir(iterador);
lista_iter_destruir(iterador2);
lista_iter_destruir(iterador3);
lista_iter_destruir(iterador4);


// Creo y destruyo una lista vacia
lista_t* lista1 = lista_crear();
lista_destruir(lista1, NULL);



// Destruyo lista_pilas
lista_destruir(lista_pilas, (*destruir_pila));

// Destruyo lista_colas
lista_destruir(lista_colas, (*destruir_cola));

// Destruyo lo que queda
lista_destruir(lista_vacia, NULL);

/*lista_destruir(lista_est, NULL);*/
lista_destruir(lista_est, NULL);


// Destruyo lista_listas
lista_destruir(lista_listas, NULL);
//destruyo los obj dinamicos

/*pila_destruir(pila1);*/
/*pila_destruir(pila2);*/
/*cola_destruir(cola1,NULL);*/
/*cola_destruir(cola2,NULL);*/
/*cola_destruir(cola3,NULL);*/
printf("\n ########### FIN DE PRUEBAS ########### \n\n");





}
	/* ******************************************************************
	 *                        PROGRAMA PRINCIPAL
	 * *****************************************************************/

/* Programa principal. */
int main(void) {
	/* Ejecuta todas las pruebas unitarias. */
	prueba_lista();
	return 0;
}
