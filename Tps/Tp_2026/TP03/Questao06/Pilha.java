class Celula
{
    public Restaurante elemento;
    public Celula prox;

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Construtor da classe Celula
     */
    public Celula()
    {
        this(null);
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @param restaurante
     * @reason Construtor da classe Celula com restaurante
     */
    public Celula(Restaurante restaurante)
    {
        this.elemento = restaurante;
        this.prox = null;
    }
}

public class Pilha
{
    private Celula topo;

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Construtor da classe Pilha
     */
    public Pilha()
    {
        topo = null;
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @param restaurante
     * @reason Insere um restaurante no topo da pilha
     */
    public void inserir(Restaurante restaurante)
    {
        Celula tmp = new Celula(restaurante);
        tmp.prox = topo;
        topo = tmp;
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Remove um restaurante do topo da pilha
     * @return restaurante removido
     */
    public Restaurante remover() throws Exception
    {
        if (topo == null)
        {
            throw new Exception("Erro ao remover!");
        }

        Restaurante resp = topo.elemento;
        Celula tmp = topo;
        topo = topo.prox;
        tmp.prox = null;
        return resp;
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Mostra os restaurantes da pilha da base para o topo
     */
    public void mostrar()
    {
        mostrar(topo);
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @param i
     * @reason Metodo recursivo para mostrar os restaurantes da pilha
     */
    private void mostrar(Celula i)
    {
        if (i != null)
        {
            mostrar(i.prox);
            System.out.println(i.elemento.formatar());
        }
    }
}
