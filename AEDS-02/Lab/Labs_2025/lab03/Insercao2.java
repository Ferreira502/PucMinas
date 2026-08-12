import java.util.Scanner;

class Insercao2 
{
    public void Insercao2(int[] array) 
    {
        int n = array.length;
        for (int i = 1; i < n; i++) 
        {
            int tmp = array[i];
            int j = i - 1;

            while (j >= 0 && array[j] > tmp) 
            {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = tmp;
        }
    }

    public void print(int[] array) {
        for (int i = 0; i < array.length; i++) 
        {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Digite a quantidade de elementos: ");
        int n = sc.nextInt();
        // System.out.println("Digite o modulo: ");
        // int m = sc.nextInt();

        int[] array = new int[n];
        System.out.println("Digite os elementos:");

        for (int i = 0; i < n; i++) 
        {
            array[i] = sc.nextInt();
        }

        Sort sorter = new Sort();
        sorter.sort(array);

        System.out.println("Array ordenado:");
        sorter.print(array);
    }
}