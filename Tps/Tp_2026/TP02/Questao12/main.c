#include <stdio.h>
#include "ColecaoRestaurante.h"

#define MAX 100

typedef struct
{
    Restaurante dados[MAX];
    int topo;
} Pilha;

void inicializar( Pilha *p )
{
    p->topo = -1;
}

int pilha_vazia( Pilha *p )
{
    return p->topo == -1;
}

int pilha_cheia( Pilha *p )
{
    return p->topo == MAX - 1;
}

void inserir( Pilha *p, Restaurante r )
{
    if ( !pilha_cheia(p) )
    {
        p->topo++;
        p->dados[p->topo] = r;
    }
}

Restaurante remover( Pilha *p )
{
    Restaurante r = p->dados[p->topo];
    p->topo--;
    return r;
}

void mostrar( Pilha *p )
{
    char saida_linha[500];
    for ( int i = p->topo; i >= 0; i-- )
    {
        formatar_restaurante(&p->dados[i], saida_linha);
        printf("%s\n", saida_linha);
    }
}

/**
 * @author Gabriel Ferreira Pereira
 * @reason Pilha com alocacao sequencial de registros de restaurante.
 *         Lê IDs para montar a colecao base, depois processa comandos
 *         I (inserir) e R (remover) operando sobre a pilha.
 */
int main()
{
    ColecaoRestaurante colecao = ler_csv();
    Restaurante *restaurantes = get_restaurantes(&colecao);
    Pilha pilha;
    inicializar(&pilha);

    char saida_linha[500];
    int id = 0;

    // leitura dos IDs para montar a pilha inicial
    while ( scanf("%d", &id) && id != -1 )
    {
        for ( int i = 0; i < get_tamanho(&colecao); i++ )
        {
            if ( restaurantes[i].id == id )
            {
                inserir(&pilha, restaurantes[i]);
            }
        }
    }

    // processamento dos comandos
    char opcao;

    while ( scanf(" %c", &opcao) == 1 )
    {
        if ( opcao == 'I' )
        {
            scanf("%d", &id);
            for ( int i = 0; i < get_tamanho(&colecao); i++ )
            {
                if ( restaurantes[i].id == id )
                {
                    inserir(&pilha, restaurantes[i]);
                }
            }
        }
        
        else if ( opcao == 'R' )
        {
            if ( !pilha_vazia(&pilha) )
            {
                Restaurante r = remover(&pilha);
                printf("(R)%s\n", r.nome);
            }
        }
    }

    mostrar(&pilha);

    return 0;
}