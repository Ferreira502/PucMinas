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
            }
        }
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        ColecaoRestaurante colecao = ColecaoRestaurante.lerCsv();

        Restaurante[] selecionados = new Restaurante[550];
        int quantidade = 0;

        int id = sc.nextInt();
        
        while (id != -1)
        {
            selecionados[quantidade] = colecao.getRestaurantes()[id - 1];
            quantidade++;
            id = sc.nextInt();
        }

        ColecaoRestaurante.heap(selecionados, quantidade);

        for (int i = 0; i < quantidade; i++)
        {
            System.out.println(selecionados[i].formatar());
        }
    }
}