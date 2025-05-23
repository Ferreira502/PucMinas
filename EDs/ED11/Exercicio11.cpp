/*
 Exercicio04 - v0.0. - 23 / 05 / 2025
 Author: Gabriel Ferreira Pereira

 Para compilar em terminal (janela de comandos):
 Linux : g++ -o exercicio11 exercicio11.cpp
 Windows: g++ -o exercicio11 exercicio11.cpp

 Para executar em terminal (janela de comandos):
 Linux : ./exercicio11
 Windows: exercicio11
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
    cout << "\n\tMetodo01111\n";
    int n = 0;
    int inferior, superior;

    cout << "Digite a quantidade de valores aleatorios: ";
    cin >> n;

    cout << "Digite o valor inferior do intervalo: ";
    cin >> inferior;

    cout << "Digite o valor superior do intervalo: ";
    cin >> superior;

    Array<int> arr;

    arr.randomIntGenerate(n, inferior, superior);

    cout << "Valores gerados:" << endl;
    arr.print();

    getchar();

    arr.fprint("DADOS.TXT");
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo02() {
    cout << "\n\tMetodo1112\n";
    string nomeArquivo;
    cout << "Digite o nome do arquivo com os dados: ";
    cin >> nomeArquivo;

    getchar();

    Array<int> arr;
    arr.fread(nomeArquivo);

    cout << "\nDados lidos do arquivo:" << endl;
    arr.print();
    getchar();

    int maior = arr.searchFirstOdd();

    cout << "\nMaior valor impar encontrado: " << maior << endl;
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo03() {
    cout << "\n\tMetodo1113\n";
    string nomeArquivo;
    cout << "Digite o nome do arquivo com os dados: ";
    cin >> nomeArquivo;

    Array<int> arr;
    arr.fread(nomeArquivo);

    cout << "\nDados lidos do arquivo:" << endl;
    arr.print();

    getchar();

    int maior = arr.searchFirstOddx3();

    getchar();

    cout << "\nMaior valor impar multiplo de 3 encontrado: " << maior << endl;
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo04() {
    cout << "\n\tMetodo1114\n";
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo05() {
    cout << "\n\tMetodo1115\n";
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo06() {
    cout << "\n\tMetodo1116\n";
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo07() {
    cout << "\n\tMetodo1117\n";
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo08() {
    cout << "\n\tMetodo1118\n";
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo09() {
    cout << "\n\tMetodo1119\n";
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo10() {
    cout << "\n\tMetodo1120\n";
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo11() {
    cout << "\n\tMetodo11E1\n";
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo12() {
    cout << "\n\tMetodo11E2\n";
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void menuOpcoes() {
    cout << "\nExercicio11 - v.0.0 - 23/05/2025" << endl;
    cout << "Matricula: 842527 Nome: Gabriel Ferreira Pereira" << endl;
    cout << "Opcoes:" << endl;
    cout << " 0 - parar" << endl;
    cout << " 1 - metodo 1111" << endl;
    cout << " 2 - metodo 1112" << endl;
    cout << " 3 - metodo 1113" << endl;
    cout << " 4 - metodo 1114" << endl;
    cout << " 5 - metodo 1115" << endl;
    cout << " 6 - metodo 1116" << endl;
    cout << " 7 - metodo 1117" << endl;
    cout << " 8 - metodo 1118" << endl;
    cout << " 9 - metodo 1119" << endl;
    cout << "10 - metodo 1120" << endl;
    cout << "11 - metodo 11E1" << endl;
    cout << "12 - metodo 11E2" << endl;
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