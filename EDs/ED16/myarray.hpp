/* 
   myarray.hpp   - v0.0. - 27 / 05 / 2025 
   Author: Gabriel Ferreira Pereira
*/ 
 
// ----------------------------------------------- definicoes globais 
 
#ifndef  _MYARRAY_HPP_ 
#define _MYARRAY_HPP_ 
 
// dependencias 
 
#include <iostream> 
using std::cin  ;  // para entrada 
using std::cout;  // para saida 
using std::endl;  // para mudar de linha 
 
#include <iomanip> 
using std::setw;   // para definir espacamento 
 
#include <string> 
using std::string;   // para cadeia de caracteres 
 
#include <fstream> 
using std::ofstream;   // para gravar arquivo 
using std::ifstream ;   // para ler       arquivo 
 
 
template < typename T > 
class Array 
{ 
  private:   // area reservada 
    T   optional; 
    int length; 
    T  *data; 
 
  public:   // area aberta 
    Array ( int n, T initial ) 
    { 
     // definir valores iniciais 
        optional = initial; 
        length    = 0; 
        data       = nullptr; 
 
     // reservar area 
        if ( n > 0 ) 
        { 
             length  = n; 
             data     = new T [ length ]; 
        } 
    } // end constructor 
 
    void free ( ) 
    { 
       if ( data != nullptr ) 
       { 
          delete ( data ); 
          data = nullptr; 
       } // end if 
    } // end free ( ) 
 
   void set ( int position, T value ) 
    { 
      if ( 0 <= position && position < length ) 
      { 
         data [ position ] = value; 
      } // end if 
    } // end set ( ) 
 
    T    get ( int position ) 
    { 
      T value = optional; 
 
      if ( 0 <= position && position < length ) 
      { 
        value = data [ position ]; 
      } // end if 
 
      return ( value ); 
    } // end get ( ) 
 
    void print ( ) 
    { 
       cout << endl; 
       for ( int x = 0; x < length; x=x+1 ) 
       { 
           cout << setw( 3 ) << x << " : " 
                    << setw( 9 ) << data[ x ] 
                    << endl; 
       } // end for 
       cout << endl; 
    } // end print ( ) 

    void read ( ) 
    { 
       cout << endl; 
       for ( int x = 0; x < length; x=x+1 ) 
       { 
           cout << setw( 3 ) << x << " : "; 
           cin   >> data[ x ]; 
       } // end for 
       cout << endl; 
    } // end read ( )

     void fprint ( string fileName ) 
    { 
       ofstream afile;  // output file 
 
       afile.open ( fileName ); 
       afile << length << endl; 
       for ( int x = 0; x < length; x=x+1 ) 
       { 
           afile << data[ x ] << endl; 
       } // end for 
       afile.close ( ); 
    } // end fprint ( )

      void fread ( string fileName ) 
    { 
       ifstream afile; // input file 
       int n = 0; 
       afile.open ( fileName ); 
       afile >> n; 
       if ( n <= 0 ) 
       { 
          cout << "\nERROR: Invalid length.\n" << endl; 
       } 
       else 
       { 
        // guardar a quantidade de dados 
           length  = n; 
        // reservar area 
           data    = new T [ n ]; 
        // ler dados 
           for ( int x = 0; x < length; x=x+1 ) 
           { 
              afile >> data[ x ]; 
           } // end for 
       } // end if 
       afile.close ( ); 
    } // end fread ( )

     Array ( )    // construtor padrao 
    { 
     // definir valores iniciais 
        length  = 0; 
     // reservar area 
        data     = nullptr; 
    } // end constructor 
 
     // contrutor baseado em copia 
    Array ( int length, int other [ ] ) 
    { 
       if ( length <= 0 ) 
       { 
          cout << "\nERROR: Missing data.\n" << endl; 
       } 
       else 
       { 
        // criar copia 
           this->length = length; 
        // reservar area 
           data   = new T [ this->length ]; 
        // ler dados 
           for ( int x = 0; x < this->length; x=x+1 ) 
           { 
               data [ x ] = other [ x ]; 
           } // end for 
       } // end if 
    } // end constructor ( ) 

     Array ( const Array& other ) 
    { 
       if ( other.length <= 0 ) 
       { 
          cout << "\nERROR: Missing data.\n" << endl; 
       } 
       else 
       { 
        // criar copia 
           length = other.length; 
        // reservar area 
           data    = new T [ other.length ]; 
        // ler dados 
           for ( int x = 0; x < length; x=x+1 ) 
           { 
               data [ x ] = other.data [ x ]; 
           } // end for 
       } // end if 
    } // end constructor ( ) 
    
    Array& operator= ( const Array <T> other ) 
    { 
       if ( other.length <= 0 ) 
       { 
          cout << "\nERROR: Missing data.\n" << endl; 
       } 
       else 
       { 
           this->length = other.length; 
           this->data    = new T [ other.length ]; 
           for ( int x = 0; x < this->length; x=x+1 ) 
           { 
               data [ x ] = other.data [ x ]; 
           } // end for 
       } // end if 
       return ( *this ); 
    } // end operator= ( )

     bool operator== ( const Array <T> other ) 
    { 
       bool result = false; 
       int  x           = 0; 
 
       if ( other.length == 0 || length != other.length ) 
       { 
          cout << "\nERROR: Missing data.\n" << endl; 
       } 
       else 
       { 
          x = 0;  
          result = true; 
          while ( x < this->length && result ) 
          { 
              result = result &&  (data [ x ] == other.data [ x ] ); 
              x = x + 1; 
          } // end while 
       } // end if 
       return ( result ); 
    } // end operator== ( )

     Array& operator+ ( const Array <T> other ) 
    { 
       static Array <T> result ( other ); 
 
       if ( other.length <= 0 ) 
       { 
          cout << "\nERROR: Missing data.\n" << endl; 
       } 
       else 
       { 
          for ( int x = 0; x < this->length; x=x+1 ) 
          { 
              result.data [ x ] = result.data [ x ] + this->data [ x ]; 
          } // end for 
       } // end if 
       return ( result ); 
    } // end operator+ ( ) 

     const int getLength ( ) 
    { 
       return ( length ); 
    } // end getLength ( ) 
 
    T& operator[]( const int position ) 
    { 
       static T value = optional; 
 
       if ( position < 0 || length <= position ) 
       { 
          cout << endl << "\nERROR: Invalid position.\n" << endl; 
       } 
       else 
       { 
         value = data [ position ]; 
       } // end if 
       return ( value ); 
    } // end operator [ ]

void randomIntGenerate(int n, int inferior, int superior)
{
    if (n <= 0 || inferior > superior)
    {
        cout << "\nERROR: Invalid parameters for random generation.\n" << endl;
        return;
    }

    if (data != nullptr)
    {
        delete[] data;
    }

    length = n;
    data = new T[length];

    for (int i = 0; i < length; i++)
    {
        data[i] = inferior + rand() % (superior - inferior + 1);
    }
}

T searchFirstOdd()
{
    T maior = optional;
    bool encontrado = false;

    for (int i = 0; i < length; i++)
    {
        if (data[i] % 2 != 0)
        {
            if (!encontrado)
            {
                maior = data[i];
                encontrado = true;
            }
            else if (data[i] > maior)
            {
                maior = data[i];
            }
        }
    }

    if (!encontrado)
    {
        cout << "\nNao ha valores impares no arranjo" << endl;
    }

    return maior;
}

T searchFirstOddx3()
{
    T maior = optional;
    bool encontrado = false;

    for (int i = 0; i < length; i++)
    {
        if (data[i] % 2 != 0 && data[i] % 3 == 0)
        {
            if (!encontrado)
            {
                maior = data[i];
                encontrado = true;
            }
            else if (data[i] > maior)
            {
                maior = data[i];
            }
        }
    }

    if (!encontrado)
    {
        cout << "\nNao ha valores impares multiplos de 3 no arranjo" << endl;
    }

    return maior;
}

T addInterval(int start, int end)
{
    T soma = 0;

    if (start < 0 || end >= length || start > end)
    {
        cout << "\nERRO: Intervalo invalido" << endl;
        return soma;
    }

    for (int i = start; i <= end; i++)
    {
        soma = soma + data[i];
    }

    return soma;
}

double averageInterval(int start, int end)
{
    double media = 0.0;

    if (start < 0 || end >= length || start > end)
    {
        cout << "\nERRO: Intervalo invalido" << endl;
        return media;
    }

    T soma = 0;
    int quantidade = (end - start + 1);

    for (int i = start; i <= end; i++)
    {
        soma += data[i];
    }

    media = static_cast<double>(soma) / quantidade;

    return media;
}

bool negatives()
{
    bool resultado = true;

    for (int i = 0; i < length; i++)
    {
        if (data[i] <= 100)
        {
            resultado = false;
            break;
        }
    }

    return resultado;
}

bool isDecrescent()
{
    bool resultado = true;

    for (int i = 0; i < length - 1; i++)
    {
        resultado = resultado && (data[i] >= data[i + 1]);
    }

    return resultado;
}

bool searchInterval(T procurado, int inicio, int fim)
{
    bool resultado = false;

    if (inicio >= 0 && fim < length && inicio <= fim)
    {
        for (int i = inicio; i <= fim; i++)
        {
            resultado = resultado || (data[i] == procurado);
        }
    }
    else
    {
        cout << "\nERRO: Intervalo invalido" << endl;
    }

    return resultado;
}

Array<T> scalar(T constante, int inicio, int fim)
{
    Array<T> resultado(length, 0);

    if (inicio >= 0 && fim < length && inicio <= fim)
    {
        for (int i = 0; i < length; i++)
        {
            if (i >= inicio && i <= fim)
            {
                resultado.set(i, data[i] * constante);
            }
            else
            {
                resultado.set(i, data[i]);
            }
        }
    }
    else
    {
        cout << "\nERRO: Intervalo invalido" << endl;
    }

    return resultado;
}

void sortDown()
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (data[j] < data[j + 1])
            {
                T temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

bool operator!= (const Array<T>& other)
{
    if (length != other.length)
    {
        return true;
    }

    for (int i = 0; i < length; i++)
    {
        if (data[i] != other.data[i])
        {
            return true;
        }
    }

    return false;
}

Array<T> operator- (const Array<T>& other)
{
    Array<T> result(length, 0);

    if (length != other.length)
    {
        cout << "\nERROR: Arrays have different lengths.\n" << endl;
    }
    else
    {
        for (int i = 0; i < length; i++)
        {
            result.set(i, data[i] - other.data[i]);
        }
    }

    return result;
}

}; 


#endif 