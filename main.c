#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#include "librerias/TDAlistaSimple.h"
#include "librerias/TDAarboles.h"
#include "librerias/botonesAnimaciones.h"
#include "librerias/gotoxy.h"
#include "librerias/usuario.h"
#include "librerias/menus.h"
#include "librerias/estructuras.h"
#include "librerias/sala.h"
#include "librerias/enemigo.h"
#include "librerias/personaje.h"
#include "librerias/objeto.h"
#include "librerias/puertas.h"

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






int main()
{
    system("cls");

    system("mode con: cols=120 lines=40");

//    inicioMenu(0);
    frontMenuUsuario();
//        mostrarArchivo();
//    frontMenuComandoAdmin();
//    cargarJuego();

    return 0;
}


















