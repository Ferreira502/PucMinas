import java.util.*;

class Data
{
    private int ano;
    private int mes;
    private int dia;
    
    public Data(int ano, int mes, int dia) 
    {
        this.ano = ano;
        this.mes = mes;
        this.dia = dia;    
    }

        public static Data paseData( String s )
        {
            Scanner sc = new Scanner(s);
            sc.useDelimiter("-");
            int ano = sc.nextInt();
            int mes = sc.nextInt();
            int dia = sc.nextInt();

            Data data = new Data(ano, mes, dia);
            
            return data;
        }
        
        public String formatar ()
        {
            String s = String.format("%02d/%02d/%04d", dia,mes,ano);
            return s;
        }
}