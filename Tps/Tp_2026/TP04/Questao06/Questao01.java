import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

class NoAvl
{
    Restaurante elemento;
    int nivel;
    NoAvl esq, dir;

    public NoAvl( Restaurante elemento )
    {
        this.elemento = elemento;
        this.nivel = 1;
        this.esq = null;
        this.dir = null;
    }

    public int getNivel( NoAvl no )
    {
        int resp = 0;

        if ( no != null )
        {
            resp = no.nivel;
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
    private NoAvl raiz;
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

    public void zerarComparacoes()
    {
        comparacoes = 0;
    }

    public void inserir( Restaurante restaurante )
    {
        raiz = inserir(raiz, restaurante);
    }

    private NoAvl inserir( NoAvl no, Restaurante restaurante )
    {
        if ( no == null )
        {
            no = new NoAvl(restaurante);
        }
        else
        {
            int cmp = restaurante.getNome().compareTo(no.elemento.getNome());

            if ( cmp < 0 )
            {
                no.esq = inserir(no.esq, restaurante);
            }
            else if ( cmp > 0 )
            {
                no.dir = inserir(no.dir, restaurante);
            }
        }

        return balancear(no);
    }

    public Restaurante pesquisar( String nome, ArrayList<String> caminho )
    {
        zerarComparacoes();
        return pesquisar(raiz, nome, caminho, true);
    }

    private Restaurante pesquisar( NoAvl no, String nome, ArrayList<String> caminho, boolean raizFlag )
    {
        Restaurante resp = null;

        if ( no != null )
        {
            comparacoes++;

            if ( raizFlag )
            {
                caminho.add("raiz");
            }

            int cmp = nome.compareTo(no.elemento.getNome());

            if ( cmp == 0 )
            {
                resp = no.elemento;
            }
            else if ( cmp < 0 )
            {
                caminho.add("esq");
                resp = pesquisar(no.esq, nome, caminho, false);
            }
            else
            {
                caminho.add("dir");
                resp = pesquisar(no.dir, nome, caminho, false);
            }
        }

        return resp;
    }

    private NoAvl rotacionarEsq( NoAvl no )
    {
        NoAvl noDir = no.dir;
        NoAvl noDirEsq = noDir.esq;

        noDir.esq = no;
        no.dir = noDirEsq;

        no.setNivel();
        noDir.setNivel();

        return noDir;
    }

    private NoAvl rotacionarDir( NoAvl no )
    {
        NoAvl noEsq = no.esq;
        NoAvl noEsqDir = noEsq.dir;

        noEsq.dir = no;
        no.esq = noEsqDir;

        no.setNivel();
        noEsq.setNivel();

        return noEsq;
    }

    private NoAvl balancear( NoAvl no )
    {
        if ( no != null )
        {
            int fator = no.getBalanceamento();

            if ( fator == 2 )
            {
                if ( no.dir.getBalanceamento() < 0 )
                {
                    no.dir = rotacionarDir(no.dir);
                }

                no = rotacionarEsq(no);
            }
            else if ( fator == -2 )
            {
                if ( no.esq.getBalanceamento() > 0 )
                {
                    no.esq = rotacionarEsq(no.esq);
                }

                no = rotacionarDir(no);
            }

            no.setNivel();
        }

        return no;
    }
}

class NoPrimeiroNivel
{
    int chave;
    ArvoreAvl arvore;
    NoPrimeiroNivel esq, dir;

    public NoPrimeiroNivel( int chave )
    {
        this.chave = chave;
        this.arvore = new ArvoreAvl();
        this.esq = null;
        this.dir = null;
    }
}

class ArvoreArvore
{
    private NoPrimeiroNivel raiz;
    private int comparacoes;

    public ArvoreArvore()
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
     * @reason Insere o restaurante na arvore de primeiro nivel pela chave capacidade mod 15
     *         e na AVL do segundo nivel pelo nome
     */
    public void inserir( Restaurante restaurante )
    {
        int chave = restaurante.getCapacidade() % 15;
        raiz = inserirPrimeiroNivel(raiz, chave, restaurante);
    }

    private NoPrimeiroNivel inserirPrimeiroNivel( NoPrimeiroNivel no, int chave, Restaurante restaurante )
    {
        if ( no == null )
        {
            no = new NoPrimeiroNivel(chave);
            no.arvore.inserir(restaurante);
        }
        else if ( chave < no.chave )
        {
            no.esq = inserirPrimeiroNivel(no.esq, chave, restaurante);
        }
        else if ( chave > no.chave )
        {
            no.dir = inserirPrimeiroNivel(no.dir, chave, restaurante);
        }
        else
        {
            no.arvore.inserir(restaurante);
        }

        return no;
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @param nome nome pesquisado
     * @reason Pesquisa o nome nas AVLs encontradas durante o percurso pre-ordem da arvore principal
     */
    public void pesquisar( String nome )
    {
        ArrayList<String> caminho = new ArrayList<String>();
        caminho.add("RAIZ");

        Restaurante encontrado = pesquisar(raiz, nome, caminho);

        if ( encontrado == null )
        {
            caminho.add("NAO");
            System.out.println(String.join(" ", caminho));
        }
        else
        {
            caminho.add("SIM");
            System.out.println(String.join(" ", caminho) + " " + encontrado.formatar());
        }
    }

    private Restaurante pesquisar( NoPrimeiroNivel no, String nome, ArrayList<String> caminho )
    {
        Restaurante resp = null;

        if ( no != null )
        {
            resp = no.arvore.pesquisar(nome, caminho);
            comparacoes += no.arvore.getComparacoes();

            if ( resp == null )
            {
                caminho.add("ESQ");
                resp = pesquisar(no.esq, nome, caminho);

                if ( resp == null )
                {
                    caminho.add("DIR");
                    resp = pesquisar(no.dir, nome, caminho);
                }
            }
        }

        return resp;
    }
}

public class Questao01
{
    /**
     * @author Gabriel Ferreira Pereira
     * @reason Cria uma arvore binaria de arvores AVL para armazenar restaurantes,
     *         usando capacidade mod 15 no primeiro nivel e nome no segundo nivel
     */
    public static void main( String[] args ) throws Exception
    {
        ColecaoRestaurante colecao = ColecaoRestaurante.lerCsv();
        Restaurante[] restaurantes = colecao.getRestaurantes();
        Scanner sc = new Scanner(System.in);
        ArvoreArvore arvore = new ArvoreArvore();

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

        PrintWriter log = new PrintWriter("842527_hibrida_arvore_arvore.txt");
        log.printf("842527\t%d\t%f%n", arvore.getComparacoes(), tempo);
        log.close();

        sc.close();
    }
}
