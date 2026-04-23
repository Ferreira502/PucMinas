import java.util.*;


class Pilha
{
	private int T;
	private int topo;
	private int array[];

	public Pilha(int tamanho)
	{
		this.T = tamanho;
		this.array = new int [T];
		this.topo = 0;
	} //constroi a pilha com capacidade máxima igual a tamanho

	public void empilhar(int x) 
	{
		if ( topo >= array.length )
		{
			System.out.println("Erro");
			return;
		}

		array[topo] = x;
		topo++;

	} //empilha x à pilha

	public int desempilhar() 
	{
		if ( topo == 0 )
		{
			System.out.println("Erro");
			return 0;
		}

		return array[--topo];

	}//desempilha da pilha e retorna o elemento desempilhado

	public void mostrar() 
	{
		for ( int i = topo - 1; i >= 0; i--)
		{
			System.out.println("" + array[i]);
		}
	} //imprime os elementos da pilha partindo do topo

	public boolean pesquisar(int x)
       	{
		boolean retorno = false;
	 	for ( int i = 0; i < topo && retorno == false; i++)
		{
			retorno = (array[i] == x);
		}	

		return retorno;
	} //retorna true caso o elemento x esteja na pilha e false caso contrário

}

class Main
{
      public static void main ( String[] args ) 
      {
      	System.out.println("==== Pilha ESTATICA ====");
      	Pilha pilha = new Pilha(5);
      	int x1, x2, x3;

      	pilha.empilhar(5);
      	pilha.empilhar(7);
      	pilha.empilhar(8);
      	pilha.empilhar(9);

      	System.out.println("Apos insercoes(5, 7, 8, 9): ");
      	pilha.mostrar();

     	x1 = pilha.desempilhar();
      	x2 = pilha.desempilhar();

      	System.out.println("Apos remocoes (" + x1 + ", " + x2 + "):");
      	pilha.mostrar();

      	pilha.empilhar(3);
      	pilha.empilhar(4);


      	System.out.println("Apos insercoes(3, 4): ");
      	pilha.mostrar();

      	x1 = pilha.desempilhar();
      	x2 = pilha.desempilhar();
      	x3 = pilha.desempilhar();

      	System.out.println("Apos remocoes (" + x1 + ", " + x2 + ", " + x3 + "):");
      	pilha.mostrar();

      	pilha.empilhar(4);
      	pilha.empilhar(5);

      	System.out.println("Apos insercoes(4, 5): ");
      	pilha.mostrar();

      	x1 = pilha.desempilhar();
      	x2 = pilha.desempilhar();

      	System.out.println("Apos remocoes (" + x1 + ", " + x2 + "):");
      	pilha.mostrar();

      	pilha.empilhar(6);
      	pilha.empilhar(7);

      	System.out.println("Apos insercoes(6, 7): ");
      	pilha.mostrar();

      	x1 = pilha.desempilhar();

      	System.out.println("Apos remocao (" + x1 + "): ");
      	pilha.mostrar();
   }
}

