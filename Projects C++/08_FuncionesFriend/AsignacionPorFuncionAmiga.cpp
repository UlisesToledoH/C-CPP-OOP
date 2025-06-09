// Programa: AsignacionPorFuncionAmiga.cpp
// Demuestra el uso de una función `friend` para asignar directamente valores a un miembro privado de una clase.
// La función `cargar()` modifica el atributo `datos` del objeto `cosa`.
// Útil para mostrar acceso controlado sin exponer atributos directamente.
# include <iostream>
# include <conio.h>
# include <math.h>
using namespace std;
class cosa
{   private:
               int datos;
    public:
              cosa(){   datos = 0;  }
              cosa(int d){   datos = d;  }
 friend void cargar (cosa& t, int x);
         void ver(){ cout<<"DATO= "<<datos<<endl;}
};

void cargar(cosa  &t, int x) // va a trabajar una asignacion 
{
t.datos=x; // el objeto t es privado pero a traves de un objeto esta accesando al contenido
}

int main( ){
               cosa OBJ1(3),OBJ2;
               OBJ1.ver();
               OBJ2.ver();  
               cargar(OBJ1, 222);
               OBJ1.ver();
               OBJ2.ver();
               cargar(OBJ2, 223);
               OBJ1.ver();
               OBJ2.ver();     
  system("pause"); 
   return 0;

}






