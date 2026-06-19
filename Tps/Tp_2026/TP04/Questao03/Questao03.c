#include <stdio.h>
#include <time.h>

#define MAX_RESTAURANTES 500
#define TAM_TAB 31
#define TAM_RESERVA 19
#define TAM_TOTAL (TAM_TAB + TAM_RESERVA)

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
    Restaurante restaurantes[MAX_RESTAURANTES];
} Colecao_restaurante;

typedef struct Hash
{
    Restaurante tabela[TAM_TOTAL];
    int ocupado[TAM_TOTAL];
    int reserva_usada;
    int comparacoes;
} Hash;

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

    if ( linha[pos] == ',' )
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

    while ( cozinha[j] != ';' && cozinha[j] != '\0' )
    {
        r.tipo1[k++] = cozinha[j++];
    }
    r.tipo1[k] = '\0';

    if ( cozinha[j] == ';' )
    {
        j++;
    }

    k = 0;

    while ( cozinha[j] != '\0' )
    {
        r.tipo2[k++] = cozinha[j++];
    }
    r.tipo2[k] = '\0';

    // faixa preco
    pos = ler_campo(linha, pos, r.faixaPreco);

    // horario
    pos = ler_campo(linha, pos, campo);
    j = 0;
    k = 0;

    while ( campo[j] != '-' && campo[j] != '\0' )
    {
        horario_abertura[k++] = campo[j++];
    }
    horario_abertura[k] = '\0';

    if ( campo[j] == '-' )
    {
        j++;
    }

    k = 0;

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

    sprintf(saida_linha,
            "[%d ## %s ## %s ## %d ## %.1f ## [%s,%s] ## %s ## %s-%s ## %s ## %s]",
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
    FILE *f;
    char linha[500];

    colecao.tamanho = 0;

    f = fopen("/tmp/restaurantes.csv", "r");

    if ( f == NULL )
    {
        f = fopen("restaurante.csv", "r");
    }

    if ( f == NULL )
    {
        return colecao;
    }

    fgets(linha, 500, f);

    while ( colecao.tamanho < MAX_RESTAURANTES && fgets(linha, 500, f) != NULL )
    {
        int j = 0;

        while ( linha[j] != '\n' && linha[j] != '\r' && linha[j] != '\0' )
        {
            j++;
        }
        linha[j] = '\0';

        adicionar(&colecao, ler_restaurante(linha));
    }

    fclose(f);
    return colecao;
}

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
            nomes_iguais(hash, hash->tabela[pos_reserva].nome, nome))
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
    Colecao_restaurante colecao = ler_csv();
    Restaurante *restaurantes = get_restaurantes(&colecao);
    Hash hash;
    Restaurante encontrado;
    char nome[100];
    char saida_linha[500];
    int id;
    int i;

    iniciar_hash(&hash);

    while ( scanf("%d", &id) && id != -1 )
    {
        int inserido = 0;

        for ( i = 0; i < get_tamanho(&colecao); i++ )
        {
            if ( inserido == 0 && restaurantes[i].id == id )
            {
                inserir_hash(&hash, restaurantes[i]);
                inserido = 1;
            }
        }
    }

    fgets(nome, 100, stdin);

    clock_t inicio = clock();

    while ( fgets(nome, 100, stdin) != NULL )
    {
        int j = 0;
        int pos;

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

    clock_t fim = clock();
    double tempo = (double) (fim - inicio) / CLOCKS_PER_SEC;

    FILE *log = fopen("842527_hash_reserva.txt", "w");

    if ( log != NULL )
    {
        fprintf(log, "842527\t%d\t%f\n", hash.comparacoes, tempo);
        fclose(log);
    }

    return 0;
}
