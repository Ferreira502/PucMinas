#include <stdio.h>
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
    int j = 0;

    // pular cabecalho
    fgets(linha, 500, f);

    for ( int i = 0; i < 500; i++ )
    {
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
 * @param a, b
 * @reason Compara duas datas pela ordem ano, mes e dia
 * @return positivo se a > b, negativo se a < b, zero se iguais
 */
int comparar_data( Data a, Data b )
{
    if ( a.ano != b.ano )
    {
        return a.ano - b.ano;
    }

    if ( a.mes != b.mes )
    {
        return a.mes - b.mes;
    }

    return a.dia - b.dia;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param a, b
 * @reason Compara dois restaurantes pela data de abertura e desempata pelo nome
 * @return positivo se a > b, negativo se a < b, zero se iguais
 */
int comparar_restaurante( Restaurante *a, Restaurante *b )
{
    int cmp = comparar_data(a->data_abertura, b->data_abertura);

    if ( cmp != 0 )
    {
        return cmp;
    }

    return strcmp(a->nome, b->nome);
}

/**
 * @author Gabriel Ferreira Pereira
 * @param array, tamHeap, contadores
 * @reason Constroi o heap maximo inserindo um elemento por vez
 */
void construir( Restaurante *array, int tamHeap, int *contadores )
{
    for ( int i = tamHeap; i > 1; i /= 2 )
    {
        // printf("construir: comparando %s com pai %s\n", array[i].nome, array[i / 2].nome);
        contadores[0]++;

        if ( comparar_restaurante(&array[i], &array[i / 2]) > 0 )
        {
            // printf("construir: trocando %s com %s\n", array[i].nome, array[i / 2].nome);
            Restaurante temp = array[i];
            array[i] = array[i / 2];
            array[i / 2] = temp;
            contadores[1] += 3;
        }

        else
        {
            i = 1;
        }
    }
}

/**
 * @author Gabriel Ferreira Pereira
 * @param array, i, tamHeap, contadores
 * @reason Retorna o indice do maior filho de um no heap
 * @return indice do maior filho
 */
int getMaiorFilho( Restaurante *array, int i, int tamHeap, int *contadores )
{
    int filho;

    if ( 2 * i == tamHeap )
    {
        filho = 2 * i;
    }

    else
    {
        contadores[0]++;

        if ( comparar_restaurante(&array[2 * i], &array[2 * i + 1]) > 0 )
        {
            filho = 2 * i;
        }

        else
        {
            filho = 2 * i + 1;
        }
    }

    return filho;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param array, tamHeap, contadores
 * @reason Reconstroi o heap maximo apos a remocao da raiz
 */
void reconstruir( Restaurante *array, int tamHeap, int *contadores )
{
    int i = 1;

    while ( i <= ( tamHeap / 2 ) )
    {
        int filho = getMaiorFilho(array, i, tamHeap, contadores);
        // printf("reconstruir: pai %s, maior filho %s\n", array[i].nome, array[filho].nome);
        contadores[0]++;

        if ( comparar_restaurante(&array[filho], &array[i]) > 0 )
        {
            // printf("reconstruir: trocando %s com %s\n", array[i].nome, array[filho].nome);
            Restaurante temp = array[i];
            array[i] = array[filho];
            array[filho] = temp;
            contadores[1] += 3;
            i = filho;
        }

        else
        {
            i = tamHeap;
        }
    }
}

/**
 * @author Gabriel Ferreira Pereira
 * @param array, n, contadores
 * @reason Ordena o array de restaurantes com heapsort
 */
void heapsort( Restaurante *array, int n, int *contadores )
{
    Restaurante arrayTmp[501];

    for ( int i = 0; i < n; i++ )
    {
        arrayTmp[i + 1] = array[i];
        contadores[1]++;
    }

    for ( int tamHeap = 2; tamHeap <= n; tamHeap++ )
    {
        // printf("heapsort: construindo heap com tamanho %d\n", tamHeap);
        construir(arrayTmp, tamHeap, contadores);
    }

    for ( int tamHeap = n; tamHeap > 1; tamHeap-- )
    {
        // printf("heapsort: movendo %s para a posicao %d\n", arrayTmp[1].nome, tamHeap);
        Restaurante temp = arrayTmp[1];
        arrayTmp[1] = arrayTmp[tamHeap];
        arrayTmp[tamHeap] = temp;
        contadores[1] += 3;
        reconstruir(arrayTmp, tamHeap - 1, contadores);
    }

    for ( int i = 0; i < n; i++ )
    {
        array[i] = arrayTmp[i + 1];
        contadores[1]++;
    }
}

/**
 * @author Gabriel Ferreira Pereira
 * @reason Metodo principal que busca e formata o restaurante com o ID fornecido
 *         e exibe na tela a lista de restaurantes selecionados ordenados
 */
int main()
{
    Colecao_restaurante colecao = ler_csv();
    Restaurante *restaurantes = get_restaurantes(&colecao);
    Restaurante selecionados[500];
    int tamanho = 0;
    char saida_linha[500];
    int id = 0;
    int contadores[2] = {0, 0};
    clock_t inicio, fim;
    double total = 0.0;

    while ( scanf("%d", &id) && id != -1 )
    {
        for ( int i = 0; i < get_tamanho(&colecao); i++ )
        {
            if ( restaurantes[i].id == id )
            {
                selecionados[tamanho] = restaurantes[i];
                tamanho++;
            }
        }
    }

    inicio = clock();
    heapsort(selecionados, tamanho, contadores);
    fim = clock();
    total = ( fim - inicio ) / (double) CLOCKS_PER_SEC;

    FILE *log = fopen("842527_heapsort.txt", "w");
    fprintf(log, "Tempo para ordenar: %f s\n", total);
    fprintf(log, "Comparacoes: %d\n", contadores[0]);
    fprintf(log, "Movimentacoes: %d\n", contadores[1]);
    fclose(log);

    for ( int i = 0; i < tamanho; i++ )
    {
        formatar_restaurante(&selecionados[i], saida_linha);
        printf("%s\n", saida_linha);
    }

    return 0;
}