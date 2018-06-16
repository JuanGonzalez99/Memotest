//#############################################################################
// ARCHIVO             : nombre de archivo.extension
// AUTOR/ES            : Javier Pereyra/ Juan Gonzalez
// VERSION             : 0.01 beta.
// FECHA DE CREACION   : 08/06/2018.
// ULTIMA ACTUALIZACION: 08/06/2018.
// LICENCIA            : GPL (General Public License) - Version 3.
//
//  **************************************************************************
//  * El software libre no es una cuestion economica sino una cuestion etica *
//  **************************************************************************
//
// Este programa es software libre;  puede redistribuirlo  o  modificarlo bajo
// los terminos de la Licencia Publica General de GNU  tal como se publica por
// la  Free Software Foundation;  ya sea la version 3 de la Licencia,  o (a su
// eleccion) cualquier version posterior.
//
// Este programa se distribuye con la esperanza  de que le sea util,  pero SIN
// NINGUNA  GARANTIA;  sin  incluso  la garantia implicita de MERCANTILIDAD  o
// IDONEIDAD PARA UN PROPOSITO PARTICULAR.
//
// Vea la Licencia Publica General GNU para mas detalles.
//
// Deberia haber recibido una copia de la Licencia Publica General de GNU junto
// con este proyecto, si no es asi, escriba a la Free Software Foundation, Inc,
// 59 Temple Place - Suite 330, Boston, MA 02111-1307, EE.UU.

//=============================================================================
// SISTEMA OPERATIVO   : Linux (Ubuntu) / Windows XP / Windows 7.
// IDE                 : Code::Blocks - 8.02 / 10.05
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
//              Breve explicacion sobre el contenido del archivo.
//
////////////////////////////////////////////////////////////////////////////////

//*****************************************************************************
//                       CONFIGURACION MULTIPLATAFORMA
//=============================================================================
// COMPILACION EN WINDOWS
//-----------------------------------------------------------------------------
// Si este programa se va a compilar en Windows, descomente las tres lineas
// siguientes, y comente las tres lineas de "COMPILACION EN LINUX".
//-----------------------------------------------------------------------------
//#ifndef _WIN32
//  # define _WIN32
//#endif

//=============================================================================
// COMPILACION EN LINUX
//-----------------------------------------------------------------------------
// Si este programa se va a compilar en Linux, descomente las tres lineas
// siguientes, y comente las tres lineas de "COMPILACION EN WINDOWS".
//-----------------------------------------------------------------------------
//#ifndef _LINUX
// # define _LINUX
//#endif

//=================CODIGO COSMICO MULTIPLATAFORMA=======================================//
// Con este codigo, vamos directo de windows a linux en un build //

#ifdef _WIN32
#define _WIN32
//define something for Windows (32-bit)
#elif __linux
#define _LINUX
// linux
#elif __unix // all unices not caught above
// Unix
#elif __posix
// POSIX
#endif

//*****************************************************************************
//                             INCLUSIONES ESTANDAR
//=============================================================================
#include <iostream> // Libreria de flujos de  Entrada/Salida  que contiene  los
// objetos cin, cout y endl.

#include <cstdlib>  // Libreria estandar que contiene la funcion exit().

//*****************************************************************************
//                             INCLUSIONES PERSONALES
//=============================================================================
#include "CSYSTEM/csystem.h" // Libreria para multiplataforma.
#include "menu.h"

//==============================================================================
// DECLARACION DEL ESPACIO DE NOMBRES POR DEFECTO
//------------------------------------------------------------------------------
using namespace std;
// Constantes Universales
const int Y = 8;
const int X = 8;


// Defino estructura para la Matrix:
struct Pieza
{
    char symbol = '?';
    bool mostrar = false;
};

Pieza tabla[Y][X];


void cargarMatriz(Pieza t[8][8])
{

    int f;
    int c;
    char vec[64] = {'a','a','b','b','c','c','d','d','e','e','f',
                    'f','g','g','h','h','i','i','j','j','k','k','l','l',
                    'm','m','n','n','o','o','p','p','q','q','r','r','s',
                    's','t','t','v','v','w','w','x','x','y','y','z','z',
                    'A','A','B','B','C','C','D','D','E','E','F',
                    'F','G','G'
                   };
    int i = 0;

//Very Difficult by Tevez.
    while( i<64 )
    {

        if ( t[4][6].symbol == '?')
        {

            t[4][6].symbol = vec[i];
            i++;

        }
    }
}

void mostrarMatriz(Pieza t[8][8])
{

for(int f=0;f<8;f++)
{


    for(int c=0;c<8;c++)
    {

    cout<<t[f][c].symbol<<" ";

    }


cout<<endl;

}



}

//==============================================================================
// FUNCION PRINCIPAL - PUNTO DE INICIO DEL PROYECTO
//------------------------------------------------------------------------------
int main()
{
    bienvenida();
    menu();
    despedida();
    //--------------------------------------------------------------------------
    // FIN DE LA FUNCION main() SIN ERRORES.
    //--------------------------------------------------------------------------
    return 0;
}

//=============================================================================
//                            FIN DE ARCHIVO
//#############################################################################

