import java.io.File;
import java.util.*;

public class ColecaoRestaurante 
{

    private int tamanho;
    private Restaurante[] restaurantes;

    public ColecaoRestaurante( int tamanho, Restaurante[] restaurantes ) 
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
    public void imprimir() 
    {
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
    public double parseDouble(String s)
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
     * @reason Ordena os restaurantes por cidade usando ordenacao por heapSort, a chave sendo Cidade
     */
    public static int comparar( Restaurante a, Restaurante b )
    {
        int cmp = a.getCidade().compareTo(b.getCidade());
        if (cmp != 0)
        {
            return cmp;
        }

        return a.getNome().compareTo(b.getNome());
    }

    public static void heap( Restaurante[] selecionados, int tamanho )
    {
        int n = tamanho;
        Restaurante[] chave = new Restaurante[n + 1];
        for (int i = 0; i < n; i++)
        {
            chave[i + 1] = selecionados[i];
        }

        // Construcao do heap
        for (int tamHeap = 2; tamHeap <= n; tamHeap++)
        {
            construir(chave, tamHeap);
        }

        // Ordenacao propriamente dita
        int tamHeap = n;
        while (tamHeap > 1)
        {
            Restaurante tmp = chave[1];
            chave[1] = chave[tamHeap];
            chave[tamHeap] = tmp;
            tamHeap--;
            reconstruir(chave, tamHeap);
        }

        // Alterar o vetor para voltar a posicao zero
        for (int i = 0; i < n; i++)
        {
            selecionados[i] = chave[i + 1];
        }
    }

    public static void construir( Restaurante[] chave, int tamHeap )
    {
        for (int i = tamHeap; i > 1 && comparar(chave[i], chave[i / 2]) > 0; i /= 2)
        {
            Restaurante tmp = chave[i];
            chave[i] = chave[i / 2];
            chave[i / 2] = tmp;
        }
    }

    public static void reconstruir( Restaurante[] chave, int tamHeap )
    {
        int i = 1;

        while (i <= (tamHeap / 2))
        {
            int filho = getMaiorFilho(chave, i, tamHeap);
            
            if (comparar(chave[i], chave[filho]) < 0)
            {
                Restaurante tmp = chave[i];
                chave[i] = chave[filho];
                chave[filho] = tmp;
                i = filho;
            }

            else
            {
                i = tamHeap;
            }
        }
    }

    public static int getMaiorFilho( Restaurante[] chave, int i, int tamHeap )
    {
        int filho;

        if (2 * i == tamHeap || comparar(chave[2 * i], chave[2 * i + 1]) > 0)
        {
            filho = 2 * i;
        }
        
        else
        {
            filho = 2 * i + 1;
        }

        return filho;
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
