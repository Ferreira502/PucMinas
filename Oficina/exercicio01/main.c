#include<stdio.h>
#define MAX_EMERGENCIA 5
#define MAX_PERIODICA 5
#define MAX_BACKGROUND 30

typedef struct 
{
    int id;
    int prioridade;
} Tarefa;

typedef struct 
{
    Tarefa pilha[MAX_EMERGENCIA];
    int n;
} PilhaEmergencia;

typedef struct 
{
    Tarefa fila[MAX_PERIODICA];
    int primeiro;
    int ultimo;
} FilaPeriodica;

typedef struct 
{
    Tarefa lista[MAX_BACKGROUND];
    int n;
} ListaBackground;

void inserirPilha( PilhaEmergencia *p, Tarefa x ) 
{
    if ( p->n == MAX_EMERGENCIA ) 
    { 
        printf("Erro: Pilha cheia!\n");
        return;
    }

    p->pilha[p->n] = x; 
    p->n++; 
}

Tarefa removerPilha( PilhaEmergencia *p ) 
{
    if ( p->n == 0 )
    { 
        printf("Erro: Pilha vazia!\n");
        Tarefa erro = {-1, -1};
        return erro;
    }

    p->n--; 
    return p->pilha[p->n];
}

void inserirFila( FilaPeriodica *p, Tarefa t ) 
{
    if (((p->ultimo + 1) % MAX_PERIODICA) == p->primeiro) 
    {
        printf("Erro: Fila cheia!\n");
        return;
    }

    p->fila[p->ultimo] = t;
    p->ultimo = (p->ultimo + 1) % MAX_PERIODICA;
}

Tarefa removerFilaCircular( FilaPeriodica *p ) 
{
    if (p->primeiro == p->ultimo) 
    {
        printf("Erro: Fila vazia (Underflow)!\n");
        return;
    }

    Tarefa resp = p->fila[p->primeiro];
    p->primeiro = (p->primeiro + 1) % MAX_PERIODICA;

    return resp;
}

int main ()
{

}