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
 friend istream &operator>>(istream &ENTRA,Coordenadas &Ob1);
 friend ostream &operator<<(ostream &SALE,Coordenadas &Ob1);            
 friend Coordenadas &operator+(Coordenadas &Ob1, Coordenadas &Ob2);        
};
 
 int main(){
        
        Coordenadas punto1, punto2, puntoT;  // SE DECLARA UN OBJETO DE LA CLASE Coordenadas  
        cin>>punto1;  // EJECUCION DE LA SOBRECARGA DE LECTURA >>
        cout<<endl;
        cout<<punto1; // EJECUCION DE LA SOBRECARGA DE DESPLIEGUE <<
        cin>>punto2;  // EJECUCION DE LA SOBRECARGA DE LECTURA >>
        cout<<endl;
        cout<<punto2;  
        
        puntoT = punto1 + punto2 ;   
        cout<<puntoT;  
        
     system("pause");    return 0;  
  }
 
 ////////////////////////////////////////
Coordenadas &operator+(Coordenadas &Ob1, Coordenadas &Ob2){
      Coordenadas Aux;  //C1
    Aux.x = Ob1.x + Ob2.x;
    Aux.y = Ob1.y + Ob2.y;
    Aux.z = Ob1.z + Ob2.z;
    return Aux;
    }   
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



