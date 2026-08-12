import java.util.*;

public class Espelho 
{
    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int a = 0;
        int b = 0;
        int[] array = new int[1000];
        
        a = sc.nextInt();
        b = sc.nextInt();
        int i = 0;

        while(a <= b)
        {
            array[i] = a;
            i++;
            a++;
        }

        for(int j = 0; j < i; j++)
        {
            System.out.print(" " + array[j]);
        }

        for (int j = i - 1; j >= 0; j--)
        {
            System.out.print(" " + array[j]);
        }
    }
}