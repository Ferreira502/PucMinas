import java.util.Scanner;

class No 
{
    public int elemento;
    public No esq, dir;

    public No ( int elemento )
    {
        this.elemento = elemento;
        esq = dir = null;
    }
}

class ArvoreAVL
{
    private No raiz;

    public ArvoreAVL()
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

        else if ( x > i.elemento )
        {
            i.dir = inserir( i.dir, x );
        }

        else if ( x < i.elemento )
        {
            i.esq = inserir ( i.esq, x );
        }

        return i;
    }

    public boolean pesquisar ( int x )
    {
        return pesquisar( raiz, x );
    }  

    private boolean pesquisar ( No i, int x )
    {
        boolean resp = false;

        if ( x == i.elemento )
        {
            resp = true;
        }

        else if ( x < i.elemento )
        {
            resp = pesquisar( i.esq , x );
        }

        else if (  x > i.elemento )
        {
            resp = pesquisar( i.dir, x );
        }

        return resp;
    }

    public void caminharCentral ( )
    {
		caminharCentral(raiz);
    }

    private void caminharCentral ( No i )
    {
        if ( i != null )
        {
            caminharCentral(i.esq);
            System.out.println(i.elemento + "");
            caminharCentral(i.dir);
        }
    }
}

class Main
{
    public static void main( String[] args ) 
    {
        Scanner sc = new Scanner( System.in );
        ArvoreAVL avl = new ArvoreAVL();

        avl.inserir(5);
        avl.inserir(4);
        avl.inserir(25);
        avl.inserir(2);

        avl.caminharCentral();
    }
}

