#include <stdio.h>
#include <time.h>
#include "ColecaoRestaurante.h"

#define TAM_TAB 31
#define TAM_RESERVA 19
#define TAM_TOTAL (TAM_TAB + TAM_RESERVA)

typedef struct Hash
{
    Restaurante tabela[TAM_TOTAL];
    int ocupado[TAM_TOTAL];
    int reserva_usada;
    int comparacoes;
} Hash;

/**
 * @author Gabriel Ferreira Pereira
 * @param hash tabela hash
 * @reason Inicializa a tabela hash e zera contadores
 */
void iniciar_hash( Hash *hash )
{
    int i;

    hash->reserva_usada = 0;
    hash->comparacoes = 0;

    for ( i = 0; i < TAM_TOTAL; i++ )
    {
        hash->ocupado[i] = 0;
    }
}

/**
 * @author Gabriel Ferreira Pereira
 * @param nome nome do restaurante
 * @reason Aplica a funcao de transformacao somando os ASCII do nome
 * @return posicao da area principal da hash
 */
int hash_nome( char nome[] )
{
    int soma = 0;
    int i = 0;

    while ( nome[i] != '\0' )
    {
        soma += (unsigned char) nome[i];
        i++;
    }

    return soma % TAM_TAB;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param hash, nome1, nome2
 * @reason Compara dois nomes caractere por caractere contando comparacoes
 * @return 1 se os nomes forem iguais, 0 caso contrario
 */
int nomes_iguais( Hash *hash, char nome1[], char nome2[] )
{
    int i = 0;

    hash->comparacoes++;

    while ( nome1[i] != '\0' && nome2[i] != '\0' )
    {
        if ( nome1[i] != nome2[i] )
        {
            return 0;
        }

        i++;
    }

    return nome1[i] == '\0' && nome2[i] == '\0';
}

/**
 * @author Gabriel Ferreira Pereira
 * @param hash, restaurante
 * @reason Insere restaurante na hash ou na area de reserva
 */
void inserir_hash( Hash *hash, Restaurante restaurante )
{
    int pos = hash_nome(restaurante.nome);

    if ( hash->ocupado[pos] == 0 )
    {
        hash->tabela[pos] = restaurante;
        hash->ocupado[pos] = 1;
    }

    else if ( hash->reserva_usada < TAM_RESERVA )
    {
        int pos_reserva = TAM_TAB + hash->reserva_usada;
        hash->tabela[pos_reserva] = restaurante;
        hash->ocupado[pos_reserva] = 1;
        hash->reserva_usada++;
    }

    else
    {
        printf("%s\n", restaurante.nome);
    }
}

/**
 * @author Gabriel Ferreira Pereira
 * @param hash, nome, encontrado
 * @reason Pesquisa um restaurante na tabela hash e retorna sua posicao
 * @return posicao de 0 a 49 ou -1 caso nao encontre
 */
int pesquisar_hash( Hash *hash, char nome[], Restaurante *encontrado )
{
    int pos = hash_nome(nome);
    int i;

    if ( hash->ocupado[pos] == 1 && nomes_iguais(hash, hash->tabela[pos].nome, nome) )
    {
        *encontrado = hash->tabela[pos];
        return pos;
    }

    for ( i = 0; i < hash->reserva_usada; i++ )
    {
        int pos_reserva = TAM_TAB + i;

        if ( hash->ocupado[pos_reserva] == 1 &&
             nomes_iguais(hash, hash->tabela[pos_reserva].nome, nome) )
        {
            *encontrado = hash->tabela[pos_reserva];
            return pos_reserva;
        }
    }

    return -1;
}

/**
 * @author Gabriel Ferreira Pereira
 * @reason Metodo principal que insere restaurantes por ID na hash,
 *         pesquisa nomes e salva o arquivo de log
 */
int main()
{
    ColecaoRestaurante colecao = ler_csv();
    Restaurante *restaurantes = get_restaurantes(&colecao);
    Hash hash;
    Restaurante encontrado;
    char nome[100];
    char saida_linha[500];
    int id = 0;
    clock_t inicio, fim;
    double total = 0.0;

    iniciar_hash(&hash);

    while ( scanf("%d", &id) && id != -1 )
    {
        int inserido = 0;

        for ( int i = 0; i < get_tamanho(&colecao); i++ )
        {
            if ( inserido == 0 && restaurantes[i].id == id )
            {
                inserir_hash(&hash, restaurantes[i]);
                inserido = 1;
            }
        }
    }

    fgets(nome, 100, stdin);

    inicio = clock();

    while ( fgets(nome, 100, stdin) != NULL )
    {
        int j = 0;
        int pos = -1;

        while ( nome[j] != '\n' && nome[j] != '\0' )
        {
            j++;
        }
        nome[j] = '\0';

        if ( nome[0] != 'F' || nome[1] != 'I' || nome[2] != 'M' || nome[3] != '\0' )
        {
            pos = pesquisar_hash(&hash, nome, &encontrado);

            if ( pos == -1 )
            {
                printf("-1\n");
            }

            else
            {
                formatar_restaurante(&encontrado, saida_linha);
                printf("%d %s\n", pos, saida_linha);
            }
        }
    }

    fim = clock();
    total = ((fim - inicio) / (double) CLOCKS_PER_SEC);

    FILE *log = fopen("842527_hash_reserva.txt", "w");

    if ( log != NULL )
    {
        fprintf(log, "842527\t%d\t%f\n", hash.comparacoes, total);
        fclose(log);
    }

    return 0;
}
