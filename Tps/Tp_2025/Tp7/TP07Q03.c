// TP07Q04_avl.c
// 842527 - Gabriel Ferreira Pereira
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING 512
#define MAX_ARRAY  60
#define MAX_GAMES  5000
#define MAX_LINE   10000

// Struct Game 
typedef struct {
    int appId;
    char name[MAX_STRING];
    char releaseDate[MAX_STRING];
    int estimatedOwners;
    double price;
    char supportedLanguages[MAX_ARRAY][MAX_STRING];
    int supportedLanguagesCount;
    int metacriticScore;
    double userScore;
    int achievements;
    char publishers[MAX_ARRAY][MAX_STRING];
    int publishersCount;
    char developers[MAX_ARRAY][MAX_STRING];
    int developersCount;
    char categories[MAX_ARRAY][MAX_STRING];
    int categoriesCount;
    char genres[MAX_ARRAY][MAX_STRING];
    int genresCount;
    char tags[MAX_ARRAY][MAX_STRING];
    int tagsCount;
} Game;

void initializeGame(Game *game) {
    game->appId = 0;
    game->name[0] = '\0';
    game->releaseDate[0] = '\0';
    game->estimatedOwners = 0;
    game->price = 0.0;
    game->supportedLanguagesCount = 0;
    game->metacriticScore = -1;
    game->userScore = -1.0;
    game->achievements = 0;
    game->publishersCount = 0;
    game->developersCount = 0;
    game->categoriesCount = 0;
    game->genresCount = 0;
    game->tagsCount = 0;
}

void removeAspas(char *str) {
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != '"' && str[i] != '\'')
            str[j++] = str[i];
    str[j] = '\0';
}

bool isSpace(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

void trim(char *str) {
    int start = 0;
    while (isSpace(str[start])) start++;
    int end = (int)strlen(str) - 1;
    while (end >= start && isSpace(str[end])) end--;

    int j = 0;
    for (int i = start; i <= end; i++) {
        str[j++] = str[i];
    }
    str[j] = '\0';
}

bool isDigitChar(char c) {
    return (c >= '0' && c <= '9');
}

int stringParaInt(char *str) {
    int res = 0;
    int i = 0;
    bool neg = false;
    if (str[0] == '-') { neg = true; i = 1; }
    while (str[i] != '\0') {
        if (isDigitChar(str[i])) {
            res = res * 10 + (str[i] - '0');
        }
        i++;
    }
    return neg ? -res : res;
}

double stringParaDouble(char *str) {
    double res = 0.0;
    int i = 0;
    bool neg = false;
    if (str[0] == '-') { neg = true; i = 1; }
    while (str[i] != '\0' && str[i] != '.') {
        if (isDigitChar(str[i])) res = res * 10 + (str[i] - '0');
        i++;
    }
    if (str[i] == '.') {
        i++;
        double divisor = 10.0;
        while (str[i] != '\0') {
            if (isDigitChar(str[i])) {
                res += (str[i] - '0') / divisor;
                divisor *= 10;
            }
            i++;
        }
    }
    return neg ? -res : res;
}

int separarCamposCSV(char *linha, char campos[][MAX_STRING]) {
    int count = 0;
    bool dentroAspas = false;
    char campoAtual[MAX_STRING];
    int pos = 0;
    campoAtual[0] = '\0';

    for (int i = 0; linha[i] != '\0'; i++) {
        char c = linha[i];
        if (c == '"') {
            dentroAspas = !dentroAspas;
            campoAtual[pos++] = c;
        } else if (c == ',' && !dentroAspas) {
            campoAtual[pos] = '\0';
            trim(campoAtual);
            strncpy(campos[count++], campoAtual, MAX_STRING - 1);
            pos = 0;
            campoAtual[0] = '\0';
        } else {
            if (pos < MAX_STRING - 1) campoAtual[pos++] = c;
        }
    }
    if (pos > 0) {
        campoAtual[pos] = '\0';
        trim(campoAtual);
        strncpy(campos[count++], campoAtual, MAX_STRING - 1);
    }
    return count;
}

void processarArray(char *campo, char array[][MAX_STRING], int *count) {
    *count = 0;
    if (campo == NULL) return;
    char temp[MAX_STRING];
    int len = (int)strlen(campo);
    int start = 0, end = len - 1;

    if (campo[0] == '[') start++;
    if (len > 0 && campo[len - 1] == ']') end--;

    int j = 0;
    for (int i = start; i <= end; i++) {
        if (j < MAX_STRING - 1) temp[j++] = campo[i];
    }
    temp[j] = '\0';

    bool dentroAspas = false;
    char itemAtual[MAX_STRING];
    int pos = 0;
    itemAtual[0] = '\0';
    for (int i = 0; temp[i] != '\0'; i++) {
        char c = temp[i];
        if (c == '"') {
            dentroAspas = !dentroAspas;
        } else if (c == ',' && !dentroAspas) {
            itemAtual[pos] = '\0';
            trim(itemAtual);
            removeAspas(itemAtual);
            if (strlen(itemAtual) > 0)
                strncpy(array[(*count)++], itemAtual, MAX_STRING - 1);
            pos = 0;
            itemAtual[0] = '\0';
        } else {
            if (pos < MAX_STRING - 1) itemAtual[pos++] = c;
        }
    }
    if (pos > 0) {
        itemAtual[pos] = '\0';
        trim(itemAtual);
        removeAspas(itemAtual);
        if (strlen(itemAtual) > 0)
            strncpy(array[(*count)++], itemAtual, MAX_STRING - 1);
    }
}

void formatarData(char *data) {
    if (data == NULL || strlen(data) == 0) return;

    char mes[4] = {0}, dia[4] = {0}, ano[8] = {0};
    int i = 0, j = 0;

    for (i = 0; i < 3 && data[i]; i++) mes[i] = data[i];
    mes[3] = '\0';

    while (data[i] && data[i] == ' ') i++;

    j = 0;
    while (data[i] && data[i] != ',' && j < 3) {
        if (isDigitChar(data[i])) dia[j++] = data[i];
        i++;
    }
    dia[j] = '\0';
    int diaInt = stringParaInt(dia);

    while (data[i] && (data[i] == ',' || data[i] == ' ')) i++;

    j = 0;
    while (data[i] && j < 4) ano[j++] = data[i++];
    ano[j] = '\0';

    char mesNum[3] = "00";
    if (strcmp(mes, "Jan") == 0) strcpy(mesNum, "01");
    else if (strcmp(mes, "Feb") == 0) strcpy(mesNum, "02");
    else if (strcmp(mes, "Mar") == 0) strcpy(mesNum, "03");
    else if (strcmp(mes, "Apr") == 0) strcpy(mesNum, "04");
    else if (strcmp(mes, "May") == 0) strcpy(mesNum, "05");
    else if (strcmp(mes, "Jun") == 0) strcpy(mesNum, "06");
    else if (strcmp(mes, "Jul") == 0) strcpy(mesNum, "07");
    else if (strcmp(mes, "Aug") == 0) strcpy(mesNum, "08");
    else if (strcmp(mes, "Sep") == 0) strcpy(mesNum, "09");
    else if (strcmp(mes, "Oct") == 0) strcpy(mesNum, "10");
    else if (strcmp(mes, "Nov") == 0) strcpy(mesNum, "11");
    else if (strcmp(mes, "Dec") == 0) strcpy(mesNum, "12");

    char novaData[12] = {0};
    if (diaInt < 10) 
    {
        snprintf(novaData, sizeof(novaData), "0%d/%s/%s", diaInt, mesNum, ano);
    } 
    else 
    {
        snprintf(novaData, sizeof(novaData), "%02d/%s/%s", diaInt, mesNum, ano);
    }

    strcpy(data, novaData);
}

int parseEstimatedOwners(char *str) 
{
    char temp[MAX_STRING];
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (isDigitChar(str[i])) 
        {
            if (j < MAX_STRING - 1) temp[j++] = str[i];
        }
    temp[j] = '\0';
    return stringParaInt(temp);
}

void lerGame(Game *game, char *linha) 
{
    initializeGame(game);
    char campos[30][MAX_STRING];
    int numCampos = separarCamposCSV(linha, campos);
    if (numCampos > 0) game->appId = stringParaInt(campos[0]);
    if (numCampos > 1) {
        strncpy(game->name, campos[1], MAX_STRING - 1);
        trim(game->name);
        removeAspas(game->name);
    }
    if (numCampos > 2) {
        strncpy(game->releaseDate, campos[2], MAX_STRING - 1);
        trim(game->releaseDate);
        removeAspas(game->releaseDate);
        formatarData(game->releaseDate);
    }
    if (numCampos > 3) game->estimatedOwners = parseEstimatedOwners(campos[3]);

    if (numCampos > 4) 
    {
        trim(campos[4]);
        if (strcmp(campos[4], "Free to Play") == 0 || strcmp(campos[4], "0") == 0)
            game->price = 0.0;
        else
            game->price = stringParaDouble(campos[4]);
    }
    if (numCampos > 5) processarArray(campos[5], game->supportedLanguages, &game->supportedLanguagesCount);
    if (numCampos > 6) game->metacriticScore = stringParaInt(campos[6]);
    if (numCampos > 7 && strcmp(campos[7], "tbd") != 0) game->userScore = stringParaDouble(campos[7]);
    if (numCampos > 8) game->achievements = stringParaInt(campos[8]);
    if (numCampos > 9) processarArray(campos[9], game->publishers, &game->publishersCount);
    if (numCampos > 10) processarArray(campos[10], game->developers, &game->developersCount);
    if (numCampos > 11) processarArray(campos[11], game->categories, &game->categoriesCount);
    if (numCampos > 12) processarArray(campos[12], game->genres, &game->genresCount);
    if (numCampos > 13) processarArray(campos[13], game->tags, &game->tagsCount);
}

void formatarArrayParaSaida(char array[][MAX_STRING], int count, char *resultado) 
{
    resultado[0] = '\0';
    strcat(resultado, "[");
    for (int i = 0; i < count; i++) 
    {
        strcat(resultado, array[i]);
        if (i < count - 1) strcat(resultado, ", ");
    }
    strcat(resultado, "]");
}

void formatarSaida(Game *game) 
{
    char languages[2000] = "", pubs[2000] = "", devs[2000] = "", cats[2000] = "", gens[2000] = "", tags[2000] = "";
    formatarArrayParaSaida(game->supportedLanguages, game->supportedLanguagesCount, languages);
    formatarArrayParaSaida(game->publishers, game->publishersCount, pubs);
    formatarArrayParaSaida(game->developers, game->developersCount, devs);
    formatarArrayParaSaida(game->categories, game->categoriesCount, cats);
    formatarArrayParaSaida(game->genres, game->genresCount, gens);
    formatarArrayParaSaida(game->tags, game->tagsCount, tags);

    printf("=> %d ## %s ## %s ## %d ## %.2f ## %s ## %d ## %.1f ## %d ## %s ## %s ## %s ## %s ## %s ##\n",
        game->appId,
        game->name, game->releaseDate, game->estimatedOwners, game->price,
        languages, game->metacriticScore, game->userScore, game->achievements,
        pubs, devs, cats, gens, tags);
}

//  AVL em que cada No guarda um Game 
typedef struct NoAVL 
{
    Game game;
    struct NoAVL *esq;
    struct NoAVL *dir;
    int altura;
} NoAVL;

int alturaNo(NoAVL* n) 
{
    return (n == NULL) ? 0 : n->altura;
}

int maxInt(int a, int b) 
{
    return (a > b) ? a : b;
}

NoAVL* novoNoAVL(Game *g) 
{
    NoAVL *n = (NoAVL*) malloc(sizeof(NoAVL));
    n->game = *g; // copia
    n->esq = n->dir = NULL;
    n->altura = 1;
    return n;
}

NoAVL* rotacaoEsqAVL(NoAVL* h) 
{
    NoAVL* x = h->dir;
    NoAVL* T2 = x->esq;

    x->esq = h;
    h->dir = T2;

    h->altura = maxInt(alturaNo(h->esq), alturaNo(h->dir)) + 1;
    x->altura = maxInt(alturaNo(x->esq), alturaNo(x->dir)) + 1;

    
    return x;
}

NoAVL* rotacaoDirAVL(NoAVL* h) 
{
    NoAVL* x = h->esq;
    NoAVL* T2 = x->dir;

    x->dir = h;
    h->esq = T2;

    h->altura = maxInt(alturaNo(h->esq), alturaNo(h->dir)) + 1;
    x->altura = maxInt(alturaNo(x->esq), alturaNo(x->dir)) + 1;

    
    return x;
}

NoAVL* inserirAVL(NoAVL* node, Game *g) 
{
    if (node == NULL) 
    {
        return novoNoAVL(g);
    }

    
    int cmp = strcmp(g->name, node->game.name);
    if (cmp < 0) 
    {
        node->esq = inserirAVL(node->esq, g);
    } 
    else if (cmp > 0) 
    {
        node->dir = inserirAVL(node->dir, g);
    } 
    else 
    {
        return node;
    }

    node->altura = 1 + maxInt(alturaNo(node->esq), alturaNo(node->dir));

    int balance = alturaNo(node->esq) - alturaNo(node->dir);

    // rotacao esquerda esquerda
    if (balance > 1 && strcmp(g->name, node->esq->game.name) < 0)
    {
        return rotacaoDirAVL(node);
    }

    // rotacao direita direita
    if (balance < -1 && strcmp(g->name, node->dir->game.name) > 0)
    {
        return rotacaoEsqAVL(node);
    }

    // rotacao esquerda direita
    if (balance > 1 && strcmp(g->name, node->esq->game.name) > 0) 
    {
        node->esq = rotacaoEsqAVL(node->esq);
        return rotacaoDirAVL(node);
    }

    // rotacao direita esquerda
    if (balance < -1 && strcmp(g->name, node->dir->game.name) < 0) 
    {
        node->dir = rotacaoDirAVL(node->dir);
        return rotacaoEsqAVL(node);
    }

    return node;
}

// Pesquisa imprimindo caminho
bool pesquisarMostrarAVL(NoAVL *raiz, const char *nome) 
{
    printf(" raiz ");
    NoAVL *cur = raiz;
    while (cur != NULL) 
    {
        
        int cmp = strcmp(nome, cur->game.name);
        if (cmp == 0) 
        {
            return true;
        } 
        else if (cmp < 0) 
        {
            printf("esq ");
            cur = cur->esq;
        } 
        else 
        {
            printf("dir ");
            cur = cur->dir;
        }
    }
    return false;
}

// pesquisar
bool pesquisarAVL(NoAVL *raiz, const char *nome) 
{
    return pesquisarMostrarAVL(raiz, nome);
}

int main() 
{
    Game *lista = malloc(sizeof(Game) * MAX_GAMES);
    int count = 0;

    FILE* f = fopen("/tmp/games.csv", "r");
    if (!f) 
    {
        // arquivo nao encontrado
        free(lista);
        return 0;
    }

    char linha[MAX_LINE];

    // pular cabecalho
    if (fgets(linha, sizeof(linha), f) == NULL) {
        fclose(f);
        free(lista);
        return 0;
    }

    while (fgets(linha, sizeof(linha), f) != NULL && count < MAX_GAMES) {
        linha[strcspn(linha, "\n")] = '\0';
        lerGame(&lista[count], linha);
        count++;
    }
    fclose(f);

    NoAVL* raiz = NULL;
    char entrada[200];

    // inserir via ID 
    while (fgets(entrada, sizeof(entrada), stdin)) 
    {
        entrada[strcspn(entrada, "\n")] = 0;
        if (strcmp(entrada, "FIM") == 0) 
        {
            break;
        }

        int id = atoi(entrada);

        // busca linear simples para achar o game com aquele id
        for (int i = 0; i < count; i++) 
        {
            if (lista[i].appId == id) 
            {
                raiz = inserirAVL(raiz, &lista[i]);
                break;
            }
        }
    }

    // pesquisar pelos nomes
    while (fgets(entrada, sizeof(entrada), stdin)) 
    {
        entrada[strcspn(entrada, "\n")] = 0;

        if (strcmp(entrada, "FIM") == 0) 
        {
            break;
        }

        printf("%s: ", entrada);
        bool achou = pesquisarAVL(raiz, entrada);
        printf("%s\n", achou ? "SIM" : "NAO");
    }

    free(lista);
    return 0;
}
