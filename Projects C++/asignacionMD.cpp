// Asignacion de memoria dinamica

#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

class MATRIZ
{

private:
    int i, j, bandera, N, M, OPC;
    double **MTZ1;

public:
    MATRIZ();
    MATRIZ(int _N, int _M);
    MATRIZ(const MATRIZ &OBJcop);
    ~MATRIZ();
    void Leer();
    void Mostrar();
    void Menu();
};

int main()
{

    MATRIZ *OBJ1 = new MATRIZ; // c1
    OBJ1->Menu();

    //Segunda forma de usar el programa
    // MATRIZ OBJ3(2, 2);
    // OBJ3.Menu();

    system("pause");
    
    delete OBJ1;
   
    return 0;
}

void MATRIZ::Menu()
{

    do
    {
        cout << "\tB I E N V E N I D O\n";
        cout << "1. Entrar al programa\n";
        cout << "2. S A L I D A\n";
        cout << "Ingrese la opcion: ";
        cin >> OPC;

        switch (OPC)
        {
        case 1:
            Leer();
            Mostrar();
            system("cls");
            break;
        case 2:
            cout << "Gracias por usar mi menu\n";
            break;
        }

    } while (OPC != 2);
}

MATRIZ::MATRIZ()
{ // MEMORIA DINAMICA   //falta Bandera

    bandera = 0;

    cout << "\t Numero de filas: " << endl;
    cin >> N;
    cout << "\t Numero de columnas: " << endl;
    cin >> M;

    MTZ1 = new double *[N];
    for (i = 0; i < N; i++)
        MTZ1[i] = new double[M];

    if (MTZ1 == NULL)
    {
        cout << " No hay M.D." << endl;
        getch();
        exit(0);
    }
}

MATRIZ::MATRIZ(int _N, int _M)
{

    N = _N;
    M = _M;

    MTZ1 = new double *[N];
    for (i = 0; i < N; i++)
        MTZ1[i] = new double[M];

    if (MTZ1 == NULL)
    {
        cout << " No hay M.D." << endl;
        getch();
        exit(0);
    }
}

MATRIZ::MATRIZ(const MATRIZ &OBJcop)
{
    N = OBJcop.N;
    M = OBJcop.M;

    MTZ1 = new double *[N];
    for (i = 0; i < N; i++)
        MTZ1[i] = new double[M];

    if (MTZ1 == NULL)
    {
        cout << " No hay M.D." << endl;
        getch();
        exit(0);
    }
}

MATRIZ::~MATRIZ()
{
    for (i = 0; i < N; i++)
        delete[] MTZ1[i];
    delete[] MTZ1;
}

void MATRIZ::Leer()
{
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            cout << "Dato [ " << (i + 1) << "] [" << (j + 1) << " ] = " << endl;
            cin >> MTZ1[i][j];
        }
        cout << endl;
    }
}

void MATRIZ::Mostrar()
{

    i = 0;
    while (i < N)
    {
        j = 0;
        while (j < N)
        {
            if ((i = j) && (MTZ1[i][j] == 0))
            {
                bandera = 1;
                break;
            }
            j++;
        }
        i++;
    }
    if (bandera == 1)
        cout << "No se puede aplicar el metodo" << endl;
    else
        cout << "Si se puede realizar el metodo " << endl;
    getch();
}
