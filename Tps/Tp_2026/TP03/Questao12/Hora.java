import java.util.*;

class Hora
{
    private int hora;
    private int minuto;

    /**
     * @author Gabriel Ferreira Pereira
     * @param hora e minuto da hora
     * @reason Construtor da classe Hora
     */
    public Hora ( int hora, int minuto )
    {
        this.hora = hora;
        this.minuto = minuto;
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @param s String no formato HH:mm
     * @reason Converte uma String para um objeto Hora
     * @return objeto Hora correspondente
     */
    public static Hora parseHora ( String s )
    {
        Scanner sc = new Scanner(s);
        sc.useDelimiter(":");
        int hora1 = sc.nextInt();
        int minuto = sc.nextInt();

        Hora hora = new Hora(hora1, minuto);

        return hora;
    }
    
    /**
     * @author Gabriel Ferreira Pereira
     * @reason Retorna a hora no formato HH:mm
     * @return String com a hora formatada
     */
    public String formatarHora ()
    {
        String s = String.format("%02d:%02d", hora, minuto);
        return s;
    }
}