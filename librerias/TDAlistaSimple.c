#include "TDAlistaSimple.h"
#include "personaje.h"



nodo * inicNodoSimple()
{
    return NULL;
}


nodo * crearPersonaje(stPj personaje)
{
    nodo * nodoAuxiliar = (nodo*)malloc(sizeof(nodo));
    nodoAuxiliar->personaje = personaje;
    nodoAuxiliar->siguientePj = NULL;
    return nodoAuxiliar;
}


nodo * colocarEnLista(nodo * lista, nodo * nuevo) // ==> AGREGA AL PRINCIPIO DE LA LISTA
{
    if (lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nuevo->siguientePj = lista;
        lista = nuevo;
    }
    return lista;
}


nodo * buscarUltimoPersonaje(nodo * lista) // ==> RETORNA EL ULTIMO ELEMENTO
{
    nodo * iterator = lista;
    if(lista != NULL)
    {
        while (iterator->siguientePj != NULL)
        {
            iterator = iterator->siguientePj;
        }
    }
    return iterator;
}

nodo * colocarAlFinalLista(nodo * lista, nodo *nuevo) // ==> AGREGA AL FINAL DE LA LISTA
{
    if(lista != NULL)
    {
        nodo * ultimo = buscarUltimoPersonaje(lista);
        ultimo->siguientePj = nuevo;
    }
    else
    {
        lista = nuevo;
    }
    return lista;
}


nodo * borrarPersonajeBuscado (nodo * lista, stPj personaje)
{
    nodo * nodoAuxiliar = lista; // 1)
    nodo * datoAnterior; // 1)

    if((lista != NULL) && strcmpi(lista->personaje.nick,personaje.nick) == 0) // 2)
    {
        lista = lista->siguientePj; // 2)
        free(nodoAuxiliar); // 2)
    }
    else
    {
        while((nodoAuxiliar != NULL) && strcmpi(lista->personaje.nick,personaje.nick) != 0) // 3)
        {
            datoAnterior = nodoAuxiliar; // 3)
            nodoAuxiliar = nodoAuxiliar->siguientePj; //3)
        }
        if(nodoAuxiliar != NULL) // 4)
        {
            datoAnterior->siguientePj = nodoAuxiliar->siguientePj; // 4)
            free(nodoAuxiliar); // 4)
        }
    }
    return lista; // 5)
}


void unPersonaje(nodo * nodoMostrado)
{
    printf("%s%s%s\n",APERTURA,nodoMostrado->personaje.nick,CERRADO);
}


void mostrarListaNodoSimple(nodo * lista)
{
    while(lista != NULL)
    {
        unPersonaje(lista);
        lista=lista->siguientePj;
    }
}


nodo * menorBuscado(nodo *lista)
{
    nodo * menor;
    nodo * iterador = lista;
    menor = lista;
    while (iterador != NULL)
    {
        if(strcmpi(menor->personaje.nick,iterador->personaje.nick) > 0)
        {
            menor = iterador;
        }
        iterador = iterador->siguientePj;
    }
    return menor;
}


















