import java.io.PrintWriter;
import java.util.*;

public class Main
{

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Metodo de ordenacao por selecao parcial, ordena pelo atributo nome
     * @param  restaurantes, tamanho, contadores
     * */
    public  static void selecaoParcial( Restaurante[] selecionados, int tamanho, int[] comparacoes, int k )
    {
        for ( int i = 0; i < k; i++ )
        {
            int menor = i;
            
            for ( int j = i + 1; j < tamanho; j++ ) 
            {
                comparacoes[0]++; // avanca comparacoes
                
                //if ( comparar_nome(selecionados[menor].nome, selecionados[j].nome) > 0 )
                if ( selecionados[menor].getNome().compareTo(selecionados[j].getNome()) > 0)
                {
                    menor = j;
                }

                //System.out.println(menor + "");
            }
            
            if ( menor != i )
            {
                Restaurante tmp = selecionados[menor];
                selecionados[menor] = selecionados[i];
                selecionados[i] = tmp;
                comparacoes[1]++; // avanca movimentacoes
            }
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

        selecaoParcial(selecionados, tamanho, contadores, k);

        fim = System.currentTimeMillis();

        int comparacoes = contadores[0];
        int movimentacoes = contadores[1];

        boolean ordenado = true;
        for (int i = 0; i < k; i++)
        {
            if ( selecionados[i].getNome().compareTo(selecionados[i + 1].getNome() ) > 0)
            {
                ordenado = false;
            }
        }
        
        //Mostrar o conjunto ordenado, tempo de execucao e status da ordenacao
		//algoritmo.mostrar();
        // Salvar tempo e status em arquivo
        PrintWriter log = new PrintWriter("842527_selecao_parcial.txt");
        log.println("Tempo para ordenar: " + (fim - inicio) / 1000.0 + " s.");
        log.println("isOrdenado: " + ordenado);
        log.println("Comparacoes: " + comparacoes);
        log.println("Movimentacoes: " + movimentacoes);
        log.close();

        for (int j = 0; j < tamanho; j++)
        {
            System.out.println(selecionados[j].formatar());
        }

    }
}
