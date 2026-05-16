#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        j = 0;

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


typedef struct Celula 
{
	Restaurante elemento;
	struct Celula* prox;
} Celula;

Celula* primeiro;
Celula* ultimo;

/**
 * @author Gabriel Ferreira Pereira
 * @param restaurante
 * @reason Cria uma nova celula da lista flexivel
 * @return ponteiro para a nova celula
 */
Celula* novaCelula( Restaurante restaurante ) 
{
   Celula* nova = (Celula*) malloc(sizeof(Celula));
   nova->elemento = restaurante;
   nova->prox = NULL;
   return nova;
}

/**
 * @author Gabriel Ferreira Pereira
 * @reason Cria uma lista sem elementos com celula cabeca
 */
void start () 
{
   Restaurante vazio;
   vazio.id = 0;
   vazio.nome[0] = '\0';
   vazio.cidade[0] = '\0';
   vazio.capacidade = 0;
   vazio.avaliacao = 0.0;
   vazio.tipo1[0] = '\0';
   vazio.tipo2[0] = '\0';
   vazio.faixaPreco[0] = '\0';
   vazio.horario_abertura.hora = 0;
   vazio.horario_abertura.minuto = 0;
   vazio.horario_fechamento.hora = 0;
   vazio.horario_fechamento.minuto = 0;
   vazio.data_abertura.dia = 0;
   vazio.data_abertura.mes = 0;
   vazio.data_abertura.ano = 0;
   vazio.aberto = 0;

   primeiro = novaCelula(vazio);
   ultimo = primeiro;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param restaurante
 * @reason Insere um restaurante na primeira posicao da lista
 */
void inserirInicio( Restaurante restaurante ) 
{
   Celula* tmp = novaCelula(restaurante);
   tmp->prox = primeiro->prox;
   primeiro->prox = tmp;

   if ( primeiro == ultimo ) 
   {                    
        ultimo = tmp;
   }
}

/**
 * @author Gabriel Ferreira Pereira
 * @param restaurante
 * @reason Insere um restaurante na ultima posicao da lista
 */
void inserirFim( Restaurante restaurante ) 
{
   ultimo->prox = novaCelula(restaurante);
   ultimo = ultimo->prox;
}

/**
 * @author Gabriel Ferreira Pereira
 * @reason Remove um restaurante da primeira posicao da lista
 * @return restaurante removido
 */
Restaurante removerInicio() 
{
   Celula* tmp = primeiro->prox;
   Restaurante resp = tmp->elemento;
   primeiro->prox = tmp->prox;

   if ( tmp == ultimo )
   {
      ultimo = primeiro;
   }

   tmp->prox = NULL;
   free(tmp);
   return resp;
}

/**
 * @author Gabriel Ferreira Pereira
 * @reason Remove um restaurante da ultima posicao da lista
 * @return restaurante removido
 */
Restaurante removerFim() 
{
   Celula* i;

   for ( i = primeiro; i->prox != ultimo; i = i->prox );

   Restaurante resp = ultimo->elemento;
   free(ultimo);
   ultimo = i;
   ultimo->prox = NULL;

   return resp;
}

/**
 * @author Gabriel Ferreira Pereira
 * @reason Calcula e retorna o tamanho da lista
 * @return tamanho da lista
 */
int tamanho() 
{
   int tamanho = 0;
   Celula* i;
   for ( i = primeiro; i != ultimo; i = i->prox, tamanho++ );
   return tamanho;
}

/**
 * @author Gabriel Ferreira Pereira
 * @param restaurante, pos
 * @reason Insere um restaurante em uma posicao especifica da lista
 */
void inserir( Restaurante restaurante, int pos ) 
{
   int tam = tamanho();

   if ( pos == 0 )
   {
      inserirInicio(restaurante);
   } 
   else if ( pos == tam )
   {
      inserirFim(restaurante);
   } 

   else 
   {
      int j;
      Celula* i = primeiro;

      for ( j = 0; j < pos; j++, i = i->prox );

      Celula* tmp = novaCelula(restaurante);
      tmp->prox = i->prox;
      i->prox = tmp;
   }
}

/**
 * @author Gabriel Ferreira Pereira
 * @param pos
 * @reason Remove um restaurante de uma posicao especifica da lista
 * @return restaurante removido
 */
Restaurante remover( int pos ) 
{
   Restaurante resp;
   int tam = tamanho();

   if ( pos == 0 )
   {
      resp = removerInicio();
   } 

   else if ( pos == tam - 1 )
   {
      resp = removerFim();
   } 

   else 
   {
      Celula* i = primeiro;
      int j;

      for ( j = 0; j < pos; j++, i = i->prox );

      Celula* tmp = i->prox;
      resp = tmp->elemento;
      i->prox = tmp->prox;
      tmp->prox = NULL;
      free(tmp);
   }

   return resp;
}

/**
 * @author Gabriel Ferreira Pereira
 * @reason Mostra os restaurantes da lista formatados
 */
void mostrar() 
{
   char saida_linha[500];
   Celula* i;
   
   for ( i = primeiro->prox; i != NULL; i = i->prox ) 
   {
      formatar_restaurante(&i->elemento, saida_linha);
      printf("%s\n", saida_linha);
   }
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
 * @reason Metodo principal que busca e formata o restaurante com o ID fornecido
 *         e executa os comandos sobre a lista flexivel
 */
int main()
{
    Colecao_restaurante colecao = ler_csv();
    Restaurante *restaurantes = get_restaurantes(&colecao);
    int id = 0;
    int n = 0;
    char comando[3];

    start();

    while ( scanf("%d", &id) && id != -1 )
    {
        inserirFim(buscar_restaurante(restaurantes, get_tamanho(&colecao), id));
    }

    scanf("%d", &n);

    for ( int i = 0; i < n; i++ )
    {
        scanf("%s", comando);

        if ( comando[0] == 'I' && comando[1] == 'I' )
        {
            scanf("%d", &id);
            inserirInicio(buscar_restaurante(restaurantes, get_tamanho(&colecao), id));
        }

        else if ( comando[0] == 'I' && comando[1] == '*' )
        {
            int pos = 0;
            scanf("%d %d", &pos, &id);
            inserir(buscar_restaurante(restaurantes, get_tamanho(&colecao), id), pos);
        }

        else if ( comando[0] == 'I' && comando[1] == 'F' )
        {
            scanf("%d", &id);
            inserirFim(buscar_restaurante(restaurantes, get_tamanho(&colecao), id));
        }

        else if ( comando[0] == 'R' && comando[1] == 'I' )
        {
            Restaurante removido = removerInicio();
            printf("(R)%s\n", removido.nome);
        }

        else if ( comando[0] == 'R' && comando[1] == '*' )
        {
            int pos = 0;
            scanf("%d", &pos);
            Restaurante removido = remover(pos);
            printf("(R)%s\n", removido.nome);
        }

        else if ( comando[0] == 'R' && comando[1] == 'F' )
        {
            Restaurante removido = removerFim();
            printf("(R)%s\n", removido.nome);
        }
    }

    mostrar();

}
