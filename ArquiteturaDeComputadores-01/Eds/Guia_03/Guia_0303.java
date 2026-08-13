public class Guia_0303 
{

    public static int str2dec(String num, int base) 
    {
        return Integer.parseInt(num, base);
    }

    public static String dec2str(int num, int base, int nbits) 
    {
        String bin = Integer.toBinaryString(num & ((1 << nbits) - 1));
        if (base != 2) 
        { 
            return Integer.toString(Integer.parseInt(bin, 2), base).toUpperCase();
        }
        return String.format("%" + nbits + "s", bin).replace(' ', '0');
    }

    public static int C2(int x, int nbits) 
    {
        int mask = (1 << nbits) - 1;
        return ((~x) + 1) & mask;
    }

    public static String baseEvalC2(String xStr, String yStr, int base, int nbits) 
    {
        int x = str2dec(xStr, base);
        int y = str2dec(yStr, base);

        int resultado = (x + C2(y, nbits)) & ((1 << nbits) - 1);

        return dec2str(resultado, base, nbits);
    }

    public static void main(String[] args) 
    {
        String x = "1010";
        String y = "0110";
        int base = 2;
        int nbits = 4;

        String resultado = baseEvalC2(x, y, base, nbits);
        System.out.println(x + " - " + y + " usando C2 = " + resultado);
    }
}
