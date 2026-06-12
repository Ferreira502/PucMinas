
import java.util.Scanner;


class No
{
    public char elemento;
    public int tamanho = 255;
    public No[] prox;
    public boolean folha;

    public No ( char elemento )
    {
        this.elemento = elemento;
        prox = new No [tamanho];
        for (int i = 0; i < tamanho; i++) prox[i] = null;
        folha = false;
   }

   
   public No ()
   {
      this(' ');
   }

   public static int hash ( char x )
   {
        return (int)x;
   }
}

class ArvoreTrie
{
    private No raiz;
    
    public ArvoreTrie()
    {
        raiz = new No( );
    }
    
    public void inserir( String palavra ) throws Exception
    {
        inserir(palavra, raiz, 0);
    }


    public void inserir ( String palavra, No i, int x)  throws Exception
    {
        char c = palavra.charAt(x);

        if ( i.prox [c] == null )
        {
            i.prox[c] = new No(c);

            if ( x == palavra.length() - 1 )
            {
                i.prox[c].folha = true;
            }

            else 
            {
                inserir( palavra, i.prox[c], x + 1 );
            }
        }

        else if ( i.prox[c].folha == false && x < palavra.length() - 1 )
        {
            inserir(palavra, i.prox[c], x + 1);
        }

        else 
        {
            throw new Exception("Erro");   
        }
    }
    
    public boolean pesquisar( String palavra ) throws Exception 
    {
        return pesquisar( palavra, raiz, 0 );
    }

    public boolean pesquisar ( String palavra, No i, int x ) throws  Exception
    {
        char c = palavra.charAt(x);
        boolean resp = false;

        if ( i.prox[c] == null )
        {
            resp = false; 
        }

        else if ( x == palavra.length() - 1 )
        {
            resp = ( i.prox[c].folha == true );
        }

        else if ( x < palavra.length() - 1 )
        {
            resp = pesquisar(palavra, i.prox[c], x + 1 );
        }

        else 
        {
            throw new Exception ("Erro");
        }

        return resp;
    }

    public void mostrar()
    {
        mostrar("", raiz);
    }

    public void mostrar( String palavra, No i ) 
    {
        if(i.folha == true)
        {
            System.out.println("Palavra: " + ( palavra + i.elemento));
        } 

        else 
        {
            for( int j = 0; j < i.prox.length; j++ )
            {
                
                if( i.prox[j] != null )
                {
                    mostrar( palavra + i.elemento, i.prox[j] );
                }
            }
        }
    }   
}

class Main 
{
   public static void main ( String[] args ) throws Exception
   {
        Scanner sc = new Scanner( System.in );

        ArvoreTrie arv = new ArvoreTrie();

        String array[] = new String[100];
        int x = 0; 
        
        x = sc.nextInt();

        for ( int i = 0; i < x; i++ )
        {
            array[i] = sc.next();
        }

        
        int y = 0;

        while ( sc.hasNext() || y != x ) 
        {
            String palavra02;
            palavra02 = sc.next();

            y++;
        }

        // array[0] = "ABACAXI";
        // array[1] = "BALA";
        // array[2] = "BOLO";
        // array[3] = "ABACATE";
        // array[4] = "galo";
        // array[5] = "pata";
        // array[6] = "pato";
        // array[7] = "gato";
        // for( int i = 0; i < array.length; i++ )
        // {
        //         arv.inserir(array[i]);
        // }
        // arv.mostrar();
    /*
        for(int i = 0; i < array.length; i++){
            System.out.println("Pesquisar(" + array[i] + "):" + arv.pesquisar(array[i]));
        }
        String s = "ABACA";
        System.out.println("Pesquisar(" + s + "):" + arv.pesquisar(s));
        s = "ABACAXIS";
        System.out.println("Pesquisar(" + s + "):" + arv.pesquisar(s));
        s = "gaga";
        System.out.println("Pesquisar(" + s + "):" + arv.pesquisar(s));
    */
      
   }
}
