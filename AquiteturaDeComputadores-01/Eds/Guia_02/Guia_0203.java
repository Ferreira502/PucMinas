/* 
  Guia_0203.java 
     842527 - Gabriel Ferreira Pereira
*/ 


import java.util.Scanner;

public class Guia_0203 
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

    public static String double2base(double valor, int base) 
    {
        long parteInteira = (long) valor;
        double parteFracionaria = valor - parteInteira;

        StringBuilder sb = new StringBuilder();

        if (parteInteira == 0) 
        {
            sb.append("0");
        } 
        else 
        {
            while (parteInteira > 0) 
            {
                int resto = (int) (parteInteira % base);
                if (resto < 10) 
                {
                    sb.insert(0, resto);
                } 
                else 
                {
                    sb.insert(0, (char) ('A' + resto - 10));
                }
                parteInteira /= base;
            }
        }

        if (parteFracionaria > 0) 
        {
            sb.append(".");
            int count = 0;
            while (parteFracionaria > 0 && count < 10) 
            {
                parteFracionaria *= base;
                int digito = (int) parteFracionaria;
                if (digito < 10) 
                {
                    sb.append(digito);
                } 
                else 
                {
                    sb.append((char) ('A' + digito - 10));
                }
                parteFracionaria -= digito;
                count++;
            }
        }

        return sb.toString();
    }

    public static String dbin2base(int base, String binario)
    {
        double valorDecimal = bin2double(binario);
        return double2base(valorDecimal, base);
    }

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Digite um numero binario: ");
        String numeroBinario = sc.next();

        System.out.print("Digite a base de destino: ");
        int base = sc.nextInt();

        String resultado = dbin2base(base, numeroBinario);
        System.out.println(numeroBinario + " (binario) = " + resultado + " (base " + base + ")");

        sc.close();
    }
}
