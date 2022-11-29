package biblioteca;
import java.lang.*;
import java.util.*;
/**
    @author Francesco Amico
    @version 2.0
*/
public class Libro extends Documento{

    private static int contatore;
    private Autore[] autori;
    private String titolo;
    private double prezzo;
    private String casaEditrice;
    /**
        Creazione libro
        @param titolo del libro 
        @param autori del libro 
        @param prezzo del libro 
        @param casaEditrice del libro 
    */
    public Libro(String titolo,Autore[] autori,double prezzo,String casaEditrice){
        this.titolo=titolo;
        this.autori=new Autore[autori.length];
        for(int i=0;i<autori.length;i++) this.autori[i]=autori[i];
        this.prezzo=prezzo;
        this.casaEditrice=casaEditrice;
    }
    @Override
    public void info(){
        System.out.println("\n\nId :: "+super.getId());
        System.out.println("Titolo :: "+this.titolo);
        System.out.print("Autore/i ::"); 
        for(int i=0;i<autori.length;i++)
            System.out.print("  "+this.autori[i].infoAutore()[0]+" "+this.autori[i].infoAutore()[1]);
        System.out.println("\nPrezzo :: "+this.prezzo);
        System.out.println("Casa editrice :: "+this.casaEditrice);
        System.out.println("Tipo :: "+this.getInfo());
    }
    /**
        restituisce gli autori del libro
        @return autori libro 
    */
    public Autore[] getAutori(){
        return this.autori;
    }

    @Override
    protected String getInfo(){
        return "Libro";
    }

}