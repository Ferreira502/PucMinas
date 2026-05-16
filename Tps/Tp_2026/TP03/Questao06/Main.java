import java.util.Scanner;

public class Main
{
    /**
     * @author Gabriel Ferreira Pereira
     * @reason Metodo principal que busca e formata o restaurante com o ID fornecido
     *         e executa os comandos sobre a pilha
     */
    public static void main(String[] args) throws Exception
    {
        ColecaoRestaurante colecao = ColecaoRestaurante.lerCsv();
        Restaurante[] restaurantes = colecao.getRestaurantes();
        Pilha pilha = new Pilha();
        Scanner sc = new Scanner(System.in);
        int id;

        while ((id = sc.nextInt()) != -1)
        {
            for (int i = 0; i < colecao.getTamanho(); i++)
            {
                if (restaurantes[i].getID() == id)
                {
                    pilha.inserir(restaurantes[i]);
                    break;
                }
            }
        }

        int n = sc.nextInt();

        for (int i = 0; i < n; i++)
        {
            char comando = sc.next().charAt(0);

            if (comando == 'I')
            {
                id = sc.nextInt();

                for (int j = 0; j < colecao.getTamanho(); j++)
                {
                    if (restaurantes[j].getID() == id)
                    {
                        pilha.inserir(restaurantes[j]);
                        break;
                    }
                }
            }

            else if (comando == 'R')
            {
                Restaurante removido = pilha.remover();
                System.out.println("(R)" + removido.getNome());
            }
        }

        pilha.mostrar();
        sc.close();
    }
}
