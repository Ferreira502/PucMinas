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
    
    // Setters


    public Restaurante parRestaurante ( String S )
    {

        Scanner sc = new Scanner(s);

        sc.useDelimiter(",");
        int id = sc.nextInt();
        String nome = sc.next();
        String cidade = sc.next();
        int capacidade = sc.nextInt();
        double avaliacao = sc.nextDouble();



        return s;
    }

}