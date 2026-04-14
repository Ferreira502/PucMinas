//QUESTAO 03 TP01
// Autor: Gabriel Ferreira Pereira 

import java.util.*;
public class Main 
{
    public static int somenteVogais( String palavra )
    {
        char c;
        for ( int i = 0; i < palavra.length(); i++ )
        {
            c = palavra.charAt(i);

            if ( c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U' )
            {
                return 0;
            }
    
        }
        return 1;
    }

    public static int somenteConsoantes( String palavra )
    {
        char c;
        for ( int i = 0; i < palavra.length(); i++ )
        {
            c = palavra.charAt(i);

            if ( c < 'A' || (c > 'Z' && c < 'a') || c > 'z' )
            {
                return 0;
            }

            if ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' )
            {
                return 0;
            }
        }
        return 1;
    }

    public static int eInteiro(String palavra)
    {
        char c;
        int inicio = 0;
        
        if ( palavra.charAt(0) == '-' ) 
        {
            inicio = 1;
        }

        if ( inicio == palavra.length() ) 
        {
            return 0;
        }

        for ( int i = inicio; i < palavra.length(); i++ )
        {
            c = palavra.charAt(i);
            if ( c < '0' || c > '9' ) 
            {
                return 0;
            }
        }

        return 1;
    }
    public static int eReal(String palavra)
    {
        char c;
        int inicio = 0;
        int cont = 0;

        if ( eInteiro(palavra) == 1 )
        {
            return 1;
        }

        if (palavra.charAt(0) == '-')
        {
            inicio = 1;
        }

        if (inicio == palavra.length())
        {
            return 0;
        }

        for (int i = inicio; i < palavra.length(); i++)
        {
            c = palavra.charAt(i);

            if (c == '.' || c == ',')
            {
                cont++;
                if (cont > 1)
                {
                    return 0;
                }
            }

            else if (c < '0' || c > '9')
            {
                return 0;
            }
        }

        if (cont == 0)
        {
            return 0;
        }
        
        return 1;
    }

    public static void main ( String[] args)
    {
        Scanner sc = new Scanner( System.in );
        String palavra;
        palavra = sc.nextLine();
        while (palavra.length() != 3 || palavra.charAt(0) != 'F' || palavra.charAt(1) != 'I' || palavra.charAt(2) != 'M')
        {
            if ( somenteVogais(palavra) == 1)
            {
                System.out.print("SIM ");
            }

            else
            {
                System.out.print("NAO ");
            }

            if ( somenteConsoantes(palavra) == 1)
            {
                System.out.print("SIM ");
            }

            else
            {
                System.out.print("NAO ");
            }

            if ( eInteiro(palavra) == 1)
            {
                System.out.print("SIM ");
            }

            else
            {
                System.out.print("NAO ");
            }

            if ( eReal(palavra) == 1)
            {
                System.out.println("SIM");
            }

            else
            {
                System.out.println("NAO");
            }

            palavra = sc.nextLine();
        }
    }
}