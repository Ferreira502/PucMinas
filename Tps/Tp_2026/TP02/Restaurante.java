
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