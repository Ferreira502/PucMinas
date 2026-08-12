import java.util.*;

class LAB01Q02 
    {
        public static int comparaString ( String palavra)
        {
           String str1 = "FIM";
           return palavra.compareTo(str1);
        }

        public static void palavraRecursiva ()
        {
           Scanner sc = new Scanner(System.in);
           String palavra;
           System.out.println("Digite uma palavra: ");
           palavra = sc.next();

           if (comparaString(palavra) == 0)
           {
               System.out.println("FIM DO PROGRAMA");
           } 
           else 
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
               palavraRecursiva();
           }
        }
        
        public static void main ( String args[] )
        {
            palavraRecursiva();
            
        }
    }