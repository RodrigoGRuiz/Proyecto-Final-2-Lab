#ifndef TDALISTASIMPLE_H_INCLUDED
#define TDALISTASIMPLE_H_INCLUDED
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estructuras.h"
#include "personaje.h"

#define CYAN "\033[4;36m"
#define VERDE "\033[4;32m"
#define NORMAL "\033[0m"
#define APERTURA "\033[0;36m[\033[0m"
#define CERRADO "\033[0;36m]\033[0m"


#endif // TDALISTASIMPLE_H_INCLUDED


typedef struct nodo
{
    stPj personaje;
    struct nodo * siguientePj;

}nodo;


nodo * inicNodoSimple();

nodo * crearPersonaje(stPj personaje);

nodo * colocarEnLista(nodo * lista, nodo * nuevo); // ==> AGREGA AL PRINCIPIO DE LA LISTA

nodo * buscarUltimoPersonaje (nodo * lista); // ==> RETORNA EL ULTIMO ELEMENTO

nodo * colocarAlFinalLista(nodo * lista, nodo *nuevo); // ==> AGREGA AL FINAL DE LA LISTA

nodo * borrarPersonajeBuscado (nodo * lista, stPj personaje);

void unPersonaje(nodo * nodoMostrado);

void mostrarListaNodoSimple(nodo * lista);

nodo * menorBuscado(nodo *lista);



