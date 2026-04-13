import java.util.*;


class Pilha
{
	private int T;
	private topo;
	private array[];

	public Pilha(int tamanho)
	{
		this.T = tamanho;
	} //constroi a pilha com capacidade máxima igual a tamanho

	public void empilhar(int x) 
	{
		if ( topo >= array.length )
		{
			System.out.println("Erro");
		}

		array[topo] = x;
		topo++;

	} //empilha x à pilha

	public int desempilhar() 
	{
		if ( topo >= array.length || topo == 0 )
		{
			System.out.println("Erro");
		}

		return array[--topo];

	}//desempilha da pilha e retorna o elemento desempilhado

	public void mostrar() 
	{
		for ( int i = 0; i < T; i++)
		{
			System.out.println("" + array[i]);
		}
	} //imprime os elementos da pilha partindo do topo

	public boolean pesquisar(int x)
       	{
		boolean retorno = false;
	 	for ( int i = 0; i < T && retorno == false; i++)
		{
			retorno = (array[i] == x);
		}	

		return retorno;
	} //retorna true caso o elemento x esteja na pilha e false caso contrário

}

class Main
{

}

