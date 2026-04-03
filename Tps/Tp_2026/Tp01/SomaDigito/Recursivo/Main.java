// Questao 12 do Tp01
// Autor: Gabriel Ferreira Pereira

import java.util.*;

public class Main 
{    
    public static int soma(int n)
    {
        if (n < 0) 
        {
            n = -n;
        }

        if (n == 0) 
        {
            return 0;
        } 
  
        else 
        {
            int ultimoDigito = n % 10;
            int restante = n / 10;
            int somaRestante = soma(restante);
            int resultado = ultimoDigito + somaRestante;
            return resultado;
        }
    }
    
    public static void main ( String[] args )
    {
        Scanner sc = new Scanner(System.in);
        int num = 0;
        num = sc.nextInt();

        while ( num != 1) 
        {   
            int soma = soma(num);
            System.out.println("" + soma);
            num = sc.nextInt();
        }

    }
}