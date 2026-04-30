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
