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

#define null nullptr

void pause ( std::string text ) 
{ 
    std::string dummy; 
    std::cin.clear ( ); 
    std::cout << std::endl << text; 
    std::cin.ignore( ); 
    std::getline(std::cin, dummy); 
    std::cout << std::endl << std::endl; 
} // end pause ( ) 

// -------------------------- definicao de metodos

/**  
     Funcao para acrescentar valor ao final 
     de um arranjo, por meio de apontador. 
     @return  apontador para arranjo atualizado 
     @param array - apontador para arranjo 
     @param value - valor a ser inserido 
  */ 

void metodo01() 
{
    cout << "\n\tMetodo01\n";
    Array<int> arr;
    int n = 0;

    cout << "Quantos valores: ";
    cin >> n;

    for (int i = 0; i < n; i++) 
    {
        int val;
        cout << "Digite o valor " << i + 1 << ": ";
        cin >> val;
        arr.push_back(val);
    }

    cout << "Array preenchido: ";

    arr.print();
    pause("Apertar ENTER para continuar");
    getchar();
}

void metodo02() 
{
    cout << "\n\tMetodo02\n";
    Array<int> arr;
    int n = 0, valor = 0;

    cout << "Quantos valores deseja inserir? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Digite o valor " << (i + 1) << ": ";
        cin >> valor;
        arr.push_back(valor);
    }

    cout << "\nAntes do pop_back: ";
    arr.print();

    arr.pop_back();

    cout << "Depois do pop_back: ";
    arr.print();

    pause("Apertar ENTER para continuar");
    getchar();
}

void metodo03() 
{
    cout << "\n\tMetodo03\n";
    Array<int> arr;
    int n = 0, valor = 0;

    cout << "Quantos valores deseja inserir no inicio do array: ";
    cin >> n;

    for (int i = 0; i < n; i++) 
    {
        cout << "Digite o valor " << (i + 1) << ": ";
        cin >> valor;
        arr.push_front(valor);
    }

    cout << "\nArray resultante: ";
    arr.print();

    pause("Apertar ENTER para continuar");
    getchar();
}

void metodo04() 
{
    cout << "\n\tMetodo04\n";
    Array<int> arr;
    int n = 0, valor = 0;

    cout << "Quantos valores deseja inserir: ";
    cin >> n;

    for (int i = 0; i < n; i++) 
    {
        cout << "Digite o valor " << (i + 1) << ": ";
        cin >> valor;
        arr.push_back(valor); 
    }

    cout << "\nAntes do pop_front: ";
    arr.print();

    arr.pop_front();

    cout << "\nArray resultante: ";
    arr.print();
    pause("Apertar ENTER para continuar");
    getchar();
}

void metodo05() 
{
    cout << "\n\tMetodo05\n";
    Array<int> arr;
    int n = 0, valor = 0;

    cout << "Quantos valores deseja inserir: ";
    cin >> n;

    for (int i = 0; i < n; i++) 
    {
        cout << "Digite o valor " << (i + 1) << ": ";
        cin >> valor;
        arr.push_back(valor);
    }

    cout << "Array atual: ";
    arr.print();

    cout << "\nDigite um valor para inserir no meio: ";
    cin >> valor;

    arr.push_mid(valor);

    cout << "Array push_mid: ";
    arr.print();

    pause("Apertar ENTER para continuar");
    getchar();
}

void metodo06() 
{
    cout << "\n\tMetodo06\n";
    Array<int> arr;
    int n = 0, valor = 0;

    cout << "Quantos valores: ";
    cin >> n;

    for (int i = 0; i < n; i++) 
    {
        cout << "Digite o valor " << (i + 1) << ": ";
        cin >> valor;
        arr.push_back(valor);
    }

    cout << "Array antes do pop_mid: ";
    arr.print();

    arr.pop_mid();

    cout << "Array depois do pop_mid: ";
    arr.print();
    
    pause("Apertar ENTER para continuar");
    getchar();
}

void metodo07() 
{
    cout << "\n\tMetodo07\n";

    ref_intArray a = read_intArray();
    ref_intArray b = read_intArray();

    cout << "Primeiro array: ";
    print_intArray(a);

    cout << "Segundo array : ";
    print_intArray(b);

    int resultado = intArray_cmp(a, b);

    cout << "\nResultado da comparacao: ";
    if (resultado == 0)
        cout << "Arrays iguais.\n";
    else if (resultado < 0)
        cout << "Primeiro array e menor.\n";
    else
        cout << "Primeiro array e maior.\n";

    delete[] a->data;
    delete a;
    delete[] b->data;
    delete b;

    pause("Apertar ENTER para continuar");
    getchar();
}

void metodo08() 
{
    cout << "\n\tMetodo08\n";
    ref_intArray a = read_intArray();
    ref_intArray b = read_intArray();

    ref_intArray c = intArray_cat(a, b);

    cout << "Primeiro array: ";
    print_intArray(a);

    cout << "Segundo array : ";
    print_intArray(b);

    cout << "Array concatenado: ";
    print_intArray(c);

    delete[] a->data;
    delete a;
    delete[] b->data;
    delete b;
    delete[] c->data;
    delete c;

    pause("Apertar ENTER para continuar");
    getchar();
}

void metodo09() 
{
    cout << "\n\tMetodo09\n";

    ref_intArray arr = read_intArray();

    int valor;
    cout << "Digite o valor a ser procurado: ";
    cin >> valor;

    ref_intArray encontrado = intArray_seek(arr, valor);

    if (encontrado != nullptr) 
    {
        cout << "\nValor encontrado: ";
        print_intArray(encontrado);
        delete[] encontrado->data;
        delete encontrado;
    } else 
    {
        cout << "\nValor NAO encontrado no array";
    }

    delete[] arr->data;
    delete arr;

    pause("Apertar ENTER para continuar");
    getchar();
}

void metodo10() 
{
    cout << "\n\tMetodo10\n";
    getchar();
    pause("Apertar ENTER para continuar");
    getchar();
}

void metodo11() 
{
    cout << "\n\tMetodo11\n";
    pause("Apertar ENTER para continuar");
    getchar();
}

void metodo12() 
{
    cout << "\n\tMetodo12\n";
    pause("Apertar ENTER para continuar");
    getchar();
}

void menuOpcoes() 
{
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