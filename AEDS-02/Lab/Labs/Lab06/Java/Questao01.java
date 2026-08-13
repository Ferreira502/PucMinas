import java.util.*;

class Fila 
{
    private Celula primeiro;
    private Celula ultimo;

    public Fila() 
    {
		primeiro = new Celula();
		ultimo = primeiro;
    }

    public void inserir ( int x )
    {   
        ultimo.prox = new Celula(x);
        ultimo = ultimo.prox;
    }

    public int remover()
    {
	    int resp;

        if ( primeiro == ultimo )
        {
           resp = -1;
        }

	    else 
	    {
        	Celula tmp = primeiro;
        	primeiro = primeiro.prox;
        	int elemento = primeiro.elemento;
		    tmp.prox = null;
        	tmp = null;
        	resp =  elemento;
	    }

	    return resp;
    }

    public void mostrar()
    {
        for ( Celula i = primeiro.prox; i != null; i = i.prox )
        {
            System.out.print(i.elemento + " ");
        }

        System.out.println("");
    }

    public boolean pesquisar ( int x )
    {
        boolean resp = false;

        for ( Celula i = primeiro.prox; i != null; i = i.prox )
        {
            if ( i.elemento == x )
            {
                resp = true;
            }
        }

        return resp;
    }

}

class Celula 
{
    public int elemento;
    public Celula prox;

    public Celula ()
    {
        this(0);
    }

    public Celula( int elemento ) 
    {
        this.elemento = elemento;
        this.prox = null;
	}
}


class Questao01 
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