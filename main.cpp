#include <iostream>
#include <fstream>
using namespace std;

void escribir();
void leer();
int menu();

int main() {
  int opg;
  do{
    opg=menu();
    switch (opg)
    {
      case 1:
      escribir();
      system("read -p 'Presiona Enter para continuar...' var"); 
      break;
     
      case 2:
      leer();
      system("read -p 'Presiona Enter para continuar...' var"); 
      break;

      case 0:
      cout<<"------GRACIAS-----\n";
      system("read -p 'Presiona Enter para continuar...' var"); 
      break;
    }
    system("clear");
  }while(opg!=0);
}

int menu()
{
  int op;
  do {
  cout<<endl;
  cout << "1 - AÑADIR DATOS" << endl;
  cout << "2 - LEER DATOS" << endl;
  cout << "0 ‐ Salir" << endl;
  cout << "Opcion: ";
  cin >> op;
  } while ((op < 0) || (op > 2));
  return op;
}

void escribir()
{
  ofstream archivo;
  string datos;
  char r;
  int la;
  double pg;
  cout<<"INGRESE NOMBRE DEL ARCHIVO: ";
  cin.ignore();
  getline(cin,datos);
  archivo.open(datos.c_str(),ios::app);
  do{

    cout<<"Ingrese cantidad de lapices: ";
    cin>>la;
    if(la>1000)
    {
      pg=la*0.85;
    }
    else 
    {
      pg = la*0.90;
    }
    cout<<"El pago total es: "<<pg<<endl;
    archivo << la << endl;
    archivo << pg << endl;
    cout<<"DESEA AGREGAR OTRO DATO s/n: ";
    cin>>r;
    cin.ignore();
  }while(r=='s');
}

void leer ()
{
  int la;
  double pg;
  ifstream datoslectura ("lapices.txt");
  while(!datoslectura.eof())
        {
            datoslectura>>la>>pg;
            if (!datoslectura.fail())
                {
                    cout<<"**********************"<<endl;
                    cout<<"Los lapices son :     "<<la<<endl;
                    cout<<"EL pago es :          "<<pg<<endl;
                    cout<<"**********************"<<endl;
                }
        }
}


