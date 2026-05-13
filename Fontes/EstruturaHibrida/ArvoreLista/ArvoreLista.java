class Celula
{
    String palavra;
    Celula prox;

    Celula ( String palavra )
    {
        this.palavra = palavra;
        this.prox = null;
    }
}

class No
{
    char elemento;
    No esq;
    No dir;
    Celula primeiro;

    No ( char elemento )
    {
        this.elemento = elemento;
        this.esq = null;
        this.dir = null;
        this.primeiro = null;
    }
}

class Arvore
{
    private No raiz;
    
    Arvore()
    {
        this.raiz = null;
    }


    No pesquisar ( No i, char c)
    {
        if( i == null )
        {
            return null;
        }

        if ( i.elemento == c)
        {
            return i;
        }

        else if ( c < i.elemento )
        {
            return pesquisar(i.esq, c);
        }

        else 
        {
            return pesquisar(i.dir, c);
        }

    }

    void pesquisarLista( No i, String palavra ) 
    {
        Celula ultimo = i.primeiro;

        if (ultimo == null) 
        {
            i.primeiro = new Celula(palavra);
            return;
        }
        
        while (ultimo.prox != null) 
        {
            ultimo = ultimo.prox;
        }

        ultimo.prox = new Celula(palavra);
    }

    void contarPalavras( No i, String palavra ) 
    {
        No no = pesquisar(i, palavra.charAt(0));

        if (no != null) 
        {
            pesquisarLista(no, palavra); // pesquisar e inserir palavra no final da lista sem esta Ordenado
            pesquisarOrdenado(no, palavra); // pesquisar e inserir palavra ordenado, tem que passar apenas o No em vez de passar o apontador
        }
    }

    void pesquisarOrdenado ( No i, String palavra )
    {
        Celula anterior = null;
        Celula atual = i.primeiro;

        while ( atual != null && palavra.compareTo(atual.palavra) > 0 )
        {
            anterior = atual;
            atual = atual.prox;
        }

        Celula nova = new Celula(palavra);
        nova.prox = atual;

        if (anterior == null) 
        {
            i.primeiro = nova; // insere no início
        } 
        
        else 
        {
            anterior.prox = nova; // insere no meio ou fim
        }
    }
 
}

class ArvoreLista
{
   public static void main ( String[] args )
    {}
}
