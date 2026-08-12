/* 
  Guia_0204.java 
     842527 - Gabriel Ferreira Pereira
*/ 


import java.util.Scanner;

public class Guia_0204 
{

    public static double base2double(String x, int base1) 
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
            int valor;
            if (c >= '0' && c <= '9') 
            {
                valor = c - '0';
            } 
            else 
            {
                valor = 10 + (c - 'A');
            }
            resultado += valor * Math.pow(base1, i);
        }

        for (int i = 0; i < parteFracionaria.length(); i++) 
        {
            char c = parteFracionaria.charAt(i);
            int valor;
            if (c >= '0' && c <= '9') 
            {
                valor = c - '0';
            } 
            else 
            {
                valor = 10 + (c - 'A');
            }
            resultado += valor * Math.pow(base1, -(i + 1));
        }

        return resultado;
    }

    public static String double2base(double valor, int base2) 
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
                int resto = (int) (parteInteira % base2);
                if (resto < 10) 
                {
                    sb.insert(0, resto);
                } 
                else 
                {
                    sb.insert(0, (char) ('A' + resto - 10));
                }
                parteInteira /= base2;
            }
        }

        if (parteFracionaria > 0) 
        {
            sb.append(".");
            int count = 0;
            while (parteFracionaria > 0 && count < 10) 
            {
                parteFracionaria *= base2;
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

    public static String dbase2base(int base1, int base2, String x) 
    {
        double valorDecimal = base2double(x, base1);
        return double2base(valorDecimal, base2);
    }

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Digite o numero: ");
        String numero = sc.next();

        System.out.print("Digite a base de origem: ");
        int base1 = sc.nextInt();

        System.out.print("Digite a base de destino: ");
        int base2 = sc.nextInt();

        String resultado = dbase2base(base1, base2, numero);
        System.out.println(numero + " (base " + base1 + ") = " + resultado + " (base " + base2 + ")");

        sc.close();
    }
}
