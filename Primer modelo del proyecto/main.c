#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "gotoxy.h"

#define PURCLARO "\033[1;35m"
#define ROJO "\033[0;31m"
#define CYAN "\033[0;36m"
#define VERDE "\033[0;32m"
#define AZUL "\033[0;34m"
#define MARRON "\033[0;33m"
#define NORMAL "\033[0m"
#define APERTURA "\033[0;36m[\033[0m"
#define CERRADO "\033[0;36m]\033[0m"

#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77
#define SALIR 27

#define FILAS 30
#define COLUMNAS 30

typedef struct
{
    int posX;
    int posY;
    int vida;
} stPj;

typedef struct
{
    int posX;
    int posY;
    int altura;
    int ancho;
}Room;

void mapaBase();
stPj * crearPj(int x, int y);
void dibujarCuadroP(int x1,int y1,int x2,int y2,char color[]);
int dibujarRoom(Room * sala); //<-- Imprime en consola la sala
Room * crearSala(int x, int y, int alto, int ancho); //<-- carga con datos la sala
Room ** inicioMap(); //<-- inicializa sala


int dibujarRoom(Room * sala) //<-- Imprime en consola la sala
{
    printf("%s",MARRON);
    int x;
    int y;
    for(x = sala->posX; x < sala->posX + sala->ancho; x++)
    {
        gotoxy(x,sala->posY);printf("%c",176); //<----- IMPRIME LA PARTE DE ARRIBA
        gotoxy(x,sala->posY + sala->altura);printf("%c",176); //<-- LA PARTE DE ABAJO
    }

    for(y = sala->posY+1;y < sala->posY + sala->altura; y++)
    {
        gotoxy(sala->posX,y);printf("%c",176); //<----- IMPRIME LA PARTE DE ARRIBA
        gotoxy(sala->posX + sala->ancho -1 ,y);printf("%c",176); //<-- LA PARTE DE ABAJO
    }
    printf("%s",NORMAL);
}



Room * crearSala(int x, int y, int alto, int ancho) //<-- carga con datos la sala
{
    Room * nuevaSala = malloc(sizeof(Room));

    nuevaSala->posX = x;
    nuevaSala->posY = y;
    nuevaSala->altura = alto;
    nuevaSala->ancho = ancho;

    return nuevaSala;
}



Room ** inicioMap() //<-- inicializa sala
{
    Room ** salas = malloc(sizeof(Room)*6);


    salas[0] = crearSala(13,13,6,8);
    dibujarRoom(salas[0]);

    salas[1] = crearSala(40,2,6,20);
    dibujarRoom(salas[1]);

    salas[2] = crearSala(40,18,6,20);
    dibujarRoom(salas[2]);


    return salas;

}



int main()
{





    system("cls");

    inicioMap();
    stPj * personaje;
    stPj * guardia;
    guardia = crearPj(17,15);
    personaje = crearPj(14,15);


//    stPj * enemigo1;
//    enemigo1 = crearEnemigo(25,30);
//
//
//    stPj * enemigo2;
//    enemigo2 = crearEnemigo(20, 23);

    int gameOver = 0;

    while(gameOver != 1)
    {
        gameOver = ingresarMovimiento(personaje, &gameOver);
    }







    return 0;
}


stPj * crearPj(int x, int y)
{
    stPj * personaje = (stPj*)malloc(sizeof(stPj));
    personaje->posX = x;
    personaje->posY = y;
    personaje->vida = 20;
    gotoxy(personaje->posX,personaje->posY);
    printf("%c",254);
    return personaje;
}


//stPj * crearEnemigo(int x, int y)
//{
//    stPj * enemigo = (stPj*)malloc(sizeof(stPj));
//    enemigo->posX = x;
//    enemigo->posY = y;
//    enemigo->vida = 20;
//    gotoxy(enemigo->posX,enemigo->posY);
//    printf("%c",254);
//    return enemigo;
//}

int ingresarMovimiento(stPj * personaje, int * gameOver)
{
    while(gameOver != 1)
    {
        if(kbhit())
        {
            int tecla = getch();
            //ARRIBA
            if(tecla == ARRIBA)
            {
                moverPj(personaje->posX,personaje->posY-1,personaje);
            }
            //ABAJO
            if(tecla == ABAJO)
            {
                moverPj(personaje->posX,personaje->posY+1,personaje);
            }
            //IZQ
            if(tecla == IZQUIERDA)
            {
                moverPj(personaje->posX-1,personaje->posY,personaje);
            }
            //DER
            if(tecla == DERECHA)
            {
                moverPj(personaje->posX+1,personaje->posY,personaje);
            }
            if(tecla == SALIR)
            {
                *gameOver = 1;
            }
        }
    }
    return gameOver;
}

int moverPj(int x, int y, stPj * personaje)
{
    hidecursor(1);
    gotoxy(personaje->posX,personaje->posY);
    printf(" ");
    personaje->posX = x;
    personaje->posY = y;
    gotoxy(personaje->posX,personaje->posY);
    printf("%c",254);
    gotoxy(personaje->posX,personaje->posY);
}

void dibujarCuadroP(int x1,int y1,int x2,int y2,char color[])
{
    int i;
    printf("%s",color);
    for (i=x1; i<x2; i++)
    {
        gotoxy(i,y1);
        printf("%c",205); //linea horizontal superior
        gotoxy(i,y2);
        printf("%c",205); //linea horizontal inferior
    }

    for (i=y1; i<y2; i++)
    {
        gotoxy(x1,i);
        printf("%c",186); //linea vertical izquierda
        gotoxy(x2,i);
        printf("%c",186); //linea vertical derecha
    }

    gotoxy(x1,y1);
    printf("%c",201);
    gotoxy(x1,y2);
    printf("%c",200);
    gotoxy(x2,y1);
    printf("%c",187);
    gotoxy(x2,y2);
    printf("%c",188);
    printf("%s",NORMAL);
}


////Primer prueba   --------------------------------------------------------
//
////Creacion de una matriz dinamica
//int crearMatrizDinamica ()
//{
//int **matriz;
//
//matriz = (int **) malloc (FILAS* /*en este caso hace un #define*/ sizeof(int*));
//
//for (i =0; i< FILAS; i++)
//  {
//matriz[i] =(int *) malloc (COLUMNAS* sizeof(int));
//  }
//}
//
////FIN Primer Prueba ------------------------------------------------------
//
//
//
//
////Segunda prueba -----------------------------------------------------------------
//
////Otra manera de crear una matriz dinamica
//
////Variables
//int **matriz;
//int i;
//int j;
//int numFilas;
//int numColumnas;
//
//
//numFilas = 5;
//numColumnas = 5;
//
//
////Memoria dinamica
//matriz = (int **) calloc(numFilas, sizeof(int *));
//
//for (i = 0; i < numFilas; ++i)
//{
// matriz[i] = (int*) calloc(numColumnas, sizeof(int));
//}
//
////Salida por pantalla   /*muestra*/
//
//for(i = 0; i < numFilas; ++i)
//{
//  for(j = 0; j < numColumnas; ++j)
//  {
//   printf("\n");
//  }
//
//}
//
//// Liberacion de la memoria
//
//for(i = 0; i < numFilas; ++i)
//{
// free(matriz[i]);
//
// return 0;
//}
//  FIN segunda Prueba --------------------------------------------------------------






/*
forma diferente de poder inicializar cosas
intMatrix = (int *)malloc(lines * columns * sizeof(int))
*/





















































//{ Matriz cosas

//  void cargarMatriz(int matriz[][3],  int dimX, int dimY){
//    for (int i = 0; i < dimX; i++){
//        for (int j = 0; j < dimY; j++){
//            printf("Ingrese el valor para la posicion (%i, %i).", i ,j);
//            fflush(stdin);
//            scanf("%i", &matriz[i][j]);
//        }
//    }
// }
//
//void mostrarMatriz(int matriz[][2])
//{
//
//    for(int i = 0; i < 9; i++)
//    {
//        for(int j = 0; j < 3; j++)
//        {
//            printf("[%d]", matriz[i][j]);
//        }
//        printf("\n"); /// para acomdarlo en pantalla
//
//    }
//
//
//
// }
//int main()
//{
//
//
//    int dimX = 3;
//    int dimY = 3;
//    int matriz[dimX][dimY];
//    printf("\n ---- EJERCICIO 1 - CARGAR MATRIZ ----\n");
//    cargarMatriz(matriz, dimX, dimY);
//
//   mostrarMatriz(matriz);
//
//}
//}















