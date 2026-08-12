import java.util.*;

public class Main {

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Metodo principal que busca e formata o restaurante com o ID fornecido
     * e chama a funcao de pesquisa e exibe na tela SIM ou NAO se o nome fornecido
     * esta na pesquisa
     */
    public static void main(String[] args) throws Exception 
    {
        Scanner sc = new Scanner(System.in);
        ColecaoRestaurante colecao = ColecaoRestaurante.lerCsv();
        Restaurante[] restaurantes = colecao.getRestaurantes();
        Lista lista = new Lista(500);
        int id = 0;

        while ((id = sc.nextInt()) != -1) 
        {
            for (int i = 0; i < colecao.getTamanho(); i++) 
            {
                if (restaurantes[i].getID() == id) 
                {
                    lista.inserirFim(restaurantes[i]);
                }
            }
        }

        int n = sc.nextInt();

        for (int i = 0; i < n; i++) 
        {
            String comando = sc.next();

            if (comando.compareTo("II") == 0) 
            {
                id = sc.nextInt();
                for (int j = 0; j < colecao.getTamanho(); j++) 
                {
                    if (restaurantes[j].getID() == id) 
                    {
                        lista.inserirInicio(restaurantes[j]);
                    }
                }

            } 

            else if (comando.compareTo("I*") == 0) 
            {
                int posicao = sc.nextInt();
                id = sc.nextInt();
                for (int j = 0; j < colecao.getTamanho(); j++) 
                {
                    if (restaurantes[j].getID() == id) 
                    {
                        lista.inserir(restaurantes[j], posicao);
                    }
                }

            } 

            else if (comando.compareTo("IF") == 0) 
            {
                id = sc.nextInt();
                for (int j = 0; j < colecao.getTamanho(); j++) 
                {
                    if (restaurantes[j].getID() == id) 
                    {
                        lista.inserirFim(restaurantes[j]);
                    }
                }
            } 
            
            else if (comando.compareTo("RI") == 0) 
            {
                Restaurante r = lista.removerInicio();
                System.out.println("(R) " + r.getNome());
            } 
            
            else if (comando.compareTo("R*") == 0) 
            {
                int posicao = sc.nextInt();
                Restaurante r = lista.remover(posicao);
                System.out.println("(R) " + r.getNome());
            } 
            
            else if (comando.compareTo("RF") == 0) 
            {
                Restaurante r = lista.removerFim();
                System.out.println("(R) " + r.getNome());
            }
        }

        lista.mostrar();
    }
}