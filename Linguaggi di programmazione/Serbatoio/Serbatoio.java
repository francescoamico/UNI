/** Classe Serbatoio
    @author Francesco Amico    
*/
public class Serbatoio{
    private int livello;//inizializzata a 0 in quanto attributo
    private final int CAPACITA=10;//costante da inizializzare

    /** Costruttore: livello =  10 */
    public Serbatoio(){
        this.livello=10;
    }
    /** @param livello nuovo valore di livello */
    public Serbatoio(int livello){
        this.livello=livello;
    }
    /** @param j decrementato da livello */
    public void consuma(int j){
        this.livello-=j;
    }
    /** @param j incrementato a livello */
    public void rifornisci(int j){
        this.livello+=j;
    }
    /** @return valore di livello */
    public int getLivello(){
        return this.livello;
    }
}