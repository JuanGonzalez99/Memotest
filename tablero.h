#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED
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


#endif // TABLERO_H_INCLUDED
