// Questao 12 do Tp01
// Autor: Gabriel Ferreira Pereira

import java.util.*;

public class Main
{    
    public static int soma(int n) 
    {
        if (n <= 0) 
        {
            return 0;
        }
        
        return (n % 10) + soma(n / 10);
    }
    
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextInt()) 
        {
            int num = sc.nextInt();
            System.out.println(soma(num));
        }
    }
}