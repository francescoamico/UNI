import java.lang.*;
import java.util.*;

public class Main{

    private static void stampaArray(int[] array){
        int i;
        System.out.print("[");
        if(array.length==0) System.out.println("]");
        else{
            for(i=0;i<array.length-1;i++)
                System.out.print(array[i]+", ");
            System.out.println(array[i]+"]");
        }
    } 

    private static double mediaValori(int[] array){
        double m=0;
        for(int i=0;i<array.length;i++)
            m+=array[i];
        return m/array.length;
    }

    private static int[] selezionaPari(int[] v){
        int c=0;
        for(int n:v)
            if(n%2==0) c++;

        int[] array=new int[c];
        int j=0;
        for(int n:v){
            if(n%2==0){
                array[j]=n;
                j++;
            }
        }
        return array;
    }

    private static int[] eliminaDuplicati(int[] v){
        Arrays.sort(v);
        int l=0;
        for(int i=1;i<v.length;i++)
            if(v[i]==v[i-1]) l++;

        int[] array=new int[v.length-l];
        int j=0;
        array[j++]=v[0];
        for(int i=1;i<v.length;i++){
            if(v[i]!=v[i-1])
                array[j++]=v[i];
        }
        return array;
    }

    public static void main(String[] args){
        int[] array={12,4,7,6,3,7,7,4,21,78};
        System.out.print("\nArray :: ");
        stampaArray(array);
        System.out.println("Media :: "+mediaValori(array));
        System.out.print("Seleziona pari :: ");
        stampaArray(selezionaPari(array));
        System.out.print("Elimina duplicati :: ");
        stampaArray(eliminaDuplicati(array));
    }
}