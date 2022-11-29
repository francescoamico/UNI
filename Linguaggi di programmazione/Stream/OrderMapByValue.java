import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.lang.*;

public class Main {
    /*ordinamento mappa per valore*/
    static <K,V extends Comparable<? super V>> Map<K,V> orderByValue(Map<K,V> map){
        return map.entrySet().stream().sorted(Comparator.comparing(Map.Entry<K,V>::getValue))
        .collect(Collectors.toMap(Map.Entry<K,V>::getKey,Map.Entry<K,V>::getValue,(o,n)->n,LinkedHashMap::new));
    }

    public static void main(String[] args){
        Map<Integer,String> map=new HashMap<>();
        map.put(2, "Amico");
        map.put(1, "Gucciardi");
        map.put(12, "Andolina");
        map.put(3, "Andre");

        System.out.println(orderByValue(map));
    }
}