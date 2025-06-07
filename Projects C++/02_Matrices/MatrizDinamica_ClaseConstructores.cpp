// Programa: MatrizDinamica_ClaseConstructores.cpp
// Crea y gestiona matrices dinámicas con una clase que incluye constructor por defecto, parametrizado y de copia.
// Permite leer y mostrar la matriz, e incluye verificación de condición para aplicar un método (por ejemplo, si hay ceros en la diagonal).


#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

class MATRIZ{
	
	private:
		int i,j,bandera,N,M,OPC;
		double **MTZ1;
		
	public:
		MATRIZ();
		MATRIZ(int _N, int _M);
		MATRIZ(const MATRIZ &OBJcop);
		~MATRIZ();
		void Leer();
		void Mostrar();
		void Menu();
		
		
	
};

int main(){
	
	MATRIZ OBJ1; //C1
	OBJ1.Leer();
	OBJ1.Mostrar();
	
	
	MATRIZ *OBJ2=new MATRIZ(3,3); //C2
	cout<<"\n---------Se ejecuta el constructor parametrizado---------\n";
	cout<<"\n";
	OBJ2->Leer();
	OBJ2->Mostrar();
	
	MATRIZ OBJcopia(*OBJ2); //Ccopia
	cout<<"\n------------Se ejecuta la copia------------------\n";
	cout<<"\n";
	OBJcopia.Leer();
	OBJcopia.Mostrar();
	
	
	system("pause");
	delete OBJ2;
	
	return 0;
}

MATRIZ::MATRIZ(){  //MEMORIA DINAMICA 

 N=0; M=0; bandera=0;

	cout<<"\nDigite el numero de filas: ";
           cin>>N;
        cout<<"Digite el numero de columnas: ";					
           cin>>M;
           
    MTZ1= new double *[N];
              for ( i=0;  i<N; i++)
                  MTZ1[i]=new double [M];	 
        
		if(MTZ1 == NULL)
            {
                cout<<" No hay M.D."<<endl;
                getch ();
                exit (0);
            } 
			        
    
}

MATRIZ::MATRIZ(int _N, int _M){
	
	N=_N; M=_M;
	
    MTZ1= new double *[N];
      for ( i=0;  i<N; i++)
          MTZ1[i]=new double [M];	 
        
	if(MTZ1 == NULL)
        {
            cout<<" No hay M.D."<<endl;
            getch ();
            exit (0);
        }    
            
    
}

MATRIZ::MATRIZ(const MATRIZ &OBJcop){
	N=OBJcop.N; M=OBJcop.M;
	
    MTZ1= new double *[N];
      for ( i=0;  i<N; i++)
          MTZ1[i]=new double [M];	 
        
	if(MTZ1 == NULL)
        {
            cout<<" No hay M.D."<<endl;
            getch ();
            exit (0);
        }    

        
}



MATRIZ::~MATRIZ(){
	
	for(i=0; i<N; i++)
		cout<<"Liberando memoria...\n";
        delete [] MTZ1 [i];
        delete [] MTZ1;
}

void MATRIZ::Leer(){
	cout<<"\n";
	for(i=0; i<N; i++)
                {
                   for(j=0; j<M; j++)
                     {
                        cout<<"Dato [ "<<(i+1)<<"] ["<<(j+1)<<" ] = "<<endl; 
                           cin>>MTZ1[i][j];
                     } cout<<endl;
                 }             
}

void MATRIZ::Mostrar(){
	
	cout<<endl;cout<<endl;cout<<endl;
   for(i=0; i<N; i++)
    {  for(j=0; j<M; j++)
    	cout<<"  "<<MTZ1[i][j];
       cout<<endl;
       
    }    
	
	i=0;
    while(i<N)
   {
     j=0;
     while(j<N)
      {
        if((i=j) && (MTZ1[i][j]==0))
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