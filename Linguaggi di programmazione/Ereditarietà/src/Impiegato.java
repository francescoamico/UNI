package persone;

public class Impiegato extends Persona{
    private String datoreLavoro;
    private double salario;

    public Impiegato(String nome,String cognome,String datoreLavoro,double salario){
        super(nome,cognome);
        this.datoreLavoro=datoreLavoro;
        this.salario=salario;
    }

    @Override
    public void presentati(){
        super.presentati();
        System.out.println("Datore di lavoro :: "+this.datoreLavoro);
        System.out.println("Salario :: "+this.salario);
    }
    
    @Override
    public String toString(){
        return super.toString()+"\n"+this.datoreLavoro+"\n"+this.salario;
    }
}