#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED
#include <stdbool.h>


typedef struct
{
    int id;
    char nombreApellido[30];
    char nickUsuario[30];
    char email[30];
    char contrasenia[30];
    bool habilitado;
    char nombreArchivoPersonajes[80];

}stUsuario;


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



typedef struct
{
    stCaracteristica atributos;
    stPosicion posicion;
    char nick[30];
    int llaves;

} stPj;


typedef struct
{
    stUsuario usuario;
    struct stArbol * ramaDer;
    struct stArbol * ramaIzq;

}stArbol;







#endif // ESTRUCTURAS_H_INCLUDED
