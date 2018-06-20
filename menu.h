////#############################################################################
// ARCHIVO             : menu.h
// AUTOR               : Javier Pereyra / Juan Gonzalez
// FECHA DE CREACION   : 08/06/2018.
// ULTIMA ACTUALIZACION: 20/06/2018.
// LICENCIA : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux (Ubuntu) / Windows 10.
// IDE                 : Code::Blocks - 17.12 / 10.05
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
//              Breve explicacion sobre el contenido del archivo.
//
////////////////////////////////////////////////////////////////////////////////


#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "funciones.h"
#include "tablero.h"
#include <string.h>

using namespace std;



//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
void bienvenida()
{
    cout<<"Juga este jueguito, que ta bueno"<<endl;
    pedirEnter();
}

//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
void menuPrincipal()
{
    sys::cls();
    cout<<"1. Jugar"<<endl;
    cout<<"2. Ayuda"<<endl;
    cout<<"3. Salir"<<endl;
    cout<<"Insert Coin."<<endl;
}

void menuDificultades();
void menuAyuda();

//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
void menu()
{
    char opcion[2];
    bool salir= false;
    while(!salir)
    {
        menuPrincipal();
        cout<<"Ingresa una opción: ";
        sys::getline(opcion,2);
        //Validacion de entrada. ( Solo ingreso de uno, dos y tres ).
        while(!validarEntero(opcion) || strlen(opcion)!=1 || opcion[0] < '1' || opcion[0] > '3')
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
        }break;
        case '2':
        {
            menuAyuda();
        }break;
        case '3':
        {
            salir = true;
            cout<<"Salida:Exit:Ausfahrt:Sortie:123...."<<endl;
        }break;

        } // FIn Switch.
        pedirEnter();
    } // Fin while

}

void juego(int);



void menuDificultades()
{
    int dificultad;
    bool salir = false;
    char op[2];
    while(!salir)
    {
        sys::cls();
        cout<<"1. Facil"<<endl;
        cout<<"2. Mediano"<<endl;
        cout<<"3. Dificil"<<endl;
        cout<<"4. Volver"<<endl;
        cout<<endl;
        cout<<"Ingrese una opcion: ";
        sys::getline(op,2);
        while(!validarEntero(op) || strlen(op)!=1 || op[0] < '1' || op[0] > '4')
        {
            cout<<"No te hagas el loco devuelta."<<endl;
            sys::getline(op,2);
        }
        sys::cls();
        switch(op[0]){
    case '1':
        {
            dificultad = 4;
        }break;
    case '2':
        {
            dificultad = 6;
        }break;
    case '3':
        {
            dificultad = 8;
        }break;
    case '4':
        {
            cout<<"No te anima juga? dale que vaaaaa...."<<endl;
            salir = true;
            continue;
        }break;

        } // Fin Switch.

        juego(dificultad);

        pedirEnter();
    } // Fin While.

}


void juego(int dificultad)
{
    initMatriz(tabla);
    cargarMatriz(tabla, dificultad);
    bool finJuego=false;
    int movimientos=4;
    char op1[2];
    char op2[2];
    char op1_2[2];
    char op2_2[2];
    while(!finJuego)
    {
        sys::cls();
        cout << "Movimientos restantes: " << movimientos << endl;
        cout << "Flash: F" << endl;
        cout << "Salir: S" << endl << endl;
        mostrarMatriz(tabla, dificultad);
        cout << endl << "Ingrese fila o una de las opciones: ";
        sys::getline(op1, 2);
        if(strlen(op1) == 1 && (op1[0] == 'f' || op1[0] == 'F'))
        {
           // funcFlash();
            continue;
        }
        cout << endl << "Ingrese columna o una de las opciones: ";
        sys::getline(op2, 2);


        if( ((strlen(op1)==1) && (op1[0]=='S' || op1[0]=='s')) || (strlen(op2)==1 && (op2[0]=='S' || op2[0]=='S')) )
        {
            finJuego=true;
            continue;
        }

        if( strlen(op1)!= 1 || strlen(op2)!=1 )
        {
            cout << "Deja de hacerte el loco man";
            pedirEnter();
            continue;
        }

    }   // Fin While.
}


void menuAyuda()
{
    cout<<"=================================== AYUDA ====================================="<<endl;
    cout<<"Memotest: Se trata de un jueguito loco en donde usted debe encontrar"<<endl;
    cout<<"los pares de fichas iguales que se hallan en el tablero, segun la dificultad"<<endl;
    cout<<"Facil: 4x4"<<endl;
    cout<<"Mediano: 6x6"<<endl;
    cout<<"Dificil: 8x8"<<endl;
    cout<<endl;
    cout<<"Para jugar debe seleccionar las fichas que quiere dar vuelta"<<endl;
    cout<<"ingresando sus coordenadas ( Fila y Columna )"<<endl;
    cout<<endl;
    cout<<"Ademas, usted posee otras opciones: "<<endl;
    cout<<"Flash ( F ): Muestra todas las fichas durante un breve periodo de tiempo"<<endl;
    cout<<"Salir ( S ): Regresa al menu de seleccion de dificultad"<<endl;
    cout<<"(nota: Para salir del juego correctamente debe presionar primero la tecla 's' y"<<endl;
    cout<<"luego otra 's' o nada - recuerde presionar enter luego de cada ingreso -)"<<endl;
}


//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
void despedida()
{
    cout<<"Chau."<<endl;
}






#endif // MENU_H_INCLUDED
