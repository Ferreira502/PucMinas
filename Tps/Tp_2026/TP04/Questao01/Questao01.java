import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

class Data
{
    private int ano;
    private int mes;
    private int dia;

    public Data( int ano, int mes, int dia )
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
        return new Data(ano, mes, dia);
    }

    public String formatarData()
    {
        return String.format("%02d/%02d/%04d", dia, mes, ano);
    }
}

class Hora
{
    private int hora;
    private int minuto;

    public Hora( int hora, int minuto )
    {
        this.hora = hora;
        this.minuto = minuto;
    }

    public static Hora parseHora( String s )
    {
        Scanner sc = new Scanner(s);
        sc.useDelimiter(":");
        int hora = sc.nextInt();
        int minuto = sc.nextInt();
        sc.close();
        return new Hora(hora, minuto);
    }

    public String formatarHora()
    {
        return String.format("%02d:%02d", hora, minuto);
    }
}

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
        String[] tiposCozinha, String faixaPreco, Hora horarioAbertura,
        Hora horarioFechamento, Data dataAbertura, boolean aberto )
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

    public int getID()
    {
        return this.id;
    }

    public String getNome()
    {
        return this.nome;
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
        boolean aberto = abertoStr.charAt(0) == 't';

        sc.close();

        return new Restaurante(id, nome, cidade, capacidade, avaliacao, tiposCozinha, faixaPreco, horarioAbertura, horarioFechamento, dataAbertura, aberto);
    }

    public String formatar()
    {
        String tipos = "[" + tiposCozinha[0] + "," + tiposCozinha[1] + "]";
        String horario = horarioAbertura.formatarHora() + "-" + horarioFechamento.formatarHora();
        String data = dataAbertura.formatarData();

        return "[" + id + " ## " + nome + " ## " + cidade + " ## " + capacidade + " ## "
            + avaliacao + " ## " + tipos + " ## " + faixaPreco + " ## "
            + horario + " ## " + data + " ## " + aberto + "]";
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

    public void adicionar( Restaurante restaurante )
    {
        this.restaurantes[this.tamanho] = restaurante;
        this.tamanho++;
    }

    public Restaurante[] getRestaurantes()
    {
        return this.restaurantes;
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

class No
{
    public Restaurante elemento;
    public int nivel;
    public No esq, dir;
    public No raiz;

    public No( Restaurante elemento )
    {
        this.elemento = elemento;
        this.nivel = 1;
        this.esq = null;
        this.dir = null;
        this.raiz = null;
    }

    public int getNivel( No i )
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
        movimentacoes++;
    }

    private No inserir( No i, Restaurante restaurante )
    {
        if ( i == null )
        {
            i = new No(restaurante);
            movimentacoes++;
        }
        else
        {
            int cmp = i.elemento.getNome().compareTo(restaurante.getNome());
            comparacoes++;

            if ( cmp < 0 )
            {
                i.dir = inserir(i.dir, restaurante);
                movimentacoes++;
            }
            else if ( cmp > 0 )
            {
                i.esq = inserir(i.esq, restaurante);
                movimentacoes++;
            }
        }

        return balancear(i);
    }

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
            int op = nome.compareTo(i.elemento.getNome());
            comparacoes++;

            if ( raizFlag )
            {
                System.out.print("raiz");
            }

            if ( op == 0 )
            {
                System.out.println(" SIM");
            }
            else if ( op > 0 )
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

    public void caminharCentral()
    {
        caminharCentral(raiz);
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

    public No rotacionarEsq( No i )
    {
        No noDir = i.dir;
        No noDirEsq = noDir.esq;

        noDir.esq = i;
        i.dir = noDirEsq;
        movimentacoes += 2;

        i.setNivel();
        noDir.setNivel();

        return noDir;
    }

    public No rotacionarDir( No i )
    {
        No noEsq = i.esq;
        No noEsqDir = noEsq.dir;

        noEsq.dir = i;
        i.esq = noEsqDir;
        movimentacoes += 2;

        i.setNivel();
        noEsq.setNivel();

        return noEsq;
    }

    private No balancear( No i )
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
            movimentacoes++;
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
            movimentacoes++;
        }

        i.setNivel();

        return i;
    }
}

class Questao01
{
    public static void main( String[] args ) throws Exception
    {
        Scanner sc = new Scanner( System.in );
        ColecaoRestaurante colecao = ColecaoRestaurante.lerCsv();
        Restaurante[] restaurantes = colecao.getRestaurantes();
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
        String nome = sc.nextLine();

        long inicio = System.currentTimeMillis();

        while ( nome.compareTo("FIM") != 0 )
        {
            arvore.pesquisar(nome);
            nome = sc.nextLine();
        }

        arvore.caminharCentral();

        long fim = System.currentTimeMillis();
        PrintWriter log = new PrintWriter("842527_arvore_avl.txt");
        log.println("Tempo: " + (fim - inicio) / 1000.0 + " s");
        log.println("Comparacoes: " + arvore.getComparacoes());
        log.println("Movimentacoes: " + arvore.getMovimentacoes());
        log.close();
    }
}
