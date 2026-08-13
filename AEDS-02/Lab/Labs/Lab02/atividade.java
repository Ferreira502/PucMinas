// Algoritmo para poder achar o maior numero do array em java. Feito no laboratorio de AEDS2.

import java.util.*;

class atividade 
{
	public static int maiorNum( int vet[] , int n )
	{
		System.out.println("Cheguei aqui");
		int x = vet [0];
		for ( int i = 0; i < vet.length; i++ )
		{
		 	if ( vet[i] > x)
			{
				x = vet[i];
			}
		}
		return x;
	}

	public static void main ( String[] args )
	{
		Scanner sc = new Scanner ( System.in );
		int n = sc.nextInt();
		int[] vet = new int[n];
		int resultado = 0;

		for ( int i = 0; i < vet.length; i++ )
		{
			System.out.println("Posicao: " + i);
			vet[i] = sc.nextInt();
		}

		resultado = maiorNum(vet, n);
		System.out.println("parei aqui");

		System.out.println("" + resultado);
		sc.close();
	}	
}
