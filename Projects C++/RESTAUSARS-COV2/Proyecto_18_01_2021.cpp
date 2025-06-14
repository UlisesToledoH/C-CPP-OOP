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
#include <winbgim.h>
using namespace std; 

class Graficos{
	protected:
		int i;
	public:
	Graficos();
	~Graficos();
	void dibujarCuadro(int x1,int y1,int x2,int y2);
	void gotoxy(int x,int y);
	void Portada();
	//friend class Producto;
	//friend class Proveedores;
};

class Comidas: public Graficos{
	protected:
	int num,opc7,opc8,comensales,Tprod,sub2,beb,num2,ref;
	float Total; //El total tiene que ir a comensales para pode hacer el calculo de la cuenta a pagar
	string Descrip;
	int platillo,sub,i;
	public:
	Comidas();
	~Comidas();
	void VerComidas();
	float Ventas(int plt,int beb);
	float Acum(int sub,int sub2);
	void VerPedido();
	float retTotal();
	float AcumC(int num,int num2);
	void Bebidas();
	void Ticket();
};

class Comensales:public Comidas{
protected:
		string nombre, apellido1, apellido2;
		string email,direccion,fechaven, telefono;
		char CVV[3],tarjeta[16];
		int opc2,efep,opc3,bandera,bandera2;
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
		string cargo,clave,c,salario ,emailE,telefonoE, direccionE; 
		int i,opc,bandera3;
	public: 
		Empleados();
		~Empleados();
		void LeeDatosE();
		void VerDatosE();
		void Menu_empleados();
};


class Producto:public Graficos { 
	protected:
		Graficos objprod;
		string nomprod,clavprod;
		int cantprod,i;
		float precprod,subtot,total;
	public:
		Producto();
		~Producto();
		void Compra();
		float VerCompra();
		float Retsubtot();
		float Acumsubtot(float subt);
		
		//friend class Proveedores;
		
};
class Proveedores{ //CAMBIAR PRODUCTO POR PROVEEDORES
	protected:
	//	Graficos objprov;
		string NomProv,NomVta,telef;
		int produc,i,id,opc9,opc13;
		Producto *Verduras1,*Semillas,*Lacteos,*Carnes,*Especias, objprov; //HACEMOS UNA ANIDACION
		int TamV1,TamS1,TamL1,TamC1,TamE1,banderaP; //para mis memorias dinamicas
		float Total;
	public:
		Proveedores();
		~Proveedores();
		void LeeDatosP(); 
		void VerDatosP();
		void Menu_provedores();
		void Submenu_provedores();
		float Retotal();

};
class Facturacion: public Empleados{
	protected: 
	string RFC, razon_s, CFDI,CP;
	float iva;
	int opc3,banderaF;
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
		int cla,Clave,resp;
	    string usu,usuario;
	public:
		~Acceso();
		Acceso();
	void Leerc();
	int Impc();
};


class Menu: public Acceso, public Proveedores{ //public Comensales, public Producto
	protected:
	int opc1,opc3, i;
	public:
	Menu();
	~Menu();
	void VerMenu();
	
};

int main(){
	
	/*Graficos objG;
	objG.Portada();*/
	
	system("mode con: cols=80 lines=25");
	system("COLOR F1");
	
	Acceso *objA=new Acceso();
	objA->Impc();


	
	
	Menu obj1;
	obj1.VerMenu();
	

	
	delete objA;
	
	
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Graficos::Graficos(){
	i=0;
}

Graficos::~Graficos(){ }

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

void Graficos::Portada(){
	/*
	//initwindow( 1000 , 800, "WinBGIm",300,0 );//Para el tama�o de ventana
	initwindow( 1000 , 800);//Para el tama�o de ventana
	//setviewport(0,0,1000,800,1); //Nos sirve para establecer la vista actual para la salida de graficos
	
	
	int c=1;
	for(int i = 0; i<500; i++)
	{   
       setcolor(c);
	   	rectangle(getmaxx()/2+i,getmaxy()/2-i,getmaxx()/2-i,getmaxy()/2+i);
	   	setcolor(c);
        ellipse(getmaxx()/2,getmaxy()/2-i,i,i,i,i); 
        setcolor(c);
        ellipse(getmaxx()/2,getmaxy()/2+i,i,i,i,i); 
        
	  	delay(2);if(c>0 && c<2) c=1;
       c++; 
    }

    setcolor(15);
    settextstyle(10,0,5);
    outtextxy(275,380,"RESTAUSARS-COV2");
	settextstyle(10,0,1);
    outtextxy(325,50, "INSTITUTO POLITECNICO NACIONAL");
    outtextxy(420,70,"ESIME Zacatenco");
    outtextxy(300,90, "Ingenieria en comunicaciones y electronica");
    outtextxy( 65 , 600 , "Toledo Hernandez Ulises Gabriel" );
    outtextxy( 65 , 625 , "Duarte Zapote Adriana");
    outtextxy( 65 , 650 , "Equipo 12" );
    outtextxy( 65 , 675 , "2CM2" );
	//bgiout <<"[ENTER] para entrar al programa";
	
	//outstreamxy( 100, 700 ); 
	
	while( !kbhit() ){cout<<"[ENTER] para entrar al programa";};//Para cerrar; 
	closegraph(); */
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

Acceso::~Acceso(){ }

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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Menu::Menu(){
		opc1=0; //bandera1=0;
	}
	Menu::~Menu(){ }	
	
	void Menu::VerMenu(){
		
		
		do{
		
			system("cls");
		dibujarCuadro(0,0,78,24);
		dibujarCuadro(1,1,77,3);
		gotoxy(15,2);cout<<".......BIENVENIDO A RESTAUSARS-COV2.......";
		gotoxy(25,5);cout<<""; //FALTA PONER TEXTO
		gotoxy(25,8);cout<<"1.Comensal";
		gotoxy(25,9);cout<<"2.Empleado";
		gotoxy(25,10);cout<<"3.Proveedor";
		gotoxy(25,11);cout<<"4.Facturar";
		gotoxy(25,13);cout<<"5.Salir del programa";
		gotoxy(25,15);cout<<"Digite una opcion...->"; cin>>opc1;
		
		switch(opc1){
			case 1:
			 	Menu_comensales();VerMenu();
				break;
			case 2: 
			 	Menu_empleados();VerMenu();
				break;
			case 3:
				Menu_provedores();VerMenu();
				break;
			case 4:
				if(bandera2==1){MenuFactura();VerMenu();}
				else {gotoxy(15,17);cout<<"*Para poder facturar primero realice una compra como comensal ";gotoxy(15,18);system("pause");VerMenu();}
				break;	
			case 5:
				system("cls");
				dibujarCuadro(0,0,78,24);
				dibujarCuadro(9,4,60,7);// LINEA VERTICAL IZQ, LINEA HORIZONTAL SUP, LINEA VERT DEREC, LINEA HORIZ INFERIOR
				gotoxy(12,5);cout<<"Gracias por visitar RESTAUSARS-COV2";
				gotoxy(12,6);cout<<"Vuelva pronto";
				gotoxy(10,10);
				break;
			default: 
				gotoxy(25,17);cout<<"*Opci�n no valida, intente de nuevo";gotoxy(25,18);system("pause");VerMenu();
			
		}
		
	}while(opc1>5 || opc1<1);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Comidas::Comidas(){
		num=0;  opc8=0;  
		Total=0; platillo=0;
		sub=0; opc7=0; Tprod=0; sub2=0; beb=0; num2=0; ref=0;
		
	}
Comidas::~Comidas(){ }

void Comidas::VerComidas(){
		do{
			system("cls");
			system("mode con: cols=100 lines=40");
		dibujarCuadro(0,0,98,38);
		dibujarCuadro(1,1,97,3);
		gotoxy(52,2);cout<<"MENU\n";
		gotoxy(10,4);cout<<"*NOTA: Todos los platillos incluyen un refresco de 600 ml";
		gotoxy(10,6);cout<<"(1)De la hacienda.......................................$40";
		gotoxy(10,7);cout<<"(2)Colonial.............................................$65";
		gotoxy(10,8);cout<<"(3)Mexicano.............................................$35";
		gotoxy(10,9);cout<<"(4)Combinado............................................$40";
		gotoxy(10,10);cout<<"(5)Toluque"<<"\xA4"<<"o............................................$60";
		gotoxy(10,11);cout<<"(6)Arrachera Norte"<<"\xA4"<<"a....................................$80";
		gotoxy(10,12);cout<<"(7)Carne asada..........................................$120";
		gotoxy(10,13);cout<<"(8)Milanesa tradicional.................................$100";
		gotoxy(10,14);cout<<"(9)Enchiladas de mole con pollo.........................$80";
		gotoxy(10,15);cout<<"(10)Enchiladas suizas con pollo.........................$85";
		gotoxy(10,16);cout<<"(11)Ensalada caribe"<<"\xA4"<<"a...................................$60";
		gotoxy(10,17);cout<<"(12)Pechuga a las finas hierbas.........................$50";
		gotoxy(10,18);cout<<"(13)Pechuga con mole poblano............................$65";
		gotoxy(10,19);cout<<"(14)B"<<"\xA1"<<"squets con queso crema y fresas...................$70";
		gotoxy(10,20);cout<<"(15)Sopa de verduras....................................$30";
		gotoxy(10,22);cout<<"Ingrese la opci\xA2n deseada: "; gotoxy(10,23);cin>>opc8;
		
		switch(opc8){
			case 1:	gotoxy(16,26);cout<<"De la hacienda";
				gotoxy(10,27);cout<<"Milanesa de pollo (75 g), chilaquiles verdes ";
				gotoxy(10,28);cout<<"y huevo revuelto a la mexicana";
				gotoxy(10,30);cout<<"\xA8"<<"Cu\xA0ntas desea ordenar? "; 
				gotoxy(10,31);cin>>num;
				platillo=40;
				beb=15;
				Bebidas();
				Ventas(platillo,beb);
				break;
			case 2:gotoxy(16,26);cout<<"Colonial";
				gotoxy(10,27);cout<<"Milanesa de pollo (150 g), acompa�ada de frijoles ";
				gotoxy(10,28);cout<<"campesinos y dos huarachitos con salsa roja y verde";
				gotoxy(10,30);cout<<"\xA8"<<"Cu\xA0ntas desea ordenar? "; 
				gotoxy(10,31);cin>>num;
				platillo=65;
				beb=15;
				Bebidas();
				Ventas(platillo,beb);
				break;
			case 3:gotoxy(16,26);cout<<"Mexicano";
				gotoxy(10,27);cout<<"Carne asada (120 g), chilaquiles rojos y dos molletes";
				gotoxy(10,29);cout<<"\xA8"<<"Cu\xA0ntas desea ordenar? "; 
				gotoxy(10,30);cin>>num;
				platillo=35;
				beb=15;
				Bebidas();
				Ventas(platillo,beb);
				break;
			case 4:	gotoxy(16,26);cout<<"Combinado";
				gotoxy(10,27);cout<<"Dos hot cakes con jamon, tocino y dos huevos revueltos";
				gotoxy(10,29);cout<<"\xA8"<<"Cu\xA0ntas desea ordenar? "; 
				gotoxy(10,30);cin>>num;
				platillo=40;
				beb=15;
				Bebidas();
				Ventas(platillo,beb);
				break;
			case 5:gotoxy(16,26);cout<<"Toluque"<<"\xA4"<<"o";
				gotoxy(10,27);cout<<"Chilaquiles verdes con queso, crema y trozos de chorizo horneado;";
				gotoxy(10,28);cout<<"cubiertos con tiras de pollo asadas (150 g) y un huevo estrellado";
				gotoxy(10,30);cout<<"\xA8"<<"Cu\xA0ntas desea ordenar? "; 
				gotoxy(10,31);cin>>num;
				platillo=60;
				beb=15;
				Bebidas();
				Ventas(platillo,beb);
				break;
			case 6:gotoxy(16,26);cout<<"Arrachera Norte"<<"\xA4"<<"a";
				gotoxy(10,27);cout<<"Servida con cebolla toreada, chorizo y queso panela asado; ";
				gotoxy(10,28);cout<<"acompa"<<"\xA4"<<"ada de guacamole";
				gotoxy(10,30);cout<<"\xA8"<<"Cu\xA0ntas desea ordenar? "; 
				gotoxy(10,31);cin>>num;
				platillo=80;
				beb=15;
				Bebidas();
				Ventas(platillo,beb);
				break;
			case 7:gotoxy(16,26);cout<<"Carne asada";
				gotoxy(10,27);cout<<"Carne de res acompa"<<"\xA4"<<"ada de taquitos dorados de queso, ";
				gotoxy(10,28);cout<<"papas cambray, nopal y queso asado";
				gotoxy(10,30);cout<<"\xA8"<<"Cu\xA0ntas desea ordenar? "; 
				gotoxy(10,31);cin>>num;
				platillo=120;
				beb=15;
				Bebidas();
				Ventas(platillo,beb);
				break;
			case 8:gotoxy(16,26);cout<<"Milanesa tradicional";
				gotoxy(10,27);cout<<"Pechuga de pollo empanizada con papas a la francesa y guacamole";
				gotoxy(10,29);cout<<"\xA8"<<"Cu\xA0ntas desea ordenar? "; 
				gotoxy(10,30);cin>>num;
				platillo=100;
				beb=15;
				Bebidas();
				Ventas(platillo,beb);
				break;
			case 9:gotoxy(16,26);cout<<"Enchiladas de mole con pollo";
				gotoxy(10,27);cout<<"Ba"<<"\xA4"<<"�adas en nuestro tradicional mole, rellenas con pollo,servidas con crema,";
				gotoxy(10,28);cout<<" queso, cebolla morada y frijoles refritos.";
				gotoxy(10,30);cout<<"\xA8"<<"Cu\xA0ntas desea ordenar? "; 
				gotoxy(10,31);cin>>num;
				platillo=80;
				beb=15;
				Bebidas();
				Ventas(platillo,beb);
				break;
			case 10:gotoxy(16,26);cout<<"Enchiladas suizas con pollo";
			gotoxy(10,27);cout<<"Con nuestra tradicional salsa suiza, rellenas con pollo,";
				gotoxy(10,28);cout<<"gratinadas con queso gouda, cebolla y acompa�adas de frijoles refritos.";
				gotoxy(10,30);cout<<"\xA8"<<"Cu\xA0ntas desea ordenar? "; 
				gotoxy(10,31);cin>>num;
				platillo=85;
				beb=15;
				Bebidas();
				Ventas(platillo,beb);
				break;
			case 11:gotoxy(16,26);cout<<"Ensalada caribe"<<"\xA4"<<"a";
				gotoxy(10,27);cout<<"Combinaci�n de lechugas,pechuga marinada a la parrilla (150 g), durazno , ";
				gotoxy(10,28);cout<<"fresas y vinagreta de naranja.";
				gotoxy(10,30);cout<<"\xA8"<<"Cu\xA0ntas desea ordenar? "; 
				gotoxy(10,31);cin>>num;
				platillo=60;
				beb=15;
				Bebidas();
				Ventas(platillo,beb);
				break;
			case 12:gotoxy(16,26);cout<<"Pechuga a las finas hierbas";
				gotoxy(10,27);cout<<"Acompa"<<"\xA4"<<"ada de nopal asado, jitomate y queso panela";
				gotoxy(10,29);cout<<"\xA8"<<"Cu\xA0ntas desea ordenar? "; 
				gotoxy(10,30);cin>>num;
				platillo=50;
				beb=15;
				Bebidas();
				Ventas(platillo,beb);
				break;
			case 13:gotoxy(16,26);cout<<"Pechuga con mole poblano";
				gotoxy(10,27);cout<<"Doble pechuga en nuestro tradicional mole poblano, ";
				gotoxy(10,29);cout<<"acompa"<<"\xA4"<<"ada de arroz yfrijoles campesinos"; 
				gotoxy(10,30);cout<<"\xA8"<<"Cu\xA0ntas desea ordenar? "; 
				gotoxy(10,31);cin>>num;
				platillo=65;
				beb=15;
				Bebidas();
				Ventas(platillo,beb);
				break;
			case 14:gotoxy(16,26);cout<<"B"<<"\xA1"<<"squets con queso crema y fresas";
				gotoxy(10,27);cout<<"Dos b"<<"\xA1"<<"squets cortados a la mitadcon queso crema y fresas";
				gotoxy(10,29);cout<<"\xA8"<<"Cu\xA0ntas desea ordenar? "; 
				gotoxy(10,30);cin>>num;
				platillo=70;
				beb=15;
				Bebidas();
				Ventas(platillo,beb);
				break;
			case 15:gotoxy(16,26);cout<<"Sopa de verduras";
				gotoxy(10,27);cout<<"Deliciosa sopa  verduras y carne,calabaza elote";
				gotoxy(10,28);cout<<"\xA8"<<"Cu\xA0ntas desea ordenar? "; 
				gotoxy(10,29);cin>>num;
				platillo=30;
				beb=15;
				Bebidas();
				Ventas(platillo,beb);
				break;
			default: gotoxy(10,26);cout<<"Opci\xA2n no v\xA0lida, int\x82ntelo de nuevo";gotoxy(10,27); system("pause");
		}
		}while(opc8<1||opc8>15);
		
	}

float Comidas::Ventas(int plt,int beb){
		sub=num*platillo;//precio del platillo por la cantidad
			
		sub2=num2*beb;
		do{	
		system("cls");
		system("mode con: cols=80 lines=25");
		dibujarCuadro(0,0,78,24);
		dibujarCuadro(10,7,60,18);// LINEA VERTICAL IZQ, LINEA HORIZONTAL SUP, LINEA VERT DEREC, LINEA HORIZ INFERIOR
		gotoxy(13,10);cout<<"[1]Ordenar algo mas \n";
		gotoxy(13,11);cout<<"[2]Ir a pagar\n";
		gotoxy(13,13);cout<<"Digite la opcion a realizar: ";cin>>opc7;
		switch(opc7){
			case 1:	Acum(sub,sub2);AcumC(num,num2);//si quiere agregar otro platillo se acumula primero el subtotal del primer platillo agregado
					VerComidas(); break;//regresa al menu de comidas
			case 2: Acum(sub,sub2); AcumC(num,num2);break;//si ya no se van a agregar mas platillos envia el subtotal al total
					//retTotal();
			default: gotoxy(13,15);cout<<"Opcion no valida, intente de nuevo\n";
		}	
	}while(opc7<1 || opc7>2);
	}
	
	void Comidas::Bebidas(){
		system("cls");
		system("mode con: cols=80 lines=25");
		dibujarCuadro(0,0,78,24);
		dibujarCuadro(2,2,77,5);// LINEA VERTICAL IZQ, LINEA HORIZONTAL SUP, LINEA VERT DEREC, LINEA HORIZ INFERIOR
		gotoxy(3,3);cout<<"Para acompa"<<"\xA4"<<"ar su platillo, seleccione alguna bebida de su preferencia";
		gotoxy(3,4);cout<<"*Todas las bebidas con de 600 ml con un valor de $15.00";
		dibujarCuadro(9,6,50,14);// LINEA VERTICAL IZQ, LINEA HORIZONTAL SUP, LINEA VERT DEREC, LINEA HORIZ INFERIOR
		gotoxy(10,7);cout<<"[1]Coca Cola";
		gotoxy(10,8);cout<<"[2]Pepsi"; 
		gotoxy(10,9);cout<<"[3]7up"; 
		gotoxy(10,10);cout<<"[4]Mirinda"; 
		gotoxy(10,11);cout<<"[5]Sangria"; 
		gotoxy(10,12);cout<<"[6]Manzanita Sol"; 
		gotoxy(10,13);cout<<"[7]Sidral Mundet"; 
		gotoxy(10,16);cout<<"Seleccione el refreco que va a querer "; 
		gotoxy(10,17);cin>>ref;
		gotoxy(10,18);cout<<"Cuantos de este va a querer?";
		gotoxy(10,19);cin>>num2;
		
	}
	
	float Comidas::Acum(int sub,int sub2){
		
		Total=Total+(sub+sub2);//acumula los subtotales
		return Total;
	}
	
	float Comidas::AcumC(int num,int num2){
		Tprod=Tprod+num+num2; //acumula la cantidad de productos ordendados
		return Tprod;
	}
	
	void Comidas::Ticket(){
			gotoxy(13,11);cout<<"Cantidad de productos: "<<Tprod;
			retTotal();
		}
		
	float Comidas::retTotal(){
		
		gotoxy(13,12);cout<<"Subtotal: $"<<sub+sub2<<endl;
		gotoxy(13,13);cout<<"Total: $"<<Total<<endl;
		gotoxy(13,16);cout<<"Gracias por su compra :)\n";
	}
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		Empleados::Empleados(){
		clave=""; salario=""; emailE=""; telefonoE=""; direccionE=""; bandera3=0;
	}
	
	Empleados::~Empleados(){ }
	
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
			case 2: if(bandera3==1){VerDatosE();}
					else {gotoxy(15,14);cout<<"Para poder visualizar los datos, empieze por registrarse"; while( !kbhit() );Menu_empleados();}break;
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
		gotoxy(2,12);cout<<"E-mail : "; getline(cin,emailE);
		gotoxy(2,13);cout<<"Direccion: "; getline(cin,direccionE);
		gotoxy(2,14);cout<<"Telefono : ";getline(cin,telefonoE);
		gotoxy(2,15);cout<<"Salario:  $"; getline(cin,salario); 
		gotoxy(2,17);system("pause");
		bandera3=1;; //BANDERA
		system("cls");
		dibujarCuadro(0,0,78,24);
		gotoxy(30,11);cout<<"REGISTRO EXITOSO";	
		gotoxy(20,16);system("pause");
		Menu_empleados();
		
	}
	
	void Empleados::VerDatosE(){
		cin.ignore();
		do{
			system("cls");
			dibujarCuadro(0,0,78,24);
			
			gotoxy(13,8);cout<<"Digite la clave del empleado: ";gotoxy(50,8);getline(cin,c); //creo que se puede cambiar po rel algoritmo de la clave de acceso aqui
		}while(c.compare(clave)!=0);
		system("cls");
		dibujarCuadro(0,0,78,24);
		dibujarCuadro(2,7,60,14);// LINEA VERTICAL IZQ, LINEA HORIZONTAL SUP, LINEA VERT DEREC, LINEA HORIZ INFERIOR
		gotoxy(3,6);cout<<"Datos personales del empleado "<<clave<<endl;
		gotoxy(3,8);cout<<"Clave: "<<clave<<endl;
		gotoxy(3,9);cout<<"Nombre : "<<nombre<<" "<<apellido1<<" "<<apellido2<<endl;
		gotoxy(3,10);cout<<"E-mail : "<<emailE<<endl;
		gotoxy(3,11);cout<<"Direccion: "<<direccionE<<endl;
		gotoxy(3,12);cout<<"Telefono : "<<telefonoE<<endl;
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
		efec=0; opc3=0;  bandera=0; bandera2=0;
	}
		Comensales::~Comensales(){ }
		
		void Comensales::Menu_comensales(){
			do{
			system("cls");
			dibujarCuadro(0,0,78,24);
			dibujarCuadro(1,1,77,3);
			gotoxy(35,2);cout<<"COMENSALES"<<endl;	
			gotoxy(20,6);cout<<"DIGITE LA OPCION A REALIZAR";
			gotoxy(20,8);cout<<"*Nota: Por favor empiece por registrarse";
			gotoxy(25,10);cout<<"1. REGISTRARSE ";
			gotoxy(25,11);cout<<"2. VER DATOS DEL REGISTRO";
			gotoxy(25,12);cout<<"3. REALIZAR UN PEDIDO";
			gotoxy(25,13);cout<<"4. REGRESAR AL MENU PRINCIPAL";
			gotoxy(25,14);cout<<"Digite el opcion: ";gotoxy(50,14);cin>>opc3;
			switch(opc3){
				case 1: LeeDatosC();
					break;
				case 2: if(bandera==1){VerDatosC();}
					else gotoxy(20,16);cout<<"Para poder visualizar los datos"; 
					gotoxy(20,17);cout<<"empieze por registrarse"; while( !kbhit() );Menu_comensales(); 
					break;
				case 3: if(bandera==1){VerComidas();Metodo_pago();}
						else gotoxy(20,16);cout<<"Para poder visualizar los datos"; 
							 gotoxy(20,17);cout<<"empieze por registrarse"; while( !kbhit() );Menu_comensales();
					break;
				case 4: system("cls");
					break;
				default: gotoxy(20,17);cout<<"Opcion no valida, intente de nuevo";gotoxy(20,15);system("pause");
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
			gotoxy(2,12);cout<<"Telefono (Este ser"<<"\xA0"<<" el m"<<"\x82"<<"todo de contacto con el repartidor): ";getline(cin,telefono);
			gotoxy(2,14);cout<<"Estas listo para ordenar\n"; 
			gotoxy(2,15);system("pause");
			bandera=1; //BANDERA
			VerComidas();
			Metodo_pago();	
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
					gotoxy(13,8);cout<<"\xA8"<<"Cuanto dinero en efectivo dara?"; 
					gotoxy(14,9);cout<<"$";cin>>efec; //SE TIENE QUE BORRAR PARA PODER METER OTRA CANTIDAD VALIDA
					}while(efec<Total);
					cambio=efec-Total;
					gotoxy(13,14);cout<<"Cambio en efectivo: $"<<cambio<<endl;
					Ticket();
					bandera2=1;//BANDERA
					gotoxy(13,17);system("pause");
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
					
                    }while((strlen(tarjeta)>16) || (strlen(tarjeta)<16)  && (strlen(CVV)>3) || (strlen(CVV)<3));
        
                    system("cls");
					dibujarCuadro(0,0,78,24);
					dibujarCuadro(1,1,77,3);
					gotoxy(20,2);cout<<"Pago con Tarjeta de Credito o Debito";
					dibujarCuadro(10,10,60,18);
					Ticket(); 
					bandera2=1;//BANDERA PARA PODER FACTURAR
					gotoxy(13,17);system("pause");//SOLO VERIFICA EL CVV Y NO el num de digitos de la targeta
				break;
				default: gotoxy(13,17);cout<<"Opcion no valida, intente de nuevo";gotoxy(13,18); system("pause");
			}
			}while(opc2<1||opc2>2);
		}
		
//////////////////////////////////////////////////////////////////////////////////////////
	Facturacion::Facturacion(){
		RFC="";  razon_s="";//email="";direccion="";
		CP=""; banderaF=0;
		 CFDI="";
	}
		Facturacion::~Facturacion(){ }
		
		void Facturacion::MenuFactura(){
			do{
				system("cls");
				dibujarCuadro(0,0,78,24);
			dibujarCuadro(1,1,77,3);// LINEA VERTICAL IZQ, LINEA HORIZONTAL SUP, LINEA VERT DEREC, LINEA HORIZ INFERIOR
			gotoxy(35,2);cout<<"FACTURACION";
			gotoxy(20,6);cout<<"Digite la opcion a realizar"<<endl; fflush(stdin);
			gotoxy(20,8);cout<<"1. Generar Factura "<<endl;
			gotoxy(20,9);cout<<"2. Ver Factura"<<endl;
			gotoxy(20,10);cout<<"3. Borrar Factura"<<endl; //NO BORRA FACTURA
			gotoxy(20,11);cout<<"4. Regresar al Menu Principal"<<endl;
			//cout<<"5. Salir del programa"<<endl;
			gotoxy(20,13);cout<<"Digite la opcion: ";
			cin>>opc3;
			switch(opc3){
				case 1: Facturar();
				break;
				case 2: if(banderaF==1){VerFactura();}
				else {gotoxy(20,15);cout<<"Para poder visualizar la factura"; 
					gotoxy(20,16);cout<<"empieze por generarla"; while( !kbhit() );MenuFactura();}
				break;
				case 3: system("cls");break;
				case 4: system("cls");break;//Menu_comensales();
				default: cout<<"Opcion no valida\n"; 
			}
			
			}while(opc3<1 || opc3>4);
		}
		void Facturacion::Facturar(){
			system("cls");
			dibujarCuadro(0,0,78,24);
			dibujarCuadro(1,1,77,3);// LINEA VERTICAL IZQ, LINEA HORIZONTAL SUP, LINEA VERT DEREC, LINEA HORIZ INFERIOR
			gotoxy(30,2);cout<<"DATOS FISCALES "; cin.ignore();
			gotoxy(20,6);cout<<"Denominacion o Razon social : "; getline(cin,razon_s); //cin.ignore();
			gotoxy(20,7);cout<<"RFC : "; getline(cin,RFC); //cin.ignore();
			//gotoxy(20,8);cout<<"Direccion : "; getline(cin,direccion); cin.ignore();
			gotoxy(20,8);cout<<"Codigo Postal : "; getline(cin,CP);//cin.ignore();
			//gotoxy(20,10);cout<<"Correo electronico : "; getline(cin,email); cin.ignore();
			gotoxy(20,9);cout<<"Uso CFDI:"; getline(cin,CFDI); //cin.ignore();
			//gotoxy(20,12);cout<<"Telefono : ";getline(cin,telefono);cin.ignore();
			gotoxy(2,14);cout<<"Antes de presionar continuar verifique que sus datos sean correctos";
			gotoxy(2,16);system("pause");banderaF=1; //BANDERA
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
			
			gotoxy(16,20);system("pause"); system("cls");
		}
		
		/*void Facturacion::BorrarFactura(){
			
		}*/
///////////////////////////////////////////////////////////////////////////////////////////

Producto::Producto(){
	nomprod="";	clavprod="";cantprod=0; precprod=0;	subtot=0;  i=0; total=0;
}

Producto::~Producto(){
}

void Producto::Compra()//lectura de datos para comprar, pondremos, nombre,cantidad
		{ 
			//cout<<"\n";
			//system("cls");
			dibujarCuadro(0,0,78,24);
			dibujarCuadro(1,1,77,3);
			gotoxy(3,4);cout<<"Clave del producto: ";cin>>clavprod; cin.ignore();
			gotoxy(3,5);cout<<"Drescripcion del producto: ";getline(cin,nomprod);
			gotoxy(3,6);cout<<"Cantidad a comprar: ";cin>>cantprod;
			gotoxy(3,7);cout<<"Precio: "; cin>>precprod;
		}

float Producto::VerCompra(){
			//cout<<"\n";
			//system("cls");
			//objprod.dibujarCuadro(0,0,78,24);
			//objprod.dibujarCuadro(1,1,77,3);
			
			gotoxy(3,10);cout<<"Clave del producto: "<<clavprod<<endl;
			gotoxy(3,11);cout<<"Drescripcion del producto: "<<nomprod<<endl;
			gotoxy(3,12);cout<<"Cantidad a comprar: "<<cantprod<<endl;
			gotoxy(3,13);cout<<"Precio: "<<precprod<<endl;
			subtot=cantprod*precprod;
			//Acumsubtot(subtot);
			gotoxy(3,14);cout<<"Subtotal : "<<subtot<<endl;
			//return subtot;
}

/*void Producto::Compra()//lectura de datos para comprar, pondremos, nombre,cantidad
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
			//subtot=cantprod*precprod;
			//Acumsubtot(subtot);
			//objprod.gotoxy(3,14);cout<<"Subtotal : "<<subtot<<endl;
			//return subtot;
}
*/

float Producto::Retsubtot(){ return subtot;  }

	float Producto::Acumsubtot(float subt)
	{
		total=total+subt;//acumula los subtotales
		return total;
	}


///////////////////////////////////////////////////////////////////////////////////////////

Proveedores::Proveedores(){
	 //nomprov=""; id=0; descrip=""; 
	 produc=0; opc9=0; i=0;  Total=0; opc13=0; banderaP=0;
	
	objprov.gotoxy(3,8);cout<<"Cuantos frutas/verduras se compraran: ";
	cin>>TamV1;
	Verduras1 = new Producto[TamV1];
	if(Verduras1==NULL){
    objprov.gotoxy(3,10);cout<<"No hay mem din \n"; objprov.gotoxy(3,11);system("pause"); 
	exit(0);}
	
	objprov.gotoxy(3,8);cout<<"Cuantas semillas/aditivos se compraran: ";
	cin>>TamS1;
	Semillas = new Producto[TamS1];
	if(Semillas==NULL){
    objprov.gotoxy(3,10);cout<<"No hay mem din \n"; objprov.gotoxy(3,11);system("pause"); 
	exit(0);}
	
	objprov.gotoxy(3,8);cout<<"Cuantos lacteos se compraran: ";
	cin>>TamL1;
	Lacteos = new Producto[TamL1];
	if(Lacteos==NULL){
       objprov.gotoxy(3,10);cout<<"No hay mem din \n";objprov.gotoxy(3,11);system("pause"); 
		exit(0);}
	
	objprov.gotoxy(3,8);cout<<"Cuantas carnes/embutidos se compraran: ";
	cin>>TamC1;
	Carnes = new Producto[TamC1];
	if(Carnes==NULL){
       objprov.gotoxy(3,10);cout<<"No hay mem din \n"; objprov.gotoxy(3,11);system("pause"); 
		exit(0);}
				     	
	objprov.gotoxy(3,8);cout<<"Cuantas especias/aceites se compraran: ";
	cin>>TamE1;
	Especias = new Producto[TamE1];
	
	if(Especias==NULL){
       objprov.gotoxy(3,10);cout<<"No hay mem din \n"; objprov.gotoxy(3,11);system("pause"); 
		exit(0);}
}

		Proveedores::~Proveedores(){
			//cout<<"Liberando memoria en proveedores\n";
			/*delete []Verduras1;
			delete []Semillas;
			delete []Lacteos;
			delete []Carnes;
			delete []Especias;*/
			
			if(Verduras1!=NULL){delete []Verduras1;}
			else if(Semillas!=NULL ){delete []Semillas; }
			else if(Lacteos!=NULL){ delete []Lacteos;}	
			else if(Carnes!=NULL){delete []Carnes; }
			else if(Especias!=NULL){delete []Especias;}
			
			/*if(Verduras1!=NULL && Semillas!=NULL && Lacteos!=NULL && Carnes!=NULL && Especias!=NULL){
            delete []Verduras1; delete []Semillas; delete []Lacteos; delete []Carnes; delete []Especias; }	*/
		}
		
		void Proveedores::Menu_provedores(){
			do{
			system("cls");
			objprov.dibujarCuadro(0,0,78,24);
			objprov.dibujarCuadro(1,1,77,3);
			
			objprov.gotoxy(35,2);cout<<"MENU DE PROVEDORES"<<endl;
			
			objprov.gotoxy(25,8);cout<<"[1] Registrar datos de proveedor"<<endl;
			
			objprov.gotoxy(25,9);cout<<"[2] Visualizar datos de proveedor"<<endl;
			
			objprov.gotoxy(25,10);cout<<"[3] Regresar al menu principal"<<endl;
			
			objprov.gotoxy(25,11);cout<<"Digite la opcion a realizar: ";cin>>opc9;
			
				switch(opc9){
					case 1: Submenu_provedores();  break;
					case 2: if(banderaP==1){VerDatosP();}
							else{objprov.gotoxy(20,15);cout<<"Para poder visualizar a los proveedores"; 
							objprov.gotoxy(20,16);cout<<"empieze por registrarlos"; while( !kbhit() );Menu_provedores();
							} break;
					case 3:  system("cls"); break;
					default: objprov.gotoxy(25,13);cout<<"Opcion invalida"<<endl;objprov.gotoxy(25,14); system("pause"); break;
				}
			}while(opc9!=3);
		}
		
		void Proveedores::Submenu_provedores(){
		
			do{
				cin.ignore();
				system("cls");
				objprov.dibujarCuadro(0,0,78,24);
				objprov.dibujarCuadro(1,1,77,3);
				objprov.gotoxy(30,2);cout<<"REGISTRO PROVEEDOR";
				objprov.gotoxy(3,4);cout<<"Tipo de proveedor";
				objprov.gotoxy(3,5);cout<<"[1]Frutas y Verduras";
				objprov.gotoxy(3,6);cout<<"[2]Semillas y aditivos";
				objprov.gotoxy(3,7);cout<<"[3]Lacteos";
				objprov.gotoxy(3,8);cout<<"[4]Carnes y embutidos";
				objprov.gotoxy(3,9);cout<<"[5]Especias y aceites";
				objprov.gotoxy(3,9);cout<<"[6]Regresar al menu de proveedores";
				objprov.gotoxy(3,10);cout<<"Digite una opcion: "; 
				objprov.gotoxy(3,11);cin>>opc13;
	
				switch(opc13){
					
					case 1: LeeDatosP(); 
				     			banderaP=1;	
							
							for(i=0;i<TamV1;i++){
								system("cls");
								objprov.gotoxy(25,2);cout<<"Ingreso compra de frutas/verduras: ";
								Verduras1[i].Compra();
								Total=Total+Verduras1[i].Retsubtot();
							} 

							break;		
					case 2: LeeDatosP();
							
				     			
								for(i=0;i<TamS1;i++){
								system("cls");
				     		objprov.gotoxy(25,2);cout<<"Ingreso compra de semillas/aditivos: ";
									Semillas[i].Compra();
									Total=Total+Semillas[i].Retsubtot();
								} 
								banderaP=1;

						break;
					case 3:
						LeeDatosP();
						
								for(i=0;i<TamL1;i++){
								system("cls");
				     			objprov.gotoxy(25,2);cout<<"Ingreso compra de lacteos: ";
									Lacteos[i].Compra();
									Total=Total+Lacteos[i].Retsubtot();
								} 
									banderaP=1;
						break;
					case 4:
							LeeDatosP();
							
				     		
								for(i=0;i<TamC1;i++){	
								system("cls");
								objprov.gotoxy(25,2);cout<<"Ingreso compra de carnes/embutidos: ";
									Carnes[i].Compra();
									Total=Total+Carnes[i].Retsubtot();
								} 
									banderaP=1;
						break;
					case 5:
							LeeDatosP();
							
				     			
								for(i=0;i<TamE1;i++){
								system("cls");
				     		objprov.gotoxy(25,2);cout<<"Ingreso compra de especias/aceites : ";
									Especias[i].Compra();
									Total=Total+Especias[i].Retsubtot();
								} 
									banderaP=1;
						break;
					case 6: system("cls"); break;
					default: objprov.gotoxy(25,13);cout<<"Opcion invalida"<<endl;objprov.gotoxy(25,14); system("pause"); break;
					
				}
				
			}while(opc13<1 || opc13>6);	
	}
	
	void Proveedores::LeeDatosP()
		{	
			system("cls");
			cin.ignore();objprov.dibujarCuadro(0,0,78,24);
			objprov.gotoxy(3,4);cout<<"Nombre del proveedor : "; getline(cin,NomProv);
			objprov.gotoxy(3,5);cout<<"Nombre del vendedor : "; getline(cin,NomVta);
			objprov.gotoxy(3,6);cout<<"Telefono del vendedor : "; getline(cin,telef);
			
			/*gotoxy(3,4);cout<<"Nombre del proveedor : "; getline(cin,NomProv);
			gotoxy(3,5);cout<<"Nombre del vendedor : "; getline(cin,NomVta);
			gotoxy(3,6);cout<<"Telefono del vendedor : "; getline(cin,telef);*/
			
		}
		
	void Proveedores::VerDatosP()
		{   
					
			system("mode con: cols=80 lines=30");
			system("cls");
			objprov.dibujarCuadro(0,0,78,28);
			objprov.dibujarCuadro(1,1,77,3);
			objprov.gotoxy(35,2);cout<<"Proveedores";
			objprov.gotoxy(3,4);cout<<"Nombre del proveedor :"<<NomProv;
	    	objprov.gotoxy(3,5);cout<<"Nombre del vendedor :"<<NomVta;
	        objprov.gotoxy(3,6);cout<<"Telefono del vendedor :"<<telef; 
			
			if(Verduras1!=NULL){
				objprov.gotoxy(3,8);cout<<"Verduras/Frutas"; //PROBLEMAS AL IMPRIMIR CON gotoxy Se traslapan los datos y solo se ve el de frutas
				for(i=0;i<TamV1;i++)
	        	{   Verduras1[i].VerCompra(); }
	        	
			}else if(Semillas!=NULL){
				objprov.gotoxy(3,16);cout<<"Lacteos";
				for(i=0;i<TamS1;i++)
	        {   Semillas[i].VerCompra(); }
			
			}else if(Lacteos!=NULL){
				objprov.gotoxy(3,16);cout<<"Lacteos";
				for(i=0;i<TamL1;i++)
	        {   Lacteos[i].VerCompra(); }
			
			}else if(Carnes!=NULL){
				objprov.gotoxy(3,16);cout<<"Carnes";
				for(i=0;i<TamC1;i++)
	        {   Carnes[i].VerCompra(); }
			
			}else if(Especias!=NULL){
				objprov.gotoxy(3,16);cout<<"Especias";
				for(i=0;i<TamE1;i++)
	        {   Lacteos[i].VerCompra(); }
			}
	        
			
	        
	        
	       /* gotoxy(3,16);cout<<"Lacteos";
	        for(i=0;i<TamL1;i++)
	        {   Fruta1[i].VerCompra(); }*/
	        
			
			
			
			/*system("mode con: cols=80 lines=30");
			system("cls");
			objprov.dibujarCuadro(0,0,78,28);
			objprov.dibujarCuadro(1,1,77,3);
			objprov.gotoxy(35,2);cout<<"Proveedores";
			objprov.gotoxy(3,4);cout<<"Nombre del proveedor :"<<NomProv;
	        objprov.gotoxy(3,5);cout<<"Nombre del vendedor :"<<NomVta;
	        objprov.gotoxy(3,6);cout<<"Telefono del vendedor :"<<telef; 
			
			if(Verduras1!=NULL){
				objprov.gotoxy(3,8);cout<<"Verduras/Frutas"; //PROBLEMAS AL IMPRIMIR CON gotoxy Se traslapan los datos y solo se ve el de frutas
				for(i=0;i<TamV1;i++)
	        	{   Verduras1[i].VerCompra(); }
	        	
			}else if(Lacteos!=NULL){
				for(i=0;i<TamL1;i++)
	        {   Lacteos[i].VerCompra(); }
			}*/
	        
	        /*objprov.gotoxy(3,16);cout<<"Lacteos";
	        for(i=0;i<Taml1;i++)
	        {   Fruta1[i].VerCompra(); }*/
	        
	        
	        //TOTAL
			//cout<<"Total : "<<Total<<endl; //NO IMPRIME EL TOTAL, IMPRIME UN CERO
			//objprov.gotoxy(3,20);system("pause");
			
			objprov.gotoxy(3,20);system("pause");
			system("cls");
			system("mode con: cols=80 lines=25");
        } 
        
