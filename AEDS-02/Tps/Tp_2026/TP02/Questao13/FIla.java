class Fila
{
    private Restaurante[] array;
    private int primeiro;
    private int ultimo;

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Construtor da classe Fila com tamanho 5
     */
    public Fila()
    {
        array = new Restaurante[6]; // tamanho 5 + 1
        primeiro = ultimo = 0;
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Verifica se a fila esta cheia
     */
    public boolean isCheia()
    {
        return ( ( ultimo + 1 ) % array.length ) == primeiro;
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Verifica se a fila esta vazia
     */
    public boolean isVazia()
    {
        return primeiro == ultimo;
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @param restaurante Restaurante a ser inserido
     * @reason Insere um restaurante no fim da fila.
     *         Se a fila estiver cheia, remove o primeiro antes de inserir
     */
    public void inserir( Restaurante restaurante ) throws Exception
    {
        if ( isCheia() )
        {
            Restaurante r = remover();
            System.out.println("(R) " + r.getNome());
        }

        array[ultimo] = restaurante;
        ultimo = ( ultimo + 1 ) % array.length;
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Remove e retorna o primeiro restaurante da fila
     */
    public Restaurante remover() throws Exception
    {
        if ( isVazia() )
            throw new Exception("Erro ao remover!");

        Restaurante resp = array[primeiro];
        primeiro = ( primeiro + 1 ) % array.length;
        return resp;
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Calcula a media arredondada do ano de abertura dos restaurantes na fila
     */
    public int mediaAno()
    {
        int soma = 0;
        int count = 0;
        for ( int i = primeiro; i != ultimo; i = ( i + 1 ) % array.length )
        {
            soma += array[i].getDataAbertura().getAno();
            count++;
        }
        return Math.round( (float) soma / count );
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Mostra os restaurantes da fila formatados
     */
    public void mostrar()
    {
        for ( int i = primeiro; i != ultimo; i = ( i + 1 ) % array.length )
            System.out.println(array[i].formatar());
    }
}