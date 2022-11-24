#ifndef PERSONAJE_H_INCLUDED
#define PERSONAJE_H_INCLUDED
#include "estructuras.h"
#include "gotoxy.h"



void comprueboPosicion(stSala * room,stPj * personaje,int x,int y);
void mostrarVida(int x, int y,int fin, int ascii);
stPj * crearPj(int xSpawn,int ySpawn, char nick[]);
int movimientoPersonaje(bool estado,stSala * sala1, stPj * heroe);
void pintarPersonajeParado(int x,int y);
void pintarPersonajeAtaca(int x,int y);
void pintarPersonajeDefensa(int x,int y);
void accionPersonaje(nodoEnemigo * enemigo,stPj * personaje);
void interfaz(stPj * personaje);
stPj * agarraObjeto(stPj * personaje,stSala * room);
void cartelTurnoPj();
















#endif // PERSONAJE_H_INCLUDED
