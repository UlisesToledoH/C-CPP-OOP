// Programa: AreaTriangulo_Heron_POO.cpp
// Calcula el área de un triángulo con el teorema de Herón usando POO en C++.
// Verifica que los lados formen un triángulo válido, solicita datos al usuario y muestra el resultado.

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class Coordenadas {
private:
    float a, b, c;
    int band;

public:
    Coordenadas();      
    Coordenadas(float _a, float _b, float _c); 
    Coordenadas(const Coordenadas &OBJcop);
    ~Coordenadas();

    void AsignaCoordenadas(float p, float q, float t);
    void Lee_abc();
    int VerifTriang();
    float Reta();
    float Retb();
    float Retc();
};

class Triangulos {
private:
    Coordenadas lados;
    float semi;
    float area;

public:
    void Leer();
    void SemiPer();
    void AreaT();
    void ResArea();
};

// Implementación clase Coordenadas
Coordenadas::Coordenadas() {
    a = b = c = 0.0;
    band = 0;
}

Coordenadas::Coordenadas(float _a, float _b, float _c) {
    a = _a;
    b = _b;
    c = _c;
    band = 0;
}

Coordenadas::Coordenadas(const Coordenadas &OBJcop) {
    a = OBJcop.a;
    b = OBJcop.b;
    c = OBJcop.c;
    band = OBJcop.band;
}

Coordenadas::~Coordenadas() {
    cout << "Liberando memoria de objetos\n";
}

void Coordenadas::AsignaCoordenadas(float p, float q, float t) {
    a = p;
    b = q;
    c = t;
}

int Coordenadas::VerifTriang() {
    if ((a + b > c) && (a + c > b) && (b + c > a))
        band = 0;
    else
        band = 1;
    return band;
}

void Coordenadas::Lee_abc() {
    do {
        cout << "\n\tTeorema de Heron\n";
        cout << "Ingrese el valor de a: "; cin >> a;
        cout << "Ingrese el valor de b: "; cin >> b;
        cout << "Ingrese el valor de c: "; cin >> c;
        if (VerifTriang())
            cout << "Los lados ingresados no forman un triángulo válido. Intenta nuevamente.\n";
    } while (VerifTriang());
}

float Coordenadas::Reta() { return a; }
float Coordenadas::Retb() { return b; }
float Coordenadas::Retc() { return c; }

// Implementación clase Triangulos
void Triangulos::Leer() {
    lados.Lee_abc();
}

void Triangulos::SemiPer() {
    semi = (lados.Reta() + lados.Retb() + lados.Retc()) / 2.0;
}

void Triangulos::AreaT() {
    area = sqrt(semi * (semi - lados.Reta()) * (semi - lados.Retb()) * (semi - lados.Retc()));
}

void Triangulos::ResArea() {
    cout << "\nEl área del triángulo es = " << area << endl;
}

// Función principal
int main() {
    Triangulos obj;
    obj.Leer();
    obj.SemiPer();
    obj.AreaT();
    obj.ResArea();

    system("pause");
    return 0;
}
