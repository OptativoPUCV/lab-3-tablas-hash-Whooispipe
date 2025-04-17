#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"


typedef struct HashMap HashMap;
int enlarge_called=0;

struct HashMap {
    Pair ** buckets;
    long size; //cantidad de datos/pairs en la tabla
    long capacity; //capacidad de la tabla
    long current; //indice del ultimo dato accedido
};

Pair * createPair( char * key,  void * value) {
    Pair * new = (Pair *)malloc(sizeof(Pair));
    new->key = key;
    new->value = value;
    return new;
}

long hash( char * key, long capacity) {
    unsigned long hash = 0;
     char * ptr;
    for (ptr = key; *ptr != '\0'; ptr++) {
        hash += hash*32 + tolower(*ptr);
    }
    return hash%capacity;
}

int is_equal(void* key1, void* key2){
    if(key1==NULL || key2==NULL) return 0;
    if(strcmp((char*)key1,(char*)key2) == 0) return 1;
    return 0;
}

/*
2.- Implemente la función void insertMap(HashMap * map, char * key, void * value). Esta función inserta un 
nuevo dato (key,value) en el mapa y actualiza el índice current a esa posición.
Recuerde que para insertar un par (clave,valor) debe:

a - Aplicar la función hash a la clave para obtener la posición donde debería insertar el nuevo par

b - Si la casilla se encuentra ocupada, avance hasta una casilla disponible (*método de resolución de colisiones*).
 Una casilla disponible es una casilla nula, pero también una que tenga un par inválido (key==NULL).

c - Ingrese el par en la casilla que encontró.

No inserte claves repetidas. 
Recuerde que el arreglo es **circular**.
Recuerde actualizar la variable size.
   
    void insertMap(HashMap * map, char * key, void * value){


    }

*/
long posicionvalida(HashMap*map, char*key)
{
    long i= hash(key, map->capacity);
    long j=0;
    while(map->buckets[i]!=NULL )
    {
        if(is_equal(map->buckets[i]->key,key)){
            return -1;
        }
        i=(i+1)%map->capacity;
        j++;
        if(j==map->capacity)
        {
            return -1;
        }

    }
    return i;   


}

void insertMap(HashMap * map, char * key, void * value) {
    if (map == NULL || key == NULL) return;

    long posicion = posicionvalida(map, key);

    if (posicion == -1) 
    {
        return; 
    } 
    else {
        map->buckets[posicion] = createPair(strdup(key), value); 
        map->size++;
        map->current = posicion;
    }
}

void enlarge(HashMap * map) {
    enlarge_called = 1; //no borrar (testing purposes)


}

/*1.- Implemente la función *createMap* en el archivo hashmap.c. Esta función crea una variable de tipo HashMap, 
inicializa el arreglo de buckets con casillas nulas, inicializa el resto de variables y retorna el mapa. Inicialice el
 índice current a -1.

    HashMap * createMap(long capacity) {


        return NULL;
    }
*/



HashMap * createMap(long capacity) {
    HashMap *map=(HashMap *)malloc(sizeof(HashMap));
    map->buckets= (Pair **)calloc(capacity,sizeof(Pair *));
    map->capacity=capacity;
    map->size=0;
    map->current=-1;
    return map;
}



void eraseMap(HashMap * map,  char * key) {    


}


/*3.- Implemente la función Pair * searchMap(HashMap * map,  char * key), la cual retorna el **Pair** asociado
 a la clave ingresada. 
Recuerde que para buscar el par debe:

a - Usar la función hash para obtener la posición donde puede encontrarse el par con la clave

b - Si la clave no se encuentra avance hasta encontrarla (*método de resolución de colisiones*)

c - Si llega a una casilla nula, retorne NULL inmediatamente (no siga avanzando, la clave no está)

Recuerde actualizar el índice current a la posición encontrada.
Recuerde que el arreglo es **circular**.

    Pair * searchMap(HashMap * map,  char * key) {


        return NULL;
    }
*/


Pair * searchMap(HashMap * map,  char * key) {
    long posicion= hash(key,map->capacity);
    if(is_equal(map->buckets[posicion]->key,key ))
    {
        return map->buckets[posicion];


    }
    else
    {  
        long i = posicionvalida(map, key);
        if(map->buckets[i]==NULL)
        {
            return NULL;
        }


    
    }


    return NULL;
}

Pair * firstMap(HashMap * map) {

    return NULL;
}

Pair * nextMap(HashMap * map) {

    return NULL;
}
