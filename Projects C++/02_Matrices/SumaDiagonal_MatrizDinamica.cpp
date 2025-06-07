// Programa: SumaDiagonal_MatrizDinamica.cpp
// Crea una matriz dinámica de tamaño NxM, llena sus valores y calcula la suma de la diagonal principal.
// Demuestra uso de memoria dinámica bidimensional con punteros dobles.

#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

int main() {
    system("color 20");
    int i, j;
    double **matriz, Suma = 0.0;
    int N, M;

    cout << "\t Filas a agregar : " << endl;
    cin >> N;
    cout << "\t Columnas a agregar: " << endl;
    cin >> M;

    // Crear arreglo de punteros
    matriz = new(nothrow) double *[N];
    if (!matriz) {
        cout << "No hay memoria disponible." << endl;
        getch();
        exit(0);
    }

    // Crear cada fila
    for (i = 0; i < N; i++) {
        matriz[i] = new(nothrow) double[M];
        if (!matriz[i]) {
            cout << "No hay memoria disponible en fila " << i + 1 << endl;
            getch();
            exit(0);
        }
    }

    // Lectura de la matriz
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            cout << "Dato [ " << (i + 1) << " ] [ " << (j + 1) << " ] = ";
            cin >> matriz[i][j];
        }
    }

    cout << "\nMatriz ingresada:\n";
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++)
            cout << matriz[i][j] << "  ";
        cout << endl;
    }

    // Calcular la suma de la diagonal principal
    for (i = 0; i < N && i < M; i++) {
        Suma += matriz[i][i];
    }

    cout << "La suma de la diagonal es = " << Suma << endl;

    // Liberación de memoria
    for (i = 0; i < N; i++)
        delete[] matriz[i];
    delete[] matriz;

    system("pause");
    return 0;
}
