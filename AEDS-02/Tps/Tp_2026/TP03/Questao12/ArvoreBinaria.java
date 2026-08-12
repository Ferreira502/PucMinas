class ArvoreBinaria
{
	private No raiz;

	public ArvoreBinaria()
       	{
		raiz = null;
	}

	public void inserir ( int x )
	{
		raiz = inserir( raiz, x );
	}
	
	private No inserir ( No i, int x)
	{
		if ( i == null )
		{
			i = new No(x);
		}

		else if ( x > i.elemento )
		{
			i.dir = inserir( i.dir, x );
		}

		else if ( x < i.elemento )
		{
			i.esq = inserir( i.esq, x );
		}

		else 
		{
			System.out.println ( "Erro" );
		}
		
		return i;
	}

	public boolean pesquisar ( int x )
	{
		  return pesquisar( raiz, x );
	}

	public boolean pesquisar ( No i, int x )
	{
		boolean resp = false;

		if ( i == null )
		{
			resp = false;
		}

		else if ( i.elemento == x )
		{
			resp = true;
		}

		else if ( x > i.elemento )
		{
			System.out.println( i.elemento + "" );
			resp = pesquisar( i.dir, x );
		}
		
		else if ( x < i.elemento )
		{
			System.out.println(i.elemento + "");
			resp = pesquisar ( i.esq, x );
		}

		return resp;	
	}


	public void caminharCentral()
	{
		if ( raiz == null )
		{
			System.out.println("V");
		}

		else 
		{
			caminharCentral(raiz);
			System.out.println();
		}
	}

	private void caminharCentral( No i )
	{
		if (i != null)
		{
			caminharCentral(i.esq);
			System.out.println(i.elemento + "");
			caminharCentral(i.dir);
		}
	}

	public void caminharPre()
	{
		if ( raiz == null )
		{
			System.out.println("V");
		}

		else
	       	{
			caminharPre(raiz);
			System.out.println();
		}
	}

	private void caminharPre( No i )
	{
		if ( i != null )
		{
			System.out.println( i.elemento + "" );
			caminharPre(i.esq);
			caminharPre(i.dir);
		}
	}

	public void caminharPos()
	{
		if ( raiz == null )
		{
			System.out.println("V");
		}
	
		else 
		{
			caminharPos(raiz);
			System.out.println();
		}

	}

	private void caminharPos( No i )
	{
		if ( i != null )
		{
			caminharPos(i.esq);
			caminharPos(i.dir);
			System.out.println(i.elemento + "");
		}
	}

}
