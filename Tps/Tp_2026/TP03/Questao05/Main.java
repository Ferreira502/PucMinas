import java.io.PrintWriter;
import java.util.*;

public class Main
{

    /**
     * @author Gabriel Ferreira Pereira
     * @param selecionados, tamanho, nome, contadores
     * @reason funcao que faz a pesquisa Sequencial para achar o nome do restaurante de acordo com id fonecido
     * @return resp
     */
    public static boolean pesqSeq( Restaurante[] selecionados, int tamanho, String nome, int[] contadores )
    {
        boolean resp = false;

        for ( int i = 0; i < tamanho; i++ )
        {
            //System.out.println("'" + selecionados[i].getNome() + "'");
            contadores[0]++;
            if ( selecionados[i].getNome().compareTo(nome) == 0 )
            {
                resp = true;
                i = tamanho;
            }
            
            //System.out.println("Comparando: '" + selecionados[i].getNome() + "' com '" + nome + "'");

        }
        return resp;
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Metodo principal que busca e formata o restaurante com o ID fornecido
     *         e chama a funcao de pesquisa e exibe na tela SIM ou NAO se o nome fornecido esta na pesquisa
     */

    public static void main( String[] args ) throws Exception
    {
        Scanner sc = new Scanner(System.in);
        ColecaoRestaurante colecao = ColecaoRestaurante.lerCsv();
        Restaurante[] restaurantes = colecao.getRestaurantes();
        Restaurante[] selecionados = new Restaurante[500];

        int tamanho = 0;
        int id = 0;

        while ( ( id = sc.nextInt() ) != -1 )
        {
            for ( int i = 0; i < colecao.getTamanho(); i++ )
            {
                if ( restaurantes[i].getID() == id )
                {
                    selecionados[tamanho] = restaurantes[i];
                    tamanho++;
                }
            }
        }

        int[] comparacoes = new int[]{0};
        long inicio = System.currentTimeMillis();

        PrintWriter log = new PrintWriter("842527_sequencial.txt");

        sc.nextLine();    // pega o \n do nextInt de -1
        String nome = sc.nextLine();

        while ( !(nome.charAt(0) == 'F' && nome.charAt(1) == 'I' && nome.charAt(2) == 'M') )
        {
            if ( pesqSeq(selecionados, tamanho, nome, comparacoes) )
            {
                System.out.println("SIM");
            }

            else
            {
                System.out.println("NAO");
            }

            nome = sc.nextLine();
        }

        long fim = System.currentTimeMillis();

        log.println("Comparacoes: " + comparacoes[0]);
        log.close();
    }
}