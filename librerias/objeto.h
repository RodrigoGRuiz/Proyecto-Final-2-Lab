#ifndef OBJETO_H_INCLUDED
#define OBJETO_H_INCLUDED

#include "gotoxy.h"
#include "estructuras.h"
#include "sala.h"


nodoObjeto * inicListaObjeto();
nodoObjeto * cargarListaObjetos();
nodoObjeto * agregaraAListaObjetos(nodoObjeto * lista, nodoObjeto * nuevoObjeto);
nodoObjeto * crearObjeto(int tipo,int valor,int cuerpo,char nombre[],int posObjetoX,int posObjetoY);
void muestraListaPuerta(nodoPuerta * lista);
void unObjeto(nodoObjeto * item);
bool tocarObjeto(nodoObjeto * item,int x,int y);





























#endif // OBJETO_H_INCLUDED
