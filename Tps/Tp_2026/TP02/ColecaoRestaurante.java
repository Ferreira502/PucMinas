import java.util.*;

public class ColecaoRestaurante 
{
    private int tamanho;
    private Restaurante[] restaurantes;

    public ColecaoRestaurante ( int tamanho, Restaurante[] restaurantes )
    {
        this.tamanho = tamanho;
        this.restaurantes = restaurantes;
    }

    // Getters

    public int getTamanho ()
    {
        return this.tamanho;
    }

    public Restaurante[] getRestaurantes ()
    {
        return this.restaurantes;
    }

    public void lerCsv ( String path )
    {
        Scanner sc = new Scanner(path);
        
    }
}
