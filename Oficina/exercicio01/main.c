#include <stdio.h>

#define MAX_EMERGENCIA 5
#define MAX_PERIODICA 5
#define MAX_BACKGROUND 30

typedef struct {
    int id;
    int prioridade; // 0-10 (0 = máxima prioridade)
} Tarefa;

typedef struct {
    Tarefa pilha[MAX_EMERGENCIA];
    int n;
} PilhaEmergencia;

typedef struct {
    Tarefa fila[MAX_PERIODICA];
    int primeiro;
    int ultimo;
} FilaPeriodica;

typedef struct {
    Tarefa lista[MAX_BACKGROUND];
    int n;
} ListaBackground;

// --- FUNÇÕES DA PILHA (EMERGÊNCIA) ---
void inserirPilha(PilhaEmergencia *p, Tarefa x) {
    if (p->n == MAX_EMERGENCIA) {
        printf("Erro: Pilha de Emergencia cheia!\n");
        return;
    }
    p->pilha[p->n] = x;
    p->n++;
}

Tarefa removerPilha(PilhaEmergencia *p) {
    if (p->n == 0) {
        printf("Erro: Pilha vazia!\n");
        Tarefa erro = {-1, -1};
        return erro;
    }
    p->n--;
    return p->pilha[p->n];
}

// --- FUNÇÕES DA FILA (PERIÓDICA) ---
void inserirFila(FilaPeriodica *p, Tarefa t) {
    if (((p->ultimo + 1) % MAX_PERIODICA) == p->primeiro) {
        printf("Erro: Fila Periodica cheia!\n");
        return;
    }
    p->fila[p->ultimo] = t;
    p->ultimo = (p->ultimo + 1) % MAX_PERIODICA;
}

Tarefa removerFilaCircular(FilaPeriodica *p) {
    if (p->primeiro == p->ultimo) {
        printf("Erro: Fila vazia!\n");
        Tarefa erro = {-1, -1};
        return erro;
    }
    Tarefa resp = p->fila[p->primeiro];
    p->primeiro = (p->primeiro + 1) % MAX_PERIODICA;
    return resp;
}

// --- FUNÇÕES DA LISTA (BACKGROUND) ---
void inserirBackground(ListaBackground *l, Tarefa t) {
    if (l->n >= MAX_BACKGROUND) {
        printf("Erro: Lista Background cheia!\n");
        return;
    }
    int i = l->n - 1;
    while (i >= 0 && l->lista[i].prioridade > t.prioridade) {
        l->lista[i + 1] = l->lista[i];
        i--;
    }
    l->lista[i + 1] = t;
    l->n++;
}

Tarefa removerBackground(ListaBackground *l) {
    if (l->n == 0) {
        Tarefa erro = {-1, -1};
        return erro;
    }
    Tarefa resp = l->lista[0];
    for (int i = 0; i < l->n - 1; i++) {
        l->lista[i] = l->lista[i + 1];
    }
    l->n--;
    return resp;
}

// --- REQUISITOS DO SISTEMA ---
Tarefa processarTarefa(PilhaEmergencia *p, FilaPeriodica *f, ListaBackground *l) {
    if (p->n > 0) return removerPilha(p);
    if (f->primeiro != f->ultimo) return removerFilaCircular(f);
    if (l->n > 0) return removerBackground(l);
    
    Tarefa vazia = {-1, -1};
    return vazia;
}

void promoverTarefa(PilhaEmergencia *p, ListaBackground *l, int id) {
    int achou = -1;
    for (int i = 0; i < l->n; i++) {
        if (l->lista[i].id == id) {
            achou = i;
            break;
        }
    }
    if (achou != -1) {
        Tarefa t = l->lista[achou];
        for (int j = achou; j < l->n - 1; j++) l->lista[j] = l->lista[j + 1];
        l->n--;
        inserirPilha(p, t);
        printf("Tarefa ID %d promovida para Emergencia!\n", id);
    } else {
        printf("Tarefa ID %d nao encontrada no Background.\n", id);
    }
}

void imprimirEstruturas(PilhaEmergencia *p, FilaPeriodica *f, ListaBackground *l) {
    printf("\n--- ESTADO ATUAL ---");
    printf("\nEmergencia (Pilha): %d tarefas", p->n);
    printf("\nPeriodica (Fila): %d tarefas", (f->ultimo - f->primeiro + MAX_PERIODICA) % MAX_PERIODICA);
    printf("\nBackground (Lista): %d tarefas\n", l->n);
}

// --- MAIN COM MENU ---
int main() {
    PilhaEmergencia pe = {.n = 0};
    FilaPeriodica fp = {.primeiro = 0, .ultimo = 0};
    ListaBackground lb = {.n = 0};

    int opcao, tipo;
    Tarefa temp;

    do {
        printf("\n--- SISTEMA DE TAREFAS ---");
        printf("\n1. Criar Nova Tarefa");
        printf("\n2. Processar Proxima Tarefa");
        printf("\n3. Promover Tarefa (Background -> Emergencia)");
        printf("\n4. Mostrar Estatisticas");
        printf("\n0. Sair");
        printf("\nEscolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("ID: "); scanf("%d", &temp.id);
                printf("Prioridade (0-10): "); scanf("%d", &temp.prioridade);
                printf("Tipo (1-Emergencia, 2-Periodica, 3-Background): "); scanf("%d", &tipo);
                if(tipo == 1) inserirPilha(&pe, temp);
                else if(tipo == 2) inserirFila(&fp, temp);
                else if(tipo == 3) inserirBackground(&lb, temp);
                break;
            case 2:
                temp = processarTarefa(&pe, &fp, &lb);
                if(temp.id != -1) printf("Executando Tarefa ID: %d\n", temp.id);
                else printf("Nada para processar.\n");
                break;
            case 3:
                printf("ID para promover: "); scanf("%d", &tipo);
                promoverTarefa(&pe, &lb, tipo);
                break;
            case 4:
                imprimirEstruturas(&pe, &fp, &lb);
                break;
        }
    } while (opcao != 0);

    return 0;
}