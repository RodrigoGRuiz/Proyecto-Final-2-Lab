#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#include "gotoxy.h"
#include "usuario.h"
#include "menus.h"
#include "estructuras.h"
#include "sala.h"
#include "puertas.h"


#define PURCLARO "\033[1;35m"
#define ROJO "\033[0;31m"
#define CYAN "\033[0;36m"
#define VERDE "\033[0;32m"
#define VERDESUB "\033[4;32m"
#define AZUL "\033[0;34m"
#define MARRON "\033[0;33m"
#define NORMAL "\033[0m"
#define NORMALSUB "\033[4;1;37m"
#define APERTURA "\033[0;36m[\033[0m"
#define CERRADO "\033[0;36m]\033[0m"

#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77

#define ESPACIO 32
#define CANCELAR 8
#define ENTER 13
#define SALIR 27
#define C 99
#define A 97
#define E 101

#define ESBIRRO 1
#define BOOS 2



nodoPuerta * inicListaPuertas()
{
    return NULL;
}

nodoPuerta * crearPuerta(int cantApertura,int posPuertaX,int postPuertaY)
{
    nodoPuerta * nodoAuxiliar = (nodoPuerta*)malloc(sizeof(nodoPuerta));

    nodoAuxiliar->cantLlaves = cantApertura;

    nodoAuxiliar->posPuerta.x = posPuertaX;

    nodoAuxiliar->posPuerta.y = postPuertaY;

    nodoAuxiliar->habilitado = true;

    nodoAuxiliar->siguiente = NULL;

    return nodoAuxiliar;
}

nodoPuerta * agregaraPuertaALista(nodoPuerta * listaPuertas, nodoPuerta * nuevaPuerta)
{
    if(listaPuertas == NULL)
    {
        listaPuertas = nuevaPuerta;
    }
    else
    {
        nuevaPuerta->siguiente = listaPuertas;
        listaPuertas = nuevaPuerta;
    }

    return listaPuertas;
}

nodoPuerta * cargarPuertas()
{
    nodoPuerta * listaPuerta = inicListaPuertas();

    listaPuerta = agregaraPuertaALista(listaPuerta,crearPuerta(1,20,16));
    listaPuerta = agregaraPuertaALista(listaPuerta,crearPuerta(2,11,7));
    listaPuerta = agregaraPuertaALista(listaPuerta,crearPuerta(2,64,21));

    return listaPuerta;
}

nodoPuerta * buscarPuerta(nodoPuerta * listaPuertas,int x, int y)
{
    nodoPuerta * puertaBuscada;
    while(listaPuertas != NULL)
    {
        if(listaPuertas->posPuerta.x == x && listaPuertas->posPuerta.y == y)
        {
            puertaBuscada = listaPuertas;
        }
        listaPuertas = listaPuertas->siguiente;
    }
    return puertaBuscada;
}

void cargarPuertasMapa(stSala * room)
{
    nodoPuerta * puerta = room->listaPuertas;
    while(puerta != NULL)
    {
        room->matriz[puerta->posPuerta.x][puerta->posPuerta.y] = 35;
        puerta = puerta->siguiente;
    }
}
















