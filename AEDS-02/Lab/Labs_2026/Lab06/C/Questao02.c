#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Celula 
{
    int elemento;
    struct Celula* prox;

} Celula;

Celula* primeiro;
Celula* ultimo;


Celula* novaCelula( int elemento ) 
{
    Celula* nova = (Celula*) malloc(sizeof(Celula));

    if ( nova == NULL ) 
    {
        printf("\nErro");
    }

    nova->elemento = elemento;
    nova->prox = NULL;
    return nova;
}

void start() 
{
    primeiro = novaCelula(-1);
    ultimo = primeiro;
}

void inserir( int x ) 
{
    ultimo->prox = novaCelula(x);
    ultimo = ultimo->prox;
}


int remover() 
{
    if ( primeiro == ultimo )
    {
        return -1;
    }

    Celula* tmp = primeiro;
    primeiro = primeiro->prox;
    int resp = primeiro->elemento;
    
    tmp->prox = NULL;
    free(tmp);

    return resp;
}

void mostrar() 
{
    for ( Celula* i = primeiro->prox; i != NULL; i = i->prox ) 
    {
        printf("%d ", i->elemento);
    }

    printf("\n");
}

bool pesquisar( int x ) 
{
    bool resp = false;

    for ( Celula* i = primeiro->prox; i != NULL; i = i->prox ) 
    {
        if ( i->elemento == x )
        {
            resp = true;
        }
    }
    return resp;
}

int main() 
{
    start(); 

    char op;
    int x = 0, resposta = 0;

    while ( scanf(" %c", &op) != EOF ) 
    {
        if ( op == 'E' ) 
        {
            scanf("%d", &x);
            inserir(x);
        } 

        else if ( op == 'D' ) 
        {
            resposta = remover();
            printf("%d\n", resposta);
        } 

        else if ( op == 'M' ) 
        {
            mostrar();
        } 

        else if ( op == 'P' ) 
        {
            scanf("%d", &x);

            if ( pesquisar(x) ) 
            {
                printf("S\n");

            } 

            else 
            {
                printf("N\n");
            }
        }
    }

    return 0;
}