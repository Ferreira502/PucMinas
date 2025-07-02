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
    int capacity;
    int *data;
public:
    Array()
    {
        capacity = 0;
        data = nullptr;
    }

    Array (int size)
    {
        if (size <= 0)
        {
            capacity = 0;
            data = nullptr;
        }
        
        else
        {
            capacity = size;
            data = new int [capacity];

            for (int i = 0; i < capacity; i++)
            {
                data [i] = 0;
            }
        }
    }

    void push_back(int value, int& size)
    {
        if (size < capacity) // ainda tem espaço
        {
            data[size] = value;
            size++;
        }
        else
        {
            cout << "Erro: Pilha cheia. Nao e possivel inserir" << endl;
        }
    }

    void pop_back (int& size)
    {
        if ( size > 0)
        {
            size--;   
            data[size] = 0;
            
        }
        else 
        {
            cout << "Pilha vazia" << endl;
        }
    } 

    void push_front (int value, int& size)
    {
        if (size < capacity)
        {
            for (int i = size; i > 0; i--)
            {
                data[i] = data[i - 1];
            }

            data[0] = value;

            size++;
        }
        else 
        {
            cout << "Pilha cheia" << endl;
        }
    }

    void pop_front (int &size)
    {
        if(size > 0 )
        {
            for ( int i = 0; i < size - 1; i++)
                {
                    data[i] = data [i + 1];
                }
            data[size - 1] = 0;
            size --;
        }
        else 
        {
            cout << "Pilha vazia" << endl;
        }
    }

    void push_mid(int value, int& size)
    {
        if (size < capacity)
        {
            int mid = size / 2;
            
            for (int i = size; i > mid; i--)
            {
                data[i] = data[i - 1];
            }

            data[mid] = value;

            size++;
        }
        else
        {
            cout << "Erro: Pilha cheia. Nao e possivel inserir no meio." << endl;
        }
    }

    void pop_mid (int &size)
    {
        if (size > 0)
        {
            int mid = size / 2;
            for ( int i = mid; i < size - 1; i++)
                {
                    data[i] = data [i + 1];
                }
            data[size - 1] = 0;
            size --;
            
        }
        
        else
        {
            cout << "Pilha vazia. Nada para remover do meio." << endl;
        }
        
    }


    void print ( ) 
    {
        cout << "[";
        for (int i = 0; i < capacity; i++)
        {
            cout << data[i] << " ";
        }
        cout << "]" << endl;
    }

    void set(int index, int value)
    {
        if (index >= 0 && index < capacity)
        {
            data[index] = value;
        }
        else
        {
            cout << "Erro: indice invalido." << endl;
        }
    }

    int get(int index)
    {
        if (index >= 0 && index < capacity)
        {
            return data[index];
        }
        else
        {
            cout << "Erro: indice invalido." << endl;
            return -1; // valor padrão de erro
        }
    }

};

typedef struct s_intArray 
{ 
    int length; 
    int *data; 
} intArray;

typedef intArray* ref_intArray;

int intArray_cmp(ref_intArray p, ref_intArray q)
{   
    if (p == nullptr || q == nullptr) return -1;

    if (p->length != q->length)
    {
        return -1;
    }

    for (int i = 0; i < p->length; i++)
    {
        if (p->data[i] != q->data[i])
        {
            return -1;
        }
        
    }
}

ref_intArray intArray_cat(ref_intArray p, ref_intArray q)
{
    int newLength = p->length + q->length;
    ref_intArray result = new intArray;
    result->length = newLength;
    result->data = new  int[newLength];

    for (int i = 0; i < p->length; i++)
    {
        result->data[i] = p->data[i];
    }

    for (int i = 0; i < q->length; i++)
    {
        result->data[p->length + i] = q->data[i];
    }

    return result;
    
}

ref_intArray intArray_seek(ref_intArray a, int x)
{
    for (int i = 0; i < a->length; i++)
    {
        if (a->data[i] == x)
        {
            ref_intArray result = new intArray;
            result->length = 1;
            result->data = &(a->data[i]);
            return result;
        }
    }

    return nullptr; // não encontrou
}

ref_intArray intArray_sub(ref_intArray a, int start, int size)
{
    if (a == nullptr || a->data == nullptr)
    {
        cout << "Erro: array nulo" << endl;
        return nullptr;
    }

    if (start < 0 || start >= a->length || size < 0 || start + size > a->length)
    {
        cout << "Erro: intervalo invalido.\n";
        return nullptr;
    }

    // Criar novo subarray
    ref_intArray result = new intArray;
    result->length = size;
    result->data = new int[size];

    for (int i = 0; i < size; i++)
    {
        result->data[i] = a->data[start + i];
    }

    return result;
}

ref_intArray intArray_merge(ref_intArray p, ref_intArray q)
{
    // Validar entrada
    if (p == nullptr || q == nullptr || p->data == nullptr || q->data == nullptr)
    {
        cout << "Erro: arrays invalidos.\n";
        return nullptr;
    }

    // Criar novo array para o resultado
    int total = p->length + q->length;
    ref_intArray result = new intArray;
    result->length = total;
    result->data = new int[total];

    int i = 0, j = 0, k = 0;

    // Merge: comparando elementos
    while (i < p->length && j < q->length)
    {
        if (p->data[i] <= q->data[j])
        {
            result->data[k++] = p->data[i++];
        }
        else
        {
            result->data[k++] = q->data[j++];
        }
    }

    // Copiar o restante de p (se sobrar)
    while (i < p->length)
    {
        result->data[k++] = p->data[i++];
    }

    // Copiar o restante de q (se sobrar)
    while (j < q->length)
    {
        result->data[k++] = q->data[j++];
    }

    return result;
}

void bobby_Short(ref_intArray a)
{
    for (int i = 0; i < a->length - 1; i++)
    {
        for (int j = i + 1; j < a->length; j++)
        {
            if (a->data[i] < a->data[j])
            {
                int temp = a->data[i];
                a->data[i] = a->data[j];
                a->data[j] = temp;
            }
        }
    }
}

ref_intArray intArray_mergeDown(ref_intArray p, ref_intArray q)
{
    if (p == nullptr || q == nullptr || p->data == nullptr || q->data == nullptr)
        return nullptr;

    bobby_Short(p);
    bobby_Short(q);

    int total = p->length + q->length;
    ref_intArray result = new intArray;
    result->length = total;
    result->data = new int[total];

    int i = 0, j = 0, k = 0;

    while (i < p->length && j < q->length)
    {
        if (p->data[i] >= q->data[j])
            result->data[k++] = p->data[i++];
        else
            result->data[k++] = q->data[j++];
    }

    while (i < p->length)
        result->data[k++] = p->data[i++];

    while (j < q->length)
        result->data[k++] = q->data[j++];

    return result;
}



void intArray_print(ref_intArray arr)
{
    cout << "[";
    for (int i = 0; i < arr->length; i++)
    {
        cout << arr->data[i] << " ";
    }
    cout << "]" << endl;
}


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
    Array   a (10);
    int size = 0; 
    
    //Adiciona dados na Pilha de tras pra frente
    // |__|__|__|__|__| <--

    a.push_back(1, size); // insere 1 na posição 0
    a.push_back(2, size); // insere 2 na posição 1
    
    cout << "push back: "  <<  endl;
    a.print();

    cout << "\n";
    //Remove dados na Pilha de tras pra frente
    // |__|__|__|__|__| <--

    // a.pop_back(size); // remove 2 na posicao 1
    // a.pop_back(size); // remove 1 na posicao 0
    cout << "pop back: " << endl;
    a.print();

    cout << "\n";

    //Adiciona dados na Pilha de frente para tras
    // -->  |__|__|__|__|__|

    a.push_front(1, size); // insere 1 na posicao 1
    a.push_front(2, size); // insere 2 na posicao 0

    cout << "push front: " << endl;
    a.print();

    cout << "\n";
    //Remove dados na Pilha de frente para tras
    // -->  |__|__|__|__|__|

    // a.pop_front(size); // remove 2 na posicao 0
    // a.pop_front(size); // remove 1 na posicao 1
    cout << "pop front: " << endl;
    a.print();

    cout << "\n";

    a.push_mid(5, size); // insere 5 na posicao do meio
    cout << "push mid: " << endl;
    a.print();

    cout << "\n";
    a.pop_mid(size); // remove o valor na posicao do meio
    cout << "pop mid: " << endl;
    a.print();

    cout << "\n";
    //Comparacao

    cout << "Comparacao: " << endl;

    // Usando struct intArray
    ref_intArray x = new intArray{3, new int[3]{1, 2, 3}};
    ref_intArray y = new intArray{3, new int[3]{1, 2, 3}};
    ref_intArray z = new intArray{3, new int[3]{1, 2, 4}};

    cout << "x: "; intArray_print(x);
    cout << "y: "; intArray_print(y);
    cout << "z: "; intArray_print(z);

    cout << "x == y: " << intArray_cmp(x, y) << endl; // 3
    cout << "x <  z: " << intArray_cmp(x, z) << endl; // -1

    cout << "\n";
    //Concatenar

    cout << "Concatenar: " << endl;

    ref_intArray d = new intArray{3, new int[3]{1, 2, 3}};
    ref_intArray e = new intArray{2, new int[2]{4, 5}};
    ref_intArray r = intArray_cat(d, e);

    cout << "d: "; intArray_print(d);
    cout << "e: "; intArray_print(e);
    cout << "d + e: "; intArray_print(r);

    cout << "\n";
    //Seek

    cout << "Seek:" << endl;

    ref_intArray arr = new intArray{5, new int[5]{10, 20, 30, 40, 50}};
    ref_intArray found = intArray_seek(arr, 30);

    if (found != nullptr)
    {
        cout << "Valor 30 encontrado: ";
        intArray_print(found);
    }
    else
    {
        cout << "Valor 30 nao encontrado.\n";
    }

    cout << "\n";
    //Substring

    cout << "Substring" << endl;

    ref_intArray f = new intArray{5, new int[5]{10, 20, 30, 40, 50}};
    ref_intArray sub = intArray_sub(f, 1, 3); // Esperado: {20, 30, 40}
    intArray_print(sub);

    cout << "\n";
    //Merge

    ref_intArray g = new intArray{4, new int[4]{1, 3, 5, 7}};
    ref_intArray h = new intArray{3, new int[3]{2, 4, 6}};
    ref_intArray i = intArray_merge(g, h);

    cout << "a: "; intArray_print(g);  // [1 3 5 7]
    cout << "b: "; intArray_print(h);  // [2 4 6]
    
    cout << "Merge: " << endl; 
    intArray_print(i);  // [1 2 3 4 5 6 7]

    cout << "\n";
    //Merge Down

    ref_intArray j = new intArray{3, new int[3]{9, 6, 3}};
    ref_intArray k = new intArray{3, new int[3]{8, 7, 2}};
    ref_intArray l = intArray_mergeDown(j, k);

    cout << "MergeDown" << endl;
    intArray_print(l); // deve exibir: [9 8 7 6 3 2]

    cout << "\n";

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