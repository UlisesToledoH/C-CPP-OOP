// Programa: TiempoEntradaSalida_SobrecargaResta.cpp
// Calcula la diferencia entre dos horarios (entrada y salida) usando sobrecarga del operador `-`.
// Utiliza también sobrecarga de `>>` y `<<` para manejar objetos `Tiempo`.
// Muestra cómo representar una duración horaria con POO y operaciones personalizadas.


#include<iostream>
#include<cstdlib>
#include<math.h>
using namespace std;

class Tiempo{
    private: int H, M;
        char P;
    public: Tiempo();
            ~Tiempo();
        friend ostream &operator<<(ostream &sale, Tiempo &Horas);
        friend istream &operator>>(istream &entra, Tiempo &Horas);
        Tiempo &operator-(Tiempo &Horas); //
};

main(){
    Tiempo T1, T2, Tt;
    cout<<"Hora de entrada con formato 8:15  : ";
    cin>>T1;
    cout<<"Hora de salida con formato 17:30  : ";
    cin>>T2;
    Tt=T2-T1;
    cout<<"\n"<<"Usted entro a la(s): "<<T1<<endl;
    cout<<"Usted salio a la(s): "<<T2<<endl<<endl<<endl;
    cout<<"\t"<<"\t"<<"Usted hizo "<<Tt<<" de laborales"<<endl<<endl;
    system("pause");
    return 0;
}

Tiempo::Tiempo(){    H=0; M=0;    }

Tiempo::~Tiempo(){    cout<<"Muriendo..."<<endl;  }

istream &operator>>(istream &entra, Tiempo &Horas){
    entra>>Horas.H>>Horas.P>>Horas.M;
    return entra;
}
ostream &operator<<(ostream &sale, Tiempo &Horas){
    sale<<Horas.H<<":"<<Horas.M;
    return sale;
}

Tiempo &Tiempo::operator-(Tiempo &Horas){
    Tiempo aux;        //T2           H 13 : M 35  
                      // T1       -      7 :  10  
                      
    if(M<Horas.M){
        M = M + 60;
        H = H - 1;
    }
   // if(M>Horas.M){
       
     //    M-=60;    M = M*(-1);  H+=1;
      //  }
    aux.H=abs(H-Horas.H);
    aux.M=abs(M-Horas.M);
    
    
    return aux;
}

