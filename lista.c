#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "lista.h"


typedef struct nodo{
    void* valor;
    struct nodo* ref;
} nodo_t;

struct lista{
	nodo_t* lista_inicio;
    nodo_t* lista_fin;
	size_t largo;
};


struct lista_iter{
	/*lista_t* anterior;*/
	/*lista_t* actual;*/
	nodo_t* anterior;
	nodo_t* actual;
};
//~ 




/* ******************************************************************
 *                    PRIMITIVAS BASICAS DE LA LISTA
 * *****************************************************************/

//FUNCION AUXILIAR: creacion de un nodo
//Recibe un valor. Devuelve el nodo.
 nodo_t* nodo_crear(void* valor){
    nodo_t* nodo = malloc(sizeof(nodo_t));
    if (nodo == NULL) return NULL;
    nodo->valor = valor;
    nodo_t* ref = NULL;
    nodo->ref = ref;
    return nodo;
}


// Crea una lista.
// Post: devuelve una nueva lista vacia.
lista_t* lista_crear(){
typedef nodo_t * lista_t;
	lista_t* lista;
	lista = malloc(sizeof(lista_t));
	if (lista == NULL) return NULL;
	nodo_t* nodo = NULL;
	*lista = nodo;
	return lista;
}
 
 
 
 
// Destruye la lista. Si se recibe la funciÃÂ³n destruir_dato por parÃÂ¡metro,
// para cada uno de los elementos de la lista llama a destruir_dato.
// Pre: la lista fue creada. destruir_dato es una funciÃÂ³n capaz de destruir
// los datos de la lista, o NULL en caso de que no se la utilice.
// Post: se eliminaron todos los elementos de la lista.
 void lista_destruir(lista_t *lista, void destruir_dato(void *)){
	puts("Entre a lista_destruir");
		nodo_t *siguiente = lista->lista_inicio;
        nodo_t *nodo_ref = NULL;
        
        //Revisar si llega hasta el final!!	
        if (destruir_dato != NULL){ 
			puts("ENTRE AL IF DE DESTRUIR DATO!");
			while (true){
				puts("ENTRE AL WHILE DE DESTRUIR DATO!");
				destruir_dato(siguiente->valor);	
				if (siguiente->ref == NULL) break;
				siguiente = siguiente->ref;
				}
			}
        siguiente = lista->lista_inicio;
        nodo_ref = siguiente->ref;
        //Mato todos los nodo
        while (nodo_ref->ref){
            free(siguiente);
            siguiente = nodo_ref->ref;
            free(nodo_ref);
            nodo_ref = siguiente->ref;
        }//while
        //finalmente mato a la lista
        free(lista);
 }


// Devuelve dato de tipo size_t expresando la cantidad de elementos que contiene
// la lista. Si la lista no contiene elementos, devuelve 0.
// Pre: la lista fue creada.
size_t lista_largo(const lista_t *lista){
	printf("lista segun lista_largo: %p.\n", lista->lista_inicio);
	return lista->largo;
	}


// Devuelve verdadero o falso, segÃÂºn si la lista tiene o no elementos.
// Pre: la lista fue creada.
bool lista_esta_vacia(const lista_t *lista){
	printf("largo segun esta_vacia: %zu.\n", lista->largo);
	printf("lista segun esta_vacia: %p.\n", lista->lista_inicio);
	if (lista->largo == 0) return true;
	return false;
}

//~ // Agrega un nuevo elemento a la lista en la primera posicion. Devuelve 
//~ // falso en caso de error.
//~ // Pre: la lista fue creada.
//~ // Post: se agrego un nuevo elemento a la lista, valor se encuentra al principio
//~ // de la lista.

 bool lista_insertar_primero(lista_t *lista, void *dato){
	nodo_t* nuevo_nodo = nodo_crear(dato);
    if (lista->largo == 0){
        lista->lista_inicio = nuevo_nodo;
        lista->lista_fin = nuevo_nodo;
    }
    else
	    nuevo_nodo->ref = lista->lista_inicio;
        lista->lista_inicio = nuevo_nodo;

	printf("largo segun insertar antes de insertar: %zu\n", lista->largo);
	lista->largo= lista->largo + 1;
	printf("largo segun insertarluego de insertar: %zu\n", lista->largo);	
	/*lista->lista_inicio = nuevo_nodo;*/
	printf("lista segun insertar luego de lista = nodo_nuevo:  %p\n", lista->lista_inicio);

	return true; //que error puede haber? RTA: puede haber un monton!...
}
	

//~ // Agrega un nuevo elemento a la lista en la ultima posicion. Devuelve 
//~ // falso en caso de error.
//~ // Pre: la lista fue creada.
//~ // Post: se agrego un nuevo elemento a la lista, valor se encuentra al final
//~ // de la lista.
bool lista_insertar_ultimo(lista_t *lista, void *dato){
	nodo_t* nuevo_nodo = nodo_crear(dato);
    if (nuevo_nodo == NULL) return false;
    else if (lista->largo == 0){
        lista->lista_inicio = nuevo_nodo;
        lista->lista_fin = nuevo_nodo;
    }
    else
    {
        (lista->lista_fin)->ref = nuevo_nodo;
        lista->lista_fin= nuevo_nodo;
    }
	lista->largo += 1;
	return true; //que error puede haber? RTA: puede haber un monton!...
 }


// Obtiene el valor del primer elemento de la lista. Si la lista tiene
// elementos, se devuelve el valor del primero, si estÃÂ¡ vacÃÂ­a devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolviÃÂ³ el primer elemento de la lista, cuando no estÃÂ¡ vacÃÂ­a.
void *lista_ver_primero(const lista_t *lista){
	if (lista_esta_vacia(lista) == true) return NULL;
	printf("lista segun ver_primero %p\n", (lista->lista_inicio)->valor);
	return (lista->lista_inicio)->valor;
	}
	

//~ 
//~ // Saca el primer elemento de la lista. Si la lista tiene elementos, se quita el
//~ // primero de la lista, y se devuelve su valor, si estÃÂ¡ vacÃÂ­a, devuelve NULL.
//~ // Pre: la lista fue creada.
//~ // Post: se devolviÃÂ³ el valor del primer elemento anterior, la lista
//~ // contiene un elemento menos, si la lista no estaba vacÃÂ­a.
void *lista_borrar_primero(lista_t *lista){
    if (lista_esta_vacia(lista)) return NULL;
    nodo_t *nodo_a_borrar = lista->lista_inicio;
    void *valor = nodo_a_borrar->valor;
    lista->lista_inicio= (nodo_a_borrar)->ref;
    //chau nodo
    free(nodo_a_borrar);

    lista->largo -=1;
    return valor;
    }

// Inserta un dato en la lista en la posicion que se pasa por parametro.
// Pre: la lista no es vacia.
// Post: se ha insertado el valor pasado por parametro en la posicion
// señalada por el iterador. Los elementos ubicados luego de esa posicion
// avanzan su posicion en uno.
bool lista_insertar(lista_t *lista, lista_iter_t *iter, void *dato){
	/*nodo_t* nodo_nuevo = nodo_crear(dato);*/
    if (iter->anterior == NULL || iter->actual != NULL){
        //Estoy en el primer nodo
        lista_insertar_primero(lista, dato);
        //Actualizo el iterador
        iter->actual = lista->lista_inicio;
        iter->anterior = NULL;
        return true;
        }
    else {
        //estoy al final
        nodo_t* nodo_nuevo = nodo_crear(dato); 
        if (nodo_nuevo == NULL) return false;
        (iter->anterior)->ref = nodo_nuevo;
        nodo_nuevo->ref = iter->actual;
        lista->largo +=1;
        
        //Actualizo el iterador

        iter->actual = nodo_nuevo;
        return true;
        }
        
	}
	
// Elimina el dato en la lista ubicado en la posicion que se pasa por parametro.	
// Pre: la lista no es vacia.
// Post: se elimina de la lista el elemento señalado por el iterador.
void *lista_borrar(lista_t *lista, lista_iter_t *iter){
    nodo_t *nodo_a_borrar = iter->actual;
	void* borrado = (iter->actual)->valor;
	iter->actual = (iter->actual)->ref;
    free(nodo_a_borrar);
	lista->largo -=1;
	return borrado;
	}


/* ******************************************************************
 *                    PRIMITIVAS DEL ITERADOR
 * *****************************************************************/

// Pre: Recibe una lista como parametro y crea un iterador de ella.
// Post: devuelve un iterador de lista posicionado en el primer elemento.
// Si la lista esta vacia devuelve NULL.
lista_iter_t *lista_iter_crear(const lista_t *lista)
{
    if (lista_esta_vacia(lista)) return NULL;
    lista_iter_t* iter = malloc(sizeof(lista_iter_t));
    iter->anterior = NULL;
    iter->actual = lista->lista_inicio;
    return iter;
}

// Avanza una posicion en la lista.
// Pre: el iterador fue creado.
// Post: se avanzo una posicion en la actual del iterador. Si la posicion
// actual era la ultima, se devuelve false.
bool lista_iter_avanzar(lista_iter_t *iter){
	if ((iter->actual)->ref == NULL) return false;
	iter->anterior = iter->actual;
	iter->actual = (iter->actual)->ref;
	return true;
}

// Devuelve un puntero al valor de la posicion donde se encuentra el
// iterador. Si la lista esta vacia, devuelve NULL.
// Pre: el iterador fue creado.
void *lista_iter_ver_actual(const lista_iter_t *iter){
	void* valor = (iter->actual)->valor;
	return valor;
}

// Verifica si se encuentra al final de la lista.
// Pre: el iterador fue creado.
// Post: devuelve true si el iterador se encuentra al final de la lista
// false si no se encuentra al final de la lista.
bool lista_iter_al_final(const lista_iter_t *iter){
	if ((iter->actual)->ref == NULL) return true;
	return false;
}
//~ 
// Destruye el iterador.
// Pre: el iterador fue creado.
// Post: se elimina el iterador.
void lista_iter_destruir(lista_iter_t *iter){
    free(iter);

}
//~ 
