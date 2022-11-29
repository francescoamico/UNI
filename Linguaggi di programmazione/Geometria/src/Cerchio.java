package geometria.figurepiane;
/**
    Classe cerchio
    @author Francesco Amico
*/
public class Cerchio{
    private double raggio;
    private static final double PI_GRECO=3.14;
    /**@param raggio inserito dal client */
    public Cerchio(double raggio){
        this.raggio=raggio;
    }
    /**@return area cerchio */
    public double calcolaArea(){
        return (this.raggio*this.raggio*PI_GRECO);
    }
}