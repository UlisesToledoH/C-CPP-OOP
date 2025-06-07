// Programa: DistanciaEntrePuntos_ClaseAmiga.cpp
// Este programa define una clase Punto con coordenadas (x, y) y un constructor parametrizado.
// Muestra cómo calcular la distancia entre dos puntos usando una función `friend`.
// La función `distancia` accede directamente a los miembros privados de los objetos Punto sin usar métodos públicos.
// El programa ilustra el uso de funciones amigas (friend functions) en C++ y cómo acceder a datos privados desde fuera de la clase.

# include <iostream>
# include <conio.h>
# include <math.h>
using namespace std;
class Punto
{  private :
           float x;
           float y;
   public :
             Punto ( float a, float b );//C2
        void visualizar ( );
friend float distancia( Punto p1, Punto p2);
} ;
int main(){
    Punto OBJ1(11,22),OBJ2(25,28);  // ejecuta al C2 dos veces
    OBJ1.visualizar();
    OBJ2.visualizar();
    cout<<"Resultado distancia = "<<distancia(OBJ1,OBJ2)<<endl;
    system("pause");    return 0;
 }
Punto::Punto ( float a, float b ){  x=a ; y=b;}
void Punto::visualizar ( ){ 
    cout<<"x="<<x<<endl;
    cout<<"y="<<y<<endl;  }

float distancia ( Punto p1, Punto p2)
{ float d;
d= sqrt( pow(p2.x-p1.x,2)+pow(p2.y - p1.y,2) );
return d;
}
