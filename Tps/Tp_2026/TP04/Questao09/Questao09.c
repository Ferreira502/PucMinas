#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Data
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Hora
{
    int hora;
    int minuto;
} Hora;

typedef struct Restaurante
{
    int id;
    char nome[100];
    char cidade[100];
    int capacidade;
    double avaliacao;
    char tipo1[50];
    char tipo2[50];
    char faixaPreco[10];
    Hora horario_abertura;
    Hora horario_fechamento;
    Data data_abertura;
    int aberto;
} Restaurante;

typedef struct Colecao_restaurante
{
    int tamanho;
    Restaurante restaurantes[500];
} Colecao_restaurante;

/**
 * @author Gabriel Ferreira Pereira
 * @param s String no formato YYYY-MM-DD
 * @reason Converte uma String para um objeto Data
 * @return objeto Data correspondente
 */
Data parse_data( char *s )
{
    Data data;
    sscanf(s, "%d-%d-%d", &data.ano, &data.mes, &data.dia);
    return data;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param data objeto Data
 * @param saida_linha para armazenar a data formatada
 * @reason Retorna a data no formato DD/MM/YYYY
 */
void formatar_data( Data *data, char *saida_linha )
{
    sprintf(saida_linha, "%02d/%02d/%04d", data->dia, data->mes, data->ano);
}

/**
 * @author Gabriel Ferreira Pereira
 * @param s String no formato hh:mm
 * @reason Converte uma String para um objeto Hora
 * @return objeto Hora correspondente
 */
Hora parse_hora( char *s )
{
    Hora hora;
    sscanf(s, "%d:%d", &hora.hora, &hora.minuto);
    return hora;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param hora objeto Hora
 * @param saida_linha para armazenar a hora formatada
 * @reason Retorna a hora no formato hh:mm
 */
void formatar_hora( Hora *hora, char *saida_linha )
{
    sprintf(saida_linha, "%02d:%02d", hora->hora, hora->minuto);
}

/**
 * @author Gabriel Ferreira Pereira
 * @param linha, pos, campo
 * @reason Le um campo da linha do CSV ate encontrar virgula ou fim de linha
 * @return nova posicao na linha apos o campo lido
 */
int ler_campo( char *linha, int pos, char *campo )
{
    int i = 0;
    
    while ( linha[pos] != ',' && linha[pos] != '\0' && linha[pos] != '\n' )
    {
        campo[i] = linha[pos];
        i++;
        pos++;
    }

    campo[i] = '\0';
    pos++;

    return pos;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param linha String da linha do CSV
 * @reason Le uma linha do CSV e cria um objeto Restaurante
 * @return Restaurante criado
 */
Restaurante ler_restaurante( char *linha )
{
    Restaurante r;
    char campo[100];
    char horario_abertura[10];
    char horario_fechamento[10];
    char data_str[20];
    char aberto_str[10];
    char cozinha[100];
    int pos = 0;
    int j = 0, k = 0;

    // id
    pos = ler_campo(linha, pos, campo);
    sscanf(campo, "%d", &r.id);

    // nome
    pos = ler_campo(linha, pos, r.nome);

    // cidade
    pos = ler_campo(linha, pos, r.cidade);

    // capacidade
    pos = ler_campo(linha, pos, campo);
    sscanf(campo, "%d", &r.capacidade);

    // avaliacao
    pos = ler_campo(linha, pos, campo);
    sscanf(campo, "%lf", &r.avaliacao);

    // cozinha
    pos = ler_campo(linha, pos, cozinha);

    while ( cozinha[j] != ';' )
    {
        r.tipo1[k++] = cozinha[j++];
    }

    r.tipo1[k] = '\0';
    j++; k = 0;
    
    while ( cozinha[j] != '\0' )
    {
        r.tipo2[k++] = cozinha[j++];
    }
    r.tipo2[k] = '\0';

    // faixa preco
    pos = ler_campo(linha, pos, r.faixaPreco);

    // horario
    pos = ler_campo(linha, pos, campo);
    j = 0; k = 0;

    while ( campo[j] != '-' )
    {
        horario_abertura[k++] = campo[j++];
    }

    horario_abertura[k] = '\0';
    j++; k = 0;

    while ( campo[j] != '\0' )
    {
        horario_fechamento[k++] = campo[j++];
    }

    horario_fechamento[k] = '\0';
    r.horario_abertura = parse_hora(horario_abertura);
    r.horario_fechamento = parse_hora(horario_fechamento);

    // data
    pos = ler_campo(linha, pos, data_str);
    r.data_abertura = parse_data(data_str);

    // aberto
    pos = ler_campo(linha, pos, aberto_str);

    if ( aberto_str[0] == 't' )
    {
        r.aberto = 1;
    }

    else
    {
        r.aberto = 0;
    }

    return r;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param r, saida_linha
 * @reason Retorna o restaurante formatado como String
 */
void formatar_restaurante( Restaurante *r, char *saida_linha )
{
    char data_str[20];
    char horario_abertura[10];
    char horario_fechamento[10];
    char aberto_str[10];

    formatar_data(&r->data_abertura, data_str);
    formatar_hora(&r->horario_abertura, horario_abertura);
    formatar_hora(&r->horario_fechamento, horario_fechamento);

    if ( r->aberto == 1 )
    {
        sprintf(aberto_str, "true");
    }

    else
    {
        sprintf(aberto_str, "false");
    }

    sprintf(saida_linha, "[%d ## %s ## %s ## %d ## %.1f ## [%s,%s] ## %s ## %s-%s ## %s ## %s]",
        r->id, r->nome, r->cidade, r->capacidade, r->avaliacao,
        r->tipo1, r->tipo2, r->faixaPreco,
        horario_abertura, horario_fechamento,
        data_str, aberto_str);
}

/**
 * @author Gabriel Ferreira Pereira
 * @param colecao objeto Colecao_restaurante
 * @reason Retorna a quantidade de restaurantes da colecao
 * @return tamanho da colecao
 */
int get_tamanho( Colecao_restaurante *colecao )
{
    return colecao->tamanho;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param colecao, r
 * @reason Adiciona um restaurante na colecao
 */
void adicionar( Colecao_restaurante *colecao, Restaurante r )
{
    colecao->restaurantes[colecao->tamanho] = r;
    colecao->tamanho++;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param colecao objeto Colecao_restaurante
 * @reason Retorna o array de restaurantes da colecao
 * @return ponteiro para o array de restaurantes
 */
Restaurante* get_restaurantes( Colecao_restaurante *colecao )
{
    return colecao->restaurantes;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param colecao objeto Colecao_restaurante
 * @reason Imprime todos os restaurantes da colecao formatados
 */
void imprimir( Colecao_restaurante *colecao )
{
    char saida_linha[500];
    for ( int i = 0; i < colecao->tamanho; i++ )
    {
        formatar_restaurante(&colecao->restaurantes[i], saida_linha);
        printf("%s\n", saida_linha);
    }
}

/**
 * @author Gabriel Ferreira Pereira
 * @reason Le o dataset do arquivo CSV e retorna a colecao de restaurantes
 * @return colecao de restaurantes
 */
Colecao_restaurante ler_csv()
{
    Colecao_restaurante colecao;
    colecao.tamanho = 0;

    FILE *f = fopen("/tmp/restaurantes.csv", "r");

    char linha[500];

    if ( f == NULL )
    {
        return colecao;
    }
 
    if ( fgets(linha, 500, f) == NULL )
    {
        fclose(f);
        return colecao;
    }

    for ( int i = 0; i < 500 && fgets(linha, 500, f) != NULL; i++ )
    {
        int j = 0;

        while ( linha[j] != '\n' && linha[j] != '\r' && linha[j] != '\0' )
        {
            j++;
        }
        
        linha[j] = '\0';


        Restaurante r = ler_restaurante(linha);
        adicionar(&colecao, r);
    }

    fclose(f);
    return colecao;
}

typedef struct No
{
    char letra;
    Restaurante elemento;
    struct Celula *primeiro;
    struct Celula *ultimo;
    int folha;
} No;

typedef struct Celula
{
    No *elemento;
    struct Celula *prox;
} Celula;

typedef struct Arvore_trie
{
    No *raiz;
    int comparacoes;
} Arvore_trie;

Celula* nova_celula( No *elemento )
{
    Celula *nova = (Celula*) malloc(sizeof(Celula));
    nova->elemento = elemento;
    nova->prox = NULL;

    return nova;
}

No* novo_no( char letra )
{
    No *no = (No*) malloc(sizeof(No));
    no->letra = letra;
    no->folha = 0;
    no->primeiro = nova_celula(NULL);
    no->ultimo = no->primeiro;

    return no;
}

void iniciar_arvore( Arvore_trie *arvore )
{
    arvore->raiz = novo_no(' ');
    arvore->comparacoes = 0;
}

No* get_filho( No *no, char c )
{
    No *filho = NULL;
    Celula *i;

    for ( i = no->primeiro->prox; i != NULL && filho == NULL; i = i->prox )
    {
        if ( i->elemento->letra == c )
        {
            filho = i->elemento;
        }
    }

    return filho;
}

void set_filho( No *no, No *filho )
{
    no->ultimo->prox = nova_celula(filho);
    no->ultimo = no->ultimo->prox;
}


void inserir_rec( Restaurante restaurante, char nome[], No *i, int j )
{
    char c = nome[j];
    No *filho = get_filho(i, c);

    if ( filho == NULL )
    {
        filho = novo_no(c);
        set_filho(i, filho);

        if ( j == (int)strlen(nome) - 1 )
        {
            filho->folha = 1;
            filho->elemento = restaurante;
        }

        else
        {
            inserir_rec(restaurante, nome, filho, j + 1);
        }
    }

    else if ( j < (int)strlen(nome) - 1 )
    {
        inserir_rec(restaurante, nome, filho, j + 1);
    }

    else if ( filho->folha == 0 )
    {
        filho->folha = 1;
        filho->elemento = restaurante;
    }
}

void inserir_arvore( Arvore_trie *arvore, Restaurante restaurante )
{
    inserir_rec(restaurante, restaurante.nome, arvore->raiz, 0);
}

Restaurante* pesquisar_rec( Arvore_trie *arvore, char nome[], No *no, int j )
{
    Restaurante *resp = NULL;
    char c = nome[j];
    No *filho = get_filho(no, c);
    arvore->comparacoes++;

    if ( filho == NULL )
    {
        resp = NULL;
    }

    else
    {
        printf("%c ", c);

        if ( j == (int)strlen(nome) - 1 )
        {
            if ( filho->folha == 1 )
            {
                resp = &filho->elemento;
            }
        }

        else
        {
            resp = pesquisar_rec(arvore, nome, filho, j + 1);
        }
    }

    return resp;
}

void pesquisar_arvore( Arvore_trie *arvore, char nome[] )
{
    char saida_linha[500];
    Restaurante *resp = pesquisar_rec(arvore, nome, arvore->raiz, 0);

    if ( resp == NULL )
    {
        printf("NAO\n");
    }

    else
    {
        formatar_restaurante(resp, saida_linha);
        printf("SIM %s\n", saida_linha);
    }
}

void mostrar_rec( char s[], No *no )
{
    char nova[500];
    strcpy(nova, s);
    int tam = strlen(nova);
    nova[tam] = no->letra;
    nova[tam + 1] = '\0';

    if ( no->folha == 1 )
    {
        char saida_linha[500];
        formatar_restaurante(&no->elemento, saida_linha);
        printf("%s %s\n", nova, saida_linha);
    }

    Celula *i;

    for ( i = no->primeiro->prox; i != NULL; i = i->prox )
    {
        mostrar_rec(nova, i->elemento);
    }
}

void mostrar( Arvore_trie *arvore )
{
    Celula *i;

    for ( i = arvore->raiz->primeiro->prox; i != NULL; i = i->prox )
    {
        mostrar_rec("", i->elemento);
    }
}

/**
 * @author Gabriel Ferreira Pereira
 * @reason Metodo principal que busca e formata o restaurante com o ID fornecido
 *         e exibe na tela a lista de restaurantes selecionados
 */

int main()
{
    Colecao_restaurante colecao = ler_csv();
    Restaurante *restaurantes = get_restaurantes(&colecao);
    Restaurante *encontrado;
    char saida_linha[500];
    Arvore_trie arvore;
    int id = 0;

    iniciar_arvore(&arvore);

    while ( scanf("%d", &id) && id != -1 )
    {
        for ( int i = 0; i < get_tamanho(&colecao); i++ )
        {
            if ( restaurantes[i].id == id )
            {
                inserir_arvore(&arvore, restaurantes[i]);
                i = get_tamanho(&colecao);
            }
        }
    }

    char nome[100];
    fgets(nome, 100, stdin);

    clock_t inicio = clock();

    while ( fgets(nome, 100, stdin) != NULL )
    {
        int j = 0;

        while ( nome[j] != '\n' && nome[j] != '\r' && nome[j] != '\0' )
        {
            j++;
        }

        nome[j] = '\0';

        if ( strcmp(nome, "FIM") == 0 )
        {
            break;
        }

        else
        {
            encontrado = pesquisar_rec(&arvore, nome, arvore.raiz, 0);

            if ( encontrado == NULL )
            {
                printf("NAO\n");
            }
            else
            {
                formatar_restaurante(encontrado, saida_linha);
                printf("SIM %s\n", saida_linha);
            }
        }
    }

    clock_t fim = clock();
    double total = (double) (fim - inicio) / CLOCKS_PER_SEC;

    FILE *log = fopen("842527_arvore_trie_lista.txt", "w");

    fprintf(log, "Comparacoes: %d\n", arvore.comparacoes);
    fprintf(log, "Total: %f\n", total);
    fclose(log);   
}