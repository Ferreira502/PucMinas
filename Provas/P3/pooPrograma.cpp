#include <iostream>
using namespace std;

class Pessoa {
private:
    string nome;
    int idade;

public:
    Pessoa(string nome = "", int idade = 0) {
        // Usando 'this' para referenciar os atributos do objeto
        this->nome = nome;
        this->idade = idade;
    }

    void apresentar() const {
        cout << "Nome: " << nome << ", Idade: " << idade << endl;
    }

    void alterarNome(string novoNome) {
        this->nome = novoNome; // 'this' é útil para clareza (ou evitar conflitos com parâmetros)
    }

    void alterarIdade(int novaIdade) {
        this->idade = novaIdade;
    }
};

// Função que altera a pessoa via referência (não faz cópia!)
void modificarPessoaPorReferencia(Pessoa& p) {
    p.alterarNome("Nome Atualizado");
    p.alterarIdade(99);
}

// Função que altera a pessoa via ponteiro
void modificarPessoaPorPonteiro(Pessoa* p) {
    if (p != nullptr) {
        p->alterarNome("Nome por Ponteiro");
        p->alterarIdade(88);
    }
}

int main() {
    // Criando objeto estaticamente
    Pessoa p1("Gabriel", 21);
    cout << "Antes da modificação por referência:\n";
    p1.apresentar();

    modificarPessoaPorReferencia(p1); // Passagem por referência
    cout << "Depois da modificação por referência:\n";
    p1.apresentar();

    // Criando objeto dinamicamente (com ponteiro)
    Pessoa* p2 = new Pessoa("Joana", 25);
    cout << "\nAntes da modificação por ponteiro:\n";
    p2->apresentar();

    modificarPessoaPorPonteiro(p2); // Passagem por ponteiro
    cout << "Depois da modificação por ponteiro:\n";
    p2->apresentar();

    delete p2; // libera memória
    return 0;
}