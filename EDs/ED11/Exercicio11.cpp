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
    string nomeArquivo;
    int inicio, fim;

    cout << "Digite o nome do arquivo com os dados: ";
    cin >> nomeArquivo;

    Array<int> arr;
    arr.fread(nomeArquivo);

    cout << "\nDados lidos do arquivo:" << endl;
    arr.print();

    getchar();

    cout << "Digite a posicao inicial: ";
    cin >> inicio;
    cout << "Digite a posicao final: ";
    cin >> fim;

    getchar();

    int soma = arr.addInterval(inicio, fim);
    getchar();

    cout << "\nSoma dos elementos no intervalo [" << inicio << ", " << fim << "] = " << soma << endl;
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo05() {
    cout << "\n\tMetodo1115\n";
    string nomeArquivo;
    int inicio, fim;

    cout << "Digite o nome do arquivo com os dados: ";
    cin >> nomeArquivo;

    Array<int> arr;
    arr.fread(nomeArquivo);

    cout << "\nDados lidos do arquivo:" << endl;
    arr.print();

    getchar();

    cout << "Digite a posicao inicial: ";
    cin >> inicio;

    cout << "Digite a posicao final: ";
    cin >> fim;

    getchar();
    double media = arr.averageInterval(inicio, fim);
    getchar();

    cout << fixed;
    cout.precision(2);
    cout << "\nMedia dos elementos no intervalo [" << inicio << ", " << fim << "] = " << media << endl;
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo06() {
    cout << "\n\tMetodo1116\n";
    Array<int> arr;
    arr.fread("DADOS.TXT");

    cout << "\nDados lidos:" << endl;
    arr.print();
    getchar();

    bool teste = arr.negatives();

    if (teste)
    {
        cout << "\nTodos os valores sao positivos e maiores que 100" << endl;
    }
    else
    {
        cout << "\nNem todos os valores sao positivos e maiores que 100" << endl;
    }
    getchar();
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo07() {
    cout << "\n\tMetodo1117\n";
    Array<int> arr;
    arr.fread("DADOS.TXT");

    cout << "\nDados lidos:" << endl;
    arr.print();
    getchar();

    bool teste = arr.isDecrescent();

    if (teste)
    {
        cout << "\nOs valores estao em ordem decrescente" << endl;
    }
    else
    {
        cout << "\nOs valores NAO estao em ordem decrescente" << endl;
    }
    getchar();

    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo08() {
    cout << "\n\tMetodo1118\n";
    Array<int> arr;
    arr.fread("DADOS.TXT");

    cout << "\nDados lidos:" << endl;
    arr.print();

    getchar();

    int procurado, inicio, fim;
    cout << "Valor a procurar: ";
    cin >> procurado;

    cout << "Posicao inicial: ";
    cin >> inicio;

    cout << "Posicao final: ";
    cin >> fim;

    getchar();

    bool existe = arr.searchInterval(procurado, inicio, fim);

    if (existe)
    {
        cout << "\nO valor " << procurado << " foi encontrado no intervalo [" << inicio << ", " << fim << "]." << endl;
    }
    else
    {
        cout << "\nO valor " << procurado << " NAO foi encontrado no intervalo [" << inicio << ", " << fim << "]." << endl;
    }

    getchar();
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo09() {
    cout << "\n\tMetodo1119\n";
    Array<int> arr;
    arr.fread("DADOS.TXT");

    cout << "\nArranjo original:" << endl;
    arr.print();

    int constante, inicio, fim;
    cout << "Constante de escala: ";
    cin >> constante;

    cout << "Posicao inicial: ";
    cin >> inicio;

    cout << "Posicao final: ";
    cin >> fim;
    getchar();

    Array<int> novo = arr.scalar(constante, inicio, fim);

    cout << "\nArranjo escalado:" << endl;
    novo.print();
    getchar();

    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo10() {
    cout << "\n\tMetodo1120\n";
    Array<int> arr;
    arr.fread("DADOS.TXT");

    cout << "\nArranjo original:" << endl;
    arr.print();

    arr.sortDown();

    cout << "\nArranjo em ordem decrescente:" << endl;
    arr.print();

    getchar();
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo11() {
    cout << "\n\tMetodo11E1\n";
    int valores1[] = {1, 2, 3};
    int valores2[] = {1, 2, 4};

    Array<int> a1(3, valores1);
    Array<int> a2(3, valores2);

    cout << "\nArray 1:";
    a1.print();

    cout << "Array 2:";
    a2.print();

    if (a1 != a2)
    {
        cout << "\nOs arrays sao diferentes " << endl;
    }
    else
    {
        cout << "\nOs arrays sao iguais" << endl;
    }
    cout << "Apertar ENTER para continuar." << endl;
    getchar();
}

void metodo12() {
    cout << "\n\tMetodo11E2\n";
    int valores1[] = {10, 20, 30, 40};
    int valores2[] = {1, 2, 3, 4};

    Array<int> a1(4, valores1);
    Array<int> a2(4, valores2);

    cout << "\nArray 1:" << endl;
    a1.print();
    cout << "\nArray 2:" << endl;
    a2.print();

    Array<int> diferencas = a1 - a2;

    getchar();
    
    cout << "\nDiferencas (a1 - a2):" << endl;
    diferencas.print();
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