
import java.security.spec.X509EncodedKeySpec;
import java.util.*;

class Persona{
    private final String nome,cognome;
    
    public Persona(String nome,String cognome){
        this.nome=nome;
        this.cognome=cognome;
    }

    public String getNome(){
        return this.nome;
    }

    public String getCognome(){
        return this.cognome;
    }

    @Override
    public String toString(){
        return "Persona :: "+this.getNome()+" "+this.getCognome();
    }
}

class Punto{
    private final float x,y;

    public Punto(float x,float y){
        this.x=x;
        this.y=y;
    }

    public float getX(){
        return this.x;
    }

    public float getY(){
        return this.y;
    }

    @Override
    public String toString(){
        return "Punto("+this.getX()+","+this.getY()+")";
    }
}

public class Main{

    static boolean consecutivi(Set<Integer> s)throws NoSuchElementException{
        Object[] arr=s.toArray();
        if(arr.length==0) throw new NoSuchElementException();
        else{
            for(int i=0;i<arr.length-1;i++)
                if(((int)arr[i]<=10 && (int)arr[i]>=-10) && ((int)arr[i+1]<=10 && (int)arr[i+1]>=-10)) return true;
            return false;
        }
    }

    static boolean consecutivi1(Set<Integer> s) throws NoSuchElementException{
        Iterator<Integer>i=s.iterator();
        Integer ob,ob1=i.next();
        while(i.hasNext()){
            ob=ob1;
            if(i.hasNext()){
                ob1=i.next();
                if((ob<=10 && ob>=-10) && (ob1<=10 && ob>=-10)) return true;
            } 
        }
        return false;
    }

    static boolean consecutivi2(Set<Integer> s)throws NoSuchElementException{
        if(s.isEmpty()==true) throw new NoSuchElementException();
        else{
            int x=20;
            for(int i:s){
                if((x<=10 && x>=-10) && (i<=10 && i>=-10)) return true;
                x=i;
            }
            return false;
        }
    }

    static void eliminaPari(Set<Integer> s){
        if(s.isEmpty()==true)System.out.println("Insieme vuoto!");
        else{
            for(Iterator<Integer>i=s.iterator();i.hasNext();)
                if(i.next()%2==0) i.remove();
        }
    }

    static void stampaPrimoQuadrante (Set<Punto> p){
        if(p.isEmpty()==true) System.out.println("Insieme vuoto!");
        else{
            System.out.println("Punti primo quadrante:");
            for(Punto xy:p){
               if(xy.getX()>=0 && xy.getY()>=0) System.out.println(xy); 
            }
        }
    }

    static TreeSet<Persona> insiemePersoneOrdinato(HashSet<Persona> persone,Comparator<Persona> comparatore){
        TreeSet<Persona> p= new TreeSet<>(comparatore);
        for(Persona a:persone)
            p.add(a);
        return p;
    }

    static void selezionaPari(ArrayList<Integer> numeri){
        if(numeri.isEmpty()==true) System.out.println("Lista vuota!");
        else{
            ListIterator<Integer> i = numeri.listIterator(0);
            do{
                if(i.next()%2!=0) i.remove();
            } while(i.hasNext());
        }
    }

    static void eliminaDuplicati(ArrayList<Integer> numeri){
        if(numeri.isEmpty()==true) System.out.println("Lista vuota!");
        else{
            ArrayList<Integer> numeri2=new ArrayList<>();
            Integer x;
            for(ListIterator<Integer> i = numeri.listIterator(0);i.hasNext();){
                x=i.next();
                if(numeri2.contains(x)) i.remove();
                else numeri2.add(x);
            }
        }
    }

    public static void main(String... args){

        /*//sia for che iteratore
        Set<Integer> s=new HashSet<>();
        s.add(4);
        s.add(13);
        s.add(4);
        s.add(7);
        try{
            if (consecutivi(s)==true)
                System.out.println("L'insieme contiene due numeri consecutivi tra -10 e 10");
            else System.out.println("L'insieme non contiene due numeri consecutivi tra -10 e 10");
        }catch(NoSuchElementException e){
            System.out.println("Insieme vuoto!");
        }*/


        /*//for esteso
        Set<Integer> s=new LinkedHashSet<>();
        s.add(4);
        s.add(13);
        s.add(4);//copia non inserita
        s.add(7);
        s.add(5);
        try{
            if (consecutivi2(s)==true)
                System.out.println("L'insieme contiene due numeri consecutivi tra -10 e 10");
            else System.out.println("L'insieme non contiene due numeri consecutivi tra -10 e 10");
        }catch(NoSuchElementException e){
            System.out.println("Insieme vuoto!");
        }*/
        

        /*//elimina pari
        Set<Integer> s=new HashSet<>();
        s.add(4);
        s.add(13);
        s.add(18);
        s.add(21);
        s.add(23);
        s.add(2);
        eliminaPari(s);
        for(Integer i:s)
           System.out.println(i);*/
        
        
        /*//punti primo quadrante
        Set<Punto> punti=new LinkedHashSet<>();
        punti.add(new Punto(-3.2f,5f));
        punti.add(new Punto(10f,3f));
        punti.add(new Punto(-21f,-1.9f));
        punti.add(new Punto(12f,-34.5f));
        stampaPrimoQuadrante(punti);*/
        

        /*//Insieme ordinato di persone
        HashSet<Persona> persone=new HashSet<>();
        persone.add(new Persona("Luca","Verdi"));
        persone.add(new Persona("Lucia","Bianchi"));
        persone.add(new Persona("Mario","Rossi"));
        persone.add(new Persona("Giorgio","Bruni"));
        persone.add(new Persona("Paolo","Rossi"));
        Comparator<Persona> comparatore = new Comparator<>(){
            @Override
            public int compare(Persona p1,Persona p2){
                if(p1.getCognome().equals(p2.getCognome()))
                    return p1.getNome().compareTo(p2.getNome());
                else return p1.getCognome().compareTo(p2.getCognome());
            }
        };
        TreeSet<Persona> insiemeOrdinatoDiPersone = insiemePersoneOrdinato(persone, comparatore);
        for(Persona a:insiemeOrdinatoDiPersone)
            System.out.println(a);*/


        //seleziona pari e elimina duplicati da ArrayList
        ArrayList<Integer> numeri=new ArrayList<>();
        numeri.add(8);
        numeri.add(7);
        numeri.add(8);
        numeri.add(13);
        numeri.add(2);
        numeri.add(7);
        eliminaDuplicati(numeri);
        System.out.println("Elimina duplicati :: "+numeri);
        selezionaPari(numeri);
        System.out.println("Seleziona pari :: "+numeri);
    }
}