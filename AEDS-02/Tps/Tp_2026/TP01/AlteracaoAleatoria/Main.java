// QUESTAO 02 DO TP01
// Autor: Gabriel Ferreira Pereira

import java.util.*;

class Main 
{
    public static Random gerador = new Random();

    public static void alteracao ( String palavra)
    {
        char x;
        char y;

        x = (char) ('a' + (Math.abs (gerador.nextInt()) % 26));
        y = (char) ('a' + (Math.abs (gerador.nextInt()) % 26));

        String novaPalavra = "";

        for ( int i = 0; i < palavra.length(); i++)
        {
            char c = palavra.charAt(i);
            
            if ( c == x ) 
            {
                novaPalavra += y;
            }

            else 
            {
                novaPalavra += c;
            }
        }
            
        System.out.println(novaPalavra);
    }

    public static void main ( String [] args)
    {
        gerador.setSeed(4);

        Scanner sc = new Scanner ( System.in );
        String palavra;

        palavra = sc.nextLine();
        
        while ( palavra.length() != 3 || palavra.charAt(0) != 'F' || palavra.charAt(1) != 'I' || palavra.charAt(2) != 'M' )
        {
            alteracao(palavra);
            palavra = sc.nextLine();
        }
    }
}