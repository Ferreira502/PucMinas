import java.io.PrintWriter;
import java.util.Scanner;

class No
{
    public Restaurante elemento;
    public int nivel;
    public No esq, dir;

    public No( Restaurante elemento )
    {
        this.elemento = elemento;
        this.nivel = 1;
        this.esq = null;
        this.dir = null;
    }

    public int getNivel( No i )
    {
        int resp = 0;

        if ( i != null )
        {
            resp = i.nivel;
        }

        return resp;
    }

    public void setNivel()
    {
        int nivelEsq = getNivel(this.esq);
        int nivelDir = getNivel(this.dir);

        if ( nivelEsq > nivelDir )
        {
            this.nivel = nivelEsq + 1;
        }
        else
        {
            this.nivel = nivelDir + 1;
        }
    }

    public int getBalanceamento()
    {
        return getNivel(this.dir) - getNivel(this.esq);
    }
}

class ArvoreAvl
{
    private No raiz;
    private int comparacoes;

    public ArvoreAvl()
    {
        raiz = null;
        comparacoes = 0;
    }

    public int getComparacoes()
    {
        return comparacoes;
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @param restaurante restaurante a ser inserido
     * @reason Insere um restaurante na AVL usando o nome como chave
     */
    public void inserir( Restaurante restaurante )
    {
        raiz = inserir(raiz, restaurante);
    }

    private No inserir( No i, Restaurante restaurante )
    {
        if ( i == null )
        {
            i = new No(restaurante);
        }
        else if ( restaurante.getNome().compareTo(i.elemento.getNome()) > 0 )
        {
            i.dir = inserir(i.dir, restaurante);
        }
        else if ( restaurante.getNome().compareTo(i.elemento.getNome()) < 0 )
        {
            i.esq = inserir(i.esq, restaurante);
        }

        return balancear(i);
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @param nome nome pesquisado na AVL
     * @reason Pesquisa um restaurante pelo nome e imprime o caminho percorrido
     */
    public void pesquisar( String nome )
    {
        pesquisar(raiz, nome, true);
    }

    private void pesquisar( No i, String nome, boolean raizFlag )
    {
        if ( i == null )
        {
            System.out.println(" NAO");
        }
        else
        {
            comparacoes++;
            int cmp = nome.compareTo(i.elemento.getNome());

            if ( raizFlag )
            {
                System.out.print("raiz");
            }

            if ( cmp == 0 )
            {
                System.out.println(" SIM");
            }
            else if ( cmp > 0 )
            {
                System.out.print(" dir");
                pesquisar(i.dir, nome, false);
            }
            else
            {
                System.out.print(" esq");
                pesquisar(i.esq, nome, false);
            }
        }
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Mostra os restaurantes em ordem alfabetica pelo nome
     */
    public void caminharCentral()
    {
        if ( raiz == null )
        {
            System.out.println("V");
        }
        else
        {
            caminharCentral(raiz);
        }
    }

    private void caminharCentral( No i )
    {
        if ( i != null )
        {
            caminharCentral(i.esq);
            System.out.println(i.elemento.formatar());
            caminharCentral(i.dir);
        }
    }

    private No rotacionarEsq( No i )
    {
        No noDir = i.dir;
        No noDirEsq = noDir.esq;

        noDir.esq = i;
        i.dir = noDirEsq;

        i.setNivel();
        noDir.setNivel();

        return noDir;
    }

    private No rotacionarDir( No i )
    {
        No noEsq = i.esq;
        No noEsqDir = noEsq.dir;

        noEsq.dir = i;
        i.esq = noEsqDir;

        i.setNivel();
        noEsq.setNivel();

        return noEsq;
    }

    private No balancear( No i )
    {
        if ( i != null )
        {
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
        }

        return i;
    }
}

public class Questao01
{
    /**
     * @author Gabriel Ferreira Pereira
     * @reason Insere restaurantes em uma arvore AVL por nome,
     *         pesquisa chaves e exibe caminhamento em ordem
     */
    public static void main( String[] args ) throws Exception
    {
        ColecaoRestaurante colecao = ColecaoRestaurante.lerCsv();
        Restaurante[] restaurantes = colecao.getRestaurantes();
        Scanner sc = new Scanner(System.in);
        ArvoreAvl arvore = new ArvoreAvl();

        int id = sc.nextInt();

        while ( id != -1 )
        {
            for ( int i = 0; i < colecao.getTamanho(); i++ )
            {
                if ( restaurantes[i].getID() == id )
                {
                    arvore.inserir(restaurantes[i]);
                    i = colecao.getTamanho();
                }
            }

            id = sc.nextInt();
        }

        sc.nextLine();

        long inicio = System.nanoTime();
        String nome = sc.nextLine();

        while ( nome.compareTo("FIM") != 0 )
        {
            arvore.pesquisar(nome);
            nome = sc.nextLine();
        }

        long fim = System.nanoTime();
        double tempo = (fim - inicio) / 1000000000.0;

        arvore.caminharCentral();

        PrintWriter log = new PrintWriter("842527_arvore_avl.txt");
        log.printf("842527\t%d\t%f%n", arvore.getComparacoes(), tempo);
        log.close();

        sc.close();
    }
}
