import java.io.File;
import java.util.*;

class Restaurante
{
    private int id;
    private String nome;
    private String cidade;
    private int capacidade;
    private double avaliacao;
    private String[] tiposCozinha;
    private String faixaPreco;
    private Hora horarioAbertura;
    private Hora horarioFechamento;
    private Data dataAbertura;
    private boolean aberto;
    

    /**
     * @author Gabriel Ferreira Pereira
     * @param id, nome, cidade, capacidade, avaliacao, tiposCozinha, faixaPreco, horarioAbertura, 
     *          horarioFechamento, dataAbertura, aberto do restaurante
     * @reason Construtor da classe Restaurante
     */
    public Restaurante( int id, String nome, String cidade, int capacidade, double avaliacao, 
        String[] tiposCozinha, String faixaPreco, Hora horarioAbertura, Hora horarioFechamento, Data dataAbertura, boolean aberto ) 
    {
        this.id = id;
        this.nome = nome;
        this.cidade = cidade;
        this.capacidade = capacidade;
        this.avaliacao = avaliacao;
        this.tiposCozinha = tiposCozinha;
        this.faixaPreco = faixaPreco;
        this.horarioAbertura = horarioAbertura;
        this.horarioFechamento = horarioFechamento;
        this.dataAbertura = dataAbertura;
        this.aberto = aberto;
    }

    // Getters

    public int getID ()
    {
        return this.id;
    }

    public String getNome ()
    {
        return this.nome;
    }

    public String getCidade ()
    {
        return this.cidade;
    }

    public int getCapacidade ()
    {
        return this.capacidade;
    }

    public double getAvaliacao ()
    {
        return this.avaliacao;
    }

    public String[] getTiposCozinha ()
    {
        return this.tiposCozinha;
    }

    public String getFaixaPreco ()
    {
        return this.faixaPreco;
    }

    public Hora getHorarioAbertura ()
    {
        return this.horarioAbertura;
    }

    public Hora getHorarioFechamento ()
    {
        return this.horarioFechamento;
    }

    public Data getDataAbertura ()
    {
        return this.dataAbertura;
    }

    public boolean getAberto ()
    {
        return this.aberto;
    }
    
    /**
     * @author Gabriel Ferreira Pereira
     * @param String s
     * @reason Converte uma String para double manualmente
     * @return numero real
     */
    public static double parseDouble( String s )
    {
        int inteiro = 0;
        int decimal = 0;
        boolean ponto = false;

        for ( int i = 0; i < s.length(); i++ )
        {
            char c = s.charAt(i);
            if (c == '.')
            {
                ponto = true;
            }
            
            else if ( ponto == false) 
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
     * @param path caminho do arquivo CSV
     * @reason Le uma linha do CSV e cria um objeto Restaurante
     * @return Restaurante criado
     */
    public static Restaurante ler( String linha ) throws Exception
    {
        Scanner sc = new Scanner(linha);
        sc.useDelimiter(",");

        int id = sc.nextInt();
        String nome = sc.next();
        String cidade = sc.next();
        int capacidade = sc.nextInt();
        double avaliacao = parseDouble(sc.next());

        String cozinhaStr = sc.next();
        Scanner scCozinha = new Scanner(cozinhaStr);
        scCozinha.useDelimiter(";");
        String tipo1 = scCozinha.next();
        String tipo2 = scCozinha.next();
        scCozinha.close();
        String[] tiposCozinha = new String[]{tipo1, tipo2};

        String faixaPreco = sc.next();

        String horario = sc.next();
        Scanner scHorario = new Scanner(horario);

        scHorario.useDelimiter("-");

        Hora horarioAbertura   = Hora.parseHora(scHorario.next());
        Hora horarioFechamento = Hora.parseHora(scHorario.next());
        scHorario.close();

        Data dataAbertura = Data.parseData(sc.next());

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

        Restaurante restaurante = new Restaurante(id, nome, cidade, capacidade, avaliacao, tiposCozinha, faixaPreco, horarioAbertura, horarioFechamento, dataAbertura, aberto);
        return restaurante;    
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Retorna o restaurante formatado como String
     * @return String com o restaurante formatado
     */
    public String formatar()
    {
        String tipos = "[" + tiposCozinha[0] + "," + tiposCozinha[1] + "]";
        String horario = horarioAbertura.formatarHora() + "-" + horarioFechamento.formatarHora();
        String data = dataAbertura.formatarData();
    
        return "[" + id + " ## " + nome + " ## " + cidade + " ## " + capacidade + " ## " + 
            avaliacao + " ## " + tipos + " ## " + faixaPreco + " ## " + 
            horario + " ## " + data + " ## " + aberto + "]";
    }

}

class ColecaoRestaurante 
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
     * @return this.tamanho
     */
    public int getTamanho() 
    {
        return this.tamanho;
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @param Restaurante r
     * @reason Adiciona tamanho em ColecaoRestaurante
     */
    public void adicionar( Restaurante r )
    {
        this.restaurantes[this.tamanho] = r;
        this.tamanho++;
    }
    /**
     * @author Gabriel Ferreira Pereira
     * @reason Pega os restaurantes da colecao
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
        for ( int i = 0; i < this.tamanho; i++ ) 
        {
            System.out.println(this.restaurantes[i].formatar());
        }
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Le o dataset do arquivo CSV usando Restaurante.ler() e retorna a colecao
     * @return colecao
     */
    public static ColecaoRestaurante lerCsv() throws Exception
    {
        ColecaoRestaurante colecao = new ColecaoRestaurante(0, new Restaurante[500]);
        Scanner sc = new Scanner(new File("/tmp/restaurantes.csv"));
        
        sc.nextLine();

        sc.useDelimiter(",|\n");

        for ( int i = 0; i < 500; i++ )
        {
            colecao.adicionar(Restaurante.ler(sc.nextLine()));
        }

        return colecao;
    }
}

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

/**
 * Celula Dupla (lista dupla dinamica)
 */
class CelulaDupla 
{
	public Restaurante elemento;
	public CelulaDupla ant;
	public CelulaDupla prox;

	/**
	 * Construtor da classe.
	 */
	public CelulaDupla() 
    {
		this(null);
	}

	/**
	 * Construtor da classe.
	 * @param elemento int inserido na celula.
	 */
	public CelulaDupla(Restaurante elemento) 
    {
		this.elemento = elemento;
		this.ant = this.prox = null;
	}
}

/**
 * Lista dupla dinamica
 */
class Lista
{
	private CelulaDupla primeiro;
	private CelulaDupla ultimo;

	/**
	 * Construtor da classe que cria uma lista dupla sem elementos (somente no cabeca).
	 */
	public Lista(int elemento)
    {
		primeiro = new CelulaDupla();
		ultimo = primeiro;
	}

	/**
	 * Insere um elemento na primeira posicao da lista.
    * @param x int elemento a ser inserido.
	 */
	public void inserirInicio(Restaurante x) 
    {
        CelulaDupla tmp = new CelulaDupla(x);

        tmp.ant = primeiro;
        tmp.prox = primeiro.prox;
        primeiro.prox = tmp;

        if(primeiro == ultimo)
        {
            ultimo = tmp;
        }

        else
        {
            tmp.prox.ant = tmp;
        }
        
        tmp = null;
	}

	/**
	 * Insere um elemento na ultima posicao da lista.
    * @param x int elemento a ser inserido.
	 */
	public void inserirFim(Restaurante x) 
    {
		ultimo.prox = new CelulaDupla(x);
        ultimo.prox.ant = ultimo;
		ultimo = ultimo.prox;
	}


	/**
	 * Remove um elemento da primeira posicao da lista.
    * @return resp int elemento a ser removido.
	 */
	public Restaurante removerInicio()
    {
		if (primeiro == ultimo) 
        {
			System.out.println("ERRO");
		}

        CelulaDupla tmp = primeiro;
		primeiro = primeiro.prox;
		Restaurante resp = primeiro.elemento;
        tmp.prox = primeiro.ant = null;
        tmp = null;
		return resp;
	}


	/**
	 * Remove um elemento da ultima posicao da lista.
    * @return resp int elemento a ser removido.
	 */
	public Restaurante removerFim() 
    {
		if (primeiro == ultimo) 
        {
			System.out.println("ERRO");
		} 

        Restaurante resp = ultimo.elemento;
        ultimo = ultimo.ant;
        ultimo.prox.ant = null;
        ultimo.prox = null;
		return resp;
	}

	/**
    * Insere um elemento em uma posicao especifica considerando que o 
    * primeiro elemento valido esta na posicao 0.
    * @param x int elemento a ser inserido.
	 * @param pos int posicao da insercao.
	 * Se <code>posicao</code> invalida.
	 */
   public void inserir(Restaurante x, int pos) 
   {

        int tamanho = tamanho();

        if(pos < 0 || pos > tamanho)
        {
			System.out.println("ERRO");
        } 
        
        else if (pos == 0)
        {
            inserirInicio(x);
        } 
        else if (pos == tamanho)
        {
            inserirFim(x);
        } 

        else 
        {
		   // Caminhar ate a posicao anterior a insercao
            CelulaDupla i = primeiro;
            for(int j = 0; j < pos; j++, i = i.prox);
		
            CelulaDupla tmp = new CelulaDupla(x);
            tmp.ant = i;
            tmp.prox = i.prox;
            tmp.ant.prox = tmp.prox.ant = tmp;
            tmp = i = null;
      }
   }

	/**
    * Remove um elemento de uma posicao especifica da lista
    * considerando que o primeiro elemento valido esta na posicao 0.
	 * @param posicao Meio da remocao.
    * @return resp int elemento a ser removido.
	 */
	public Restaurante remover(int pos)
    {
        Restaurante resp = null;
        int tamanho = tamanho();

        if (primeiro == ultimo)
        {
            System.out.println("ERRO");

        } 
        else if(pos < 0 || pos >= tamanho)
        {
            System.out.println("ERRO");
        } 
        else if (pos == 0)
        {
            resp = removerInicio();
        } 
        else if (pos == tamanho - 1)
        {
            resp = removerFim();
        } 
        else 
        {
            // Caminhar ate a posicao anterior a insercao
            CelulaDupla i = primeiro.prox;
            for(int j = 0; j < pos; j++, i = i.prox);
            
            i.ant.prox = i.prox;
            i.prox.ant = i.ant;
            resp = i.elemento;
            i.prox = i.ant = null;
            i = null;
        }

		return resp;
	}


	/**
	 * Mostra os elementos da lista separados por espacos.
	 */
	public void mostrar() 
    {
		for (CelulaDupla i = primeiro.prox; i != null; i = i.prox) 
        {
			System.out.println(i.elemento.formatar());
		}
	}

	/**
	 * Calcula e retorna o tamanho, em numero de elementos, da lista.
	 * @return resp int tamanho
	 */
   public int tamanho() 
   {
      int tamanho = 0; 
      for(CelulaDupla i = primeiro; i != ultimo; i = i.prox, tamanho++);
      return tamanho;
   }
}


class Questao08
{
     /**
     * @author Gabriel Ferreira Pereira
     * @reason Metodo principal que busca e formata o restaurante com o ID fornecido
     *         e exibe na tela a lista de restaurantes selecionados
     */
    public static void main(String[] args) throws Exception 
    {
        Scanner sc = new Scanner(System.in);
        ColecaoRestaurante colecao = ColecaoRestaurante.lerCsv();
        Restaurante[] restaurantes = colecao.getRestaurantes();
        Lista lista = new Lista(500);
        int id = 0;

        while ((id = sc.nextInt()) != -1) 
        {
            for (int i = 0; i < colecao.getTamanho(); i++) 
            {
                if (restaurantes[i].getID() == id) 
                {
                    lista.inserirFim(restaurantes[i]);
                }
            }
        }

        int n = sc.nextInt();

        for (int i = 0; i < n; i++) 
        {
            String comando = sc.next();

            if (comando.compareTo("II") == 0) 
            {
                id = sc.nextInt();
                for (int j = 0; j < colecao.getTamanho(); j++) 
                {
                    if (restaurantes[j].getID() == id) 
                    {
                        lista.inserirInicio(restaurantes[j]);
                    }
                }

            } 

            else if (comando.compareTo("I*") == 0) 
            {
                int posicao = sc.nextInt();
                id = sc.nextInt();
                for (int j = 0; j < colecao.getTamanho(); j++) 
                {
                    if (restaurantes[j].getID() == id) 
                    {
                        lista.inserir(restaurantes[j], posicao);
                    }
                }

            } 

            else if (comando.compareTo("IF") == 0) 
            {
                id = sc.nextInt();
                for (int j = 0; j < colecao.getTamanho(); j++) 
                {
                    if (restaurantes[j].getID() == id) 
                    {
                        lista.inserirFim(restaurantes[j]);
                    }
                }
            } 
            
            else if (comando.compareTo("RI") == 0) 
            {
                Restaurante r = lista.removerInicio();
                System.out.println("(R)" + r.getNome());
            } 
            
            else if (comando.compareTo("R*") == 0) 
            {
                int posicao = sc.nextInt();
                Restaurante r = lista.remover(posicao);
                System.out.println("(R)" + r.getNome());
            } 
            
            else if (comando.compareTo("RF") == 0) 
            {
                Restaurante r = lista.removerFim();
                System.out.println("(R)" + r.getNome());
            }
        }

        lista.mostrar();
    }   
}
