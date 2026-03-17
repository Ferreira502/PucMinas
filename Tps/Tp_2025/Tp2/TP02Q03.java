import java.util.*;

class TP02Q03 
{
    public static String inversao ( String palavra )
    {
        // Gera duas letras minusculas aleatorias
        
        String resultado = ""; 
        int a = palavra.length(); 
        
        for (int i = a - 1; i >= 0; i--)
            {
                char c = palavra.charAt(i);
                resultado = resultado + c;
            }
        return resultado;
    }
    
    
    public static int comparaString(String palavra)
    {
        String str1 = "FIM";
        return palavra.compareTo(str1); 
    }

    // Método principal
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in); 
        String palavra;        
        String newPalavra;     
        int resultado = 1;    

        // Laço que continua enquanto a palavra digitada for diferente de "FIM"
        while (resultado != 0) 
        {
            palavra = sc.nextLine();

            if (comparaString(palavra) == 0) // Verifica se a palavra é "FIM"
            {
                break;
            }
            
            resultado = comparaString(palavra);
            newPalavra = inversao(palavra);
            System.out.println(newPalavra);
        }   
    }
}