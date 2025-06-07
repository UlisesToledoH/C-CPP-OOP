/*Dise�o de un programa en POO que calcula la media, varianza y desviacion 
estandar para un conjunto de datos de tipo flotante de tama�o N. Se generara un 
apuntador, M.D, constructor, destructor, funcion que lee datos, funciones que 
calcula la media, La varianza y la desviacion estandar
En el main() se estan declarando objetos punteros y se genera
la memoria dinamica para ejecutar a los constructores 1 y2
*/
// Programa: Estadistica_MediaVarianza_POO.cpp
// Calcula la media, varianza y desviación estándar de un conjunto de datos tipo flotante.
// Usa dos clases: `Estadistica` (para almacenar datos y manejar memoria dinámica) y `Calculos` (para operar con ellos).
// Se implementan constructores, destructores, punteros, anidación de clases y cálculo estadístico básico.

#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

class Estadistica 
{      private:
              int n,i;
              float *Xi; //Variables (atributos) a utilizar
      
      public:
             Estadistica(); //Constructor 1 no tiene parametros
             Estadistica(int N);//Constructor 2, con parametros
             ~Estadistica(); //Destructor
             void LeeXi();
             int Retn();
             float Retxi(int i);
             
};

class Calculos{
	
	private: 
	Estadistica *Obj; //SE REALIZA LA ANIDACION
	int i;
	float Xm,V,D; //VARIABLES QUE UTILIZARE EN EL CALCULO
	
	public:
	Calculos();
	~Calculos();
	void LECTURA();
	float Media();    // retornan el resultado
	float Varianza();
	float Desv_Est();
	
};

int main()
{ 
	Calculos *OB1=new Calculos;
	OB1->LECTURA();
    cout<<"La Media de los datos es: " << OB1->Media()<<endl;
    cout<<"La Varianza de los datos es: " << OB1->Varianza()<<endl;
    cout<<"La Desviacion Estandar de los datos es: " << OB1->Desv_Est()<<endl;

  system("PAUSE");
  delete OB1;
    return 0;

	}
    
  
 Estadistica::Estadistica(int N){
        n=N;
      Xi=new float [n];   
   
      if(Xi==NULL)
      {      cout<<"No hay M.D\n";  system("PAUSE");  exit (0);   }
     
    }
    
	
Estadistica::Estadistica()
{    // se genera la memoria dinamica
      cout<<"Cuantos Datos Ingresara? n= ";
      cin>>n;
      Xi=new float [n];   
      if(Xi==NULL)
      {      cout<<"No hay M.D\n";  system("PAUSE");  exit (0);   }
     
 }
Estadistica::~Estadistica()
{   // libera la memoria dinamica
      if(Xi!=NULL)    delete[ ]Xi;    
      cout<<"Muriendo....\n"; 
	  system("pause");
}

int Estadistica::Retn(){ //RETORNO MI TAMA�O

return n;

}

void Estadistica::LeeXi() 
{
	
     for(i=0;i<n;i++)
     {   cout<<"Ingrese el "<<i<<" valor=";
         cin>>Xi[i];
     }
}

float Estadistica::Retxi(int i){ // Retorno *Xi
	return Xi[i];
}

///////////////////////////////////////////////   AQUI EMPIEZAN MIS FUNCIONES DE MI CLASE ANIDADA
Calculos::Calculos(){
	Obj=new Estadistica; //////////Ya es apuntador///////////
	Xm=0; V=0;	D=0;
}

Calculos::~Calculos(){
	cout<<"Muriendo en clase anidada\n";
}

float Calculos::Media()
{
      for(i=0;i<Obj->Retn();i++)  //Cambio mis puntos por las flechas
      {    Xm += Obj->Retxi(i);    } //  el objeto de la clase anidada Retorna *Xi
      Xm /= Obj->Retn();
      return Xm;
}
float Calculos::Varianza()
{
      for(i=0; i<Obj->Retn(); i++)
      {V+=pow((Obj->Retxi(i)-Xm),2);
	   }
      V /= Obj->Retn();
      return V;
}
float Calculos::Desv_Est()
{
      D= sqrt(V);
      return D;
}      

void Calculos::LECTURA(){ //Ocupo la funcion de mi clase anidada a su vez el objeto de esta apunta hacia mi lectura de la clase Estadistica
	Obj->LeeXi();
}
