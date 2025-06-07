/*       SIMULACRO DE EXAMEN DE LABORATORIO PARCIAL 2
DISE�AR UN PROGRAMA EN POO, QUE CALCULE LA MEDIA, LA VARIANZA Y 
LA DESVIACION ESTANDAR, UTILIZANDO :
    
    EQUIPOS PARES :  * ANIDACION
    EQUIPOS NONES :   AMISTAD CLASES
    
EL PROGRAMA DEBE TENER LO SIGUIENTE:
    1.  CLASES
    2.  CONSTRUCTORES Y DESTRUCTORES
    3.  FUNCIONES MIEMBRO
    4.  VARIABLES :  APUNTADOR FLOTANTE
                     VARIABLES PARA RESULTADOS
    5.  EN LA FUNCION PRINCIPAL main USAR OBJETOS PUNTERO
       
*/
#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
class C_VEC{
    private:
           float *Vec;
           int i,j,Tam; 
    public:
           C_VEC();
           C_VEC(int N);
           C_VEC(C_VEC &ObCop);
           ~C_VEC();
        void LEE_VEC();
        void VER_VEC();
        int RET_TAM();
        float RET_VEC1_1(int i);
  };
  class ESTAD{
        private:
            float Med,Var,Des;
            int i;
            C_VEC  EST1;   // aqui declaramos la anidacion 
        public:
            ESTAD();
        //    ESTAD(); 
        //    ESTAD(); 
            ~ESTAD();	
            void LEEDATOS();
            float MEDIA();
            float VARIANZA();
            float DESVIACIONE();
        };   
      
int main(){
    ESTAD  OB1;
    cout<<"Ingresar los ohmios de las resistencias a calcular\n";
    OB1.LEEDATOS();
  
    cout<<"Media = "<<OB1.MEDIA()<<endl;
    cout<<"Varianza = "<<OB1.VARIANZA()<<endl;
    cout<<"Desviacion estandard  = "<<OB1.DESVIACIONE()<<endl;
   
    system("pause");return 0;
 }
    
    C_VEC::C_VEC(){
      cout<<"Ingresa el tama�o del vector= "; cin>>Tam;
      Vec=new float[Tam];
      if(Vec==NULL){cout<<"no mem din\n";system("pause");exit(0);}
       for(i=0;i<Tam;i++)Vec[i]=0.0;
     }
     
     C_VEC::C_VEC(int N){
      Tam=N;
      Vec=new float[Tam];
      if(Vec==NULL){cout<<"no mem din\n";system("pause");exit(0);}
       for(i=0;i<Tam;i++)Vec[i]=0.0;
    }
    
     C_VEC::C_VEC(C_VEC &ObCop){
      Tam=ObCop.Tam;//
      Vec=new float[Tam];
      if(Vec==NULL){cout<<"no mem din\n";system("pause");exit(0);}
      for(i=0;i<Tam;i++)Vec[i]=ObCop.Vec[i]; //
     }
     
      C_VEC::~C_VEC(){ delete [ ]Vec;
                }
                
      void  C_VEC::LEE_VEC(){ 
            for(i=0;i<Tam;i++)cin>>Vec[i]; 
        }
        
        void  C_VEC::VER_VEC(){
            for(i=0;i<Tam;i++)cout<<Vec[i]<<endl;
        }
     int C_VEC::RET_TAM(){return Tam;}
     
    float C_VEC::RET_VEC1_1(int i){return Vec[i];}
//////////////////////////////////////

    ESTAD::ESTAD(){ Med=0.0;Var=0.0;Des=0.0;}
    
    ESTAD:: ~ESTAD(){cout<<"LIBERANDO MEMORIA DE OBJETOS\n";}
    
  float ESTAD::MEDIA(){
   Med==0.0;
    for(i=0;i<EST1.RET_TAM();i++)Med = Med + EST1.RET_VEC1_1(i) ; // ANIDACION ->   OBJ.RETORNOVARIABLE
       Med = Med/EST1.RET_TAM();
    return Med;   
  }
   float ESTAD::VARIANZA(){
        Var=0.0;
     for(i=0;i<EST1.RET_TAM();i++)
           Var = Var + pow( (EST1.RET_VEC1_1(i)-Med),2 ) ;
           Var = Var / EST1.RET_TAM() ;
    return Var;
                }
    float ESTAD::DESVIACIONE(){
          Des= sqrt(Var);          
      return Des;
    }
   void ESTAD::LEEDATOS(){
        EST1.LEE_VEC(); //OBJETOAPUNTA A LA FUNCION DE LEER DE LA PRIMERA CLASE
        }


