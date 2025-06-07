// Programa: MatrizDinamica_Constructores_Captura.cpp
// Crea una matriz dinámica con memoria reservada por punteros dobles.
// Usa tres constructores (por defecto, parametrizado y copia).
// Permite leer dimensiones, capturar datos y verificar si la matriz cumple una condición (sin ceros en la diagonal).


# include <iostream>
# include <conio.h>
# include <math.h>
using namespace std;
     
class Matriz{
	
	private:
		int i, j, bandera; 
    	double **MTZ;
    	int N, M;
    	
	public:
		Matriz();
		Matriz(int _N, int _M);
		Matriz(const Matriz &obj_c);
		~Matriz();
		void Captura();
		void Leer();
		void Mostrar();
	
};

int main(){
	
	
	Matriz *OBJ1=new Matriz();
	OBJ1->Leer();
	OBJ1->Captura();
	OBJ1->Mostrar();
	
	cout<<"\n";
	cout<<"----------Con parametros---------------\n";
	
	Matriz *OBJ2=new Matriz(3,3);
	OBJ2->Captura();
	OBJ2->Mostrar();
	
	Matriz OBJcopia(*OBJ2);
	cout<<"\n-----------Se ejecuta la copia----------\n";
	OBJcopia.Captura();
	OBJcopia.Mostrar();

	system("pause");
	delete OBJ2;
	delete OBJ1;
	return 0;
}

Matriz::Matriz(){
	N=0; M=0; bandera=0; 
}

	
Matriz::Matriz(int _N, int _M){
	N=_N; M=_M; bandera=0;
	
}

Matriz::Matriz(const Matriz &obj_c){
	N=obj_c.N;	M=obj_c.M; 
	
}

void Matriz::Mostrar(){
	
	cout<<endl;cout<<endl;cout<<endl;
   for(i=0; i<N; i++)
    {  for(j=0; j<M; j++)
    	cout<<"  "<<MTZ[i][j];
       cout<<endl;
       
    }    
	 i=0;
    while(i<N)
   {
     j=0;
     while(j<N)
      {
        if((i=j) && (MTZ[i][j]==0))
           {
                 bandera=1;
                 break;
           }
         j++;
       } 
         i++;
   }
     if (bandera==1)
        cout<<"No se puede aplicar el metodo"<<endl;
        else
           cout<<"Si se puede realizar el metodo "<<endl;
        getch();          
}


void Matriz::Leer(){
	
	cout<<"Digite el numero de filas: \n";
    cin>>N;
    cout<<"Digite el numero de columnas: \n";					
        cin>>M;
        
        
}

void Matriz::Captura(){
	
	MTZ= new double *[N];   // creacion del vector de punteros
        for ( i=0;  i<N; i++)
             MTZ[i]=new double [M]; // creacion de area de datos	
        if(MTZ == NULL)   // verifica la creacion de Mem. Din.
            {   cout<<" No hay M.D."<<endl;
                getch ();   
            }   
             
			 for(i=0; i<N; i++)
                {for(j=0; j<M; j++)
                     { cout<<"Dato [ "<<(i+1)<<"] ["<<(j+1)<<" ] = "<<endl; 
                           cin>>MTZ[i][j];
                     } cout<<endl;
                 }
}

Matriz::~Matriz(){
	  
  cout<<"Liberacion de memoria dinamica\n";
  for(i=0; i<N; i++)
        delete [] MTZ [i];
        delete [] MTZ;
}


