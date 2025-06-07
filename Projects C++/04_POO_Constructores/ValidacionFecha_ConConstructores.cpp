/*
Este programa en C++ define una clase Fecha 
que permite almacenar y validar fechas en formato día-mes-año. 
Utiliza tres tipos de constructores (por defecto, parametrizado y copia) y 
un destructor para mostrar la gestión de memoria dinámica. La clase incluye
 métodos para leer una fecha desde el usuario, mostrarla, y verificar si es 
 válida (rango de día, mes y año aceptables). El programa ejemplifica el uso de 
 objetos dinámicos y copiados en memoria.

*/

#include<stdlib.h>
#include<conio.h>
#include<iostream>
using namespace std;

class Fecha{
    private:
        int Dia, Mes, Anio,VFecha;
        char L;
    public:
        Fecha();
        Fecha(int _dia, int _mes,int _anio);
        Fecha( const Fecha &OBJcop);
        ~Fecha();
        int VERIFICAFECHA(int D,int M, int A);
        void Mostrar(void);
        void Leer(void);
};
    
int main(){
        Fecha *OBJ1= new Fecha;
        OBJ1->Leer();
        OBJ1->Mostrar();
        
        Fecha *OBJ2= new Fecha(13,3,2001);
        cout<<"\n---------Se ejecuta con parametros-----------\n";
        OBJ2->Mostrar();
        
        Fecha OBJcopia=(*OBJ2);
        cout<<"\n---------------Se ejecuta la copia-----------\n";
        OBJcopia.Mostrar();
        
        
      system("pause");
      delete OBJ1;
    	delete OBJ2;
      
      return 0;    
        }
        
Fecha::Fecha(){
	Dia=0;	Mes=0;	Anio=0;
}   

Fecha::Fecha(int _dia, int _mes,int _anio){
	Dia=_dia;	Mes=_mes;	Anio=_anio;
	
}   

Fecha::Fecha(const Fecha &OBJcop){
	Dia=OBJcop.Dia;	Mes=OBJcop.Mes;	Anio=OBJcop.Anio;
}   


Fecha::~Fecha(){
	
	cout<<"Liberando memoria\n";
	
	system("pause");
}  

 int Fecha::VERIFICAFECHA(int D,int M, int A){
    int R;
    if( (D>0 &&  D<32)&&(M>0 &&  M<13)&&(A>1000 &&  A<2100) )
        R=1;
    else
        R=0;
    return R;
  }   
  
  
void Fecha::Leer(){
	 cout<<"Introduce una fecha de la forma 01-01-2000 :\n";
                   cin>>Dia>>L>>Mes>>L>>Anio;
                   
}

void Fecha::Mostrar(){
	VFecha = VERIFICAFECHA(Dia,Mes,Anio); 
                   if(VFecha==1){
				   cout<<"Fecha correcta\n";
                   cout<<""<<Dia<<"-"<<Mes<<"-"<<Anio<<endl;
                   }else  cout<<"Fecha incorrecta\n";
} 


