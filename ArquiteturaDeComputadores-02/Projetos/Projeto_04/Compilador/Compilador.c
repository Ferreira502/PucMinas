#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "MyIO.h"

#define ARQUIVO_NOME "TESTEULA.ula"
#define ARQUIVO_HEX  "test.hex"

/**
 * @author Gabriel Nogueira
 *
 * @param arquivo_fp
 *
 * @reason  Funcao cria duas pilhas:
 *          Pilha A para ler os dados e armazená-los da maneira invertida ao processamento
 *          Pilha B para receber os dados da pilha A e armazená-los na ordem correta
 *
 * @return pilhaB (ordem correta, inicio->fim)
 */
Pilha* lerLinhas(FILE* arquivo_fp)
{
    Pilha* pilhaA = criarPilha();
    Pilha* pilhaB = criarPilha();
    int indiceLinha = 1;
    bool continuar = true;
    char linha[MAX_STRING_SIZE];
 
    // Remove a linha "inicio"
    fgets(linha, sizeof(linha), arquivo_fp);
 
    while (fgets(linha, sizeof(linha), arquivo_fp) != NULL && continuar)
    {
        indiceLinha++;
        linha[strcspn(linha, "\n")] = '\0';
 
        // Para ao encontrar "fim."
        if (strcmp(linha, "fim.") == 0)
        {
            continuar = false;
        }
 
        else
        {
            if (linhaValida(linha))
            {
                push(pilhaA, linha);
            }

            else
            {
                printErroLinha(linha, indiceLinha);
                continuar = false;
            }
        }   
    }
 
    // Transfere as linhas da pilha A para pilha B, armazenando na ordem correta
    while (!pilhaVazia(pilhaA) && !linhaValida(linha)) // ele vai transferindo enquanto a linha for valida e a pilha A nao estiver vazia
    {
        char* elemento = pop(pilhaA);
        push(pilhaB, elemento);
        free(elemento);
    }
    free(pilhaA);
 
    return pilhaB;
}
 
/**
 * @author Gabriel Ferreira
 *
 * @param pilhaResultado  pilhaB vinda do lerLinhas
 * @param arquivoHex      arquivo de saida
 *
 * @reason  Processa pilhaB diretamente
 *          Rastreia X e Y. Sempre que encontrar W, escreve XYW no hex.
 */
void gerarArquivoHex( Pilha* pilhaResultado, FILE* arquivoHex )
{
    // Registradores X e Y
    char X = ' ';
    char Y = ' ';
    char W = ' ';
 
    // pilhaB.topo
    while ( !pilhaVazia(pilhaResultado) )
    {
        char* elemento = pop(pilhaResultado);
 
        switch (elemento[0])
        {
            case 'X':
                X = trocarMne(elemento);
                break;
            case 'Y':
                Y = trocarMne(elemento);
                break;
            case 'W':
                W = trocarMne(elemento);
                // Converte W e escreve XYW no arquivo hex
                fprintf( arquivoHex, "%c%c%c\n", X, Y, trocarMne(elemento) );
                break;
        }
 
        free(elemento);
    }
}

int main(void)
{
    FILE* arquivo_fp = fopen(ARQUIVO_NOME, "r");

    if (arquivo_fp != NULL)
    {
        FILE* arquivoHex = fopen(ARQUIVO_HEX, "w");
        if (arquivoHex == NULL)
        {
            printf("Erro ao criar o arquivo %s\n", ARQUIVO_HEX);
            fclose(arquivo_fp);
            return 1;
        }
 
        Pilha* pilhaResultado = lerLinhas(arquivo_fp);
        fclose(arquivo_fp);
 
        gerarArquivoHex(pilhaResultado, arquivoHex);

 
        fclose(arquivoHex);
        free(pilhaResultado);
    }

    else
    {
        printf("Erro ao abrir o arquivo %s\n", ARQUIVO_NOME);
        return 1;
    }
    return 0;
}
