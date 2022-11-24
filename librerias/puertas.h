#ifndef PUERTAS_H_INCLUDED
#define PUERTAS_H_INCLUDED

#include "gotoxy.h"
#include "estructuras.h"
#include "sala.h"




nodoPuerta * buscarPuerta(nodoPuerta * listaPuertas,int x, int y);
void cargarPuertasMapa(stSala * room);
nodoPuerta * cargarPuertas();
nodoPuerta * inicListaPuertas();
nodoPuerta * crearPuerta(int cantApertura,int posPuertaX,int postPuertaY);
nodoPuerta * agregaraPuertaALista(nodoPuerta * listaPuertas, nodoPuerta * nuevaPuerta);














#endif // PUERTAS_H_INCLUDED
