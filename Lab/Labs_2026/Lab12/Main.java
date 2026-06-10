import java.util.*;

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
      // int x = 0;
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
            // x++;
            // System.out.println("x: " + x);
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

      if ( tabela[pos] == null )
      {
         resp = null;
      }

      else if ( tabela[pos] != null && tabela[pos].compareTo(chave) == 0 )
      {
         // System.out.println("principal posicao: " + pos);
         resp = tabela[pos];
      }

      else if ( tabela[pos].compareTo(chave) != 0 )
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

      if ( tabela[pos] == null )
      {
         resp = null;
      }

      else if ( tabela[pos].compareTo(chave) == 0 )
      {
         // System.out.println("Removeu posicao: " + pos);
         resp = tabela[pos];
         tabela[pos] = null;

         for ( int i = 0; i < nr; i++ )
         {
           // System.out.println("To aq");

            int x = hash(tabela[m + i]);

            if ( x == pos )
            {
               int y = m + i;

               tabela[pos] = tabela[y];
               
               for ( int j = y; j < m + nr - 1; j++ )
               {
                  tabela[j] = tabela[j + 1];
               }
               
               tabela[m + nr - 1 ] = null;

               nr--;
               i = nr;
               // System.out.println("inseriu na posicao: " + tabela[pos]);
            }
         }
      }

      else if ( tabela[pos].compareTo(chave) != 0 )
      {
         // System.out.println("To aq");
         for ( int i = 0; i < nr; i++ )
         {
            if ( tabela[m + i].compareTo(chave) == 0 )
            {
               // System.out.println("posicao: " + ( m + i ));
               resp = tabela[m + i];
               tabela[m + i] = null;

               int y = m + i;

               for ( int j = y; j < m + nr - 1; j++ )
               {
                  tabela[j] = tabela[j + 1];
               }

               tabela[m + nr - 1] = null;
            
               nr--;
               i = nr;
            }
         }
      }

      // System.out.println("remocao: " + resp);

      return resp;
   }


   public void mostrar()
   {
      for ( int i = 0; i < m + r; i++ )
      {
         System.out.print(i + " ");

         if ( i < m )
         {
            System.out.print("Principal ");
         }

         else
         {
            System.out.print("Reserva ");
         }

         if ( tabela[i] == null )
         {
            System.out.println("-");
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
      Scanner sc = new Scanner(System.in);
      Hash hash = new Hash(11, 3);

      while ( sc.hasNext())
      {
         String palavra;
         palavra = sc.next();
         char c = palavra.charAt(0);

         if ( c == 'I')
         {
            String palavra2;
            palavra2 = sc.next();

            try 
            {
               hash.inserir(palavra2);    
            } 
            catch (Exception e) 
            {
               System.out.println("Erro");
            }
            
         }

         if ( c == 'R')
         {
            String palavra2;
            palavra2 = sc.next();

            try 
            {
               hash.remover(palavra2);    
            } 
            catch (Exception e) 
            {
               System.out.println("Erro");
            }
            
         }

         if ( c == 'P')
         {

            String palavra2;
            palavra2 = sc.next();


            try 
            {
               if ( hash.pesquisar(palavra2).compareTo(palavra2) == 0)
               {
                  System.out.println("Sim");
               }     
            } 
            catch (Exception e) 
            {
               System.out.println("Nao");
            }
         }

         if ( c == 'M')
         {
            hash.mostrar();
         }
      }
   }
}