public class Guia_0304 {

    public static int str2dec(String num, int base) 
    {
        return Integer.parseInt(num, base);
    }

    public static String dec2str(int num, int base) 
    {
        return Integer.toString(num, base).toUpperCase();
    }

    public static String baseEval(String x, String op, String y, int base) 
    {
        int a = str2dec(x, base);
        int b = str2dec(y, base);
        int resultado = 0;

        if (op.equals("-")) 
        {
            resultado = a - b;
        } 
        else 
        {
            throw new IllegalArgumentException("Operação nao suportada: " + op);
        }

        return dec2str(resultado, base);
    }

    public static void main(String[] args) 
    {
        String x1 = "1010";
        String y1 = "0110";
        int base1 = 2;

        System.out.println(x1 + " - " + y1 + " (base " + base1 + ") = " + baseEval(x1, "-", y1, base1));

        String x2 = "25";
        String y2 = "7";
        int base2 = 10;

        System.out.println(x2 + " - " + y2 + " (base " + base2 + ") = " + baseEval(x2, "-", y2, base2));

        String x3 = "1F";
        String y3 = "A";  
        int base3 = 16;

        System.out.println(x3 + " - " + y3 + " (base " + base3 + ") = " + baseEval(x3, "-", y3, base3));
    }
}
