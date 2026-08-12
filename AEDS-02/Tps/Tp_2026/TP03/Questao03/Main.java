import java.io.PrintWriter;
import java.util.*;

public class Main
{
    /**
     * @author Gabriel Ferreira Pereira
     * @param selecionados, esq, dir, k, contadores
     * @reason Funcao recursiva do quicksortParcial parcial
     */

    public static void quicksortParcial( Restaurante[] selecionados, int tamanho, int[] contadores, int k )
    {
        quicksortParcial(selecionados, 0, tamanho - 1, k, contadores);
    }

    private static void quicksortParcial(Restaurante[] selecionados, int esq, int dir, int k, int[] contadores)
    {
        int i = esq;
        int j = dir;
        Restaurante pivo = selecionados[(esq + dir) / 2];

        while (i <= j)
        {
            while (selecionados[i].getAvaliacao() < pivo.getAvaliacao()
                || (selecionados[i].getAvaliacao() == pivo.getAvaliacao()
                && selecionados[i].getNome().compareTo(pivo.getNome()) < 0))
            {
                contadores[0]++;
                i++;
            }
            contadores[0]++;

            while (selecionados[j].getAvaliacao() > pivo.getAvaliacao()
                || (selecionados[j].getAvaliacao() == pivo.getAvaliacao()
                && selecionados[j].getNome().compareTo(pivo.getNome()) > 0))
            {
                contadores[0]++;
                j--;
            }
            contadores[0]++;

            if (i <= j)
            {
                Restaurante temp = selecionados[i];
                selecionados[i] = selecionados[j];
                selecionados[j] = temp;
                contadores[1] += 3;
                i++;
                j--;
            }
        }

        if (esq < j)
        {
            quicksortParcial(selecionados, esq, j, k, contadores);
        }

        if (i < dir && i < k)
        {
            quicksortParcial(selecionados, i, dir, k, contadores);
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

        int tamanho  = 0;
        int k = 10;
        int id = 0;
        long inicio, fim;

        while ((id = sc.nextInt()) != -1)
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
  
        int[] contadores = new int[]{0, 0};
        inicio = System.currentTimeMillis();

        if (tamanho > 0)
        {
            quicksortParcial(selecionados, tamanho, contadores, k);
        }

        fim = System.currentTimeMillis();

        boolean ordenado = true;

        int limite = tamanho;

        if (limite > k)
        {
            limite = k;
        }

        for (int i = 0; i < limite - 1; i++)
        {
            if (selecionados[i].getAvaliacao() > selecionados[i + 1].getAvaliacao() || (selecionados[i].getAvaliacao() == selecionados[i + 1].getAvaliacao()
                && selecionados[i].getNome().compareTo(selecionados[i + 1].getNome()) > 0))
            {
                ordenado = false;
            }
        }
        
        PrintWriter log = new PrintWriter("842527_quicksort_parcial.txt");
        log.println("Tempo para ordenar: " + (fim - inicio) / 1000.0 + " s.");
        log.println("isOrdenado: " + ordenado);
        log.println("Comparacoes: " + contadores[0]);
        log.println("Movimentacoes: " + contadores[1]);
        log.close();

        for (int j = 0; j < tamanho; j++)
        {
            System.out.println(selecionados[j].formatar());
        }

        sc.close();
    }
}
