class Celula 
{
    public int elemento;
    public Celula inf, sup, esq, dir;

    public Celula() 
    {
        this(0);
    }

    public Celula(int elemento) 
    {
        this.elemento = elemento;
        this.inf = this.sup = this.esq = this.dir = null;
    }
}

class Matriz 
{
    private Celula inicio;
    private int linha, coluna;

    public Matriz() 
    {
        this(3, 3);
    }

    public Matriz(int linha, int coluna) 
    {
        this.linha = linha;
        this.coluna = coluna;
        matrizFlex(linha, coluna);
    }

    //Criar Matriz Flexivel
    public void matrizFlex(int linha, int coluna) 
    {
        inicio = new Celula();
        Celula tmp = inicio;

        for (int i = 0; i < linha; i++)
        {
            tmp.dir = new Celula();
            tmp.dir.esq = tmp;
            tmp = tmp.dir;
        }

        Celula linhaCima = inicio;
        for (int j = 1; j < linha; j++) 
        {
            Celula novaLinha = new Celula();
            linhaCima.inf = novaLinha;
            novaLinha.sup = linhaCima;

            Celula atual = novaLinha;
            Celula tmpCima = linhaCima.dir;

            for (int k = 0; k < coluna; k++) 
            {
                atual.dir = new Celula();
                atual.dir.esq = atual;
                atual = atual.dir;

                atual.sup = tmpCima;
                tmpCima.inf = atual;

                tmpCima = tmpCima.dir;
            }

            linhaCima = linhaCima.inf;
        }
    }

    // preencher matriz
    public void preencherMatriz(int linha, int coluna, int x) 
    {
        Celula tmpLinha = inicio;
        Celula tmpColuna;

        for (int i = 0; i < linha; i++) 
        {
            tmpColuna = tmpLinha;
            for (int j = 0; j < coluna; j++) 
            {
                tmpColuna.elemento = x; //para fazer o usuario  digitar a matriz em vez de passar X é so colocar tmpColuna.elemento = sc.nextInt();
                tmpColuna = tmpColuna.dir;
            }
            tmpLinha = tmpLinha.inf;
        }
    }

    // mostra elemento da matriz
    public void mostrar(int linha, int coluna) 
    {
        Celula tmpLinha = inicio;
        Celula tmpColuna;

        for (int i = 0; i < linha; i++) 
        {
            tmpColuna = tmpLinha;
            for (int j = 0; j < coluna; j++) 
            {
                System.out.print(tmpColuna.elemento + " ");
                tmpColuna = tmpColuna.dir;
            }
            System.out.println();
            tmpLinha = tmpLinha.inf;
        }
    }

    // pegar Diagonal Principal
    public void diagonalPrincipal(int linha, int coluna) 
    {
        Celula inicio = new Celula();
        Celula tmp = inicio;
        while (tmp != null) 
        {
            System.out.print(tmp.elemento + " ");
            if (tmp.dir != null && tmp.inf != null) 
            {
                tmp = tmp.dir.inf;
            } 
            else 
            {
                break;
            }
        }

    }

    // pegar Diagonal Secundaria
    public void diagonalSecundaria(int linha, int coluna) 
    {
        Celula inicio = new Celula();
        Celula tmp = inicio;
        while(tmp.dir != null)
        {
            tmp = tmp.dir;
        }
        
        while (tmp != null) 
        {
            Celula atual = tmp;
            System.out.print(tmp.elemento + " ");
            if (atual.esq != null && atual.inf != null) 
            {
                atual = atual.esq.inf;
            } 
            else 
            {
                break;
            }
        }
    }

    // Remover elemento da matriz (zera o valor da célula)
    public void removerElemento(int linha, int coluna) {
        if (linha < 0 || linha >= this.linha || coluna < 0 || coluna >= this.coluna) {
            System.out.println("Posição inválida!");
            return;
        }
    
        Celula tmpLinha = inicio;
        for (int i = 0; i < linha; i++) {
            tmpLinha = tmpLinha.inf;
        }
    
        Celula tmpColuna = tmpLinha;
        for (int j = 0; j < coluna; j++) {
            tmpColuna = tmpColuna.dir;
        }
    
        tmpColuna.elemento = 0; // "Remove" o elemento
        System.out.println("Elemento removido da posição [" + linha + "][" + coluna + "]");
    }

        // Remove todas as ocorrências de um valor na matriz
    public void removerValor(int valor) {
        Celula tmpLinha = inicio;
        boolean encontrado = false;
    
        for (int i = 0; i < linha; i++) {
            Celula tmpColuna = tmpLinha;
            for (int j = 0; j < coluna; j++) {
                if (tmpColuna.elemento == valor) {
                    tmpColuna.elemento = 0; // "Remove" o valor
                    encontrado = true;
                    System.out.println("Valor " + valor + " removido da posição [" + i + "][" + j + "]");
                }
                tmpColuna = tmpColuna.dir;
            }
            tmpLinha = tmpLinha.inf;
        }
    
        if (!encontrado) {
            System.out.println("Valor " + valor + " não encontrado na matriz.");
        }
    }

    // Mostrar uma coluna específica da matriz
    public void mostrarColuna(int colunaSelecionada) {
        if (colunaSelecionada < 0 || colunaSelecionada >= this.coluna) {
            System.out.println("Índice de coluna inválido!");
            return;
        }

        Celula tmpLinha = inicio;

        // Caminha até a coluna desejada
        for (int j = 0; j < colunaSelecionada; j++) {
            tmpLinha = tmpLinha.dir;
        }

        // Agora tmpLinha está no topo da coluna desejada
        System.out.println("Coluna " + colunaSelecionada + ":");
        while (tmpLinha != null) {
            System.out.println(tmpLinha.elemento);
            tmpLinha = tmpLinha.inf;
        }
    }

    // Remove o elemento de uma coluna e linha específica
    public void removerElementoColuna(int linhaRemover, int colunaRemover) {
        if (linhaRemover < 0 || linhaRemover >= this.linha || 
            colunaRemover < 0 || colunaRemover >= this.coluna) {
            System.out.println("Posição inválida!");
            return;
        }

        Celula tmp = inicio;

        // Caminha até a coluna desejada
        for (int j = 0; j < colunaRemover; j++) {
            tmp = tmp.dir;
        }

        // Caminha até a linha desejada
        for (int i = 0; i < linhaRemover; i++) {
            tmp = tmp.inf;
        }

        // "Remove" o valor (zera o conteúdo)
        tmp.elemento = 0;
        System.out.println("Elemento da posição [" + linhaRemover + "][" + colunaRemover + "] removido!");
    }


    // Remove uma coluna inteira da matriz
    public void removerColuna(int colunaRemover) {
        if (colunaRemover < 0 || colunaRemover >= this.coluna) {
            System.out.println("Índice de coluna inválido!");
            return;
        }

        // Caso especial: remover a primeira coluna (coluna 0)
        if (colunaRemover == 0) {
            Celula linhaAtual = inicio;
            while (linhaAtual != null) {
                Celula remover = linhaAtual;
                linhaAtual = linhaAtual.inf;

                // Move o início da linha para a direita
                inicio = remover.dir;
                if (inicio != null) inicio.esq = null;

                // Desconecta completamente a célula
                remover.dir = remover.esq = remover.inf = remover.sup = null;
            }
        } else {
            Celula linhaAtual = inicio;

            // Percorre todas as linhas da matriz
            for (int i = 0; i < linha; i++) {
                Celula tmp = linhaAtual;

                // Caminha até a célula anterior à coluna que será removida
                for (int j = 0; j < colunaRemover - 1; j++) {
                    tmp = tmp.dir;
                }

                Celula remover = tmp.dir; // célula a remover

                if (remover != null) {
                    // Conecta a célula da esquerda com a da direita
                    tmp.dir = remover.dir;
                    if (remover.dir != null) remover.dir.esq = tmp;

                    // Desconecta as referências verticais
                    if (remover.sup != null) remover.sup.inf = remover.inf;
                    if (remover.inf != null) remover.inf.sup = remover.sup;

                    // Quebra todas as ligações da célula removida
                    remover.dir = remover.esq = remover.sup = remover.inf = null;
                }

                // Desce para a próxima linha
                linhaAtual = linhaAtual.inf;
            }
        }

        this.coluna--; // Atualiza o número total de colunas
        System.out.println("Coluna " + colunaRemover + " removida com sucesso!");
    }

    public static void main(String[] args) 
    {
        int valores = 1;
        Matriz m = new Matriz(3, 3);
        m.preencherMatriz(3, 3, valores);
        m.mostrar(3, 3);
        m.diagonalPrincipal(3, 3);
        m.diagonalSecundaria(3, 3);

        // m.removerColuna(1); // remove a segunda coluna
        // System.out.println("\nApós remover a coluna 1:");
        // m.mostrar(3, 3);
    }
}