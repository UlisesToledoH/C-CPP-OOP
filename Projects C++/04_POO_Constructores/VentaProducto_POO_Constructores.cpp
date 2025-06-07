// Programa: VentaProducto_POO_Constructores.cpp
// Simula la venta de un producto usando dos clases: PRODUCTO y VENTA.
// Utiliza POO con constructores por defecto y de copia, destructores, encapsulamiento y métodos para calcular subtotal y total.
// Incluye métodos de acceso para mostrar datos organizadamente.

# include <iostream>
# include <conio.h>
# include <math.h>
using namespace std;

class PRODUCTO{
	private: 
	string CLA_PROD, DESCRIP;
	float Precio, Subtotal;
	int Cant;
	public:
		PRODUCTO();
		PRODUCTO(PRODUCTO &OBCOP);
		~PRODUCTO();
		float RetSubt();
		void LeeProd();
		void VerProd();
		float Retsubt();
		float Retpre();
		int Retcant();
		string Retclave();
		string Retdes();
};

class VENTA{
	private: 
		PRODUCTO OBJ;
		float Total;
	public:
			VENTA();
			VENTA(VENTA &ObCop);
			~VENTA();
			void LEEVENTA();
			void VtaProd();
			void VerVta();
};

int main(){
	
	VENTA *Obj1=new VENTA();
	Obj1->LEEVENTA();
	Obj1->VerVta();
	
	VENTA *objcop= new VENTA(*Obj1);
	objcop->VerVta();
	
	system("pause");
	return 0;
	
}
PRODUCTO::PRODUCTO(){
	CLA_PROD=""; DESCRIP="";
	Precio=0.0; Subtotal=0.0;
	Cant=0;
}
PRODUCTO::PRODUCTO(PRODUCTO &OBCOP){
	CLA_PROD=OBCOP.CLA_PROD; DESCRIP=OBCOP.DESCRIP;
	Precio=OBCOP.Precio; Subtotal=OBCOP.Subtotal;
	Cant=OBCOP.Cant;
}
PRODUCTO::~PRODUCTO(){
	cout<<"Liberando memoria";
	system("pause");
	
}
float PRODUCTO::Retsubt(){ 
Subtotal=Precio*Cant;
return Subtotal;}

void PRODUCTO::LeeProd(){
			cout<<"Ingrese el producto a vender\n";
			cout<<"Clave : "; cin>>CLA_PROD;
			cout<<"Descripcion : "; cin>>DESCRIP;
			fflush(stdin);
			cout<<"Precio : "; cin>>Precio;
			cout<<"Cantidad : "; cin>>Cant;
			
		}
void PRODUCTO::VerProd(){
			cout<<"Producto vendido\n";
			cout<<"Clave : "<<CLA_PROD<<endl;
			cout<<"Descripcion : "<<DESCRIP<<endl;
			cout<<"Precio : "<<Precio<<endl;
			cout<<"Cantidad : "<<Cant<<endl;
			cout<<"Subtotal: 	"<<Subtotal<<endl;
		}
/////////////////////////////////////////

float PRODUCTO::Retpre(){ return Precio;}
int PRODUCTO::Retcant(){ return Cant;}
string PRODUCTO::Retclave(){return CLA_PROD;}
string PRODUCTO::Retdes(){return DESCRIP;}

VENTA::VENTA(){
	Total=0;
}

VENTA::VENTA(VENTA &ObCop){
		Total=ObCop.Total; OBJ=ObCop.OBJ;
}
VENTA::LEEVENTA(){
	cout<<"INGRESA EL PRODUCTO A VENDER"<<endl;
	OBJ.LeeProd();
}
VENTA::~VENTA(){
	cout<<"Liberando memoria"<<endl;
}
void VENTA::VtaProd(){
	Total = Total + OBJ.Retsubt();
}

void VENTA::VerVta(){
	OBJ.VerProd();
	cout<<"Total de venta:  "<<Total<<endl;
}

/*cout<<"Clave:	"<<OBJ.Retclave()<<endl;
	cout<<"Descripcion del producto:	"<<OBJ.Retdes()<<endl;
	cout<<"Precio:	"<<OBJ.Retpre()<<endl;
	cout<<"Cantidad :	"<<OBJ.Retcant()<<endl;
	cout<<"Subtotal: 	"<<OBJ.Retsub()<<endl;*/

