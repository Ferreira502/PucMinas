public class Guia_0302 
{

    public static int C1(int nbits, int x, int basex) 
    {
        int valor = Integer.parseInt(Integer.toString(x), basex);
        int mask = (1 << nbits) - 1;
        return (~valor) & mask;
    }

    public static int C2(int nbits, int x, int basex) 
    {
        int mask = (1 << nbits) - 1;
        return (C1(nbits, x, basex) + 1) & mask;
    }

    public static void mostrarComplementos(int nbits, int x, int basex) 
    {
        int valor = Integer.parseInt(Integer.toString(x), basex);
        int c1 = C1(nbits, x, basex);
        int c2 = C2(nbits, x, basex);

        String formatoBin = "%"+nbits+"s";

        System.out.println("Valor original (" + nbits + " bits, base " + basex + "): " 
                           + valor + " -> " + String.format(formatoBin, Integer.toBinaryString(valor)).replace(' ', '0'));
        System.out.println("Complemento de 1 (C1): " + c1 + " -> " + String.format(formatoBin, Integer.toBinaryString(c1)).replace(' ', '0'));
        System.out.println("Complemento de 2 (C2): " + c2 + " -> " + String.format(formatoBin, Integer.toBinaryString(c2)).replace(' ', '0'));
    }

    public static void main(String[] args) 
    {
        int nbits = 4;
        int x = 5; 
        int basex = 10; 

        mostrarComplementos(nbits, x, basex);
    }
}