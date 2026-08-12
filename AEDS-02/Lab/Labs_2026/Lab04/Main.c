#include<stdio.h>

	typedef struct
	{
		int T;
		int topo;
		int *array;
	} Pilha;

	Pilha* newPilha(int tamanho)
	{ 
		Pilha *p = (Pilha * ) malloc (sizeof(Pilha));
		p->topo = 0;
		p->T = tamanho;
		p->array ( int * ) malloc (sizeof(Pilha));
	} //constroi a pilha com capacidade máxima igual a tamanho e retorna o ponteiro para a pilha
	
	void delPilha(Pilha* p)
	{ 
		
	} //desaloca da memória a pilha p (atenção, o arranjo também deve ser desalocado)
	
	void empilhar(Pilha* p, int x)
	{
		if ( p->topo <= p->T)
		{
			p->array[++(p->topo)] = x;
		}

	} //empilha x à pilha p
	
	int desempilhar(Pilha* p) 
	{
		if( p->topo >= 0 )
		{
			return p->array[(p->topo)--];	
		}	
	} //desempilha da pilha p e retorna o elemento desempilhado
	
	void mostrar(Pilha* p) { } //imprime os elementos da pilha p partindo do topo
	
	int pesquisar(Pilha* p, int x) { } //retorna true caso o elemento x esteja na pilha p e false caso contrário

int main ()
{

}
