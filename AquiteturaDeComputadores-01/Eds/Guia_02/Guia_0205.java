/* 
  Guia_0205.java 
     842527 - Gabriel Ferreira Pereira
*/ 

import java.util.Scanner;

public class Guia_0205 
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

    public static String double2bin(double valor) 
    {
        double parteInteira = Math.floor(valor);
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
                int resto = (int)(parteInteira % 2);
                sb.insert(0, resto);
                parteInteira = Math.floor(parteInteira / 2);
            }
        }

        if (parteFracionaria > 0) 
        {
            sb.append(".");
            int count = 0;
            while (parteFracionaria > 0 && count < 10) 
            {
                parteFracionaria *= 2;
                int digito = (int) parteFracionaria;
                sb.append(digito);
                parteFracionaria -= digito;
                count++;
            }
        }

        return sb.toString();
    }

    public static String dbinEval(String bin1, String operador, String bin2) 
    {
        double val1 = bin2double(bin1);
        double val2 = bin2double(bin2);
        double resultado = 0.0;

        if (operador.equals("+")) 
        {
            resultado = val1 + val2;
        } 
        else if (operador.equals("-")) 
        {
            resultado = val1 - val2;
        } 
        else if (operador.equals("*")) 
        {
            resultado = val1 * val2;
        } 
        else if (operador.equals("/")) 
        {
            resultado = val1 / val2;
        } 
        else if (operador.equals("%")) 
        {
            resultado = val1 % val2;
        } 
        else 
        {
            return "Operador invalido";
        }

        return double2bin(resultado);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Digite o primeiro binario: ");
        String bin1 = sc.next();

        System.out.print("Digite o operador (+, -, *, /, %): ");
        String operador = sc.next();

        System.out.print("Digite o segundo binario: ");
        String bin2 = sc.next();

        String resultado = dbinEval(bin1, operador, bin2);
        System.out.println(bin1 + " " + operador + " " + bin2 + " = " + resultado + " (binario)");

        sc.close();
    }
}
