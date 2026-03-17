import java.util.*;

public class TP02Q01 
{

    public static boolean avaliarExpressao(String expr, Map<Character, Boolean> valores) 
    {
        String semEspaco = "";
        for (int i = 0; i < expr.length(); i++) 
        {
            char c = expr.charAt(i);
            if (c != ' ') 
            {
                semEspaco += c;
            }
        }
        expr = semEspaco;

        for (Map.Entry<Character, Boolean> entry : valores.entrySet()) 
        {
            String chave = entry.getKey().toString();
            String val = "0";
            if (entry.getValue()) 
            {
                val = "1";
            }
            while (expr.indexOf(chave) != -1) 
            {
                int idx = expr.indexOf(chave);
                expr = expr.substring(0, idx) + val + expr.substring(idx + 1);
            }
        }

        // Resolver "not(x)"
        while (expr.contains("not(")) 
        {
            int ini = expr.indexOf("not(");
            int fim = encontrarFechamento(expr, ini + 4);
            String dentro = expr.substring(ini + 4, fim);
            boolean val = !avaliarExpressao(dentro, valores);
            String novo = "0";
            if (val) 
            {
                novo = "1";
            }
            expr = expr.substring(0, ini) + novo + expr.substring(fim + 1);
        }

        // Resolver "and"
        while (expr.contains("and(")) 
        {
            int ini = expr.indexOf("and(");
            int fim = encontrarFechamento(expr, ini + 4);
            String dentro = expr.substring(ini + 4, fim);
            String[] partes = separarArgumentos(dentro);
            boolean val = true;

            for (int i = 0; i < partes.length; i++) 
            {
                boolean r = avaliarExpressao(partes[i], valores);
                if (val == true && r == false) {
                    val = false;
                }
            }
            String novo = "0";
            if (val) 
            {
                novo = "1";
            }
            expr = expr.substring(0, ini) + novo + expr.substring(fim + 1);
        }

        // Resolver "or"
        while (expr.contains("or(")) 
        {
            int ini = expr.indexOf("or(");
            int fim = encontrarFechamento(expr, ini + 3);
            String dentro = expr.substring(ini + 3, fim);
            String[] partes = separarArgumentos(dentro);
            boolean val = false;
            
            for (int i = 0; i < partes.length; i++) 
            {
                boolean r = avaliarExpressao(partes[i], valores);
                if (r == true) 
                {
                    val = true;
                }
            }

            String novo = "0";
            if (val) 
            {
                novo = "1";
            }
            expr = expr.substring(0, ini) + novo + expr.substring(fim + 1);
        }

        expr = expr.trim();
        return expr.equals("1");
    }

    private static int encontrarFechamento(String s, int pos) 
    {
        int contador = 0;
        for (int i = pos; i < s.length(); i++) 
        {
            char c = s.charAt(i);
            if (c == '(') 
            {
                contador++;
            } 
            else if (c == ')') 
            {
                if (contador == 0) 
                {
                    return i;
                }
                contador--;
            }
        }
        return -1;
    }

    private static String[] separarArgumentos(String s) 
    {
        List<String> args = new ArrayList<>();
        int inicio = 0, contador = 0;

        for (int i = 0; i < s.length(); i++) 
        {
            char c = s.charAt(i);
            if (c == '(') 
            {
                contador++;
            } else if (c == ')') 
            {
                contador--;
            } 
            else if (c == ',' && contador == 0) 
            {
                args.add(s.substring(inicio, i));
                inicio = i + 1;
            }
        }

        args.add(s.substring(inicio));
        String[] res = new String[args.size()];
        
        for (int i = 0; i < args.size(); i++) 
        {
            res[i] = args.get(i);
        }
        return res;
    }

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextLine()) 
        {
            String linha = sc.nextLine().trim();
        
            if (linha.length() == 0) 
            {
                break;
            }
            
            if (linha.length() == 1 && linha.charAt(0) == '0') 
            {
                break;
            }

            String[] tokens = linha.split(" ");

            int n = Integer.parseInt(tokens[0]);

            Map<Character, Boolean> valores = new HashMap<>();
            
            for (int i = 0; i < n; i++) 
            {
                int val = Integer.parseInt(tokens[i + 1]);
                if (val == 1) 
                {
                    valores.put((char) ('A' + i), true);
                } 
                
                else 
                {
                    valores.put((char) ('A' + i), false);
                }
            }

            String expressao = "";
            
            for (int i = n + 1; i < tokens.length; i++) 
            {
                if (i > n + 1) 
                {
                    expressao += " ";
                }
                expressao += tokens[i];
            }

            boolean resultado = avaliarExpressao(expressao, valores);

            if (resultado == true) 
            {
                System.out.println("1");
            } 
            else 
            {
                System.out.println("0");
            }
        }

        sc.close();
    }

}
