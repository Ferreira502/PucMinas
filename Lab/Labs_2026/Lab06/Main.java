import java.util.*;

class Main 
{
    public static void main( String[] args ) 
    {
        Scanner sc = new Scanner(System.in);
        Fila fila = new Fila();
        
        String letra;
        int resposta = 0;
        int x = 0;
        
	while ( ( sc.hasNext()) )
	{
		letra = sc.next();
		char op = letra.charAt(0);

        	if ( op == 'D' )
        	{
            		resposta = fila.remover();
			System.out.println("" + resposta);
        	}

		else if ( op == 'E')
        	{
			x = sc.nextInt();
            		fila.inserir(x);
       	 	} 

		else if ( op == 'M')
        	{
            		fila.mostrar();
        	}

		else if ( op  == 'P')
		{
			boolean resp;
			x = sc.nextInt();
			resp = fila.pesquisar(x);

			if ( resp == true )
			{
				System.out.println("S");
			}

			else 
			{
				System.out.println("N");
			}
		}

    	}   
    }
}
