package persone;

public class Persona{
    private String nome;
    private String cognome;

    public Persona(String nome,String cognome){
        this.nome=nome;
        this.cognome=cognome;
    }

    public void presentati(){
        System.out.println("Nome e Cognome :: "+this.nome+" "+this.cognome);
    }

    public String toString(){
        return this.nome+"\n"+this.cognome;
    }
}
