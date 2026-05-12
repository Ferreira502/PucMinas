import java.util.*;

class Main 
{
	public void Main ( String[] args )
	{
		Scanner sc = new Scanner(System.in);

		ArvoreBinaria arvore = new ArvoreBinaria();

		while ( sc.hasNext() )
		{
			String op = sc.next();
			int num = 0;

			if ( op.compareTo("P") == 0 )
			{
				num = sc.nextInt();

				boolean resp = arvore.pesquisar( num );

				if ( resp == true)
				{
					System.out.println("S");
				}

				else 
				{
					System.out.println("N");
				}
				
			}

			if ( op.compareTo("I") == 0)
			{
				num = sc.nextInt();

				arvore.inserir(num);
			}

			if ( op.compareTo("EM") == 0)
			{
				arvore.caminharCentral();
			}

			if ( op.compareTo("POS") == 0)
			{
				arvore.caminharPos();
			}

			if ( op.compareTo("PRE") == 0)
			{
				arvore.caminharPre();
			}		
		}
	}
}
