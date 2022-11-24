#ifndef SALA_H_INCLUDED
#define SALA_H_INCLUDED

#include "estructuras.h"
#include "gotoxy.h"
#include "enemigo.h"
#include "objeto.h"
#include "puertas.h"



void cargaMatriz(int **matriz,int filas, int columnas);
stSala * creaSala(int filas,int columnas,int xSpawn,int ySpawn,int posX,int posY);
int ** inicializarSala(int filas, int columnas);
void muestraMatriz(int **matriz,int filas, int columnas,int posX,int posY);
void cargarJuego();


#endif // SALA_H_INCLUDED
