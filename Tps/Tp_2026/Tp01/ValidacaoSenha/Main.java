// QUESTAO 08 DO TP01
// AUTOR: Gabriel Ferreira Pereira

import java.util.*;

class Main 
{
	public static void main ( String[] args )
	{
		Scanner sc = new Scanner(System.in);

		String senha;
		char c;

		senha = sc.nextLine();

		while (senha.length() != 3 || senha.charAt(0) != 'F' || senha.charAt(1) != 'I' || senha.charAt(2) != 'M')
		{
			int maiuscula = 0, minuscula = 0, caracter = 0, numero = 0;
			if ( senha.length() >= 8)
			{
				for ( int i = 0; i < senha.length(); i++ )
				{
					c = senha.charAt(i);
					if( c >= 97 && c <= 122 )
					{
						minuscula++;
					}
					if ( c >= 65 && c <= 90 )
					{
						maiuscula++;
					}
					if ( c >= 33 && c <= 47 || c >= 58 && c <= 64 || c >= 91 && c <= 96 || c >= 123 && c <= 126 )
					{
						caracter++;
					}
					if ( c >= 48 && c <= 57 )
					{
						numero++;
					}

					}
				if ( minuscula >= 1 && maiuscula >= 1 && caracter >= 1 && numero >= 1 ) 
				{
                    System.out.println("SIM");
                }
				else if ( minuscula < 1 || maiuscula < 1 || caracter < 1 || numero < 1) 
				{
					System.out.println("NAO");
				}
			}
			else
			{
				System.out.println("NAO");
			}

			senha = sc.nextLine();
				
		}
	
	}
}