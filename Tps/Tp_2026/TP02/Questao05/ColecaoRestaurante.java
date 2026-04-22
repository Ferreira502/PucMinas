import java.io.File;
import java.util.*;

public class ColecaoRestaurante 
{

    private int tamanho;
    private Restaurante[] restaurantes;

    public ColecaoRestaurante(int tamanho, Restaurante[] restaurantes) 
    {
        this.tamanho = tamanho;
        this.restaurantes = restaurantes;
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Retorna a quantidade de restaurantes da colecao
     * @return this.restaurantes
     */
    public int getTamanho() 
    {
        return this.tamanho;
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Mostrar uma frase
     * @return this.restaurantes
     */
    public Restaurante[] getRestaurantes() 
    {
        return this.restaurantes;
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Imprime todos os restaurantes da colecao
     */
    public void imprimir() {
        for (int i = 0; i < this.tamanho; i++) 
        {
            System.out.println(this.restaurantes[i].formatar());
        }
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @param String s
     * @reason Converte uma String para double manualmente
     * @return numero real
     */
    public static double parseDouble(String s)
    {
        int inteiro = 0;
        int decimal = 0;
        boolean ponto = false;
        
        for (int i = 0; i < s.length(); i++)
        {
            char c = s.charAt(i);
            if (c == '.')
            {
                ponto = true;
            }

            else if (ponto == false)
            {
                inteiro = inteiro * 10 + (c - '0');
            }
            else
            {
                decimal = decimal * 10 + (c - '0');
            }
        }
        
        return inteiro + decimal / 10.0;
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Ordena os restaurantes por cidade usando ordenacao por insercao, a chave sendo Cidade
     */
    public static void insercao(Restaurante[] selecionados, int tamanho)
    {
        for ( int i = 1; i < tamanho; i++ )
        {
            Restaurante chave = selecionados[i];
            int j = i - 1;

            while ( j >= 0 && selecionados[j].getCidade().compareTo(chave.getCidade()) > 0 )
            {
                selecionados[j + 1] = selecionados[j];
                j--;
            }

            selecionados[j + 1] = chave;
        }
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @param String path
     * @reason Le o arquivo CSV, cria os restaurantes e configura a colecao
     */
    public void lerCsv(String path) 
    {
        try 
        {
            Scanner sc = new Scanner(new File(path));
            sc.nextLine(); // pula o cabecalho antes de definir o delimitador
            sc.useDelimiter(",|\n");

            for (int i = 0; i < 500; i++) 
            {
                int id = sc.nextInt();
                String nome = sc.next();
                String cidade = sc.next();
                int capacidade = sc.nextInt();
                double avaliacao = parseDouble(sc.next());

                // Tipos Cozinha
                String cozinhaStr = sc.next(); // "churrasco;internacional"
                Scanner scCozinha = new Scanner(cozinhaStr);
                scCozinha.useDelimiter(";");
                String tipo1 = scCozinha.next();
                String tipo2 = scCozinha.next();
                //scCozinha.close();
                String[] tiposCozinha = new String[]{tipo1, tipo2};

                String faixaPreco = sc.next();

                String horario = sc.next(); // "11:00-20:00"

                Scanner scHorario = new Scanner(horario);
                scHorario.useDelimiter("-");

                Hora horarioAbertura = Hora.parseHora(scHorario.next()); // "11:00"
                Hora horarioFechamento = Hora.parseHora(scHorario.next()); // "20:00"

                Data dataAbertura = Data.paseData(sc.next());
                
                String abertoStr = sc.next();

                boolean aberto;
                
                if (abertoStr.charAt(0) == 't')
                {
                    aberto = true;
                }

                else
                {
                    aberto = false;
                }

                this.restaurantes[this.tamanho] = new Restaurante(id, nome, cidade, capacidade, avaliacao, tiposCozinha, faixaPreco, horarioAbertura, horarioFechamento, dataAbertura, aberto);
                this.tamanho++;
            }    
        } 

        catch (Exception e) 
        {
            System.out.println("Erro para abrir o Arquivo");
            return;
        }
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @param String s
     * @reason Le o dataset do arquivo CSV e retorna a colecao com os restaurantes
     * @return colecao
     */
    public static ColecaoRestaurante lerCsv() 
    {
        ColecaoRestaurante colecao = new ColecaoRestaurante(0, new Restaurante[550]);
        colecao.lerCsv("restaurante.csv");
        return colecao;
    }
}
