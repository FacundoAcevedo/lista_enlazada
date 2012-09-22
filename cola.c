#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "cola.h"

typedef struct nodo nodo_t;

struct nodo
{
    void* valor;
    struct nodo* ref;
};

struct cola
{
    nodo_t* prim;
    nodo_t* ultimo;
    long int tamanio;
};

//FUNCION AUXILIAR: creacion de un nodo
//Recibe un valor. Devuelve el nodo.
 nodo_t* nodo_crear(void* valor){
    nodo_t* nodo = malloc(sizeof(nodo_t));
    if (nodo == NULL) return NULL;
    nodo->valor = valor;
    /*nodo_t* ref = malloc(sizeof(nodo_t));*/
    /*if (ref == NULL) return NULL;*/
    nodo_t* ref = NULL;
    nodo->ref = ref;
    return nodo;
}


cola_t* cola_crear()
{
    cola_t* cola = malloc(sizeof(cola_t));
    if (cola == NULL) return NULL;
    nodo_t* nodo1 = NULL;
    nodo_t* nodo2 = NULL;
    cola->prim = nodo1;
    cola->ultimo= nodo2;
    cola->tamanio =0;
    return cola;
}


// Destruye la cola. Si se recibe la funciÃ³n destruir_dato por parÃ¡metro,
// para cada uno de los elementos de la cola llama a destruir_dato.
// Pre: la cola fue creada. destruir_dato es una funciÃ³n capaz de destruir
// los datos de la cola, o NULL en caso de que no se la utilice.
// Post: se eliminaron todos los elementos de la cola.
void cola_destruir(cola_t *cola, void destruir_dato(void*))
{
	puts("Entre a cola_destruir");
	if (cola->tamanio == 0){
        free(cola);
        return;
    }
	else{
		nodo_t* siguiente = cola->prim;
        nodo_t* dir_nodos[cola->tamanio];
        int i;
        
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
	    	//~ while (siguiente->ref != NULL){
				//~ puts("ENTRE AL WHILE DE DESTRUIR DATO!");
	    		//~ destruir_dato(siguiente->valor);
	    		//~ siguiente = siguiente->ref;
	    //while
        //if

        //Genero una lista con las direcciones de los nodos
        siguiente = cola->prim;
        puts("Genero la lista de direcciones");
        printf("Son %li nodos\n",cola->tamanio);
        for(i = 0; i < (cola->tamanio ); i++){
            dir_nodos[i] = siguiente;
            siguiente = siguiente->ref;
    	}//for
        //mato a los nodos!!!!
        for(i = 0; i < (cola->tamanio ); i++){
            puts("libero los nodos");
            free(dir_nodos[i]);
        }


        free(siguiente);
		free(cola);
	}	
}

// Devuelve verdadero o falso, segÃºn si la cola tiene o no elementos encolados.
// Pre: la cola fue creada.
bool cola_esta_vacia(const cola_t *cola)
{
    if (!cola) return NULL;
    else if(cola->tamanio == 0) return true;
    return false;
}



// Agrega un nuevo elemento a la cola. Devuelve falso en caso de error.
// Pre: la cola fue creada.
// Post: se agregÃ³ un nuevo elemento a la cola, valor se encuentra al final
// de la cola.
bool cola_encolar(cola_t *cola, void* valor)
{
    //Construyo el nuevo nodo que quiero encolar. nuevo_nodo->valor = valor
    // y nuevo_nodo->referencia = NULL porque esta al final de la cola
    nodo_t* nuevo_nodo = nodo_crear(valor);
    /*nuevo_nodo->ref = NULL;*/
    
    //Ubico nuevo_nodo:
    
    //Si la cola está vacía, nuevo_nodo es el primer y el último nodo de la cola
    if (cola->tamanio == 0){
		cola->prim = nuevo_nodo;
		cola->ultimo = nuevo_nodo;
		cola->tamanio += 1;
	}
    //Sino, debo moverme hasta el final de la cola
    else {
		nodo_t* iterador = cola->prim;
        while (true){
				if (iterador->ref == NULL){
					iterador->ref = nuevo_nodo;
					// Incremento el tamanio
					cola->tamanio += 1;
					break;
				}
                iterador= iterador->ref;
        }
    // Se cambia la referencia del ultimo elemento de la cola por la del nuevo_nodo
    cola->ultimo = iterador->ref;
    }
	return true;
}


// Obtiene el valor del primer elemento de la cola. Si la cola tiene
// elementos, se devuelve el valor del primero, si estÃ¡ vacÃ­a devuelve NULL.
// Pre: la cola fue creada.
// Post: se devolviÃ³ el primer elemento de la cola, cuando no estÃ¡ vacÃ­a.
void* cola_ver_primero(const cola_t *cola)
{
    if (cola_esta_vacia(cola)==true) return NULL;
    void* primero = (cola->prim)->valor;
    return primero;
}

// Saca el primer elemento de la cola. Si la cola tiene elementos, se quita el
// primero de la cola, y se devuelve su valor, si estÃ¡ vacÃ­a, devuelve NULL.
// Pre: la cola fue creada.
// Post: se devolviÃ³ el valor del primer elemento anterior, la cola
// contiene un elemento menos, si la cola no estaba vacÃ­a.
void* cola_desencolar(cola_t *cola)
{
    if (cola_esta_vacia(cola) == true) return NULL;
    nodo_t* nodo_aux = NULL;
    
    //Guardo el valor a desencolar
    void* desencolado = (cola->prim)->valor;
    // Cambio la referencia de prim. Ahora vale la referencia al segundo nodo.
    nodo_aux = cola->prim;

    cola->prim = (cola->prim)->ref;
    // Destruyo el nodo desencolado? ¿¿??
    free(nodo_aux);

    // Disminuyo el tamanio
    cola->tamanio -= 1;
    // Devuelvo el valor del desencolado
    return desencolado;
}    
