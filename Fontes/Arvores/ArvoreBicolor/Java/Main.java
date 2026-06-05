import java.util.*;

class No
{
    public int elemento;    
    public boolean cor;     
    public No esq, dir;      
    
    public No( int elemento ) 
	{
        this.elemento = elemento;
        this.cor = true;
        this.esq = null;
        this.dir = null;
    }

    public boolean isNoTipoQuatro ( )
    {
        return (esq != null && dir != null && esq.cor == true && dir.cor == true);
    }
}

class ArvoreBicolor
{
    public No raiz;

    public ArvoreBicolor()
    {
        raiz = null;
	raiz.cor = false;
    }

    private void fragmentar( No i )
    {
	    if ( i == raiz )
	    {
	    	i.cor = false;
		i.esq.cor = false;
		i.dir.cor = false;
	    }

	    else
	    {
	    	i.cor = true;
		i.esq.cor = false;
		i.dir.cor = false;
	    } 
    }
   
    public No rotacionarSimplesEsq( No i )
    {
    	No noDir = i.dir; 		// cria um ponteiro para pegar o no da direita que queremos balancear
	No noDirEsq = noDir.esq;   	// cria um ponteiro para pegar o no da esquerda do ponteiro criado
	noDir.esq = i;			// pega o no da direita a esquerda dele aponta para i
	i.dir = noDirEsq;		// direita do no inicial aponta para o no a esquerda do direita
	
	return noDir;			// retorna o no da direita
    }

    public No rotacionarSimplesDir ( No i ) 
    {
    	No noEsq = i.esq;
	No noEsqDir = noEsq.dir;
	noEsq.dir = i;
	i.esq = noEsqDir;

	return noEsq;
    }	    

    public No rotacionarDirEsq( No i )
    {
    	i.dir = rotacionarSimplesDir(i.dir);
	return rotacionarSimplesEsq(i);
    }

    public No rotacionarEsqDir ( No i )
    {
    	i.esq = rotacionarSimplesEsq(i.esq);
	return rotacionarSimplesDir(i);
    }

    private void balancear ( No bisavo, No avo, No pai, No i ) 
    {
    	No novaRaiz = null;

	if ( pai.elemento > avo.elemento && i.elemento > pai.elemento )
	{
		novaRaiz = rotacionarSimplesEsq(i); 
	}

	else if ( pai.elemento > avo.elemento && i.elemento < pai.elemento )
	{
		novaRaiz = rotacionarDirEsq(i);
	}

	else if ( pai.elemento < avo.elemento && i.elemento < pai.elemento )
	{
		novaRaiz = rotacionarSimplesDir(i);
	}	
	
	else if ( pai.elemento < avo.elemento && i.elemento > pai.elemento )
	{
		novaRaiz = rotacionarEsqDir(i);
	}

	if ( bisavo != null )
	{
		if ( bisavo.elemento > novaRaiz.elemento )
		{
			bisavo.esq = novaRaiz;
		}

		else 
		{
			bisavo.dir = novaRaiz;
		}
	}

	else 
	{
		raiz = novaRaiz;
	}

	novaRaiz.cor = false;
	novaRaiz.dir.cor = true;
	novaRaiz.esq.cor = true;
	
    }

    public void inserir( int x );
    {
    	if ( raiz == null )
	{
		raiz = new No(x);
	}

	else
	{
		inserir(x, null, null, null, raiz);
	}
    }

    private void inserir ( int x, No bisavo, No avo, No pai, No i )
    {

	if ( i == null )
	{
		i = new No(x, true);
		if ( x < pai.elemento ) 
		{
			pai.esq = i;
		}

		else
		{
			pai.dir = i;
		}

		if ( pai.cor == true )
		{
			balancear(bisavo, avo, pai, i);
		}
	}

	else
	{
		if ( i.isNoTipoQuatro() )
		{
			fragmentar(i);

			if ( pai != null && pai.cor == true )
			{
				balancear(bisavo, avo, pai, i);
			}
		}

    		if ( x > i.elemento )
		{
			inserir(x, avo, pai, i, i.dir);
		}
	
		else if ( x < i.elemento )
		{
			i.esq = inserir(x, avo, pai, i, i.esq);
		}

	}
    }
}

class Main
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        ArvoreBicolor ab = new ArvoreBicolor();

    }
}
