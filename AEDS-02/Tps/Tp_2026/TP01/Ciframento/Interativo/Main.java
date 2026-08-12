// QUESTAO 01 DO TP01
// Autor: Gabriel Ferreira Pereira

import java.util.*;

class Main 
{
	public static void ciframento( String palavra)
	{
		Scanner sc = new Scanner(System.in);
		char c;

		for ( int i = 0; i < palavra.length(); i++ )
		{
			c = palavra.charAt(i);
			c += 3;

			System.out.print("" + c);
		}
	}
	
	public static void main ( String[] args )
	{
		Scanner sc = new Scanner(System.in);
		String palavra;
		palavra = sc.nextLine();
		
		while ( palavra.length() != 3 || palavra.charAt(0) != 'F' || palavra.charAt(1) != 'I' || palavra.charAt(2) != 'M' )
		{
			ciframento(palavra);
			System.out.println();
			palavra = sc.nextLine();
		}
	}
}