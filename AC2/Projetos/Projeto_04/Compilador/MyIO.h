#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STRING_SIZE 64

typedef struct Pilha
{
    struct Celula* topo;
} Pilha;

typedef struct Celula
{
    char* string;
    struct Celula* proximo;
} Celula;

bool pilhaVazia(Pilha* pilha);

/**
 * @author Gabriel Nogueira
 * @reason Mostra os elementos da pilha
 * @param Pilha
 * @return void
 */

void imprimirPilha(Pilha* pilha)
{
    Celula* atual = pilha->topo;
    while (atual != NULL)
    {
        printf("%s", atual->string);
        atual = atual->proximo;
    }
}

/**
 * @author Gabriel Nogueira
 * @param frase
 * @reason Mostrar uma frase
 * @return void
 */
void print(const char* frase)
{
    printf("%s", frase);
}

/**
 * @author Gabriel Nogueira
 * @param frase
 * @reason Mostrar uma frase com quebra de linha no final
 * @return void
 */
void println(const char* frase)
{
    printf("%s\n", frase);
}

/**
 * @author Gabriel Nogueira
 * @reason Mostra a frase com o erro de leitura
 * @param frase
 * @param indiceLinha
 * @return void
 */
void printErroLinha(const char* frase, int indiceLinha)
{
    printf("Erro na leitura da linha %d\nEntrada: '%s'\n", indiceLinha, frase);
}

/**
 * @author Gabriel Ferreira
 * @reason Troca a palavra mnemonica pelo valor hexadecimal correspondente
 * @param palavra
 * @ return caracter correspondente
 */
char trocarMne ( char palavra[] )
{
    char x = ' ';
    char y = ' ';
    char z = ' ';
    int valor = 0;
 
    if ( palavra[1] == '=' )
    {
        /* 1 */
        if ( palavra[2] == 'C' && palavra[7] == 'B' ) // CopiaB
            x = '1';
 
        /* 2 */
        if ( palavra[2] == 'C' && palavra[7] == 'A' ) // CopiaA
            x = '0';
        
        /* 3 */
        if ( palavra[2] == 'A' && palavra[3] == 'x' && palavra[4] == 'B' ) // AxB
            x = '2';

        /* 4 */
        if ( palavra[2] == 'n' && palavra[3] == 'A' && palavra[4] == 'x' && palavra[5] == 'n' && palavra[6] == 'B' ) // nAxnB
            x = '3';

        /* 5 */
        if ( palavra[2] == 'A' && palavra[3] == 'e' && palavra[4] == 'B' && palavra[5] == 'n' ) // AeBn
            x = '4';

        /* 6 */
        if ( palavra[2] == 'n' && palavra[3] == 'B' ) // nB
            x = '5';
 
        /* 7 */
        if ( palavra[2] == 'n' && palavra[3] == 'A' && palavra[4] == 'o' && palavra[5] == 'n' && palavra[6] == 'B' ) // nAonB
            x = '6';

        /* 8 */
        if ( palavra[2] == 'n' && palavra[3] == 'A') // nA
            x = '7';

        /* 9 */
        if ( palavra[2] == 'A' && palavra[3] == 'o' && palavra[4] == 'n' && palavra[5] == 'B' ) // AonB
            x = '8';

        /* 10 */
        if ( palavra[2] == 'U' && palavra[3] == 'm' && palavra[4] == 'L' ) // UmL
            x = '9';

        /* 11 */
        if ( palavra[2] == 'Z' && palavra[3] == 'e' && palavra[4] == 'r' && palavra[5] == 'o' && palavra[6] == 'L' ) // ZeroL
            x = 'A';
 
        /* 12 */
        if ( palavra[2] == 'A' && palavra[3] == 'e' && palavra[4] == 'B' && palavra[5] != 'n') // AeB
            x = 'B';

        /* 13 */
        if ( palavra[2] == 'n' && palavra[3] == 'A' && palavra[4] == 'e' && palavra[5] == 'B' ) // nAeB
            x = 'C';

        /* 14 */
        if ( palavra[2] == 'A' && palavra[3] == 'e' && palavra[4] == 'n' && palavra[5] == 'B' ) // AenB
            x = 'D';

        /* 15 */
        if ( palavra[2] == 'A' && palavra[3] == 'o' && palavra[4] == 'B' ) // AoB
            x = 'E';

        /* 16 */
        if ( palavra[2] == 'n' && palavra[3] == 'A' && palavra[4] == 'e' && palavra[5] == 'n' && palavra[6] == 'B' ) // nAenB
            x = 'F';
 
        /* valor direto*/
        // Entra aqui se nenhum mnemonico foi reconhecido antes e o valor tem so 1 caractere ex: X=B; ou X=5;
        if ( x == ' ' && (palavra[3] == ';' || palavra[3] == '\0') )
        {
            y = palavra[2]; // Pega o unico digito posicao 2 da string, ex: X=B; -> y='B'

            // Verifica se e um caractere hexadecimal valido: 0-9 ou A-F
            if ( (y >= '0' && y <= '9') || (y >= 'A' && y <= 'F') )
            {
                x = y; // Valor valido retorna ele direto (ex: 'B', '5', 'A')
            }
        }

        /*
            valor direto hexa 2 digitos
            Entra aqui se nenhum mnemonico foi reconhecido E o valor tem 2 caracteres ex: X=11; ou X=15;
        */

        if ( x == ' ' && palavra[3] != ';' && palavra[4] == ';' )
        {
            y = palavra[2]; // Pega o primeiro digito ex: X=11; -> y='1'
            z = palavra[3]; // Pega o segundo digito ex: X=11; -> z='1'

            if ( y >= '0' && y <= '9' && z >= '0' && z <= '9' )
            {
                /*
                    Converte os dois chars para inteiro
                    Truque ASCII: '1' - '0' = 49 - 48 = 1
                    Ex: y='1', z='1' -> valor = 1*10 + 1 = 11
                */
                valor = ( y - '0' ) * 10 + ( z - '0' ); 

                /*
                    So converte se estiver na faixa 10-15 (equivalente hex A-F)
                    Valores fora disso (ex: 99) sao ignorados e x continua ' '
                */
                if ( valor >= 10 && valor <= 15 )
                {
                    x = 'A' + (valor - 10); // Acrescentando o valor para retornar o seu valor em Hexadecimal
                }
            }
            
        }
        
    }

    return x;
}

/**
 * @author Gabriel Nogueira
 * @reason Verificar se a linha é vazia ou possui ';' no final
 * @param linha string a verificar
 * @return true se vazia ou termina com ';', false caso contrário
*/
bool linhaValida(const char* linha)
{
    int length = strlen(linha);
    bool valido = true;

    // Desconta \n do final para nao interferir na verificacao do ';'
    while (length > 0 && (linha[length - 1] == '\n'))
    {
        length--;
    }

    if(linha != NULL)
    {
        if(linha[length - 1] != ';')
        {
            valido = 0; // se aparecer linha como x=2 sem ; vai aparecer erro
        }
        else
        {
            valido = 1;
        }

        for (int i = 0; i < length - 1 ; i++)
        {
            if (linha[i] == '=' && linha[i + 1] == ';') // se aparecer x=; ele mostra erro
            {
                valido = 0;
            }
        }
    }
    return valido;
}

/**
 * @author Gabriel Nogueira
 * @reason Criar uma pilha vazia
 * @return pilha criada
*/
Pilha* criarPilha(void)
{
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

/**
 * @author Gabriel Nogueira
 * @reason Fazer push de um elemento na pilha
 * @param pilha pilha onde inserir
 * @param str string a inserir
 * @return void
*/
void push(Pilha* pilha, const char* str)
{
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova->string = strdup(str);
    nova->proximo = pilha->topo;
    pilha->topo = nova;
}

/**
 * @author Gabriel Nogueira
 * @reason Fazer pop de um elemento da pilha
 * @param pilha pilha onde remover
 * @return string removida da pilha
*/
char* pop(Pilha* pilha)
{
    if (pilhaVazia(pilha))
    {
        return NULL;
    }
    else
    {
        Celula* temp = pilha->topo;
        char* str = temp->string;
        pilha->topo = temp->proximo;
        free(temp);
        return str;
    }
}

/**
 * @author Gabriel Nogueira
 * @reason Verificar se a pilha está vazia
 * @param pilha pilha a verificar
 * @return true se vazia, false caso contrário
*/
bool pilhaVazia(Pilha* pilha)
{
    return pilha->topo == NULL;
}