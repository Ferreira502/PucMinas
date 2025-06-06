/*
 Exercicio12 - v0.0. - 30 / 05 / 2025
 Author: Gabriel Ferreira Pereira

 Para compilar em terminal (janela de comandos):
 Linux : g++ -o exercicio12 exercicio12.cpp
 Windows: g++ -o exercicio12 exercicio12.cpp

 Para executar em terminal (janela de comandos):
 Linux : ./exercicio12
 Windows: exercicio12
*/

#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include "mymatrix.hpp" 
 
using namespace std; 

// -------------------------- definicao de metodos

int randomIntGenerate(int inferior, int superior) {
    return inferior + rand() % (superior - inferior + 1);
}

void metodo01() 
{
    cout << "\n\tMetodo01211\n";
    int M = 0, N = 0;
    cout << "Digite a quantidade de linhas (M): ";
    cin >> M;
    cout << "Digite a quantidade de colunas (N): ";
    cin >> N;

    srand(time(0));

    int** matriz = new int*[M];
    for (int i = 0; i < M; i++) 
    {
        matriz[i] = new int[N];
    }

    for (int i = 0; i < M; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            matriz[i][j] = randomIntGenerate(1, 100);
        }
    }

    ofstream arquivo("DADOS.TXT");
    if (!arquivo) 
    {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return;
    }

    arquivo << (M * N) << endl;

    for (int i = 0; i < M; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            arquivo << matriz[i][j] << endl;
        }
    }

    arquivo.close();
    cout << "Valores gravados em 'DADOS.TXT' com sucesso!" << endl;

    for (int i = 0; i < M; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}

void metodo02() 
{
    cout << "\n\tMetodo1212\n";
    Matrix<int> matrix1;
    Matrix<int> matrix2;
    string fileName;
    int constante;

    cout << "Digite o nome do arquivo de entrada: ";
    cin >> fileName;
    cin.ignore();

    matrix1.fread(fileName);

    cout << "Digite a constante para escalar a matriz: ";
    cin >> constante;
    cin.ignore(); 
    
    matrix2 = matrix1.scalar(constante);

    cout << "\n--- Matriz Original ---" << endl;
    matrix1.print();

    cout << "\n--- Matriz Escalada ---" << endl;
    matrix2.print();
    
    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}

void metodo03() 
{
    cout << "\n\tMetodo1213\n";
    Matrix<int> matrix1;
    string fileName;

    cout << "Digite o nome do arquivo com a matriz: ";
    cin >> fileName;
    cin.ignore();

    matrix1.fread(fileName);

    cout << "\n--- Matriz Lida ---\n";
    matrix1.print();

    if (matrix1.identidade())
        cout << "\nA matriz e identidade";
    else
        cout << "\nA matriz NAO e identidade\n";
    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}

void metodo04() 
{
    cout << "\n\tMetodo1214\n";
    Matrix<int> matrix1;
    Matrix<int> matrix2;
    string file1, file2;

    cout << "Digite o nome do primeiro arquivo: ";
    cin >> file1;
    cout << "Digite o nome do segundo arquivo: ";
    cin >> file2;

    matrix1.fread(file1);
    matrix2.fread(file2);

    cout << "\n--- Matriz 1 ---" << endl;
    matrix1.print();

    cout << "\n--- Matriz 2 ---" << endl;
    matrix2.print();

    if (matrix1 == matrix2){
        cout << "\nAs matrizes sao IGUAIS";
        getchar();
        }
        
    else{
        cout << "\nAs matrizes sao DIFERENTES";
        getchar();
        }

    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}

void metodo05() 
{
    cout << "\n\tMetodo1215\n";
    Matrix<int> matrix1;
    Matrix<int> matrix2;
    Matrix<int> soma;

    string file1;
    string file2;

    cout << "\nDigite o nome do primeiro arquivo: ";
    cin >> file1;

    cout << "Digite o nome do segundo arquivo: ";
    cin >> file2;

    matrix1.fread(file1);
    matrix2.fread(file2);

    cout << "\nMatrix 1:\n";
    matrix1.print();

    cout << "\nMatrix 2:\n";
    matrix2.print();

    soma = matrix1.add(matrix2);

    cout << "\nMatriz resultante da soma: ";
    soma.print();
    getchar();

    cout << "\nApertar ENTER para continuar" << endl;
    getchar();
}

void metodo06() 
{
    cout << "\n\tMetodo1216\n";
    Matrix<int> matrix1;
    string fileName;
    int row1 = 0, row2 = 0, constante = 0;

    cout << "\nDigite o nome do arquivo: ";
    cin >> fileName;

    matrix1.fread(fileName);

    cout << "\nMatriz original:\n";
    matrix1.print();

    cout << "\nDigite o indice da linha a ser modificada: ";
    cin >> row1;

    cout << "Digite o indice da linha usada na operacao: ";
    cin >> row2;

    cout << "Digite a constante multiplicadora: ";
    cin >> constante;

    matrix1.addRows(row1, row2, constante);

    getchar();
    cout << "\nMatriz apos a operacao:\n";
    matrix1.print();
    getchar();

    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}

void metodo07() 
{
    cout << "\n\tMetodo1217\n";
     Matrix<int> matrix1;
    string fileName;
    int row1 = 0, row2 = 0, constante = 0;

    cout << "\nDigite o nome do arquivo: ";
    cin >> fileName;

    matrix1.fread(fileName);

    cout << "\nMatriz original:\n";
    matrix1.print();

    cout << "\nDigite o indice da linha a ser modificada: ";
    cin >> row1;

    cout << "Digite o indice da linha usada na operacao: ";
    cin >> row2;

    cout << "Digite a constante multiplicadora: ";
    cin >> constante;

    matrix1.subtractRows(row1, row2, constante);

    getchar();
    cout << "\nMatriz apos a operacao:\n";
    matrix1.print();
    getchar();

    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}

void metodo08() 
{
    cout << "\n\tMetodo1218\n";
    Matrix<int> matrix1;
    string fileName;
    int procurado;

    cout << "\nDigite o nome do arquivo: ";
    cin >> fileName;

    matrix1.fread(fileName);

    cout << "\nMatriz carregada:\n";
    matrix1.print();

    cout << "\nDigite o valor a procurar: ";
    cin >> procurado;

    int linha = matrix1.searchRows(procurado);

    getchar();
    if (linha >= 0)
    {
        cout << "\nValor encontrado na linha: " << linha << endl;
        getchar();
    }
    else
    {
        cout << "\nValor NAO encontrado na matriz\n";
        getchar();
    }

    getchar();
    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}

void metodo09() 
{
    cout << "\n\tMetodo1219\n";
    Matrix<int> matrix1;
    string fileName;
    int procurado;

    cout << "\nDigite o nome do arquivo: ";
    cin >> fileName;

    matrix1.fread(fileName);

    cout << "\nMatriz carregada:\n";
    matrix1.print();

    cout << "\nDigite o valor a procurar: ";
    cin >> procurado;

    int coluna = matrix1.searchColumns(procurado);

    getchar();
    if (coluna >= 0)
    {
        cout << "\nValor encontrado na coluna: " << coluna << endl;
    }
    else
    {
        cout << "\nValor NAO encontrado na matriz.\n";
    }

    getchar();
    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}

void metodo10() 
{
    cout << "\n\tMetodo1220\n";
    Matrix<int> matrix1;
    string fileName;

    cout << "\nDigite o nome do arquivo: ";
    cin >> fileName;

    matrix1.fread(fileName);

    cout << "\nMatriz original:\n";
    matrix1.print();

    matrix1.transpose();

    getchar();
    cout << "\nMatriz transposta:\n";
    matrix1.print();

    getchar();
    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}

void metodo11() 
{
    cout << "\n\tMetodo12E1\n";
    Matrix<int> matrix1;
    string fileName;

    cout << "Digite o nome do arquivo: ";
    cin >> fileName;

    matrix1.fread(fileName);
    matrix1.print();

    if (matrix1.hasSequentialValuesByRow())
    {
        cout << "A matriz tem linhas com valores consecutivos.\n";
    }
    else
    {
        cout << "A matriz NAO tem linhas com valores consecutivos.\n";
    }

    getchar();
    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}

void metodo12() 
{
    cout << "\n\tMetodo12E2\n";
    int linhas = 0, colunas = 0;

    cout << "Digite o numero de linhas: ";
    cin >> linhas;

    cout << "Digite o numero de colunas: ";
    cin >> colunas;

    Matrix<int> matriz(linhas, colunas, 0);

    int valor = 1;

    for (int i = linhas - 1; i >= 0; i--)
    {
        for (int j = 0; j < colunas; j++)
        {
            matriz.set(i, j, valor);
            valor++;
        }
    }

    getchar();
    cout << "\nMatriz preenchida:\n";
    matriz.print();

    getchar();
    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}

void menuOpcoes() {
    cout << "\nExercicio12 - v.0.0 - 06/05/2025" << endl;
    cout << "Matricula: 842527 Nome: Gabriel Ferreira Pereira" << endl;
    cout << "Opcoes:" << endl;
    cout << " 0 - parar" << endl;
    cout << " 1 - metodo 1311" << endl;
    cout << " 2 - metodo 1312" << endl;
    cout << " 3 - metodo 1313" << endl;
    cout << " 4 - metodo 1314" << endl;
    cout << " 5 - metodo 1315" << endl;
    cout << " 6 - metodo 1316" << endl;
    cout << " 7 - metodo 1317" << endl;
    cout << " 8 - metodo 1318" << endl;
    cout << " 9 - metodo 1319" << endl;
    cout << "10 - metodo 1320" << endl;
    cout << "11 - metodo 13E1" << endl;
    cout << "12 - metodo 13E2" << endl;
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