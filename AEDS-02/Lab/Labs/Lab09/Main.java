import java.util.*;

class Atleta
{
    String nome;
    int peso;

    public Atleta ( String nome, int peso )
    {
        this.nome = nome;
        this.peso = peso;
    }

}

class Main 
{
    public static void main ( String[] args )
    {
        Scanner sc = new Scanner(System.in);
        Atleta[] atletas = new Atleta[100];
        int cont = 0;

        while (sc.hasNext())
        {
            String nome = sc.next();
            int peso = sc.nextInt();

            atletas[cont] = new Atleta(nome, peso);

            cont++;
        }

        for ( int i = 0; i < cont - 1; i++ )
        {
            for (int j = 0; j < cont - i - 1; j++)
            {
                if ( atletas[j].peso < atletas[j+1].peso )
                {
                    Atleta tmp = atletas[j];
                    atletas[j] = atletas[j+1];
                    atletas[j+1] = tmp;
                }

                else if ( atletas[j].peso == atletas[j+1].peso )
                {
                   if ( atletas[j].nome.compareTo( atletas[j+1].nome) > 0 ) 
                   {
                        Atleta tmp = atletas[j];
                        atletas[j] = atletas[j+1];
                        atletas[j+1] = tmp;
                   }
                }
            }
        }

        for ( int i = 0; i < cont; i++ )
        {
            System.out.println( atletas[i].nome + " " + atletas[i].peso );
        }
    }
}
