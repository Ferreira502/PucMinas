//  QUESTAO 11 DO TP01
// Autor: Gabriel Ferreira Pereira

import java.util.*;

public class Main
{
    public static String inversaoRec( String string, int n )
    {
        if ( n < 0 )
        {
            return "";
        }

        return string.charAt(n) + inversaoRec( string, n - 1 );
    }
    public static void main ( String[] args )
    {
        Scanner sc = new Scanner( System.in );

        String string;

        string = sc.nextLine();

        while ( string.length() != 3 || string.charAt(0) != 'F' || string.charAt(1) != 'I' || string.charAt(2) != 'M' )
        {
            String resposta;

            resposta = inversaoRec( string, string.length() - 1 );

            System.out.println( "" + resposta );

            string = sc.nextLine();
        }
    }
}