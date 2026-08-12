import java.util.Scanner;

public class Sort 
{

    private static int compare(int a, int b, int m) 
    {
        int modA = a % m;
        int modB = b % m;


        if (modA != modB) return modA - modB;

        boolean oddA = (a % 2 != 0);
        boolean oddB = (b % 2 != 0);

        if (oddA && !oddB) return -1;
        if (!oddA && oddB) return 1;

        if (oddA && oddB) return b - a;

        if (!oddA && !oddB) return a - b;

        return 0;
    }

    // Insertion sort 
    public static void insertionSort(int[] arr, int m) 
    {
        for (int i = 1; i < arr.length; i++) 
        {
            int tmp = arr[i];
            int j = i - 1;

            while (j >= 0 && compare(arr[j], tmp, m) > 0) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = tmp;
        }
    }

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);

        while (true) 
        {
            int n = sc.nextInt();
            int m = sc.nextInt();

            if (n == 0 && m == 0) break;

            int[] arr = new int[n];
            for (int i = 0; i < n; i++) 
            {
                arr[i] = sc.nextInt();
            }

            insertionSort(arr, m);

            System.out.println(n + " " + m);
            for (int x : arr) 
            {
                System.out.println(x);
            }
        }

        System.out.println("0 0");
    }
}
