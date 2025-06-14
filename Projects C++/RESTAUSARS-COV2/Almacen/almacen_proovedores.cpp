/*
	DISE�O DE UN PROGRAMA EN POO UTILIZANDO EL CONCEPTO DE HERENCIA
	PARA UN ALMACEN, QUE TIENE LAS CLASES PROVEDORES, CONTABILIDAD

*/

#include<stdlib.h>
#include<iostream>
//#include<string.h>

using namespace std;

//una clase especificamente de productos
class Producto{ //jitomate	jit123	5cajas	200	
	protected:
		string nomprod,clavprod;
		int cantprod;
		float precprod,subtot,total;
	public:
		Producto(){ nomprod="";	clavprod="";	cantprod=0; precprod=0;	subtot=0; total=0;}
		~Producto(){ cout<<"Liberando objetos de Prod\n";}
		
		void Compra()//lectura de datos para comprar, pondremos, nombre,cantidad
		{ 
			cout<<"\n";
			cout<<"Clave del producto: ";cin>>clavprod; cin.ignore();
			cout<<"Drescripcion del producto: ";getline(cin,nomprod);
			cout<<"Cantidad a comprar: ";cin>>cantprod;
			cout<<"Precio: "; cin>>precprod;
		}
		
		void VerCompra(){
			cout<<"\n";
			cout<<"Clave del producto: "<<clavprod<<endl;
			cout<<"Drescripcion del producto: "<<nomprod<<endl;
			cout<<"Cantidad a comprar: "<<cantprod<<endl;
			cout<<"Precio: "<<precprod<<endl;
			subtot=cantprod*precprod;
			cout<<"Subtotal : "<<subtot<<endl;
			total=(subtot*0.16)+subtot;
			cout<<"Total : "<<total<<endl;
		
		}
		friend class Proveed;
};

class Proveed{ //Central de abastos local ,1,2...
			
	protected:
		string NomProv,NomVta,telef; //NO PONER EL PRECIO DE LAS COSAS
		Producto *Verduras1,*Verduras2,*Fruta1,*Fruta2; //HACEMOS UNA ANIDACION
		int TamV1,TamV2,Tamf1,Tamf2; //para mis memorias dinamicas
		int i,j,k;
	public:
		Proveed(){ 
					i=j=k=0; NomProv=""; NomVta=""; telef=""; 
					
					
					cout<<"Cuantos tipos de verduras se compraran= ";
					cin>>TamV1;
					Verduras1 = new Producto[TamV1]; //MD para verduras1
					
					cout<<"Cuantos tipos de frutas se compraran= ";
					cin>>Tamf1;
					Fruta1 = new Producto[Tamf1];//MD para frutas1
						if(Verduras1==NULL && Fruta1==NULL){
                        cout<<"No hay mem din \n"; system("pause");
                        exit(0);
                        }        
					 } //GENERANDO MEMORIAS DINAMICAS
		~Proveed(){ 
			cout<<"Liberando memoria para Proveed\n";
			if(Verduras1!=NULL && Fruta1!=NULL){
            delete []Verduras1; delete []Fruta1;}
		}
		
		void ComProv(){ 
			
			cin.ignore();
			cout<<"Nombre del proveedor : "; getline(cin,NomProv);
			cout<<"Nombre del vendedor : "; getline(cin,NomVta);
			cout<<"Telefono del vendedor : "; getline(cin,telef);
			cout<<"Ingreso compra de verduras \n";
			for(i=0;i<TamV1;i++){
				Verduras1[i].Compra();
			} //UTILIZAMOS CICLOS PARA NUESTRA MEMORIA DINAMCA
				
			cout<<"Ingreso compra de frutas \n";
			for(i=0;i<Tamf1;i++){
				Fruta1[i].Compra();}	
		}
		
		void VerCompraProv(){
		
        cout<<"Nombre del proveedor :"<<NomProv<<endl;
        cout<<"Nombre del vendedor :"<<NomVta<<endl;
        cout<<"telefono del vendedor :"<<telef<<endl; 
       cout<<"Ingreso compra de verduras\n";
        for(i=0;i<TamV1;i++)
        {   Verduras1[i].VerCompra();  }
        cout<<"Ingreso compra de fruta\n";
        for(i=0;i<Tamf1;i++)
        {   Fruta1[i].VerCompra();  }
        
        } 
	
};

int main(){
	
	Proveed obj;
	obj.ComProv();
	obj.VerCompraProv();
	
	system("pause");
	return 0;
}

