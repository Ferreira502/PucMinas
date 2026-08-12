import java.util.*;

class Celula
{
    public int elemento;
    public Celula dir, esq, sup, inf;

    public Celula()
    {
        this.elemento = 0;
        this.dir = this.esq = this.sup = this.inf = null;
    }
}

class Matriz
{
    private Celula inicio;
    private int linhas;
    private int colunas;

    /**
     * @author Gabriel Ferreira Pereira
     * @param linhas, colunas
     * @reason Construtor que aloca e conecta todas as celulas da matriz
     */
    public Matriz( int linhas, int colunas )
    {
        this.linhas  = linhas;
        this.colunas = colunas;
        matrizFlex(linhas, colunas);
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @param linha, coluna
     * @reason Cria a matriz flexivel encadeada
     */
    public void matrizFlex( int linha, int coluna )
    {
        inicio = new Celula();
        Celula tmp = inicio;

        for ( int j = 1; j < coluna; j++ )
        {
            tmp.dir = new Celula();
            tmp.dir.esq = tmp;
            tmp = tmp.dir;
        }

        Celula linhaCima = inicio;

        for ( int i = 1; i < linha; i++ )
        {
            Celula novaLinha = new Celula();
            linhaCima.inf = novaLinha;
            novaLinha.sup = linhaCima;

            Celula atual = novaLinha;
            Celula tmpCima = linhaCima;

            for ( int j = 1; j < coluna; j++ )
            {
                atual.dir = new Celula();
                atual.dir.esq = atual;
                atual = atual.dir;

                tmpCima = tmpCima.dir;
                atual.sup = tmpCima;
                tmpCima.inf = atual;
            }

            linhaCima = linhaCima.inf;
        }
}

    /**
     * @author Gabriel Ferreira Pereira
     * @param linha, coluna
     * @reason Navega ate a celula da posicao indicada
     */
    private Celula getCelula( int linha, int coluna )
    {
        Celula c = this.inicio;

        for ( int i = 0; i < linha;  i++ ) 
        {
            c = c.inf;
        }

        for ( int j = 0; j < coluna; j++ ) 
        {
            c = c.dir;
        }

        return c;
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @param linha, coluna, valor
     * @reason Define o valor de uma celula
     */
    public void set( int linha, int coluna, int valor )
    {
        getCelula( linha, coluna ).elemento = valor;
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @param linha, coluna
     * @reason Retorna o valor de uma celula
     */
    public int get( int linha, int coluna )
    {
        return getCelula( linha, coluna ).elemento;
    }

    public int getLinhas()  
    { 
        return this.linhas; 
    }

    public int getColunas() 
    { 
        return this.colunas; 
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Exibe a matriz linha por linha
     */
    public void mostrar()
    {
        Celula tmpLinha = inicio;

        for ( int i = 0; i < linhas; i++ )
        {
            Celula tmpColuna = tmpLinha;

            for ( int j = 0; j < colunas; j++ )
            {
                System.out.print(tmpColuna.elemento + " ");
                tmpColuna = tmpColuna.dir;
            }

            System.out.println();
            tmpLinha = tmpLinha.inf;
        }
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Imprime a diagonal principal da matriz
     */
    public void mostrarDiagonalPrincipal()
    {
        Celula i = inicio;

        int min = 0;

        if ( linhas < colunas )
        {
            min = linhas;
        }

        else
        {
            min = colunas;
        }

        for ( int k = 0; k < min; k++ )
        {
            System.out.print(i.elemento + " ");

            if ( k < min - 1 )
            {
                i = i.inf;
                i = i.dir;
            }
        }

        System.out.println();
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @reason Imprime a diagonal secundaria da matriz
     */
    public void mostrarDiagonalSecundaria()
    {
        Celula i = inicio;

        for ( int j = 1; j < colunas; j++ )
        {
            i = i.dir;
        }

        int min = 0;

        if ( linhas < colunas )
        {
            min = linhas;
        }

        else
        {
            min = colunas;
        }

        for ( int k = 0; k < min; k++ )
        {
            System.out.print(i.elemento + " ");

            if ( k < min - 1 )
            {
                i = i.inf;
                i = i.esq;
            }
        }

        System.out.println();
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @param m Matriz a ser somada
     * @reason Soma esta matriz com m e retorna a resultante
     */
    public Matriz somar( Matriz m )
    {
        Matriz resultado = new Matriz( this.linhas, this.colunas );

        Celula tmpLinhaA = this.inicio;
        Celula tmpLinhaB = m.inicio;
        Celula tmpLinhaR = resultado.inicio;

        for ( int i = 0; i < linhas; i++ )
        {
            Celula a = tmpLinhaA;
            Celula b = tmpLinhaB;
            Celula r = tmpLinhaR;

            for ( int j = 0; j < colunas; j++ )
            {
                r.elemento = a.elemento + b.elemento;
                a = a.dir;
                b = b.dir;
                r = r.dir;
            }

            tmpLinhaA = tmpLinhaA.inf;
            tmpLinhaB = tmpLinhaB.inf;
            tmpLinhaR = tmpLinhaR.inf;
        }

        return resultado;
    }

    /**
     * @author Gabriel Ferreira Pereira
     * @param m Matriz a ser multiplicada
     * @reason Multiplica esta matriz por m e retorna a resultante
     */
    public Matriz multiplicar( Matriz m )
    {
        Matriz resultado = new Matriz( this.linhas, m.getColunas() );

        for ( int i = 0; i < this.linhas; i++ )
        {
            for ( int j = 0; j < m.getColunas(); j++ )
            {
                int soma = 0;

                for ( int k = 0; k < this.colunas; k++ )
                {
                    soma += this.get(i, k) * m.get(k, j);
                }

                resultado.set( i, j, soma );
            }
        }

        return resultado;
    }
}

class Questao09
{
    public static void main( String[] args )
    {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        for ( int i = 0; i < t; i++ )
        {
            int l = sc.nextInt();
            int c = sc.nextInt();

            Matriz a = new Matriz(l, c);

            for ( int j = 0; j < l; j++ )
            {
                for ( int k = 0; k < c; k++ )
                {
                    a.set( j, k, sc.nextInt() );
                }
            }

            Matriz b = new Matriz(l, c);

            for ( int x = 0; x < l; x++ )
            {
                for ( int m = 0; m < c; m++ )
                {
                    b.set( x, m, sc.nextInt() );
                }
            }

            a.mostrarDiagonalPrincipal();
            b.mostrarDiagonalSecundaria();

            a.somar(b).mostrar();
            a.multiplicar(b).mostrar();
        }
    }
}