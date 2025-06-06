// Programa: MenuInteractivo_Validaciones.cpp
// Muestra un menú con opciones para validar una fecha, verificar un triángulo y calcular fuerza entre cargas.
// Solo la validación de fecha está parcialmente implementada. Incluye portada de presentación.
// Ejemplo básico de menú en C++ con opción de expansión.



#include<iostream>
using namespace std;
class MENU1{
    private:
        int Dia, Mes, Anio,VFecha;
        char L,cadena[10];
        char OPCION;
    public:
        
        int VERIFICAFECHA(int D,int M, int A);
        void PORTADA(void); 
        void MENUTODO(void);
    };
    
    int main(){
        MENU1 REPASO;
        REPASO.PORTADA( );
        REPASO.MENUTODO( );
        
      system("pause");
      return 0;    
        }
 
 int MENU1::VERIFICAFECHA(int D,int M, int A){
    int R;
    if( (D>0 &&  D<32)&&(M>0 &&  M<13)&&(A>1000 &&  A<2100) )
        R=1;
    else
        R=0;
    return R;
  }       
void MENU1::MENUTODO(void){
       
        cout<<"\n\n\n";
        cout<<"\t\t 1.- VERIFICA UNA FECHA....\n";
        cout<<"\t\t 2.- VERIFICA UN TRIANGULO Y CALCULA SU AREA....\n";
        cout<<"\t\t 3.- CALCULA LA FUERZA ENTRE DOS CARGAS....\n";
        cout<<"\t\t 4.- S A L I D A ....\n";
        cout<<"\t\t O P C I O N : ";cin>>OPCION;
        switch( OPCION ){
           case '1':
                   cout<<"Introduce una fecha de la forma 01-01-2000 :";
                   cin>>cadena;
                   //cin>>Dia>>L>>Mes>>L>>Anio;
                //   VFecha = VERIFICAFECHA(Dia,Mes,Anio); 
                   if(VFecha==1) cout<<"Fecha correcta\n";
                   else          cout<<"Fecha incorrecta\n";
                   break;
            case '2':
                   break;
            case '3':
                   break;
            case '4':
                   break;
                   
            default :   cout<< "OPCION INCORRECTA\n";
                
           }
           
        }
void MENU1::PORTADA(void){ 
    system("color 70"); 
     cout<<"\t\t_________________________________________________________\n"; 
     cout<<"\t\t_____________INSTITUTO POLITECNICO NACIONAL______________\n"; 
     cout<<"\t\t____ESCUELA SUPERIOR DE INGENIERIA MECANICA ELECTRICA____\n";  
     cout<<"\t\t_________________________________________________________\n"; 
     cout<<"\t\t_________________________________________________________\n\n\n"; 
}  


