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

// Programa: SobrecargaIO_ObjetoSimple.cpp
// Demuestra la sobrecarga de operadores `>>` y `<<` para un objeto de la clase `Coordenadas`.
// Muestra cómo leer y desplegar coordenadas tridimensionales con sintaxis limpia tipo `cin >> objeto` y `cout << objeto`.

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
 
 int main(){
        
        Coordenadas punto1;  // SE DECLARA UN OBJETO DE LA CLASE Coordenadas  
        cin>>punto1;  // EJECUCION DE LA SOBRECARGA DE LECTURA >>
        cout<<endl;
        cout<<punto1; // EJECUCION DE LA SOBRECARGA DE DESPLIEGUE <<
        
        
   
     system("pause");    return 0;  
        
        }
 
 ////////////////////////////////////////
 istream &operator>>(istream &ENTRA,Coordenadas &Ob1){
       cout<<"x=";  ENTRA>>Ob1.x; //cambie mi cin por mi entra
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
