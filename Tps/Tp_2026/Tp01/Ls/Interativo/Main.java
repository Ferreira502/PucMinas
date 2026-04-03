//QUESTAO 03 TP01
// Autor: Gabriel Ferreira Pereira 

import java.util.*;

public class Main 
{
    public static void main ( String[] args)
    {
        Scanner sc = new Scanner( System.in );
        String palavra;

        palavra = sc.nextLine();

        while (palavra.length() != 3 || palavra.charAt(0) != 'F' || palavra.charAt(1) != 'I' || palavra.charAt(2) != 'M')
		{
            int x1 = 0;
            int x2 = 0;
            int x3 = 0;
            int x4 = 0;
            char c;

            int tamanho = palavra.length();

            for ( int i = 0; i < tamanho; i++ )
            {
                c = palavra.charAt(i);
                
                if ( c >= 97 && c <= 122 ) 
                {
                    x1++;
                }

                if ( c >= 65 && c <= 90 ) 
                {
                    x2++;
                }

                if ( c >= 48 && c <= 57 ) 
                {
                    x3++;
                }

                if ( c == 44 || c == 46 ) 
                {
                    x4++;
                }
            }



            palavra = sc.nextLine();
        }
    }
}
