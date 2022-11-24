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






//GENERA AUTOMATICAMENTE EL ARCHIVO DE PERSONAJES UNICOS POR USUARIO
void nombreArchivoPersonajes(stUsuario * usuario)
{
    char tipoArchivo [30]= "_personajes.bin";
    char temporal [80];
    strcpy(temporal,usuario->nickUsuario);
    strcat(temporal,tipoArchivo);
    strcpy(usuario->nombreArchivoPersonajes,temporal);
    gotoxy(2,38); printf("%s",usuario->nombreArchivoPersonajes);
}


//EDITA EN EL REGISTRO LOS DATOS INGRESADOS POR EL USUARIO
void editarIngreso(stUsuario * usuario)
{
    int posicion = 1;
    imprimirSelector(posicion);
    char tecla;
    while(tecla != SALIR)
    {
        if(kbhit())
        {
            tecla = getch();
            if(tecla == ARRIBA && posicion > 1 )
            {
                posicion--;
            }

            if(tecla == ABAJO && posicion < 4 )
            {
                posicion++;
            }
            if(tecla == ESPACIO && posicion == 1)
            {
                limpiarArregloChar(usuario->nombreApellido);
                dibujarLinea(48,11,77,32);
                cargarDato(usuario->nombreApellido,48,11);
                aniBotonNombreApellidoUsuarioApretado(27,10);
                tecla = SALIR;
            }
            if(tecla == ESPACIO && posicion == 2)
            {
                limpiarArregloChar(usuario->nickUsuario);
                dibujarLinea(48,16,77,32);
                cargarDato(usuario->nickUsuario,48,16);
                aniBotonNombreUsuario(27,15);
                limpiarArregloChar(usuario->nombreArchivoPersonajes);
                nombreArchivoPersonajes(usuario);
                tecla = SALIR;
            }
            if(tecla == ESPACIO && posicion == 3)
            {
                limpiarArregloChar(usuario->email);
                dibujarLinea(48,21,77,32);
                cargarDato(usuario->email,48,21);
                aniBotonEmail(27,20);
                tecla = SALIR;
            }
            if(tecla == ESPACIO && posicion == 4)
            {
                limpiarArregloChar(usuario->contrasenia);
                dibujarLinea(48,26,77,32);
                cargarDatoPass(usuario->contrasenia,48,26);
                aniBotonPass(27,25);
                tecla = SALIR;
            }
            imprimirSelector(posicion);
        }
    }
}


//AGREGA AL USUARIO A UN ARCHIVO DE USUARIO
void agregarAlArchivoUsuarios(stUsuario usuario, char nombreArchivo[])
{
    char direccionCarpeta [30]= "ArchivosAdmins\\";
    char temporal [100];
    strcpy(temporal,direccionCarpeta);
    strcat(temporal,nombreArchivo);

    FILE * archivo = fopen(temporal,"a+b");

    if(archivo)
    {
        fwrite(&usuario,sizeof(usuario),1,archivo);

     fclose(archivo);
    }
}


int verificarUsuario(char string1[],char string2[])
{
    stUsuario usuario;
    int flag = 0;
    FILE * archivo = fopen("ArchivosAdmins\\lista_usuarios.bin","r+b");
    if(archivo)
    {
        while(fread(&usuario,sizeof(usuario),1,archivo) > 0)
        {
            if( strcmpi(usuario.email,string1) == 0)
            {
                if( strcmpi(usuario.contrasenia,string2) == 0)
                {
                    flag = 1;
                }
            }
        }
        fclose(archivo);
    }
    return flag;
}

stUsuario buscaUsuario (char string[])
{
    stUsuario usuario;
    int flag = 0;
    FILE * archivo = fopen("ArchivosAdmins\\lista_usuarios.bin","r+b");
    if(archivo)
    {
        while(fread(&usuario,sizeof(usuario),1,archivo) > 0)
        {
            if( strcmpi(usuario.email,string) == 0)
            {
                    return usuario;
            }
        }
        fclose(archivo);
    }
}


int verificarEmail(char email[])
{
    stUsuario usuario;
    int flag = 0;
    FILE * archivo = fopen("ArchivosAdmins\\lista_usuarios.bin","r+b");
    if(archivo)
    {
        while(fread(&usuario,sizeof(usuario),1,archivo) > 0)
        {
            if( strcmpi(usuario.email,email) == 0)
            {
                flag = 1;
            }
        }
        fclose(archivo);
    }
    return flag;
}


int verificarNickUsuario(char nick[])
{
    stUsuario usuario;
    int flag = 0;
    FILE * archivo = fopen("ArchivosAdmins\\lista_usuarios.bin","r+b");
    if(archivo)
    {
        while(fread(&usuario,sizeof(usuario),1,archivo) > 0)
        {
            if( strcmpi(usuario.nickUsuario,nick) == 0)
            {
                flag = 1;
            }
        }
        fclose(archivo);
    }
    return flag;
}


int asignarIdUsuario()
{
    stUsuario usuario;
    int contador = 0;
    FILE * archivo = fopen("ArchivosAdmins\\lista_usuarios.bin","r+b");
    if(archivo)
    {
        while(fread(&usuario,sizeof(usuario),1,archivo) > 0)
        {
            contador ++;
        }
        fclose(archivo);
    }
    return contador;
}


nodoUsuario * inicListaUsuarios()
{
    return NULL;
}


nodoUsuario * crearUsuario(stUsuario usuario)
{
    nodoUsuario * nodoAuxiliar = (nodoUsuario*)malloc(sizeof(nodoUsuario));

    nodoAuxiliar->usuario = usuario;
    nodoAuxiliar->listaPersonajes = inicNodoSimple();
    nodoAuxiliar->siguienteUsuario = NULL;

    return nodoAuxiliar;
}


nodoUsuario * agregaraAlPrincipioUsuario(nodoUsuario * listaUsuarios,nodoUsuario * nuevoUsuario)
{
    if(listaUsuarios == NULL)
    {
        listaUsuarios = nuevoUsuario;
    }
    else
    {
        nuevoUsuario->siguienteUsuario = listaUsuarios;
        listaUsuarios = nuevoUsuario;
    }
    return listaUsuarios;
}


nodoUsuario * agregarEnOrden(nodoUsuario * listaUsuarios,nodoUsuario * nuevoUsuario)
{
    if(listaUsuarios == NULL)
    {
        listaUsuarios = nuevoUsuario;
    }
    else
    {
        if(nuevoUsuario->usuario.id < listaUsuarios->usuario.id)
        {
            listaUsuarios = agregaraAlPrincipioUsuario(listaUsuarios,nuevoUsuario);
        }
        else
        {
            nodoUsuario * anterior;
            nodoUsuario * iterador = listaUsuarios;

            while(iterador != NULL && nuevoUsuario->usuario.id > iterador->usuario.id)
            {
                anterior = iterador;
                iterador = iterador->siguienteUsuario;
            }
            anterior->siguienteUsuario = nuevoUsuario;
            nuevoUsuario->siguienteUsuario = iterador;
        }
    }
    return listaUsuarios;
}


nodoUsuario * deListaArchivo(nodoUsuario * listaUsuarios)
{
    stUsuario usuario;
    FILE * archivo =  fopen("ArchivosAdmins\\lista_usuarios.bin","r+b");

    if(archivo)
    {
        while(fread(&usuario,sizeof(usuario),1,archivo) > 0 )
        {
            nodoUsuario * nodoNuevo = crearUsuario(usuario);

            listaUsuarios = agregarEnOrden(listaUsuarios,nodoNuevo);
        }
        fclose(archivo);
    }
    return listaUsuarios;
}



int pasarListaArreglo(nodoUsuario * lista, stUsuario arreglo[],int cantElementos,int posicion)
{
    int j = 0;
    while(j < posicion)
    {
        lista = lista->siguienteUsuario;
        j++;
    }
    int i = 0;

    while(lista != NULL && i < 9 && posicion < cantElementos)
    {
        if(posicion < cantElementos+1)
        {
            arreglo[i] = lista->usuario;
            i++;
        }
        lista = lista->siguienteUsuario;
    }
    posicion+=i;
    return posicion;
}

void muestraArregloUsuarios(stUsuario arreglo[],int dim,int x,int y,int posInicial,int posFinal)
{
    int i;
    int j = 0;
    for( i = posInicial; i < posFinal && i< dim ; i++)
    {
        mostrarUsuario(arreglo[j],x,y);
        y += 3;
        j++;
    }
}

void mostrarUsuario(stUsuario usuario,int x,int y)
{
    gotoxy(x,y);printf("ID: %s%d%s",APERTURA,usuario.id,CERRADO);
    gotoxy(x,y+1);printf("NICK: %s%s%s",APERTURA,usuario.nickUsuario,CERRADO);
}


void muestraUsuarioArregloSelector(int posSelector,stUsuario arreglo[])
{
    gotoxy(51,6); printf("                              ");
    gotoxy(51,6); printf("%s",arreglo[posSelector].nombreApellido);
    gotoxy(51,10); printf("                             ");    gotoxy(51,10); printf("%s",arreglo[posSelector].nickUsuario);
    gotoxy(51,14); printf("                             ");
    gotoxy(51,14); printf("%s",arreglo[posSelector].email);
    gotoxy(51,18); printf("                             ");
    gotoxy(51,18); printf("%s",arreglo[posSelector].contrasenia);
    if(arreglo[posSelector].habilitado == true)
    {
        gotoxy(52,24); printf("%s%c%c%c%s",VERDE,219,219,219,NORMAL);
    }
    else
    {
        gotoxy(52,24); printf("%s%c%c%c%s",ROJO,219,219,219,NORMAL);
    }
}

int contarElementos(nodoUsuario * lista)
{
    int contador = 0;
    while(lista != NULL)
    {
        contador++;
        lista = lista->siguienteUsuario;
    }
    return contador;
}

















