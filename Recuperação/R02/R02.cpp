/*
 R02 - v0.0. - 09 / 06 / 2025
 Author: Gabriel Ferreira Pereira

 Para compilar em terminal (janela de comandos):
 Linux : g++ -o R02 R02.cpp
 Windows: g++ -o R02 R02.cpp

 Para executar em terminal (janela de comandos):
 Linux : ./R02
 Windows: R02
*/

#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "myarray.hpp"

using namespace std;

// -------------------------- definicao de metodos

void metodo01() 
{
   cout << "\n\tMetodo1311\n";

   ifstream infile("DADOS1.TXT");
   if (!infile) 
   {
     cout << "Erro ao abrir DADOS1.TXT" << endl;
     return;
   }

   int size;
   infile >> size;

   Array<int> arr(size, 0);
   for (int i = 0; i < size; i++) 
   {
      infile >> arr[i];
   }
   infile.close();

   if (!isAscending(arr)) 
   {
       sortAscending(arr);
   }

   ofstream outfile("CRESCENTE.TXT");
   if (!outfile) 
   {
      cout << "Erro ao criar CRESCENTE.TXT" << endl;
      return;
   }

   outfile << arr.getLength() << endl;
   for (int i = 0; i < arr.getLength(); i++) 
   {
      outfile << arr.get(i) << endl;
   }
   outfile.close();

   cout << "Processo concluido com sucesso" << endl;
   cout << "\nApertar ENTER para continuar." << endl;
   getchar();
}


void metodo02() 
{

   cout << "\n\tMetodo1312\n";
   cout << "\nApertar ENTER para continuar." << endl;
   getchar();
}

void metodo03() 
{
   cout << "\n\tMetodo1313\n";
   cout << "\nApertar ENTER para continuar." << endl;
   getchar();
}

void metodo04() 
{
   cout << "\n\tMetodo1314\n";
   cout << "\nApertar ENTER para continuar." << endl;
   getchar();
}

void metodo05() 
{
   cout << "\n\tMetodo1315\n";
   cout << "\nApertar ENTER para continuar." << endl;
   getchar();
}

void metodo06() 
{
   cout << "\n\tMetodo1316\n";
   cout << "\nApertar ENTER para continuar." << endl;
   getchar();
}

void metodo07() 
{
   cout << "\n\tMetodo1317\n";
   cout << "\nApertar ENTER para continuar." << endl;
   getchar();
}

void metodo08() 
{
   cout << "\n\tMetodo1318\n";
   cout << "\nApertar ENTER para continuar." << endl;
   getchar();
}

void metodo09() 
{
   cout << "\n\tMetodo1319\n";
   cout << "\nApertar ENTER para continuar." << endl;
   getchar();
}

void metodo10() 
{
   cout << "\n\tMetodo1320\n";
   cout << "\nApertar ENTER para continuar." << endl;
   getchar();
}

void metodo11() 
{
   cout << "\n\tMetodo13E1\n";
   cout << "\nApertar ENTER para continuar." << endl;
   getchar();
}

void metodo12() 
{
   cout << "\n\tMetodo13E2\n";
   cout << "\nApertar ENTER para continuar." << endl;
   getchar();
}

void menuOpcoes() {
    cout << "\nR02 - v.0.0 - 06/05/2025" << endl;
    cout << "Matricula: 842527 Nome: Gabriel Ferreira Pereira" << endl;
    cout << "Opcoes: "           << endl;
    cout << " 0 - parar "        << endl;
    cout << " 1 - metodo 01 "  << endl;
    cout << " 2 - metodo 02 "  << endl;
    cout << " 3 - metodo 03 "  << endl;
    cout << " 4 - metodo 04 "  << endl;
    cout << " 5 - metodo 05 "  << endl;
    cout << " 6 - metodo 06 "  << endl;
    cout << " 7 - metodo 07 "  << endl;
    cout << " 8 - metodo 08 "  << endl;
    cout << " 9 - metodo 09 "  << endl;
    cout << "10 - metodo 10 "  << endl;
    cout << endl;
}

// -------------------------- definicao do metodo principal

int main() 
{
    int opcao = 0;

    do {
        menuOpcoes();
        cout << "Qual a sua opcao? ";
        cin >> opcao;
        cin.ignore(); // Para consumir o ENTER após o número

        cout << opcao << endl;

        switch (opcao) {
            case 0: break;
            case 1:  metodo01(); break;
            case 2:  metodo02(); break;
            case 3:  metodo03(); break;
            case 4:  metodo04(); break;
            case 5:  metodo05(); break;
            case 6:  metodo06(); break;
            case 7:  metodo07(); break;
            case 8:  metodo08(); break;
            case 9:  metodo09(); break;
            case 10: metodo10(); break;
            default: 
                cout << "\nERRO: Opcao invalida\n" << endl;
                break;
        }

    } while (opcao != 0);

    cout << "\nApertar ENTER para terminar." << endl;
    cin.get();

    return 0;
}