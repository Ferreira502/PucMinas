class Hash
{
   String tabela[];
   int m;
   int r;
   int nr;

   public Hash( int m, int r ) 
   {
      this.m = m;
      this.r = r;
      this.nr = 0;
      this.tabela = new String[m + r];
   }

   private int hash ( String chave )
   {
      int x = 0;


      for (int i = 0; i < chave.length(); i++) 
      {
         char caractere = chave.charAt(i);
         x += caractere;
      }

      // System.out.println("Chave: " + chave);
      // System.out.println("Soma: " + x);


      x = x % m;

      // System.out.println("Posicao hash: " + x);

      return x;
   }

   private boolean isPosicaoLivre( int pos )
   {
      boolean resp = true;

      if ( tabela[pos] != null )
      {
         resp = false;
      }

      return resp;
   }

   public void inserir ( String chave ) throws Exception
   {
      int pos = hash(chave);
      // System.out.println("\nInserindo: " + chave);
      // System.out.println("Posicao: " + pos);

      if ( pesquisar(chave) != null )
      {
         // System.out.println("Erro: " + chave);
         throw new Exception("repetido");
      }

      if ( isPosicaoLivre(pos) == true )
      {
         // System.out.println("Inseriu posicao: " + pos);
         tabela[pos] = chave;
      }

      else
      {
         // System.out.println("Colisao posicao: " + pos);
         if ( nr < r )
         {
            // System.out.println("Inseriu reserva posicao: " + ( m + nr ));
            tabela[m + nr] = chave;
            nr++;
            // System.out.println("Reserva usada: " + nr + " " + r);
         }

         else 
         {
            throw new Exception("ta cheia");
         }
      }
   }

   public String pesquisar ( String chave )
   {
      int pos = hash(chave);
      String resp = null;
      // System.out.println("\nPesquisando: " + chave);
      // System.out.println("Posicao: " + pos);

      if ( tabela[pos] != null && tabela[pos].compareTo(chave) == 0 )
      {
         // System.out.println("principal posicao: " + pos);
         resp = tabela[pos];
      }

      else 
      {
         // System.out.println("To aq");
         for ( int i = 0; i < nr; i++ )
         {
            // System.out.println("Testando reserva posicao: " + (m + i));
            if ( tabela[m + i] != null && tabela[m + i].compareTo(chave) == 0 )
            {
               // System.out.println("reserva posicao: " + (m + i));
               resp = tabela[m + i];
               i = nr;
            }
         }
      }

      // System.out.println("Resultado pesquisa: " + resp);

      return resp;
   }

   public String remover ( String chave )
   {
      int pos = hash(chave);
      String resp = null;
      // System.out.println("\nRemovendo: " + chave);
      // System.out.println("Posicao: " + pos);

      if ( tabela[pos] != null && tabela[pos].compareTo(chave) == 0 )
      {
         // System.out.println("Removeu posicao: " + pos);
         resp = tabela[pos];
         tabela[pos] = null;

         for ( int i = 0; i < nr; i++ )
         {
            if ( tabela[m + i ] != null &)
         }
      }

      else
      {
         // System.out.println("To aq");
         for ( int i = 0; i < nr; i++ )
         {
            if ( tabela[m + i] != null && tabela[m + i].compareTo(chave) == 0 )
            {
               // System.out.println("posicao: " + ( m + i ));
               resp = tabela[m + i];
               tabela[m + i] = null;

               // System.out.println("reserva: " + nr + " " + r);
            }
         }
      }

      // System.out.println("remocao: " + resp);

      return resp;
   }

   public void mostrar()
   {
      System.out.println("Indice\tArea\t\tConteudo");

      for ( int i = 0; i < m + r; i++ )
      {
         System.out.print(i + "\t");

         if ( i < m )
         {
            System.out.print("Principal\t");
         }

         else
         {
            System.out.print("Reserva\t\t");
         }

         if ( tabela[i] == null )
         {
            System.out.println("--");
         }

         else
         {
            System.out.println(tabela[i]);
         }
      }
   }
}

class Main 
{
   public static void main(String[] args) throws Exception
   {
      Hash hash = new Hash(11, 3);

      hash.inserir("Brasil");
      hash.inserir("Canada");
      hash.inserir("Franca");
      hash.inserir("China");
      hash.inserir("Egito");
      hash.inserir("Australia");
      hash.inserir("Alemanha");
      hash.inserir("Japao");
      hash.inserir("Mexico");
      hash.inserir("Marrocos");


      // hash.pesquisar("Brasil");
      // hash.pesquisar("Canada");
      // hash.pesquisar("Franca");
      // hash.pesquisar("China");
      // hash.pesquisar("Egito");
      // hash.pesquisar("Australia");
      // hash.pesquisar("Alemanha");
      // hash.pesquisar("Japao");
      // hash.pesquisar("Mexico");
      // hash.pesquisar("Marrocos");
      // hash.pesquisar("Estados Unidos");
      // hash.pesquisar("Argentina");
      hash.remover("Brasil");
      hash.remover("China");
      hash.remover("Alemanha");
      hash.inserir("Espanha");

      hash.mostrar();
   }
}
