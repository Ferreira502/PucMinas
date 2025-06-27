/*
 Exercicio16 - v0.0. - 27 / 05 / 2025
 Author: Gabriel Ferreira Pereira

 Para compilar em terminal (janela de comandos):
 Linux : g++ -o exercicio16 exercicio16.cpp
 Windows: g++ -o exercicio16 exercicio16.cpp

 Para executar em terminal (janela de comandos):
 Linux : ./exercicio16
 Windows: exercicio16
*/

#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include "myarray.hpp" 
 
using namespace std; 

// -------------------------- definicao de metodos

void metodo01() {
    cout << "\n\tMetodo01\n";
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo02() {
    cout << "\n\tMetodo02\n";
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo03() {
    cout << "\n\tMetodo03\n";
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo04() {
    cout << "\n\tMetodo04\n";
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo05() {
    cout << "\n\tMetodo05\n";
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo06() {
    cout << "\n\tMetodo06\n";
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo07() {
    cout << "\n\tMetodo07\n";
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo08() {
    cout << "\n\tMetodo08\n";
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo09() {
    cout << "\n\tMetodo09\n";
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo10() {
    cout << "\n\tMetodo10\n";
    getchar();
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo11() {
    cout << "\n\tMetodo11\n";
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo12() {
    cout << "\n\tMetodo12\n";
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void menuOpcoes() {
    cout << "\nExercicio16 - v.0.0 - 27/05/2025" << endl;
    cout << "Matricula: 842527 Nome: Gabriel Ferreira Pereira" << endl;
    cout << "Opcoes:" << endl;
    cout << " 0 - parar" << endl;
    cout << " 1 - metodo 01" << endl;
    cout << " 2 - metodo 02" << endl;
    cout << " 3 - metodo 03" << endl;
    cout << " 4 - metodo 04" << endl;
    cout << " 5 - metodo 05" << endl;
    cout << " 6 - metodo 06" << endl;
    cout << " 7 - metodo 07" << endl;
    cout << " 8 - metodo 08" << endl;
    cout << " 9 - metodo 09" << endl;
    cout << "10 - metodo 10" << endl;
    cout << "11 - metodo 11" << endl;
    cout << "12 - metodo 12" << endl;
    cout << endl;
}

// -------------------------- definicao do metodo principal

int main() {
    int opcao = 0;

    do {
        menuOpcoes();
        cout << "Qual a sua opcao? ";
        cin >> opcao;
        getchar();

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