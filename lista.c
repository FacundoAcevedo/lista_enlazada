#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

typedef struct nodo{
    void* valor;
    struct nodo* ref;
}nodo_t;

struct lista{
	nodo_t* inicio;
    nodo_t* fin;
	size_t largo;
};


struct lista_iter{
	nodo_t* anterior;
	nodo_t* actual;
};




/* ******************************************************************
 *                    PRIMITIVAS BASICAS DE LA LISTA
 * *****************************************************************/

//FUNCION AUXILIAR: creacion de un nodo
//Recibe un valor. Devuelve el nodo.
 nodo_t* nodo_crear(void* valor){
    nodo_t* nodo = malloc(sizeof(nodo_t));
    if (nodo == NULL) return NULL;
    nodo->valor = valor;
    /*nodo_t* ref = NULL;*/
    /*nodo->ref = ref;*/
    nodo->ref = NULL;
    return nodo;
}


// Crea una lista.
// Post: devuelve una nueva lista vacia.
lista_t* lista_crear(){
	lista_t* lista;
	lista = malloc(sizeof(lista_t));
	if (lista == NULL) return NULL;
	lista->inicio = NULL;
	lista->fin = NULL;
	lista->largo = 0;	
	return lista;

}
 
 
// Destruye la lista. Si se recibe la funciÃÂ³n destruir_dato por parÃÂ¡metro,
// para cada uno de los elementos de la lista llama a destruir_dato.
// Pre: la lista fue creada. destruir_dato es una funciÃÂ³n capaz de destruir
// los datos de la lista, o NULL en caso de que no se la utilice.
// Post: se eliminaron todos los elementos de la lista.
<<<<<<< HEAD
 void lista_destruir(lista_t *lista, void destruir_dato(void *)){
	puts("entre a un destruir");
	if (lista==NULL) return;
	void* borrado;
	int largo;
	largo = (int) lista_largo(lista);
	printf (" largo %d \n", largo);
=======
void lista_destruir(lista_t *lista, void destruir_dato(void *)){
	if (lista==NULL) return;
	void* borrado;
>>>>>>> c997e3c87d76616e55b95981a781add5e4021576
	while (!lista_esta_vacia(lista)){
		borrado = lista_borrar_primero(lista);
		printf("direccion de elemento a borrar %p\n", borrado);
		if (destruir_dato!= NULL){
			destruir_dato(borrado);	
			}
		}
    free(lista);
    puts("termine un destruir");
 }


// Devuelve dato de tipo size_t expresando la cantidad de elementos que contiene
// la lista. Si la lista no contiene elementos, devuelve 0.
// Pre: la lista fue creada.
size_t lista_largo(const lista_t *lista){
	return lista->largo;
	}


// Devuelve verdadero o falso, segÃÂºn si la lista tiene o no elementos.
// Pre: la lista fue creada.
bool lista_esta_vacia(const lista_t *lista){
	if (lista->largo == 0) return true;
	return false;
}

// Agrega un nuevo elemento a la lista en la primera posicion. Devuelve 
// falso en caso de error.
// Pre: la lista fue creada.
// Post: se agrego un nuevo elemento a la lista, valor se encuentra al principio
// de la lista.

bool lista_insertar_primero(lista_t *lista, void *dato){
	
	nodo_t* nuevo_nodo = nodo_crear(dato);
    if (nuevo_nodo == NULL) return false;
    if (lista_esta_vacia(lista)){
        lista->inicio = nuevo_nodo;
		lista->fin = nuevo_nodo;
		}
    else{
	    nuevo_nodo->ref = lista->inicio;
        lista->inicio = nuevo_nodo;
		}
	lista->largo += 1;
	return true; 
}
	

// Agrega un nuevo elemento a la lista en la ultima posicion. Devuelve 
// falso en caso de error.
// Pre: la lista fue creada.
// Post: se agrego un nuevo elemento a la lista, valor se encuentra al final
// de la lista.
bool lista_insertar_ultimo(lista_t *lista, void *dato){
	nodo_t* nuevo_nodo = nodo_crear(dato);
    if (nuevo_nodo == NULL) return false;
    else if (lista->largo == 0){
        lista->inicio = nuevo_nodo;
        lista->fin = nuevo_nodo;
		}
    else{
        (lista->fin)->ref = nuevo_nodo;
        lista->fin= nuevo_nodo;
		}
	lista->largo += 1;
	return true; 
 }


// Obtiene el valor del primer elemento de la lista. Si la lista tiene
// elementos, se devuelve el valor del primero, si estÃÂ¡ vacÃÂ­a devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolviÃÂ³ el primer elemento de la lista, cuando no estÃÂ¡ vacÃÂ­a.
void *lista_ver_primero(const lista_t *lista){
	if (lista_esta_vacia(lista)) return NULL;
	return (lista->inicio)->valor;
	}

<<<<<<< HEAD

=======
>>>>>>> c997e3c87d76616e55b95981a781add5e4021576
// Saca el primer elemento de la lista. Si la lista tiene elementos, se quita el
// primero de la lista, y se devuelve su valor, si estÃÂ¡ vacÃÂ­a, devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolviÃÂ³ el valor del primer elemento anterior, la lista
// contiene un elemento menos, si la lista no estaba vacÃÂ­a.
void *lista_borrar_primero(lista_t *lista){
    if (lista_esta_vacia(lista)) return NULL;

    nodo_t *nodo_a_borrar = lista->inicio;
    void *valor = nodo_a_borrar->valor;
    lista->inicio= (nodo_a_borrar)->ref;
    
<<<<<<< HEAD
    free(lista->inicio);
=======
    free(nodo_a_borrar);
>>>>>>> c997e3c87d76616e55b95981a781add5e4021576
    lista->largo -=1;
    if (lista->largo == 0) lista->fin = NULL;
    return valor;
    }

// Inserta un dato en la lista en la posicion que se pasa por parametro.
// Pre: la lista no es vacia.
// Post: se ha insertado el valor pasado por parametro en la posicion
// señalada por el iterador. Los elementos ubicados luego de esa posicion
// avanzan su posicion en uno.
bool lista_insertar(lista_t *lista, lista_iter_t *iter, void *dato){
	if (iter->anterior == NULL && iter->actual != NULL){ // o sea si iter = posicion inicial
        //Estoy en el primer nodo
        lista_insertar_primero(lista, dato);
        //Actualizo el iterador
        iter->actual = lista->inicio;
        iter->anterior = NULL;
        lista->largo +=1;
        return true;
        }
        //if
    nodo_t* nodo_nuevo = nodo_crear(dato); 
    if (nodo_nuevo == NULL) return false;
    (iter->anterior)->ref = nodo_nuevo;
    nodo_nuevo->ref = iter->actual;
    lista->largo +=1;
    //Actualizo el iterador
    iter->actual = nodo_nuevo;
    return true;
    }
        
	
// Elimina el dato en la lista ubicado en la posicion que se pasa por parametro.	
// Pre: la lista no es vacia.
// Post: se elimina de la lista el elemento señalado por el iterador.
void *lista_borrar(lista_t *lista, lista_iter_t *iter){
    nodo_t *nodo_a_borrar = iter->actual;
    
    /*Si estoy en el primer lugar */

    if (lista_esta_vacia(lista)) return NULL;
    else if ( !(iter->anterior) && iter->actual)
    {
        void* borrado = nodo_a_borrar->valor;
        lista_borrar_primero(lista);
        free(nodo_a_borrar);
        return borrado;
    }
    /*si estoy al final*/
    else if (lista_iter_al_final(iter))
    {
        void* borrado = nodo_a_borrar->valor;
        /*actualizo la lista*/
        lista->fin = iter->anterior;
        free(nodo_a_borrar);
        return borrado;
    }
    /*si estoy en caulquier otro lugar*/
    void* borrado = nodo_a_borrar->valor;
    (iter->anterior)->ref = nodo_a_borrar->ref; 
    free(nodo_a_borrar);
    return borrado;
    /*if (lista_iter_al_final(iter)){*/
		/*if (iter->anterior == NULL){ // hay un solo elemento*/
			/*void* borrado;*/
			/*borrado = lista_borrar_primero(lista);*/
			/*return borrado;*/
			/*}*/
		/*lista->fin = iter->anterior;*/
		/*iter->anterior->ref = NULL;*/
	/*}*/
    /*else if ((!iter->anterior) &&  iter->actual){//Estoy al principio*/
			/*void* borrado;*/
			/*borrado = lista_borrar_primero(lista);*/
            /*[>free(nodo_a_borrar);<]*/
			/*return borrado;*/
			/*}*/

	/*void* borrado = (iter->actual)->valor;*/
	/*iter->actual = (iter->actual)->ref;*/
    /*free(nodo_a_borrar);*/
	/*lista->largo -=1;*/
	/*return borrado;*/
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
    iter->actual = lista->inicio;
    return iter;
}

// Avanza una posicion en la lista.
// Pre: el iterador fue creado.
// Post: se avanzo una posicion en la actual del iterador. Si la posicion
// actual era la ultima, se devuelve false.
bool lista_iter_avanzar(lista_iter_t *iter){
	if (lista_iter_al_final(iter)) return false;
	if (iter->actual == NULL) return false;
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
	if ((iter->actual)->ref== NULL) return true;
	return false;
}
//~ 
// Destruye el iterador.
// Pre: el iterador fue creado.
// Post: se elimina el iterador.
void lista_iter_destruir(lista_iter_t *iter){
    free(iter);

} 
