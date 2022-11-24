#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED
#include "sala.h"
#include "personaje.h"
#include "enemigo.h"
#include "estructuras.h"


void combate(nodoEnemigo * enemigo,stPj * personaje);
stPj* colicionEnemigo(stPj * personaje,stSala * room);
bool trueTouch(nodoEnemigo * enemigo,int x,int y);
void UnNodo(nodoEnemigo * nodo);
void mostrarLista(nodoEnemigo * lista);
nodoEnemigo * cargarListaEnemigos();
nodoEnemigo * agregarAlPrint(nodoEnemigo * lista, nodoEnemigo * nuevoNodo);
nodoEnemigo * crearEnemigo(int vida,int danio,int tipo,int defensa,int spawnX, int spawnY);
nodoEnemigo * inicLista();
void accionEnemigo(nodoEnemigo * enemigo,stPj * personaje);
void cartelTurnoEnemigo();
void nombresEnemigos();
void textoInfoEnemigo(int valor);




























#endif // ENEMIGO_H_INCLUDED
