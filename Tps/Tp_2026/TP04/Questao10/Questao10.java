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
    

    /**
     * @author Gabriel Ferreira Pereira
     * @param id, nome, cidade, capacidade, avaliacao, tiposCozinha, faixaPreco, horarioAbertura, 
     *          horarioFechamento, dataAbertura, aberto do restaurante
     * @reason Construtor da classe Restaurante
     */
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

    // Getters

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
    
    /**
     * @author Gabriel Ferreira Pereira
     * @param String s
     * @reason Converte uma String para double manualmente
     * @return numero real
     */
    public static double parseDouble( String s )
    {
        int inteiro = 0;
        int decimal = 0;
        boolean ponto = false;

        for ( int i = 0; i < s.length(); i++ )
        {
            char c = s.charAt(i);
            if (c == '.')
            {
                ponto = true;
            }
            
            else if ( ponto == false) 
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

    /**
     * @author Gabriel Ferreira Pereira
     * @param path caminho do arquivo CSV
     * @reason Le uma linha do CSV e cria um objeto Restaurante
     * @return Restaurante criado
     */
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

        Hora horarioAbertura   = Hora.parseHora(scHorario.next());
        Hora horarioFechamento = Hora.parseHora(scHorario.next());
        scHorario.close();

        Data dataAbertura = Data.parseData(sc.next());

        String abertoStr = sc.next();
        boolean aberto;

        if (abertoStr.charAt(0) == 't')
        {
            aberto = true;
        }

        else
        {
            aberto = false;
        }

        Restaurante restaurante = new Restaurante(id, nome, cidade, capacidade, avaliacao, tiposCozinha, faixaPreco, horarioAbertura, horarioFechamento, dataAbertura, aberto);
        return restaurante;    
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Retorna o restaurante formatado como String
     * @return String com o restaurante formatado
     */
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

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Retorna a quantidade de restaurantes da colecao
     * @return this.tamanho
     */
    public int getTamanho() 
    {
        return this.tamanho;
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @param Restaurante r
     * @reason Adiciona tamanho em ColecaoRestaurante
     */
    public void adicionar( Restaurante r )
    {
        this.restaurantes[this.tamanho] = r;
        this.tamanho++;
    }
    /**
     * @author Gabriel Ferreira Pereira
     * @reason Pega os restaurantes da colecao
     * @return this.restaurantes
     */
    public Restaurante[] getRestaurantes() 
    {
        return this.restaurantes;
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Imprime todos os restaurantes da colecao
     */
    public void imprimir() 
    {
        for ( int i = 0; i < this.tamanho; i++ ) 
        {
            System.out.println(this.restaurantes[i].formatar());
        }
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Le o dataset do arquivo CSV usando Restaurante.ler() e retorna a colecao
     * @return colecao
     */
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
    
    /**
     * @author Gabriel Ferreira Pereira
     * @param ano mes e dia da data
     * @reason Construtor da classe Data
     */
    public Data ( int ano, int mes, int dia ) 
    {
        this.ano = ano;
        this.mes = mes;
        this.dia = dia;    
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @param s String no formato YYYY-MM-DD
     * @reason Converte uma String para um objeto Data
     * @return objeto Data correspondente
     */
    public static Data parseData( String s )
    {
        Scanner sc = new Scanner(s);
        sc.useDelimiter("-");
        int ano = sc.nextInt();
        int mes = sc.nextInt();
        int dia = sc.nextInt();

        Data data = new Data ( ano, mes, dia );
        
        return data;
    }
    
    /**
     * @author Gabriel Ferreira Pereira
     * @reason Retorna a data no formato DD/MM/YYYY
     * @return String com a data formatada
     */
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

    /**
     * @author Gabriel Ferreira Pereira
     * @param hora e minuto da hora
     * @reason Construtor da classe Hora
     */
    public Hora ( int hora, int minuto )
    {
        this.hora = hora;
        this.minuto = minuto;
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @param s String no formato HH:mm
     * @reason Converte uma String para um objeto Hora
     * @return objeto Hora correspondente
     */
    public static Hora parseHora ( String s )
    {
        Scanner sc = new Scanner(s);
        sc.useDelimiter(":");
        int hora1 = sc.nextInt();
        int minuto = sc.nextInt();

        Hora hora = new Hora(hora1, minuto);

        return hora;
    }
    
    /**
     * @author Gabriel Ferreira Pereira
     * @reason Retorna a hora no formato HH:mm
     * @return String com a hora formatada
     */
    public String formatarHora ()
    {
        String s = String.format("%02d:%02d", hora, minuto);
        return s;
    }
}

class NoBinario
{
    No elemento;
    NoBinario esq, dir;

    public NoBinario( No elemento )
    {
        this.elemento = elemento;
        esq = dir = null;
    }
}

class ArvoreBinaria
{
    private NoBinario raiz;

    public ArvoreBinaria()
    {
        raiz = null;
    }

    public No getFilho( char c )
    {
        return getFilho(c, raiz);
    }

    private No getFilho( char c, NoBinario i )
    {
        No resp = null;

        if ( i == null )
        {
            resp = null;
        }

        else if ( c == i.elemento.letra )
        {
            resp = i.elemento;
        }

        else if ( c < i.elemento.letra )
        {
            resp = getFilho(c, i.esq);
        }

        else
        {
            resp = getFilho(c, i.dir);
        }

        return resp;
    }

    public void setFilho( No filho ) throws Exception
    {
        raiz = setFilho(filho, raiz);
    }

    private NoBinario setFilho( No filho, NoBinario i ) throws Exception
    {
        if ( i == null )
        {
            i = new NoBinario(filho);
        }

        else if ( filho.letra < i.elemento.letra )
        {
            i.esq = setFilho(filho, i.esq);
        }

        else if ( filho.letra > i.elemento.letra )
        {
            i.dir = setFilho(filho, i.dir);
        }

        else
        {
            throw new Exception("Erro");
        }

        return i;
    }

    public void mostrar( String s )
    {
        mostrar(s, raiz);
    }

    private void mostrar( String s, NoBinario i )
    {
        if ( i != null )
        {
            mostrar(s, i.esq);
            i.elemento.mostrar(s);
            mostrar(s, i.dir);
        }
    }
}

class No 
{
    public char letra;
    public Restaurante elemento;
    public ArvoreBinaria prox;
    public boolean folha;
    
    public No ()
    {
        this(' ');
    }

    public No ( char letra )
    {
        this.letra = letra;
        this.elemento = null;
        prox = new ArvoreBinaria();
        folha = false;
    }

    public No getFilho( char c )
    {
        No filho = prox.getFilho(c);

        return filho;
    }

    public void setFilho ( No filho ) throws Exception
    {
        prox.setFilho(filho);
    }

    public ArvoreBinaria getFilho()
    {
        return prox;
    }

    public void mostrar( String s )
    {
        if ( folha == true )
        {
            System.out.println((s + letra) + " " + elemento.formatar());
        }

        prox.mostrar(s + letra);
    }
}

class ArvoreTrie 
{
    private No raiz;
    private int comparacoes;

    public ArvoreTrie()
    {
        raiz = new No();
        comparacoes = 0;
    }

    public int getComparacoes()
    {
        return comparacoes;
    }


    public void pesquisar( String s ) throws Exception
    {
        Restaurante resp = pesquisar(s, raiz, 0);

        if ( resp == null )
        {
            System.out.println("NAO");
        }

        else
        {
            System.out.println("SIM " + resp.formatar());
        }
    }

    public Restaurante pesquisar( String s, No no, int j ) throws Exception
    {
        Restaurante resp = null;
        char c = s.charAt(j);

        No filho = no.getFilho(c);
        comparacoes++;

        if ( filho == null )
        {
            resp = null;
        }
        else
        {
            System.out.print(c + " ");

            if ( j == s.length() - 1 )
            {
                if ( filho.folha == true )
                {
                    resp = filho.elemento;
                }
            }
            else
            {
                resp = pesquisar(s, filho, j + 1);
            }
        }

        return resp;
    }

    public void inserir( Restaurante restaurante ) throws Exception
    {
        inserir(restaurante, restaurante.getNome(), raiz, 0);
    }

    private void inserir ( Restaurante restaurante, String s, No i, int j ) throws Exception
    {
        char c = s.charAt(j);
        No filho = i.getFilho(c);

        if ( filho == null )
        {
            filho = new No(c);
            i.setFilho(filho);

            if ( j == s.length() - 1 )
            {
                filho.folha = true;
                filho.elemento = restaurante;
            }

            else
            {
                inserir(restaurante, s, filho, j + 1);
            }
        }

        else if ( j < s.length() - 1 )
        {
            inserir(restaurante, s, filho, j + 1);
        }

        else if ( filho.folha == false )
        {
            filho.folha = true;
            filho.elemento = restaurante;
        }

        else
        {
            throw new Exception("Erro");
        }
    }

    public void mostrar()
    {
        mostrar("", raiz);
    }

    private void mostrar ( String s, No no )
    {
        if ( no.folha == true )
        {
            System.out.println((s + no.letra) + " " + no.elemento.formatar());
        }
    
        no.getFilho().mostrar(s + no.letra);
    }

}

class Questao10
{
     /**
     * @author Gabriel Ferreira Pereira
     * @reason Metodo principal que busca e formata o restaurante com o ID fornecido
     *         e exibe na tela a lista de restaurantes selecionados
     */
    public static void main( String[] args ) throws Exception
    {
        ColecaoRestaurante colecao = ColecaoRestaurante.lerCsv();
        Restaurante[] restaurantes = colecao.getRestaurantes();
        Scanner sc = new Scanner(System.in);
        ArvoreTrie arvore = new ArvoreTrie();

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

        long inicio = System.currentTimeMillis();
        String nome = sc.nextLine();

        while ( nome.compareTo("FIM") != 0 )
        {
            arvore.pesquisar(nome);
            nome = sc.nextLine();
        }

        long fim = System.currentTimeMillis();

        PrintWriter log = new PrintWriter("842527_arvore_trie_arvore.txt");
        log.println("Tempo: " + (fim - inicio) / 1000.0 + " s");
        log.println("Comparacoes: " + arvore.getComparacoes());
        log.close();
    }
}
