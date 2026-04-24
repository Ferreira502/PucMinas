import java.io.PrintWriter;
import java.util.*;

public class Main
{

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Metodo de ordenacao por insercao, ordena pelo atributo cidade
     * @param  restaurantes, tamanho, contadores
     * */
    public static void insercao( Restaurante[] restaurantes, int tamanho, int[] contadores )
    {
        for ( int i = 1; i < tamanho; i++ )
        {
            Restaurante tmp = restaurantes[i];
            int j = i - 1;

            contadores[0]++;   // avanca o comparacoes

            while ( j >= 0 && restaurantes[j].getCidade().compareTo(tmp.getCidade()) > 0 )
            {
                restaurantes[j + 1] = restaurantes[j];
                j--;
                contadores[1]++; // avanca o movimentacoes
            }

            restaurantes[j + 1] = tmp;
            contadores[1]++; // avanca o movimentacoes
        }
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Metodo principal que busca e formata o restaurante com o ID fornecido
     *         e exibe na tela a lista de restaurantes selecionados
     */
    public static void main(String[] args) throws Exception
    {
        Scanner sc = new Scanner(System.in);
        
        ColecaoRestaurante colecao = ColecaoRestaurante.lerCsv();
        Restaurante[] restaurantes = colecao.getRestaurantes();
        Restaurante[] selecionados = new Restaurante[500];

        int tamanho = 0;
        
        int id = 0;

        long inicio, fim;

        while ( ( id = sc.nextInt() ) != -1 )
        {
            for (int i = 0; i < colecao.getTamanho(); i++)
            {
                if (restaurantes[i].getID() == id)
                {
                    selecionados[tamanho] = restaurantes[i];
                    tamanho++;
                }
            }
        }
  
        // Execucao do algoritmo de ordenacao
        int[] contadores = new int[]{0, 0};
        
        inicio = System.currentTimeMillis();

        insercao(selecionados, tamanho, contadores);

        fim = System.currentTimeMillis();

        int comparacoes = contadores[0];
        int movimentacoes = contadores[1];

        boolean ordenado = true;
        for (int i = 0; i < tamanho - 1; i++)
        {
            if (selecionados[i].getCidade().compareTo(selecionados[i + 1].getCidade()) > 0)
            {
                ordenado = false;
            }
        }
        
        //Mostrar o conjunto ordenado, tempo de execucao e status da ordenacao
		//algoritmo.mostrar();
        // Salvar tempo e status em arquivo
        PrintWriter log = new PrintWriter("842527_insercao.txt");
        log.println("Tempo para ordenar: " + (fim - inicio) / 1000.0 + " s.");
        log.println("isOrdenado: " + ordenado);
        log.println("Comparacoes: " + comparacoes);
        log.println("Movimentacoes: " + movimentacoes);
        log.close();


        for (int i = 0; i < tamanho; i++)
        {
            System.out.println(selecionados[i].formatar());
        }
    }
}