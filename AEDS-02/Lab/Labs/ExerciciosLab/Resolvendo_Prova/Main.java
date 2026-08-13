import java.util.*;

class Main 
{
    public static void main(String[] args) 
	{
        Scanner sc = new Scanner(System.in);
        int n = 0;
        int x = 0;
        x = sc.nextInt();
        n = sc.nextInt();
        String[] saidas = new String[x];

        for (int y = 0; y < x; y++) 
		{
            String[] palavras = new String[n];

            for (int i = 0; i < n; i++) 
			{
                palavras[i] = sc.next();
            }

            for (int i = 0; i < n - 1; i++) 
			{	
                for (int j = i + 1; j < n; j++) 
				{
                    if (palavras[i].length() < palavras[j].length()) 
					{
                        String tmp = palavras[i];
                        palavras[i] = palavras[j];
                        palavras[j] = tmp;
                    } 
					else if (palavras[i].length() == palavras[j].length()) 
					{
                        
						if (palavras[i].charAt(0) < palavras[j].charAt(0)) 
						{
                            String tmp = palavras[i];
                            palavras[i] = palavras[j];
                            palavras[j] = tmp;
                        }
                    }
                }
            }

            saidas[y] = "";
            for (int i = 0; i < n; i++) 
			{
                if (i == 0) 
				{
                    saidas[y] = palavras[i];
                } 
				else 
				{
                    saidas[y] += " " + palavras[i];
                }
            }
            
			if (y < x - 1) 
			{
				n = sc.nextInt();
			}
        }

        for (int y = 0; y < x; y++) 
		{
            System.out.println(saidas[y]);
        }
    }
}