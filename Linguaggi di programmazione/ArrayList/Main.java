import java.util.*;
import java.lang.*;

public class Main{

    private static void selezionaPari(ArrayList<Integer> array){
        int i=0;
        while(i<array.size()){
            if(array.get(i)%2!=0)
                array.remove(i);
            else i++;
        }
    }

    private static void eliminaDuplicati(ArrayList<Integer> array){
        Collections.sort(array);
        int i=1;
        while(i<array.size()){
            if(array.get(i)==array.get(i-1))  array.remove(i);
            else i++;
        }
    }

    public static void main(String[] args){
        ArrayList<Integer> array=new ArrayList<Integer>();
        array.add(1);
        array.add(12);
        array.add(6);
        array.add(7);
        array.add(1);
        array.add(7);
        array.add(8);
        array.add(8);
        System.out.println("Array :: "+array);
        eliminaDuplicati(array);
        System.out.println("Elimina duplicati :: "+array);
        selezionaPari(array);
        System.out.println("Seleziona pari :: "+array);
    }

}