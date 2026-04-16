import java.util.*;

class Hora
{
    private int hora;
    private int minuto;
    
    public Hora(int hora, int minuto) 
    {
        this.hora = hora;
        this.minuto = minuto;
    }

    public static Hora paseHora( String s )
    {
        Scanner sc = new Scanner(s);
        sc.useDelimiter("-");
        int hora1 = sc.nextInt();
        int minuto = sc.nextInt();

        Hora hora = new Hora(hora1, minuto);

        return hora;
    }
    
    
    public String formatar ()
    {
        String s = String.format("%02d:%02d", hora, minuto);
        return s;
    }
}