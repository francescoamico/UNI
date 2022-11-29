package geometria.figuresolide;
/**
    Classe cubo
    @author Francesco Amico
*/
public class Cubo{
    private double lato;
    /**@param lato inserito dal client */
    public Cubo(double lato){
        this.lato=lato;
    }
    /**@return volume del cubo */
    public double calcolaVolume(){
        return (this.lato*this.lato*this.lato);
    }
}