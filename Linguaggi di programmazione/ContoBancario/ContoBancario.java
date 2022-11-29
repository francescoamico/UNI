/**
    @author Francesco Amico
*/
public class ContoBancario{
    private String utente="Mario Rossi";
    private int id;
    private double saldo;
    private static int counter=0;;

    /**Costruttuore che assegna id al conto */
    public ContoBancario(){
        this.id=ContoBancario.counter++;
    }

    /**@param ammontare viene versato sul conto */
    public void versa(double ammontare){
        this.saldo+=ammontare;
    }

    /**@param ammontare viene prelevato dal conto */
    public void preleva(double ammontare){
        this.saldo-=ammontare;
    }
    /**@param ammontare cifra da trasferire
        @param c conto su cui trasferire la cifra
    */
    public void trasferisci(double ammontare,ContoBancario c){
        this.preleva(ammontare);
        c.versa(ammontare);
    }
    /**@return ritorna il saldo */
    public double getSaldo(){
        return this.saldo;
    }
    /**@return ritorna id conto */
    public int getId(){
        return this.id;
    }
}