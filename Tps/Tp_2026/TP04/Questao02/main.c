#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ColecaoRestaurante.h"

typedef struct No
{
    Restaurante elemento;
    bool cor;
    struct No *esq, *dir;
} No;

typedef struct ArvoreBicolor
{
    No *raiz;
} ArvoreBicolor;

int comparar_nomes( char *a, char *b )
{
    int i = 0;

    while ( a[i] != '\0' && b[i] != '\0' )
    {
        if ( a[i] > b[i] )
        {
            return 1;
        }
        else if ( a[i] < b[i] )
        {
            return -1;
        }

        i++;
    }

    if ( a[i] == '\0' && b[i] == '\0' )
    {
        return 0;
    }
    else if ( a[i] == '\0' )
    {
        return -1;
    }

    return 1;
}

int is_fim( char *nome )
{
    return nome[0] == 'F' && nome[1] == 'I' && nome[2] == 'M' && nome[3] == '\0';
}

No* novo_no( Restaurante elemento )
{
    No *novo = (No*) malloc(sizeof(No));
    novo->elemento = elemento;
    novo->cor = true;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

bool is_no_tipo_quatro( No *i )
{
    return i != NULL && i->esq != NULL && i->dir != NULL &&
           i->esq->cor == true && i->dir->cor == true;
}

void fragmentar( ArvoreBicolor *arvore, No *i )
{
    if ( i == arvore->raiz )
    {
        i->cor = false;
        i->esq->cor = false;
        i->dir->cor = false;
    }
    else
    {
        i->cor = true;
        i->esq->cor = false;
        i->dir->cor = false;
    }
}

No* rotacionar_simples_esq( No *i )
{
    No *no_dir = i->dir;
    No *no_dir_esq = no_dir->esq;
    no_dir->esq = i;
    i->dir = no_dir_esq;
    return no_dir;
}

No* rotacionar_simples_dir( No *i )
{
    No *no_esq = i->esq;
    No *no_esq_dir = no_esq->dir;
    no_esq->dir = i;
    i->esq = no_esq_dir;
    return no_esq;
}

No* rotacionar_dir_esq( No *i )
{
    i->dir = rotacionar_simples_dir(i->dir);
    return rotacionar_simples_esq(i);
}

No* rotacionar_esq_dir( No *i )
{
    i->esq = rotacionar_simples_esq(i->esq);
    return rotacionar_simples_dir(i);
}

void balancear( ArvoreBicolor *arvore, No *bisavo, No *avo, No *pai, No *i )
{
    No *nova_raiz = NULL;

    if ( comparar_nomes(pai->elemento.nome, avo->elemento.nome) > 0 &&
         comparar_nomes(i->elemento.nome, pai->elemento.nome) > 0 )
    {
        nova_raiz = rotacionar_simples_esq(avo);
    }
    else if ( comparar_nomes(pai->elemento.nome, avo->elemento.nome) > 0 &&
              comparar_nomes(i->elemento.nome, pai->elemento.nome) < 0 )
    {
        nova_raiz = rotacionar_dir_esq(avo);
    }
    else if ( comparar_nomes(pai->elemento.nome, avo->elemento.nome) < 0 &&
              comparar_nomes(i->elemento.nome, pai->elemento.nome) < 0 )
    {
        nova_raiz = rotacionar_simples_dir(avo);
    }
    else if ( comparar_nomes(pai->elemento.nome, avo->elemento.nome) < 0 &&
              comparar_nomes(i->elemento.nome, pai->elemento.nome) > 0 )
    {
        nova_raiz = rotacionar_esq_dir(avo);
    }

    if ( bisavo != NULL )
    {
        if ( comparar_nomes(bisavo->elemento.nome, nova_raiz->elemento.nome) > 0 )
        {
            bisavo->esq = nova_raiz;
        }
        else
        {
            bisavo->dir = nova_raiz;
        }
    }
    else
    {
        arvore->raiz = nova_raiz;
    }

    nova_raiz->cor = false;
    nova_raiz->esq->cor = true;
    nova_raiz->dir->cor = true;
}

void inserir_rec( ArvoreBicolor *arvore, Restaurante restaurante,
    No *bisavo, No *avo, No *pai, No *i )
{
    if ( i == NULL )
    {
        i = novo_no(restaurante);

        if ( comparar_nomes(restaurante.nome, pai->elemento.nome) < 0 )
        {
            pai->esq = i;
        }
        else
        {
            pai->dir = i;
        }

        if ( pai->cor == true )
        {
            balancear(arvore, bisavo, avo, pai, i);
        }
    }
    else
    {
        if ( is_no_tipo_quatro(i) )
        {
            fragmentar(arvore, i);

            if ( pai != NULL && pai->cor == true )
            {
                balancear(arvore, bisavo, avo, pai, i);
            }
        }

        if ( comparar_nomes(restaurante.nome, i->elemento.nome) > 0 )
        {
            inserir_rec(arvore, restaurante, avo, pai, i, i->dir);
        }
        else if ( comparar_nomes(restaurante.nome, i->elemento.nome) < 0 )
        {
            inserir_rec(arvore, restaurante, avo, pai, i, i->esq);
        }
    }
}

void inserir( ArvoreBicolor *arvore, Restaurante restaurante )
{
    if ( arvore->raiz == NULL )
    {
        arvore->raiz = novo_no(restaurante);
        arvore->raiz->cor = false;
    }
    else
    {
        inserir_rec(arvore, restaurante, NULL, NULL, NULL, arvore->raiz);
        arvore->raiz->cor = false;
    }
}

void pesquisar_rec( No *i, char *nome, int raiz )
{
    if ( i == NULL )
    {
        printf(" NAO\n");
    }
    else
    {
        if ( raiz )
        {
            printf("raiz");
        }

        if ( comparar_nomes(nome, i->elemento.nome) == 0 )
        {
            printf(" SIM\n");
        }
        else if ( comparar_nomes(nome, i->elemento.nome) > 0 )
        {
            printf(" dir");
            pesquisar_rec(i->dir, nome, 0);
        }
        else
        {
            printf(" esq");
            pesquisar_rec(i->esq, nome, 0);
        }
    }
}

void pesquisar( ArvoreBicolor *arvore, char *nome )
{
    pesquisar_rec(arvore->raiz, nome, 1);
}

void caminhar_em_rec( No *i )
{
    if ( i != NULL )
    {
        char saida_linha[500];
        caminhar_em_rec(i->esq);
        formatar_restaurante(&i->elemento, saida_linha);
        printf("%s\n", saida_linha);
        caminhar_em_rec(i->dir);
    }
}

void caminhar_em( ArvoreBicolor *arvore )
{
    if ( arvore->raiz == NULL )
    {
        printf("V\n");
    }
    else
    {
        caminhar_em_rec(arvore->raiz);
    }
}

/**
 * @author Gabriel Ferreira Pereira
 * @reason Insere restaurantes em arvore bicolor por nome,
 *         pesquisa chaves e exibe caminhamento em ordem
 */
int main()
{
    ColecaoRestaurante colecao = ler_csv();
    Restaurante *restaurantes = get_restaurantes(&colecao);
    ArvoreBicolor arvore;
    arvore.raiz = NULL;
    int id = 0;
    char nome[100];

    while ( scanf("%d", &id) && id != -1 )
    {
        for ( int i = 0; i < get_tamanho(&colecao); i++ )
        {
            if ( restaurantes[i].id == id )
            {
                inserir(&arvore, restaurantes[i]);
                i = get_tamanho(&colecao);
            }
        }
    }

    fgets(nome, 100, stdin);
    while ( fgets(nome, 100, stdin) != NULL )
    {
        int j = 0;

        while ( nome[j] != '\n' && nome[j] != '\r' && nome[j] != '\0' )
        {
            j++;
        }

        nome[j] = '\0';

        if ( is_fim(nome) == 0 )
        {
            pesquisar(&arvore, nome);
        }
    }

    caminhar_em(&arvore);

    FILE *log = fopen("842527_arvore_bicolor.txt", "w");
    fclose(log);

    return 0;
}
