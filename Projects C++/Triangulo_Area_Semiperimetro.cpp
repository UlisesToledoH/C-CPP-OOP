// Programa: Triangulo_Area_Semiperimetro.cpp
// Calcula el semiperímetro y área de un triángulo con el teorema de Herón usando POO.
// Incluye dos constructores, verificación de validez, lectura y liberación de memoria.


#include <iostream>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
using namespace std;
class Triangulo
{
private:
    float S,A,a,b,c;
public:
    Triangulo(float _a, float _b, float _c);
    Triangulo();
    ~Triangulo();
    void Leer();
    void Mostrar();
    void Verificar();
    float Semiperimetro();
    float Area();
};

int main()
{
    Triangulo Obj1;//constructor 1
    Obj1.Leer();
    Obj1.Verificar();
    Obj1.Mostrar();
    
    float _a,_b,_c;
    Triangulo Obj2(_a,_b,_c);//constructor 2
    Obj2.Leer();
    Obj2.Verificar();
    Obj2.Mostrar();
    system("pause");

    return 0;
}
 void Triangulo::Verificar()
 {
     if(a+b>c)
     {
        if(b+c>a)
            if(a+c>b){
                cout<<"Es un triangulo\n";
                Semiperimetro();
                Area();}
     }
     else {cout<<"No es un triangulo\n";
            }
 }
    float Triangulo::Semiperimetro(){
        S=(a+b+c)/2;
        return (S);
    }
    float Triangulo::Area(){
        A=sqrt(S*(S-a)*(S-b)*(S-c));
        return(A);
    }
    void Triangulo::Leer(){
        cout<<"Introduzca el lado a\n"; cin>>a;
        cout<<"Introduzca el lado b\n"; cin>>b;
        cout<<"Introduzca el lado c\n"; cin>>c;

    }
    void Triangulo::Mostrar(){
        cout<<"S = "<<S<<endl;
        cout<<"\n";
        cout<<"A = "<<A<<"\n"<<endl;
    }
	
	Triangulo::~Triangulo(){
        cout<<"Liberando memoria.\n";
        system("pause");
    }
	Triangulo::Triangulo(){
	        a=0; b=0; c=0;
	    }
    
    Triangulo::Triangulo(float _a, float _b, float _c){
	a=_a;
	b=_b;
	c=_c;

}
	
    
   
