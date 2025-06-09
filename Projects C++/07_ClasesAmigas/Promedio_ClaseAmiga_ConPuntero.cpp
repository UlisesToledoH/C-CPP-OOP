// Programa: Promedio_ClaseAmiga_ConPuntero.cpp
// Calcula el promedio de tres calificaciones usando una clase amiga que accede a un objeto de tipo `Coordenadas`.
// Se implementa la amistad entre clases y uso de punteros dinámicos (`new`).
// Ideal para practicar encapsulamiento, acceso indirecto y memoria dinámica en POO.
# include <iostream>
# include <conio.h>
# include <math.h>
using namespace std;
                        // AMISTAD ENTRE CLASES, USO DE OBJETO puntero
class Coordenadas
{  private:
            float x,y,z;
   public:            //Constructor por defecto
          Coordenadas( void ) ;
          void LeeCoord(void);
          void VerCoord(void);   
          float Retx(){return x;}
           float Rety(){return y;}
            float Retz(){return z;}
            friend class Algo;
};

class Algo{
    private:
         Coordenadas *Ani_xyz;
         float Prom;
    public:
         Algo(){ Prom=0.0;	Ani_xyz = new Coordenadas; }
         void LEEA(){Ani_xyz->LeeCoord();}
         void VERA(){Ani_xyz->VerCoord();}
         float Promedio(){ 
         
           Prom=Ani_xyz->x+Ani_xyz->y+Ani_xyz->z;
        
           Prom = Prom/3;
           return Prom;
           }   
  };        
 int main(){
        
        Algo Alumna1,Alumna2;
       cout<<"Ingresa las 3 calificaciones de Paulina"<<endl; 
        Alumna1.LEEA();
        Alumna1.VERA();
        cout<<"promedio = "<< Alumna1.Promedio()<<endl;;
         
       cout<<"Ingresa las 3 calificaciones de Sarai"<<endl; 
        Alumna2.LEEA();
        Alumna2.VERA();
        cout<<"promedio = "<< Alumna2.Promedio()<<endl;;
       
     system("pause");    return 0;  
        
        }
 
 ////////////////////////////////////////         
Coordenadas::Coordenadas( void )
  {  x=0;   y=0;   z=9;  }  
void  Coordenadas::VerCoord(){
     cout<<"("<<x<<","<<y<<","<<z<<")"<<endl;     }
     
void Coordenadas::LeeCoord(void){
    cout<<"x=";  cin>>x;
    cout<<"y=";  cin>>y;
    cout<<"z=";  cin>>z; 
}   
