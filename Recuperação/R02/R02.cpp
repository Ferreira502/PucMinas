/*
 R02 - v0.0. - 06 / 05 / 2025
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

using namespace std;

// -------------------------- definicao de metodos

void metodo01() 
{
   cout << "\n\tMetodo1311\n";
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
    cout << " 1 - metodo 1311 "  << endl;
    cout << " 2 - metodo 1312 "  << endl;
    cout << " 3 - metodo 1313 "  << endl;
    cout << " 4 - metodo 1314 "  << endl;
    cout << " 5 - metodo 1315 "  << endl;
    cout << " 6 - metodo 1316 "  << endl;
    cout << " 7 - metodo 1317 "  << endl;
    cout << " 8 - metodo 1318 "  << endl;
    cout << " 9 - metodo 1319 "  << endl;
    cout << "10 - metodo 1320 "  << endl;
    cout << "11 - metodo 13E1 "  << endl;
    cout << "12 - metodo 13E2 "  << endl;
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
            case 11: metodo11(); break;
            case 12: metodo12(); break;
            default: 
                cout << "\nERRO: Opcao invalida\n" << endl;
                break;
        }

    } while (opcao != 0);

    cout << "\nApertar ENTER para terminar." << endl;
    cin.get();

    return 0;
}