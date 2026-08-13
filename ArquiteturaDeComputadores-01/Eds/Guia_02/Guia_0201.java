/* 
  Guia_0201.java 
     842527 - Gabriel Ferreira Pereira
*/ 


import java.util.Scanner;

public class Guia_0201 
{
    public static double bin2double(String x) 
    {
        String[] partes = x.split("\\.");
        String parteInteira = partes[0];
        String parteFracionaria = "";

        if (partes.length > 1) 
        {
            parteFracionaria = partes[1];
        }

        double resultado = 0.0;

        for (int i = 0; i < parteInteira.length(); i++) 
        {
            char c = parteInteira.charAt(parteInteira.length() - 1 - i);
            if (c == '1') 
            {
                resultado += Math.pow(2, i);
            }
        }

        for (int i = 0; i < parteFracionaria.length(); i++) 
        {
            char c = parteFracionaria.charAt(i);
            if (c == '1') 
            {
                resultado += Math.pow(2, -(i + 1));
            }
        }

        return resultado;
    }

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Digite um numero em binario: ");
        String numeroBinario = sc.next();

        double resultado = bin2double(numeroBinario);
        System.out.println(numeroBinario + " em decimal e: " + resultado);

        sc.close();
    }
}