import java.util.*;

class TP01Q01  
{
    public static void imprimirInvertido(int num) 
    {
        int[] digitos = new int[100];
        int tamanho = 0;

        if (num == 0) 
        {
            System.out.print("0");
            return;
        }

        while (num > 0) 
        {
            digitos[tamanho] = num % 10;
            num /= 10;
            tamanho++;
        }

        for (int i = 0; i < tamanho; i++) 
        {
            System.out.print(digitos[i]);
        }
    }

    public static void invertido(int x, int n) 
    {
        for (int i = x; i <= n; i++) 
        {
            System.out.print(i);
        }

        for (int i = n; i >= x; i--) 
        {
            imprimirInvertido(i);
        }
    }

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int n = sc.nextInt();

        invertido(x, n);

        sc.close();
    }
}
