import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args)throws Exception{

        /*Lettura file riga per riga con Scanner
        Scanner scan=new Scanner(new File("prova.txt"));
        while(scan.hasNext())
            System.out.println(scan.nextLine());
        scan.close();*/

        /*Lettura file riga per riga con BufferedReader
        BufferedReader r=new BufferedReader(new FileReader("prova.txt"));
        String s;
        while((s=r.readLine())!=null)
            System.out.println(s);
        r.close();*/

        /*Lettura file carattere per carattere
        FileReader r=new FileReader("prova.txt");//o FileInputStream se il file non contiene solo caratteri
        int c;
        while((c=r.read())!=-1)
            System.out.println((char)c);
        r.close();*/

        /*Copia carattere per carattere da un file ad un altro
        FileReader r=new FileReader("prova.txt");
        FileWriter w=new FileWriter("copia.txt");
        int c;
        while((c=r.read())!=-1)
            w.write(c);
        r.close();
        w.close();*/

        /*Copia riga per riga da un file ad un altro
        BufferedReader r=new BufferedReader(new FileReader("prova.txt"));
        PrintWriter w=new PrintWriter(new FileWriter("copia.txt"));
        String s;
        while((s=r.readLine())!=null)
            w.println(s);
        r.close();
        w.close();*/

        /*Legge da tastiera(da utilizzare a posto di Scanner)
        InputStreamReader r=new InputStreamReader(System.in);
        char c;
        String s="";
        while((c=(char)r.read())!=10)//allo \n si ferma
            s+=c;
        System.out.println(s);*/

        /*lettura carattere per carattere da console e scrittura su file
        InputStreamReader r=new InputStreamReader(System.in);
        FileWriter w=new FileWriter("prova.txt");
        int c;
        while((c=r.read())!=-1)
            w.write(c);
        r.close();
        w.close();*/

        /*numero righe, parole, caratteri alfanumerici e caratteri alfabetici all'interno di un file
        BufferedReader reader=new BufferedReader(new FileReader("prova.txt"));
        String s;
        int r=0,p=0,c=0,a=0;
        
        while((s=reader.readLine())!=null){
            r++;
            p+=s.split("\s").length;
            c+=s.replaceAll("\s+|\\W","").toCharArray().length;
            a+=s.replaceAll("\s+|\\W+|\\d+","").toCharArray().length;
        }

        System.out.println("Righe :: "+r);
        System.out.println("Parole :: "+p);
        System.out.println("Caratteri alfanumerici :: "+c);
        System.out.println("Caratteri alfabetici :: "+a);
        reader.close();*/

        /*crea file che ad ogni riga di prova.txt aggiunge un numero progressivo e un tab
        BufferedReader r=new BufferedReader(new FileReader("prova.txt"));
        PrintWriter w=new PrintWriter(new FileWriter("output.txt"));
        int c=0;
        String s;
        while((s=r.readLine())!=null){
            w.println(s+c+"\t");
            c++;
        }
        r.close();
        w.close();*/

        
        /*cifra/decifra un file (cifrario di Cesare)
        FileReader r=new FileReader("prova.txt");
        FileWriter w=new FileWriter("prova.txt",true);
        int c,key=4;//chiave del cifrario 
        w.write("\n");
        while((c=r.read())!=-1){
            if((char)c!=' ')
                w.write(c-key);
            else w.write(c);
        }
        r.close();
        w.close();*/

    }
}