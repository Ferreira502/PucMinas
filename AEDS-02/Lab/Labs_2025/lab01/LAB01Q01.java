import java.util.*;

class LAB01Q01 
{
    
    public static int comparaString ( String palavra)
    {
       String str1 = "FIM";
       return palavra.compareTo(str1);
    }
    
    public static void main ( String args [] )
    {
        Scanner sc = new Scanner(System.in);
        String palavra;
        int resultado = 1;
        
        while (resultado != 0)
        {
            System.out.println("Digite uma palavra: ");
            palavra = sc.next();
    
            resultado = comparaString(palavra);
    
            if (resultado != 0)
            {
                int cont = 0;
                for (int i = 0; i < palavra.length(); i++)
                {
                    char c = palavra.charAt(i);
                    if (c >= 'A' && c <= 'Z') 
                    {
                        cont++;
                    }
                }
    
                System.out.println("cont: " + cont);
            }
        }

        System.out.println("FIM do programa");
    }
    
}
