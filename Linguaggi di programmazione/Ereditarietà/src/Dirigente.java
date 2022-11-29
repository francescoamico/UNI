package persone;

public class Dirigente extends Impiegato{
    private String dipartimento;

    public Dirigente(String nome,String cognome,String datoreLavoro,double salario,String dipartimento){
        super(nome,cognome,datoreLavoro,salario);
        this.dipartimento=dipartimento;
    }

    @Override
    public void presentati(){
        super.presentati();
        System.out.println("Dipartimento diretto :: "+this.dipartimento);
    }
    
    @Override
    public String toString(){
        return super.toString()+"\n"+this.dipartimento;
    }
}