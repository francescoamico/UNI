import java.util.*;
import java.lang.*;

public class Main{
    static <E extends Object> HashMap<E,Integer> hashElementi(List<E> lista)throws NoSuchElementException{
        if(lista.isEmpty()==true) throw new NoSuchElementException();
        else{
            HashMap<E,Integer> map = new HashMap<>();
            for(E e:lista) map.put(e,e.hashCode());
            return map;
        }
    } 

    static String stringaMassima(Map<String,Integer> map)throws NoSuchElementException{
        if(map.keySet().isEmpty()== true) throw new NoSuchElementException();
        else{
            String t="";
            int max=0;
            for(String s:map.keySet()){
                if(max<map.get(s)){ max=map.get(s); t=s;}
            }
            return t;
        }
    }

    static <E,T extends Comparable<? super T>> E valoreMassimo(Map<E,T> map)throws NoSuchElementException{
        if(map.keySet().isEmpty()== true) throw new NoSuchElementException();
        else{
            Iterator<E> i=map.keySet().iterator();
            E t=i.next();
            for(E s:map.keySet()){
                if(map.get(t).compareTo(map.get(s))<0) t=s; 
            }
            return t;
        }
    }

    public static void main(String[] args){
        /*//coppie numero frequenza
        HashMap<Integer,Float> map=new HashMap<>();
        for(int i=0;i<10;i++) map.put(i,0f);

        Random generatore = new Random();
        int d;
        for(int i=0;i<1000;i++){
            d=generatore.nextInt(10);
            map.put(d,map.get(d)+1);
        }

        for(int i=0;i<10;i++) map.put(i,map.get(i)/1000);

        System.out.println("Coppie numero frequenza :");
        for(Integer x:map.keySet()){
            System.out.println("("+x+","+map.get(x)+")");
        }*/


        /*//coppia (elemento,elemento.hashCode())
        List<String> s = new ArrayList<>();
        s.add("Pippo");
        s.add("Pluto");
        s.add("Topolino");
        s.add("Topolino");
        try{
            HashMap<String,Integer> map=hashElementi(s);
            for(String x:map.keySet()){
                System.out.println("("+x+","+map.get(x)+")");
            }
        }catch(NoSuchElementException e){
            System.out.println("The list is empty");
        }*/


        /*//Chiave generica(nell'esempio String) con valore massimo
        Map<String,Integer> map = new HashMap<>();
        map.put("Pluto",25);
        map.put("Pippo",76);
        map.put("Topolino",10);
        map.put("Paperino",100);
        try{
            System.out.println("Stringa con valore massimo :: "+valoreMassimo(map));
        }catch(NoSuchElementException e){
            System.out.println("The keySet is empty");
        }*/

    }
}