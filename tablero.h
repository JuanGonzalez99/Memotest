////#############################################################################
// ARCHIVO             : tablero.h
// AUTOR               : Javier Pereyra / Juan Gonzalez
// FECHA DE CREACION   : 15/06/2018.
// ULTIMA ACTUALIZACION: 30/06/2018.
// LICENCIA : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux (Ubuntu) / Windows 10.
// IDE                 : Code::Blocks - 17.12
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
//          Este encabezado se utiliza para la declaración de la tabla que se
//          requiere para el Memotest, y de la estructura "Pieza", de la cual
//          estará compuesta la misma, al igual que las funciones que trabajen
//          con dicha tabla.
//
////////////////////////////////////////////////////////////////////////////////


#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED

// Defino estructura para la Matrix:
struct Pieza
{
    char symbol;
    bool mostrar;
};

Pieza tabla[8][8];

//*****************************************************************************
//                         DEFINICION DE LAS FUNCIONES
//=============================================================================
// FUNCION : void initMatriz(Pieza t[8][8])
// ACCION : Inicializa cada miembro de cada pieza que compone la matriz para
//          luego poder cargarla correctamente.
// PARAMETROS: Pieza t[8][8] -> Tabla de piezas que se utilizará en el juego.
// DEVUELVE : void --> nada, ya que trabaja sobre la variable que se le pasa por
//                     referencia.
//-----------------------------------------------------------------------------
void initMatriz(Pieza t[8][8])
{
    for(int y=0; y<8; y++)
    {
        for(int x=0; x<8; x++)
        {
            t[y][x].symbol='0';
            t[y][x].mostrar=false;
        }
    }
}

//=============================================================================
// FUNCION : void cargarMatriz(Pieza t[8][8], int dificultad).
// ACCION : Carga la matriz con letras en posiciones aleatorias para poder
//          comenzar el juego, utilizando la función random de la librería
//          CSYSTEM.
// PARAMETROS: Pieza t[8][8] -> Tabla de piezas que se utilizará en el juego.
//             int dificultad -> Entero que representa el nivel de dificultad
//                               elegido por el usuario.
//                               El máximo permitido es 8, ya que si se ingresa
//                               un número mayor el programa puede llegar a
//                               intentar acceder a memoria que no le pertenece,
//                               causando un malfuncionamiento del mismo.
// DEVUELVE : void --> nada, ya que trabaja sobre la variable que se le pasa por
//                     referencia.
//-----------------------------------------------------------------------------
void cargarMatriz(Pieza t[8][8], int dificultad)
{
    int f;
    int c;
    char vec[64] = {'a','a','b','b','c','c','d','d',
                    'e','e','f','f','g','g','h','h',
                    'i','i','j','j','k','k','l','l',
                    'm','m','n','n','o','o','p','p',
                    'q','q','r','r','s','s','t','t',
                    'v','v','w','w','x','x','y','y',
                    'z','z','A','A','B','B','C','C',
                    'D','D','E','E','F','F','G','G'
                   };
    int i = 0;


    while( i<(dificultad*dificultad) )
    {
        f = sys::random(dificultad);
        c = sys::random(dificultad);
        if ( t[f][c].symbol == '0')
        {
            t[f][c].symbol = vec[i];
            i++;
        }
    }
}

//=============================================================================
// FUNCION : void mostrarMatriz(Pieza t[8][8], int dificultad).
// ACCION : Muestra la tabla por pantalla, de una forma prolija y visualmente
//          agradable, indicando el valor de cada fila y columna.
// PARAMETROS: Pieza t[8][8] -> Tabla de piezas que se utilizará en el juego.
//             int dificultad -> Entero que representa el nivel de dificultad
//                               elegido por el usuario.
//                               El máximo permitido es 8, ya que si se ingresa
//                               un número mayor el programa puede llegar a
//                               intentar acceder a memoria que no le pertenece,
//                               causando un malfuncionamiento del mismo.
// DEVUELVE : void --> nada, ya que trabaja sobre la variable que se le pasa por
//                     referencia.
//-----------------------------------------------------------------------------
void mostrarMatriz(Pieza t[8][8], int dificultad)
{
    char numeros[]="12345678";
    cout << "  ";
    for(int l=0; l<dificultad; l++)
    {

        cout <<  "  C" << numeros[l];

    }

    cout << endl << "   ";
    for(int j=0; j<dificultad; j++)
    {
        cout << "----";
    }

    cout << endl;

    for(int f=0; f<dificultad; f++)
    {
        cout << "F" << f+1 << " |";
        for(int c=0; c<dificultad; c++)
        {
            if(t[f][c].mostrar)
            {
                cout<< " " << t[f][c].symbol<<" |";
            }
            else
            {
                cout << " ? |";
            }
        }

        cout <<  endl << "   ";
        for(int j=0; j<dificultad; j++)
        {
            cout << "----";
        }
        cout << endl;
    }
}


//=============================================================================
// FUNCION : void mostrarTodo(Pieza t[8][8], int dificultad).
// ACCION : Muestra la tabla por pantalla, de una forma prolija y visualmente
//          agradable, indicando el valor de cada fila y columna.
// PARAMETROS: Pieza t[8][8] -> Tabla de piezas que se utilizará en el juego.
//             int dificultad -> Entero que representa el nivel de dificultad
//                               elegido por el usuario.
//                               El máximo permitido es 8, ya que si se ingresa
//                               un número mayor el programa puede llegar a
//                               intentar acceder a memoria que no le pertenece,
//                               causando un malfuncionamiento del mismo.
// DEVUELVE : void --> nada, ya que trabaja sobre la variable que se le pasa por
//                     referencia.
//-----------------------------------------------------------------------------
void mostrarTodo(Pieza t[8][8], int dificultad)
{
    char numeros[]="12345678";
    cout << "  ";
    for(int l=0; l<dificultad; l++)
    {
        cout << "  C" << numeros[l];
    }

    cout << endl << "   ";
    for(int j=0; j<dificultad; j++)
    {
        cout << "----";
    }

    cout << endl;

    for(int f=0; f<dificultad; f++)
    {
        cout << "F" << f+1 << " |";
        for(int c=0; c<dificultad; c++)
        {

            cout<< " " << t[f][c].symbol<<" |";

        }

        cout << endl << "   ";
        for(int j=0; j<dificultad; j++)
        {
            cout << "----";
        }
        cout << endl;
    }
}

bool gano(Pieza t[8][8], int dificultad)
{
    for(int y=0; y<dificultad; y++)
    {
        for(int x=0; x<dificultad; x++)
        {
            if( t[y][x].mostrar == false )
                return false;
        }
    }
    return true;
}

#endif // TABLERO_H_INCLUDED
