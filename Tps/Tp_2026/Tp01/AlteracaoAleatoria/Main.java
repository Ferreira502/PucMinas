// QUESTAO 02 DO TP01
// Autor: Gabriel Ferreira Pereira

import java.util.*;

class Main 
{
    public static void main ( String [] args)
    {
        Scanner sc = new Scanner ( System.in );
        String palavra;
        char c;
        char x;
        char y;

        Random gerador = new Random();
        gerador.setSeed(4);

        palavra = sc.nextLine();

        while (palavra.length() != 3 || palavra.charAt(0) != 'F' || palavra.charAt(1) != 'I' || palavra.charAt(2) != 'M')
		{                
            x = (char) ('a' + (Math.abs (gerador.nextInt()) % 26));
            y = (char) ('a' + (Math.abs (gerador.nextInt()) % 26));

            for ( int i = 0; i < palavra.length(); i++)
            {
                c = palavra.charAt(i);
    
                if ( c == x ) 
                {
                    c += y;
                }

                else if ( c == y )
                {
                    c += x;
                }
            }
            
            System.out.println("" + palavra);
            palavra = sc.nextLine();
		}
    }
}