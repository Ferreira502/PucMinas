import java.util.Scanner;

class No
{
    public char elemento;
    public boolean folha;
    private No[] prox;

    public No()
    {
        this(' ');
    }

    public No(char elemento)
    {
        this.elemento = elemento;
        this.folha = false;
        this.prox = new No[255];
    }

    public static int hash(char c)
    {
        return (int) c;
    }

    public No getFilho(char c)
    {
        int pos = hash(c);
        No filho = prox[pos];

        return filho;
    }

    public void setFilho(No filho)
    {
        int pos = hash(filho.elemento);
        prox[pos] = filho;
    }

    private int contarFilhos()
    {
        int quantidade = 0;

        for (int i = 0; i < prox.length; i++)
        {
            if (prox[i] != null)
            {
                quantidade++;
            }
        }

        return quantidade;
    }

    public No[] getFilhos()
    {
        int quantidade = contarFilhos();
        No[] filhos = new No[quantidade];
        int j = 0;

        for (int i = 0; i < prox.length; i++)
        {
            if (prox[i] != null)
            {
                filhos[j] = prox[i];
                j++;
            }
        }

        return filhos;
    }
}

class ArvoreTrie
{
    private No raiz;

    public ArvoreTrie()
    {
        raiz = new No();
    }

    public void inserir(String s) throws Exception
    {
        if (s == null || s.length() == 0)
        {
            throw new Exception("Erro ao inserir");
        }

        inserir(s, raiz, 0);
    }

    private void inserir(String s, No i, int j) throws Exception
    {
        char c = s.charAt(j);
        No filho = i.getFilho(c);

        if (filho == null)
        {
            filho = new No(c);
            i.setFilho(filho);

            if (j == s.length() - 1)
            {
                filho.folha = true;
            }
            else
            {
                inserir(s, filho, j + 1);
            }
        }
        else if (filho.folha == false && j < s.length() - 1)
        {
            inserir(s, filho, j + 1);
        }
        else
        {
            throw new Exception("Erro ao inserir");
        }
    }

    public boolean pesquisar(String s)
    {
        boolean resp = false;

        if (s != null && s.length() > 0)
        {
            resp = pesquisar(s, raiz, 0);
        }

        return resp;
    }

    private boolean pesquisar(String s, No i, int j)
    {
        boolean resp;
        char c = s.charAt(j);
        No filho = i.getFilho(c);

        if (filho == null)
        {
            resp = false;
        }
        else if (j == s.length() - 1)
        {
            resp = filho.folha == true;
        }
        else
        {
            resp = pesquisar(s, filho, j + 1);
        }

        return resp;
    }

    public void mostrar()
    {
        mostrar("", raiz);
    }

    private void mostrar(String s, No no)
    {
        if (no != raiz)
        {
            s += no.elemento;
        }

        if (no.folha == true)
        {
            System.out.println("Palavra: " + s);
        }
        else
        {
            No[] filhos = no.getFilhos();
            int i = 0;

            while (i < filhos.length)
            {
                mostrar(s, filhos[i]);
                i++;
            }
        }
    }
}

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        ArvoreTrie arvore = new ArvoreTrie();
        boolean continuar = true;

        while (sc.hasNext() && continuar == true)
        {
            String comando = sc.next();
            char c = comando.charAt(0);

            if (c == 'I' && sc.hasNext())
            {
                String palavra = sc.next();

                try
                {
                    arvore.inserir(palavra);
                }
                catch (Exception e)
                {
                    System.out.println("Erro");
                }
            }
            else if (c == 'P' && sc.hasNext())
            {
                String palavra = sc.next();

                if (arvore.pesquisar(palavra) == true)
                {
                    System.out.println("Sim");
                }
                else
                {
                    System.out.println("Nao");
                }
            }
            else if (c == 'M')
            {
                arvore.mostrar();
            }
            else if (c == 'S')
            {
                continuar = false;
            }
        }

        sc.close();
    }
}
