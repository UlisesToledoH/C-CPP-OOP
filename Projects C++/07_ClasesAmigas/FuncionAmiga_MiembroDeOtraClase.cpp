// Programa: FuncionAmiga_MiembroDeOtraClase.cpp
// Muestra cómo una función miembro (`EsMayor`) de una clase (`B`) puede ser amiga de otra clase (`A`).
// Permite a `B` acceder a miembros privados de `A` para realizar una comparación.
// Demuestra el uso de `friend` y relaciones cruzadas entre clases.
// funcio miembro EsMayor de la clase B es amiga de la clase A
 
#include <iostream.h>
#include <stdlib.h>

class A; // Declaraci�n previa (forward)
 
class B {   
private:
    int b;
 public:
    B(int i=0) {b = i;}
    void Ver() {cout <<"b = "<< b << endl;}
    bool EsMayor(A Xa);  // Compara b con a
}; 

class A {
   public:
          A(int i=0) {a = i;}
         void Ver() {cout <<"a = "<< a << endl;}
   private:
         // Funci�n amiga tiene acceso 
        // a miembros privados de la clase A
    friend bool B::EsMayor(A Xa); 
             int a;
};


bool B::EsMayor(A Xa) // A es mi clase, y Xa mi variable de mi constructor parametrizado
{
   return b > Xa.a;
}
int main( )
{
   A Na(10);
   B Nb(12);
   
   Na.Ver();
   Nb.Ver();            //         =      ==
   if(Nb.EsMayor(Na)) cout << "Nb es mayor que Na" << endl;
   else cout << "Nb no es mayor que Na" << endl;
   system("PAUSE");  
   return 0;
}


