import java.util.*;

public class Main
{

    /**
     * @author Gabriel Ferreira Pereira
     * @param colecao, id
     * @reason Busca e imprime o restaurante com o ID fornecido
     */
    public static void buscarPorId(ColecaoRestaurante colecao, int id)
    {
        Restaurante[] restaurantes = colecao.getRestaurantes();

        for (int i = 0; i < colecao.getTamanho(); i++)
        {
            if (restaurantes[i].getID() == id)
            {
                System.out.println(restaurantes[i].formatar());
                return;
            }   
        }

        System.out.println("Restaurante nao encontrado");
    }

    public static void main( String[] args )
    {
        Scanner sc = new Scanner(System.in);
        ColecaoRestaurante colecao = ColecaoRestaurante.lerCsv();
        //colecao.insercao();
        int id = 0;
        
        while (sc.hasNextInt())
        {
            id = sc.nextInt();
            buscarPorId(colecao, id);
        }

        ColecaoRestaurante.insercao(colecao.getRestaurantes());

        colecao.imprimir();
    }
}