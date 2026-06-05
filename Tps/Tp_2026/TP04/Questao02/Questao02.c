#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

    if ( linha[pos] != '\0' )
    {
        pos++;
    }

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

    pos = ler_campo(linha, pos, campo);
    sscanf(campo, "%d", &r.id);

    pos = ler_campo(linha, pos, r.nome);
    pos = ler_campo(linha, pos, r.cidade);

    pos = ler_campo(linha, pos, campo);
    sscanf(campo, "%d", &r.capacidade);

    pos = ler_campo(linha, pos, campo);
    sscanf(campo, "%lf", &r.avaliacao);

    pos = ler_campo(linha, pos, cozinha);

    while ( cozinha[j] != ';' )
    {
        r.tipo1[k++] = cozinha[j++];
    }

    r.tipo1[k] = '\0';
    j++;
    k = 0;
    
    while ( cozinha[j] != '\0' )
    {
        r.tipo2[k++] = cozinha[j++];
    }

    r.tipo2[k] = '\0';

    pos = ler_campo(linha, pos, r.faixaPreco);
    pos = ler_campo(linha, pos, campo);
    j = 0;
    k = 0;

    while ( campo[j] != '-' )
    {
        horario_abertura[k++] = campo[j++];
    }

    horario_abertura[k] = '\0';
    j++;
    k = 0;

    while ( campo[j] != '\0' )
    {
        horario_fechamento[k++] = campo[j++];
    }

    horario_fechamento[k] = '\0';
    r.horario_abertura = parse_hora(horario_abertura);
    r.horario_fechamento = parse_hora(horario_fechamento);

    pos = ler_campo(linha, pos, data_str);
    r.data_abertura = parse_data(data_str);

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
 * @reason Le o dataset do arquivo CSV e retorna a colecao de restaurantes
 * @return colecao de restaurantes
 */
Colecao_restaurante ler_csv()
{
    Colecao_restaurante colecao;
    colecao.tamanho = 0;

    FILE *f = fopen("/tmp/restaurantes.csv", "r");

    if ( f == NULL )
    {
        f = fopen("restaurante.csv", "r");
    }

    char linha[500];
    fgets(linha, 500, f);

    for ( int i = 0; i < 500; i++ )
    {
        int j = 0;
        fgets(linha, 500, f);

        while ( linha[j] != '\n' && linha[j] != '\0' )
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

typedef struct NoBicolor
{
    Restaurante elemento;
    bool cor;
    struct NoBicolor *esq, *dir;
} NoBicolor;

typedef struct ArvoreBicolor
{
    NoBicolor *raiz;
    int comparacoes;
} ArvoreBicolor;

NoBicolor* novo_no_bicolor( Restaurante r )
{
    NoBicolor *novo = (NoBicolor*) malloc(sizeof(NoBicolor));
    novo->elemento = r;
    novo->cor = true;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

ArvoreBicolor nova_arvore_bicolor()
{
    ArvoreBicolor arvore;
    arvore.raiz = NULL;
    arvore.comparacoes = 0;
    return arvore;
}

NoBicolor* rotacionar_esq( NoBicolor *no )
{
    NoBicolor *dir = no->dir;
    no->dir = dir->esq;
    dir->esq = no;
    dir->cor = no->cor;
    no->cor = true;
    return dir;
}

NoBicolor* rotacionar_dir( NoBicolor *no )
{
    NoBicolor *esq = no->esq;
    no->esq = esq->dir;
    esq->dir = no;
    esq->cor = no->cor;
    no->cor = true;
    return esq;
}

void trocar_cores( NoBicolor *no )
{
    no->cor = !no->cor;
    no->esq->cor = !no->esq->cor;
    no->dir->cor = !no->dir->cor;
}

NoBicolor* balancear( NoBicolor *no )
{
    if ( no->dir != NULL && no->dir->cor == true && (no->esq == NULL || no->esq->cor == false) )
    {
        no = rotacionar_esq(no);
    }

    if ( no->esq != NULL && no->esq->cor == true && no->esq->esq != NULL && no->esq->esq->cor == true )
    {
        no = rotacionar_dir(no);
    }

    if ( no->esq != NULL && no->esq->cor == true && no->dir != NULL && no->dir->cor == true )
    {
        trocar_cores(no);
    }

    return no;
}

NoBicolor* inserir_rec( NoBicolor *no, Restaurante r )
{
    if ( no == NULL )
    {
        no = novo_no_bicolor(r);
    }
    else
    {
        int cmp = strcmp(r.nome, no->elemento.nome);

        if ( cmp < 0 )
        {
            no->esq = inserir_rec(no->esq, r);
        }
        else if ( cmp > 0 )
        {
            no->dir = inserir_rec(no->dir, r);
        }
    }

    return balancear(no);
}

/**
 * @author Gabriel Ferreira Pereira
 * @param arvore arvore bicolor
 * @param r restaurante a ser inserido
 * @reason Insere restaurante usando o nome como chave de pesquisa
 */
void inserir( ArvoreBicolor *arvore, Restaurante r )
{
    arvore->raiz = inserir_rec(arvore->raiz, r);
    arvore->raiz->cor = false;
}

void pesquisar_rec( NoBicolor *no, char *nome, int raiz, int *comparacoes )
{
    if ( no == NULL )
    {
        printf(" NAO\n");
    }
    else
    {
        if ( raiz )
        {
            printf("raiz");
        }

        (*comparacoes)++;
        int cmp = strcmp(nome, no->elemento.nome);

        if ( cmp == 0 )
        {
            printf(" SIM\n");
        }
        else if ( cmp > 0 )
        {
            printf(" dir");
            pesquisar_rec(no->dir, nome, 0, comparacoes);
        }
        else
        {
            printf(" esq");
            pesquisar_rec(no->esq, nome, 0, comparacoes);
        }
    }
}

/**
 * @author Gabriel Ferreira Pereira
 * @param arvore arvore bicolor
 * @param nome nome pesquisado
 * @reason Pesquisa restaurante pelo nome e mostra o caminho percorrido
 */
void pesquisar( ArvoreBicolor *arvore, char *nome )
{
    pesquisar_rec(arvore->raiz, nome, 1, &arvore->comparacoes);
}

void caminhar_em_rec( NoBicolor *no )
{
    if ( no != NULL )
    {
        caminhar_em_rec(no->esq);
        char saida_linha[500];
        formatar_restaurante(&no->elemento, saida_linha);
        printf("%s\n", saida_linha);
        caminhar_em_rec(no->dir);
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
    Colecao_restaurante colecao = ler_csv();
    Restaurante *restaurantes = get_restaurantes(&colecao);
    ArvoreBicolor arvore = nova_arvore_bicolor();
    int id;

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
        
        if ( strcmp(nome, "FIM") != 0 )
        {
            pesquisar(&arvore, nome);
        }
    }

    clock_t fim = clock();
    double tempo = (double) (fim - inicio) / CLOCKS_PER_SEC;

    caminhar_em(&arvore);

    FILE *log = fopen("842527_arvore_bicolor.txt", "w");
    fprintf(log, "842527\t%d\t%f\n", arvore.comparacoes, tempo);
    fclose(log);

    return 0;
}
