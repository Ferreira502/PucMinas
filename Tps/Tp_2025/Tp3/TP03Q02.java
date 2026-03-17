import java.util.*;

class TP03Q02 
{

    // Função recursiva para inverter uma string
    public static String inversao(String palavra) 
    {
        if (palavra.length() <= 1) 
        {
            return palavra;
        }
        return palavra.charAt(palavra.length() - 1) + inversao(palavra.substring(0, palavra.length() - 1));
    }

    // Função para comparar string com "FIM"
    public static int comparaString(String palavra) 
    {
        String str1 = "FIM";
        return palavra.compareTo(str1);
    }

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        String palavra;
        int resultado = 1;

        while (resultado != 0) {
            palavra = sc.nextLine();

            if (comparaString(palavra) == 0) 
            {
                break;
            }

            resultado = comparaString(palavra);
            String newPalavra = inversao(palavra); 
            System.out.println(newPalavra);
        }

        sc.close();
    }
}
