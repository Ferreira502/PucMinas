/* 
  Guia_0202.java 
     842527 - Gabriel Ferreira Pereira
*/ 


import java.util.Scanner;

public class Guia_0202 
{
    public static String double2bin(double x) 
    {
        int parteInteira = (int) x; 
        double parteFracionaria = x - parteInteira;

        StringBuilder binario = new StringBuilder();

        if (parteInteira == 0) 
        {
            binario.append("0");
        } 
        else 
        {
            StringBuilder temp = new StringBuilder();
            while (parteInteira > 0) 
            {
                int resto = parteInteira % 2;
                temp.append(resto);
                parteInteira = parteInteira / 2;
            }
            binario.append(temp.reverse());
        }

        if (parteFracionaria > 0) 
        {
            binario.append(".");
            int limite = 20;
            while (parteFracionaria > 0 && limite > 0) 
            {
                parteFracionaria = parteFracionaria * 2;
                if (parteFracionaria >= 1) 
                {
                    binario.append("1");
                    parteFracionaria = parteFracionaria - 1;
                } 
                else 
                {
                    binario.append("0");
                }
                limite--;
            }
        }

        return binario.toString();
    }

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Digite um numero decimal: ");
        double numero = sc.nextDouble();

        String resultado = double2bin(numero);
        System.out.println(numero + " em binario e: " + resultado);

        sc.close();
    }
}