// Programa: SumaVectores_MemoriaDinamica.cpp
// Genera tres vectores con memoria dinámica. Lee dos vectores desde teclado, los suma elemento a elemento
// y muestra el resultado en un tercer vector. Demuestra uso de punteros y memoria dinámica.

#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;

void LeeVector(float *vec, int tam);
void VerVector(float *vec, int tam);

int main() {
    float *vector1, *vector2, *vectorT;
    int tam;

    cout << "Indica cuantos datos quieres en el Vector1 = ";
    cin >> tam;

    vector1 = new float[tam];
    vector2 = new float[tam];
    vectorT = new float[tam];

    // Lectura de los dos vectores
    LeeVector(vector1, tam);
    LeeVector(vector2, tam);

    // Cálculo de la suma de dos vectores
    for (int i = 0; i < tam; i++)
        vectorT[i] = vector1[i] + vector2[i];

    cout << "\nVector1 + Vector2 = VectorT\n";
    cout << "______________________________\n";
    for (int i = 0; i < tam; i++) {
        cout << "    " << vector1[i] << "    +     " << vector2[i]
             << "   =   " << vectorT[i] << endl;
        cout << "______________________________\n";
    }

    cout << "\nContenido de los vectores:\n";
    VerVector(vector1, tam);
    cout << "\n";
    VerVector(vector2, tam);
    cout << "\n";
    VerVector(vectorT, tam);

    cout << "\n\n";
    system("pause");

    // Liberación de memoria
    delete[] vector1;
    delete[] vector2;
    delete[] vectorT;

    return 0;
}

void LeeVector(float *vec, int tam) {
    for (int i = 0; i < tam; i++) {
        cout << "  Vector[" << i << "] = ";
        cin >> vec[i];
    }
}

void VerVector(float *vec, int tam) {
    for (int i = 0; i < tam; i++)
        cout << "  Vector[" << i << "] = " << vec[i] << endl;
}
