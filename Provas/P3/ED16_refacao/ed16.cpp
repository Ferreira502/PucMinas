/* 
   Exemplo1600 - v0.0. - __ / __ / _____ 
   Author: _____________________________ 
 
 */ 
 
// ----------------------------------------------- preparacao 
 
// dependências 
 
#include <iostream> 
 
// ----------------------------------------------- definicoes globais 
 
using namespace std; 
 

void pause ( std::string text ) 
{ 
    std::string dummy; 
    std::cin.clear ( ); 
    std::cout << std::endl << text; 
    std::cin.ignore( ); 
    std::getline(std::cin, dummy); 
    std::cout << std::endl << std::endl; 
} // end pause ( ) 

// ----------------------------------------------- metodos 
 
class Array
{
private:
    int length;
    int *data;
public:
    Array()
    {
        length = 0;
        data = nullptr;
    }

    Array (int size)
    {
        if (size <= 0)
        {
            length = 0;
            data = nullptr;
        }
        
        else
        {
            length = size;
            data = new int [length];

            for (int i = 0; i < length; i++)
            {
                data [i] = 0;
            }
        }
    }

     void push_back(int value) 
     {
        int* newData = new int[length + 1];

        for (int i = 0; i < length; i++) {
            newData[i] = data[i];
        }

        newData[length] = value;
        delete[] data;
        data = newData;
        length++;
    }

    void array_pop_back ( int *array)
    {

    } 

    void array_push_front (int *array, int value)
    {

    }

    void array_pop_front (int *array)
    {

    }

    void print ( ) 
    {
        cout << "[";
        for (int i = 0; i < length; i++)
        {
            cout << data[i] << " ";
        }
        cout << "]";
    }
};


/** 
   Method_00 - nao faz nada. 
 */ 
void method_00 ( ) 
{ 
 // nao faz nada 
} // end method_00 ( ) 
 
/** 
   Method_01 - Testar definicoes da classe. 
 */ 
void method_01 ( ) 
{ 
 // definir dados 
 
 // identificar 
    cout << "\nMethod_01 - v0.0\n" << endl; 
    Array   a;
    Array * b = nullptr;
    
    a.push_back(1);

    cout << "push back: "  <<  endl;
    a.print();

 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_01 ( )

// ----------------------------------------------- acao principal 
 
/* 
  Funcao principal. 
  @return codigo de encerramento 
*/ 
int main ( ) 
{ 
 // definir dado 
    int x = 0;  // definir variavel com valor inicial 
 
 // repetir até desejar parar 
    do 
    { 
     // identificar 
        cout << "EXEMPLO1600 - Programa - v0.0\n " << endl; 
 
     // mostrar opcoes 
        cout << "Opcoes     " << endl; 
        cout << " 0 - parar    " << endl; 
        cout << " 1 - testar definicoes  " << endl; 
 
     // ler do teclado 
        cout << endl << "Entrar com uma opcao: "; 
        cin  >> x; 
 
     // escolher acao 
        switch ( x ) 
        { 
          case 0: 
            method_00 ( ); 
           break; 
          case 1: 
            method_01 ( ); 
           break; 
          default: 
            cout << endl << "ERRO: Valor invalido." << endl; 
        } // end switch 
    } 
    while ( x != 0 ); 
 
 // encerrar 
    pause  ( "Apertar ENTER para terminar" ); 
    return ( 0 ); 
} // end main ( )

/* 
---------------------------------------------- documentacao complementar 
 
---------------------------------------------- notas / observacoes / comentarios 
 
---------------------------------------------- previsao de testes 
 
---------------------------------------------- historico 
 
Versao Data   Modificacao 
  0.1 __/__   esboco 
 
 ---------------------------------------------- testes 
 
Versao Teste 
  0.1 01. ( OK )    identificacao de programa 
 
*/