import java.util.*;

class Data
{
    private int ano;
    private int mes;
    private int dia;
    
    /**
     * @author Gabriel Ferreira Pereira
     * @param ano mes e dia da data
     * @reason Construtor da classe Data
     */
    public Data ( int ano, int mes, int dia ) 
    {
        this.ano = ano;
        this.mes = mes;
        this.dia = dia;    
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @param s String no formato YYYY-MM-DD
     * @reason Converte uma String para um objeto Data
     * @return objeto Data correspondente
     */
    public static Data parseData( String s )
    {
        Scanner sc = new Scanner(s);
        sc.useDelimiter("-");
        int ano = sc.nextInt();
        int mes = sc.nextInt();
        int dia = sc.nextInt();

        Data data = new Data ( ano, mes, dia );
        
        return data;
    }
    
    /**
     * @author Gabriel Ferreira Pereira
     * @reason Retorna a data no formato DD/MM/YYYY
     * @return String com a data formatada
     */
    public String formatarData ()
    {
        String s = String.format("%02d/%02d/%04d", dia,mes,ano);
        return s;
    }
}