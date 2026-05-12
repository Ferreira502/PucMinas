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

typedef struct ArvoreBinaria
{
	No* raiz;
} ArvoreBinaria;
 
ArvoreBinaria* novo_arvore_binaria()
{
	ArvoreBinaria* novo_arvore = (ArvoreBinaria*) malloc (sizeof(ArvoreBinaria));
	novo_arvore->raiz = NULL;
	return novo_arvore;
}

void inserir ( ArvoreBinaria* ab, int x)
{
	inserir(raiz,x);
}


void inserirRec ( ArvoreBinaria* ab, int x )
{
	if ( novo_arvore->elemento == x )
	{
		ArvoreBinaria* ab = (ArvoreBinaria*) malloc (sizeof(x));
	}

	else if ( x > novo_arvore->elemento )
	{
		novo_arvore>dir = inserir(ab->dir, x);
	}

	else if ( x < novo_arvore->elemento )
	{
		ab->esq = inserir(ab->esq, x);
	}
}

int pesquisar( ArvoreBinaria* ab, int x )
{
	bool resp = false;
	if ()
	{}
}

//int main ()
//{}
