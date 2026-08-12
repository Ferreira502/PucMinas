import java.io.File;
import java.io.PrintWriter;
import java.util.*;

class Restaurante
{
    private int id;
    private String nome;
    private String cidade;
    private int capacidade;
    private double avaliacao;
    private String[] tiposCozinha;
    private String faixaPreco;
    private Hora horarioAbertura;
    private Hora horarioFechamento;
    private Data dataAbertura;
    private boolean aberto;
    

    public Restaurante( int id, String nome, String cidade, int capacidade, double avaliacao,
        String[] tiposCozinha, String faixaPreco, Hora horarioAbertura, Hora horarioFechamento, Data dataAbertura, boolean aberto )
    {
        this.id = id;
        this.nome = nome;
        this.cidade = cidade;
        this.capacidade = capacidade;
        this.avaliacao = avaliacao;
        this.tiposCozinha = tiposCozinha;
        this.faixaPreco = faixaPreco;
        this.horarioAbertura = horarioAbertura;
        this.horarioFechamento = horarioFechamento;
        this.dataAbertura = dataAbertura;
        this.aberto = aberto;
    }

    public int getID ()
    {
        return this.id;
    }

    public String getNome ()
    {
        return this.nome;
    }

    public String getCidade ()
    {
        return this.cidade;
    }

    public int getCapacidade ()
    {
        return this.capacidade;
    }

    public double getAvaliacao ()
    {
        return this.avaliacao;
    }

    public String[] getTiposCozinha ()
    {
        return this.tiposCozinha;
    }

    public String getFaixaPreco ()
    {
        return this.faixaPreco;
    }

    public Hora getHorarioAbertura ()
    {
        return this.horarioAbertura;
    }

    public Hora getHorarioFechamento ()
    {
        return this.horarioFechamento;
    }

    public Data getDataAbertura ()
    {
        return this.dataAbertura;
    }

    public boolean getAberto ()
    {
        return this.aberto;
    }

    public static double parseDouble( String s )
    {
        int inteiro = 0;
        int decimal = 0;
        boolean ponto = false;

        for ( int i = 0; i < s.length(); i++ )
        {
            char c = s.charAt(i);

            if ( c == '.' )
            {
                ponto = true;
            }

            else if ( ponto == false )
            {
                inteiro = inteiro * 10 + (c - '0');
            }

            else
            {
                decimal = decimal * 10 + (c - '0');
            }
        }

        return inteiro + decimal / 10.0;
    }

    public static Restaurante ler( String linha ) throws Exception
    {
        Scanner sc = new Scanner(linha);
        sc.useDelimiter(",");

        int id = sc.nextInt();
        String nome = sc.next();
        String cidade = sc.next();
        int capacidade = sc.nextInt();
        double avaliacao = parseDouble(sc.next());

        String cozinhaStr = sc.next();
        Scanner scCozinha = new Scanner(cozinhaStr);
        scCozinha.useDelimiter(";");
        String tipo1 = scCozinha.next();
        String tipo2 = scCozinha.next();
        scCozinha.close();
        String[] tiposCozinha = new String[]{tipo1, tipo2};

        String faixaPreco = sc.next();

        String horario = sc.next();
        Scanner scHorario = new Scanner(horario);
        scHorario.useDelimiter("-");
        Hora horarioAbertura = Hora.parseHora(scHorario.next());
        Hora horarioFechamento = Hora.parseHora(scHorario.next());
        scHorario.close();

        Data dataAbertura = Data.parseData(sc.next());
        String abertoStr = sc.next();
        boolean aberto;

        if ( abertoStr.charAt(0) == 't' )
        {
            aberto = true;
        }

        else
        {
            aberto = false;
        }

        sc.close();
        Restaurante restaurante = new Restaurante(id, nome, cidade, capacidade, avaliacao, tiposCozinha, faixaPreco, horarioAbertura, horarioFechamento, dataAbertura, aberto);
        return restaurante;
    }

    public String formatar()
    {
        String tipos = "[" + tiposCozinha[0] + "," + tiposCozinha[1] + "]";
        String horario = horarioAbertura.formatarHora() + "-" + horarioFechamento.formatarHora();
        String data = dataAbertura.formatarData();

        return "[" + id + " ## " + nome + " ## " + cidade + " ## " + capacidade + " ## " +
            avaliacao + " ## " + tipos + " ## " + faixaPreco + " ## " +
            horario + " ## " + data + " ## " + aberto + "]";
    }
}

class ColecaoRestaurante
{
    private int tamanho;
    private Restaurante[] restaurantes;

    public ColecaoRestaurante( int tamanho, Restaurante[] restaurantes )
    {
        this.tamanho = tamanho;
        this.restaurantes = restaurantes;
    }

    public int getTamanho()
    {
        return this.tamanho;
    }

    public void adicionar( Restaurante r )
    {
        this.restaurantes[this.tamanho] = r;
        this.tamanho++;
    }

    public Restaurante[] getRestaurantes()
    {
        return this.restaurantes;
    }

    public void imprimir()
    {
        for ( int i = 0; i < this.tamanho; i++ )
        {
            System.out.println(this.restaurantes[i].formatar());
        }
    }

    public static ColecaoRestaurante lerCsv() throws Exception
    {
        ColecaoRestaurante colecao = new ColecaoRestaurante(0, new Restaurante[500]);
        Scanner sc = new Scanner(new File("/tmp/restaurantes.csv"));
        
        sc.nextLine();

        sc.useDelimiter(",|\n");

        for ( int i = 0; i < 500; i++ )
        {
            colecao.adicionar(Restaurante.ler(sc.nextLine()));
        }

        return colecao;
    }
}

class Data
{
    private int ano;
    private int mes;
    private int dia;

    public Data ( int ano, int mes, int dia )
    {
        this.ano = ano;
        this.mes = mes;
        this.dia = dia;
    }

    public static Data parseData( String s )
    {
        Scanner sc = new Scanner(s);
        sc.useDelimiter("-");
        int ano = sc.nextInt();
        int mes = sc.nextInt();
        int dia = sc.nextInt();
        sc.close();

        Data data = new Data ( ano, mes, dia );
        return data;
    }

    public String formatarData ()
    {
        String s = String.format("%02d/%02d/%04d", dia,mes,ano);
        return s;
    }
}

class Hora
{
    private int hora;
    private int minuto;

    public Hora ( int hora, int minuto )
    {
        this.hora = hora;
        this.minuto = minuto;
    }

    public static Hora parseHora ( String s )
    {
        Scanner sc = new Scanner(s);
        sc.useDelimiter(":");
        int hora1 = sc.nextInt();
        int minuto = sc.nextInt();
        sc.close();

        Hora hora = new Hora(hora1, minuto);
        return hora;
    }

    public String formatarHora ()
    {
        String s = String.format("%02d:%02d", hora, minuto);
        return s;
    }
}

class NoAvl
{
    public Restaurante elemento;
    public int nivel;
    public NoAvl esq, dir;

    public NoAvl( Restaurante elemento )
    {
        this.elemento = elemento;
        this.nivel = 1;
        this.esq = null;
        this.dir = null;
    }

    public int getNivel( NoAvl i )
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
    public NoAvl raiz;
    private int comparacoes;
    private int movimentacoes;

    public ArvoreAvl()
    {
        raiz = null;
        comparacoes = 0;
        movimentacoes = 0;
    }

    public int getComparacoes()
    {
        return comparacoes;
    }

    public int getMovimentacoes()
    {
        return movimentacoes;
    }

    public void inserir( Restaurante restaurante )
    {
        raiz = inserir(raiz, restaurante);
    }

    private NoAvl inserir( NoAvl i, Restaurante restaurante )
    {
        if ( i == null )
        {
            i = new NoAvl(restaurante);
            movimentacoes++;
        }

        else if ( i.elemento.getNome().compareTo(restaurante.getNome()) < 0 )
        {
            comparacoes++;
            i.dir = inserir(i.dir, restaurante);
        }

        else if ( i.elemento.getNome().compareTo(restaurante.getNome()) > 0 )
        {
            comparacoes += 2;
            i.esq = inserir(i.esq, restaurante);
        }

        else
        {
            comparacoes += 2;
        }

        return balancear(i);
    }

    public NoAvl rotacionarEsq( NoAvl i )
    {
        NoAvl noDir = i.dir;
        NoAvl noDirEsq = noDir.esq;

        noDir.esq = i;
        i.dir = noDirEsq;

        i.setNivel();
        noDir.setNivel();
        movimentacoes += 2;

        return noDir;
    }

    public NoAvl rotacionarDir( NoAvl i )
    {
        NoAvl noEsq = i.esq;
        NoAvl noEsqDir = noEsq.dir;

        noEsq.dir = i;
        i.esq = noEsqDir;

        i.setNivel();
        noEsq.setNivel();
        movimentacoes += 2;

        return noEsq;
    }

    private NoAvl balancear( NoAvl i )
    {
        int fator = i.getBalanceamento();
        
        if ( fator == 2 )
        {
            int fatorFilhoDir = i.dir.getBalanceamento();
            
            if ( fatorFilhoDir < 0 )
            {
                i.dir = rotacionarDir(i.dir);
                movimentacoes++;
            }

            i = rotacionarEsq(i);
        }

        else if ( fator == -2 )
        {
            int fatorFilhoEsq = i.esq.getBalanceamento(); 

            if ( fatorFilhoEsq > 0 )
            {
                i.esq = rotacionarEsq(i.esq);
                movimentacoes++;
            }
            
            i = rotacionarDir(i);
        }
    
        i.setNivel();
        return i;
    }

    public Restaurante pesquisar( String nome )
    {
        return pesquisar(raiz, nome, true);
    }

    private Restaurante pesquisar( NoAvl i, String nome, boolean primeira )
    {
        Restaurante resp = null;

        if ( i != null )
        {
            if ( primeira == true )
            {
                System.out.print("raiz ");
            }

            if ( nome.compareTo(i.elemento.getNome()) == 0 )
            {
                comparacoes++;
                resp = i.elemento;
            }

            else if ( nome.compareTo(i.elemento.getNome()) < 0 )
            {
                comparacoes += 2;
                System.out.print("esq ");
                resp = pesquisar(i.esq, nome, false);
            }

            else
            {
                comparacoes += 2;
                System.out.print("dir ");
                resp = pesquisar(i.dir, nome, false);
            }
        }

        return resp;
    }
}

class NoPrimeiroNivel
{
    int elemento;
    NoPrimeiroNivel esq, dir;
    ArvoreAvl outro;

    public NoPrimeiroNivel( int elemento )
    {
        this.elemento = elemento;
        this.esq = this.dir = null;
        this.outro = new ArvoreAvl();
    }
}

class ArvoreArvore
{
    private NoPrimeiroNivel raiz;
    private int comparacoes;
    private int movimentacoes;

    public ArvoreArvore()
    {
        raiz = null;
        comparacoes = 0;
        movimentacoes = 0;
    }

    public int getComparacoes()
    {
        return comparacoes + getComparacoes(raiz);
    }

    private int getComparacoes( NoPrimeiroNivel no )
    {
        int resp = 0;

        if ( no != null )
        {
            resp = no.outro.getComparacoes() + getComparacoes(no.esq) + getComparacoes(no.dir);
        }

        return resp;
    }

    public int getMovimentacoes()
    {
        return movimentacoes + getMovimentacoes(raiz);
    }

    private int getMovimentacoes( NoPrimeiroNivel no )
    {
        int resp = 0;

        if ( no != null )
        {
            resp = no.outro.getMovimentacoes() + getMovimentacoes(no.esq) + getMovimentacoes(no.dir);
        }

        return resp;
    }

    public void inserir( Restaurante restaurante ) throws Exception
    {
        int chave = restaurante.getCapacidade() % 15;
        raiz = inserir(restaurante, chave, raiz);
    }

    private NoPrimeiroNivel inserir( Restaurante restaurante, int chave, NoPrimeiroNivel no ) throws Exception
    {
        if ( no == null )
        {
            no = new NoPrimeiroNivel(chave);
            no.outro.inserir(restaurante);
            movimentacoes++;
        }

        else
        {
            comparacoes++;
            if ( chave < no.elemento )
            {
                no.esq = inserir(restaurante, chave, no.esq);
            }

            else if ( chave > no.elemento )
            {
                no.dir = inserir(restaurante, chave, no.dir);
            }

            else
            {
                no.outro.inserir(restaurante);
            }
        }

        return no;
    }

    public void pesquisar( String nome )
    {
        System.out.print("RAIZ ");
        Restaurante resp = pesquisar(nome, raiz);

        if ( resp == null )
        {
            System.out.println("NAO");
        }

        else
        {
            System.out.println("SIM " + resp.formatar());
        }
    }

    private Restaurante pesquisar( String nome, NoPrimeiroNivel no )
    {
        Restaurante resp = null;

        if ( no != null )
        {
            resp = no.outro.pesquisar(nome);
            comparacoes++;

            if ( resp == null )
            {
                System.out.print("ESQ ");
                resp = pesquisar(nome, no.esq);
            }

            if ( resp == null )
            {
                System.out.print("DIR ");
                resp = pesquisar(nome, no.dir);
            }
        }

        return resp;
    }
}

class Questao06
{
    public static void main( String[] args ) throws Exception
    {
        Scanner sc = new Scanner( System.in );
        ColecaoRestaurante colecao = ColecaoRestaurante.lerCsv();
        Restaurante[] restaurantes = colecao.getRestaurantes();
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
        String nome = sc.nextLine();

        long inicio = System.currentTimeMillis();

        while ( nome.compareTo("FIM") != 0 )
        {
            arvore.pesquisar(nome);
            nome = sc.nextLine();
        }

        long fim = System.currentTimeMillis();
        PrintWriter log = new PrintWriter("842527_hibrida_arvore_arvore.txt");
        log.println("Tempo: " + (fim - inicio) / 1000.0 + " s");
        log.println("Comparacoes: " + arvore.getComparacoes());
        log.println("Movimentacoes: " + arvore.getMovimentacoes());
        log.close();
        sc.close();
    }
}
