/* 
   Contato.hpp  - v0.1. - 06 / 06 / 2025 
   Author: Gabriel Ferreira
*/ 

#ifndef _CONTATO_H_ 
#define _CONTATO_H_ 

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
void pause(std::string text) 
{ 
    std::string dummy; 
    std::cin.clear(); 
    std::cout << std::endl << text; 
    std::cin.ignore(); 
    std::getline(std::cin, dummy); 
    std::cout << std::endl << std::endl; 
} 

// ---------------------------------------------- definicao de classe 

class Contato : public Erro 
{ 
  private: 
    string nome; 
    string fones[10];
    int quantidade;
    std::string endResidencial;
    std::string endProfissional;

  public: 
    ~Contato() { } 

    Contato()
    {
        setErro(0);
        nome = "";
        quantidade = 0;
        for (int i = 0; i < 10; i++)
            fones[i] = "";
        endResidencial = "";
        endProfissional = "";
    }

    Contato(std::string nome_inicial, std::string fone1, std::string fone2 = "") 
    {
        setErro(0);
        setNome(nome_inicial);
        setFone(fone1, 0);
        setFone(fone2, 1);
    }

    Contato(const Contato& another) 
    {
        setErro(0);
        nome = another.nome;
        fones[0] = another.fones[0];
        fones[1] = another.fones[1];
        quantidade = another.quantidade;
    }

    void setNome(const std::string& nome)
    {
        if (nome.empty())
            setErro(1);
        else
            this->nome = nome;
    }

    void setFone(const std::string& fone, int index)
    {
        if (index < 0 || index >= 10 || fone.empty())
        {
            setErro(2);
            return;
        }

        fones[index] = fone;

        if (index >= quantidade)
            quantidade = index + 1;

        setErro(0);
    }

    std::string getNome() 
    { 
        return this->nome; 
    } 

    std::string getFone(int index) const
    {
        if (index < 0 || index >= quantidade)
            return "";
        return fones[index];
    }

     int phones() const
    {
        return quantidade;
    }

    void removeFone(int index)
    {
        if (index < 0 || index >= quantidade)
        {
            std::cout << "Erro: Indice invalido para remover telefone" << std::endl;
            return;
        }
        for (int i = index; i < quantidade - 1; i++)
        {
            fones[i] = fones[i + 1];
        }
        fones[quantidade - 1] = "";
        quantidade--;
        setErro(0);
    }

    void setEnderecoResidencial(const std::string& endereco)
    {
        endResidencial = endereco;
    }

    std::string getEnderecoResidencial() const
    {
        return endResidencial;
    }

    void setEnderecoProfissional(const std::string& endereco)
    {
        endProfissional = endereco;
    }

    std::string getEnderecoProfissional() const
    {
        return endProfissional;
    }

    std::string toString() const
    {
        std::string resultado = "{ " + nome;
        for (int i = 0; i < quantidade; i++)
        {
            if (!fones[i].empty())
            {
                resultado += ", " + fones[i];
            }
        }
        if (!endResidencial.empty())
            resultado += ", Endereco Residencial: " + endResidencial;
        if (!endProfissional.empty())
            resultado += ", Endereco Profissional: " + endProfissional;
        resultado += " }";
        return resultado;
    }

    void testEnderecos() const
    {
        std::cout << "\nEndereco Residencial: \n" << (endResidencial.empty() ? "Nao informado" : endResidencial) << std::endl;
        std::cout << "\nEndereco Profissional: \n" << (endProfissional.empty() ? "Nao informado" : endProfissional) << std::endl;
    }

    bool hasErro() 
    { 
        return (getErro() != 0); 
    } 

    void readName(std::string prompt)
    {
        std::string input;
        std::cout << prompt;
        std::getline(std::cin, input);
        setNome(input);
    }

    void testReadName()
    {
        readName("Nome: ");
        if (hasErro())
            std::cout << "ERRO: nome invalido" << std::endl;
        else
            std::cout << "Nome armazenado: " << getNome() << std::endl;
    }

    void readPhone(std::string prompt)
    {
        std::string input;
        std::cout << prompt;
        std::getline(std::cin, input);

        if (fones[0].empty()) setFone(input, 0);
        else setFone(input, 1);
    }

    void testReadPhone()
    {
        readPhone("Fone: ");
        if (hasErro())
            std::cout << "ERRO: telefone invalido" << std::endl;
        else
            std::cout << "Telefone armazenado: " << toString() << std::endl;
    }

    bool isValidPhone(std::string fone)
    {
        for (char c : fone)
        {
            if (!isdigit(c) && c != '-')
                return false;
        }
        return !fone.empty();
    }

    void testIsValidPhone()
    {
        std::string input;
        std::cout << "Digite um telefone para testar: ";
        std::getline(std::cin, input);

        if (isValidPhone(input))
            std::cout << "Telefone valido" << std::endl;
        else
            std::cout << "Telefone invalido" << std::endl;
    }

    void readFromFile(std::string fileName)
    {
        std::ifstream file(fileName);

        if (!file)
        {
            std::cout << "Erro ao abrir o arquivo: " << fileName << std::endl;
            return;
        }

        std::getline(file, nome);
        std::getline(file, fones[0]);
        std::getline(file, fones[1]);

        file.close();

        if (!nome.empty())
        {
            std::cout << "Dados lidos com sucesso" << std::endl;
            std::cout << "Nome: " << nome << "\nTelefone 1: " << fones[0] << "\nTelefone 2: " << fones[1] << std::endl;
        }
        else
        {
            std::cout << "Nome vazio. Dados nao atribuidos." << std::endl;
        }
    }

    void writeToFile(std::string fileName) 
    {
        if (nome.empty()) 
        {
            std::cout << "Nome vazio. Dados nao gravados" << std::endl;
            return;
        }

        std::ofstream file(fileName);

        if (!file) {
            std::cout << "Erro ao abrir o arquivo para escrita: " << fileName << std::endl;
            return;
        }

        file << nome << std::endl;
        file << fones[0] << std::endl;
        file << fones[1] << std::endl;

        file.close();

        std::cout << "Dados gravados com sucesso em " << fileName << std::endl;
    }

    int phones()
    {
        return quantidade;
    }
    
     void testPhones() const
    {
        std::cout << "Quantidade de telefones: " << quantidade << std::endl;
        for (int i = 0; i < quantidade; i++)
        {
            std::cout << "Telefone " << i + 1 << ": " << fones[i] << std::endl;
        }
    }

    void setPhone2a(std::string fone)
    {
        if (quantidade < 1)
        {
            std::cout << "Nenhum telefone cadastrado ainda. Adicione o primeiro telefone antes" << std::endl;
            return;
        }

        if (quantidade == 1)
        {
            char resposta;
            std::cout << "Deseja adicionar mais um telefone?: ";
            std::cin >> resposta;
            std::cin.ignore();

            if (resposta == 's' || resposta == 'S')
            {
                setFone(fone, 1);
                std::cout << "Segundo telefone adicionado com sucesso" << std::endl;
            }
            else
            {
                std::cout << "Segundo telefone nao foi adicionado" << std::endl;
            }
        }
        else
        {
            std::cout << "Este contato ja possui dois telefones" << std::endl;
        }
    }

    void testSetPhone2a()
    {
        std::string fone;
        std::cout << "Digite o segundo telefone: ";
        std::getline(std::cin, fone);
        setPhone2a(fone);

        std::cout << "Contato atual: " << toString() << std::endl;
    }

    void setPhone2b(std::string fone)
    {
        if (quantidade < 2)
        {
            std::cout << "Erro: O contato nao possui dois telefones registrados" << std::endl;
        }
        else
        {
            setFone(fone, 1);
            std::cout << "Segundo telefone alterado com sucesso" << std::endl;
        }
    }

    void testSetPhone2b()
    {
        std::string fone;
        std::cout << "Digite o novo valor para o segundo telefone: ";
        std::getline(std::cin, fone);
        setPhone2b(fone);

        std::cout << "Contato atualizado: " << toString() << std::endl;
    }

    void setPhone2c(std::string fone)
    {
        if (quantidade < 2)
        {
            std::cout << "Erro: O contato nao possui dois telefones para remover" << std::endl;
        }
        else
        {
            this->fones[1] = "";
            quantidade = 1; 
            std::cout << "Segundo telefone removido com sucesso" << std::endl;
        }
    }
    
    void testSetPhone2c()
    {
        std::cout << "Removendo o segundo telefone" << std::endl;
        setPhone2c("");
        std::cout << "Contato atualizado: " << toString() << std::endl;
    }


}; 

using ref_Contato = Contato*; 

#endif