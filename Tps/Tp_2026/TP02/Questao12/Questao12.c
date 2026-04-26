#include <stdio.h>

#define MAX 100


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

typedef struct
{
    Restaurante dados[MAX];
    int topo;
} Pilha;

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

    // pular cabecalho
    fgets(linha, 500, f);

    for ( int i = 0; i < 500; i++ )
    {
        int j = 0;
        fgets(linha, 500, f);

        // substitui o \n por \0 para encerrar a string
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

/**
 * @author Gabriel Ferreira Pereira
 * @param p objeto Pilha
 * @reason Inicializa a pilha com topo -1
 */
void inicializar( Pilha *p )
{
    p->topo = -1;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param p objeto Pilha
 * @reason Verifica se a pilha esta vazia
 * @return 1 se vazia, 0 caso contrario
 */
int pilha_vazia( Pilha *p )
{
    return p->topo == -1;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param p objeto Pilha
 * @reason Verifica se a pilha esta cheia
 * @return 1 se cheia, 0 caso contrario
 */
int pilha_cheia( Pilha *p )
{
    return p->topo == MAX - 1;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param p objeto Pilha
 * @param r Restaurante a ser inserido
 * @reason Insere um restaurante no topo da pilha
 */
void inserir( Pilha *p, Restaurante r )
{
    if ( pilha_cheia(p) )
    {
        printf("Erro: pilha cheia!\n");
    }
    else
    {
        p->topo++;
        p->dados[p->topo] = r;
    }
}

/**
 * @author Gabriel Ferreira Pereira
 * @param p objeto Pilha
 * @reason Remove e retorna o restaurante do topo da pilha
 * @return Restaurante removido
 */
Restaurante remover( Pilha *p )
{
    if ( pilha_vazia(p) )
    {
        printf("Erro: pilha vazia!\n");
        Restaurante vazio;
        vazio.id = -1;
        return vazio;
    }

    Restaurante r = p->dados[p->topo];
    p->topo--;
    return r;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param p objeto Pilha
 * @reason Mostra os restaurantes da pilha do topo para a base
 */
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
    Colecao_restaurante colecao = ler_csv();
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