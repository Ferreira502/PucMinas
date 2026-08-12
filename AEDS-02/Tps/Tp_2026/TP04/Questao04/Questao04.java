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

class Hash
{
    Restaurante tabela[];
    int m;
    int comparacoes;

    public Hash()
    {
        this(83);
    }

    public Hash( int m )
    {
        this.m = m;
        this.comparacoes = 0;
        this.tabela = new Restaurante[m];
    }

    public int h( String chave )
    {
        int x = 0;

        for ( int i = 0; i < chave.length(); i++ )
        {
            char caractere = chave.charAt(i);
            x += caractere;
        }

        x = x % m;

        return x;
    }

    public int reh( String chave )
    {
        int x = 0;

        for ( int i = 0; i < chave.length(); i++ )
        {
            char caractere = chave.charAt(i);
            x += caractere;
        }

        x = (x + 1) % m;

        return x;
    }

    private boolean isPosicaoLivre( int pos )
    {
        boolean resp = true;

        if ( tabela[pos] != null )
        {
            resp = false;
        }

        return resp;
    }

    public int getComparacoes()
    {
        return comparacoes;
    }

    public boolean inserir( Restaurante restaurante )
    {
        boolean resp = false;

        if ( restaurante != null )
        {
            int pos = h(restaurante.getNome());

            if ( tabela[pos] == null )
            {
                tabela[pos] = restaurante;
                resp = true;
            }

            else
            {
                pos = reh(restaurante.getNome());

                if ( tabela[pos] == null )
                {
                    tabela[pos] = restaurante;
                    resp = true;
                }
            }
        }

        return resp;
    }

    private int pesquisarPosicao( String nome, Restaurante[] encontrado, boolean contar )
    {
        int pos = h(nome);
        int resp = -1;

        if ( tabela[pos] != null )
        {
            if ( contar == true )
            {
                comparacoes++;
            }

            if ( tabela[pos].getNome().compareTo(nome) == 0 )
            {
                encontrado[0] = tabela[pos];
                resp = pos;
            }
            else
            {
                pos = reh(nome);

                if ( tabela[pos] != null )
                {
                    if ( contar == true )
                    {
                        comparacoes++;
                    }

                    if ( tabela[pos].getNome().compareTo(nome) == 0 )
                    {
                        encontrado[0] = tabela[pos];
                        resp = pos;
                    }
                }
            }
        }

        return resp;
    }

    public boolean pesquisar( String nome, Restaurante[] encontrado )
    {
        boolean resp = false;

        if ( pesquisarPosicao(nome, encontrado, true) != -1 )
        {
            resp = true;
        }

        return resp;
    }

    public int getPosicao( String nome )
    {
        Restaurante[] encontrado = new Restaurante[1];
        return pesquisarPosicao(nome, encontrado, false);
    }
}

class Questao04
{
    public static void main( String[] args ) throws Exception
    {
        Scanner sc = new Scanner( System.in );
        ColecaoRestaurante colecao = ColecaoRestaurante.lerCsv();
        Restaurante[] restaurantes = colecao.getRestaurantes();
        Hash hash = new Hash(83);

        int id = sc.nextInt();

        while ( id != -1 )
        {
            for ( int i = 0; i < colecao.getTamanho(); i++ )
            {
                if ( restaurantes[i].getID() == id )
                {
                    if ( hash.inserir(restaurantes[i]) == false )
                    {
                        System.out.println(restaurantes[i].getNome());
                    }

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
            Restaurante[] encontrado = new Restaurante[1];

            if ( hash.pesquisar(nome, encontrado) == false )
            {
                System.out.println("-1");
            }

            else
            {
                int pos = hash.getPosicao(nome);
                System.out.println(pos + " " + encontrado[0].formatar());
            }

            nome = sc.nextLine();
        }

        long fim = System.currentTimeMillis();
        PrintWriter log = new PrintWriter("842527_hash_rehash.txt");
        log.println("Tempo: " + (fim - inicio) / 1000.0 + " s");
        log.println("Comparacoes: " + hash.getComparacoes());
        log.close();
    }
}