import java.util.Scanner;

class No 
{

    public int elemento;
    public int nivel;
    public No esq, dir;
    public No raiz;

    No( int elemento ) 
	{
        this.elemento = elemento;
        this.nivel = 1;
        this.esq = null;
        this.dir = null;
        this.raiz = null;
    }

    public int getNivel(No i) 
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

        int nivelEsq = getNivel(this.esq);
        int nivelDir = getNivel(this.dir);

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

    public int getBalanceamento() 
	{
        int nivelEsq = getNivel(this.esq);
        int nivelDir = getNivel(this.dir);

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

    public void inserir( int x ) 
	{
        raiz = inserir(raiz, x);
    }

    private No inserir( No i, int x ) 
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

        return balancear(i);
    }

    public void caminharCentral() 
	{
        caminharCentral(raiz);
    }

    private void caminharCentral(No i) 
	{
        if ( i != null ) 
		{
            caminharCentral(i.esq);
            //System.out.println(i.elemento + "" + "( " + i.getBalanceamento() + ")");
            
            System.out.println(i.elemento + "" + "( " + i.nivel + ")");
            caminharCentral(i.dir);
        }
    }

    public No rotacionarEsq ( No i )
    {
        No noDir = i.dir;
        No noDirEsq = noDir.esq;

        noDir.esq = i;
        i.dir = noDirEsq;

        
		i.setNivel();
		noDir.setNivel();

        return noDir;
    }

    public No rotacionarDir ( No i )
    {
        No noEsq = i.esq;
        No noEsqDir = noEsq.dir;

        noEsq.dir = i;
        i.esq = noEsqDir;

        i.setNivel();
		noEsq.setNivel();

        return noEsq;
   }

   private No balancear ( No i )
   {
        // System.out.println ("Cheguei aq balancear");
        int fator = i.getBalanceamento();
        
        if ( fator == 2 )
        {
            int fatorFilhoDir = i.dir.getBalanceamento();
            
            if ( fatorFilhoDir < 0 )
            {
                i.dir = rotacionarDir(i.dir);
            }

            i = rotacionarEsq(i);
        }

        else if ( fator == -2 )
        {
            int fatorFilhoEsq = i.esq.getBalanceamento(); 

            if ( fatorFilhoEsq > 0 )
            {
                i.esq = rotacionarEsq(i.esq);
            }
            
            i = rotacionarDir(i);

        }
    
        i.setNivel();
        return i;
   }        
}

public class Main 
{

    public static void main(String[] args) 
	{
        ArvoreAvl av = new ArvoreAvl();
		Scanner sc = new Scanner(System.in);

		String palavra;
		palavra = sc.next();
		char c = palavra.charAt(0);

		while ( c != 'S' )
		{
			int x = 0;

			if ( c == 'I')
			{
				x = sc.nextInt();
				av.inserir(x);
				System.out.println("Voce inseriu o: " + x);
			}

			if ( c == 'C' )
			{
				av.caminharCentral();
			} 

			palavra = sc.next();
			c = palavra.charAt(0);
		}

        // av.inserir(4);
        // av.inserir(35);
        // av.inserir(10);
        // av.inserir(13);
        // av.inserir(3);
        // av.inserir(30);
        // av.inserir(15);
        // av.inserir(12);
        // av.inserir(7);
        // av.inserir(40);
        // av.inserir(20);

        // av.caminharCentral();
        // resultado caminhar -> 5, 10, 20, 25, 30, 40, 50
        // resultado nuvel -> 1, 2, 4, 1, 3, 2, 1
    }
}