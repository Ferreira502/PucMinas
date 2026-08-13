public class Guia_0301 
{
    public static int C1(int nbits, int x) 
    {
        int mask = (1 << nbits) - 1;
        return (~x) & mask;
    }

    public static int C2(int nbits, int x) 
    {
        int mask = (1 << nbits) - 1;
        return (C1(nbits, x) + 1) & mask;
    }

    public static void mostrarComplementos(int nbits, int x) 
    {
        int c1 = C1(nbits, x);
        int c2 = C2(nbits, x);

        String formatoBin = "%"+nbits+"s";

        System.out.println("Valor original (" + nbits + " bits): " + x + " -> " 
                           + String.format(formatoBin, Integer.toBinaryString(x)).replace(' ', '0'));
        System.out.println("Complemento de 1 (C1): " + c1 + " -> " 
                           + String.format(formatoBin, Integer.toBinaryString(c1)).replace(' ', '0'));
        System.out.println("Complemento de 2 (C2): " + c2 + " -> " 
                           + String.format(formatoBin, Integer.toBinaryString(c2)).replace(' ', '0'));
    }

    public static void main(String[] args) 
    {
        int nbits = 4;
        int x = 5;

        mostrarComplementos(nbits, x);
    }
}
