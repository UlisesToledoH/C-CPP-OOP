// Programa: AreaTriangulo_Heron_Compacto.cpp
// Calcula el área de un triángulo usando el teorema de Herón mediante una sola clase en C++.
// Verifica la validez del triángulo, calcula el semiperímetro y el área.
// Incluye dos constructores y destructor. Uno de los objetos usa valores fijos para demostrar su uso.

#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
class AreaTriang{
    private:
           float a,b,c,Semi,Area;
           int band; //=0;
    public:    
        AreaTriang(void);      
        AreaTriang(float _a, float _b, float _c); 
        ~AreaTriang();
        int VerifTriang();
        void Lee_abc(void);
        void SemiPer (void );
        void AreaT (void);  
        void ResArea(void); 
};

int main()
{  
    AreaTriang  Ale;
    Ale.Lee_abc();
 //   Ale.VerifTriang();
    Ale.SemiPer();
    Ale.AreaT();
    Ale.ResArea();
  ////////////////////////////////////////
    float a, b, c;
   cout<<"a=";cin>>a;
   AreaTriang Ale2(a,2,3);
  // Ale2.VerifTriang();
    Ale2.SemiPer();
    Ale2.AreaT();
    Ale2.ResArea();

   system("pause");  
   return 0; 
 }

   AreaTriang::AreaTriang(void){  // C1
        a=0.0;  b=0.0; c=0.0; Semi=0.0; Area=0.0;  band=0;
        }      
   AreaTriang::AreaTriang( float a,float b,float _c){  // C2
           this->a=a;  
           AreaTriang::b=b; 
           c=_c; 
           Semi=0.0; Area=0.0;  
         }
    AreaTriang::~AreaTriang(){
            cout<<"Liberando memoria de objetos\n";
           }
       int AreaTriang::VerifTriang(){
           if((a+b)>c  &&  (a+c)>b  &&  (b+c)>a )  
                band = 0;
           else 
                band = 1; 
              
           return band;           
                }
    void AreaTriang::Lee_abc(void){
   do{     
    cout<<"\n 				Teorema de Heron \n\n";   
    cout<<"\nIngrese el valor de a:"; cin>>a;
	cout<<"\nIngrese el valor de b:"; cin>>b;
	cout<<"\nIngrese el valor de c:"; cin>>c;
}while(VerifTriang());
            }
    void AreaTriang::SemiPer (void ){
            	Semi = (a + b + c) / 2; 
            }
    void AreaTriang::AreaT (void){
    
      Area = sqrt(Semi*(Semi-a)*(Semi-b)*(Semi-c));
            
            } 
    void AreaTriang::ResArea(void){
           cout<< "\nEl resultado del area = "<<Area<<endl;
            } 
