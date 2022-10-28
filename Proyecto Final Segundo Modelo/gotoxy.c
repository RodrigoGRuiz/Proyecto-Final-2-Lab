#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void color(int x){                                                              /// Cambia la combinacion de color de fondo y frente
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
}

void gotoxy(int X,int Y){                                                       /// Cambia las coordenadas del cursor
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X=X;
      dwPos.Y=Y;
      SetConsoleCursorPosition(hcon,dwPos);
}

int whereX(){                                                                     /// Devuelve la posicion de X
    CONSOLE_SCREEN_BUFFER_INFO sbi;
    GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &sbi);
    return sbi.dwCursorPosition.X;
}

int whereY(){                                                                   /// Devuelve la posicion de Y
    CONSOLE_SCREEN_BUFFER_INFO sbi;
    GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &sbi);
    return sbi.dwCursorPosition.Y;
}

void hidecursor(int ver){                                                       /// funcion para mostrar o esconder el cursor
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 1;
   info.bVisible = ver;
   SetConsoleCursorInfo(consoleHandle, &info);
}


void dibujarCuadro(int x1,int y1,int x2,int y2,char color[])
{
    printf("%s",color);
    int i;

    for (i=x1; i<x2; i++)
    {
        gotoxy(i,y1);
        printf("%c",219); //linea horizontal superior
        gotoxy(i,y2);
        printf("%c",219); //linea horizontal inferior
    }

    for (i=y1; i<y2; i++)
    {
        gotoxy(x1,i);
        printf("%c",219); //linea vertical izquierda
        gotoxy(x2,i);
        printf("%c",219); //linea vertical derecha
    }
    //superior izq
    gotoxy(x1,y1);printf("%c",219);
    //inferior izq
    gotoxy(x1,y2);printf("%c",219);
    //superior der
    gotoxy(x2,y1);printf("%c",219);
    //inferior der
    gotoxy(x2,y2);printf("%c",219);
    printf("\033[0m");
}


void dibujarCuadroAscii(int x1,int y1,int x2,int y2,int ascii)
{
    int i;

    for (i=x1; i<x2; i++)
    {
        gotoxy(i,y1);
        printf("%c",ascii); //linea horizontal superior
        gotoxy(i,y2);
        printf("%c",ascii); //linea horizontal inferior
    }

    for (i=y1; i<y2; i++)
    {
        gotoxy(x1,i);
        printf("%c",ascii); //linea vertical izquierda
        gotoxy(x2,i);
        printf("%c",ascii); //linea vertical derecha
    }
    //superior izq
    gotoxy(x1,y1);printf("%c",ascii);
    //inferior izq
    gotoxy(x1,y2);printf("%c",ascii);
    //superior der
    gotoxy(x2,y1);printf("%c",ascii);
    //inferior der
    gotoxy(x2,y2);printf("%c",ascii);
}

void dibujarLinea(int x, int y,int fin, int ascii)
{
    for(int i = x ; i<=fin ; i++ )
    {
        gotoxy (i,y); printf("%c",ascii);
    }
}


void centrarTexto(char *texto, int y)
{
    int longitud = strlen(texto);
    gotoxy(40-(longitud/2),y);
    printf(texto);
}

// - FUNCION QUE HACE UN FONDO BLANCO

void fondoBlanco(int x, int xfin,int limite)
{
    for(int i = 0; i< limite;i++)
    {
        dibujarLinea(x,i,xfin,32);
    }
}


































































