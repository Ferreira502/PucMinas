/* 
   mymatrix.hpp  - v0.0. - 30 / 05 / 2025 
   Author: Gabriel Ferreira Pereira
 
 */ 
 
// ----------------------------------------------- definicoes globais 
 
#ifndef  _MYMATRIX_H_ 
#define _MYMATRIX_H_ 
 
// dependencias 
 
#include <iostream> 
using std::cin  ;  // para entrada 
using std::cout;   // para saida 
using std::endl;  // para mudar de linha 
 
#include <iomanip> 
using std::setw;  // para definir espacamento 
 
#include <string> 
using std::string;  // para cadeia de caracteres 
 
#include <fstream> 
using std::ofstream;  // para gravar arquivo 
using std::ifstream;   // para ler    arquivo 
 
 
template < typename T > 
class Matrix 
{ 
  private:    // area reservada 
    T   optional; 
    int rows      ; 
    int columns; 
    T** data       ; 
 
 
 
 
 
 
 
 
 
 
 
 
  public   // area aberta 
    Matrix ( ) 
    { 
     // definir valores iniciais 
        this->rows       = 0; 
        this->columns = 0; 
     // sem reservar area 
        data                  = nullptr; 
    } // end constructor 
 
    Matrix ( int rows, int columns, T initial ) 
    { 
     // definir dado local 
        bool OK            = true; 
     // definir valores iniciais 
        this->optional = initial      ; 
        this->rows       = rows       ; 
        this->columns = columns; 
     // reservar area 
        data         = new T* [ rows ]; 
        if ( data != nullptr ) 
        { 
           for ( int x = 0; x < rows; x=x+1 ) 
           { 
              data [x] = new T  [ columns ]; 
              OK = OK && ( data [x] != nullptr ); 
           } // end for 
           if ( ! OK ) 
           { 
              data = nullptr; 
           } // end if 
        } // end if 
    } // end constructor 
 
   ~Matrix ( ) 
   { 
       if ( data != nullptr ) 
       { 
          for ( int x = 0; x < rows; x=x+1 ) 
          { 
              delete ( data [ x ] ); 
          } // end for 
          delete ( data ); 
          data = nullptr; 
       } // end if 
   } // end destructor ( ) 
 
    void set ( int row, int column, T value ) 
    { 
      if ( row       < 0 || row        >= rows      || 
           column < 0 || column >= columns ) 
      { 
         cout << "\nERROR: Invalid position.\n"; 
      } 
      else 
      { 
         data [ row ][ column ] = value; 
      } // end if 
    } // end set ( ) 
 
    T    get ( int row, int column ) 
    { 
      T value = optional; 
      if ( row       < 0 || row       >= rows       || 
           column < 0 || column >= columns ) 
      { 
         cout << "\nERROR: Invalid position.\n"; 
      } 
      else 
      { 
         value = data [ row ][ column ]; 
      } // end if 
      return ( value ); 
    } // end get ( ) 
     
    void print ( ) 
    { 
       cout << endl; 
       for ( int x = 0; x < rows; x=x+1 ) 
       { 
           for ( int y = 0; y < columns; y=y+1 ) 
           { 
               cout << data[ x ][ y ] << "\t"; 
           } // end for 
           cout << endl; 
       } // end for 
       cout << endl; 
    } // end print ( ) 
}; // end class 
 
#endif 