package persone;

public class Studente extends Persona{
    private String uni;
    private String mat;

    public Studente(String nome,String cognome,String uni,String mat){
        super(nome,cognome);
        this.uni=uni;
        this.mat=mat;
    }

    @Override
    public void presentati(){
        super.presentati();
        System.out.println("Matricola :: "+this.mat);
        System.out.println("Uni :: "+this.uni);
    }
    
    @Override
    public String toString(){
        return super.toString()+"\n"+this.uni+"\n"+this.mat;
    }
}