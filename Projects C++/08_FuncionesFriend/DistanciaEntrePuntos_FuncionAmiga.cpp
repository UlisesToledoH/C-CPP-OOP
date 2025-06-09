// Programa: DistanciaEntrePuntos_FuncionAmiga.cpp
// Calcula la distancia entre dos puntos en el plano utilizando una función amiga `friend`.
// La clase `Punto` tiene atributos privados y permite acceso a través de la función `distancia`.
// Ejemplo claro y directo de encapsulamiento con funciones externas autorizadas.
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
Punto::Punto ( float a, float b )
{  
	x=a ; y=b;
}


void Punto::visualizar ( ){ 
    cout<<"x="<<x<<endl;
    cout<<"y="<<y<<endl;  }

float distancia ( Punto p1, Punto p2)
{ float d;
d= sqrt( pow(p2.x-p1.x,2)+pow(p2.y - p1.y,2) );
return d;
}
