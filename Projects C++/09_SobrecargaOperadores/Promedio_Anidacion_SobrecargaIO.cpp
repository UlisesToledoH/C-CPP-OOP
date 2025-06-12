/*
    SOBRECARGA DE OPERADORES  ( operator )
    sintaxis general para la entrada y salida de informacion
    DECLARACION DE UNA LECTURA CON SOBRECARGA DE  cin>>
    friend istream & operator>>(istream &ENTRA,NOMCLASE &OBJCLASE);  
    
    DECLARACION DE UN DESPLIEGUE CON SOBRECARGA DE  cout<<
    friend ostream & operator<<(ostream &SALE, NOMCLASE &OBJCLASE);

    PARA EL DESARROLLO DE ESTAS FUNCIONES NO SE PONE LA PALABRA
    RESERVADA friend NI TAMPOCO SE ENLAZA CON LA CLASE 
    
    istream &operator>>(istream &ENTRA,NOMCLASE &OBJCLASE){
       // ALGORITMO USANDO OBJETO DE LA CLASE
     return ENTRA;   
    }
    ostream &operator<<(ostream &SALE,Coordenadas &Ob1){
      // ALGORITMO USANDO OBJETO DE LA CLASE
     return SALE;
     
 PARA LA EJECUCION DE ESTA SOBRECARGA DE LECTURA   cin>>OBJETO;
 PARA LA EJECUCION DE ESTA SOBRECARGA DE DESPLIEGUE   cout<<OBJETO; 
 }
*/
// Programa: Promedio_Anidacion_SobrecargaIO.cpp
// Calcula el promedio de tres calificaciones utilizando anidación de objetos y sobrecarga de operadores `>>` y `<<`.
// La clase `Algo` contiene un puntero a `Coordenadas`, y llama sus métodos indirectamente.
// Demuestra el uso combinado de encapsulamiento, memoria dinámica y sobrecarga de operadores.

# include <iostream>
# include <conio.h>
# include <math.h>
using namespace std;
                        // ANIDACION DE OBJETO puntero
class Coordenadas
{  private:
            float x,y,z;
   public:            //Constructor por defecto
          Coordenadas( void) ;
       //   void LeeCoord(void);
 friend istream &operator>>(istream &ENTRA,Coordenadas &Ob1);
       //   void VerCoord(void);
 friend ostream &operator<<(ostream &SALE,Coordenadas &Ob1);            
          float Retx(){return x;}
           float Rety(){return y;}
            float Retz(){return z;}
};

class Algo{
    private:
         Coordenadas *Ani_xyz;
         float Prom;
    public:
         Algo(){ Prom=0.0; Ani_xyz=new Coordenadas;}
         void LEEA(){cin>>*Ani_xyz;}
         void VERA(){cout<<*Ani_xyz;}
         float Promedio(){ 
                
           Prom=Ani_xyz->Retx()+Ani_xyz->Rety()+Ani_xyz->Retz();
         
           Prom = Prom/3;
           return Prom;
           }   
  };       
 int main(){
  /*      
        Coordenadas punto1;  // SE DECLARA UN OBJETO DE LA CLASE Coordenadas  
        cin>>punto1;  // EJECUCION DE LA SOBRECARGA DE LECTURA >>
        cout<<endl;
        cout<<punto1; // EJECUCION DE LA SOBRECARGA DE DESPLIEGUE <<
  */      
        
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
 istream &operator>>(istream &ENTRA,Coordenadas &Ob1){
       cout<<"x=";  ENTRA>>Ob1.x;
       cout<<"y=";  ENTRA>>Ob1.y;
       cout<<"z=";  ENTRA>>Ob1.z; 
     return ENTRA;   
 }
 ostream &operator<<(ostream &SALE,Coordenadas &Ob1){
      SALE<<"("<<Ob1.x<<","<<Ob1.y<<","<<Ob1.z<<")"<<endl; 
        return SALE;
 }
          
Coordenadas::Coordenadas( void )
  {  x=0;   y=0;   z=9;  }  


 /* 
void  Coordenadas::VerCoord(){
     cout<<"("<<x<<","<<y<<","<<z<<")"<<endl;     }
     
void Coordenadas::LeeCoord(void){
    cout<<"x=";  cin>>x;
    cout<<"y=";  cin>>y;
    cout<<"z=";  cin>>z; 
}   
*/
