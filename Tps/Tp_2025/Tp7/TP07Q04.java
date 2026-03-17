/* 
842527 - Gabriel Ferreira Pereira

Separando cada elemento do arquivouivo csv:
AppId: 897820
Name:Reigns: Game of Thrones
Release date: "Oct 18, 2018"
Estimated owners: 75000
Price: 3.99
Supported languages: "['English', 'French', 'German', 'Spanish - Spain', 'Italian', 'Japanese', 'Korean', 'Portuguese - Brazil', 'Russian', 'Simplified Chinese', 'Traditional Chinese']"
Metacritic score: 84
User score: 0
Achievements: 10
Publishers: Devolver Digital
Developers: Nerial
Categories: "Single-player,Steam Achievements,Full controller support"
Genres: "Adventure,Indie,RPG"
Tags: "RPG,Indie,Card Game,Adventure,Choices Matter,2D,Medieval,Singleplayer,Minimalist,Choose Your Own Adventure,Strategy,Story Rich,Dark Humor,Great Soundtrack,Difficult,Dark Comedy,Funny,Comedy,Cute"

Todos as estruturas foram retirados do github de Aeds2 na pasta fonte e foram modificados para Arvore Binaria, realizando insercoes de registros conforme a entrada padrao
Bibliotecas: java.io.BufferedWriter; java.io.FileWriter; java.io.IOException; import java.io.*; foram usadas para manipular os arquivouivos do csv e txt, 
para eu utiliza-las pesquisei seu funcionamento no site "W3Schools"
*/

import java.io.*;
import java.util.*;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

class Game 
{
    private int AppId;
    private String name;
    private String releaseDate;
    private int estimatedOwners;
    private double price;
    private String[] supportedLanguages;
    private int metacriticScore;
    private double userScore;
    private int achievements;
    private String[] publishers;
    private String[] developers;
    private String[] categories;
    private String[] genres;
    private String[] tags;
    public static int comparacoes = 0;
    public static int movimentacoes = 0;

    public int getAppId() 
    {
        return AppId;
    }

    public void setAppId(int AppId) 
    {
        this.AppId = AppId;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) 
    {
        this.name = name;
    }

    public String getReleaseDate() 
    {
        return releaseDate;
    }

    public void setReleaseDate(String releaseDate) 
    {
        this.releaseDate = releaseDate;
    }

    public int getEstimatedOwners() 
    {
        return estimatedOwners;
    }

    public void setEstimatedOwners(int estimatedOwners) 
    {
        this.estimatedOwners = estimatedOwners;
    }

    public double getPrice() 
    {
        return price;
    }

    public void setPrice(double price)
    {
        this.price = price;
    }

    public String[] getSupportedLanguages() 
    {
        return supportedLanguages;
    }

    public void setSupportedLanguages(String[] supportedLanguages) 
    {
        this.supportedLanguages = supportedLanguages;
    }

    public int getMetacriticScore() 
    {
        return metacriticScore;
    }

    public void setMetacriticScore(int metacriticScore) 
    {
        this.metacriticScore = metacriticScore;
    }

    public double getUserScore() 
    {
        return userScore;
    }

    public void setUserScore(double userScore) 
    {
        this.userScore = userScore;
    }

    public int getAchievements()
    {
        return achievements;
    }

    public void setAchievements(int achievements) 
    {
        this.achievements = achievements;
    }

    public String[] getPublishers() 
    {
        return publishers;
    }

    public void setPublishers(String[] publishers) 
    {
        this.publishers = publishers;
    }

    public String[] getDevelopers() 
    {
        return developers;
    }

    public void setDevelopers(String[] developers) 
    {
        this.developers = developers;
    }

    public String[] getCategories() 
    {
        return categories;
    }

    public void setCategories(String[] categories) 
    {
        this.categories = categories;
    }

    public String[] getGenres() 
    {
        return genres;
    }

    public void setGenres(String[] genres) 
    {
        this.genres = genres;
    }

    public String[] getTags()
    {
        return tags;
    }

    public void setTags(String[] tags) 
    {
        this.tags = tags;
    }

    public static Game ler(String linha) 
    {
        Game g = new Game();
        String[] campos = splitParaVirgulaDentroAspas(linha);

        g.AppId = Integer.parseInt(colocarEspaco(campos, 0));
        g.name = colocarEspaco(campos, 1);
        g.releaseDate = formatarData(colocarEspaco(campos, 2));
        g.estimatedOwners = Integer.parseInt(colocarEspaco(campos, 3));
        g.price = Double.parseDouble(colocarEspaco(campos, 4));
        g.supportedLanguages = stringParaArray(colocarEspaco(campos, 5));
        g.metacriticScore = Integer.parseInt(colocarEspaco(campos, 6));
        g.userScore = Double.parseDouble(colocarEspaco(campos, 7));
        g.achievements = Integer.parseInt(colocarEspaco(campos, 8));
        g.publishers = stringParaArray(colocarEspaco(campos, 9));
        g.developers = stringParaArray(colocarEspaco(campos, 10));
        g.categories = stringParaArray(colocarEspaco(campos, 11));
        g.genres = stringParaArray(colocarEspaco(campos, 12));
        g.tags = stringParaArray(colocarEspaco(campos, 13));

        return g;
    }

    // funcao para separar linha no arquivo mantendo o colchete
    private static String[] splitParaVirgulaDentroAspas(String linha) {
        String[] campos = new String[100];
        int count = 0;

        StringBuilder campoAtual = new StringBuilder();
        boolean dentroAspas = false;
        int colchetes = 0;

        for (int i = 0; i < linha.length(); i++) {
            char c = linha.charAt(i);

            if (c == '\"') {
                dentroAspas = !dentroAspas;
                campoAtual.append(c);
            } else if (c == '[') {
                colchetes++;
                campoAtual.append(c);
            } else if (c == ']') {
                colchetes--;
                campoAtual.append(c);
            } else if (c == ',' && !dentroAspas && colchetes == 0) {
                campos[count++] = campoAtual.toString().trim();
                campoAtual.setLength(0);
            } else {
                campoAtual.append(c);
            }
        }

        campos[count++] = campoAtual.toString().trim();

        String[] resultado = new String[count];
        for (int i = 0; i < count; i++) {
            resultado[i] = campos[i];
        }

        return resultado;
    }

    // trocar a data do arquivo de "Oct 18, 2018" para "18/10/2018"
    private static String formatarData(String data) {
        if (data == null || data.isEmpty()) {
            return "";
        }

        String[] partes = data.split(" ");

        if (partes.length < 3) {
            return data;
        }

        String mesTexto = partes[0];
        String diaTexto = partes[1].replace(",", "");
        String anoTexto = partes[2];

        int dia = Integer.parseInt(diaTexto);

        String diaFormatado;
        if (dia < 10) {
            diaFormatado = "0" + dia;
        } else {
            diaFormatado = String.valueOf(dia);
        }

        String mesFormatado;
        switch (mesTexto) {
            case "Jan":
                mesFormatado = "01";
                break;
            case "Feb":
                mesFormatado = "02";
                break;
            case "Mar":
                mesFormatado = "03";
                break;
            case "Apr":
                mesFormatado = "04";
                break;
            case "May":
                mesFormatado = "05";
                break;
            case "Jun":
                mesFormatado = "06";
                break;
            case "Jul":
                mesFormatado = "07";
                break;
            case "Aug":
                mesFormatado = "08";
                break;
            case "Sep":
                mesFormatado = "09";
                break;
            case "Oct":
                mesFormatado = "10";
                break;
            case "Nov":
                mesFormatado = "11";
                break;
            case "Dec":
                mesFormatado = "12";
                break;
            default:
                mesFormatado = "00";
                break;
        }

        return diaFormatado + "/" + mesFormatado + "/" + anoTexto;
    }

    // troca o "\" por espaco
    private static String colocarEspaco(String[] c, int i) {
        if (i >= c.length)
            return "";
        return c[i].replace("\"", "").trim();
    }

    // remove colchetes, aspas simples e duplas, e espacos extras
    private static String[] stringParaArray(String campo) {
        campo = campo.replace("[", "").replace("]", "").replace("'", "").replace("\"", "").trim();
        if (campo.isEmpty())
            return new String[0];
        return campo.split(",");
    }

    // gera a saida igual esta no verde
    public String formatarSaida(int x) {
        return "[" + x + "] => " + AppId + " ## " + name + " ## " + releaseDate + " ## " + estimatedOwners
                + " ## " + price + " ## " + Arrays.toString(supportedLanguages) + " ## " + metacriticScore
                + " ## " + userScore + " ## " + achievements + " ## " + Arrays.toString(publishers)
                + " ## " + Arrays.toString(developers) + " ## " + Arrays.toString(categories)
                + " ## " + Arrays.toString(genres) + " ## " + Arrays.toString(tags) + " ##";
    }
}

// no da Rubro-Negra
class NoAN {
    public Game elemento;
    public NoAN esq, dir;
    public boolean cor; // true vermelho false preto

    public NoAN(Game elemento, boolean cor) {
        this.elemento = elemento;
        this.cor = cor;
        this.esq = null;
        this.dir = null;
    }

    public NoAN(Game elemento) {
        this(elemento, true); // novo no vermelho por padrao
    }
}

// RubroNegra
class RubroNegra {
    private NoAN raiz;

    public RubroNegra() {
        raiz = null;
    }

    // Insercao publica mantem raiz preta
    public void inserir(Game g) {
        if (g == null || g.getName() == null)
            return;
        raiz = inserirRec(raiz, g);
        if (raiz != null)
            raiz.cor = false;
    }

    // inserir recursivo
    private NoAN inserirRec(NoAN h, Game g) 
    {

        if (h == null)
        {
            return new NoAN(g, true); // no vermelho
        }

        int cmp = g.getName().compareTo(h.elemento.getName());

        if (cmp < 0)
        {
            h.esq = inserirRec(h.esq, g);
        }

        else if (cmp > 0)
        {
            h.dir = inserirRec(h.dir, g);
        }
        
        else
        {
            return h; // chave repetida
        }

        // filho direito vermelho e filho esquerdo preto - rotacao esquerda
        if (isRed(h.dir) && !isRed(h.esq)) 
        {
            h = rotacaoEsq(h);
        }

        // filho esquerdo vermelho e neto esquerdo vermelho - rotacao direita
        if (isRed(h.esq) && isRed(h.esq.esq)) 
        {
            h = rotacaoDir(h);
        }

        // ambos os filhos vermelhos - flipColors
        if (isRed(h.esq) && isRed(h.dir)) 
        {
            flipColors(h);
        }

        Game.comparacoes++;
        return h;
    }

    // inverter cores
    private void flipColors(NoAN h) 
    {
        h.cor = !h.cor;
        h.esq.cor = !h.esq.cor;
        h.dir.cor = !h.dir.cor;
        Game.comparacoes++;
    }

    // Pesquisa
    public boolean pesquisarMostrar(String nome) 
    {
        System.out.print("=>raiz ");
        return pesquisarRec(nome, raiz);
    }

    private boolean pesquisarRec(String nome, NoAN i) 
    {
        if (i == null)
            return false;

        Game.comparacoes++;
        int cmp = nome.compareTo(i.elemento.getName());

        if (cmp == 0) 
        {
            return true;
        } 
        else if (cmp < 0) 
        {
            System.out.print("esq ");
            return pesquisarRec(nome, i.esq);
        } 
        else 
        {
            System.out.print("dir ");
            return pesquisarRec(nome, i.dir);
        }
    }

    // Auxiliares
    private boolean isRed(NoAN x) 
    {
        return x != null && x.cor;
    }

    private NoAN rotacaoEsq(NoAN h) 
    {
        NoAN x = h.dir;
        h.dir = x.esq;
        x.esq = h;
        x.cor = h.cor;
        h.cor = true;
        Game.movimentacoes++; // contar rotacao
        return x;
    }

    private NoAN rotacaoDir(NoAN h) 
    {
        NoAN x = h.esq;
        h.esq = x.dir;
        x.dir = h;
        x.cor = h.cor;
        h.cor = true;
        Game.movimentacoes++; // contar rotacao
        return x;
    }

}

// Classe principal TP07Q04
public class TP07Q04 {

    public static Game buscarGamePorId(Game[] lista, int count, int id) {
        for (int i = 0; i < count; i++) {
            if (lista[i].getAppId() == id) {
                return lista[i];
            }
        }
        return null;
    }

    public static void main(String[] args) {
        Game[] lista = new Game[100000];
        int count = 0;

        // Leitura do CSV
        try {
            Scanner arquivo = new Scanner(new File("/tmp/games.csv")); // /tmp/games.csv para poder abrir o arquivo no verde
            if (arquivo.hasNextLine())
                arquivo.nextLine(); // pular cabecalho

            while (arquivo.hasNextLine() && count < lista.length) {
                String linha = arquivo.nextLine().trim();
                if (!linha.isEmpty())
                    lista[count++] = Game.ler(linha);
            }
            arquivo.close();
        } catch (Exception e) {
            return; // se nao encontrar o arquivo encerra
        }

        Scanner sc = new Scanner(System.in);
        RubroNegra arvore = new RubroNegra();

        // Insercao ler ids e inserir os games
        while (sc.hasNextLine()) {
            String entrada = sc.nextLine().trim();
            if (entrada.equals("FIM"))
                break;

            try {
                int id = Integer.parseInt(entrada);
                Game g = buscarGamePorId(lista, count, id);
                if (g != null)
                    arvore.inserir(g);
            } catch (NumberFormatException ex) {
                // ignorar linhas invalidas
            }
        }

        // Pesquisa ler nomes e imprimir
        long inicio = System.nanoTime();

        while (sc.hasNextLine()) 
        {
            String nome = sc.nextLine().trim();
            if (nome.equals("FIM")) 
            {
                break;
            }

            System.out.print(nome + ": ");
            boolean achou = arvore.pesquisarMostrar(nome);
            System.out.println(achou ? "SIM" : "NAO");
        }

        long fim = System.nanoTime();
        double tempoSegundos = (fim - inicio) / 1_000_000_000.0;

        // Gerar arquivo de log
        String nomeArquivo = "842527_arvoreRN.txt";
        try 
        {
            BufferedWriter writer = new BufferedWriter(new FileWriter(nomeArquivo));
            writer.write("numero de comparacoes: " + Game.comparacoes);
            writer.newLine();
            writer.write("numero de movimentacoes: " + Game.movimentacoes);
            writer.newLine();
            writer.write(String.format("Tempo de execucao: %.7f segundos", tempoSegundos));
            writer.newLine();
            writer.close();
        } 
        catch (IOException e) 
        {
            System.out.println("Erro ao gerar arquivo");
        }

        sc.close();

        sc.close();
    }
}