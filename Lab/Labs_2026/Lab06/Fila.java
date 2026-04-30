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
        // esta faltando  andar Com o Primeiro 
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
	for ( Celula i = primeiro; i != null; i = i.prox )
	{
		if ( i.elemento == x )
		{
			resp = true;
		}
	}

	return resp;
    }

}
