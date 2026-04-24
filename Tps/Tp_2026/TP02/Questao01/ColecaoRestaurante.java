import java.io.File;
import java.util.*;

public class ColecaoRestaurante 
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
        ColecaoRestaurante colecao = new ColecaoRestaurante(0, new Restaurante[550]);
        Scanner sc = new Scanner(new File("restaurante.csv"));
        
        sc.nextLine();

        sc.useDelimiter(",|\n");

        for ( int i = 0; i < 500; i++ )
        {
            colecao.adicionar(Restaurante.ler(sc));
        }

        return colecao;
    }
}
