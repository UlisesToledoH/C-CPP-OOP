// Programa: DatosPersonales_ClaseAnidadaString.cpp
// Guarda y muestra información personal utilizando una clase con miembros tipo `string`.
// Demuestra el concepto de anidación de objetos de otra clase (en este caso, `std::string`).
// Incluye constructores (por defecto, parametrizado, copia) y destructor.
// Se utiliza `getline` para leer cadenas con espacios.
// concepto de anidacion, porque la clase string esta usandose
// para leer datos de tipo caracter o cadenas de caracteres.
# include <iostream>
# include <conio.h>
# include <math.h>
using namespace std;

class DATOSP{
    private:
        string nombre, apellido1, apellido2;    // anidacion de objetos de la clase string
        string email, direccion, poblacion;
        int edad; long telefono;
    public:
        DATOSP(); 
        DATOSP(string nom,string ape1,string ape2);
        DATOSP(DATOSP &OBCOP);
        ~DATOSP();
       void LEEDATOSP();
       void VERDATOSP();
 };

int main(){
   DATOSP  *ALUMNOS=new DATOSP;
   ALUMNOS->LEEDATOSP();
   ALUMNOS->VERDATOSP();
   
   DATOSP OBJcop(*ALUMNOS);
   cout<<"\n\n-----------------COPIA---------------\n";
   OBJcop.VERDATOSP();
   system("pause"); 
   return 0;
 }
 
 DATOSP::DATOSP(){
         nombre=" ";  apellido1=" "; apellido2=" ";
         email=" "; direccion=" "; poblacion=" ";
         edad=0; telefono=0;
        }
 DATOSP::DATOSP(string nom,string ape1,string ape2){
      nombre=nom;  apellido1=ape1; apellido2=ape2;
      email=" "; direccion=" "; poblacion=" ";
       edad=0; telefono=0;   
        }
 DATOSP::DATOSP(DATOSP &OBCOP){
 nombre=OBCOP.nombre;  apellido1=OBCOP.apellido1; apellido2=OBCOP.apellido2;
 email=OBCOP.email; direccion=OBCOP.direccion; poblacion=OBCOP.poblacion;       
       edad=OBCOP.edad; telefono=OBCOP.telefono;   
        }
 DATOSP::~DATOSP(){
        cout<<"liberando objetos";
        }
void DATOSP::LEEDATOSP(){   // uso de getline para la lectura de string
    cout << "Nombre : "; getline(cin, nombre);
    cout << "Primer Apellido : "; getline(cin, apellido1);
    cout << "Segundo Apellido : "; getline(cin, apellido2);
    cout << "Direccion : " ; getline(cin, direccion);
    cout << "Poblacion : " ; getline(cin, poblacion);
    cout << "e-mail : "; cin >> email;
    cout << "Edad : "; cin >> edad;
    cout << "Telefono : " ; cin >> telefono;
    }
void DATOSP::VERDATOSP(){
    cout << endl <<  "TUS DATOS" << endl;
    cout << "Nombre : " << nombre <<endl;
    cout << "Apellidos : " << apellido1 << " " << apellido2 << endl;
    cout << "E-mail : " << email << endl;
    cout << "Edad : " << edad << endl;
    cout << "Telefono : " << telefono <<endl;
    cout << "Domicilio : " << direccion << " " << poblacion << endl;
    }


