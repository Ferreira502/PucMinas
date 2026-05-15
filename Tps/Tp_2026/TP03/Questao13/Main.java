import java.util.*;


class Main 
{
    /**
     * @author Gabriel Ferreira Pereira
     * @reason Metodo principal que busca e formata o restaurante com o ID fornecido
     * e adiciona na lista circular e imprime o que foi pedido
     */
    public static void main( String[] args ) throws Exception
    {

        Scanner sc = new Scanner(System.in);
        ColecaoRestaurante colecao = ColecaoRestaurante.lerCsv();
        Restaurante[] restaurantes = colecao.getRestaurantes();

        Fila fila = new Fila();
        int id = 0;

        while ( ( id = sc.nextInt() ) != -1 )
        {
            for ( int i = 0; i < colecao.getTamanho(); i++ )
            {
                if ( restaurantes[i].getID() == id )
                {
                    fila.inserir(restaurantes[i]);
                    System.out.println("(I)" + fila.mediaAno());
                }
            }
        }

        int n = sc.nextInt();

        for ( int i = 0; i < n; i++ )
        {
            
            String comando = sc.next();

            if ( comando.compareTo("I") == 0 )
            {
                id = sc.nextInt();
                for ( int j = 0; j < colecao.getTamanho(); j++ )
                    if ( restaurantes[j].getID() == id )
                    {
                        fila.inserir(restaurantes[j]);
                        System.out.println("(I)" + fila.mediaAno());
                    }
            }
            else if ( comando.compareTo("R") == 0 )
            {
                Restaurante r = fila.remover();
                System.out.println("(R)" + r.getNome());
            }
        }

        fila.mostrar();
    }
}