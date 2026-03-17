import java.util.*;

class Ciframento {
	public static void main (String []  args)
	{
		Scanner sc = new Scanner ( System.in );
		
		String palavra;
		char newPalavra[] = new char[100];

		while(true)
		{
			palavra = sc.nextLine();

			if ( palavra.equals("FIM"))
			{
				break;
			}

			for(int i = 0; i < palavra.length(); i++)
			{
				int var = palavra.charAt(i);
				System.out.printf("%c ", var+3); 
			}
		}
	}
}
