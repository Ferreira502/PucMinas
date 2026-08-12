import java.io.PrintWriter;
import java.util.*;

public class Main 
{
    public static int getMaiorFilho( Restaurante[] restaurantes, int i, int tamHeap ) 
    {
        int filho = 0;

        if ( 2 * i == tamHeap || restaurantes[2 * i].getDataAbertura().compareTo(restaurantes[2 * i + 1].getDataAbertura()) > 0 ) 
        {
            filho = 2 * i; 
        }
        
        else 
        {
            filho = 2 * i + 1;
        }

        return filho;
    }

    public static void construir( Restaurante[] restaurantes, int tamHeap, int[] contadores ) 
    {
        for ( int i = tamHeap; i > 1; i /= 2 ) 
        {
            contadores[0]++; // avanca o comparacao

            if ( restaurantes[i].getDataAbertura().compareTo(restaurantes[i / 2].getDataAbertura()) > 0 ) 
            {
                Restaurante tmp = restaurantes[i];
                restaurantes[i] = restaurantes[i / 2];
                restaurantes[i / 2] = tmp;
                contadores[1]++; // avanca o movimentacao
            }
        }
    }

    public static void reconstruir( Restaurante[] restaurantes, int tamHeap, int[] contadores ) 
    {
        int i = 1;

        while ( i <= tamHeap / 2 ) 
        {
            int filho = getMaiorFilho( restaurantes, i, tamHeap );

            contadores[0]++; // avanca o comparacao

            if ( restaurantes[i].getDataAbertura().compareTo(restaurantes[filho].getDataAbertura()) < 0 ) 
            {
                Restaurante tmp = restaurantes[i];
                restaurantes[i] = restaurantes[filho];
                restaurantes[filho] = tmp;
                contadores[1]++; // avanca o movimentacao

                i = filho;
            } 

            else 
            {
                i = tamHeap;
            }
        }
    }

    public static void heapSort( Restaurante[] selecionados, int tamanho, int[] contadores ) 
    {
        Restaurante[] tmp = new Restaurante[tamanho + 1];
        
        for ( int i = 0; i < tamanho; i++ ) 
        {
            tmp[i + 1] = selecionados[i];
        }
        
        for ( int tamHeap = 2; tamHeap <= tamanho; tamHeap++ ) 
        {
            construir(tmp, tamHeap, contadores);
        }
    
        int tamHeap = tamanho;
        
        while ( tamHeap > 1 ) 
        {
            Restaurante aux = tmp[1];
            tmp[1] = tmp[tamHeap];
            tmp[tamHeap] = aux;
            tamHeap--;
            contadores[1]++; // avanca o movimentacao

            reconstruir(tmp, tamHeap, contadores);
        }

        for ( int i = 0; i < tamanho; i++ ) 
        {
            selecionados[i] = tmp[i + 1];
        }
    }

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
  
        int[] contadores = new int[]{0, 0};

        inicio = System.currentTimeMillis();
        heapSort(selecionados, tamanho, contadores);
        fim = System.currentTimeMillis();

        int comparacoes = contadores[0];
        int movimentacoes = contadores[1];

        boolean ordenado = true;
        
        for (int i = 0; i < tamanho - 1; i++) 
        {
            if (selecionados[i].getDataAbertura().compareTo(selecionados[i + 1].getDataAbertura()) > 0) 
            {
                ordenado = false;

            }
        }
        
        PrintWriter log = new PrintWriter("842527_heapsort.txt");
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