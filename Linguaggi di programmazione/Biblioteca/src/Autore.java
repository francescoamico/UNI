package biblioteca;
import java.lang.String;
/**
    @author Francesco Amico
    @version 1.0
*/
public class Autore{

    private String nome;
    private String cognome;
    /**
        Creazione autore
        @param nome autore 
        @param cognome autore 
    */
    public Autore(String nome,String cognome){
        this.nome=nome;
        this.cognome=cognome;
    }
    /**
        Restituisce nome e cognome dell'autore
        @return nome e cognome autore 
    */
    public String[] infoAutore(){
        String[] info={this.nome,this.cognome};
        return info;
    }

}