class No 
{
    public int elemento;
    public int nivel;
    public No esq, dir;
    public No raiz;

    No ( int elemento )
    {
    	this.elemento = elemento;
	this.nivel = 1;
	this.esq = null;
	this.dir = null;
	this.raiz = null;
    }


    public int getNivel ( No i )
    {
	int x = 0;

	if ( i != null )
	{
		x = i.nivel;	
	}

	return x;
    }

    public void setNivel()
    {
	int x = 1;

	int nivelEsq = getNivel( this.esq );
	int nivelDir = getNivel( this.dir );

	if ( nivelEsq > nivelDir )
	{
		x = nivelEsq + x;
	}

	else
	{
		x = nivelDir + x;
	}


	this.nivel = x;
    }

    public getBalanceamento()
    {
    	int nivelEsq = getNivel( this.esq );
	int nivelDir = getNivel( this.dir );

	return nivelDir - nivelEsq;
    }    
}

class ArvoreAvl
{
   public No raiz;

   public ArvoreAvl()
   {
   	raiz = null;
   }

   public void inserir ( int x )
   {
	   raiz = inserir ( raiz, x );
   }

   private No inserir ( No i, int x )
   {
   	if ( i == null )
	{
		i = new No(x);
	}

	else if ( i.elemento < x )
	{
		i.dir = inserir(i.dir, x);
	}

	else if ( i.elemento > x ) 
	{
		i.esq = inserir(i.esq, x);
	}

	i.setNivel();
	return i;
   }

   public void caminharCentral ()
   {
   	caminharCentral(raiz);
   }

   private void caminharCentral ( No i )
   {
   	if ( i != null )
	{
		caminharCentral(i.esq);
		System.out.println(i.elemento + "" + "( " + i.nivel + ")" );
		caminharCentral(i.dir);
	}
   }

/*
   public No rotacionarEsq ( No i )
   {
   	No noDir = i.dir;
	No noDirEsq = i.esq;

	noDir.esq = i;
	i.dir = noDirEsq;

	return noDir;
   }

   public No rotacionarDir ( No i )
   {
   	No noEsq = i.esq;
	No noEsqDir = noEsq.dir;

	noEsq.dir = no;
	no.esq = noEsqDir;

	return noEsq;
   }
 */
}

public class Main
{
	public static void main(String[] args)
	{
		ArvoreAvl av = new ArvoreAvl();

		av.inserir(20);
		av.inserir(10);
		av.inserir(30);
		av.inserir(5);
		av.inserir(25);
		av.inserir(40);
		av.inserir(50);

		av.caminharCentral();
		// resultado caminhar -> 5, 10, 20, 25, 30, 40, 50
		// resultado nuvel -> 1, 2, 4, 1, 3, 2, 1
	}
}
