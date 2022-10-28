#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gotoxy.h"

#define PURCLARO "\033[1;35m"
#define ROJO "\033[0;31m"
#define CYAN "\033[0;36m"
#define VERDE "\033[0;32m"
#define VERDESUB "\033[4;32m"
#define AZUL "\033[0;34m"
#define MARRON "\033[0;33m"
#define NORMAL "\033[0m"
#define APERTURA "\033[0;36m[\033[0m"
#define CERRADO "\033[0;36m]\033[0m"

#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77

#define CANCELAR 8
#define ENTER 13
#define SALIR 27
#define C 99
#define A 97

#define ESBIRRO 1
#define BOOS 2



typedef struct
{
    int x;
    int y;
} stPosicion;

typedef struct
{
    int tipo;
    int danio;
    int defensa;
    int vida;
} stCaracteristica;

typedef struct
{
    stCaracteristica atributos;
    stPosicion posicion;
    char nick[30];
    int llaves;

} stPj;


typedef struct
{
    stPosicion posObjeto;
    int valor;
    int tipo;
    int cuerpo;
    bool habilitado;
    char nombre[20];
    struct nodoObjeto * siguiente;

} nodoObjeto;



typedef struct
{
    stCaracteristica atributos;
    stPosicion posicion;
    int cuerpo;
    bool habilitado;
    struct stEnemigo * siguiente;

} nodoEnemigo;

typedef struct
{
    int cantLlaves;
    bool habilitado;
    int cuerpo;
    stPosicion posPuerta;
    struct nodoPuerta * siguiente;

} nodoPuerta;



typedef struct
{
    int filas;
    int columnas;

    int ** matriz;

    stPosicion spawn;
    stPosicion posicion;

    nodoEnemigo * listaEnemigos;

    nodoObjeto * listaDeObjetos;

    nodoPuerta * listaPuertas;

} stSala;

void botonAceptar(int x, int y);
void botonSalir(int x, int y);
void botonCreditos(int x, int y);
void botonAceptarApretado(int x, int y);
void botonSalirApretado(int x, int y);
void botonCreditosApretado(int x, int y);
void botonAdmin(int x, int y);
void botonAdminApretado(int x, int y);
void nombreJuego(int x,int y);



nodoPuerta * buscarPuerta(nodoPuerta * listaPuertas,int x, int y);
void cargarPuertasMapa(stSala * room);
nodoPuerta * cargarPuertas();
nodoPuerta * inicListaPuertas();
nodoPuerta * crearPuerta(int cantApertura,int posPuertaX,int postPuertaY);
nodoPuerta * agregaraPuertaALista(nodoPuerta * listaPuertas, nodoPuerta * nuevaPuerta);


stPj * agarraObjeto(stPj * personaje,stSala * room);
nodoObjeto * inicListaObjeto();
nodoObjeto * cargarListaObjetos();
nodoObjeto * agregaraAListaObjetos(nodoObjeto * lista, nodoObjeto * nuevoObjeto);
nodoObjeto * crearObjeto(int tipo,int valor,int cuerpo,char nombre[],int posObjetoX,int posObjetoY);
void muestraListaPuerta(nodoPuerta * lista);
void unObjeto(nodoObjeto * item);
bool tocarObjeto(nodoObjeto * item,int x,int y);


stPj* colicionEnemigo(stPj * personaje,stSala * room);
bool trueTouch(nodoEnemigo * enemigo,int x,int y);
void UnNodo(nodoEnemigo * nodo);
void mostrarLista(nodoEnemigo * lista);
nodoEnemigo * cargarListaEnemigos();
nodoEnemigo * agregarAlPrint(nodoEnemigo * lista, nodoEnemigo * nuevoNodo);
nodoEnemigo * crearEnemigo(int vida,int danio,int tipo,int defensa,int spawnX, int spawnY);
nodoEnemigo * inicLista();
void accionEnemigo(nodoEnemigo * enemigo,stPj * personaje);

void comprueboPosicion(stSala * room,stPj * personaje,int x,int y);
void mostrarVida(int x, int y,int fin, int ascii);
stPj * crearPj(int xSpawn,int ySpawn, char nick[]);
int movimientoPersonaje(bool estado,stSala * sala1, stPj * heroe);
void pintarPersonajeParado(int x,int y);
void pintarPersonajeAtaca(int x,int y);
void pintarPersonajeDefensa(int x,int y);
void combate(nodoEnemigo * enemigo,stPj * personaje);
void accionPersonaje(nodoEnemigo * enemigo,stPj * personaje);



void cuadrado(int **matriz, int x1, int y1, int x2, int y2,int ascii);
stSala * creaSala(int filas,int columnas,int xSpawn,int ySpawn,int posX,int posY);
void cargaMatriz(int **matriz,int filas, int columnas);
int ** inicializarSala(int filas, int columnas);
void interfaz(stPj * personaje);
void menuCombate();
void cargarJuego();

void muestraMatriz(int **matriz,int filas, int columnas,int posX,int posY);
void fondoEBlanco(int x1,int y1,int x2, int y2);
void cuadradoAscii(int x1, int y1,int x2,int y2,int ascii);


void menuInicioSesion();
void inicioMenu();
void dibujarFondo();
void nombreJuego(int x,int y);

void menuIngresar();

int main()
{
    system("cls");

    system("mode con: cols=120 lines=40");

//    menuIngresar();
//    menuInicioSesion();
    inicioMenu();
//    menuCombate();
//    cargarJuego();











    return 0;
}


//{ FUNCIONES GAME

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

void menuCombate()
{
    system("cls");
    dibujarCuadro(0,0,118,25,CYAN); // cuadrado principal
    dibujarCuadro(0,0,118,39,CYAN);//cuadrado panel
    dibujarCuadro(4,4,29,22,CYAN); // cuadrado Exterior
    cuadradoAscii(2,2,117,24,219);//cuadrado batalla
    dibujarCuadro(2,27,40,37,CYAN);//cuadrado teclas menu
    cuadradoAscii(3,26,39,22,32); // cuadrado blanco teclas

    cuadradoAscii(4,4,29,23,32); // cuadrado blanco personaje
    dibujarCuadro(3,3,29,22,CYAN); // marco jugador
    cuadradoAscii(1,26,118,39,219); //cuadrado estado nombre personaje

    cuadradoAscii(91,4,114,23,32); // cuadrado blaco enemigo
    dibujarCuadro(90,3,113,22,CYAN); // marco enemigo

    pintarEnemigo(97,10);
    pintarPersonajeParado(10,10);

    gotoxy(4,28);
    printf(" ______      ______      ______");
    gotoxy(4,29);
    printf("| | J  |    | | K  |    | | L  |");
    gotoxy(4,30);
    printf("| |    |    | |    |    | |    |");
    gotoxy(4,31);
    printf("| |____|    | |____|    | |____|");
    gotoxy(4,32);
    printf("|/_____/    |/_____/    |/_____/");
    gotoxy(4,33);
    printf("%sAtaca%s    %sDefensa%s     %sEspera%s",APERTURA,CERRADO,APERTURA,CERRADO,APERTURA,CERRADO);
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

void cuadradoAscii(int x1, int y1,int x2,int y2,int ascii)
{
    for (int i = x1; i < x2 ; i++ )
    {
        for (int j = y1; j < y2 ; j++ )
        {
            gotoxy(i,j);
            printf("%c",ascii);
        }
    }
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




//}




//{ FUNCIONES PERSONAJE
//CREA UN PERSONAJE
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


//}

//{ FUNCIONES SALA ----------------------------

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

//DIBUJA UN CUADRADO EN LA MATRIZ DE CUALQUIER TIPO
void cuadrado(int **matriz, int x1, int y1, int x2, int y2,int ascii)
{
    for(int i = x1; i <= x2; i++)
    {
        for(int j = y1; j <= y2; j++)
        {
            matriz[i][j] = ascii;
        }
    }
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




//}

//{  FUNCIONES ENEMIGO ------------------------
nodoEnemigo * inicLista()
{
    return NULL;
}

nodoEnemigo * cargarListaEnemigos()
{
    nodoEnemigo * lista = inicLista();
//    nodoEnemigo * nuevoEnemigo = crearEnemigo(1,4,ESBIRRO,4,6,21);
    nodoEnemigo * nuevoEnemigo1 = crearEnemigo(10,4,ESBIRRO,4,29,8);
    nodoEnemigo * nuevoEnemigo2 = crearEnemigo(10,4,ESBIRRO,4,18,18);
//    lista = agregarAlPrint(lista, nuevoEnemigo);
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


//}

//{ FUNCIONES DE OBJETOS


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
            system("cls");
            muestraMatriz(room->matriz,room->filas,room->columnas,0,0);
            mostrarLista(room->listaEnemigos);
            muestraListaObjetos(room->listaDeObjetos);
            interfaz(personaje);

        }
        item = item->siguiente;
    }
    return personaje;
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


//}


//{ FUNCIONES PUERTAS

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


//}




void accionEnemigo(nodoEnemigo * enemigo,stPj * personaje)
{
    srand(time(NULL));
    int accion = rand()%3;

    mostrarVida(50,5,personaje->atributos.vida,219);
    gotoxy(50,19);
    printf("Vida Enemigo:");

    mostrarVida(50,20,enemigo->atributos.vida,219);
    if(enemigo->atributos.vida > 1)
    {
        if(accion <=0)
        {
            accion++;
        }
        if(accion == 1)
        {
            Sleep(500);
            personaje->atributos.vida -= enemigo->atributos.danio;
            gotoxy(50,15);
            printf("ENEMIGO ATACA");
            Sleep(2000);
            menuCombate();
            mostrarVida(50,5,personaje->atributos.vida,219);
        }
        if(accion == 2)
        {
            gotoxy(50,15);
            printf("ENEMIGO DEFIENDE");
            if(enemigo->atributos.vida < 10)
            {
                enemigo->atributos.vida += enemigo->atributos.defensa;
            }
            Sleep(2000);
            menuCombate();
            mostrarVida(50,5,enemigo->atributos.vida,219);
        }
    }
}

void accionPersonaje(nodoEnemigo * enemigo,stPj * personaje)
{
    int vidaPj = personaje->atributos.vida;
    int tecla;
    bool turno = true;
    gotoxy(50,4);
    printf("Vida Personaje:");
    mostrarVida(50,5,vidaPj,219);
    gotoxy(50,19);
    printf("Vida Enemigo:");
    mostrarVida(50,20,enemigo->atributos.vida,219);
    while(turno == true)
    {
        if(kbhit())
        {
            tecla = getch();
            if(tecla == 'j')
            {
                cuadradoAscii(5,5,29,22,32); // cuadrado blanco personaje
                pintarPersonajeAtaca(10,10);
                Sleep(500);

                enemigo->atributos.vida -= personaje->atributos.danio;

                cuadradoAscii(5,5,29,22,32); // cuadrado blanco personaje
                pintarPersonajeParado(10,10);
                Sleep(500);

                turno = false;
            }
            if(tecla == 'k')
            {
                cuadradoAscii(5,5,29,22,32); // cuadrado blanco personaje
                pintarPersonajeDefensa(10,10);
                Sleep(500);

                if(vidaPj <20)
                {
                    vidaPj += personaje->atributos.defensa;
                }

                cuadradoAscii(5,5,29,22,32); // cuadrado blanco personaje
                pintarPersonajeParado(10,10);
                Sleep(500);

                turno = false;
            }
            if(tecla == 'l')
            {
                cuadradoAscii(5,5,29,22,32); // cuadrado blanco personaje
                pintarPersonajeParado(10,10);
                Sleep(500);
                turno = false;
            }

            menuCombate();
            gotoxy(50,19);
            printf("Vida Enemigo:");
            mostrarVida(50,20,enemigo->atributos.vida,219);
            mostrarVida(50,5,vidaPj,219);
        }
    }
    personaje->atributos.vida = vidaPj;
}

void combate(nodoEnemigo * enemigo,stPj * personaje)
{
    menuCombate();
    bool batalla = true;

    while(batalla == true)
    {
        accionPersonaje(enemigo,personaje);
        Sleep(500);
        accionEnemigo(enemigo,personaje);
        if(enemigo->atributos.vida < 1)
        {
            enemigo->habilitado = false;
        }
        if(personaje->atributos.vida < 1 || enemigo->atributos.vida < 1)
        {
            batalla = false;
        }
    }
}






//{ FUNCION MENU PRINCIPAL
void inicioMenu()
{
    int condCorte = 0;
    while(condCorte == 0)
    {
        system("cls");
        gotoxy(4,10);
        printf("printf(%cHello World!%c);",34,34);
        gotoxy(50,5);
        printf("printf(%cGoodbye World!%c);",34,34);
        gotoxy(70,8);
        printf("desapilar(&Wold);");
        gotoxy(4,30);
        printf("Sleep(forever);",34,34);
        gotoxy(20,3);
        printf("while(jugadorVivo != dead);");
        gotoxy(10,25);
        printf("free(nodoJugador);");
        gotoxy(90,25);
        printf("if(siApruebo)");
        gotoxy(90,26);
        printf("     bailar;");
        gotoxy(90,27);
        printf("else");
        gotoxy(90,28);
        printf("     llorar;");

        gotoxy(28,16);
        printf("%s%c%c%s%c%c%s",ROJO,219,219,VERDE,219,219,NORMAL);
        gotoxy(28,17);
        printf("%s%c%c%s%c%c%s",MARRON,219,219,AZUL,219,219,NORMAL);

        gotoxy(87,16);
        printf("%s%c%c%s%c%c%s",ROJO,219,219,VERDE,219,219,NORMAL);
        gotoxy(87,17);
        printf("%s%c%c%s%c%c%s",MARRON,219,219,AZUL,219,219,NORMAL);

        dibujarCuadro(0,0,119,39,CYAN);
        nombreJuego(33,10);
        botonAdmin(103,34);
        botonAceptar(45,33);
        botonSalir(2,1);
        botonCreditos(2,33);
        int tecla;
        while(tecla != SALIR)
        {

            if(kbhit())
            {
                tecla = getch();

                if(tecla == ENTER)
                {
                    aniBotonAceptar(45,33);
                    menuInicioSesion();
                }
                if(tecla == C)
                {
                    aniBotonCreditos(2,33);
                }
                if(tecla == A)
                {
                    aniBotonAdmin(103,34);
                }
                if(tecla == SALIR)
                {
                    aniBotonSalir(2,1);
                    condCorte = 1;
                }
            }
        }
    }
}

void nombreJuego(int x,int y)
{
    gotoxy(x,y);
    printf(" ______   ______   ______   ______   ______   ______ ");
    gotoxy(x,y+1);
    printf("| | B  | | | A  | | | T  | | | T  | | | L  | | | E  |");
    gotoxy(x,y+2);
    printf("| |    | | |    | | |    | | |    | | |    | | |    |");
    gotoxy(x,y+3);
    printf("| |____| | |____| | |____| | |____| | |____| | |____|");
    gotoxy(x,y+4);
    printf("|/_____/ |/_____/ |/_____/ |/_____/ |/_____/ |/_____/");
    gotoxy(x+9,y+6);
    printf(" ______   ______   ______   ______ ");
    gotoxy(x+9,y+7);
    printf("| | C  | | | O  | | | D  | | | E  |");
    gotoxy(x+9,y+8);
    printf("| |    | | |    | | |    | | |    |");
    gotoxy(x+9,y+9);
    printf("| |____| | |____| | |____| | |____|");
    gotoxy(x+9,y+10);
    printf("|/_____/ |/_____/ |/_____/ |/_____/");
}

void botonAceptar(int x, int y)
{
    gotoxy(x,y);
    printf(" __________________________");
    gotoxy(x,y+1);
    printf("| |          ENTER         |");
    gotoxy(x,y+2);
    printf("| |                        |");
    gotoxy(x,y+3);
    printf("| |________________________|");
    gotoxy(x,y+4);
    printf("|/________________________/");
}

void botonSalir(int x, int y)
{
    gotoxy(x,y);
    printf(" ________");
    gotoxy(x,y+1);
    printf("| |  ESC |");
    gotoxy(x,y+2);
    printf("| |      |");
    gotoxy(x,y+3);
    printf("| |______|");
    gotoxy(x,y+4);
    printf("|/______/");
}

void botonCreditos(int x, int y)
{
    gotoxy(x,y);
    printf(" ________");
    gotoxy(x,y+1);
    printf("| |  C   |");
    gotoxy(x,y+2);
    printf("| |      |");
    gotoxy(x,y+3);
    printf("| |______|");
    gotoxy(x,y+4);
    printf("|/______/");
}

void botonAceptarApretado(int x, int y)
{
    gotoxy(x,y);
    printf(" __________________________");
    gotoxy(x,y+1);
    printf("||          ENTER         |");
    gotoxy(x,y+2);
    printf("||                        |");
    gotoxy(x,y+3);
    printf("||________________________|");
    gotoxy(x,y+4);
    printf("|/________________________/");
}

void botonSalirApretado(int x, int y)
{
    gotoxy(x,y);
    printf(" ________");
    gotoxy(x,y+1);
    printf("||  ESC |");
    gotoxy(x,y+2);
    printf("||      |");
    gotoxy(x,y+3);
    printf("||______|");
    gotoxy(x,y+4);
    printf("|/______/");
}

void botonCreditosApretado(int x, int y)
{
    gotoxy(x,y);
    printf(" ________");
    gotoxy(x,y+1);
    printf("||  C   |");
    gotoxy(x,y+2);
    printf("||      |");
    gotoxy(x,y+3);
    printf("||______|");
    gotoxy(x,y+4);
    printf("|/______/");
}

void botonAdmin(int x, int y)
{
    gotoxy(x,y);
    printf(" ______________");
    gotoxy(x,y+1);
    printf("| | A : Admin |");
    gotoxy(x,y+2);
    printf("| |___________|");
    gotoxy(x,y+3);
    printf("|/___________/");
}

void botonAdminApretado(int x, int y)
{
    gotoxy(x,y);
    printf(" ______________");
    gotoxy(x,y+1);
    printf("|| A : Admin |");
    gotoxy(x,y+2);
    printf("||___________|");
    gotoxy(x,y+3);
    printf("|/___________/");
}

//}


//{

void menuInicioSesion()
{
        system("cls");

        gotoxy(28,16);
        printf("%s%c%c%s%c%c%s",ROJO,219,219,VERDE,219,219,NORMAL);
        gotoxy(28,17);
        printf("%s%c%c%s%c%c%s",MARRON,219,219,AZUL,219,219,NORMAL);
        gotoxy(87,16);
        printf("%s%c%c%s%c%c%s",ROJO,219,219,VERDE,219,219,NORMAL);
        gotoxy(87,17);
        printf("%s%c%c%s%c%c%s",MARRON,219,219,AZUL,219,219,NORMAL);

        dibujarCuadro(0,0,119,39,CYAN);
        nombreJuego(33,10);
        botonIngresar(35,30);
        botonRegistrarse(68,30);
        botonSalir(2,1);
        gotoxy(30,24);
        printf("printf(%cSi tienes una Cuenta Ingresar sino Registrate...%c);",34,34);
        selector(28,31);
        int posicion = 1;

        int tecla;
        while(tecla != SALIR)
        {
            if(kbhit())
            {
                tecla = getch();

                if(tecla == DERECHA)
                {
                    cuadradoAscii(28,31,34,33,32);
                    selector(60,31);
                    posicion  = 2;
                }
                if(tecla == IZQUIERDA)
                {
                    cuadradoAscii(60,31,66,33,32);
                    selector(28,31);
                    posicion = 1;
                }
                if(tecla == ENTER && posicion == 1)
                {
                    aniBotonIngresar(35,30);
                    menuIngresar();
                }
                if(tecla == ENTER && posicion == 2)
                {
                    aniBotonRegistrarse(68,30);
                }
                if(tecla == SALIR)
                {
                    aniBotonSalir(2,1);
                    inicioMenu();
                }
            }
        }
    }

void botonIngresar(int x, int y)
{
    gotoxy(x,y);
    printf(" ______________");
    gotoxy(x,y+1);
    printf("| |  Ingresar  |");
    gotoxy(x,y+2);
    printf("| |____________|");
    gotoxy(x,y+3);
    printf("|/____________/");
}

void botonIngresarApretado(int x, int y)
{
    gotoxy(x,y);
    printf(" ______________");
    gotoxy(x,y+1);
    printf("||  Ingresar  |");
    gotoxy(x,y+2);
    printf("||____________|");
    gotoxy(x,y+3);
    printf("|/____________/");
}

void botonRegistrarse(int x, int y)
{
    gotoxy(x,y);
    printf(" _______________");
    gotoxy(x,y+1);
    printf("| | Registrarse |");
    gotoxy(x,y+2);
    printf("| |_____________|");
    gotoxy(x,y+3);
    printf("|/_____________/");
}

void botonRegistrarseApretado(int x, int y)
{
    gotoxy(x,y);
    printf(" _______________");
    gotoxy(x,y+1);
    printf("|| Registrarse |");
    gotoxy(x,y+2);
    printf("||_____________|");
    gotoxy(x,y+3);
    printf("|/_____________/");
}

void selector(int x, int y)
{
    gotoxy(x,y);
    printf("%s%c%c%s%c%c%s %c",ROJO,219,219,VERDE,219,219,NORMAL,175);
    gotoxy(x,y+1);
    printf("%s%c%c%s%c%c%s %c",MARRON,219,219,AZUL,219,219,NORMAL,175);
}

void frontMenuIngreso()
{
    gotoxy(28,16);
        printf("%s%c%c%s%c%c%s",ROJO,219,219,VERDE,219,219,NORMAL);
        gotoxy(28,17);
        printf("%s%c%c%s%c%c%s",MARRON,219,219,AZUL,219,219,NORMAL);
        gotoxy(87,16);
        printf("%s%c%c%s%c%c%s",ROJO,219,219,VERDE,219,219,NORMAL);
        gotoxy(87,17);
        printf("%s%c%c%s%c%c%s",MARRON,219,219,AZUL,219,219,NORMAL);

        dibujarCuadro(0,0,119,39,CYAN);

        nombreJuego(33,10);
        botonSalir(2,1);
        botonEmail(33,25);
        botonContrasenia(33,30);

        gotoxy(44,23);
        printf("printf(%cIngrese sus Datos...%c);",34,34);

        botonCargaDatos(50,25);
        botonCargaDatos(50,30);
}

void cargarDato(char arreglo[])
{
    char tecla;
    int i = 0;
    int posCursorX = whereX();
    int posCursorY = whereY();

    while((tecla = _getch()) != ENTER )
    {
        posCursorX = whereX();

        if(posCursorX < 84 )
        {
            gotoxy(posCursorX,posCursorY);
            arreglo[i] = tecla;
            printf("%c",tecla);
            i++;
        }
        if(tecla == CANCELAR)
        {
            gotoxy(posCursorX-1,posCursorY);printf(" ");
            gotoxy(posCursorX-1,posCursorY);
            i--;
        }
    }
    if(tecla == ENTER)
    {
        aniBotonEmail(33,25);
    }
    arreglo[i] = '\0';
}

void cargarPass(char arreglo[])
{
    char tecla;
    int i = 0;
    int posCursorX;
    int posCursorY = whereY();

    while((tecla = _getch()) != ENTER )
    {
        if(posCursorX < 84 )
        {
            arreglo[i] = tecla;
            i++;
            printf("%c",42);
            posCursorX = whereX();
        }
        if(tecla == CANCELAR)
        {
            gotoxy(posCursorX-1,posCursorY);printf(" ");
            gotoxy(posCursorX-1,posCursorY);
            i--;
        }
    }
    if(tecla == ENTER)
    {
        aniBotonPass(33,30);
    }
    arreglo[i] = '\0';
}

void menuIngresar()
{

    system("cls");
    frontMenuIngreso();

    char email[30];
    char pass [30];



    int tecla;
    while(tecla != SALIR)
    {
        if(kbhit())
        {
            tecla = getch();

            if(tecla == ENTER)
            {
                gotoxy(54,26);
                cargarDato(email);

                gotoxy(54,31);
                cargarPass(pass);
            }
            if(tecla == SALIR)
            {
                aniBotonSalir(2,1);
            }
        }
    }
    printf("%s\n",pass);
    printf("%s",email);
    system("pause");

}

void botonEmail(int x, int y)
{
        gotoxy(x,y);
    printf(" ______________");
    gotoxy(x,y+1);
    printf("| |   Email:   |");
    gotoxy(x,y+2);
    printf("| |____________|");
    gotoxy(x,y+3);
    printf("|/____________/");
}

void botonEmailApretado(int x, int y)
{
        gotoxy(x,y);
    printf(" ______________");
    gotoxy(x,y+1);
    printf("||   Email:   |");
    gotoxy(x,y+2);
    printf("||____________|");
    gotoxy(x,y+3);
    printf("|/____________/");
}

void botonContrasenia(int x, int y)
{
    gotoxy(x,y); printf(" ______________");
    gotoxy(x,y+1); printf("| |   Pass:    |");
    gotoxy(x,y+2); printf("| |____________|");
    gotoxy(x,y+3); printf("|/____________/");
}

void botonContraseniaApretado(int x, int y)
{
    gotoxy(x,y); printf(" ______________");
    gotoxy(x,y+1); printf("||   Pass:    |");
    gotoxy(x,y+2); printf("||____________|");
    gotoxy(x,y+3); printf("|/____________/");
}

void botonCargaDatos(int x, int y)
{
    gotoxy(x,y); printf(" __________________________________");
    gotoxy(x,y+1); printf("| |                                |");
    gotoxy(x,y+2); printf("| |________________________________|");
    gotoxy(x,y+3); printf("|/________________________________/");
}
//}


void aniBotonSalir(int x,int y)
{
    botonSalirApretado(x,y);
    Sleep(100);
    botonSalir(x,y);
    Sleep(100);

}

void aniBotonPass(int x, int y)
{
    botonContraseniaApretado(x,y);
    Sleep(300);
    botonContrasenia(x,y);
    Sleep(300);
}

void aniBotonEmail(int x, int y)
{
    botonEmailApretado(x,y);
    Sleep(300);
    botonEmail(x,y);
    Sleep(300);
}

void aniBotonIngresar(int x, int y)
{
    botonIngresarApretado(x,y);
    Sleep(200);
    botonIngresar(x,y);
    Sleep(200);
}

void aniBotonRegistrarse(int x, int y)
{
    botonRegistrarseApretado(x,y);
    Sleep(200);
    botonRegistrarse(x,y);
    Sleep(200);
}

void aniBotonAceptar(int x, int y)
{
    botonAceptarApretado(x,y);
    Sleep(100);
    botonAceptar(x,y);
    Sleep(100);
}

void aniBotonCreditos(int x,int y)
{
    botonCreditosApretado(x,y);
    Sleep(100);
    botonCreditos(x,y);
    Sleep(100);
}

void aniBotonAdmin(int x,int y)
{
    botonAdminApretado(x,y);
    Sleep(100);
    botonAdmin(x,y);
    Sleep(100);
}

