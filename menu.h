////#############################################################################
// ARCHIVO             : menu.h
// AUTOR               : Javier Pereyra / Juan Gonzalez
// FECHA DE CREACION   : 08/06/2018.
// ULTIMA ACTUALIZACION: 29/06/2018.
// LICENCIA : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux (Ubuntu) / Windows 10.
// IDE                 : Code::Blocks - 17.12
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
//          En este archivo se desarrollan todas las funciones relacionadas
//          con los menus, incluyendo la bienvenida y despedida del programa
//
////////////////////////////////////////////////////////////////////////////////



#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "funciones.h"
#include "tablero.h"
#include <string.h>

using namespace std;



//*****************************************************************************
//                         DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : void bienvenida().
// ACCION : En esta función se realiza el mensaje de bienvenida al programa.
// PARAMETROS: -.
// DEVUELVE : void --> nada, ya que solo muestran mensajes por pantalla.
//-----------------------------------------------------------------------------
void bienvenida()
{
    cout<<"Juga este jueguito, que ta bueno"<<endl;
    pedirEnter();
}

//=============================================================================
// FUNCION : void menu().
// ACCION : Esta función dispone las opciones del menu principal por pantalla.
// PARAMETROS: -.
// DEVUELVE : void --> nada, ya que su fin es mostrar texto por pantalla.
//-----------------------------------------------------------------------------
void menu()
{
    sys::cls();
    cout<<"1. Jugar"<<endl;
    cout<<"2. Ayuda"<<endl;
    cout<<"3. Salir"<<endl;
    cout<<endl;
}

void menuDificultades();
void menuAyuda();

//=============================================================================
// FUNCION : void menuPrincipal().
// ACCION : En esta función se encuentra el menú principal, en el cual se le
//          pide al usuario que elija la opción deseada, y la misma es validada
//          para impedir una posible corrupción del programa.
// PARAMETROS: -.
// DEVUELVE : void --> nada, ya que, en realidad, esta función fue creada para
//                     hacer el main más "limpio".
//-----------------------------------------------------------------------------
void menuPrincipal()
{
    char opcion[2];
    bool salir= false;
    while(!salir)
    {
        menu();
        cout<<"Ingresa una opcion: ";
        sys::getline(opcion,2);
        //Validacion de entrada. ( Solo ingreso de uno, dos y tres ).
        while(strlen(opcion)!=1 || opcion[0] < '1' || opcion[0] > '3')
        {
            cout<<"No te hagas el loco"<<endl;
            sys::getline(opcion,2);
        }

        //Limpiamos la pantallita.
        sys::cls();

        //Switch elemental.
        switch(opcion[0])
        {
        case '1':
        {
            menuDificultades();
        }
        break;
        case '2':
        {
            menuAyuda();
        }
        break;
        case '3':
        {


        //agregar la funcion de salida.
        if(salida() == true)
        {
            salir = true;
        }

        }
        break;

        } // Fin Switch.
        pedirEnter();
    } // Fin while

}

void juego(int);



//=============================================================================
// FUNCION : void menuDificultades().
// ACCION : Dispone un menú en el cual el usuario puede seleccionar un nivel de
//          dificultad, o puede volver al menú anterior, mediante el uso de un
//          while y un switch adentro del mismo, validando los ingresos del
//          usuario.
// PARAMETROS: -.
// DEVUELVE : void --> nada, ya que solo se desea saber el nivel de dificultad
//                     que desea el usuario, para lo cual no es necesario
//                     ningún tipo de retorno.
//-----------------------------------------------------------------------------
void menuDificultades()
{
    int dificultad;
    bool volver = false;
    char op[2];
    while(!volver)
    {
        sys::cls();
        cout<<"1. Facil"<<endl;
        cout<<"2. Mediano"<<endl;
        cout<<"3. Dificil"<<endl;
        cout<<"4. Volver"<<endl;
        cout<<endl;
        cout<<"Ingrese una opcion: ";
        sys::getline(op,2);
        while( strlen(op)!= 1 || op[0] < '1' || op[0] > '4')
        {
            cout<<"No te hagas el loco devuelta"<<endl;
            sys::getline(op,2);
        }
        sys::cls();
        switch(op[0])
        {
        case '1':
        {
            dificultad = 4;
        }
        break;
        case '2':
        {
            dificultad = 6;
        }
        break;
        case '3':
        {
            dificultad = 8;
        }
        break;
        case '4':
        {
            cout<<"Volviendo al menu anterior..."<<endl;
            volver = true;
            continue;
        }
        break;

        } // Fin Switch.

        juego(dificultad);

    } // Fin While.

}


//=============================================================================
// FUNCION : void juego(int dificultad).
// ACCION : Esta funcion resume todas las acciones necesarias para lograr el
//          correcto funcionamiento del juego.
// PARAMETROS: int dificultad -> Entero que representa el nivel de dificultad
//                               elegido por el usuario.
//                               El máximo permitido es 8, ya que si se ingresa
//                               un número mayor el programa puede llegar a
//                               intentar acceder a memoria que no le pertenece,
//                               causando un malfuncionamiento del mismo.
// DEVUELVE : void --> nada, ya que se utiliza para emprolijar el código.
//-----------------------------------------------------------------------------
void juego(int dificultad)
{
    //Inicializa la Matriz.
    initMatriz(tabla);

    //Realiza la Carga de la matriz de acuerdo a su nivel de dificultad.
    cargarMatriz(tabla, dificultad);

    //Variable Booleana para definir el fin del juego.
    bool finJuego=false;

    //Variable Booleana para definir la cantidad de veces que se usa la opcion Flash.
    bool usoFlash = 0;

    //Un booleano más, encima son dos ( Para validar si la ficha se puede o no usar ).
    bool ingreso1 = true;
    bool ingreso2 = true;

    //Variable entera para definir la cantidad de movimientos.
    int movimientos;

    //Transformo variables a enteros.
    int dat1, dat2, dat3, dat4;

    //Resguardamos contenido de la matriz.
//    int resguardo1 = 0;
//    int resguardo2 = 0;

    if ( dificultad == 4 )
        movimientos = 2;

    else if (dificultad == 6 )
        movimientos = 40;

    else
        movimientos = 60;

    char op1[2];
    char op2[2];
    char op3[2];
    char op4[2];

    while(!finJuego)
    {
        while(ingreso1)
        {
            sys::cls();
            mostrarMatriz(tabla, dificultad);
            cout <<endl;
            cout << "Movimientos restantes: " << movimientos << endl;
            cout << "Flash: F | Salir: S" << endl;
            cout << "-------------------"<<endl;
            cout << "- F = FILA        -"<<endl;
            cout << "- C = COLUMNA     -"<<endl;
            cout << "-------------------"<<endl;
            cout << endl << "Ingrese primera fila o una de las opciones: ";
            sys::getline(op1, 2);

            while( op1[0] < '1' || strlen(op1) != 1 || ( op1[0] > (char)dificultad+48  &&  !(op1[0] == 'S' || op1[0] == 's') && !(op1[0] == 'F' || op1[0] == 'f') ) )
            {
                cout<<"SYSTEM DENIED! ";
                sys::getline(op1,2);
            }

            if(op1[0] == 'S' || op1[0] == 's')
            {
                if(salida())
                {
                    finJuego = true;
                    break;
                }
                else
                {
                    cout << "decidite hermano";
                    pedirEnter();
                    continue;
                }
            }

            if(op1[0] == 'f' || op1[0] == 'F')
            {   //Valido si ya uso el FLASH.
                if ( usoFlash == 0)
                {
                    sys::cls();
                    mostrarTodo(tabla,dificultad);
                    sys::msleep(3);
                    usoFlash = 1;
                    continue;
                }
                else
                {
                    cout<<"Cuantas veces queres usarlo?"<<endl;
                    pedirEnter();
                    continue;
                }
            }

            sys::cls();
            mostrarMatriz(tabla, dificultad);
            cout <<endl;
            cout << "Movimientos restantes: " << movimientos << endl;
            cout << "Salir: S" << endl << endl;
            cout << endl << "Ingrese primer columna: ";
            sys::getline(op2, 2);
            while( strlen(op2) != 1 || ( op2[0] > (char)dificultad+48  &&  !(op2[0] == 'S' || op2[0] == 's') ) || op2[0] < '1' )
            {
                if( strlen(op2) == 1 && ( op2[0] == 'f' || op2[0] == 'F' ))
                    cout<<"No se puede usar el flash aca! Intente nuevamente: ";
                else
                    cout<<"Deja de hacerte el loco man" << endl;
                sys::getline(op2,2);
            }

            if(op2[0] == 'S' || op2[0] == 's')
            {
                if(salida())
                {
                    finJuego = true;
                    break;
                }
                else
                {
                    cout << "decidite hermano";
                    pedirEnter();
                    continue;
                }
            }

            dat1 = (int)op1[0]-48;
            dat2 = (int)op2[0]-48;
            if(tabla[dat1-1][dat2-1].mostrar == false)
            {
                tabla[dat1-1][dat2-1].mostrar = true;
                ingreso1 = false;
            }
            else
            {
                cout << " NOOOOOOOOOOOOOOOOOOOO!!!!!"<<endl;
                pedirEnter();
            }
        }

        if(finJuego)
            continue;

        //Fin de primero pedido ----------------------------------------------------------------------------------

        while(ingreso2)
        {

            sys::cls();
            mostrarMatriz(tabla, dificultad);
            cout <<endl;
            cout << "Movimientos restantes: " << movimientos << endl;
            cout << "Salir: S" << endl;
            cout << "-------------------"<<endl;
            cout << "- F = FILA        -"<<endl;
            cout << "- C = COLUMNA     -"<<endl;
            cout << "-------------------"<<endl;
            cout << endl << "Ingrese segunda fila o una de las opciones: ";
            sys::getline(op3, 2);

            while( strlen(op3) != 1 || ( op3[0] > (char)dificultad+48  &&  !(op3[0] == 'S' || op3[0] == 's')) || op3[0] < '1'  )
            {
                if( strlen(op3) == 1 && ( op3[0] == 'f' || op3[0] == 'F' ))
                    cout<<"No se puede usar el flash aca! Intente nuevamente: ";
                else
                    cout<<"SYSTEM DENIED! ";
                sys::getline(op3,2);
            }

            if(op3[0] == 'S' || op3[0] == 's')
            {
                if(salida())
                {
                    finJuego = true;
                    break;
                }
                else
                {
                    cout << "decidite hermano";
                    pedirEnter();
                    continue;
                }
            }

            if(op3[0] == 'f' || op3[0] == 'F')
            {   //Valido si ya uso el FLASH.
                if ( usoFlash == 0)
                {
                    sys::cls();
                    mostrarTodo(tabla,dificultad);
                    sys::msleep(3);
                    usoFlash = 1;
                    continue;
                }
                else
                {
                    cout<<"¿Cuantas veces queres usarlo?"<<endl;
                    pedirEnter();
                    continue;
                }
            }

            sys::cls();
            mostrarMatriz(tabla, dificultad);
            cout <<endl;
            cout << "Movimientos restantes: " << movimientos << endl;
            cout << "Salir: S" << endl << endl;
            cout << endl << "Ingrese segunda columna: ";
            sys::getline(op4, 2);
            while( strlen(op4) != 1 || ( op4[0] > (char)dificultad+48  &&  !(op4[0] == 'S' || op4[0] == 's') ) || op4[0] < '1' )
            {
                if( strlen(op4) == 1 && ( op4[0] == 'f' || op4[0] == 'F' ))
                    cout<<"No se puede usar el flash aca! Intente nuevamente: ";
                else
                    cout<<"Deja de hacerte el loco man" << endl;
                sys::getline(op4,2);
            }

            if(op4[0] == 'S' || op4[0] == 's')
            {
                if(salida())
                {
                    finJuego = true;
                    break;
                }
                else
                {
                    cout << "decidite hermano";
                    pedirEnter();
                    continue;
                }
            }

            dat3 = (int)op3[0]-48;
            dat4 = (int)op4[0]-48;
            if(tabla[dat3-1][dat4-1].mostrar == false)
            {
                tabla[dat3-1][dat4-1].mostrar = true;
                ingreso2 = false;
            }
            else
            {
                cout << " NOOOOOOOOOOOOOOOOOOOO!!!!!"<<endl;
                pedirEnter();
            }
        }

        //Fin de segundo pedido ----------------------------------------------------------------------------------


        if(finJuego)
            continue;

        //Comienza el juego ( begin )
        sys::cls();
        mostrarMatriz(tabla, dificultad);
        if ( tabla[dat1-1][dat2-1].symbol == tabla[dat3-1][dat4-1].symbol )
        {
            cout<<"FELICITACIONES"<<endl;
        }
        else
        {
            cout<<"NOOOOOO DEVUELTA MAL!!!"<<endl;
            tabla[dat1-1][dat2-1].mostrar = false;
            tabla[dat3-1][dat4-1].mostrar = false;
        }

        //Contamos cantidad de monedas disponibles para jugar ( Arcade mode ).
        movimientos--;

        pedirEnter();

        if(movimientos == 0)
        {
            cout<<"GAME OVER PAapapaaaaaaaaaaaaaaaaaaaaaa"<<endl;
            pedirEnter();
            break; // Salis del vicio.
        }
        ingreso1 = true;
        ingreso2 = true;



    }   // Fin While.
}



//=============================================================================
// FUNCION : void menuAyuda().
// ACCION : Muestra al usuario una breve descripción del juego y de sus comandos.
// PARAMETROS: -.
// DEVUELVE : void --> nada, ya que solo muestra texto por pantalla.
//-----------------------------------------------------------------------------
void menuAyuda()
{
    cout<<"=================================== AYUDA ====================================="<<endl;
    cout<<"Memotest: Se trata de un juego cuyo objetivo principal es encontrar los pares"<<endl;
    cout<<"de fichas iguales que se hallan en el tablero, segun la dificultad:"<<endl;
    cout<<"Facil: 4x4"<<endl;
    cout<<"Mediano: 6x6"<<endl;
    cout<<"Dificil: 8x8"<<endl;
    cout<<endl;
    cout<<"Para jugar debe seleccionar las fichas que quiere dar vuelta"<<endl;
    cout<<"ingresando sus coordenadas ( Fila y Columna )."<<endl;
    cout<<endl;
    cout<<"Ademas, usted posee otras opciones:"<<endl;
    cout<<"Flash ( F ): Muestra todas las fichas durante un breve periodo de tiempo (esta"<<endl;
    cout<<"             accion solo se puede realizar una vez por partida)."<<endl;
    cout<<"Salir ( S ): Regresa al menu de seleccion de dificultad en cualquier instancia"<<endl;
    cout<<"             de la partida."<<endl;
    cout<<"(Nota: Para salir del juego correctamente debe presionar primero la tecla 's' y"<<endl;
    cout<<"luego otra 's' o nada - recuerde presionar Enter luego de cada ingreso -)."<<endl;
}


//=============================================================================
// FUNCION : void despedida().
// ACCION : En esta función se realiza el mensaje de despedida del programa.
// PARAMETROS: -.
// DEVUELVE : void --> nada, ya que solo muestra mensajes por pantalla.
//-----------------------------------------------------------------------------
void despedida()
{
    cout<<"Hasta la proxima...,";
    pedirEnter();
}

#endif // MENU_H_INCLUDED
