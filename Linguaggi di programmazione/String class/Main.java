public class Main{

    public static String getIniziali(String nome,String cognome){
        return (nome.charAt(0)+"&"+cognome.charAt(0));
    }
    
    public static String stringReverse(String s){
        String n="";
        for(int i=s.length()-1;i>=0;i--) n+=s.charAt(i);
        return n;
    }

    public static int contaOccorrenze(String s,String pattern){
        int counter=0;
        int i=s.indexOf(pattern);

        while(s.indexOf(pattern)>=0){//occorrenza trovata
            s=s.substring(++i,s.length());
            counter++;
            i=s.indexOf(pattern);
        }

        return counter;
    }

    public static void main(String[] args){

        System.out.println(getIniziali(args[0],args[1]));
        System.out.println(stringReverse(args[0]));
        System.out.println(contaOccorrenze("banana","ana"));

    }
}