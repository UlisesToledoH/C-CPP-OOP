/*
Este programa define una clase Dat_XY para representar puntos o pares ordenados (x, y) en un plano, e incluye operaciones como:

Distancia entre dos puntos (tipo vectorial).

Producto de números fraccionarios (tratando x/y como fracción).

Suma de números complejos (tratando x + yi).
*/

# include <iostream>
# include <conio.h>
# include <math.h>
using namespace std;
class Dat_XY
{  private:
            int x,y;
   public:
          Dat_XY( void ) ;   //Constructor por defecto
          Dat_XY ( int p, int q) ;//Constructor parametrizado o comun.
          Dat_XY( const  Dat_XY  &obj_c);//Constructor de copia.
          ~Dat_XY( void ) ; 
          void VerX(void);    void VerY(void);   
          void LeeX(void);    void LeeY(void);
          void AsignaX(int a);
          void AsignaY(int b);
          int Retx();       int Rety();
          friend float distancia( Dat_XY p1, Dat_XY p2);
          friend void ProdRac( Dat_XY p1, Dat_XY p2);
          friend void SumaCom( Dat_XY p1, Dat_XY p2);
};
int main(){
    float Dist;
    Dat_XY PUNTO1(3,5), PUNTO2(5,9);
    Dist = distancia(PUNTO1, PUNTO2);
    cout<<"Distancia entre dos puntos = "<<Dist<<endl;
    system("pause"); 
    cout<<"El producto de dos numeros fraccionarios\n"; 
    Dat_XY raci1(3,5), raci2(5,9);
    ProdRac(raci1,raci2);
   cout<<"El suma de dos numeros imaginarios\n"; 
    Dat_XY Imag1(3,5), Imag2(5,-9);
    SumaCom(Imag1,Imag2);   
    system("pause"); 
    return 0;
 }
 void SumaCom( Dat_XY p1, Dat_XY p2){
   if( (p1.y+p2.y) < 0 )   
       cout<<(p1.x+p2.x)<<" "<<(p1.y+p2.y)<<"i"<<endl;
   else
      cout<<(p1.x+p2.x)<<" + "<<(p1.y+p2.y)<<"i"<<endl;
}
 void ProdRac( Dat_XY p1, Dat_XY p2){
        cout<<(p1.x*p2.x)<<"/"<<(p1.y*p2.y)<<endl;
   }
 
float distancia (Dat_XY p1, Dat_XY p2)
{ float d;
d= sqrt( pow(p2.x-p1.x,2)+pow(p2.y - p1.y,2) );
return d;
} 
 Dat_XY::Dat_XY( void )
  {  x=0;   y=0;  }  
 Dat_XY::Dat_XY ( int p, int q)
  {x=p;     y=q;  }
 Dat_XY::Dat_XY( const  Dat_XY  & obj_c)    
  {   x= obj_c.x;  y= obj_c.y; }  
 Dat_XY::~Dat_XY( void ){ cout<<"\n\nliberando objetos\n";
  system("pause"); 
 }  
  void  Dat_XY::VerX(void){  cout<<x;     } 
  void  Dat_XY::VerY(void){  cout<<y;     }
  void  Dat_XY::LeeX(void){  cin>>x;      }    
  void  Dat_XY::LeeY(void){  cin>>y;      } 
  void Dat_XY::AsignaX(int a){ x=a;     }
  void Dat_XY::AsignaY(int b){ y=b;     }  
  int Dat_XY::Retx(){return x;}
  int Dat_XY::Rety(){return y;}
  
  

