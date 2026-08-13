import java.util.*;

class Maiusculas
{
	public static int maiuscula (String palavra)
	{
		int x = 0;
		for(int i = 0; i < palavra.length(); i++)
		{
			if(palavra.charAt(i) >= 'A' && palavra.charAt(i) <= 'Z')
			{
				x++;
			}
		}

		return x;
	}

	public static void main(String[] args)
	{
		Scanner sc = new Scanner (System.in);
		String palavra;
		int x = 0;

		while(sc.hasNextLine())
		{
			palavra = sc.nextLine();
			x = maiuscula(palavra);
			System.out.println("" + x);
		}

		sc.close();
	}
}
