#include <stdio.h>
#include <string.h>

#define TAM 100
#define M 11
#define R 3

typedef struct
{
   char tabela[M + R][TAM];
   int ocupado[M + R];
   int m;
   int r;
   int nr;
} Hash;

void copiarString ( char destino[], char origem[] )
{
   int i = 0;

   while ( origem[i] != '\0' )
   {
      destino[i] = origem[i];
      i++;
   }

   destino[i] = '\0';
}

void start ( Hash *hash, int m, int r )
{
   hash->m = m;
   hash->r = r;
   hash->nr = 0;

   for ( int i = 0; i < m + r; i++ )
   {
      hash->tabela[i][0] = '\0';
      hash->ocupado[i] = 0;
   }
}

int hash ( char chave[], Hash *h )
{
   int x = 0;

   for ( int i = 0; i < strlen ( chave ); i++ )
   {
      char caractere = chave[i];
      x += caractere;
   }

   x = x % h->m;

   return x;
}

int isPosicaoLivre ( int pos, Hash *h )
{
   int resp = 1;

   if ( h->ocupado[pos] == 1 )
   {
      resp = 0;
   }

   return resp;
}

char *pesquisar ( char chave[], Hash *h )
{
   int pos = hash ( chave, h );
   char *resp = NULL;

   if ( h->ocupado[pos] == 0 )
   {
      resp = NULL;
   }

   else if ( h->ocupado[pos] == 1 && strcmp ( h->tabela[pos], chave ) == 0 )
   {
      resp = h->tabela[pos];
   }

   else if ( strcmp ( h->tabela[pos], chave ) != 0 )
   {
      for ( int i = 0; i < h->nr; i++ )
      {
         if ( h->ocupado[h->m + i] == 1 && strcmp ( h->tabela[h->m + i], chave ) == 0 )
         {
            resp = h->tabela[h->m + i];
            i = h->nr;
         }
      }
   }

   return resp;
}

int inserir ( char chave[], Hash *h )
{
   int pos = hash ( chave, h );
   int resp = 1;

   if ( pesquisar ( chave, h ) != NULL )
   {
      resp = 0;
   }

   else if ( isPosicaoLivre ( pos, h ) == 1 )
   {
      copiarString ( h->tabela[pos], chave );
      h->ocupado[pos] = 1;
   }

   else
   {
      if ( h->nr < h->r )
      {
         copiarString ( h->tabela[h->m + h->nr], chave );
         h->ocupado[h->m + h->nr] = 1;
         h->nr++;
      }

      else
      {
         resp = 0;
      }
   }

   return resp;
}

char *remover ( char chave[], Hash *h )
{
   int pos = hash ( chave, h );
   char *resp = NULL;

   if ( h->ocupado[pos] == 0 )
   {
      resp = NULL;
   }

   else if ( strcmp ( h->tabela[pos], chave ) == 0 )
   {
      resp = h->tabela[pos];
      h->ocupado[pos] = 0;
      h->tabela[pos][0] = '\0';

      for ( int i = 0; i < h->nr; i++ )
      {
         int x = hash ( h->tabela[h->m + i], h );

         if ( x == pos )
         {
            int y = h->m + i;

            copiarString ( h->tabela[pos], h->tabela[y] );
            h->ocupado[pos] = 1;

            for ( int j = y; j < h->m + h->nr - 1; j++ )
            {
               copiarString ( h->tabela[j], h->tabela[j + 1] );
               h->ocupado[j] = h->ocupado[j + 1];
            }

            h->tabela[h->m + h->nr - 1][0] = '\0';
            h->ocupado[h->m + h->nr - 1] = 0;

            h->nr--;
            i = h->nr;
         }
      }
   }

   else if ( strcmp ( h->tabela[pos], chave ) != 0 )
   {
      for ( int i = 0; i < h->nr; i++ )
      {
         if ( strcmp ( h->tabela[h->m + i], chave ) == 0 )
         {
            resp = h->tabela[h->m + i];
            int y = h->m + i;

            for ( int j = y; j < h->m + h->nr - 1; j++ )
            {
               copiarString ( h->tabela[j], h->tabela[j + 1] );
               h->ocupado[j] = h->ocupado[j + 1];
            }

            h->tabela[h->m + h->nr - 1][0] = '\0';
            h->ocupado[h->m + h->nr - 1] = 0;

            h->nr--;
            i = h->nr;
         }
      }
   }

   return resp;
}

void mostrar ( Hash *h )
{
   for ( int i = 0; i < h->m + h->r; i++ )
   {
      printf ( "%d ", i );

      if ( i < h->m )
      {
         printf ( "Principal " );
      }

      else
      {
         printf ( "Reserva " );
      }

      if ( h->ocupado[i] == 0 )
      {
         printf ( "-\n" );
      }

      else
      {
         printf ( "%s\n", h->tabela[i] );
      }
   }
}

int main ( )
{
   Hash h;
   char palavra[TAM];
   char palavra2[TAM];

   start ( &h, 11, 3 );

   while ( scanf ( "%s", palavra ) != EOF )
   {
      char c = palavra[0];

      if ( c == 'I' )
      {
         scanf ( "%s", palavra2 );

         if ( inserir ( palavra2, &h ) == 0 )
         {
            printf ( "Erro\n" );
         }
      }

      if ( c == 'R' )
      {
         scanf ( "%s", palavra2 );
         remover ( palavra2, &h );
      }

      if ( c == 'P' )
      {
         scanf ( "%s", palavra2 );

         if ( pesquisar ( palavra2, &h ) != NULL )
         {
            printf ( "Sim\n" );
         }

         else
         {
            printf ( "Nao\n" );
         }
      }

      if ( c == 'M' )
      {
         mostrar ( &h );
      }
   }

}
