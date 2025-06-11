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
#include <fstream>
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
   cout << "\n\tMetodo01\n";
   Array<int> arr;
   arr.fread("DADOS1.TXT");

   cout << "\nArranjo original:" << endl;
   arr.print();

   arr.sortDown();

   cout << "\nArranjo em ordem decrescente:" << endl;

   ofstream arquivo("DECRESCENTE.TXT");

   if(arquivo.is_open())
   {
      arquivo << arr.getLength() << endl;
      for (int i = 0; i < arr.getLength(); i++) 
      {
         arquivo << arr.get(i) << endl;
      }
      arquivo.close();
      cout << "Dados gravados com sucesso\n";
   }
   else {
        cout << "Nao foi possivel abrir o arquivo\n";
    }

   getchar();
   cout << "\nApertar ENTER para continuar." << endl;
   getchar();
}

void arranjo_inverter(Array<int>& arr) 
{
    int n = arr.getLength();
    for (int i = 0; i < n / 2; i++) 
    {
        int temp = arr.get(i);
        arr.set(i, arr.get(n - 1 - i));
        arr.set(n - 1 - i, temp);
    }
}


void metodo02() 
{

   cout << "\n\tMetodo02\n";
   Array<int> arr;
   arr.fread("DECRESCENTE.TXT");

   cout << "\nArranjo original:" << endl;
   arr.print();

   arranjo_inverter(arr);

   cout << "\nArranjo invertido:" << endl;
   arr.print();

   ofstream arquivo("INVERTIDOS.TXT");

   if (arquivo.is_open()) 
   {
       arquivo << arr.getLength() << endl;
       for (int i = 0; i < arr.getLength(); i++) 
       {
         arquivo << arr.get(i) << endl;
       }
       arquivo.close();
       cout << "Dados invertidos gravados com sucesso no arquivo INVERTIDOS.TXT\n";
   } else 
   {
      cout << "Nao foi possivel abrir o arquivo INVERTIDOS.TXT\n";
   }

   getchar();
   cout << "\nApertar ENTER para continuar." << endl;
   getchar();
}

void metodo03() 
{
   cout << "\n\tMetodo03\n";
   cout << "\nApertar ENTER para continuar." << endl;
   getchar();
}

void metodo04() 
{
   cout << "\n\tMetodo04\n";
   cout << "\nApertar ENTER para continuar." << endl;
   getchar();
}


void metodo05() 
{
   cout << "\n\tMetodo05\n";
   cout << "\nApertar ENTER para continuar." << endl;
   getchar();
}

void metodo06() 
{
   cout << "\n\tMetodo06\n";
   cout << "\nApertar ENTER para continuar." << endl;
   getchar();
}

void metodo07() 
{
   cout << "\n\tMetodo07\n";
   cout << "\nApertar ENTER para continuar." << endl;
   getchar();
}

void metodo08() 
{
   cout << "\n\tMetodo08\n";
   cout << "\nApertar ENTER para continuar." << endl;
   getchar();
}

void metodo09() 
{
   cout << "\n\tMetodo09\n";
   cout << "\nApertar ENTER para continuar." << endl;
   getchar();
}

void metodo10() 
{
   cout << "\n\tMetodo10\n";
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