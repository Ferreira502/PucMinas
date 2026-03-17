import java.util.Scanner;

public class TP03Q03 
{

    // Função recursiva que retorna a soma dos dígitos de n
    public static int somaDigitos(int n) 
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
            int somaRestante = somaDigitos(restante);
            int resultado = ultimoDigito + somaRestante;
            return resultado;
        }
    }

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextInt()) 
        { 
            int num = sc.nextInt();
            int soma = somaDigitos(num);
            System.out.println(soma);
        } 

        sc.close();
    }
}
