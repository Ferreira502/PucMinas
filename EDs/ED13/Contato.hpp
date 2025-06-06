/* 
   Contato.hpp  - v0.0. - 05 / 06 / 2025 
   Author: Gabriel Ferreira
*/ 

#ifndef _CONTATO_H_ 
#define _CONTATO_H_ 

// dependencias 
#include <iostream> 
using std::cin;  
using std::cout;   
using std::endl;  

#include <iomanip> 
using std::setw;  

#include <string> 
using std::string;  

#include <fstream> 
using std::ofstream;  
using std::ifstream;   

#include "Erro.hpp" 

// pausa
void pause ( std::string text ) 
{ 
    std::string dummy; 
    std::cin.clear(); 
    std::cout << std::endl << text; 
    std::cin.ignore(); 
    std::getline(std::cin, dummy); 
    std::cout << std::endl << std::endl; 
} 

// ---------------------------------------------- definicao de classe 

/**
 * Classe para tratar contatos, derivada da classe Erro.
 */ 
class Contato : public Erro 
{ 
  private: 
    string nome; 
    string fone; 

  public: 
    // Destrutor 
    ~Contato() { } 

    // Construtor padrao 
    Contato() 
    { 
        setErro(0); 
        nome = ""; 
        fone = ""; 
    } 

    // Construtor alternativo 
    Contato(std::string nome_inicial, std::string fone_inicial) 
    { 
        setErro(0); 
        setNome(nome_inicial); 
        setFone(fone_inicial); 
    } 

    // Construtor de copia 
    Contato(Contato const &another) 
    { 
        setErro(0); 
        setNome(another.nome); 
        setFone(another.fone); 
    } 

    // Metodo para atribuir nome 
    void setNome(std::string nome) 
    { 
        if (nome.empty()) 
            setErro(1); // nome invalido 
        else 
            this->nome = nome; 
    } 

    // Metodo para atribuir telefone 
    void setFone(std::string fone) 
    { 
        if (fone.empty()) 
            setErro(2); // fone invalido 
        else 
            this->fone = fone; 
    } 

    // Funcao para obter nome 
    std::string getNome() 
    { 
        return this->nome; 
    } 

    // Funcao para obter fone 
    std::string getFone() 
    { 
        return this->fone; 
    } 

    // Funcao para obter dados como string 
    std::string toString() 
    { 
        return "{ " + getNome() + ", " + getFone() + " }"; 
    } 

    // Verificar existencia de erro 
    bool hasErro() 
    { 
        return (getErro() != 0); 
    } 
}; 

using ref_Contato = Contato*; 

#endif
