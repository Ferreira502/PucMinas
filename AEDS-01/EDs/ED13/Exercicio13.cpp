/*
 Exercicio12 - v0.0. - 06 / 05 / 2025
 Author: Gabriel Ferreira Pereira

 Para compilar em terminal (janela de comandos):
 Linux : g++ -o exercicio13 exercicio13.cpp
 Windows: g++ -o exercicio13 exercicio13.cpp

 Para executar em terminal (janela de comandos):
 Linux : ./exercicio13
 Windows: exercicio13
*/

#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include "Contato.hpp" 
 
using namespace std; 

// -------------------------- definicao de metodos

void metodo01() 
{
    cout << "\n\tMetodo01311\n";
    Contato contato1;
    contato1.testReadName();
    getchar();
    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}

void metodo02() 
{
    cout << "\n\tMetodo1312\n";
    Contato contato1;
    contato1.testReadPhone();
    getchar();
    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}

void metodo03() 
{
    cout << "\n\tMetodo1313\n";
    Contato contato1;
    contato1.testIsValidPhone();
    getchar();
    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}

void metodo04() 
{
    cout << "\n\tMetodo1314\n";
    Contato contato1;

    std::string nomeArquivo;
    std::cout << "Digite o nome do arquivo: ";
    std::getline(std::cin, nomeArquivo);

    contato1.readFromFile(nomeArquivo);
    
    getchar();
    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}

void metodo05() 
{
    cout << "\n\tMetodo1315\n";
    Contato contato1;
    contato1.setNome("Joao Silva");
    contato1.setFone("9999-1234", 0);

    contato1.writeToFile("Pessoa1.txt");
    
    cout << "\nApertar ENTER para continuar" << endl;
    getchar();
}

void metodo06() 
{
    cout << "\n\tMetodo1316\n";
    Contato contato1("Joao da Silva", "99999-1111", "98888-2222");

    std::cout << "Contato criado:" << std::endl;
    std::cout << contato1.toString() << std::endl;

    Contato contato2;
    std::cout << "\nLeitura de contato:" << std::endl;
    contato2.readName("Digite o nome: ");
    contato2.readPhone("Digite o primeiro telefone: ");
    contato2.readPhone("Digite o segundo telefone: ");
    
    std::cout << "\nContato lido:" << std::endl;
    std::cout << contato2.toString() << std::endl;
    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}

void metodo07() 
{
    cout << "\n\tMetodo1317\n";
    Contato contato1;
    contato1.setFone("9999-1234", 0);
    contato1.setFone("8888-5678", 1);

    int n = contato1.phones();
    contato1.testPhones();
    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}

void metodo08() 
{
    cout << "\n\tMetodo1318\n";
    
    Contato contato1;
    contato1.setFone("91234-5678", 0);

    contato1.testSetPhone2a();

    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}

void metodo09() 
{
    cout << "\n\tMetodo1319\n";
    
    Contato contato1;
    contato1.setFone("91234-5678", 0); 
    contato1.setFone("99876-4321", 1); 

    contato1.testSetPhone2b();
    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}

void metodo10() 
{
    cout << "\n\tMetodo1320\n";
    Contato contato1;
    contato1.setFone("91234-5678", 0); 
    contato1.setFone("99876-4321", 1); 

    contato1.testSetPhone2c();
    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}

void metodo11() 
{
    cout << "\n\tMetodo13E1\n";
    Contato contato1;
    contato1.setNome("Joao");
    contato1.setFone("9999-1234", 0);
    contato1.setFone("8888-5678", 1);
    contato1.setFone("7777-9999", 2);

    contato1.testPhones();
    std::cout << "Quantidade telefones: " << contato1.phones() << std::endl;

    contato1.removeFone(1);

    contato1.testPhones();
    std::cout << "Quantidade telefones: " << contato1.phones() << std::endl;

    getchar();
    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}

void metodo12() 
{
    cout << "\n\tMetodo13E2\n";

    Contato contato1;
    contato1.setNome("\nJoao da Silva\n");
    contato1.setFone("\n9999-1234\n", 0);
    contato1.setFone("\n8888-5678\n", 1);

    contato1.setEnderecoResidencial("\nRua das Flores, 123\n");
    contato1.setEnderecoProfissional("\nAv. Central, 456\n");

    std::cout << contato1.toString() << std::endl;
    contato1.testEnderecos();

    std::cout << "\nQuantidade de telefones: \n" << contato1.phones() << std::endl;

    getchar();
    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}

void menuOpcoes() {
    cout << "\nExercicio13 - v.0.0 - 06/05/2025" << endl;
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