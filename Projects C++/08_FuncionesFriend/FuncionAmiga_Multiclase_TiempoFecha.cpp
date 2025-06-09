// Programa: FuncionAmiga_Multiclase_TiempoFecha.cpp
// Combina información de dos clases (`TIME1` y `DATE1`) mediante una función amiga común `TIME_DATE`.
// Muestra cómo una misma función `friend` puede acceder a atributos privados de varias clases para generar una salida compuesta.
// También demuestra el uso de `sprintf` para formatear una cadena.
// funcion amiga de una clase

#include<conio.h>
#include<iostream>
using namespace std;
#define DP ':'
class DATE1;  // forward

class TIME1{
   private:
	   int hr, mn;
   public : 
       friend char *TIME_DATE(TIME1 &,DATE1 &);
	   TIME1(int hr,int mn);  // constructor
 };
class DATE1 {
  private:
     int month,day,year;   // variables propias de DATE

  public :
    friend char * TIME_DATE(TIME1 &,DATE1 &);  // creacion de la funcion amiga
            	  DATE1 (int m, int d, int y);
	};
int main(){

	TIME1 x(15,35);
    DATE1 d(1,1,2003);
	cout << " \n FECHA HORA ";
    cout << TIME_DATE(x,d) << "\n";
    cout.fill  ('0');    
    cout.width ( 4 );
    cout <<"HORA DEL SISTEMA : "<< __TIME__<<endl;
    cout<<" Y FECHA DEL SISTEMA :  "<<__DATE__ << "\n";	
    system("pause"); return 0;
}

char *TIME_DATE(TIME1 &t, DATE1 &d)
{
    char *buf = new char[50];
	sprintf(buf,"time : %02d:%02d \t  date : %02d-%02d-%4d",t.hr,t.mn,d.month,d.day,d.year);
	return buf;
}

TIME1::TIME1(int hr,int mn){
	this->hr = hr;
    this->mn = mn;
    cout<<"entra al constructor TIME1\n";
	};

     DATE1::DATE1 (int m, int d, int y) {
         month = m; day = d; year = y;
         cout<<"entra al constructor TIME1\n";
       }
