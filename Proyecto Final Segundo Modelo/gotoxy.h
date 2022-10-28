#ifndef GOTOXY_H_INCLUDED
#define GOTOXY_H_INCLUDED

void color(int x);
void gotoxy(int X,int Y);
int whereX();
int whereY();
void hidecursor(int ver);
void dibujarCuadro(int x1,int y1,int x2,int y2,char color[]);
void dibujarLinea(int x, int y,int fin, int ascii);
void centrarTexto(char *texto, int y);
void fondoBlanco(int x, int xfin,int limite);
void dibujarCuadroAscii(int x1,int y1,int x2,int y2,int ascii);

#endif // GOTOXY_H_INCLUDED
