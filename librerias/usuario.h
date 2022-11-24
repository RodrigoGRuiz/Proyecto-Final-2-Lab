#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include <stdbool.h>
#include "estructuras.h"
#include "usuario.h"

typedef struct
{
    stUsuario usuario;
    stPj * listaPersonajes;
    struct nodo * siguienteUsuario;
}nodoUsuario;

void nombreArchivoPersonajes(stUsuario * usuario);
void editarIngreso(stUsuario * usuario);
void agregarAlArchivoUsuarios(stUsuario usuario, char nombreArchivo[]);
stUsuario buscaUsuario (char string[]);

int verificarUsuario(char string1[],char string2[]);
int verificarEmail(char email[]);
int verificarNickUsuario(char nick[]);
int asignarIdUsuario();

nodoUsuario * inicListaUsuarios();
nodoUsuario * crearUsuario(stUsuario usuario);
nodoUsuario * agregarEnOrden(nodoUsuario * listaUsuarios,nodoUsuario * nuevoUsuario);
nodoUsuario * agregaraAlPrincipioUsuario(nodoUsuario * listaUsuarios,nodoUsuario * nuevoUsuario);
nodoUsuario * deListaArchivo(nodoUsuario * listaUsuarios);

int pasarListaArreglo(nodoUsuario * lista, stUsuario arreglo[],int cantElementos,int posicion);
void muestraArregloUsuarios(stUsuario arreglo[],int dim,int x,int y,int posInicial,int posFinal);
void mostrarUsuario(stUsuario usuario,int x,int y);
int contarElementos(nodoUsuario * lista);
void muestraUsuarioArregloSelector(int posSelector,stUsuario arreglo[]);

#endif // USUARIO_H_INCLUDED





