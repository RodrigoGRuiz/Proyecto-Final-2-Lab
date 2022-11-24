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
#include "enemigo.h"
#include "objeto.h"
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



void interfaz(stPj * personaje)
{
    dibujarCuadroAscii(1,1,117,24,219);
    dibujarCuadro(0,0,118,25,CYAN); // cuadrado principal
    dibujarCuadro(0,0,118,39,CYAN);//cuadrado panel
    cuadradoAscii(1,26,118,39,219);//cuadrado estado nombre personaje
    cuadradoAscii(2,27,36,38,32); //controles cuadrado blanco
    cuadradoAscii(38,28,67,37,32); //estadisticas cuadrado blanco
    dibujarCuadro(37,27,67,37,CYAN); // estadisticas cuadrado
    gotoxy(3,27);
    printf("             ______ ");
    gotoxy(3,28);
    printf("            | | W  |");
    gotoxy(3,29);
    printf("            | | ^  |");
    gotoxy(3,30);
    printf("            | |_|__|");
    gotoxy(3,31);
    printf("            |/_____/");
    gotoxy(3,32);
    printf(" ______      ______      ______");
    gotoxy(3,33);
    printf("| | A  |    | | S  |    | | D  |");
    gotoxy(3,34);
    printf("| | <- |    | | |  |    | | -> |");
    gotoxy(3,35);
    printf("| |____|    | |_v__|    | |____|");
    gotoxy(3,36);
    printf("|/_____/    |/_____/    |/_____/");

    gotoxy(40,28);
    printf("%sPersonaje:%s",VERDESUB,NORMAL);
    gotoxy(40,29);
    printf("%s->%s%s",VERDE,NORMAL,personaje->nick); //nombre personaje
    gotoxy(40,30);
    printf("%sVida:%s",VERDESUB,NORMAL);
    mostrarVida(40,31,personaje->atributos.vida,254); //vida personaje
    gotoxy(40,33);
    printf("%sDanio%s",VERDESUB,NORMAL);
    gotoxy(40,34);
    printf("%s%d%s",APERTURA,personaje->atributos.danio,CERRADO);
    gotoxy(40,35);
    printf("%sLlaves:%s",VERDESUB,NORMAL);
    gotoxy(40,36);
    printf("%s%d%s",APERTURA,personaje->llaves,CERRADO);
    gotoxy(personaje->posicion.x,personaje->posicion.y);
    printf("%s%c%s",CYAN,219,NORMAL);
    gotoxy(personaje->posicion.x,personaje->posicion.y);

}



stPj * crearPj(int xSpawn,int ySpawn, char nick[])
{
    stPj * personaje = (stPj*)malloc(sizeof(stPj));
    strcpy(personaje->nick,nick);

    personaje->atributos.vida = 20;
    personaje->atributos.danio = 5;
    personaje->atributos.defensa = 4;
    personaje->llaves = 0;

    personaje->posicion.x = xSpawn;
    personaje->posicion.y = ySpawn;

    gotoxy(xSpawn,ySpawn);
    printf("%s%c%s",CYAN,219,NORMAL);
    gotoxy(xSpawn,ySpawn);



    return personaje;
}

//COMPRUEBA LA COLICION DEL PERSONAJE EN LA MATRIZ
void comprueboPosicion(stSala * room,stPj * personaje,int x,int y)
{
    bool flag;

    if(room->matriz[x][y] != 219)
    {
        if(room->matriz[x][y] == 35)
        {
            nodoPuerta * puerta = buscarPuerta(room->listaPuertas,x,y);
            if(puerta->habilitado  == true && personaje->llaves == puerta->cantLlaves)
            {
                personaje->posicion.x = x;
                personaje->posicion.y = y;
                room->matriz[puerta->posPuerta.x][puerta->posPuerta.y] = 250;
                puerta->habilitado = false;
            }
            else if(puerta->habilitado  == true && personaje->llaves != puerta->cantLlaves)
            {
                personaje->posicion.x = personaje->posicion.x;
                personaje->posicion.y = personaje->posicion.y;
            }
            else
            {
                personaje->posicion.x = x;
                personaje->posicion.y = y;
            }
        }
        else
        {

            personaje->posicion.x = x;
            personaje->posicion.y = y;
        }
    }
}

void mostrarVida(int x, int y,int fin, int ascii)
{
    int contador =0;
    int valor = x + fin;
    for(int i = x ; i <= valor; i++ )
    {
        if(contador <= 20)
        {
            gotoxy (i,y);
            printf("%s%c%s",ROJO,ascii,NORMAL);
            gotoxy (x,y+1);
            printf("|0");
            gotoxy (valor-1,y+1);
            printf(">|%d",fin);
        }
        contador++;
    }
}

int movimientoPersonaje(bool estado,stSala * room, stPj * personaje)
{
    muestraMatriz(room->matriz,room->filas,room->columnas,0,0);
    mostrarLista(room->listaEnemigos);
    muestraListaObjetos(room->listaDeObjetos);
    interfaz(personaje);
    while(!estado)
    {
        if(kbhit())
        {
            int nuevaX;
            int nuevaY;

            char tecla = getch();
            gotoxy(personaje->posicion.x,personaje->posicion.y);
            printf("%s%c%s",VERDE,250,NORMAL);
            if(tecla == 'w')
            {
                nuevaX = personaje->posicion.x;
                nuevaY = personaje->posicion.y-1;
                comprueboPosicion(room,personaje,nuevaX,nuevaY);
            }
            if(tecla == 's')
            {
                nuevaX = personaje->posicion.x;
                nuevaY = personaje->posicion.y+1;
                comprueboPosicion(room,personaje,nuevaX,nuevaY);
            }
            if(tecla == 'a')
            {
                nuevaX = personaje->posicion.x-1;
                nuevaY = personaje->posicion.y;
                comprueboPosicion(room,personaje,nuevaX,nuevaY);
            }
            if(tecla == 'd')
            {
                nuevaX = personaje->posicion.x+1;
                nuevaY = personaje->posicion.y;
                comprueboPosicion(room,personaje,nuevaX,nuevaY);
            }
            //METODO RECORRER LA LISTA DE ENEMIGOS (QUE RICIBE POR PARAMETRO LA POSICION X Y DEL PJ y LISTA ENEMIGOS)
            personaje = colicionEnemigo(personaje,room);
            personaje = agarraObjeto(personaje,room);


            gotoxy(personaje->posicion.x,personaje->posicion.y);
            printf("%s%c%s",CYAN,219,NORMAL);
            gotoxy(personaje->posicion.x,personaje->posicion.y);
            if(personaje->atributos.vida < 1)
            {
                estado = true;
                system("cls");
                printf("Perdiste");
            }
        }
    }
    return estado;
}

void pintarPersonajeParado(int x,int y)
{
    gotoxy(x,y);
    printf("     %c%c",219,219);

    gotoxy(x,y+2);
    printf("   %c%c%c%c%c%c",220,223,219,219,223,220);
    gotoxy(x,y+3);
    printf("   %c %c%c %c",219,219,219,219);
    gotoxy(x,y+4);
    printf("   %c %c%c %c",220,219,219,220);
    gotoxy(x,y+5);
    printf("    %c  %c",219,219);
    gotoxy(x,y+6);
    printf("    %c  %c",219,219);
    gotoxy(x,y+7);
    printf("   %c%c  %c%c",220,219,219,220);
    gotoxy(x,y+8);
    printf("=============");
    gotoxy(x,y+9);
    printf("  =========");
    gotoxy(x,y+10);
    printf("   ======");
}

void pintarPersonajeDefensa(int x,int y)
{
    gotoxy(x,y-3);
    printf("  %s%c     %c%s",VERDE,38,38,NORMAL);
    gotoxy(x,y-2);
    printf("  %s%c%c    %c%c%s",VERDE,38,38,38,38,NORMAL);
    gotoxy(x,y-1);
    printf("  %s%c%s%c%s%c%s  %s%c%s%c%s%c%s",VERDE,38,NORMAL,223,VERDE,38,NORMAL,VERDE,38,NORMAL,223,VERDE,38,NORMAL);
    gotoxy(x,y);
    printf("   %c %c%c %c",219,219,219,219);
    gotoxy(x,y+1);
    printf("   %c    %c",219,219);
    gotoxy(x,y+2);
    printf("    %c%c%c%c",223,219,219,223);
    gotoxy(x,y+3);
    printf("     %c%c",219,219);
    gotoxy(x,y+4);
    printf("     %c%c",219,219);
    gotoxy(x,y+5);
    printf("    %c  %c",219,219);
    gotoxy(x,y+6);
    printf("    %c  %c",219,219);
    gotoxy(x,y+7);
    printf("   %c%c  %c%c",220,219,219,220);
    gotoxy(x,y+8);
    printf("=============");
    gotoxy(x,y+9);
    printf("  =========");
    gotoxy(x,y+10);
    printf("   ======");
}

void pintarPersonajeAtaca(int x,int y)
{
    gotoxy(x,y-3);
    printf("        %s%c%s",ROJO,38,NORMAL);
    gotoxy(x,y-2);
    printf("       %s%c%c%s",ROJO,38,38,NORMAL);
    gotoxy(x,y-1);
    printf("       %s%c%s%c%s%c%s",ROJO,38,NORMAL,223,ROJO,38,NORMAL);
    gotoxy(x,y);
    printf("     %c%c %c",219,219,219);
    gotoxy(x,y+1);
    printf("        %c",219);
    gotoxy(x,y+2);
    printf("   %c%c%c%c%c",220,223,219,219,223);
    gotoxy(x,y+3);
    printf("   %c %c%c",219,219,219);
    gotoxy(x,y+4);
    printf("   %c %c%c",220,219,219);
    gotoxy(x,y+5);
    printf("    %c  %c",219,219);
    gotoxy(x,y+6);
    printf("    %c  %c",219,219);
    gotoxy(x,y+7);
    printf("   %c%c  %c%c",220,219,219,220);
    gotoxy(x,y+8);
    printf("=============");
    gotoxy(x,y+9);
    printf("  =========");
    gotoxy(x,y+10);
    printf("   ======");
}

stPj * agarraObjeto(stPj * personaje,stSala * room)
{
    int flag = false;
    nodoObjeto * item = room->listaDeObjetos;
    while(item != NULL)
    {
        flag = tocarObjeto(item,personaje->posicion.x,personaje->posicion.y);

        if(flag && item->habilitado)
        {
            if(item->tipo == 1 && personaje->atributos.vida < 20)
            {
                personaje->atributos.vida += item->valor;
                while(personaje->atributos.vida > 20)
                {
                    personaje->atributos.vida--;
                }
            }
            if(item->tipo == 2)
            {
                personaje->atributos.danio += item->valor;
            }
            if(item->tipo == 3)
            {
                personaje->llaves += item->valor;
            }
            item->habilitado = false;

            muestraListaObjetos(room->listaDeObjetos);
            interfaz(personaje);

        }
        item = item->siguiente;
    }
    return personaje;
}

void accionPersonaje(nodoEnemigo * enemigo,stPj * personaje)
{
    int vidaPj = personaje->atributos.vida;
    int tecla;
    bool turno = true;

    cuadradoConMarco(45,3,74,7,MARRON);
    gotoxy(47,4);
    printf("Vida Personaje:");
    mostrarVida(47,5,vidaPj,219);

    cuadradoConMarco(45,18,74,22,MARRON);
    gotoxy(47,19);
    printf("Vida Enemigo:");
    mostrarVida(47,20,enemigo->atributos.vida,219);

    while(turno == true)
    {
        if(kbhit())
        {
            tecla = getch();
            if(tecla == 'j')
            {
                cuadradoConMarco(3,3,26,22,MARRON); // cuadrado personaje
                pintarPersonajeAtaca(9,10);
                Sleep(500);

                enemigo->atributos.vida -= personaje->atributos.danio;

                 cuadradoConMarco(3,3,26,22,MARRON); // cuadrado personaje
                pintarPersonajeParado(9,10);
                Sleep(500);

                turno = false;
            }
            if(tecla == 'k')
            {
                cuadradoConMarco(3,3,26,22,MARRON); // cuadrado personaje
                pintarPersonajeDefensa(9,10);
                Sleep(500);

                if(vidaPj <20)
                {
                    vidaPj += personaje->atributos.defensa;
                }

                cuadradoConMarco(3,3,26,22,MARRON); // cuadrado personaje
                pintarPersonajeParado(9,10);
                Sleep(500);

                turno = false;
            }
            if(tecla == 'l')
            {
                cuadradoConMarco(3,3,26,22,MARRON); // cuadrado personaje
                pintarPersonajeParado(9,10);
                Sleep(500);
                turno = false;
            }

                cuadradoConMarco(45,3,74,7,MARRON);
                gotoxy(47,4);
                printf("Vida Personaje:");
                mostrarVida(47,5,vidaPj,219);

                cuadradoConMarco(45,18,74,22,MARRON);
                gotoxy(47,19);
                printf("Vida Enemigo:");
                mostrarVida(47,20,enemigo->atributos.vida,219);
        }
    }
    personaje->atributos.vida = vidaPj;
}

void cartelTurnoPj()
{
    cuadradoConMarco(28,3,35,9,MARRON);
    printf("%s",VERDE);
    gotoxy(32,5); printf("%c%c",220,219);
    gotoxy(31,6); printf("%c%c%c",219,219,219);
    gotoxy(32,7); printf("%c%c",223,219);
    printf("%s",NORMAL);
}
















