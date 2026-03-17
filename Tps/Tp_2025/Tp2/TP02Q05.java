import java.util.*;

class TP02Q05 {

    // Metodo que verifica se duas strings sao anagramas
    public static boolean saoAnagramas(String s1, String s2) 
    {
        if (s1.length() != s2.length()) 
        {
            return false;
        }

        int[] cont = new int[26];

        for (int i = 0; i < s1.length(); i++) 
        {
            char c = s1.charAt(i);
            if (c >= 'a' && c <= 'z') c = (char)(c - 32); 
            cont[c - 'A']++;
        }

        for (int i = 0; i < s2.length(); i++) 
        {
            char c = s2.charAt(i);
            if (c >= 'a' && c <= 'z') c = (char)(c - 32);
            cont[c - 'A']--;
        }

        for (int i = 0; i < 26; i++) 
        {
            if (cont[i] != 0) return false;
        }

        return true;
    }

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextLine()) 
        {
            String entrada = sc.nextLine();

            // Verificação de "FIM"
            if (entrada.length() == 3 &&
                entrada.charAt(0) == 'F' &&
                entrada.charAt(1) == 'I' &&
                entrada.charAt(2) == 'M') {
                break;
            }

            String s1 = "";
            String s2 = "";
            boolean segundaPalavra = false;

            // Percorre a string e separa em s1 e s2
            for (int i = 0; i < entrada.length(); i++) 
            {
                if (!segundaPalavra) 
                {
                    if (entrada.charAt(i) == ' ' &&
                        i + 2 < entrada.length() &&
                        entrada.charAt(i + 1) == '-' &&
                        entrada.charAt(i + 2) == ' ') 
                        {
                            segundaPalavra = true;
                            i += 2;
                        } 
                        else 
                        {
                            s1 += entrada.charAt(i);
                        }
                } 
                else 
                {
                    s2 += entrada.charAt(i);
                }
            }

            if (saoAnagramas(s1, s2)) 
            {
                System.out.println("SIM");
            } 
            else 
            {
                System.out.println("N\u00C3O");
            }
        }

        sc.close();
    }
}
