import java.util.*;

public class Main
{

    /**
     * @author Gabriel Ferreira Pereira
     * @param colecao, id
     * @reason Busca e imprime o restaurante com o ID fornecido
     */
    public static Restaurante buscarPorId(ColecaoRestaurante colecao, int id)
    {
        Restaurante[] restaurantes = colecao.getRestaurantes();

        for (int i = 0; i < colecao.getTamanho(); i++)
        {
            if (restaurantes[i].getID() == id)
            {
                return restaurantes[i];
            }
        }

        return null;
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
            Restaurante r = buscarPorId(colecao, id);

            if (r != null)
            {
                selecionados[quantidade] = r;
                quantidade++;
            }

            id = sc.nextInt();
        }

        ColecaoRestaurante.insercao(selecionados, quantidade);

        for (int i = 0; i < quantidade; i++)
        {
            System.out.println(selecionados[i].formatar());
        }
    }
}