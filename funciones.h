////#############################################################################
// ARCHIVO             : funciones.h
// AUTOR               : Javier Pereyra / Juan Gonzalez
// FECHA DE CREACION   : 08/06/2018.
// ULTIMA ACTUALIZACION: 30/06/2018.
// LICENCIA : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux (Ubuntu) / Windows 10.
// IDE                 : Code::Blocks - 17.12
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
//          Acá se crean funciones auxiliares que se utilizarán a lo largo
//          del programa.
//
////////////////////////////////////////////////////////////////////////////////


#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <string.h>

using namespace std;

//*****************************************************************************
//                         DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : void pedirEnter().
// ACCION : Pide un enter al usuario mediante el uso de una cadena auxiliar y
//          la función getline de la librería CSYSTEM, para que, en el caso de
//          que el usuario ingrese accidentalmente un caracter, no se rompa
//          el programa.
// PARAMETROS: -.
// DEVUELVE : void --> nada, ya que solo se desea pedir un enter al usuario.
//-----------------------------------------------------------------------------
void pedirEnter()
{
    char enter[2];
    cout<<"\n\n\n(Presione enter para continuar)"<<endl;
    sys::getline(enter,2);
}

//=============================================================================
// FUNCION : bool salida().
// ACCION : Pregunta al usuario si esta seguro que desea salir.
// PARAMETROS: -.
// DEVUELVE : bool --> Devuelve true si el usuario quiere salir, caso contrario
//                     devuelve false.
//-----------------------------------------------------------------------------
bool salida()
{
    char validar[2];
    cout<<"Estas seguro?"<<endl;
    cout<<"Presione 's' + enter para salir: ";
    sys::getline(validar,2);

    if(strlen(validar) == 1 && (validar[0] == 's' || validar[0] == 'S'))
        return true; // Dejas el vicio.
    else
        return false; // Seguis con el vicio.
}

#endif // FUNCIONES_H_INCLUDED
