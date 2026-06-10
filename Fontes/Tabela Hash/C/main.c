#include <stdio.h>
#include <stdbool.h>

#define MAX 100
#define m 11
#define r 3

typedef struct
{
    char tabela[MAX][MAX];
    int nr;
} Hash;

void iniciarHash(Hash *hash)
{
    hash->nr = 0;

    for(int i = 0; i < m + r; i++)
    {
        hash->tabela[i][0] = '\0';
    }
}

int isPosicaoLivre(Hash *hash, int pos)
{
    return hash->tabela[pos][0] == '\0';
}

void copiarString(char destino[], char origem[])
{
    int i = 0;

    while(origem[i] != '\0')
    {
        destino[i] = origem[i];
        i++;
    }

    destino[i] = '\0';
}

int iguais(char s1[], char s2[])
{
    int i = 0;

    while(s1[i] != '\0' && s2[i] != '\0')
    {
        if(s1[i] != s2[i])
        {
            return 0;
        }

        i++;
    }

    return s1[i] == '\0' && s2[i] == '\0';
}

int hashFunc(char chave[])
{
    int x = 0;

    for(int i = 0; chave[i] != '\0'; i++)
    {
        x += chave[i];
    }

    return x % m;
}

char *pesquisar(Hash *hash, char chave[])
{
    int pos = hashFunc(chave);

    if(iguais(hash->tabela[pos], chave))
    {
        return hash->tabela[pos];
    }

    for(int i = 0; i < hash->nr; i++)
    {
        if(iguais(hash->tabela[m + i], chave))
        {
            return hash->tabela[m + i];
        }
    }

    return NULL;
}

void inserir(Hash *hash, char chave[])
{
    int pos = hashFunc(chave);

    if(pesquisar(hash, chave) != NULL)
    {
        printf("Erro\n");
    }
    else if(isPosicaoLivre(hash, pos))
    {
        copiarString(hash->tabela[pos], chave);
    }
    else
    {
        if(hash->nr < r)
        {
            copiarString(hash->tabela[m + hash->nr], chave);
            hash->nr++;
        }
        else
        {
            printf("ta cheia\n");
        }
    }
}

char *remover(Hash *hash, char chave[])
{
    int pos = hashFunc(chave);
    char *resp = NULL;

    if(iguais(hash->tabela[pos], chave))
    {
        resp = hash->tabela[pos];

        hash->tabela[pos][0] = '\0';

        for(int i = 0; i < hash->nr; i++)
        {
            int reserva = m + i;

            if(hashFunc(hash->tabela[reserva]) == pos)
            {
                copiarString(hash->tabela[pos], hash->tabela[reserva]);

                for(int j = reserva; j < m + hash->nr - 1; j++)
                {
                    copiarString(hash->tabela[j], hash->tabela[j + 1]);
                }

                hash->tabela[m + hash->nr - 1][0] = '\0';
                hash->nr--;

                i = hash->nr;
            }
        }
    }
    else
    {
        for(int i = 0; i < hash->nr; i++)
        {
            int reserva = m + i;

            if(iguais(hash->tabela[reserva], chave))
            {
                resp = hash->tabela[reserva];

                for(int j = reserva; j < m + hash->nr - 1; j++)
                {
                    copiarString(hash->tabela[j], hash->tabela[j + 1]);
                }

                hash->tabela[m + hash->nr - 1][0] = '\0';
                hash->nr--;

                i = hash->nr;
            }
        }
    }

    return resp;
}

void mostrar(Hash *hash)
{
    for(int i = 0; i < m + r; i++)
    {
        printf("%d ", i);

        if(i < m)
        {
            printf("Principal ");
        }
        else
        {
            printf("Reserva ");
        }

        if(hash->tabela[i][0] == '\0')
        {
            printf("-\n");
        }
        else
        {
            printf("%s\n", hash->tabela[i]);
        }
    }
}

int main()
{
    Hash hash;

    iniciarHash(&hash);

    inserir(&hash, "Brasil");
    inserir(&hash, "Canada");
    inserir(&hash, "Franca");

    if(pesquisar(&hash, "Brasil") != NULL)
    {
        printf("Sim\n");
    }
    else
    {
        printf("Nao\n");
    }

    remover(&hash, "Brasil");

    if(pesquisar(&hash, "Brasil") != NULL)
    {
        printf("Sim\n");
    }
    else
    {
        printf("Nao\n");
    }

    mostrar(&hash);

    return 0;
}