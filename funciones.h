////#############################################################################
// ARCHIVO             : funciones.h
// AUTOR               : Javier Pereyra / Juan Gonzalez
// FECHA DE CREACION   : 08/06/2018.
// ULTIMA ACTUALIZACION: 20/06/2018.
// LICENCIA : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux (Ubuntu) / Windows 10.
// IDE                 : Code::Blocks - 17.12
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
//          Ac� se crean funciones auxiliares que se utilizar�n a lo largo
//          del programa.
//
////////////////////////////////////////////////////////////////////////////////


#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


using namespace std;

//*****************************************************************************
//                         DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : bool validarEntero(char *c).
// ACCION : Recorre la cadena de caracteres pasada por par�metro para verificar
//          si la misma se compone s�lo de n�meros o no, mediante un for que
//          analiza caracter por caracter, validando que su valor, en la tabla
//          ASCII corresponda a la representaci�n de un n�mero.
// PARAMETROS: char* c -> Cadena de caracteres, no tiene restricciones.
// DEVUELVE : bool --> Si devuelve verdadero, la cadena pasada por par�metro
//                     est� compuesta �nicamente de n�meros.
//                     Caso contrario, la cadena contiene uno o m�s caracteres
//                     que no son num�ricos.
//-----------------------------------------------------------------------------
bool validarEntero(char* c)
{
    bool esEntero = true;

    for(int x=0; c[x]!='\0'; x++)
    {
        if( c[x] < '0' || c[x] > '9' )
        {
            esEntero = false;
        }
    }
    return esEntero;

}

//=============================================================================
// FUNCION : void pedirEnter().
// ACCION : Pide un enter al usuario mediante el uso de una cadena auxiliar y
//          la funci�n getline de la librer�a CSYSTEM, para que, en el caso de
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

#endif // FUNCIONES_H_INCLUDED
