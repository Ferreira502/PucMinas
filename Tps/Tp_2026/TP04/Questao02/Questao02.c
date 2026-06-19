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
    int movimentacoes;
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
    arvore.movimentacoes = 0;
    return arvore;
}

bool is_no_tipo_quatro( NoBicolor *no )
{
    return no != NULL && no->esq != NULL && no->dir != NULL && no->esq->cor == true && no->dir->cor == true;
}

void fragmentar( ArvoreBicolor *arvore, NoBicolor *no )
{
    if ( no == arvore->raiz )
    {
        no->cor = false;
        no->esq->cor = false;
        no->dir->cor = false;
        arvore->movimentacoes += 3;
    }

    else
    {
        no->cor = true;
        no->esq->cor = false;
        no->dir->cor = false;
        arvore->movimentacoes += 3;
    }
}

NoBicolor* rotacionar_simples_esq( ArvoreBicolor *arvore, NoBicolor *no )
{
    NoBicolor *no_Dir = no->dir;
    NoBicolor *no_Dir_esq = no_Dir->esq;
    no_Dir->esq = no;
    no->dir = no_Dir_esq;
    arvore->movimentacoes += 2;

    return no_Dir;
}

NoBicolor* rotacionar_simples_dir( ArvoreBicolor *arvore, NoBicolor *no )
{
    NoBicolor *no_Esq = no->esq;
    NoBicolor *no_Esq_dir = no_Esq->dir;
    no_Esq->dir = no;
    no->esq = no_Esq_dir;
    arvore->movimentacoes += 2;

    return no_Esq;
}

NoBicolor* rotacionar_dir_esq( ArvoreBicolor *arvore, NoBicolor *no )
{
    no->dir = rotacionar_simples_dir(arvore, no->dir);
    arvore->movimentacoes++;
    return rotacionar_simples_esq(arvore, no);
}

NoBicolor* rotacionar_esq_dir( ArvoreBicolor *arvore, NoBicolor *no )
{
    no->esq = rotacionar_simples_esq(arvore, no->esq);
    arvore->movimentacoes++;
    return rotacionar_simples_dir(arvore, no);
}

void balancear( ArvoreBicolor *arvore, NoBicolor *bisavo, NoBicolor *avo, NoBicolor *pai, NoBicolor *i )
{
    NoBicolor *nova_raiz = NULL;
    int cmp_pai_avo = strcmp(pai->elemento.nome, avo->elemento.nome);
    int cmp_i_pai = strcmp(i->elemento.nome, pai->elemento.nome);
    arvore->comparacoes += 2;

    if ( cmp_pai_avo > 0 && cmp_i_pai > 0 )
    {
        nova_raiz = rotacionar_simples_esq(arvore, avo);
    }

    else if ( cmp_pai_avo > 0 && cmp_i_pai < 0 )
    {
        nova_raiz = rotacionar_dir_esq(arvore, avo);
    }

    else if ( cmp_pai_avo < 0 && cmp_i_pai < 0 )
    {
        nova_raiz = rotacionar_simples_dir(arvore, avo);
    }
    
    else if ( cmp_pai_avo < 0 && cmp_i_pai > 0 )
    {
        nova_raiz = rotacionar_esq_dir(arvore, avo);
    }

    if ( bisavo != NULL )
    {
        arvore->comparacoes++;

        if ( strcmp(bisavo->elemento.nome, nova_raiz->elemento.nome) > 0 )
        {
            bisavo->esq = nova_raiz;
        }

        else
        {
            bisavo->dir = nova_raiz;
        }

        arvore->movimentacoes++;
    }

    else
    {
        arvore->raiz = nova_raiz;
        arvore->movimentacoes++;
    }

    nova_raiz->cor = false;
    nova_raiz->esq->cor = true;
    nova_raiz->dir->cor = true;
    arvore->movimentacoes += 3;
}

void inserir_rec( ArvoreBicolor *arvore, Restaurante r, NoBicolor *bisavo, NoBicolor *avo, NoBicolor *pai, NoBicolor *i )
{
    if ( i == NULL )
    {
        i = novo_no_bicolor(r);
        arvore->movimentacoes++;
        arvore->comparacoes++;

        if ( strcmp(r.nome, pai->elemento.nome) < 0 )
        {
            pai->esq = i;
        }
        else
        {
            pai->dir = i;
        }

        arvore->movimentacoes++;

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

        int cmp = strcmp(r.nome, i->elemento.nome);
        arvore->comparacoes++;

        if ( cmp > 0 )
        {
            inserir_rec(arvore, r, avo, pai, i, i->dir);
        }

        else if ( cmp < 0 )
        {
            inserir_rec(arvore, r, avo, pai, i, i->esq);
        }
    }
}

/**
 * @author Gabriel Ferreira Pereira
 * @param arvore arvore bicolor
 * @param r restaurante a ser inserido
 * @reason Insere restaurante usando o nome como chave de pesquisa
 */
void inserir( ArvoreBicolor *arvore, Restaurante r )
{
    if ( arvore->raiz == NULL )
    {
        arvore->raiz = novo_no_bicolor(r);
        arvore->movimentacoes++;
        arvore->raiz->cor = false;
        arvore->movimentacoes++;
    }

    else
    {
        inserir_rec(arvore, r, NULL, NULL, NULL, arvore->raiz);
        arvore->raiz->cor = false;
        arvore->movimentacoes++;
    }
}

void pesquisar_rec( ArvoreBicolor *arvore, NoBicolor *no, char *nome, int raiz )
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

        int cmp = strcmp(nome, no->elemento.nome);
        arvore->comparacoes++;

        if ( cmp == 0 )
        {
            printf(" SIM\n");
        }
        else if ( cmp > 0 )
        {
            printf(" dir");
            pesquisar_rec(arvore, no->dir, nome, 0);
        }
        else
        {
            printf(" esq");
            pesquisar_rec(arvore, no->esq, nome, 0);
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
    pesquisar_rec(arvore, arvore->raiz, nome, 1);
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
    caminhar_em_rec(arvore->raiz);
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
    int id = 0;
    clock_t inicio, fim;
    double total = 0.0;

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
    inicio = clock();

    while ( fgets(nome, 100, stdin) != NULL )
    {
        int j = 0;

        while ( nome[j] != '\n' && nome[j] != '\0' && nome[j] != '\r')
        {
            j++;
        }

        nome[j] = '\0';
        
        if ( strcmp(nome, "FIM") != 0 )
        {
            pesquisar(&arvore, nome);
        }
        
    }

    fim = clock();
    total = ((fim - inicio) / (double)CLOCKS_PER_SEC);

    caminhar_em(&arvore);

    FILE *log = fopen("842527_arvore_bicolor.txt", "w");

    if ( log != NULL )
    {
        fprintf(log, "Comparacoes: %d\n", arvore.comparacoes);
        fprintf(log, "Movimentacoes: %d\n", arvore.movimentacoes);
        fprintf(log, "Total: %f\n", total);
        fclose(log);
    }

    return 0;
}
