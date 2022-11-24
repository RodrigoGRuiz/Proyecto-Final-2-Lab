#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#include "usuario.h"
#include "botonesAnimaciones.h"
#include "gotoxy.h"
#include "TDAarboles.h"
#include "TDAlistaSimple.h"
#include "estructuras.h"
#include "sala.h"
#include "puertas.h"
#include "enemigo.h"
#include "personaje.h"

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



//FUNCION CARGA UNA MATRIZ CON ELEMENTOS;
void cargaMatriz(int **matriz,int filas, int columnas)
{
    cuadrado(matriz,0,0,118,23,219);
    cuadrado(matriz,3,3,7,4,250);
    cuadrado(matriz,10,3,12,4,250);
    cuadrado(matriz,4,7,9,9,250);
    cuadrado(matriz,5,13,7,14,250);
    cuadrado(matriz,4,16,7,18,250);
    cuadrado(matriz,3,20,8,22,250);
    cuadrado(matriz,12,7,13,8,250);
    cuadrado(matriz,11,13,15,15,250);
    cuadrado(matriz,10,18,12,20,250);
    cuadrado(matriz,16,4,19,6,250);
    cuadrado(matriz,15,9,20,11,250);
    cuadrado(matriz,16,18,19,20,250);
    cuadrado(matriz,16,18,19,20,250);
    cuadrado(matriz,23,3,27,4,250);
    cuadrado(matriz,23,6,27,8,250);
    cuadrado(matriz,25,11,30,12,250);
    cuadrado(matriz,22,14,26,16,250);
    cuadrado(matriz,22,20,24,22,250);
    cuadrado(matriz,25,20,26,21,250);
    cuadrado(matriz,33,4,36,5,250);
    cuadrado(matriz,32,8,36,9,250);
    cuadrado(matriz,34,11,38,12,250);
    cuadrado(matriz,34,15,38,17,250);
    cuadrado(matriz,29,18,32,19,250);
    cuadrado(matriz,35,20,36,21,250);
    cuadrado(matriz,44,3,47,5,250);
    cuadrado(matriz,39,6,42,8,250);
    cuadrado(matriz,42,13,44,15,250);
    cuadrado(matriz,44,17,49,18,250);
    cuadrado(matriz,40,21,44,22,250);
    cuadrado(matriz,52,5,55,7,250);
    cuadrado(matriz,48,10,53,11,250);
    cuadrado(matriz,50,14,54,15,250);
    cuadrado(matriz,54,19,56,20,250);
    cuadrado(matriz,59,3,62,4,250);
    cuadrado(matriz,59,8,62,9,250);
    cuadrado(matriz,56,16,59,17,250);
    cuadrado(matriz,56,11,57,12,250);
    cuadrado(matriz,60,12,62,14,250);
    cuadrado(matriz,66,5,69,6,250);
    cuadrado(matriz,65,10,66,11,250);
    cuadrado(matriz,68,13,71,14,250);
    cuadrado(matriz,63,17,67,18,250);
    cuadrado(matriz,65,20,68,21,250);
    cuadrado(matriz,74,3,79,4,250);
    cuadrado(matriz,74,6,77,7,250);
    cuadrado(matriz,70,9,74,10,250);
    cuadrado(matriz,74,13,77,14,250);
    cuadrado(matriz,72,17,76,18,250);
    cuadrado(matriz,71,20,75,22,250);
    cuadrado(matriz,82,5,86,6,250);
    cuadrado(matriz,80,9,83,11,250);
    cuadrado(matriz,80,15,83,16,250);
    cuadrado(matriz,78,18,81,20,250);
    cuadrado(matriz,89,3,94,4,250);
    cuadrado(matriz,88,8,90,10,250);
    cuadrado(matriz,86,12,90,14,250);
    cuadrado(matriz,86,17,89,19,250);
    cuadrado(matriz,85,21,89,22,250);
    cuadrado(matriz,94,6,96,7,250);
    cuadrado(matriz,93,9,99,10,250);
    cuadrado(matriz,95,12,98,13,250);
    cuadrado(matriz,93,15,94,16,250);
    cuadrado(matriz,97,16,99,17,250);
    cuadrado(matriz,93,19,96,21,250);
    cuadrado(matriz,100,3,103,4,250);
    cuadrado(matriz,104,10,106,11,250);
    cuadrado(matriz,102,14,106,15,250);
    cuadrado(matriz,103,17,106,18,250);
    cuadrado(matriz,100,20,103,22,250);
    cuadrado(matriz,107,4,115,8,250);
    cuadrado(matriz,110,10,115,11,250);
    cuadrado(matriz,109,13,112,14,250);
    cuadrado(matriz,110,16,114,17,250);
    cuadrado(matriz,107,20,110,22,250);
    cuadrado(matriz,113,19,115,20,250);
    // CAMINO 1
    matriz[9][22] = 250;
    matriz[10][22] = 250;
    matriz[11][22] = 250;
    matriz[12][22] = 250;
    matriz[12][21] = 250;
    // CAMINO 2
    matriz[13][18] = 250;
    matriz[14][18] = 250;
    matriz[14][19] = 250;
    matriz[14][20] = 250;
    matriz[14][21] = 250;
    matriz[14][22] = 250;
    matriz[15][22] = 250;
    matriz[16][22] = 250;
    matriz[16][21] = 250;
    cuadrado(matriz,21,11,24,11,250);
    // CAMINO 3
    matriz[18][19] = 250;
    matriz[18][17] = 250;
    matriz[18][16] = 250;
    matriz[18][15] = 250;
    matriz[18][15] = 250;
    matriz[19][16] = 250;
    matriz[20][16] = 250;
    matriz[21][16] = 250;
    matriz[17][15] = 250;
    matriz[16][15] = 250;
    // CAMINO 4
    cuadrado(matriz,9,13,9,17,250);
    matriz[10][13] = 250;
    matriz[8][17] = 250;
    // CAMINO 5
    matriz[5][15] = 250;
    // CAMINO 6
    cuadrado(matriz,6,10,6,12,250);
    // CAMINO 7
    matriz[8][6] = 250;
    matriz[8][5] = 250;
    matriz[7][5] = 250;
    matriz[9][5] = 250;
    matriz[10][5] = 250;
    // CAMINO 8
    matriz[10][7] = 250;
    matriz[11][7] = 250;
    // CAMINO 9
    cuadrado(matriz,13,3,16,3,250);
    cuadrado(matriz,19,3,22,3,250);
    // CAMINO 10
    matriz[27][5] = 250;
    cuadrado(matriz,28,8,31,8,250);
    cuadrado(matriz,35,5,35,7,250);
    //CAMINO 11
    cuadrado(matriz,36,4,43,4,250);
    cuadrado(matriz,47,6,47,7,250);
    cuadrado(matriz,43,7,47,7,250);
    cuadrado(matriz,39,9,39,11,250);
    matriz[31][11] = 250;
    matriz[32][11] = 250;
    matriz[33][11] = 250;
    //CAMINO 12
    matriz[26][17] = 250;
    matriz[26][18] = 250;
    matriz[22][18] = 250;
    matriz[22][19] = 250;
    cuadrado(matriz,22,18,26,18,250);
    cuadrado(matriz,27,21,29,21,250);
    matriz[29][20] = 250;
    //CAMINO 13
    matriz[33][16] = 250;
    matriz[32][16] = 250;
    matriz[32][17] = 250;
    matriz[35][18] = 250;
    matriz[35][19] = 250;
    //CAMINO 14
    cuadrado(matriz,40,13,40,19,250);
    cuadrado(matriz,38,19,38,21,250);
    matriz[37][21] = 250;
    matriz[39][19] = 250;
    matriz[41][13] = 250;
    matriz[41][13] = 250;
    matriz[44][16] = 250;
    matriz[44][19] = 250;
    matriz[44][20] = 250;
    //CAMINO 15
    cuadrado(matriz,49,22,58,22,250);
    cuadrado(matriz,49,18,49,21,250);
    cuadrado(matriz,58,21,64,21,250);
    matriz[56][18] = 250;
    matriz[54][16] = 250;
    matriz[55][16] = 250;
    matriz[50][12] = 250;
    matriz[50][13] = 250;
    matriz[53][8] = 250;
    matriz[53][9] = 250;
    matriz[55][4] = 250;
    cuadrado(matriz,55,3,73,3,250);
    //CAMINO 16
    matriz[68][18] = 250;
    matriz[68][19] = 250;
    cuadrado(matriz,65,12,65,15,250);
    matriz[68][19] = 250;
    matriz[63][15] = 250;
    matriz[63][16] = 250;
    matriz[64][15] = 250;
    matriz[56][10] = 250;
    //CAMINO 17
    matriz[67][11] = 250;
    matriz[68][11] = 250;
    matriz[68][12] = 250;
    matriz[71][11] = 250;
    matriz[71][12] = 250;
    matriz[74][11] = 250;
    matriz[74][12] = 250;
    //CAMINO 18
    cuadrado(matriz,75,9,77,9,250);
    matriz[77][8] = 250;
    cuadrado(matriz,71,7,73,7,250);
    matriz[70][5] = 250;
    matriz[71][5] = 250;
    matriz[71][6] = 250;
    cuadrado(matriz,62,6,65,6,250);
    matriz[62][7] = 250;
    cuadrado(matriz,56,9,58,9,250);
    matriz[57][13] = 250;
    matriz[54][21] = 250;
    cuadrado(matriz,57,14,59,14,250);
    //CAMINO 19
    matriz[76][15] = 250;
    cuadrado(matriz,76,16,79,16,250);
    matriz[77][12] = 250;
    cuadrado(matriz,77,11,79,11,250);
    matriz[83][7] = 250;
    matriz[83][8] = 250;
    cuadrado(matriz,86,4,88,4,250);
    matriz[81][17] = 250;
    matriz[81][16] = 250;
    matriz[76][20] = 250;
    matriz[77][20] = 250;
    cuadrado(matriz,76,22,84,22,250);
    //CAMINO 20
    matriz[89][20] = 250;
    matriz[86][15] = 250;
    matriz[86][16] = 250;
    matriz[90][11] = 250;
    matriz[88][7] = 250;
    cuadrado(matriz,88,6,93,6,250);
    //CAMINO 21
    matriz[97][6] = 250;
    matriz[99][3] = 250;
    cuadrado(matriz,98,3,98,6,250);
    cuadrado(matriz,103,5,103,10,250);
    matriz[106][12] = 250;
    matriz[106][13] = 250;
    matriz[102][16] = 250;
    matriz[102][17] = 250;
    //CAMINO 22
    matriz[106][19] = 250;
    matriz[106][20] = 250;
    matriz[104][20] = 250;
    matriz[105][20] = 250;
    cuadrado(matriz,96,22,103,22,250);
    matriz[99][18] = 250;
    cuadrado(matriz,96,19,99,19,250);
    matriz[95][16] = 250;
    matriz[96][16] = 250;
    matriz[93][14] = 250;
    matriz[93][13] = 250;
    matriz[94][13] = 250;
    matriz[99][11] = 250;
    matriz[99][12] = 250;
    //FINAL
    cuadrado(matriz,110,22,115,22,250);
    matriz[115][21] = 250;
    matriz[113][18] = 250;
    matriz[109][15] = 250;
    matriz[109][16] = 250;
    matriz[115][12] = 250;
    cuadrado(matriz,112,13,115,13,250);
    matriz[115][12] = 250;
    matriz[111][9] = 250;

}

//MUESTRA UNA MATRIZ EN UNA POSICION DESIGNADA
void muestraMatriz(int **matriz,int filas, int columnas,int posX,int posY)
{
    for(int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            if(matriz[i][j] == 219)
            {
                gotoxy(posX+i,posY+j);
                printf("%s%c%s",MARRON, matriz[i][j],NORMAL);
            }
            if(matriz[i][j] == 250)
            {
                gotoxy(posX+i,posY+j);
                printf("%s%c%s",VERDE, matriz[i][j],NORMAL);
            }
            if(matriz[i][j] == 35)
            {
                gotoxy(posX+i,posY+j);
                printf("%c",matriz[i][j]);
            }
        }
        printf("\n");
    }

}

//CREA UN SALA
stSala * creaSala(int filas,int columnas,int xSpawn,int ySpawn,int posX,int posY)
{
    stSala * sala = (stSala*)malloc(sizeof(stSala));
    sala->matriz = inicializarSala(filas,columnas);
    sala->filas = filas;
    sala->columnas = columnas;
    sala->spawn.x = xSpawn;
    sala->spawn.y = ySpawn;
    sala->posicion.x = posX;
    sala->posicion.y = posY;
    sala->listaEnemigos = cargarListaEnemigos();
    sala->listaDeObjetos = cargarListaObjetos();
    sala->listaPuertas = cargarPuertas();

    return sala;
}


//FUNCION INICIALIZA UNA MATRIZ DINAMICA;
int ** inicializarSala(int filas, int columnas)
{
    int ** matriz;
    matriz = (int**)calloc(filas, sizeof(int*));
    for(int i = 0; i < filas; i++)
    {
        matriz[i] = (int*)calloc(columnas,sizeof(int));
    }
    return matriz;
}


void cargarJuego()
{

    stSala * room1;

    stPj * heroe;

    room1 = creaSala(119,25,4,21,0,0);

    cargaMatriz(room1->matriz,room1->filas,room1->columnas);
    cargarPuertasMapa(room1);

    heroe = crearPj(room1->spawn.x,room1->spawn.y,"Super Rodrigo");

    bool gameOver = false;

    movimientoPersonaje(gameOver,room1,heroe);
}

























