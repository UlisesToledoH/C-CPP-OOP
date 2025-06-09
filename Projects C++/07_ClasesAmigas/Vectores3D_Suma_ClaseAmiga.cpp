// Programa: Vectores3D_Suma_ClaseAmiga.cpp
// Realiza la suma de dos vectores tridimensionales usando clases amigas.
// La clase `CALC_VECXYZ` es amiga de `Coordenadas`, permitiéndole acceder a sus miembros privados sin métodos públicos.
// Usa constructores, destructores y encapsulamiento para demostrar la relación de amistad entre clases.
/*  AMISTAD ENTRE CLASES. 
    Concepto de ubicar en private a uno o varios 
    objetos de otra clase, ya simples o puntero.
*/
# include <iostream>
# include <conio.h>
# include <math.h>
using namespace std;

class Coordenadas
{  private:
            float x,y,z;
   public:
                                //Constructor por defecto
          Coordenadas( void ) ;   
                               //Constructor parametrizado o comun.
          Coordenadas ( float p, float q, float t) ;
                             //Constructor de copia.
          Coordenadas( const  Coordenadas  &obj_c);
          ~Coordenadas( void ) ; 
          void VerCoord(void);   
          void LeeCoord(void);
          void AsignaXYZ(float a,float b,float c);
          //float Retx();
          //float Rety();
          //float Retz();  
          friend class CALC_VECXYZ;
};
class CALC_VECXYZ {
   private :           // CONCEPTO A ANIDACION EN OTRA CLASE
       Coordenadas Vec1,Vec2,VecT;  // CADA OBJETO EJECUTA AL CONSTRUCTOR 1
   public:
       void LEE();
       void SUMAV();//  void RESTAV();  void PRODPV();
       void VER();
        
};
int main(void)
{ CALC_VECXYZ ob1;    
     ob1.LEE(); 
     ob1.SUMAV();
     ob1.VER();  
  system("pause");  return 0;
}
Coordenadas::Coordenadas( void )
  {  x=0;   y=0;   z=0;  }  
 Coordenadas::Coordenadas ( float p, float q, float t)
  {x=p;     y=q;   z=t;  }
 Coordenadas::Coordenadas( const  Coordenadas  & obj_c)    
  {   x= obj_c.x;      y= obj_c.y;     z= obj_c.z;    }  
 Coordenadas::~Coordenadas( void ){ cout<<"liberando objetos\n";}   
void  Coordenadas::VerCoord(){
     cout<<"("<<x<<","<<y<<","<<z<<")"<<endl;     }
     
void Coordenadas::LeeCoord(void){
    cout<<"x=";  cin>>x;
    cout<<"y=";  cin>>y;
    cout<<"z=";  cin>>z; 
}    
 void Coordenadas::AsignaXYZ(float a,float b,float c)
 {                x=a;  y=b;   z=c;           }
 
   //float Coordenadas::Retx(){return x;}
   //float Coordenadas::Rety(){return y;}
   //float Coordenadas::Retz(){return z;} 

///////////////funciones de clase CALC_VECXYZ////////////////////////////////  
   
   void CALC_VECXYZ::LEE(){     
     cout<<"INGRESAR AL VECTOR 1 :"; //  Vec1.LeeCoord(); 
        cout<<"x=";  cin>> Vec1.x;
        cout<<"y=";  cin>> Vec1.y;
        cout<<"z=";  cin>> Vec1.z; 
     cout<<"INGRESAR AL VECTOR 2 :";  // Vec2.LeeCoord(); 
        cout<<"x=";  cin>> Vec2.x;
        cout<<"y=";  cin>> Vec2.y;
        cout<<"z=";  cin>> Vec2.z; 
     cout<<endl<<endl;}
     
     
   void  CALC_VECXYZ::SUMAV(){
        /* VecT.AsignaXYZ( Vec1.Retx()+Vec2.Retx() ,
                         Vec1.Rety()+Vec2.Rety(), EN ESTE CASO ES SOLO ANIDACION YA QUE MI OBJETO DE MI SEGUNDA CLASE APUNTA HACIA EL RETORNO
                         Vec1.Retz()+Vec2.Retz() );*/
        VecT.x = Vec1.x+Vec2.x;
        VecT.y = Vec1.y+Vec2.y; 
         VecT.z = Vec1.z+Vec2.z;                    }

   void  CALC_VECXYZ::VER(){ 
    cout<<endl<<endl;
     cout<<"\t  ";Vec1.VerCoord();
     cout<<"\n\t+"; 
     cout<<"\n\t  ";Vec2.VerCoord();
     cout<<"\n\t_____________________";
     cout<<"\n\t  "; VecT.VerCoord();    
   }


