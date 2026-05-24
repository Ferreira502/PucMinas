class No 
{
    private int elemento;
    private int altura;
    private No esq, dir;

    public No(int elemento) 
    {
        this.elemento = elemento;
        this.altura = 1;
        this.esq = null;
        this.dir = null;
    }

    public int getAltura()       
    { 
        return altura; 
    }

    public void setAltura(int h) 
    { 
        altura = h; 
    }

    public No getEsq()           
    { 
        return esq; 
    }

    public No getDir()           
    { 
        return dir; 
    }
}

class ArvoreAVL 
{
    private No raiz;

    public ArvoreAVL() 
    {
        raiz = null;
    }

    int getAltura(No i) 
    {
        if (i == null) 
        {
            return 0;
        }

        return i.getAltura();
    }

    public int fatorBalanceamento(No i) 
    {
        if (i == null) 
        {
            return 0;
        }
        
        return getAltura(i.getEsq()) - getAltura(i.getDir());
    }
}