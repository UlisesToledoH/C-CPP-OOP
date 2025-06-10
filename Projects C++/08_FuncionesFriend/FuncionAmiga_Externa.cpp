// Programa: FuncionAmiga_Externa.cpp
// Ejemplo simple de función amiga externa que accede a un miembro privado de una clase.
// La función `Ver` accede directamente a la variable privada `a` de la clase `A`.
// Se contrasta con el uso del método público `A::Ver()` para demostrar equivalencia. TOLEDO
#include <iostream>
#include <stdlib.h>
using namespace std;
class A { 
 private:
    int a;
    friend void Ver(A); // "Ver" es amiga de la clase A

  public:
    A(int i=0) {a = i;}   // constructor 
    void Ver() {cout << a << endl;}
};
 
void Ver(A Xa)
{
   // La funci�n Ver puede acceder a miembros privados
   // de la clase A, ya que ha sido declarada "amiga" de A
   cout << Xa.a << endl;
}

int main( )
{
   A Na(10);
   Ver(Na);  // Ver el valor de Na.a
   Na.Ver(); // Equivalente a la anterior
   system("PAUSE");  
   return 0;
}
