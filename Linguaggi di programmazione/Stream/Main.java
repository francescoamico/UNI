import java.util.*;
import java.util.stream.*;
import java.io.*;
import java.nio.file.*;
import java.lang.*;

class Persona{
    private String nome,cognome;
    private char genere;
    private int eta;

    public Persona(String nome,String cognome,int eta,char genere){
        this.nome=nome;
        this.cognome=cognome;
        this.eta=eta;
        this.genere=genere;
    }

    public String getNome(){
        return this.nome;
    }
    public String getCognome(){
        return this.cognome;
    }
    public int getEta(){
        return this.eta;
    }
    public char getGenere(){
        return this.genere;
    }
}
public class Main{

    public static <K,V extends Comparable<? super V>> Optional mapMax (Map<K,V> map){
        return map.entrySet()
                .stream()
                .reduce((x,y)->x.getValue().compareTo(y.getValue())>0 ? x:y)
                .map(x->x.getKey());
    }

    public static Map<Character,Set<String>> esercizio6(String file){
        try(Stream<String> lines=Files.lines(Paths.get(file))){
            return lines.
                collect(Collectors.groupingBy(l->Character.valueOf(l.charAt(0)),Collectors.mapping(
                    w -> w,
                   Collectors.toSet()
                    )
            ));
        }catch(IOException e){
            System.out.println("Errore apertura file.");
            return null;
        }
    }

    public static long esercizio7(String file,String word){
        try(Stream<String> lines=Files.lines(Paths.get(file))){
            return lines.
                    filter(l->l.contains(word))
                    .count();
        }catch(IOException e){
            System.out.println("Errore apertura file.");
            return 0;
        }
    }

    public static <K,V> Map<V,List<K>> esercizio8 (Map<K,V> map){
        return map.entrySet().stream().
                collect(Collectors.groupingBy(t->t.getValue(),Collectors.mapping(
                    w -> w.getKey(),
                    Collectors.toList()
                    )
                ));
    }


    public static void main(String[] args){
        /*esercizio1
        albums
            .stream()
            .filter(x->x.getYear()<2000)
            .foreach(Album::getAuthor);
        */

        /*esercizio2
        albums
            .stream()
            .filter(x->x.getYear()<2000)
            .flatMap(x->x.getSong().stream())
            .sorted()
            .limit(10)
            .foreach(Album::getAuthot);
        */

        /*//esercizio3
        List<Persona> persone=List.of(
                                    new Persona("Mario","Rossi",38,'M')
                                    ,new Persona("Maria","Rossi",21,'F')
                                    ,new Persona("Giulio","Bianchi",50,'M'));
        OptionalDouble avg=persone.stream()
        .filter(p->p.getGenere() =='M')
        .mapToDouble(p->p.getEta())
        .average();          
        System.out.print(avg);*/

        /*//esercizio4
        Map<Integer,String> map=new HashMap<>();
        map.put(12,"Rossi");
        map.put(14,"Bianchi");
        map.put(2,"Bruni");
        map.put(28,"Neri");
        System.out.print(mapMax(map));*/

        /*//esercizio5
        List<String> l=List.of("ZERO","DUE","QUATTRO","SEI","OTTO","DIECI","DODICI","QUATTORDICI",
                    "SEDICI","DICIOTTO","VENTI","VENTIDUE","VENTIQUATTRO","VENTISEI",
                    "VENTOTTO");
     
        System.out.print(l.stream()
                        .collect(Collectors.partitioningBy(
                            s->s.length()==l.indexOf(s),Collectors.counting())));*/
        
        /*//esercizio6
        System.out.println(esercizio6("prova.txt"));*/

        /*//esercizio7
        System.out.println("Occurence :: "+esercizio7("prova.txt","francesco"));*/

        /*//esercizio8
        Map<Integer,String> map=new HashMap<>();
        map.put(12,"Rossi");
        map.put(14,"Bianchi");
        map.put(2,"Bruni");
        map.put(28,"Neri");
        map.put(2,"Bianchi");
        System.out.print(esercizio8(map));*/

    
       /*System.out.print(new Random().doubles(3).sum());*/
    }
} 