# include <iostream>
# include <conio.h>
# include <math.h>
using namespace std;
class Dat_XY
{  private:
            float x,y;
   public:
          Dat_XY( void ) ;   //Constructor por defecto
          Dat_XY ( float p, float q) ;//Constructor parametrizado o comun.
          Dat_XY( const  Dat_XY  &obj_c);//Constructor de copia.
          ~Dat_XY( void ) ; 
          void VerX(void);    void VerY(void);   
          void LeeX(void);    void LeeY(void);
          void AsignaX(float a);
          void AsignaY(float b);
          float Retx();       float Rety();
          friend class Imaginarios;
};
class Imaginarios{
    private: 
         Dat_XY Imag1,Imag2,ImagT;    // anidacion de objetos de la clase Dat_XY
         char L; 
		 float den;
    public:
        Imaginarios();  
        Imaginarios(Imaginarios &Ob1);    
      ~ Imaginarios();
    void LeeImag();
    void VerImag();
    void CalcSuma();
    void CalcResta();
    void CalcProd();
    void CalcDiv();
 };

int main(){
    Imaginarios Calc1;
    Calc1.LeeImag();
    cout<<"Producto\n";
    Calc1.CalcProd();
    Calc1.VerImag();
    cout<<"\nSuma\n";
    Calc1.CalcSuma();
    Calc1.VerImag();
    cout<<"Resta\n";
    Calc1.CalcResta();
    Calc1.VerImag();
    cout<<"Division\n";
 	Calc1.CalcDiv();
 	
   system("pause"); 
   return 0;
 }

 Dat_XY::Dat_XY( void )
  {  x=0;   y=0;  }  
 Dat_XY::Dat_XY ( float p, float q)
  {x=p;     y=q;  }
 Dat_XY::Dat_XY( const  Dat_XY  & obj_c)    
  {   x= obj_c.x;  y= obj_c.y; }  
 Dat_XY::~Dat_XY( void ){ cout<<"liberando objetos\n";
  system("pause"); 
 }  
  void  Dat_XY::VerX(void){  cout<<x;     } 
  void  Dat_XY::VerY(void){  cout<<y;     }
  void  Dat_XY::LeeX(void){  cin>>x;      }    
  void  Dat_XY::LeeY(void){  cin>>y;      } 
  void Dat_XY::AsignaX(float a){ x=a;     }
  void Dat_XY::AsignaY(float b){ y=b;     }  
  float Dat_XY::Retx(){return x;}
  float Dat_XY::Rety(){return y;}
 //////////////////////////////////////////////
  Imaginarios::Imaginarios(){cout<<"const 1\n\n";}  
  
  Imaginarios::Imaginarios(Imaginarios &Ob1){
    this->Imag1=Ob1.Imag1;
    this->Imag2=Ob1.Imag2;
    this->ImagT=Ob1.ImagT;   
        }
  Imaginarios::~ Imaginarios(){cout<<"\n\nlibera memoria de objetos\n";}
  
  void Imaginarios::LeeImag(){
        cout<<"\nIngresa una Imaginario 1 de la forma 6+5i :";
        Imag1.LeeX(); Imag1.LeeY();cin>>L;
        cout<<"\nIngresa una Imaginario 2 de la forma 6+5i :";
        Imag2.LeeX(); Imag2.LeeY();cin>>L;
        cout<<endl;
    }
  void Imaginarios::VerImag(){
     if(Imag1.y<0)
       { cout<<"\n   "; Imag1.VerX(); cout<<""; Imag1.VerY();cout<<"i";}
     else
       {cout<<"\n   "; Imag1.VerX(); cout<<"+"; Imag1.VerY();cout<<"i";}
     if(Imag2.y<0) 
        {cout<<"\n + "; Imag2.VerX(); cout<<""; Imag2.VerY();cout<<"i";}
      else
        {cout<<"\n + "; Imag2.VerX(); cout<<"+"; Imag2.VerY();cout<<"i";}
       cout<<"\n__________";
     if(ImagT.y<0)   
       { cout<<"\n   "; ImagT.VerX(); cout<<"";ImagT.VerY();cout<<"i";}
      else 
       		{cout<<"\n   "; ImagT.VerX(); cout<<"+";ImagT.VerY();cout<<"i";}
        cout<<endl<<endl;
       }
  void Imaginarios::CalcSuma(){
        ImagT.AsignaX( Imag1.x+Imag2.x );
        ImagT.AsignaY( Imag1.y+Imag2.y ); 
  }
  
  void Imaginarios::CalcResta(){
  		ImagT.AsignaX( Imag1.x-Imag2.x );
        ImagT.AsignaY( Imag1.y-Imag2.y ); 
  }
  
  void Imaginarios::CalcProd(){
  		ImagT.AsignaX( (Imag1.x*Imag2.x ) + (Imag1.y*Imag2.y*(-1))); 
  		ImagT.AsignaY(( Imag1.x*Imag2.y ) + (Imag1.y*Imag2.x));
}
  
  	
  void Imaginarios::CalcDiv(){
  	
  
  	if(Imag2.y <0){
  		ImagT.AsignaX( (Imag1.x*Imag2.x) +(Imag1.y*(-Imag2.y*-1)));
  		ImagT.AsignaY( (Imag1.x*-Imag2.y) +(Imag1.y*Imag2.x));
  		den=(((Imag2.x)*(Imag2.x))+((-Imag2.y)*(-Imag2.y)));
  		cout<<"\n   "; ImagT.VerX(); cout<<"+";ImagT.VerY();cout<<"i"<<"/"<<den<<endl;
  	}
  	else{
  		ImagT.AsignaX( (Imag1.x*Imag2.x) +(Imag1.y*(Imag2.y)));
  		ImagT.AsignaY( (Imag1.x*-Imag2.y) +(Imag1.y*Imag2.x));
  		den=(((Imag2.x)*(Imag2.x))+((Imag2.y)*(Imag2.y)));
  		cout<<"\n   "; ImagT.VerX(); cout<<"";ImagT.VerY();cout<<"i"<<"/"<<den<<endl;
	  }
	  
}
  
  
  
