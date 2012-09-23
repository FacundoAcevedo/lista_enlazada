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
	size_t largo;
};


struct lista_iter{
	lista_t* anterior;
	lista_t* actual;
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
//~ 
//~ 
//~ 
//~ 
// Destruye la lista. Si se recibe la funciÃÂ³n destruir_dato por parÃÂ¡metro,
// para cada uno de los elementos de la lista llama a destruir_dato.
// Pre: la lista fue creada. destruir_dato es una funciÃÂ³n capaz de destruir
// los datos de la lista, o NULL en caso de que no se la utilice.
// Post: se eliminaron todos los elementos de la lista.
//~ void lista_destruir(lista_t *lista, void destruir_dato(void *)){
	//~ puts("Entre a lista_destruir");
		//~ nodo_t *siguiente = (*lista)->ref;
        //~ nodo_t *nodo_ref = NULL;
        //~ 
        //~ //Revisar si llega hasta el final!!	
        //~ if (destruir_dato != NULL){ 
			//~ puts("ENTRE AL IF DE DESTRUIR DATO!");
			//~ while (true){
				//~ puts("ENTRE AL WHILE DE DESTRUIR DATO!");
				//~ destruir_dato(siguiente->valor);	
				//~ if (siguiente->ref == NULL) break;
				//~ siguiente = siguiente->ref;
				//~ }
			//~ }
	            //~ //Genero una lista con las direcciones de los nodos
        //~ siguiente = (*lista)->ref;
        //~ nodo_ref = siguiente->ref;
        //~ //Mato todos los nodo
        //~ while (nodo_ref->ref){
            //~ free(siguiente);
            //~ siguiente = nodo_ref->ref;
            //~ free(nodo_ref);
            //~ nodo_ref = siguiente->ref;
        //~ }//while
        //~ //finalmente mato a la lista
        //~ free(lista);
//~ }


// Devuelve dato de tipo size_t expresando la cantidad de elementos que contiene
// la lista. Si la lista no contiene elementos, devuelve 0.
// Pre: la lista fue creada.
size_t lista_largo(const lista_t *lista){
	//~ size_t largo;
    //~ nodo_t *nodo_aux;
	//~ largo = 0;
    //~ if (lista_esta_vacia(lista)) return largo;
    //~ nodo_aux = (*lista)->ref;
	//~ while((*lista)->ref){ 
		//~ largo += 1;
        //~ nodo_aux = nodo_aux->ref; 
        //Esto esta para el ojete
		/*((*lista)->ref) = ((*lista)->ref)->ref;*/
		//~ }
	return lista->largo;
	}


// Devuelve verdadero o falso, segÃÂºn si la lista tiene o no elementos.
// Pre: la lista fue creada.
bool lista_esta_vacia(const lista_t *lista){
	printf("largo: %zu.\n", lista->largo);
	if (lista->largo == 0) return true;
 
	return false;
	//~ printf("Valor de lista en lista_esta_vacia: lista %p\n", &lista);
	//~ if (&lista == NULL) return true;
	//~ return false;
}

//~ // Agrega un nuevo elemento a la lista en la primera posicion. Devuelve 
//~ // falso en caso de error.
//~ // Pre: la lista fue creada.
//~ // Post: se agrego un nuevo elemento a la lista, valor se encuentra al principio
//~ // de la lista.

 bool lista_insertar_primero(lista_t *lista, void *dato){
	nodo_t* nuevo_nodo = nodo_crear(dato);
	//~ printf("%p DIR del nodo_nuevo que quiero insertar\n", nuevo_nodo);
	nuevo_nodo->ref = lista;
	printf("largo antes de insertar: %zu\n", lista->largo);
	lista->largo= lista->largo + 1;
	printf("largo luego de insertar: %zu\n", lista->largo);	
	lista = nuevo_nodo;
		//~ if (!lista_esta_vacia(lista)){
		//~ nodo_t* segundo;
		/*segundo = (*lista)->valor;*/
		/*(*lista) = nodo_nuevo;*/
		/*(*lista)->ref = segundo;*/
        //~ segundo = (*lista)->ref;
        //~ (*lista)->ref = nodo_nuevo;
        //~ nodo_nuevo->ref = segundo;
		//~ return true;
		//~ }
	//~ (*lista)->ref = nodo_nuevo;

	//~ printf("----Lo que vale lista cuando hago lista = nodo_nuevo: lista %p\n", lista);

	return true; //que error puede haber?
}
	

//~ // Agrega un nuevo elemento a la lista en la ultima posicion. Devuelve 
//~ // falso en caso de error.
//~ // Pre: la lista fue creada.
//~ // Post: se agrego un nuevo elemento a la lista, valor se encuentra al final
//~ // de la lista.
//~ bool lista_insertar_ultimo(lista_t *lista, void *dato){
    //~ nodo_t* nodo_nuevo = nodo_crear(dato);
	//~ if (lista_esta_vacia(lista)){
		//~ (*lista)->ref = nodo_nuevo;
		//~ return true;
		//~ }
	//~ /*while((*lista)->ref){ */
		//~ /*((*lista)->ref) = ((*lista)->ref)->ref;*/
	   //~ /* }*/
    //~ nodo_t *nodo_aux = (*lista)->ref; 
    //~ while(nodo_aux->ref){
        //~ nodo_aux = nodo_aux->ref;
    //~ }
    //~ nodo_aux->ref = nodo_nuevo;
    //~ lista->largo +=1;
	//~ return true;
	//~ }


// Obtiene el valor del primer elemento de la lista. Si la lista tiene
// elementos, se devuelve el valor del primero, si estÃÂ¡ vacÃÂ­a devuelve NULL.
// Pre: la lista fue creada.
// Post: se devolviÃÂ³ el primer elemento de la lista, cuando no estÃÂ¡ vacÃÂ­a.
void *lista_ver_primero(const lista_t *lista){
	if (lista_esta_vacia(lista) == true) return NULL;
	printf("lista %p\n", lista);
	return lista;
	}
	

//~ 
//~ // Saca el primer elemento de la lista. Si la lista tiene elementos, se quita el
//~ // primero de la lista, y se devuelve su valor, si estÃÂ¡ vacÃÂ­a, devuelve NULL.
//~ // Pre: la lista fue creada.
//~ // Post: se devolviÃÂ³ el valor del primer elemento anterior, la lista
//~ // contiene un elemento menos, si la lista no estaba vacÃÂ­a.
//~ void *lista_borrar_primero(lista_t *lista){
    //~ if (lista_esta_vacia(lista)) return NULL;
    //~ nodo_t* nodo_aux = NULL;
    //~ 
    //~ //Guardo el valor a borrar
    //~ void* borrado = (*lista)->valor;
    //~ // Cambio la referencia de prim. Ahora vale la referencia al segundo nodo.
    //~ nodo_aux = (*lista)->ref;
//~ 
    //~ (*lista)->ref  = ((*lista)->ref)->ref;
    //~ // Destruyo el nodo borrado
    //~ free(nodo_aux);
	//~ 
	//~ lista->largo -=1;
    //~ // Devuelvo el valor del borrado
    //~ return borrado;
//~ }    
//~ 
//~ // Inserta un dato en la lista en la posicion que se pasa por parametro.
//~ // Pre: la lista no es vacia.
//~ // Post: se ha insertado el valor pasado por parametro en la posicion
//~ // señalada por el iterador. Los elementos ubicados luego de esa posicion
//~ // avanzan su posicion en uno.
//~ bool lista_insertar(lista_t *lista, lista_iter_t *iter, void *dato){
	//~ nodo_t* nodo_nuevo = nodo_crear(dato);
    //~ (iter->anterior)->ref = nodo_nuevo;
	//~ nodo_nuevo->ref = iter->actual;
	//~ lista->largo +=1;
	//~ return true;
	//~ }
	//~ 
//~ // Eimina el dato en la lista ubicado en la posicion que se pasa por parametro.	
//~ // Pre: la lista no es vacia.
//~ // Post: se elimina de la lista el elemento señalado por el iterador.
//~ void *lista_borrar(lista_t *lista, lista_iter_t *iter){
	//~ void* borrado = iter->actual;
	//~ iter->anterior = iter->actual;
	//~ lista->largo -=1;
	//~ return borrado;
	//~ }
//~ 
//~ 
//~ /* ******************************************************************
 //~ *                    PRIMITIVAS DEL ITERADOR
 //~ * *****************************************************************/
//~ 
//~ // Pre: Recibe una lista como parametro y crea un iterador de ella.
//~ // Post: devuelve un iterador de lista posicionado en el primer elemento.
//~ // Si la lista esta vacia devuelve NULL.
//~ lista_iter_t *lista_iter_crear(const lista_t *lista)
//~ {
    //~ if (lista_esta_vacia(lista)) return NULL;
    //~ lista_iter_t* iter = NULL;
    //~ iter->anterior = NULL;
    //~ iter->actual = *lista;
    //~ return iter;
//~ }
//~ 
//~ // Avanza una posicion en la lista.
//~ // Pre: el iterador fue creado.
//~ // Post: se avanzo una posicion en la actual del iterador. Si la posicion
//~ // actual era la ultima, se devuelve false.
//~ bool lista_iter_avanzar(lista_iter_t *iter){
	//~ if ((iter->actual)->ref == NULL) return false;
	//~ iter->anterior = iter->actual;
	//~ iter->actual = (iter->actual)->ref;
	//~ return true;
//~ }
//~ 
//~ // Devuelve un puntero al valor de la posicion donde se encuentra el
//~ // iterador. Si la lista esta vacia, devuelve NULL.
//~ // Pre: el iterador fue creado.
//~ void *lista_iter_ver_actual(const lista_iter_t *iter){
	//~ void* valor = (iter->actual)->valor;
	//~ return valor;
//~ }
//~ 
//~ // Verifica si se encuentra al final de la lista.
//~ // Pre: el iterador fue creado.
//~ // Post: devuelve true si el iterador se encuentra al final de la lista
//~ // false si no se encuentra al final de la lista.
//~ bool lista_iter_al_final(const lista_iter_t *iter){
	//~ if (iter->actual->ref == NULL) return true;
	//~ return false;
//~ }

//~ // Destruye el iterador.
//~ // Pre: el iterador fue creado.
//~ // Post: se elimina el iterador.
//~ void lista_iter_destruir(lista_iter_t *iter);
//~ 

