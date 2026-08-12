#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No
{
    int elemento;
    struct No *esq, *dir;
} No;

No* novo_no ( int elemento )
{
    No* novo = (No*) malloc ( sizeof(No) );
    novo->elemento = elemento;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void delete_no ( No* no )
{
    free(no);
}

typedef struct ArvoreBinaria
{
    No* raiz;
} ArvoreBinaria;

ArvoreBinaria* novo_arvore_binaria ()
{
    ArvoreBinaria* novo_arvore = (ArvoreBinaria*) malloc ( sizeof(ArvoreBinaria) );
    novo_arvore->raiz = NULL;
    return novo_arvore;
}

void delete_arvore_binaria_rec ( No* no )
{
    if ( no == NULL )
	{
        return;
	}

    delete_arvore_binaria_rec(no->esq);
    delete_arvore_binaria_rec(no->dir);
    delete_no(no);
}

void delete_arvore_binaria ( ArvoreBinaria* ab )
{
    delete_arvore_binaria_rec(ab->raiz);
    free(ab);
}

No* inserir_rec ( No* no, int x )
{
    if ( no == NULL )
	{
        return novo_no(x);
	}

    else if ( x < no->elemento )
	{
        no->esq = inserir_rec(no->esq, x);
	}

    else if ( x > no->elemento )
	{
        no->dir = inserir_rec(no->dir, x);
	}

    return no;
}

void inserir ( ArvoreBinaria* ab, int x )
{
    ab->raiz = inserir_rec(ab->raiz, x);
}

int pesquisar_rec ( No* no, int x )
{
    if ( no == NULL )
	{
        return 0;
	}

    printf("%d ", no->elemento);

    if ( no->elemento == x )
	{
        return 1;
	}

    else if ( x > no->elemento )
	{
        return pesquisar_rec(no->dir, x);
	}

    else
	{
        return pesquisar_rec(no->esq, x);
	}
}

int pesquisar ( ArvoreBinaria* ab, int x )
{
    int resp = pesquisar_rec(ab->raiz, x);

    if ( resp )
	{
        printf("S\n");
	}

    else
	{
        printf("N\n");
	}
    return resp;
}

void caminhar_pre_rec ( No* no )
{
    if ( no == NULL )
	{
        return;
	}

    printf("%d ", no->elemento);
    caminhar_pre_rec(no->esq);
    caminhar_pre_rec(no->dir);
}

void caminhar_pre ( ArvoreBinaria* ab )
{
    if ( ab->raiz == NULL )
	{
        printf("V\n");
	}

    else
    {
        caminhar_pre_rec(ab->raiz);
        printf("\n");
    }
}

void caminhar_pos_rec ( No* no )
{
    if ( no == NULL )
	{
        return;
	}

    caminhar_pos_rec(no->esq);
    caminhar_pos_rec(no->dir);
    printf("%d ", no->elemento);
}

void caminhar_pos ( ArvoreBinaria* ab )
{
    if ( ab->raiz == NULL )
	{
        printf("V\n");
    }
	
	else
    {
        caminhar_pos_rec(ab->raiz);
        printf("\n");
    }
}

void caminhar_em_rec ( No* no )
{
    if ( no == NULL )
	{
        return;
	}

    caminhar_em_rec(no->esq);
    printf("%d ", no->elemento);
    caminhar_em_rec(no->dir);
}

void caminhar_em ( ArvoreBinaria* ab )
{
    if ( ab->raiz == NULL )
	{
        printf("V\n");
	}

    else
    {
        caminhar_em_rec(ab->raiz);
        printf("\n");
    }
}

int main ()
{
    ArvoreBinaria* ab = novo_arvore_binaria();
    char op[4];

    while ( scanf("%s", op) != EOF )
    {
        if ( op[0] == 'I' )
        {
            int x;
            scanf("%d", &x);
            inserir(ab, x);
        }
        
		else if ( op[0] == 'P' && op[1] == '\0' )
        {
            int x = 0;
            scanf("%d", &x);
            pesquisar(ab, x);
        }

        else if ( op[0] == 'P' && op[1] == 'R' )
		{
            caminhar_pre(ab);
		}

        else if ( op[0] == 'P' && op[1] == 'O' )
		{
            caminhar_pos(ab);
		}

        else if ( op[0] == 'E' )
		{
            caminhar_em(ab);
		}
    }

    delete_arvore_binaria(ab);
}