#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#include "TDAlistaSimple.h"
#include "TDAarboles.h"
#include "botonesAnimaciones.h"
#include "gotoxy.h"
#include "usuario.h"
#include "menus.h"
#include "estructuras.h"


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
#define PALABRACLAVE "mermelada"

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




//    FUNCIONES MENUS




void frontMenuCombate()
{
    system("cls");
    dibujarCuadro(0,0,118,25,CYAN); // cuadrado principal
    dibujarCuadro(0,0,118,39,CYAN);//cuadrado panel
    dibujarCuadro(4,4,29,22,CYAN); // cuadrado Exterior
    cuadradoAscii(2,2,117,24,219);//cuadrado batalla
    cuadradoAscii(2,26,117,39,219);


    cuadradoConMarco(3,3,26,22,MARRON); // cuadrado personaje
    cuadradoConMarco(92,3,115,22,MARRON); //cuadrado enemigo
    cuadradoConMarco(45,10,74,16,MARRON); //cuadrado accion enemigo

    pintarEnemigo(99,10);
    pintarPersonajeParado(9,10);

    cuadradoConMarco(42,27,77,36,MARRON); //cuadrado muestra controles
    muestraControles(44,30);
    gotoxy(44,29);
    printf("%sAtaca%s     %sCurar%s     %sEspera%s",APERTURA,CERRADO,APERTURA,CERRADO,APERTURA,CERRADO);

    cuadradoConMarco(3,27,35,37,MARRON); //cuadrado muestra info enemigo

    cuadradoConMarco(84,27,115,31,MARRON); //cuadrado estad. info enemigo
    cuadradoConMarco(84,31,115,37,MARRON); //cuadrado estad. info enemigo

}

void menuCombate(stPj * personaje,nodoEnemigo * enemigo)
{
    frontMenuCombate();
    gotoxy(86,28);
    printf("ENEMIGO:");
    nombresEnemigos();
    gotoxy(90,32);
    printf("ATRIBUTOS:");
    gotoxy(86,33);
    printf("Vida : %d",enemigo->atributos.vida);
    gotoxy(86,34);
    printf("Danio : %d",enemigo->atributos.danio);
    gotoxy(86,35);
    printf("Defensa : %d",enemigo->atributos.defensa);
}

char menuInicioSesionSecundario(char tecla)
{
    frontMenuInicioSesion();
    int posicion = 1;
    while(tecla != SALIR)
    {
        if(kbhit())
        {
            tecla = getch();

            if(tecla == DERECHA)
            {
                cuadradoAscii(28,31,34,33,32);
                selector(61,31);
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
                tecla = menuIngresar(0);
            }
            if(tecla == ENTER && posicion == 2)
            {
                aniBotonRegistrarse(68,30);
                tecla = menuRegitro(0);
            }
        }
    }
    return tecla;
}

char inicioMenuSecundario(char tecla)
{
    frontInicioMenu();
    while(tecla != SALIR)
    {

        if(kbhit())
        {
            tecla = getch();

            if(tecla == ENTER)
            {
                aniBotonAceptar(45,33);
                tecla = menuInicioSesion(0);
            }
            if(tecla == C)
            {
                aniBotonCreditos(2,33);
            }
            if(tecla == A)
            {
                aniBotonAdmin(103,34);
                tecla = menuAdministrador(0);
            }
        }
    }
    return tecla;
}

void frontMenuInicioSesion()
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
}

char menuInicioSesion(char tecla)
{
    frontMenuInicioSesion();
    int posicion = 1;
    while(tecla != SALIR)
    {
        if(kbhit())
        {
            tecla = getch();

            if(tecla == DERECHA)
            {
                cuadradoAscii(28,31,34,33,32);
                selector(61,31);
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
                tecla = menuIngresar(0);
            }
            if(tecla == ENTER && posicion == 2)
            {
                aniBotonRegistrarse(68,30);
                tecla = menuRegitro(0);
            }
            if(tecla == SALIR)
            {
                aniBotonSalir(2,1);
                tecla = inicioMenuSecundario(0);
            }
        }
    }
    return tecla;
}

void frontInicioMenu()
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
}

char inicioMenu(char tecla)
{
    frontInicioMenu();
    while(tecla != SALIR)
    {

        if(kbhit())
        {
            tecla = getch();

            if(tecla == ENTER)
            {
                aniBotonAceptar(45,33);
                tecla = menuInicioSesion(0);
            }
            if(tecla == C)
            {
                aniBotonCreditos(2,33);
            }
            if(tecla == A)
            {
                aniBotonAdmin(103,34);
                tecla = menuAdministrador(0);

            }
            if(tecla == SALIR)
            {
                aniBotonSalir(2,1);
            }
        }
    }
    return tecla;
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
    botonEnter(80,25);
    nombreJuego(33,10);
    botonSalir(2,1);
    botonEmail(27,25);
    botonContrasenia(27,30);

    gotoxy(35,23);
    printf("printf(%cPrecione ESPACIO para Iniciar Sesion...%c);",34,34);

    botonCargaDatos(44,25);
    botonCargaDatos(44,30);
}

char menuIngresar(char tecla)
{

    system("cls");
    frontMenuIngreso();

    char email[30];
    char contrasenia [30];
    stUsuario usuario;

    while(tecla != SALIR)
    {
        if(kbhit())
        {
            tecla = getch();

            if(tecla == ESPACIO)
            {
                limpiarArregloChar(email);
                cuadradoAscii(47,26,78,27,32);
                gotoxy(48,26);
                cargarDato(email,48,26);
                aniBotonEmail(27,25);

                limpiarArregloChar(contrasenia);
                cuadradoAscii(47,31,78,31,32);
                gotoxy(48,31);
                cargarDatoPass(contrasenia,48,31);
                aniBotonPass(27,30);
            }
            if(tecla == ENTER)
            {
                int flag = verificarUsuario(email,contrasenia);
                if(flag)
                {
                    usuario = buscaUsuario(email);
                    gotoxy(25,37);
                    printf("%sprintf(%cBienvenido %s ...%c);%s",VERDE,34,usuario.nickUsuario,34,NORMAL);
                    Sleep(2000);
                    menuUsuario(usuario);
                }
                else
                {
                    gotoxy(20,37);
                    printf("%sprintf(%cTe atrapamos tramposillo, apriete ESPACIO para volver a Intentar...%c);%s",ROJO,34,34,NORMAL);
                    Sleep(3000);
                    cuadradoAscii(20,36,100,38,32);
                }
            }
            if(tecla == SALIR)
            {
                aniBotonSalir(2,1);
                menuInicioSesionSecundario(0);
            }
        }
    }
    return tecla;
}

void frontMenuAdministrador()
{
    system("cls");
    gotoxy(28,12);
    printf("%s%c%c%s%c%c%s",ROJO,219,219,VERDE,219,219,NORMAL);
    gotoxy(28,13);
    printf("%s%c%c%s%c%c%s",MARRON,219,219,AZUL,219,219,NORMAL);
    gotoxy(87,12);
    printf("%s%c%c%s%c%c%s",ROJO,219,219,VERDE,219,219,NORMAL);
    gotoxy(87,13);
    printf("%s%c%c%s%c%c%s",MARRON,219,219,AZUL,219,219,NORMAL);

    dibujarCuadro(0,0,119,39,CYAN);
    botonEnter(80,25);
    tituloAdmins(33,8);
    botonSalir(2,1);

    botonEmail(27,20);
    botonContrasenia(27,25);
    botonCodigo(27,30);

    gotoxy(36,19);
    printf("printf(%cBienvenido Se%cor de las Tinieblas...%c);",34,164,34);

    botonCargaDatos(44,20);
    botonCargaDatos(44,25);
    botonCargaDatos(44,30);
}

char menuAdministradorSecundario(char tecla)
{
    frontMenuAdministrador();

    char email[30];
    char contrasenia [30];
    char palabraSecreta[30];
    stUsuario usuario;

    while(tecla != SALIR)
    {
        if(kbhit())
        {
            tecla = getch();

            if(tecla == ESPACIO)
            {
                limpiarArregloChar(email);
                cuadradoAscii(48,21,78,22,32);
                cargarDato(email,48,21);
                aniBotonEmail(27,20);

                limpiarArregloChar(contrasenia);
                cuadradoAscii(48,26,78,27,32);
                cargarDatoPass(contrasenia,48,26);
                aniBotonPass(27,25);

                limpiarArregloChar(palabraSecreta);
                cuadradoAscii(48,31,78,32,32);
                cargarDatoPass(palabraSecreta,48,31);
                aniBotonCodigo(27,30);


            }
            if(tecla == ENTER)
            {
                aniBotonEnter(80,25);
                int flag = verificarUsuario(email,contrasenia);
                if(flag)
                {
                    usuario = buscaUsuario(email);

                    if(strcmpi(palabraSecreta,PALABRACLAVE) == 0)
                    {
                        gotoxy(40,37);
                        printf("%sprintf(%cBienvenido %s ...%c);%s",VERDE,34,usuario.nickUsuario,34,NORMAL);
                        Sleep(2000);
                        menuComandoAdmin(0,usuario);
                    }
                    else
                    {
                        gotoxy(20,37);
                        printf("%sprintf(%cLa policia esta llendo a tu casa IMPOSTOR!!!...  o vuelva intentar...%c);%s",ROJO,34,34,NORMAL);
                        Sleep(4000);
                        cuadradoAscii(15,36,100,38,32);
                    }
                }
                else
                {
                    gotoxy(20,37);
                    printf("%sprintf(%cTe atrapamos tramposillo, apriete ESPACIO para volver a Intentar...%c);%s",ROJO,34,34,NORMAL);
                    Sleep(3000);
                    cuadradoAscii(20,36,100,38,32);
                }
            }
        }
    }
    return tecla;
}

char menuAdministrador(char tecla)
{
    frontMenuAdministrador();

    char email[30];
    char contrasenia [30];
    char palabraSecreta[30];
    stUsuario usuario;

    while(tecla != SALIR)
    {
        if(kbhit())
        {
            tecla = getch();

            if(tecla == ESPACIO)
            {
                limpiarArregloChar(email);
                cuadradoAscii(48,21,78,22,32);
                cargarDato(email,48,21);
                aniBotonEmail(27,20);

                limpiarArregloChar(contrasenia);
                cuadradoAscii(48,26,78,27,32);
                cargarDatoPass(contrasenia,48,26);
                aniBotonPass(27,25);

                limpiarArregloChar(palabraSecreta);
                cuadradoAscii(48,31,78,32,32);
                cargarDatoPass(palabraSecreta,48,31);
                aniBotonCodigo(27,30);


            }
            if(tecla == ENTER)
            {
                aniBotonEnter(80,25);
                int flag = verificarUsuario(email,contrasenia);
                if(flag)
                {
                    usuario = buscaUsuario(email);

                    if(strcmpi(palabraSecreta,PALABRACLAVE) == 0)
                    {
                        gotoxy(40,37);
                        printf("%sprintf(%cBienvenido %s ...%c);%s",VERDE,34,usuario.nickUsuario,34,NORMAL);
                        Sleep(2000);
                        menuComandoAdmin(0,usuario);
                    }
                    else
                    {
                        gotoxy(20,37);
                        printf("%sprintf(%cLa policia esta llendo a tu casa IMPOSTOR!!!...  o vuelva intentar...%c);%s",ROJO,34,34,NORMAL);
                        Sleep(4000);
                        cuadradoAscii(15,36,100,38,32);
                    }
                }
                else
                {
                    gotoxy(20,37);
                    printf("%sprintf(%cTe atrapamos tramposillo, apriete ESPACIO para volver a Intentar...%c);%s",ROJO,34,34,NORMAL);
                    Sleep(3000);
                    cuadradoAscii(20,36,100,38,32);
                }
            }
            if(tecla == SALIR)
            {
                aniBotonSalir(2,1);
                inicioMenuSecundario(0);
            }
        }
    }
    return tecla;
}

void frontMenuRegistro()
{
    system("cls");
    dibujarCuadro(0,0,119,39,CYAN);

    tituloMenu(40,1);
    gotoxy(30,7);
    printf("printf(%cPrecione ESPACIO para llenar los Campos...%c);",34,34);
    gotoxy(90,9);
    printf("printf(%cREGISTRAR...%c);",34,34);

    botonEnter(95,10);
    botonSalir(2,1);

    botonNombreApellidoUsuario(27,10);
    botonNombreUsuario(27,15);
    botonEmail(27,20);
    botonContrasenia(27,25);
    botonConfirmarContrasenia(27,30);
    botonEditar(95,30);


    botonCargaDatos(44,10);
    botonCargaDatos(44,15);
    botonCargaDatos(44,20);
    botonCargaDatos(44,25);
    botonCargaDatos(44,30);



}

char menuRegitro(char tecla)
{
    frontMenuRegistro();
    int flag;
    stUsuario usuario;
    char passTemporal[30];

    while(tecla != SALIR)
    {
        if(kbhit())
        {
            tecla = getch();

            if(tecla == ESPACIO)
            {

                cuadradoAscii(85,11,89,33,32);
                selector(85,11);
                cargarDato(usuario.nombreApellido,48,11);
                aniBotonNombreApellidoUsuarioApretado(27,10);
                do
                {
                    limpiarArregloChar(usuario.nickUsuario);
                    cuadradoAscii(85,11,89,33,32); // BORRA EL SELECTOR
                    cuadradoAscii(48,16,89,17,32); // BORRA EL ANTERIOR TEXTO INGRESADO
                    selector(85,16);
                    cargarDato(usuario.nickUsuario,48,16);
                    aniBotonNombreUsuario(27,15);
                    flag = verificarNickUsuario(usuario.nickUsuario);
                    if(flag == 1)
                    {
                        gotoxy(45,19);
                        printf("%sprintf(%cTe copiaste de otro...%c);%s",ROJO,34,34,NORMAL);
                        Sleep(3000);
                        cuadradoAscii(45,19,78,20,32); // BORRA EL ANTERIOR TEXTO INGRESADO
                    }
                }
                while(flag != 0);

                do
                {
                    limpiarArregloChar(usuario.email);
                    cuadradoAscii(85,11,89,33,32); // BORRA EL SELECTOR
                    cuadradoAscii(48,21,78,22,32); // BORRA EL ANTERIOR TEXTO INGRESADO
                    selector(85,21);
                    cargarDato(usuario.email,48,21);
                    aniBotonEmail(27,20);
                    flag = verificarEmail(usuario.email);
                    if(flag == 1)
                    {
                        gotoxy(45,24);
                        printf("%sprintf(%cTe copiaste de otro...%c);%s",ROJO,34,34,NORMAL);
                        Sleep(3000);
                        cuadradoAscii(45,24,78,25,32); // BORRA EL ANTERIOR TEXTO INGRESADO
                    }
                }
                while(flag != 0);

                cuadradoAscii(85,11,89,33,32);
                selector(85,26);
                cargarDatoPass(usuario.contrasenia,48,26);
                aniBotonPass(27,25);


                cuadradoAscii(85,11,89,33,32);
                selector(85,31);
                cargarDatoPass(passTemporal,48,31);
                aniBotonConfirmaContrasenia(27,30);

                usuario.habilitado = true;
                nombreArchivoPersonajes(&usuario);

                while(strcmpi(passTemporal,usuario.contrasenia) != 0)
                {
                    limpiarArregloChar(passTemporal);
                    gotoxy(15,37);
                    printf("%sprintf(%cAcabas de escribir la Contrasenia, se ve que te la olvidaste, Vuelve a Intentar...%c);%s",ROJO,34,34,NORMAL);
                    Sleep(2000);
                    selector(85,31);
                    dibujarLinea(2,37,115,32);
                    cuadradoAscii(85,11,89,33,32);
                    cargarDatoPass(passTemporal,48,31);
                    aniBotonConfirmaContrasenia(27,30);
                }
            }
            if(tecla == E)
            {
                aniBotonEditar(95,30);
                editarIngreso(&usuario);
                while(strcmpi(passTemporal,usuario.contrasenia) != 0)
                {
                    limpiarArregloChar(passTemporal);
                    gotoxy(15,37);
                    printf("%sprintf(%cAcabas de escribir la Contrasenia, se ve que te la olvidaste, Vuelve a Intentar...%c);%s",ROJO,34,34,NORMAL);
                    Sleep(2000);
                    selector(85,31);
                    dibujarLinea(2,37,115,32);
                    cuadradoAscii(85,11,89,33,32);
                    cargarDatoPass(passTemporal,48,31);
                    aniBotonConfirmaContrasenia(27,30);
                }
            }
            if(tecla == ENTER)
            {
                aniBotonEnter(95,10);
                usuario.id = asignarIdUsuario();
                agregarAlArchivoUsuarios(usuario,"lista_usuarios.bin");
                menuUsuario(usuario);
            }

            if(tecla == SALIR)
            {
                aniBotonSalir(2,1);
                tecla = menuInicioSesionSecundario(0);
            }
        }
    }
    return tecla;
}

void frontMenuComandoAdmin()
{
    system("cls");
    dibujarCuadro(0,0,119,39,CYAN); // principal
    dibujarCuadro(2,7,40,36,NORMAL); // seleccion
    dibujarCuadro(42,2,117,37,NORMAL); // todos datos usuario
    dibujarCuadro(44,4,86,35,MARRON); // solo datos usuario
    dibujarCuadro(88,4,115,11,MARRON); // datos personaje
    dibujarCuadro(88,18,115,31,MARRON); // recuadro personaje
    pintarPersonajeParado(96,20);
    marcosUsuarios();

    botonCargaDatos(47,5);
    gotoxy(48,5);printf("%sNombre Apellido:%s",NORMALSUB,NORMAL);
    botonCargaDatos(47,9);
    gotoxy(48,9);printf("%sNick:%s",NORMALSUB,NORMAL);
    botonCargaDatos(47,13);
    gotoxy(48,13);printf("%sEmail:%s",NORMALSUB,NORMAL);
    botonCargaDatos(47,17);
    gotoxy(48,17);printf("%sContrase%ca:%s",NORMALSUB,164,NORMAL);
    gotoxy(48,22);printf("%sHabilitado:%s",NORMALSUB,NORMAL);
    gotoxy(70,22);printf("%sPersonajes:%s",NORMALSUB,NORMAL);
    botonVacio(48,23);
    botonVacio(70,23);

    botonEditarUsuario(49,30);
    botonCambioEstado(71,30);
    botonSalir(2,1);
    flechaUp(18,1);
    flechaDown(30,1);
    flechaRight(106,12);
    flechaLeft(88,12);
    botonEditarPersonaje(89,32);
}

char menuComandoAdmin(char tecla, stUsuario admin)
{
    system("cls");
    frontMenuComandoAdmin();

    nodoUsuario * listaUsuarios;
    listaUsuarios = inicListaUsuarios();
    listaUsuarios = deListaArchivo(listaUsuarios);
    int cantidadElementos = contarElementos(listaUsuarios);
    stUsuario * arreglo = malloc(sizeof(stUsuario)*cantidadElementos);
    int posInicial = 0;
    int posFinal = 0;

    posFinal = pasarListaArreglo(listaUsuarios,arreglo,cantidadElementos,posInicial);




    int selectorUsuario = 1;
    movimientoSelectorUsuario(selectorUsuario);
    muestraUsuarioArregloSelector(selectorUsuario-1,arreglo);
    muestraArregloUsuarios(arreglo,cantidadElementos,5,9,posInicial,posFinal);

    int valor = 2;

    while(tecla != SALIR)
    {
        if(kbhit())
        {
            tecla = getch();

            if(tecla == ABAJO)
            {
                if(valor < cantidadElementos)
                {
                    if(selectorUsuario < 10 && valor < cantidadElementos)
                    {
                        aniBotonDown(30,1);
                        selectorUsuario++;
                        valor++;
                    }

                    if(selectorUsuario == 10)
                    {
                        borrarMuestraUsuarios();
                        marcosUsuarios();
                        selectorUsuario = 1;
                        posInicial = posFinal;
                        posFinal = pasarListaArreglo(listaUsuarios,arreglo,cantidadElementos,posInicial);
                        valor--;
                    }

                }
            }
            if(tecla == ARRIBA)
            {
                if(valor > 2)
                {
                    if(selectorUsuario > 0 && valor > 2)
                    {
                        aniBotonUp(18,1);
                        selectorUsuario--;
                        valor--;
                    }
                    if(selectorUsuario == 0)
                    {
                        borrarMuestraUsuarios();
                        marcosUsuarios();
                        selectorUsuario = 1;
                        posInicial -= 9;
                        if(posInicial <0)
                        {
                            posInicial = 0;
                        }
                        posFinal = pasarListaArreglo(listaUsuarios,arreglo,cantidadElementos,posInicial);
                        valor = (posInicial+2);
                    }
                }

            }
            if(tecla == ENTER)
            {

            }

            movimientoSelectorUsuario(selectorUsuario);
            muestraUsuarioArregloSelector(selectorUsuario-1,arreglo);
            muestraArregloUsuarios(arreglo,cantidadElementos,5,9,posInicial,posFinal);

        }
    }


    return tecla;
}

void frontMenuUsuario()
{
    system("cls");
    dibujarCuadro(0,0,119,39,CYAN); // principal
//    cuadradoAscii(1,1,119,39,219); //
    cuadradoConMarco(2,2,50,30,MARRON);
    cuadradoConMarco(52,2,117,20,MARRON);
    pintarPersonajeParado(80,4);
    flechaRight(95,10);
}

void menuUsuario(stUsuario usuario)
{
    frontMenuUsuario();

}







// FUNCIONES HERRAMIENTAS DE LOS MENUS

void cargarDato(char arreglo[],int x,int y)
{
    gotoxy(x,y);
    char tecla; // tecla apretada
    int i = 0; // iterador

    int posCursorX; // where devuelve la posicion de cursor en la consola en X
    int posCursorY = whereY(); // where devuelve la posicion de cursor en la consola en Y

    while((tecla = _getch()) != ENTER ) // Mientras la tecla obtenida sea diferente que enter segui.
    {

        posCursorX = whereX(); // donde esta ubicado el cuersor en X;

        if(tecla != CANCELAR && i < 30)
        {
            gotoxy(posCursorX,posCursorY); // el cursor se va posicionar en las posiciones anteriormente definidas
            arreglo[i] = tecla; // asigo la tecla obtenida al arreglo en la posicion del iterador
            printf("%c",tecla); // imprimo la tecla para verla
            i++; // iterador aumenta
        }
        else if(tecla == CANCELAR && i > 0) //si apreta la tecla la borrar texto
        {
            arreglo[i] = '\0';
            i--; // iterador se resta para que en el arreglo se pare en la posicon del borrado
            posCursorX--;
            gotoxy(posCursorX,posCursorY);
            printf(" "); //que se pare en la posicion -1 en x del cursor y imprime VACIO
            gotoxy(posCursorX,posCursorY); // que se posicione devuelta donde esta el borrado .
        }
    }
    arreglo[i] = '\0';
}

void cargarDatoPass(char arreglo[],int x,int y)
{
    gotoxy(x,y);
    char tecla; // tecla apretada
    int i = 0; // iterador

    int posCursorX; // where devuelve la posicion de cursor en la consola en X
    int posCursorY = whereY(); // where devuelve la posicion de cursor en la consola en Y

    while((tecla = _getch()) != ENTER ) // Mientras la tecla obtenida sea diferente que enter segui.
    {

        posCursorX = whereX(); // donde esta ubicado el cuersor en X;

        if(tecla != CANCELAR && posCursorX < 84 && i < 30)
        {
            gotoxy(posCursorX,posCursorY); // el cursor se va posicionar en las posiciones anteriormente definidas
            arreglo[i] = tecla; // asigo la tecla obtenida al arreglo en la posicion del iterador
            printf("%c",42); // imprimo la tecla para verla
            i++; // iterador aumenta
        }
        else if(tecla == CANCELAR && i > 0) //si apreta la tecla la borrar texto
        {
            arreglo[i] = '\0';
            i--; // iterador se resta para que en el arreglo se pare en la posicon del borrado
            posCursorX--;
            gotoxy(posCursorX,posCursorY);
            printf(" "); //que se pare en la posicion -1 en x del cursor y imprime VACIO
            gotoxy(posCursorX,posCursorY); // que se posicione devuelta donde esta el borrado .
        }
    }
    arreglo[i] = '\0';
}

void limpiarArregloChar(char arreglo[])
{
    for(int i = 0; i < 30; i++)
    {
        arreglo[i] = '\0';
    }
}

void imprimirSelector(int posicion)
{
    cuadradoAscii(85,11,89,33,32);
    if(posicion == 1)
    {
        selector(85,11);
    }
    if(posicion == 2)
    {
        selector(85,16);
    }
    if(posicion == 3)
    {
        selector(85,21);
    }
    if(posicion == 4)
    {
        selector(85,26);
    }

}

void selector(int x, int y)
{
    gotoxy(x,y);
    printf("%s%c%c%s%c%c%s ",ROJO,219,219,VERDE,219,219,NORMAL);
    gotoxy(x,y+1);
    printf("%s%c%c%s%c%c%s ",MARRON,219,219,AZUL,219,219,NORMAL);
}

void selectorUsuario(int x, int y,char color[])
{
    dibujarCuadro(x,y,x+36,y+3,color);
}



void movimientoSelectorUsuario(int posicion)
{
    switch(posicion)
    {
    case 1:
        marcosUsuarios();
        selectorUsuario(3,8,ROJO);
        break;
    case 2:
        marcosUsuarios();
        selectorUsuario(3,11,ROJO);
        break;
    case 3:
        marcosUsuarios();
        selectorUsuario(3,14,ROJO);
        break;
    case 4:
        marcosUsuarios();
        selectorUsuario(3,17,ROJO);
        break;
    case 5:
        marcosUsuarios();
        selectorUsuario(3,20,ROJO);
        break;
    case 6:
        marcosUsuarios();
        selectorUsuario(3,23,ROJO);
        break;
    case 7:
        marcosUsuarios();
        selectorUsuario(3,26,ROJO);
        break;
    case 8:
        marcosUsuarios();
        selectorUsuario(3,29,ROJO);
        break;
    case 9:
        marcosUsuarios();
        selectorUsuario(3,32,ROJO);
        break;

    }
}


void marcosUsuarios()
{
    selectorUsuario(3,8,MARRON);
    selectorUsuario(3,11,MARRON);
    selectorUsuario(3,14,MARRON);
    selectorUsuario(3,17,MARRON);
    selectorUsuario(3,20,MARRON);
    selectorUsuario(3,23,MARRON);
    selectorUsuario(3,26,MARRON);
    selectorUsuario(3,29,MARRON);
    selectorUsuario(3,32,MARRON);
}


void borrarMuestraUsuarios()
{
    cuadradoAscii(4,10,38,35,32);
}




















