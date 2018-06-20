////#############################################################################
// ARCHIVO             : tablero.h
// AUTOR               : Javier Pereyra / Juan Gonzalez
// FECHA DE CREACION   : 15/06/2018.
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


#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED
// Constantes Universales
const int Y = 8;
const int X = 8;


// Defino estructura para la Matrix:
struct Pieza
{
    char symbol;
    bool mostrar;
};

Pieza tabla[Y][X];


void initMatriz(Pieza t[8][8])
{
    for(int y=0;y<8;y++)
    {
        for(int x=0;x<8;x++)
        {
            t[y][x].symbol='0';
            t[y][x].mostrar=false;
        }
    }
}

//=============================================================================
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
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
// FUNCION : tipo nombre(lista de parametros)
// ACCION : explicar brevemente que es lo que hace la funcion y como.
// PARAMETROS: lista de parametros (uno por linea donde se indique: tipo, nombre,
// que representa, y valores posibles si existieran limitaciones).
// DEVUELVE : tipo --> explicacion si representa algo.
//-----------------------------------------------------------------------------
void mostrarMatriz(Pieza t[8][8], int dificultad)
{
    char letras[]="ABCDEFGH";
    cout << "  ";
    for(int l=0; l<dificultad; l++)
    {
        cout << "  " << letras[l] << " ";
    }

    cout << endl << "  ";
    for(int j=0; j<dificultad; j++)
    {
        cout << "----";
    }

    cout << endl;

    for(int f=0; f<dificultad; f++)
    {
        cout << f+1 << " |";
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

        cout << endl << "  ";
        for(int j=0; j<dificultad; j++)
        {
            cout << "----";
        }

        cout << endl;
    }
}


#endif // TABLERO_H_INCLUDED
