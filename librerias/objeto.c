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
#include "objeto.h"


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






nodoObjeto * inicListaObjeto()
{
    return NULL;
}

nodoObjeto * crearObjeto(int tipo,int valor,int cuerpo,char nombre[],int posObjetoX,int posObjetoY)
{
    nodoObjeto * nodoAuxiliar = (nodoObjeto*)malloc(sizeof(nodoObjeto));
    nodoAuxiliar->valor = valor;
    nodoAuxiliar->cuerpo = cuerpo;
    nodoAuxiliar->tipo = tipo;
    nodoAuxiliar->habilitado = true;
    nodoAuxiliar->posObjeto.x = posObjetoX;
    nodoAuxiliar->posObjeto.y = posObjetoY;
    strcmpi(nodoAuxiliar->nombre, nombre);

    return nodoAuxiliar;
}

nodoObjeto * agregaraAListaObjetos(nodoObjeto * lista, nodoObjeto * nuevoObjeto)
{
    if(lista == NULL)
    {
        lista = nuevoObjeto;
    }
    else
    {
        nuevoObjeto->siguiente = lista;
        lista = nuevoObjeto;
    }

    return lista;
}

nodoObjeto * cargarListaObjetos()
{
    nodoObjeto * lista = inicListaObjeto();
    lista = agregaraAListaObjetos(lista,crearObjeto(1,5,254,"Pocion",4,4));
    lista = agregaraAListaObjetos(lista,crearObjeto(2,4,254,"Barreta",13,8));
    lista = agregaraAListaObjetos(lista,crearObjeto(3,1,254,"Llave",17,10));
    return lista;
}

void unObjeto(nodoObjeto * item)
{
    if(item->tipo == 1)
    {
        gotoxy(item->posObjeto.x,item->posObjeto.y);
        printf("%s%c%s",VERDE,item->cuerpo,NORMAL);
    }
    if(item->tipo == 2)
    {
        gotoxy(item->posObjeto.x,item->posObjeto.y);
        printf("%s%c%s",PURCLARO,item->cuerpo,NORMAL);
    }
    if(item->tipo == 3)
    {
        gotoxy(item->posObjeto.x,item->posObjeto.y);
        printf("%s%c%s",MARRON,item->cuerpo,NORMAL);
    }
}

void muestraListaObjetos(nodoObjeto * lista)
{
    while ( lista != NULL)
    {
        if(lista->habilitado == true)
        {
            unObjeto(lista);
        }
        lista = lista->siguiente;
    }
}

bool tocarObjeto(nodoObjeto * item,int x,int y)
{
    bool flag = false;
    if(item->posObjeto.x == x && item->posObjeto.y == y)
    {
        flag = true;
    }
    return flag;
}























