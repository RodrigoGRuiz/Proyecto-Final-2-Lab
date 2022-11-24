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
#include "personaje.h"
#include "enemigo.h"


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




nodoEnemigo * inicLista()
{
    return NULL;
}

nodoEnemigo * cargarListaEnemigos()
{
    nodoEnemigo * lista = inicLista();
    nodoEnemigo * nuevoEnemigo = crearEnemigo(1,4,ESBIRRO,4,6,21);
    nodoEnemigo * nuevoEnemigo1 = crearEnemigo(10,4,ESBIRRO,4,29,8);
    nodoEnemigo * nuevoEnemigo2 = crearEnemigo(10,4,ESBIRRO,4,18,18);
    lista = agregarAlPrint(lista, nuevoEnemigo);
    lista = agregarAlPrint(lista, nuevoEnemigo1);
    lista = agregarAlPrint(lista, nuevoEnemigo2);

    return lista;
}

nodoEnemigo * crearEnemigo(int vida,int danio,int tipo,int defensa,int spawnX, int spawnY)
{
    nodoEnemigo * aux = (nodoEnemigo*)malloc(sizeof(nodoEnemigo));
    aux->atributos.tipo = tipo;
    aux->atributos.vida = vida;
    aux->atributos.danio = danio;
    aux->atributos.defensa = defensa;
    aux->posicion.x = spawnX;
    aux->posicion.y = spawnY;
    aux->habilitado = true;
    aux->cuerpo = 219;
    aux->siguiente = NULL;

    return aux;
}

nodoEnemigo * agregarAlPrint(nodoEnemigo * lista, nodoEnemigo * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    return lista;
}

void UnNodo(nodoEnemigo * nodo)
{
    gotoxy(nodo->posicion.x,nodo->posicion.y);
    printf("%s%c%s",ROJO,nodo->cuerpo,NORMAL);
}

void mostrarLista(nodoEnemigo * lista)
{
    while(lista != NULL)
    {
        if(lista->habilitado == true)
        {
            UnNodo(lista);
        }
        lista = lista->siguiente;
    }
}

stPj * colicionEnemigo(stPj * personaje,stSala * room)
{
    int flag = false;
    nodoEnemigo * enemigo = room->listaEnemigos;
    while(enemigo != NULL)
    {
        flag = trueTouch(enemigo,personaje->posicion.x,personaje->posicion.y);
        if(flag && enemigo->habilitado)
        {
            system("cls");
            combate(enemigo,personaje);

            muestraMatriz(room->matriz,room->filas,room->columnas,0,0);
            mostrarLista(room->listaEnemigos);
            muestraListaObjetos(room->listaDeObjetos);
            interfaz(personaje);
        }
        enemigo = enemigo->siguiente;
    }
    return personaje;
}

bool trueTouch(nodoEnemigo * enemigo,int x,int y)
{
    bool flag = false;
    if(enemigo->posicion.x == x && enemigo->posicion.y == y)
    {
        flag = true;
    }
    return flag;
}

void pintarEnemigo(int x,int y)
{
    printf("%s",ROJO);
    gotoxy(x,y);
    printf("%c%c%c %c",219,178,177,178);
    gotoxy(x,y+1);
    printf("    %c%c%c %c",178,178,177,178);
    gotoxy(x,y+2);
    printf("%c %c%c%c",177,178,219,178);
    gotoxy(x,y+3);
    printf("   %c %c%c%c",219,178,177,219);
    gotoxy(x,y+4);
    printf("%c   %c%c%c  %c",177,177,178,219,178);
    gotoxy(x,y+5);
    printf("%c %c%c%c",219,178,177,178);
    gotoxy(x,y+6);
    printf("%c %c%c",178,177,219);
    gotoxy(x,y+7);
    printf("   %c%c%c%c  %c",177,177,178,219,178);
    printf("%s",NORMAL);
    gotoxy(x,y+8);
    printf("=============");
    gotoxy(x,y+9);
    printf("  =========");
    gotoxy(x,y+10);
    printf("   ======");
}

void accionEnemigo(nodoEnemigo * enemigo,stPj * personaje)
{
    srand(time(NULL));
    int accion = rand()%3;

    cuadradoConMarco(45,3,74,7,MARRON);
    gotoxy(47,4);
    printf("Vida Personaje:");
    mostrarVida(47,5,personaje->atributos.vida,219);

    cuadradoConMarco(45,18,74,22,MARRON);
    gotoxy(47,19);
    printf("Vida Enemigo:");
    mostrarVida(47,20,enemigo->atributos.vida,219);

    if(enemigo->atributos.vida > 1)
    {
        if(accion <=0)
        {
            accion++;
        }
        if(accion == 1)
        {
            personaje->atributos.vida -= enemigo->atributos.danio;
            gotoxy(53,13); printf("ENEMIGO ATACA");
            Sleep(3000);
            gotoxy(53,13); printf("             ");
        }
        if(accion == 2)
        {
            gotoxy(51,13); printf("ENEMIGO DEFIENDE");
            if(enemigo->atributos.vida < 10)
            {
                enemigo->atributos.vida += enemigo->atributos.defensa;
            }
            Sleep(3000);
            gotoxy(51,13); printf("                ");
            cuadradoConMarco(45,18,74,22,MARRON);
            gotoxy(50,19);
            printf("Vida Enemigo:");
            mostrarVida(47,20,enemigo->atributos.vida,219);
        }
    }
}

void combate(nodoEnemigo * enemigo,stPj * personaje)
{
    menuCombate(personaje,enemigo);
    bool batalla = true;

    while(batalla == true)
    {
        cartelTurnoPj();
        accionPersonaje(enemigo,personaje);
        Sleep(500);
        cuadradoAscii(28,3,36,10,219);
        if(enemigo->atributos.vida < 1)
        {
            enemigo->habilitado = false;
        }
        else
        {
            cartelTurnoEnemigo();
            accionEnemigo(enemigo,personaje);
            cuadradoAscii(83,3,91,10,219);
        }

        if(personaje->atributos.vida < 1 || enemigo->atributos.vida < 1)
        {
            batalla = false;
        }
    }
}

void cartelTurnoEnemigo()
{
    cuadradoConMarco(83,3,90,9,MARRON);
    printf("%s",VERDE);
    gotoxy(85,5); printf("%c%c",219,220);
    gotoxy(85,6); printf("%c%c%c",219,219,219);
    gotoxy(85,7); printf("%c%c",219,223);
    printf("%s",NORMAL);
}

void nombresEnemigos()
{
    srand(time(NULL));
    int enemigo = (rand()%(3-1+1))+1;

    if(enemigo == 0)
    {
        enemigo++;
    }
    switch(enemigo)
    {
    case 1:
        gotoxy(86,29);printf("ERROR: BUCLE INFINITO");
        textoInfoEnemigo(enemigo);
        break;
    case 2:
        gotoxy(86,29);printf("ERROR: PARAMETRO INCORRECTO");
        textoInfoEnemigo(enemigo);
        break;
    case 3:
        gotoxy(86,29);printf("ERROR: NOMBRE REDEFINIDO");
        textoInfoEnemigo(enemigo);
        break;
    }
}

void textoInfoEnemigo(int valor)
{
    switch(valor)
    {
    case 1:
        gotoxy(5,29);printf("Se ve que olvidaste pensar ");
        gotoxy(5,30);printf("la condicion de corte");
        gotoxy(5,31);printf("ahora este bucle no esta");
        gotoxy(5,32);printf("dejandote avanzar");
        break;
    case 2:
        gotoxy(5,29);printf("Recorriendo el codigo vimos");
        gotoxy(5,30);printf("que una de las Funciones");
        gotoxy(5,31);printf("esta teniendo problemas con ");
        gotoxy(5,32);printf("un parametro SALVAJE");
        gotoxy(5,33);printf("dice que se llama ROBERTO pero");
        gotoxy(5,34);printf("en realizadad es RICARDO!!!");
        break;
    case 3:
        gotoxy(5,29);printf("En Una fiesta Exclusiva de" );
        gotoxy(5,30);printf("Funciones asistienron dos ");
        gotoxy(5,31);printf("variables que se dicen ser");
        gotoxy(5,32);printf("la misma persona !!!");
        gotoxy(5,34);printf("        -AMOUNGUS-");
        break;
    }
}





























