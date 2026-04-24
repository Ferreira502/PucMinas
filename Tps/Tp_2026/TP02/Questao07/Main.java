import java.io.PrintWriter;
import java.util.*;

public class Main
{

    public static void mergesort( Restaurante[] restaurantes, int esq, int dir, int[] contadores )
    {
        if ( esq < dir )
        {
            int meio = ( esq + dir ) / 2;
            mergesort( restaurantes, esq, meio, contadores );
            mergesort( restaurantes, meio + 1, dir, contadores );
            intercalar( restaurantes, esq, meio, dir, contadores );
        }
    }

    public static void intercalar( Restaurante[] restaurantes, int esq, int meio, int dir, int[] contadores )
    {
        int n1, n2, i, j, k;
        n1 = meio - esq + 1;
        n2 = dir - meio;

        Restaurante[] a1 = new Restaurante[n1];
        Restaurante[] a2 = new Restaurante[n2];

        for ( i = 0; i < n1; i++ )
        {
            a1[i] = restaurantes[esq + i];
        }

        for ( j = 0; j < n2; j++ )
        {
            a2[j] = restaurantes[meio + j + 1];
        }

        i = 0;
        j = 0;
        k = esq;

        // Intercala os dois subarrays comparando cidade e desempatando por nome
        
        while ( i < n1 && j < n2 )
        {
            contadores[0]++; // avanca o movimentacoes

            int tmp = a1[i].getCidade().compareTo( a2[j].getCidade() );

            // Se as cidades forem iguais, desempata pelo nome
            if ( tmp == 0 )
            {
                contadores[0]++; // avanca o movimentacoes
                tmp = a1[i].getNome().compareTo( a2[j].getNome() );
            }

            // Coloca o menor elemento no array original
            if ( tmp <= 0 )
            {
                restaurantes[k++] = a1[i++];
            }
            else
            {
                restaurantes[k++] = a2[j++];
            }

            contadores[1]++; // avanca o comparacoes
        }

        // Copia o restante de a1 caso a2 tenha acabado primeiro
        while ( i < n1 )
        {
            restaurantes[k++] = a1[i++];
            contadores[1]++; // avanca o comparcoes 
        }

        // Copia o restante de a2 caso a1 tenha acabado primeiro
        while ( j < n2 )
        {
            restaurantes[k++] = a2[j++];
            contadores[1]++; // avanca o comparacoes
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

        mergesort( selecionados, 0, tamanho - 1, contadores );

        fim = System.currentTimeMillis();

        int comparacoes = contadores[0];
        int movimentacoes = contadores[1];

        boolean ordenado = true;
        
        for (int i = 0; i < tamanho - 1; i++)
        {
            // Compara a cidade do elemento atual com a cidade do proximo elemento
            // Se a cidade atual for maior que a proxima, o array nao esta ordenado
            
            if (selecionados[i].getCidade().compareTo(selecionados[i + 1].getCidade()) > 0)
            {
                ordenado = false;
            }
        }
        
        //Mostrar o conjunto ordenado, tempo de execucao e status da ordenacao
		//algoritmo.mostrar();
        // Salvar tempo e status em arquivo
        PrintWriter log = new PrintWriter("842527_mergesort.txt");
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