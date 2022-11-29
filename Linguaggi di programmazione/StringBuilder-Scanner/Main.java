import java.util.*;

public class Main{

    private static boolean isValidEmail(String s){
        return s.matches("[a-zA-Z0-9._-]+@+[a-zA-Z0-9.-]+\\.+(it|com|net|gov|edu|fr|de)");
    }

    private static int sumOfDigits(int n){
        return n<10 ? n:n%10+sumOfDigits(n/10);
    }

    private static boolean areAnagrams(StringBuilder s, StringBuilder t){
        if(s.length()!=t.length()) return false;
        int j;
        for(int i=0;i<s.length();i++){                          
            j=0;                                                        
            while(j<t.length() && s.charAt(i)!=t.charAt(j)){j++;}
            if(j==t.length()) return false;
            else  t.deleteCharAt(j);
        }
        return true;
    }

    private static void eliminaVocali(StringBuilder s){
        int i=0;
        while(i<s.length()){
            if(String.valueOf(s.charAt(i)).matches("(a|A|e|E|i|I|o|O|u|U)"))
                s.deleteCharAt(i);
            else i++;
        }
    }

    private static StringBuilder baseUno(int n){
        StringBuilder s=new StringBuilder();
        for(int i=0;i<=n;i++) s.append("0");
        return s;
    }

    private static String stringCapitalize(String s){
        StringBuilder t=new StringBuilder();
        t.append(String.valueOf(s.charAt(0)).toUpperCase());
        
        for(int i=1;i<s.length();i++){
            if(s.charAt(i-1)==' ')
                t.append(String.valueOf(s.charAt(i)).toUpperCase());
            else t.append(String.valueOf(s.charAt(i)));
        }
        return t.toString();
    }

    private static String fibonacci(int n){
        if (n==1) return "b";
        if(n==2) return "a";
        else return (fibonacci(n-1)+fibonacci(n-2));
    }
    
    private static String randomString(int a,int n){//alfabeto [a-z]
        a%=26;//rimaniamo nel range [a-z]
        StringBuilder s=new StringBuilder();
        for(int i=0;i<n;i++)
            s.append(String.valueOf((char)('a'+(int)(a*Math.random()))));
        return s.toString();
    }

    public static void main(String[] args){
        Scanner scan=new Scanner(System.in);

        System.out.println("\nInserire email :: ");
        if(isValidEmail(scan.nextLine())==true)
            System.out.println("email valida");
        else  System.out.println("email non valida");

        System.out.print("\nInserire intero :: ");
        System.out.println("Somma delle cifre :: "+sumOfDigits(scan.nextInt())+"\n");

        StringBuilder s=new StringBuilder("supErcalIfragili");
        StringBuilder t=new StringBuilder("bora");
        System.out.println(s.toString()+" e "+t.toString()+" sono anagrammi? "+areAnagrams(s,t));

        System.out.println("\nRimozione vocali da "+s.toString()+"...");
        eliminaVocali(s);
        System.out.println(s);

        System.out.println("\n5 in base 1 :: "+baseUno(5));

        System.out.println("\nFibonacci di 6 :: "+fibonacci(6));

        System.out.println("\n"+stringCapitalize("sono una stringa composta da parole che iniziano per lettara maiuscola"));

        System.out.println("\nStringa random :: "+randomString(4,15));
    }

}