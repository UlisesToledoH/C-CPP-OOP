//PROYECTO FINAL EQUIPO 12
//DUARTE ZAPOTE ADRIANA 
//TOLEDO HERNANDEZ ULISES GABRIEL
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <cstring>
#include <windows.h>
//#include <graphics.h>
#include <conio.h>
//#include <uconio.h>
//#include <wchar.h>
//#include <locale.h>
//#include <winbgim.h>
using namespace std; 

class Graficos{
	protected:
		int i;
	public:
	Graficos();
	~Graficos();
	void dibujarCuadro(int x1,int y1,int x2,int y2);
	void gotoxy(int x,int y);
	friend class Producto;
	friend class Proveedores;
};

class Comidas: public Graficos{
	protected:
	int num,opc7,opc8,comensales;
	float Total,Tprod; //El total tiene que ir a comensales para pode hacer el calculo de la cuenta a pagar
	string Descrip;
	int platillo,sub,i;
	public:
	Comidas();
	~Comidas();
	void VerComidas();
	float Ventas(int plt);
	float Acum(int subT);
	float AcumC(int num);
//	void VerPedido();
	void Ticket();
	float retTotal();
};

class Comensales:public Comidas{
protected:
		string nombre, apellido1, apellido2;
		string email,direccion,fechaven, telefono;
		char CVV[3],tarjeta[16];
		int opc2,efep,opc3;
		float efec,cambio;
	public:
		Comensales();
		~Comensales();
		void Menu_comensales();
		void LeeDatosC();
		void VerDatosC();
		void Metodo_pago();
		void Facturacion();	
};
class Empleados: public Comensales{
	protected:	
		string cargo,clave,c,salario; 
		int i,opc;
	public: 
		Empleados();
		~Empleados();
		void LeeDatosE();
		void VerDatosE();
		void Menu_empleados();
};

class Producto{ //jitomate	jit123	5cajas	200	
	protected:
		Graficos objprod;
		string nomprod,clavprod;
		int cantprod,i;
		float precprod,subtot;
	public:
		Producto();
		~Producto();
		void Compra();
		float VerCompra();
		float Retsubtot();
		float Acumsubtot(float subt);
		friend class Proveedores;
};

class Proveedores{
	protected:
		Graficos objprov;
		string NomProv,NomVta,telef;
		int produc,i,id,opc9;
		Producto *Verduras1,*Verduras2,*Fruta1,*Fruta2; //HACEMOS UNA ANIDACION
		int TamV1,TamV2,Tamf1,Tamf2; //para mis memorias dinamicas
		float Total;
	public:
		Proveedores();
		~Proveedores();
		void LeeDatosP(); 
		void VerDatosP();
		void Menu_provedores();
		float Retotal();

};

class Facturacion: public Empleados{
	protected: 
	string RFC,email,direccion, razon_s,ciudad, CFDI,CP;
	float iva;
	int opc3;
	public:
		Facturacion();
		~Facturacion();
		void MenuFactura();
		void Facturar();
		void VerFactura();
		float IVA();
		void BorrarFactura();
};

class Acceso: public Facturacion{
	protected:
		/*char contra[10];
		int cont=0, correcto=0;
		char pass;*/
		int cla,Clave,resp;
	    string usu,usuario;
	public:
		~Acceso();
		Acceso();
	void Leerc();
	int Impc();
};

class Menu: public Acceso, public Proveedores, public Producto{ //public Comensales,
	protected:
	//Usuario *obj=new Usuario(); 
	///Proveedores *obj2=new Proveedores();
	int opc1,opc3, i;
	public:
	Menu();
	~Menu();
	void VerMenu();
	
};

int main(){
	
	system("mode con: cols=80 lines=25");
	system("COLOR F1");
	
	Acceso *objA=new Acceso();
	objA->Impc();

	//textcolor(9);
	/*Acceso c;
   if(	c.Impc() == 1 ){
	   cout<<"correcto, entra al proyecto\n";
	   system("pause");
	}else {cout<<" no puede entrar al proyecto \n";
		system("pause");
		}*/
	
	
	Menu obj1;
	obj1.VerMenu();
	
	/*Menu *OBJ1=new Menu();
	OBJ1->VerMenu();
	system("pause");*/
	delete objA;
	
	
	//delete OBJ1;
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Graficos::Graficos(){
	i=0;
}

Graficos::~Graficos(){
	cout<<"Liberando memoria de gr\160ficos"<<endl;
}

void Graficos::dibujarCuadro(int x1,int y1,int x2,int y2){
	    for (i=x1;i<x2;i++){
			gotoxy(i,y1); cout << "\304"; //linea horizontal superior
			gotoxy(i,y2); cout << "\304"; //linea horizontal inferior
	    }
	
	    for (i=y1;i<y2;i++){
			gotoxy(x1,i); cout <<"\263"; //linea vertical izquierda
			gotoxy(x2,i); cout <<"\263"; //linea vertical derecha
		}
		
	    gotoxy(x1,y1); cout<< "\332"; 
	    gotoxy(x1,y2); cout<< "\300";
	    gotoxy(x2,y1); cout<< "\277";
	    gotoxy(x2,y2); cout<< "\331";
}

void Graficos::gotoxy(int x,int y){
	HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos); 
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Acceso::Acceso(){
	//cont=0, correcto=0;  //contra=""; //pass="1234";
	usuario = "admin";
	Clave = 12345;
	usu=" ";
	cla=0;	
	resp=1;
}

Acceso::~Acceso(){
	
}

void Acceso::Leerc()
{
	dibujarCuadro(0,0,78,24);//COLUM, LINEAS
	dibujarCuadro(1,1,77,3);
	gotoxy(33,2);cout << "RESTATUSARS-COV2 ";
	//dibujarCuadro(22,8,60,18);// LINEA VERTICAL IZQ, LINEA HORIZONTAL SUP, LINEA VERT DEREC, LINEA HORIZ INFERIOR
	gotoxy(23,9);cout << "Introduce el usuario (admin): ";
	dibujarCuadro(20,10,60,12);
    gotoxy(23,14);cout << "Introduce tu clave (12345): ";
	dibujarCuadro(20,15,60,17);
	gotoxy(24,11);cout<<" ";cin>>usu;
	gotoxy(24,16);cout<<" ";cin>>cla;
}

int Acceso::Impc()
{	resp=0;
	do
	{
	    Leerc();
		if(cla!=Clave || usu!=usuario)	
		{	
			gotoxy(23,20);cout<<"*Usuario o Contrasenia incorrecta."<<endl;
			gotoxy(23,21);cout<<"*Ingrese datos v\xA0lidos."<<endl;
			gotoxy(23,22);system("pause");
			system("cls");
			resp++;
		}
			if(resp==3)return 0;
	}while(cla!=Clave || usu!=usuario);
	if(cla==Clave && usu==usuario){
			/*cout<<"acceso concedido"<<endl;*/
	}
   return 1;	
}

/*void Acceso::Contrasenia(){
	
	//system("color B0");
    /**arreglo de caracteres
    cout<<"Introduce tu password\n";
    cin>>contra;
    if(strcmp(contra,"1234")==0)//si son iguales regresa un 0,strcmp(string compare)
        correcto=1;
    else
    {
        while(strcmp(contra,"1234")!=0 && cont<3)//si devuelve 0 son iguales
        {
            cont++;
            cout<<"Introduce tu password de nuevo, intento ["<<cont<<"]: ";
            cin>>contra;
        }
    }
    if(cont>=3 && correcto==0)
    {
        cout<<"Agotaste los 3 intentos\n";
        exit(0);
    }
    else
    	system("cls");
    	cout<<"BIENVENIDO AL SISTEMA\n";
        //Sleep(2500);
        //portada();
}*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Menu::Menu(){
		opc1=0;
	}
	Menu::~Menu(){
		//delete obj;
		//delete obj2;
	cout<<"Liberando memoria en menu \n";
	//system("pause");	
	}	
	
	void Menu::VerMenu(){
		
		
		
		do{
		
			system("cls");
		dibujarCuadro(0,0,78,24);
		dibujarCuadro(1,1,77,3);
		gotoxy(15,2);cout<<".......BIENVENIDO A RESTAUSARS-COV2.......\n";
		gotoxy(25,5);cout<<"�Quien nos visita?\n";
		gotoxy(25,8);cout<<"1.Comensal\n";
		gotoxy(25,9);cout<<"2.Empleado\n";
		gotoxy(25,10);cout<<"3.Proveedor\n";
		gotoxy(25,11);cout<<"4.Facturar\n";
		gotoxy(25,13);cout<<"5.Salir del programa \n";
		gotoxy(25,15);cout<<"Digite una opcion...->"; cin>>opc1;
		switch(opc1){
			case 1:
			 	Menu_comensales();VerMenu();//no entra cuando se regresa al menu inicial 
				break;
			case 2: 
			 	Menu_empleados();VerMenu();
				break;
			case 3:
				Menu_provedores();VerMenu();
				break;
			case 4:
				MenuFactura();VerMenu();
				break;	
			case 5:
				cout<<"Gracias por visitar RESTAUSARS-COV2\n";
				cout<<"Vuelva pronto\n";
				break;
			default: 
				cout<<"Opci�n no v�lida, intente de nuevo\n"; VerMenu();
			
		}
		
	}while(opc1>5 || opc1<1);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Comidas::Comidas(){
		num=0;  opc8=0;  
		Total=0; platillo=0;
		sub=0; opc7=0;
	}
Comidas::~Comidas(){
	
		cout<<"Liberando memoria menu comidas\n";
	}

void Comidas::VerComidas(){
		do{
			system("cls");
		dibujarCuadro(0,0,78,24);
		dibujarCuadro(1,1,77,3);
		gotoxy(32,2);cout<<"MENU DE SNACKS\n";
		gotoxy(10,4);cout<<"(1)Hamburguesa sencilla...................$40\n";
		gotoxy(10,5);cout<<"(2)Hamburguesa doble carne................$65\n";
		gotoxy(10,6);cout<<"(3)Hot dog sencillo.......................$25\n";
		gotoxy(10,7);cout<<"(4)Hotdog con tocino......................$30\n";
		gotoxy(10,8);cout<<"(5)Orden de alitas(7 pzas)................$60\n";
		gotoxy(10,9);cout<<"(6)Pizza..................................$60\n";
		gotoxy(10,10);cout<<"(7)Orden de alitas(7 pzas)................$60\n";
		gotoxy(10,11);cout<<"(8)Orden de alitas(7 pzas)................$60\n";
		gotoxy(10,12);cout<<"(9)Orden de alitas(7 pzas)................$60\n";
		gotoxy(10,13);cout<<"(10)Orden de alitas(7 pzas)................$60\n";
		gotoxy(10,14);cout<<"(11)Orden de alitas(7 pzas)................$60\n";
		gotoxy(10,15);cout<<"(12)Orden de alitas(7 pzas)................$60\n";
		gotoxy(10,16);cout<<"(13)Orden de alitas(7 pzas)................$60\n";
		gotoxy(10,17);cout<<"(14)Orden de alitas(7 pzas)................$60\n";
		gotoxy(10,18);cout<<"(15)Orden de alitas(7 pzas)................$60\n";
		gotoxy(10,20);cout<<"Ingrese la opci\xA2n deseada: "; cin>>opc8;
		
		
		
		switch(opc8){
			case 1:	gotoxy(18,12);cout<<"Hamburguesa sencilla";
				gotoxy(10,13);cout<<"Deliciosa carne de res a la plancha,con queso americano y";
				gotoxy(10,14);cout<<"vegetales frescos, todo dentro de nuestro fabuloso pan casero";
				gotoxy(10,16);cout<<"\xA8"<<"Cu\xA0ntas desea ordenar? "; 
				gotoxy(10,17);cin>>num;
				//pt=&opc;//inicializaci�n del puntero
				//pt=&MTZ[0]; //apunta al valor del primero elemento, que es el precio del platillo
				//platillo=*pt;//asigna el valor del puntero a una variable
				//cout<<platillo<<endl;
				platillo=40;
				Ventas(platillo);
				break;
			case 2:gotoxy(18,12);cout<<"Hamburguesa doble carne";
				gotoxy(10,13);cout<<"Dos porciones de nuestra deliciosa carne de res a la plancha";
				gotoxy(10,14);cout<<"con queso americano, jamon,queso Oaxaca y vegetales frescos. ";
				gotoxy(10,15);cout<<"Todo dentro de nuestro fabuloso pan casero";
				gotoxy(10,17);cout<<"\xA8"<<"Cu\xA0ntas desea ordenar? "; 
				gotoxy(10,18);cin>>num;
				//pt=&opc;
				//pt=&MTZ[1]; platillo=*pt;
				//cout<<platillo<<endl;
				platillo=65;
				Ventas(platillo);
				break;
			case 3:gotoxy(18,12);cout<<"Hot dog sencillo";
				gotoxy(10,13);cout<<"Exquisita salchica de pavo con cebollitas acarameladas encima y";
				gotoxy(10,14);cout<<"dentro de nuestro fabuloso pan casero ";
				gotoxy(10,16);cout<<"\xA8"<<"Cu\xA0ntas desea ordenar? "; 
				gotoxy(10,17);cin>>num;
				//pt=&opc;
				//pt=&MTZ[2]; platillo=*pt;
				platillo=25;
				Ventas(platillo);
				break;
			case 4:	gotoxy(18,12);cout<<"Hotdog con tocino";
				gotoxy(10,13);cout<<"Exquisita salchica de pavo envuelta en tocino, con cebollitas ";
				gotoxy(10,14);cout<<"acarameladas encima dentro de nuestro fabuloso pan casero";
				gotoxy(10,16);cout<<"\xA8"<<"Cu\xA0ntas desea ordenar? "; 
				gotoxy(10,17);cin>>num;
				//pt=&opc;
				//pt=&MTZ[3]; platillo=*pt;
				//cout<<platillo<<endl;
				platillo=30;
				Ventas(platillo);
				break;
			case 5:gotoxy(18,12);cout<<"Orden de alitas";
				gotoxy(10,13);cout<<"Deliciosas alitas al carb�n ba�adas en nuestra ";
				gotoxy(10,14);cout<<"picosita salsa BBQ,receta de la casa.";
				gotoxy(10,16);cout<<"\xA8"<<"Cu\xA0ntas desea ordenar? "; 
				gotoxy(10,17);cin>>num;
				//pt=&opc;
				//pt=&MTZ[4];  platillo=*pt;
				//cout<<*pt<<endl;
				platillo=60;
				Ventas(platillo);
				break;
			//case 6:system("cls");break;
			default: gotoxy(18,12);cout<<"Opci\xA2n no v\xA0lida, int\x82ntelo de nuevo";gotoxy(18,13); system("pause");
		}
		}while(opc8<1||opc8>5);
		
	}

float Comidas::Ventas(int plt){
		sub=num*platillo;//precio del platillo por la cantidad
		//cout<<"$"<<sub<<".00\n";
		//system("pause");
		
		do{	
		system("cls");
		dibujarCuadro(0,0,78,24);
		dibujarCuadro(10,7,60,18);// LINEA VERTICAL IZQ, LINEA HORIZONTAL SUP, LINEA VERT DEREC, LINEA HORIZ INFERIOR
		gotoxy(13,10);cout<<"[1]Ordenar algo mas \n";
		gotoxy(13,11);cout<<"[2]Ir a pagar\n";
		gotoxy(13,13);cout<<"Digite la opcion a realizar: ";cin>>opc7;
		switch(opc7){
			case 1:	Acum(sub);//si quiere agregar otro platillo se acumula primero el subtotal del primer platillo agregado
					VerComidas(); break;//regresa al menu de comidas
			case 2: Acum(sub); break;//si ya no se van a agregar mas platillos envia el subtotal al total
					//retTotal();
			default: gotoxy(13,15);cout<<"Opcion no valida, intente de nuevo\n";
		}	
	}while(opc7<1 || opc7>2);
	}
	
	float Comidas::Acum(int subT){
		Total=Total+subT;//acumula los subtotales
		return Total;
	}
	float Comidas::AcumC(int num){
		Tprod=Tprod+num;//acumula la cantidad de productos ordendados
		return Tprod;
	}
	
	void Comidas::Ticket(){
			gotoxy(13,10);cout<<"Cantidad de productos: "<<Tprod;
			retTotal();
		}
	float Comidas::retTotal(){
		gotoxy(13,11);cout<<"Subtotal: $"<<sub<<endl;
		gotoxy(13,12);cout<<"Total: $"<<Total<<endl;
		gotoxy(13,13);cout<<"Gracias por su compra :)\n";
		
		
		//return Total;//retorna para la fucion de comensales
	}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Empleados::Empleados(){
		clave=""; salario="";
	}
	
	Empleados::~Empleados(){
		cout<<"Liberando memoria"<<endl;
	}
	
	void Empleados::Menu_empleados(){
		do{
		system("cls");
		dibujarCuadro(0,0,78,24);
		dibujarCuadro(1,1,77,3);
		gotoxy(30,2);cout<<"MENU DE EMPLEADOS"<<endl;
		gotoxy(20,8);cout<<"1. INGRESAR DATOS DE EMPLEADO"<<endl;
		gotoxy(20,9);cout<<"2. VISUALIZAR DATOS DEL EMPLEADO [CON CLAVE]"<<endl;
		gotoxy(20,10);cout<<"3. REGRESAR AL MENU PRINCIPAL"<<endl;
		gotoxy(20,12);cout<<"Digite el numero de opcion a realizar: ";cin>>opc;
		switch(opc){
			case 1: LeeDatosE();break;
			case 2: VerDatosE();break;
			case 3: system("cls"); break;
			default: gotoxy(20,14);cout<<"Opcion no valida, intente de nuevo";gotoxy(20,15);system("pause"); //Agregar system("pause") para que muestre que la opcion no es valida a los demas submenus
		}
	}	while(opc<1 || opc>3);
}
		
	
	void Empleados::LeeDatosE(){
		
		system("cls");
		dibujarCuadro(0,0,78,24);
		dibujarCuadro(1,1,77,3);	
		gotoxy(27,2);cout<<"Ingrese sus datos personales\n";
		cin.ignore();
		gotoxy(2,6);cout<<"Clave: ";getline(cin,clave);
		gotoxy(2,8);cout<<"Cargo: "; getline(cin,cargo);
		gotoxy(2,9);cout<<"Nombre : "; getline(cin,nombre);
		gotoxy(2,10);cout<<"Primer apellido : "; getline(cin,apellido1);
		gotoxy(2,11);cout<<"Segundo apellido : "; getline(cin,apellido2);
		gotoxy(2,12);cout<<"E-mail : "; getline(cin,email);
		gotoxy(2,13);cout<<"Direccion: "; getline(cin,direccion);
		gotoxy(2,14);cout<<"Telefono : ";getline(cin,telefono);
		gotoxy(2,15);cout<<"Salario:  $"; getline(cin,salario); 
		gotoxy(2,17);system("pause");
		system("cls");
		dibujarCuadro(0,0,78,24);
		gotoxy(30,11);cout<<"REGISTRO EXITOSO";	
		gotoxy(20,16);system("pause");
		
		Menu_empleados();
	}
	
	void Empleados::VerDatosE(){
		
		do{
			system("cls");
			dibujarCuadro(0,0,78,24);
			cin.ignore();
			gotoxy(13,8);cout<<"Digite la clave del empleado: ";getline(cin,c); //creo que se puede cambiar po rel algoritmo de la clave de acceso aqui
		}while(c.compare(clave)!=0);
		system("cls");
		dibujarCuadro(0,0,78,24);
		dibujarCuadro(2,7,60,14);// LINEA VERTICAL IZQ, LINEA HORIZONTAL SUP, LINEA VERT DEREC, LINEA HORIZ INFERIOR
		gotoxy(3,6);cout<<"Datos personales del empleado "<<clave<<endl;
		gotoxy(3,8);cout<<"Clave: "<<clave<<endl;
		gotoxy(3,9);cout<<"Nombre : "<<nombre<<" "<<apellido1<<" "<<apellido2<<endl;
		gotoxy(3,10);cout<<"E-mail : "<<email<<endl;
		gotoxy(3,11);cout<<"Direccion: "<<direccion<<endl;
		gotoxy(3,12);cout<<"Telefono : "<<telefono<<endl;
		gotoxy(3,13);cout<<"Salario: $"<<salario<<endl; 
		gotoxy(3,18);system("pause");
		Menu_empleados();
	
	}
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
	Comensales::Comensales(){
		nombre=""; apellido1=""; apellido2="";
		email=""; direccion="";
		telefono=""; fechaven=""; opc2=0; cambio=0;
		efec=0; opc3=0;
	}
		Comensales::~Comensales(){
			cout<<"Liberando memoria\n"<<endl;
			system("pause");
		}
		
		void Comensales::Menu_comensales(){
			do{
			system("cls");
			dibujarCuadro(0,0,78,24);
			dibujarCuadro(1,1,77,3);
			gotoxy(35,2);cout<<"COMENSALES"<<endl;	
			gotoxy(20,6);cout<<"Digite la opcion a realizar"<<endl;
			gotoxy(25,8);cout<<"1. Lee datos "<<endl;
			gotoxy(25,9);cout<<"2. Ver datos"<<endl;
			gotoxy(25,10);cout<<"3. Volver al menu"<<endl;
			gotoxy(25,12);cout<<"Digite el opcion: ";cin>>opc3;
			switch(opc3){
				case 1: LeeDatosC();break;
				case 2: VerDatosC();break;
				case 3: system("cls");break;  
				//case 4: gotoxy(20,12); cout<<"Gracias por visitar RESTAUSARS-COV2\n";
				cout<<"Vuelva pronto\n";break;
			}
			
			}while(opc3<1 || opc3>4);
		}
		
		void Comensales::LeeDatosC(){			
			system("cls");
			dibujarCuadro(0,0,78,24);
			dibujarCuadro(1,1,77,3);
			cin.ignore();
			gotoxy(30,2);cout<<"REGISTRO DEL CLIENTE\n";
			gotoxy(20,5);cout<<"Ingrese sus datos personales\n";
			gotoxy(2,7);cout<<"Nombre : "; getline(cin,nombre);
			gotoxy(2,8);cout<<"Primer apellido : "; getline(cin,apellido1);
			gotoxy(2,9);cout<<"Segundo apellido : ";getline(cin,apellido2);
			gotoxy(2,10);cout<<"E-mail : "; getline(cin,email);
			gotoxy(2,11);cout<<"Direccion de entrega: "; getline(cin,direccion);
			gotoxy(2,12);cout<<"Telefono (Este ser� el m�todo de contacto con el repartidor): ";getline(cin,telefono);
			gotoxy(2,14);cout<<"Estas listo para ordenar\n"; 
			gotoxy(2,15);system("pause");
			VerComidas();
			Metodo_pago();	
			Ticket();
		}
	
		
		void Comensales::VerDatosC(){
			system("cls");
			dibujarCuadro(0,0,78,24);
			dibujarCuadro(1,1,77,3);
			gotoxy(15,2);cout<<"Verifique que sus datos sean correctos\n";
			dibujarCuadro(5,7,60,14);// LINEA VERTICAL IZQ, LINEA HORIZONTAL SUP, LINEA VERT DEREC, LINEA HORIZ INFERIOR
				gotoxy(6,9);cout<<"Nombre : "<<nombre<<" "<<apellido1<<" "<<apellido2<<endl;
				gotoxy(6,10);cout<<"Direccion : "<<direccion<<endl;
				gotoxy(6,11);cout<<"E-mail : "<<email<<endl;
				gotoxy(6,12);cout<<"Telefono : "<<telefono<<endl;
				gotoxy(6,20);system("pause");
				Menu_comensales();
		}
		void Comensales::Metodo_pago(){
			do{
				system("cls");
				dibujarCuadro(0,0,78,24);
			dibujarCuadro(10,7,60,18);// LINEA VERTICAL IZQ, LINEA HORIZONTAL SUP, LINEA VERT DEREC, LINEA HORIZ INFERIOR
			gotoxy(28,5);cout<<"METODO DE PAGO";
			gotoxy(13,8);cout<<"Escoja un metodo de pago";
			gotoxy(13,10);cout<<"1.Efectivo";
			gotoxy(13,11);cout<<"2.Tarjeta de credito o debito";
			gotoxy(13,13);cout<<"Digite una opcion...->"; cin>>opc2;
			switch(opc2)
			{
				case 1:
					do{
					system("cls");
					dibujarCuadro(0,0,78,24);
					dibujarCuadro(1,1,77,3);
					gotoxy(25,2);cout<<"Pago en efectivo";
					gotoxy(28,5);cout<<"Monto a pagar: "<<Total<<endl;
					dibujarCuadro(10,7,60,18);
					gotoxy(13,8);cout<<"�Cuanto dinero en efectivo dara?"; 
					gotoxy(14,9);cout<<"$";cin>>efec; //SE TIENE QUE BORRAR PARA PODER METER OTRA CANTIDAD VALIDA
					}while(efec<Total);
					cambio=efec-Total;
					gotoxy(13,11);cout<<"Cambio en efectivo: $"<<cambio<<endl;
					gotoxy(13,15);system("pause");
				break;
				case 2:
					do{
					system("cls");
					dibujarCuadro(0,0,78,24);
					dibujarCuadro(1,1,77,3);
					gotoxy(20,2);cout<<"Pago con Tarjeta de Credito o Debito";
					gotoxy(28,5);cout<<"Monto a pagar: "<<Total<<endl;
                    gotoxy(13,5);cout<<"Ingrese los 16 digitos de su tarjeta: ";
                    dibujarCuadro(12,6,60,8);// LINEA VERTICAL IZQ, LINEA HORIZONTAL SUP, LINEA VERT DEREC, LINEA HORIZ INFERIOR
                    gotoxy(13,7);cout<<" ";cin>>tarjeta;
                    gotoxy(13,10);cout<<"Ingrese su codigo de seguridad CVV:";
                    dibujarCuadro(12,11,60,13);// LINEA VERTICAL IZQ, LINEA HORIZONTAL SUP, LINEA VERT DEREC, LINEA HORIZ INFERIOR
                    gotoxy(13,12);cout<<" ";cin>>CVV;
					gotoxy(13,15);system("pause");//system("cls");
                    }while(((strlen(tarjeta)>16)||(strlen(tarjeta)<16) ) && ((strlen(CVV)>3)||(strlen(CVV)<3))); //SOLO VERIFICA EL CVV Y NO el num de digitos de la targeta
				break;
				default: gotoxy(13,17);cout<<"Opcion no valida, intente de nuevo";
			}
			}while(opc2<1||opc2>2);
		}
	//////////////////////////////////////////////////////////
	Facturacion::Facturacion(){
		RFC=""; email="";direccion=""; razon_s="";
		CP="";
		 CFDI="";
	}
		Facturacion::~Facturacion(){
			cout<<"Liberando memoria\n";
		}
		void Facturacion::MenuFactura(){
			do{
				system("cls");
				dibujarCuadro(0,0,78,24);
			dibujarCuadro(1,1,77,3);// LINEA VERTICAL IZQ, LINEA HORIZONTAL SUP, LINEA VERT DEREC, LINEA HORIZ INFERIOR
			gotoxy(35,2);cout<<"FACTURACION";
			gotoxy(20,6);cout<<"Digite la opcion a realizar"<<endl; fflush(stdin);
			gotoxy(20,8);cout<<"1. Generar Factura "<<endl;
			gotoxy(20,9);cout<<"2. Ver Factura"<<endl;
			gotoxy(20,10);cout<<"3. Borrar Factura"<<endl;
			gotoxy(20,11);cout<<"4. Regresar al Menu Principal"<<endl;
			//cout<<"5. Salir del programa"<<endl;
			gotoxy(20,13);cout<<"Digite la opcion: ";
			cin>>opc3;
			switch(opc3){
				case 1: Facturar();
				break;
				case 2: VerFactura();
				break;
				case 3: system("cls");break;
				case 4: system("cls");break;//Menu_comensales();
				/*case 5: cout<<"Gracias por visitar RESTAUSARS-COV2\n";
				cout<<"Vuelva pronto\n"; system("pause"); break;*/
				default: cout<<"Opcion no valida\n"; 
			}
			
			}while(opc3<1 || opc3>4);
		}
		void Facturacion::Facturar(){
			system("cls");
			dibujarCuadro(0,0,78,24);
			dibujarCuadro(1,1,77,3);// LINEA VERTICAL IZQ, LINEA HORIZONTAL SUP, LINEA VERT DEREC, LINEA HORIZ INFERIOR
			gotoxy(30,2);cout<<"DATOS FISCALES "<<endl; cin.ignore();
			gotoxy(20,6);cout<<"Denominacion o Razon social : "; getline(cin,razon_s); cin.ignore();
			gotoxy(20,7);cout<<"RFC : "; getline(cin,RFC); cin.ignore();
			gotoxy(20,8);cout<<"Direccion : "; getline(cin,direccion); cin.ignore();
			gotoxy(20,9);cout<<"Codigo Postal : "; getline(cin,CP);cin.ignore();
			gotoxy(20,10);cout<<"Correo electronico : "; getline(cin,email); cin.ignore();
			gotoxy(20,11);cout<<"Uso CFDI:"; getline(cin,CFDI); cin.ignore();
			gotoxy(20,12);cout<<"Telefono : ";getline(cin,telefono);cin.ignore();
			gotoxy(2,14);cout<<"Antes de presionar continuar verifique que sus datos sean correctos";
			gotoxy(2,16);system("pause");
			system("cls");	
			do{
			system("cls");
			dibujarCuadro(0,0,78,24);
			dibujarCuadro(12,7,66,18);// LINEA VERTICAL IZQ, LINEA HORIZONTAL SUP, LINEA VERT DEREC, LINEA HORIZ INFERIOR
			gotoxy(18,9);cout<<"Pulse la tecla segun opcion que desee realizar";
			gotoxy(18,11);cout<<"[1] Cambiar datos";
			gotoxy(18,12);cout<<"[2] Ir a ver la factura";
			gotoxy(18,14);cout<<"Opcion: ";cin>>opc3;
		
			switch(opc3){
				case 1: Facturar();break;
				case 2: VerFactura();break;
				default: cout<<"Opcion no valida"; system("pause"); 
			}
		}while(opc3<1 || opc3>2);
			/*if(opc3==1){
					Facturar();}
			else{	
			VerFactura();}
			system("pause");*/
		}
		float Facturacion::IVA(){
			iva=Total*0.16;
			return(iva);
		}
		void Facturacion::VerFactura(){
			system("cls");
			dibujarCuadro(0,0,78,24);
			dibujarCuadro(1,1,77,3);// LINEA VERTICAL IZQ, LINEA HORIZONTAL SUP, LINEA VERT DEREC, LINEA HORIZ INFERIOR
			gotoxy(30,2);cout<<"FACTURA";
			cin.ignore();
			gotoxy(18,5);cout<<"Denominacion o Razon social......: "<<razon_s<<endl;
			gotoxy(18,6);cout<<"RFC..............................: "<<RFC<<endl;
			gotoxy(18,7);cout<<"Direccion........................: "<<direccion<<endl;
			gotoxy(18,8);cout<<"Codigo Postal....................: "<<CP<<endl;
			gotoxy(18,9);cout<<"Correo electronico...............: "<<email<<endl;
			gotoxy(18,10);cout<<"Uso CFDI.........................: "<<CFDI<<endl;
			gotoxy(18,11);cout<<"Telefono.........................: "<<telefono<<endl;
			gotoxy(18,12);cout<<"Descripcion del gasto:...........: Alimento"<<endl;
			gotoxy(18,13);cout<<"__________________________________________________"<<endl;
			gotoxy(18,14);cout<<"Monto sin IVA....................: $"<<Total<<endl;
			gotoxy(18,15);cout<<"IVA..............................: $"<<IVA()<<endl;
			gotoxy(18,16);cout<<"Monto total......................: $"<<Total+iva<<endl;
			
			//cout<<"�Desea regresar al Menu Principal?\n";
			/*cout<<" ";cin>>opc3;
			if(opc3==1){
				system("cls");
					}
			else{
			cout<<"Gracias por visitarnos"<<endl;
			
			}*/
			gotoxy(16,20);system("pause"); system("cls");
		}
		
		/*void Facturacion::BorrarFactura(){
			
		}*/
///////////////////////////////////////////////////////////////////////////////////////////

Producto::Producto(){
	nomprod="";	clavprod="";cantprod=0; precprod=0;	subtot=0;  i=0; //total=0;
}

Producto::~Producto(){
	cout<<"Liberando memoria en Producto\n";
}

void Producto::Compra()//lectura de datos para comprar, pondremos, nombre,cantidad
		{ 
			//cout<<"\n";
			//objprod.dibujarCuadro(0,0,78,24);
			//objprod.dibujarCuadro(1,1,77,3);
			objprod.gotoxy(3,4);cout<<"Clave del producto: ";cin>>clavprod; cin.ignore();
			objprod.gotoxy(3,5);cout<<"Drescripcion del producto: ";getline(cin,nomprod);
			objprod.gotoxy(3,6);cout<<"Cantidad a comprar: ";cin>>cantprod;
			objprod.gotoxy(3,7);cout<<"Precio: "; cin>>precprod;
		}

float Producto::VerCompra(){
			//cout<<"\n";
			//objprod.dibujarCuadro(0,0,78,24);
			//objprod.dibujarCuadro(1,1,77,3);
			objprod.gotoxy(3,10);cout<<"Clave del producto: "<<clavprod<<endl;
			objprod.gotoxy(3,11);cout<<"Drescripcion del producto: "<<nomprod<<endl;
			objprod.gotoxy(3,12);cout<<"Cantidad a comprar: "<<cantprod<<endl;
			objprod.gotoxy(3,13);cout<<"Precio: "<<precprod<<endl;
			subtot=cantprod*precprod;
			//Acumsubtot(subtot);
			objprod.gotoxy(3,14);cout<<"Subtotal : "<<subtot<<endl;
			//return subtot;
}

float Producto::Retsubtot(){ return subtot;  }

	/*float Producto::Acumsubtot(float subt)
	{
		total=total+subt;//acumula los subtotales
		return total;
	}*/


///////////////////////////////////////////////////////////////////////////////////////////
Proveedores::Proveedores(){
	 //nomprov=""; id=0; descrip=""; 
	 produc=0; opc9=0; i=0;  Total=0;
	 
}

		Proveedores::~Proveedores(){
			cout<<"Liberando memoria en proveedores\n";
			if(Verduras1!=NULL && Fruta1!=NULL){
            delete []Verduras1; delete []Fruta1;}	
		}
		
		void Proveedores::Menu_provedores(){
			do{
			system("cls");
			objprov.dibujarCuadro(0,0,78,24);
			objprov.dibujarCuadro(1,1,77,3);
			objprov.gotoxy(35,2);cout<<"MENU DE PROVEDORES"<<endl;
			
			objprov.gotoxy(25,8);cout<<"[1] Registrar datos de provedor"<<endl;
			
			objprov.gotoxy(25,9);cout<<"[2] Visualizar datos de provedor"<<endl;
			
			objprov.gotoxy(25,10);cout<<"[3] Regresar al menu principal"<<endl;
			
			objprov.gotoxy(25,11);cout<<"Digite la opcion a realizar: ";cin>>opc9;
			
				switch(opc9){
					case 1: LeeDatosP(); break;
					case 2: VerDatosP(); break;
					case 3:  system("cls"); break;
					default: objprov.gotoxy(25,13);cout<<"Opcion invalida"<<endl;objprov.gotoxy(25,14); system("pause"); break;
				}
			}while(opc9!=3);
		}
		
		void Proveedores::LeeDatosP()
		{	
			cin.ignore();
			system("cls");
			objprov.dibujarCuadro(0,0,78,24);
			objprov.dibujarCuadro(1,1,77,3);
			objprov.gotoxy(30,2);cout<<"REGISTRO PROVEEDOR";
			objprov.gotoxy(3,4);cout<<"Nombre del proveedor : "; getline(cin,NomProv);
			objprov.gotoxy(3,5);cout<<"Nombre del vendedor : "; getline(cin,NomVta);
			objprov.gotoxy(3,6);cout<<"Telefono del vendedor : "; getline(cin,telef);
			//objprov.gotoxy(3,7);system("pause");
			
			//UTILIZAMOS CICLOS PARA NUESTRA MEMORIA DINAMCA
			//cout<<"\n";
			 //MD para verduras1
			
			objprov.dibujarCuadro(0,0,78,24);
			//objprov.dibujarCuadro(1,1,77,3);
			objprov.gotoxy(3,8);cout<<"Cuantos verduras se compraran= ";
			cin>>TamV1;
			Verduras1 = new Producto[TamV1];
			objprov.gotoxy(3,9);cout<<"Cuantos frutas se compraran= ";
			cin>>Tamf1;
			Fruta1 = new Producto[Tamf1];
			//COMPROBANDO QUE FUNCIONA LA MEMORIA DINAMICA
			if(Verduras1==NULL && Fruta1==NULL){
	        objprov.gotoxy(3,10);cout<<"No hay mem din \n"; objprov.gotoxy(3,11);system("pause"); 
			exit(0);}
			
			system("cls");
			objprov.dibujarCuadro(0,0,78,24);
			objprov.gotoxy(25,2);cout<<"Ingreso compra de verduras ";
			for(i=0;i<TamV1;i++){
				Verduras1[i].Compra();
				Total=Total+Verduras1[i].Retsubtot();
			} 
			objprov.gotoxy(3,8);system("pause");
			
			//MD para frutas1	
			system("cls");
			objprov.dibujarCuadro(0,0,78,24);
			//objprov.gotoxy(3,9);cout<<"Cuantos frutas se compraran= ";
			//cin>>Tamf1;	
			objprov.gotoxy(25,2);cout<<"Ingreso compra de frutas \n";
			for(i=0;i<Tamf1;i++){
				Fruta1[i].Compra();
				Total=Total+Fruta1[i].Retsubtot(); 
				}
			system("cls");
					
		}
		
	
		void Proveedores::VerDatosP()
		{   system("cls");
			system("mode con: cols=80 lines=30");
			objprov.dibujarCuadro(0,0,78,28);
			objprov.dibujarCuadro(1,1,77,3);
			objprov.gotoxy(35,2);cout<<"Proveedores";
			objprov.gotoxy(3,4);cout<<"Nombre del proveedor :"<<NomProv;
	        objprov.gotoxy(3,5);cout<<"Nombre del vendedor :"<<NomVta;
	        objprov.gotoxy(3,6);cout<<"Telefono del vendedor :"<<telef; 
			
	        
			objprov.gotoxy(3,8);cout<<"Verduras"; //PROBLEMAS AL IMPRIMIR CON gotoxy Se traslapan los datos y solo se ve el de frutas
	        for(i=0;i<TamV1;i++)
	        {   Verduras1[i].VerCompra(); }
	        
	        objprov.gotoxy(3,16);cout<<"Frutas";
	        for(i=0;i<Tamf1;i++)
	        {   Fruta1[i].VerCompra(); }
	        
	        //TOTAL
			//cout<<"Total : "<<Total<<endl; //NO IMPRIME EL TOTAL, IMPRIME UN CERO
			objprov.gotoxy(3,20);system("pause");
			system("cls");
			system("mode con: cols=80 lines=25");
        } 
        
        float Proveedores::Retotal(){ return Total; }
		
