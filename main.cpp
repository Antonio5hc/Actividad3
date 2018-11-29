//Herberth Antonio Portillo Cruz PC18022
//Librerias necesarias
#include <iostream>
#include <cstdlib>
#include <math.h>//pow
#include <fstream>//uso de ficheros
#include <sstream>//convertir a string
#include <conio.h>

using namespace std;

//Se declaran las funciones para que sean reconocidas por el programa al ejecutarlas
void menu();//Menu principal
void fibonacci();//Funcion de Fibonacci
void clean();//funcion para limpiar pantalla
void taylor();//funciones que ejecutara la seire de taylor
double tay(int n, int x);
double factorial(int n);
void finalizar();//opcion salir
int escribir(int o, string n, string d, string r);
void leer();

//Int main funcion que siempre es la principal necesaria para ejecutar el programa
int main(){

	system("color 70");
 //muestra el menu
   menu();
return 0;
}

//Funcion Menú que desplegara las opciones disponibles
void menu(){

    clean();//Cada que se ejecuta limpia la pantalla
    //variable donde se guardara la opcion elegida
	int n;

	cout<<"MENU INICIAL\n"<<endl;

	cout<<"1. Resolver Fibonacci\n"<<endl;

	cout<<"2. Serie de Taylor\n"<<endl;

	cout<<"3. Ver resultados\n"<<endl;

	cout<<"4. Salir\n"<<endl;

	cout<<"Elija una opcion: "; cin>>n;
	clean();

    //ciclo para usar el menu
	switch(n){

		case 1:
			fibonacci();
			break;

		case 2:
			taylor();
			break;

		case 3:
	    	leer();
			break;

		case 4:
		    finalizar();
			break;

        default:
            //opcion que muestra un mensaje al elegir un dato no disponible

            cout<<"La opcion elegida no es valida"<<endl;
            system("pause");

            clean();
            menu();

            break;

            menu();

	}
}

//Funcion de Fibonacci (Reutilizada de Internet)
void fibonacci(){

	string nom = "Fibonacci";//Se asigna el nombre para el registro

    int i;
    int n, cont = 0;
    long long int a[100];

    stringstream ss;//Se usa para convertir a string el vector
    a[0] = 0;
    a[1] = 1;

    cout << "Numero de terminos de la serie = ";
    cin >> n;
    cout << "\n";

    for(i=1; i < n; i++){

        a[i+1] = a[i-1] + a[i];
    }

     for(i=0; i < n; i++){

        if (cont == 10){

            cout << "\n";
            cont = 0;
        }
        cout << a[i] << " ";
        cont += 1;

  	ss<< a[i] << " ";    //Se guarda cada iteracion en la variable que luego para a ser string

     }
    cout << "\n";
    //Se convierten a string los datos ingresados por el usuario
    stringstream sq;
  	sq<<"Terminos de la serie: "<<n;
    string datos= sq.str();
    //Aquí se convierte finalmente la variable que tiene las iteraciones de fibonacci
    string res= ss.str();

    //Se envian las variables a la funcion escribir, que guarda en el registro
    escribir(1, nom, datos, res);

    //Se solicita Enter para ir al menú
    getch();
    menu();
}

//Funcion de Serie de Taylor
void taylor(){
	//declaracion de variables
	int n;
	int x;
	double res;
	string nom = "Serie de Taylor";//Se asigna el nombre para el registro

	cout<<"Ingrese valor de n: "; cin>> n;
	cout<<"Ingrese valor de x: "; cin>> x;
	cout<<endl;
    res = tay(n,x);//Se llama a la variable que realiza la operacion
	cout<<"El valor de Taylor para n= "<<n<<" y x= "<<x<<" es igual a: "<<res<<endl;//Se muestra el resultado

	//Se convierten a string los datos necesarios para se almacenados
    stringstream ss;
  	ss<<"n= "<<n <<" y x= "<<x;
    string datos= ss.str();
     stringstream sr;
  	sr<<"El resultado es: "<<res;
    string re= sr.str();
    //Se envian a guardar
	escribir(2, nom, datos, re);

	//Enter para ir al menu
	getch();
	menu();
}

//Operaciones de la serie de taylor

double tay(int n, int x){

	double t;
	double s;

	for (int i = 0; i < n; i++){

		t = pow(x, i) / factorial(i);
		s += t;
	}
	return s;
}

double factorial(int n){

	double fact =1;
	for(int i= 2; i<=n; i++){
		fact*=i;
	}
	return fact;
}

//Funcion que guarda en el archivo en formato .txt
int escribir(int o, string n, string d, string r){

	fstream file("registro.txt", ios::in | ios::out | ios::app);//Se abre el archivo de manera que se carguen los datos previamente almacenados

    //Se comprueba si el archivo no se puede abrir se muestra un mensaje
  if (!file.is_open()){

  	cout<<"Error al abrir archivo!";

  }else{

  	cout<<"Archivo abierto..."<<endl;

  	cout<<"Escribiendo en el archivo... Se ha guardado correctamente!"<<endl;

  //guardando en el archivo

    //Se convierten los datos si es necesario, se igualan las variables.
    stringstream sa;
  	sa<<o;
  	string opcion= sa.str();

    string nombre = n;
  	string datos = d;

  	string resultado=r;

  	file<<opcion<<" - "<<nombre<<" - "<<datos<<" - "<<resultado<<endl;//Se envia a guardar el texto
}
return 0;
}

//Funcion que permite leer los datos almacenados en el archivo .txt
void leer(){

		fstream file("registro.txt", ios::in | ios::out | ios::app);//se carga el texto donde se guardo los resultados
  //Se comprueba si se abre correctamente
  if (!file.is_open()){

  	cout<<"El archivo no se puedo abrir"<<endl;

  }else{

  	//Codigo para extraer el texto y mostratlo en consola (reutilizado de internet)
  	file.seekg(0);
  	string line;
  	cout<<"-Registro-"<<endl;
  	cout<<endl;
  	while(file.good()){
  	 	getline(file, line);
  	    cout << line << endl;
	}
}

//Enter para ir al menu
getch();
menu();

}

//Funcion como pantalla de salida
void finalizar(){

cout<<endl;
system("pause");
clean();

cout<<"  GRACIAS POR USAR NUESTRO PROGRAMA"<<endl;


}

void clean(){

system("cls");

}
