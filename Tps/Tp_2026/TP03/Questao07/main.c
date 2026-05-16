#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ColecaoRestaurante.h"

typedef struct Celula
{
    Restaurante elemento;
    struct Celula *prox;
} Celula;

/**
 * @author Gabriel Ferreira Pereira
 * @param restaurante
 * @reason Cria uma nova celula da lista flexivel
 * @return ponteiro para a nova celula
 */
Celula* nova_celula( Restaurante restaurante )
{
    Celula *nova = (Celula*) malloc(sizeof(Celula));
    nova->elemento = restaurante;
    nova->prox = NULL;
    return nova;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param restaurantes, tamanho, id
 * @reason Busca um restaurante pelo ID no vetor lido do CSV
 * @return restaurante encontrado
 */
Restaurante buscar_restaurante( Restaurante *restaurantes, int tamanho, int id )
{
    for ( int i = 0; i < tamanho; i++ )
    {
        if ( restaurantes[i].id == id )
        {
            return restaurantes[i];
        }
    }

    return restaurantes[0];
}

/**
 * @author Gabriel Ferreira Pereira
 * @param primeiro, ultimo
 * @reason Inicializa a lista flexivel com celula cabeca
 */
void start( Celula **primeiro, Celula **ultimo )
{
    Restaurante restaurante_vazio;
    memset(&restaurante_vazio, 0, sizeof(Restaurante));
    *primeiro = nova_celula(restaurante_vazio);
    *ultimo = *primeiro;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param primeiro, ultimo, restaurante
 * @reason Insere um restaurante no inicio da lista
 */
void inserir_inicio( Celula **primeiro, Celula **ultimo, Restaurante restaurante )
{
    Celula *tmp = nova_celula(restaurante);
    tmp->prox = (*primeiro)->prox;
    (*primeiro)->prox = tmp;

    if ( *primeiro == *ultimo )
    {
        *ultimo = tmp;
    }
}

/**
 * @author Gabriel Ferreira Pereira
 * @param ultimo, restaurante
 * @reason Insere um restaurante no fim da lista
 */
void inserir_fim( Celula **ultimo, Restaurante restaurante )
{
    (*ultimo)->prox = nova_celula(restaurante);
    *ultimo = (*ultimo)->prox;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param primeiro, ultimo
 * @reason Remove um restaurante do inicio da lista
 * @return restaurante removido
 */
Restaurante remover_inicio( Celula **primeiro, Celula **ultimo )
{
    Celula *tmp = (*primeiro)->prox;
    Restaurante resp = tmp->elemento;
    (*primeiro)->prox = tmp->prox;

    if ( tmp == *ultimo )
    {
        *ultimo = *primeiro;
    }

    free(tmp);
    return resp;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param primeiro, ultimo
 * @reason Remove um restaurante do fim da lista
 * @return restaurante removido
 */
Restaurante remover_fim( Celula **primeiro, Celula **ultimo )
{
    Celula *i;

    for ( i = *primeiro; i->prox != *ultimo; i = i->prox );

    Restaurante resp = (*ultimo)->elemento;
    free(*ultimo);
    *ultimo = i;
    (*ultimo)->prox = NULL;
    return resp;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param primeiro, ultimo
 * @reason Retorna a quantidade de elementos validos da lista
 * @return tamanho da lista
 */
int tamanho_lista( Celula *primeiro, Celula *ultimo )
{
    int tamanho = 0;

    for ( Celula *i = primeiro; i != ultimo; i = i->prox )
    {
        tamanho++;
    }

    return tamanho;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param primeiro, ultimo, restaurante, pos
 * @reason Insere um restaurante em uma posicao especifica da lista
 */
void inserir( Celula **primeiro, Celula **ultimo, Restaurante restaurante, int pos )
{
    int tam = tamanho_lista(*primeiro, *ultimo);

    if ( pos == 0 )
    {
        inserir_inicio(primeiro, ultimo, restaurante);
    }

    else if ( pos == tam )
    {
        inserir_fim(ultimo, restaurante);
    }

    else
    {
        Celula *i = *primeiro;

        for ( int j = 0; j < pos; j++, i = i->prox );

        Celula *tmp = nova_celula(restaurante);
        tmp->prox = i->prox;
        i->prox = tmp;
    }
}

/**
 * @author Gabriel Ferreira Pereira
 * @param primeiro, ultimo, pos
 * @reason Remove um restaurante de uma posicao especifica da lista
 * @return restaurante removido
 */
Restaurante remover( Celula **primeiro, Celula **ultimo, int pos )
{
    int tam = tamanho_lista(*primeiro, *ultimo);

    if ( pos == 0 )
    {
        return remover_inicio(primeiro, ultimo);
    }

    if ( pos == tam - 1 )
    {
        return remover_fim(primeiro, ultimo);
    }

    Celula *i = *primeiro;

    for ( int j = 0; j < pos; j++, i = i->prox );

    Celula *tmp = i->prox;
    Restaurante resp = tmp->elemento;
    i->prox = tmp->prox;
    free(tmp);
    return resp;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param primeiro
 * @reason Mostra os restaurantes da lista formatados
 */
void mostrar( Celula *primeiro )
{
    char saida_linha[500];

    for ( Celula *i = primeiro->prox; i != NULL; i = i->prox )
    {
        formatar_restaurante(&i->elemento, saida_linha);
        printf("%s\n", saida_linha);
    }
}

/**
 * @author Gabriel Ferreira Pereira
 * @reason Metodo principal que busca e formata o restaurante com o ID fornecido
 *         e executa os comandos sobre a lista flexivel
 */
int main()
{
    ColecaoRestaurante colecao = ler_csv();
    Restaurante *restaurantes = get_restaurantes(&colecao);
    Celula *primeiro;
    Celula *ultimo;
    int id = 0;
    int n = 0;
    char comando[3];

    start(&primeiro, &ultimo);

    while ( scanf("%d", &id) && id != -1 )
    {
        inserir_fim(&ultimo, buscar_restaurante(restaurantes, get_tamanho(&colecao), id));
    }

    scanf("%d", &n);

    for ( int i = 0; i < n; i++ )
    {
        scanf("%s", comando);

        if ( strcmp(comando, "II") == 0 )
        {
            scanf("%d", &id);
            inserir_inicio(&primeiro, &ultimo, buscar_restaurante(restaurantes, get_tamanho(&colecao), id));
        }

        else if ( strcmp(comando, "IF") == 0 )
        {
            scanf("%d", &id);
            inserir_fim(&ultimo, buscar_restaurante(restaurantes, get_tamanho(&colecao), id));
        }

        else if ( strcmp(comando, "I*") == 0 )
        {
            int pos = 0;
            scanf("%d %d", &pos, &id);
            inserir(&primeiro, &ultimo, buscar_restaurante(restaurantes, get_tamanho(&colecao), id), pos);
        }

        else if ( strcmp(comando, "RI") == 0 )
        {
            Restaurante removido = remover_inicio(&primeiro, &ultimo);
            printf("(R)%s\n", removido.nome);
        }

        else if ( strcmp(comando, "RF") == 0 )
        {
            Restaurante removido = remover_fim(&primeiro, &ultimo);
            printf("(R)%s\n", removido.nome);
        }

        else if ( strcmp(comando, "R*") == 0 )
        {
            int pos = 0;
            scanf("%d", &pos);
            Restaurante removido = remover(&primeiro, &ultimo, pos);
            printf("(R)%s\n", removido.nome);
        }
    }

    mostrar(primeiro);

    return 0;
}
