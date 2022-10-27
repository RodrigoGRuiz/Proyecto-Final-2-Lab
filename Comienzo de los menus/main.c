#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define ENTER 13

#define ESCP 27


typedef struct
{
    char nombre[20];
    char contra[20];

} stUsuario;




int main()
{

    menuBienvenida();
//    ingresoParaAdmins();
}





int menuBienvenida()
{

    printf("\t");
    printf("\t");
    printf("BIENVENIDO A NUESTRO JUEGO, PORFAVOR PRESIONE ENTER PARA CONTINUAR... \n");

    int opc;
    do
    {

        if(kbhit())
        {
            opc = getch();

            if(opc == ENTER)
            {

//                system("cls");
                printf("PERFECTO QUE COMIENZE EL JUEGO /n");
                /*MENU DE INGRESO  REGISTRO*/
                system("cls");
                menuIngresoRegistro();
                break;
            }
            if(opc == ESCP)
            {

//                system("cls");
                printf("ADIOS MALDITO DESGRACIADO \n");

                break;

            }
        }

    }
    while(opc != ENTER || opc == ESCP);



    return 0;

}


void menuIngresoRegistro()
{

    loguin();
}



int loguin()
{

    printf("             SELECCIONE LA OPCION CON LA QUE DESEA CONTINUAR \n");
    printf("       ----------------------------------------------------------------- \n");
    printf("OPCION NUMERO 1: [INGRESAR] \n");
    printf("OPCION NUMERO 2 [INGRESAR COMO ADMIN]  \n");
    printf("OPCION NUMERO 3: [REGISTRARSE] \n");
    printf("PRESIONE ESCAPE PARA SALIR \n");


    int opc;
    do
    {

      if(kbhit())
      {
          fflush(stdin);
          opc = getch();

          if(opc == 49)
          {

            system("cls");
             printf("Tas ingresando");
             ingresarNormal();
            break;
          }
          if(opc == 50)
          {
            system("cls");
            printf("Bienvenido queridisimo administrador, maquina maqueavelica del mal, fiera, titan, mastodonte, creack \n");
            ingresoParaAdmins();
            break;
          }
          if(opc == 51)
          {

            system("cls");
            registro();
            break;
          }
          if(opc == ESCP)
          {
              break;
          }
      }


      }while(opc != ESCP);

    return 0;
}

void ingresarNormal()
{

    ///comprobar nombre usuario y contrasenia
    //Correcto\\

    primerMenu();

    //incorrecto\\

//    printf("intenttos fallidos \n");
    ///crear funcion de intentos fallidos


}


void ingresoParaAdmins()
{
    int si = 1;
    printf("SOS ADMIM? \n");

    char opc;
    fflush(stdin);
    scanf("%s", &opc);

    if(opc == 1)
    {
        printf("bien capo \n");
        printf("Decime la super clave secreta \n");
        /*capturar y verificar clave*/
        //Desplegar menu admins
    }
    else
    {
        printf("Que haces aca entonces?  \n");
    }

  segundoMenu();

}

void registro()
{

    printf("Usted esta ingresando a registrarse \n");
    ///pedir nombre y contrasenia que quiera tener
    //capturarlo y guardarlo
    /*pasar a un archivo*/


    ///Printf("movimiento completado")

    ///Devolver a inicio de sesion;

}


void primerMenu()                /*FUNCIONES QUE VAN DENTRO DEL USUARIO*/
{



    printf("                        SELECCIONE UNA OPCION PARA CONTINUAR \n");
    printf("----------------------------------------------------------------------------------------------------- \n");
    printf("OPCION 1: Edicion del Personaje \n");
    printf("OPCION 2: Ver mi Perfil \n");
    printf("OPCION 3: Darse de baja \n");
    printf("OPCION 4: Creacion de un personaje \n");
    printf("OPCION 5: Comenzar a  Jugar \n");
    printf("OPCION 6: Cerrrar sesion \n");
    printf("PRESIONE ESCAPE PARA SALIR");


    int opc;
    do
    {

        if(kbhit())
        {

            opc = getch();

            if(opc == 49)
            {

                system("cls");

            printf("Bienvenido a la edicion del personaje que cambios desea hacer? \n");
            /*Despliega menu de edicion del personaje*/

                break;


            }
            if(opc == 50)
            {


                 system("cls");

            printf("Bienvenido a tu perfil \n");
            /*Despliega vista del perfil*/
            /*conjunto a eso despliega la opcion de modificarlo*/

                break;

            }
            if(opc == 51)
            {

                 system("cls");

            printf("Usted esta seguro que quiere darse de baja? \n");
            /*Despliega funcion de darse de baja*/

                break;


            }
            if(opc == 52)
            {

                 system("cls");

            printf("Bienvenido a la creacion del personaje? \n");
            /*Despliega creacr personaje*/

                break;


            }
            if(opc == 53)
            {

                 system("cls");

            printf("YA ES HORA COMENZEMOS...? \n");
            sleep(500);
            /*Despliega comenzar a jugar*/

                break;



            }
            if(opc == 54)
            {

                 system("cls");

            printf("A RECUPERAR ENERGIAS, NOS VEMOS EN LA PROXIMA...? \n");
            /*Despliega menu de edicion del personaje*/

                break;


            }
            if(opc == ESCP)
            {
                break;
            }

        }

    }while(opc != '7');


}


void segundoMenu()                /*FUNCIONES QUE VAN DENTRO DE ADMINS*/
{


     printf("                        SELECCIONE UNA OPCION PARA CONTINUAR \n");
    printf("----------------------------------------------------------------------------------------------------- \n");
    printf("OPCION 1: VER LA LISTA DE LOS USUARIOS \n");
    printf("OPCION 2: DAR DE BAJA USUARIOS \n");
    printf("OPCION 3: DAR DE ALTA USUARIOS \n");
    printf("OPCION 4: VER LAS LISTAS DE PERSONAJES  \n");
    printf("OPCION 5: DAR DE BAJA UN PERSONAJE \n");
    printf("OPCION 6: DAR DE ALTA UN PERSONAJE \n");
    printf("PRESIONE ESCAPE PARA SALIR");


    int opc;
    do
    {

        if(kbhit())
        {

            opc = getch();

            if(opc == 49)
            {

                system("cls");

            printf("Bienvenido a la Lista de usuarios... \n");
            /*Despliega vista de las listas*/

                break;


            }
            if(opc == 50)
            {


                 system("cls");

            printf("dame el nombre del q vamos a fletar \n");
            /*despliega lista de usuarios y selecciona un nombre*/

                break;

            }
            if(opc == 51)
            {

                 system("cls");

            printf("A quien le vamos a dar otra oportunidad? \n");
            /*Despliega funcion de dar de alta y selecciona un  nombre*/

                break;


            }
            if(opc == 52)
            {

                 system("cls");

            printf("Veamos los personajes de quien? \n");
            /*Despliega verlista de personajes de tal persona*/

                break;


            }
            if(opc == 53)
            {

                 system("cls");

            printf("Adar de baja un personaje...? \n");
            sleep(500);
            /*Despliega comenzar a jugar*/

                break;



            }
            if(opc == 54)
            {

            printf("dar de alta un personaje..? \n");
                 system("cls");

            /*Despliega menu de edicion del personaje*/

                break;


            }
            if(opc == ESCP)
            {
                break;
            }

        }

    }while(opc != ESCP);

}












