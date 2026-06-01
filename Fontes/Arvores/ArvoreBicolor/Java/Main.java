import java.util.Scanner;

class No
{
    public int elemento;    
    public boolean cor;     
    public No esq, dir;      
    
    public No( int elemento ) 
	{
        this.elemento = elemento;
        this.cor = false;
        this.esq = null;
        this.dir = null;
    }

    public boolean isNoTipoQuatro ( No i )
    {
        return (i.esq != null && i.dir != null && i.esq.cor == true && i.dir.cor == true);
    }

    public void fragmentarNoTipoQuatro ( No i )
    {
        i.cor = true;
        i.esq.cor = false;
        i.dir.cor = false;
    }
}

class ArvoreBicolor
{
    public No raiz;

    public ArvoreBicolor()
    {
        raiz = null;
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