#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#include "TDAarboles.h"
#include "usuario.h"
#include "personaje.h"
#include "estructuras.h"


#define ROJO "\033[0;31m"
#define CYAN "\033[0;36m"
#define VERDE "\033[4;32m"
#define NORMAL "\033[0m"
#define APERTURA "\033[0;36m[\033[0m"
#define CERRADO "\033[0;36m]\033[0m"




stArbol * iniciarArbol()
{
    return NULL;
}

/// FUNCION QUE CREA UN NUEVO NODO TIPO ARBOL
stArbol * crearNodoArbol(stUsuario usuario)
{
    stArbol * nodoAuxiliar = (stArbol*)malloc(sizeof(stArbol)); /// <--- Asigno Memoria Dinamica

    nodoAuxiliar->usuario = usuario; /// <---- Le asigno el dato ingresado por parametro al nuevo nodo.
    nodoAuxiliar->ramaDer = NULL; /// <--- Le asigno null para dejarlo preparado para poder enlazar nuevos elementos y no me tome basura.
    nodoAuxiliar->ramaIzq = NULL; /// <--- Lo mismo que el anterior.

    return nodoAuxiliar; /// <--- Retono el puntero del NODO Auxiliar
}


/// FUNCION INSERTA UN DATO EN EL ARBOL
stArbol * insertar (stArbol * arbol, stUsuario usuario)
{
    if(arbol == NULL) /// <--- COMPROBAS si el arbol esta vacio.
    {
        arbol = crearNodoArbol(usuario); /// <--- CREAMOS un nuevo nodo.
    }
    else /// <--- SINO
    {
        if( usuario.id > arbol->usuario.id) /// <--- Si el dato a ingresar es mas grande que el DATO que esta en la posicion actual
        {
            arbol->ramaDer = insertar(arbol->ramaDer, usuario); /// <---
        }
        else
        {
            arbol->ramaIzq = insertar(arbol->ramaIzq, usuario);
        }
    }
    return arbol;
}


///FUNCION QUE BUSCA UN NODO DENTRO DE UN ARBOL
stArbol * buscarDato(stArbol * arbol, stUsuario usuario) /// <--- pasamos por parametro los dato buscados;
{
    stArbol * respuesta = NULL; /// <--- crweamos un NODO auxiliar para poder iterar entre los elementos
    if(arbol != NULL) /// <--- Comprobamos si el arbol tiene elementos
    {
        if(usuario.id == arbol->usuario.id) /// <--- si el dato es igual al arbol
        {
            respuesta = arbol; /// <--- DEVOLVEMOS el albol donde se encuentra el arbol
        }
        else /// <--- Sino
        {
            if(usuario.id > arbol->usuario.id) /// <--- Si el DATO es mayor que es DATO que se encuentra en el Arbol actual
            {
                respuesta = buscarDato(arbol->ramaDer,usuario); /// <--- BUSCAMOS el DATO en la rama DERECHA
            }
            else
            {
                respuesta = buscarDato(arbol->ramaIzq,usuario); /// <--- BUSCAMOS el DATO en la rama IZQUIERDA
            }
        }
    }
    return respuesta; /// <--- RETORNAMOS el puntero del DATO encontrado.
}

///FUNCION MUESTRA EL ARBOL POR EL PRIMERO LA RAMA IZQUIERDA

void preOrder (stArbol * arbol)
{
    if(arbol != NULL)
    {
        unDato(arbol->usuario);
        preOrder(arbol->ramaIzq);
        preOrder(arbol->ramaDer);
    }
}

/// FUNCION QUE MUESTRA EL ARBOL EN EL ORDEN CORRESPONDIENTE
void inOrder (stArbol * arbol)
{
    if(arbol != NULL)
    {
        inOrder(arbol->ramaIzq);
        unDato(arbol->usuario);
        inOrder(arbol->ramaDer);
    }
}

/// FUNCION QUE MUESTRA EL ARBOL

void postOrder (stArbol * arbol)
{
    if(arbol != NULL)
    {
        postOrder(arbol->ramaIzq);
        postOrder(arbol->ramaDer);
        unDato(arbol->usuario);
    }
}

void unDato(stUsuario usuario)
{
    printf("Nombre Apellido: %s\n", usuario.nombreApellido);
    printf("Nick Usuario: %s\n", usuario.nickUsuario);
    printf("Email Usuario: %s\n", usuario.email);
    printf("Contrasenia: %s\n", usuario.contrasenia);
}



stArbol * pasarArchivoArbol(stArbol * arbolNavidad)
{
    stUsuario usuario;

    FILE * archivo = fopen("ArchivosAdmins\\lista_usuarios.bin","r+b");
    if(archivo)
    {
        while(fread(&usuario,sizeof(usuario),1,archivo)>0)
        {
            arbolNavidad = insertar(arbolNavidad,usuario);
        }

        fclose(archivo);
    }
}


















































