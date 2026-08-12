
class Lista
{
    private Restaurante[] array;
    private int n;

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Construtor da classe Lista
     */
    public Lista()
    {
        this(6);
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @param tamanho Tamanho da lista
     * @reason Construtor da classe Lista com tamanho
     */
    public Lista( int tamanho )
    {
        array = new Restaurante[tamanho];
        n = 0;
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @param restaurante Restaurante a ser inserido
     * @reason Insere um restaurante na primeira posicao da lista
     */
    public void inserirInicio( Restaurante restaurante ) throws Exception
    {
        if ( n >= array.length )
        {
            throw new Exception("Erro ao inserir!");
        }

        //levar elementos para o fim do array
        for ( int i = n; i > 0; i-- )
        {
            array[i] = array[i-1];
        }

        array[0] = restaurante;
        n++;
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @param restaurante Restaurante a ser inserido
     * @reason Insere um restaurante na ultima posicao da lista
     */
    public void inserirFim( Restaurante restaurante ) throws Exception
    {
        if ( n >= array.length )
            throw new Exception("Erro ao inserir!");

        array[n] = restaurante;
        n++;
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @param restaurante Restaurante a ser inserido
     * @param posicao Posicao de insercao
     * @reason Insere um restaurante em uma posicao especifica da lista
     */
    public void inserir( Restaurante restaurante, int pos ) throws Exception
    {
        //validar insercao
        if ( n >= array.length || pos < 0 || pos > n )
        {
            throw new Exception("Erro ao inserir!");
        }
        
        //levar elementos para o fim do array
        for ( int i = n; i > pos; i-- )
        {
            array[i] = array[i-1];
        }

        array[pos] = restaurante;
        n++;
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Remove e retorna o primeiro restaurante da lista
     * @return Restaurante removido
     */
    public Restaurante removerInicio() throws Exception
    {
        //validar remocao
        if ( n == 0 )
        {
            throw new Exception("Erro ao remover!");
        }
        
        Restaurante resp = array[0];
        n--;

        for ( int i = 0; i < n; i++ )
        {
            array[i] = array[i+1];
        }

        return resp;
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Remove e retorna o ultimo restaurante da lista
     * @return Restaurante removido
     */
    public Restaurante removerFim() throws Exception
    {
        //validar remocao
        if ( n == 0 )
        {
            throw new Exception("Erro ao remover!");
        }

        return array[--n];
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @param posicao Posicao de remocao
     * @reason Remove e retorna o restaurante de uma posicao especifica da lista
     * @return Restaurante removido
     */
    public Restaurante remover( int pos ) throws Exception
    {
        //validar remocao
        if ( n == 0 || pos < 0 || pos >= n )
        {
            throw new Exception("Erro ao remover!");
        }

        Restaurante resp = array[pos];
        n--;

        for ( int i = pos; i < n; i++ )
        {
            array[i] = array[i+1];
        }
        
        return resp;
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Mostra os restaurantes da lista formatados
     */
    public void mostrar()
    {
        for ( int i = 0; i < n; i++ )
        {
            System.out.println(array[i].formatar());
        }
    }
}