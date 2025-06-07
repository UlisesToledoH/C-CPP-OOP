# include <iostream>
# include <conio.h>
# include <math.h>
using namespace std;

class Coordenadas
{  private:
            int x,y,z;
   public:
                                //Constructor por defecto
          Coordenadas( void ) ;   
                               //Constructor parametrizado o comun.
          Coordenadas ( int p, int q, int t) ;
                             //Constructor de copia.
          Coordenadas( const  Coordenadas  &obj_c);
          void  VerCoord(void);   
          void LeeCoord(void);
};
int main(void)
{    cout<<"Declaracion de objeto con parametros\n";
     Coordenadas *Objk=new Coordenadas(1,2,3);   // Ejecuta al constructor con parametros
     Objk->VerCoord( );         // 1 2 3 del objeto   Objk
    
 
   cout<<"Declaracion de objeto copia\n\n";
      Coordenadas *Objcopia=new Coordenadas(*Objk);  // Ejecuta al constructor copia
   cout<<"Visualizacion de los datos copia\n";
      Objcopia->VerCoord( );     // 1 2 3 del objeto   Objcopia
     
    Coordenadas *ObjSimple=new Coordenadas; // Ejecuta Constructor por defecto
    ObjSimple->LeeCoord();
    ObjSimple->VerCoord();
     
     
    Coordenadas  EstherCopia(  *ObjSimple ); 
    EstherCopia.VerCoord();  
      
 system("pause");
   //delete Objk;
 
 return 0;
}

 Coordenadas::Coordenadas( void )
  {  x=0;   y=0;   z=0;  }  
 Coordenadas::Coordenadas ( int p, int q, int t)
  {x=p;     y=q;   z=t;  }
 Coordenadas::Coordenadas( const  Coordenadas  & obj_c)    
  {   x= obj_c.x;      y= obj_c.y;     z= obj_c.z;    }  
   
void  Coordenadas::VerCoord(){
     cout<<"("<<x<<","<<y<<","<<z<<")"<<endl;     }
     
void Coordenadas::LeeCoord(void){
    cout<<"x=";  cin>>x;
    cout<<"y=";  cin>>y;
    cout<<"z=";  cin>>z; 
    }
