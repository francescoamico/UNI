/* FIBONACCI time:O(log n) space:O(log n) */
import java.util.Scanner;
public class Fibonacci{

    private static void rigaPerColonna(long[][] m1, long[][] m2){
        long[][] m3 = new long[2][2];

        for(int i=0; i<2; i++)
            for(int j=0; j<2; j++)
                m3[i][j] = m1[i][0]*m2[0][j] + m1[i][1]*m2[1][j];

        for(int i=0; i<2; i++)
            for(int j=0; j<2; j++)
                m1[i][j] = m3[i][j];
    }

    private static void potenzaDiMatrice(long[][] m, int n){
        if(n>1){
            potenzaDiMatrice(m, n/2); //doubling
            rigaPerColonna(m,m);
        }
        if(n%2 != 0){
            long[][] tmp = {{1,1},{1,0}};
            rigaPerColonna(m,tmp);
        }
    }

    public static long fibonacci(int n){
        long[][] m = {{1,0},{0,1}};
        potenzaDiMatrice(m,n-1);
        return m[0][0];
    }
    
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);

        System.out.print("Inserisci n :: ");
        int n = 0;
        while(n<1) n = scan.nextInt();
        System.out.println("Fibonacci("+n+") = "+fibonacci(n));

        scan.close();
    } 

}