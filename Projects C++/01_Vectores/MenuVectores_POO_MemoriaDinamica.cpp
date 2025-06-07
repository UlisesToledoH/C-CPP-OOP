// Programa: MenuVectores_POO_MemoriaDinamica.cpp
// Maneja tres vectores flotantes dinámicos mediante una clase en C++ con POO.
// Usa constructores, sobrecarga por nombre, memoria dinámica y menús para sumar vectores y buscar el mayor/menor valor.
// Ilustra uso de punteros, objetos y menú interactivo.
#include <stdlib.h>
#include <iostream>
#include <windows.h>
using namespace std;

class VECTORES{
    private:
        float *Vector1,*Vector2,*VectorT,MAY,MEN;   
        int TAM; int OPC, OPC1;
    public:
        VECTORES();
        VECTORES(int T);
        VECTORES(const VECTORES &OBJcop);
        ~VECTORES();
     void LeeVector(float *Vec);
     void LeeVector1();
     void VerTABLA();
     void MENUVEC();
     void SUMAVECS();
     float MAYOR( );
     float MENOR( );
 };
 int main( ){
        VECTORES  *Obj1=new VECTORES;   // c1
        Obj1->MENUVEC();
        //system("pause");
     
  system("pause"); 
  delete Obj1;
  return 0;      
   }   
 VECTORES::VECTORES(){
     cout<<"Indica cuantos datos quieres en los Vectores = ";
     cin>>TAM;
        Vector1 = new float[TAM];  
        Vector2 = new float[TAM]; 
        VectorT = new float[TAM];
    if(Vector1==NULL &&Vector2==NULL&&VectorT==NULL)
    {cout<<"no hay mem. din�mica\n"; system("pause");exit(0);}
     for(int i=0; i<TAM; i++){  
        Vector1[i]=0.0;  Vector2[i]=0.0; VectorT[i]=0.0;
     }
      OPC=0;  OPC1=0;
 }
 VECTORES::VECTORES(int T){
     TAM=T;
        Vector1 = new float[TAM];  
        Vector2 = new float[TAM]; 
        VectorT = new float[TAM];
    if(Vector1==NULL &&Vector2==NULL&&VectorT==NULL)
    {cout<<"no hay mem. din�mica\n"; system("pause");exit(0);}
     for(int i=0; i<TAM; i++){  
        Vector1[i]=0.0;  Vector2[i]=0.0; VectorT[i]=0.0;
     }  
     OPC=0;  OPC1=0;
 }
  VECTORES::VECTORES(const VECTORES &OBJcop){
        TAM=OBJcop.TAM;
        Vector1 = new float[TAM];  
        Vector2 = new float[TAM]; 
        VectorT = new float[TAM];
    if(Vector1==NULL &&Vector2==NULL&&VectorT==NULL)
    {cout<<"no hay mem. din�mica\n"; system("pause");exit(0);}
     for(int i=0; i<TAM; i++){  
        Vector1[i]=OBJcop.Vector1[i];  
        Vector2[i]=OBJcop.Vector2[i]; 
        VectorT[i]=OBJcop.VectorT[i];
     } 
      OPC=0;  OPC1=0;  
  }
  VECTORES::~VECTORES(){
    delete [ ]Vector1;  delete [ ]Vector2;  delete [ ]VectorT;       
  } 
    
void VECTORES::MENUVEC(){
  do{ system("cls"); 
      cout<<"M E N U    D E   V E C T O R E S \n";
      cout<<"1.- SUMA DE VECTORES \n";  
      cout<<"2.- RESTA DE VECTORES \n"; 
      cout<<"3.- PRODUCTO DE VECTORES \n"; 
      cout<<"4.- BUSQUEDA \n"; 
      cout<<"5.- S A L I D A \n";   
      cout<<"Ingrese la opcion : "; cin>>OPC;
      switch( OPC ){
          case 1 :  
                    LeeVector(Vector1);
                    LeeVector(Vector2);
                    SUMAVECS();
                    VerTABLA();
                
                  break;
          case 4 :  
                cout<<"SUBMENU BUSQUEDA \n";
                cout<<"1.- BUSCA MAYOR \n";  
                cout<<"2.- BUSCA MENOR \n"; 
                cout<<"3.- S A L I D A \n";   
                cout<<"Ingrese la opcion : "; cin>>OPC1;
                  switch( OPC1 ){
                     case 1: LeeVector1();
                             cout<<"dato mayor = "<<MAYOR()<<endl;
                             break;
                     case 2: LeeVector1();
                             cout<<"dato menor = "<<MENOR()<<endl;
                             break;         
                     case 3 : 
                            cout<<"Gracias por usar mi submenu\n";
                            break;
                     default : cout<<"Opcion Incorrecta\n";
                   }
                  break;
          case 5 : 
                   cout<<"Gracias por usar mi menu\n";
                   break;
          default : cout<<"Opcion Incorrecta\n";
              
      }
      Beep(200,1500);
  }while(OPC!=5);
    
}
 float VECTORES::MAYOR( ){
     MAY=Vector1[0];
        for(int i=0;i<TAM;i++){
            if(MAY<Vector1[i])
                MAY=Vector1[i];  
        }
       return MAY; 
 }
 float VECTORES::MENOR( ){
     MEN=Vector1[0];
        for(int i=0;i<TAM;i++){
            if(MEN>Vector1[i])
                MEN=Vector1[i];  
        }
       return MEN;     
 }
 void VECTORES::SUMAVECS(){
  //Calculo de la suma de dos vectores 
 for(int i=0;i<TAM;i++)  VectorT[i]=Vector1[i]+Vector2[i];
 }
 
void VECTORES::LeeVector1(){  
    for(int i=0; i<TAM; i++)                        
    {  cout<<"  Vector1["<<i<<"] = ";    cin>>Vector1[i] ;    }
}        
void VECTORES::LeeVector(float *Vec){  
     for(int i=0; i<TAM; i++)                        
    {  cout<<"  Vector["<<i<<"] = ";    cin>>Vec[i] ;    }
}    
    
void  VECTORES::VerTABLA( ){
      
    cout<<" Vector1  +  Vector2 = VectorT\n";
    cout<<"______________________________\n";

    for(int i=0; i<TAM; i++) 
     {  cout<<"    "<<Vector1[i]<<"    +     "<<Vector2[i]
                                  <<"   =   "<<VectorT[i]<<endl;
        cout<<"______________________________\n";
     } 
    
    
 }    
    
